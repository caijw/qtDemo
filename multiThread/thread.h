#ifndef THREAD_H
#define THREAD_H

#include <atomic>
#include <memory>
#include <thread>
#include "macros.h"


class Thread {
 public:
  explicit Thread(const std::string& name = "");

  ~Thread();

//  fml::RefPtr<fml::TaskRunner> GetTaskRunner() const;

  void Join();

  static void SetCurrentThreadName(const std::string& name);

 private:
  std::unique_ptr<std::thread> thread_;
//  fml::RefPtr<fml::TaskRunner> task_runner_;
  std::atomic_bool joined_;

  FML_DISALLOW_COPY_AND_ASSIGN(Thread);
};

#endif // THREAD_H
