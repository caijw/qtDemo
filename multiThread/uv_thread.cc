#include "uv_thread.h"
#include <pthread.h>
#include <memory>
#include <string>
#include "waitable_event.h"
#include <unistd.h>
#include <iostream>

UVThread::UVThread(const std::string& name) : joined_(false) {
  AutoResetWaitableEvent latch;
  thread_ = std::unique_ptr<std::thread>(new std::thread( [&latch, name]() -> void {
      SetCurrentThreadName(name);
      latch.Signal();
      // TODO(kingweicai): run uv loop
      while(true) {
        sleep(1);
        std::cout << "thread running" << std::endl;
      }
    }) );
  latch.Wait();
}

UVThread::~UVThread() {
  Join();
}

void UVThread::Join() {
  if (joined_) {
    return;
  }
  joined_ = true;
  thread_->join();
}

void UVThread::SetCurrentThreadName(const std::string& name) {
  if (name == "") {
    return;
  }
   pthread_setname_np(pthread_self(), name.c_str());
}

