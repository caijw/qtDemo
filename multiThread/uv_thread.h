#ifndef UV_THREAD_H
#define UV_THREAD_H

#include <atomic>
#include <memory>
#include <thread>
#include "macros.h"
#include "uv.h"


class UVThread {
 public:
  explicit UVThread(const std::string& name = "");

  ~UVThread();

//  fml::RefPtr<fml::TaskRunner> GetTaskRunner() const;

  void Join();

  static void SetCurrentThreadName(const std::string& name);

 private:
  std::unique_ptr<std::thread> thread_;
//  fml::RefPtr<fml::TaskRunner> task_runner_;
  std::atomic_bool joined_;
  uv_loop_t *loop;
  static void wait_for_a_while(uv_idle_t* handle);
  FML_DISALLOW_COPY_AND_ASSIGN(UVThread);
};

#endif // THREAD_H
