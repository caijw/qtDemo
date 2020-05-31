#include "waitable_event.h"

void AutoResetWaitableEvent::Signal() {
  std::unique_lock<std::mutex> locker(mutex_);
  signaled_ = true;
  cv_.notify_one();
}

void AutoResetWaitableEvent::Reset() {
  std::unique_lock<std::mutex> locker(mutex_);
  signaled_ = false;
}

void AutoResetWaitableEvent::Wait() {
  std::unique_lock<std::mutex> locker(mutex_);
  while (!signaled_)
    cv_.wait(locker);
  signaled_ = false;
}

//bool AutoResetWaitableEvent::WaitWithTimeout(TimeDelta timeout) {
//  std::unique_lock<std::mutex> locker(mutex_);

//  if (signaled_) {
//    signaled_ = false;
//    return false;
//  }

//  // We may get spurious wakeups.
//  TimeDelta wait_remaining = timeout;
//  TimePoint start = TimePoint::Now();
//  while (true) {
//    if (std::cv_status::timeout ==
//        cv_.wait_for(locker,
//                     std::chrono::nanoseconds(wait_remaining.ToNanoseconds())))
//      return true;  // Definitely timed out.

//    // We may have been awoken.
//    if (signaled_)
//      break;

//    // Or the wakeup may have been spurious.
//    TimePoint now = TimePoint::Now();
//    FML_DCHECK(now >= start);
//    TimeDelta elapsed = now - start;
//    // It's possible that we may have timed out anyway.
//    if (elapsed >= timeout)
//      return true;

//    // Otherwise, recalculate the amount that we have left to wait.
//    wait_remaining = timeout - elapsed;
//  }

//  signaled_ = false;
//  return false;
//}

bool AutoResetWaitableEvent::IsSignaledForTest() {
  std::unique_lock<std::mutex> locker(mutex_);
  return signaled_;
}
