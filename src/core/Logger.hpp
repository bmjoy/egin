#pragma once
#include <string>

namespace core {
  class Logger {
  private:
  public:
    Logger();
    void log(const char* message, ...);
    ~Logger();
  protected:
  };

  extern Logger logger;
}