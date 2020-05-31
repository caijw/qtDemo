#ifndef WAITABLE_EVENT_H
#define WAITABLE_EVENT_H
#include <condition_variable>
#include <mutex>
#include "macros.h"

class AutoResetWaitableEvent final {
 public:
  AutoResetWaitableEvent() {}
  ~AutoResetWaitableEvent() {}

  // Put the event in the signaled state. Exactly one |Wait()| will be unblocked
  // and the event will be returned to the unsignaled state.
  //
  // Notes (these are arguably bugs, but not worth working around):
  // * That |Wait()| may be one that occurs on the calling thread, *after* the
  //   call to |Signal()|.
  // * A |Signal()|, followed by a |Reset()|, may cause *no* waiting thread to
  //   be unblocked.
  // * We rely on pthreads's queueing for picking which waiting thread to
  //   unblock, rather than enforcing FIFO ordering.
  void Signal();

  // Put the event into the unsignaled state. Generally, this is not recommended
  // on an auto-reset event (see notes above).
  void Reset();

  // Blocks the calling thread until the event is signaled. Upon unblocking, the
  // event is returned to the unsignaled state, so that (unless |Reset()| is
  // called) each |Signal()| unblocks exactly one |Wait()|.
  void Wait();

  // Like |Wait()|, but with a timeout. Also unblocks if |timeout| expires
  // without being signaled in which case it returns true (otherwise, it returns
  // false).
//  bool WaitWithTimeout(TimeDelta timeout);

  // Returns whether this event is in a signaled state or not. For use in tests
  // only (in general, this is racy). Note: Unlike
  // |base::WaitableEvent::IsSignaled()|, this doesn't reset the signaled state.
  bool IsSignaledForTest();

 private:
  std::condition_variable cv_;
  std::mutex mutex_;

  // True if this event is in the signaled state.
  bool signaled_ = false;

  FML_DISALLOW_COPY_AND_ASSIGN(AutoResetWaitableEvent);
};

#endif // WAITABLE_EVENT_H
