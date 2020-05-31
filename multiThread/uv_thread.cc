#include "uv_thread.h"
#include <pthread.h>
#include <memory>
#include <string>
#include "waitable_event.h"
#include <unistd.h>
#include <iostream>
#include "stdlib.h"

UVThread::UVThread(const std::string& name) : joined_(false) {
  AutoResetWaitableEvent latch;
  thread_ = std::unique_ptr<std::thread>(new std::thread( [&latch, name, this]() -> void {
      SetCurrentThreadName(name);
      loop = uv_default_loop();
      uv_loop_init(loop);
      uv_idle_t idler;
      idler.data = this;
      uv_idle_init(uv_default_loop(), &idler);
      uv_idle_start(&idler, wait_for_a_while);

      latch.Signal();

      uv_run(loop, UV_RUN_DEFAULT);
      uv_loop_close(loop);
      free(loop);
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

void UVThread::wait_for_a_while(uv_idle_t* handle) {
    std::cout << "idle run" << std::endl;
    sleep(1);
}

