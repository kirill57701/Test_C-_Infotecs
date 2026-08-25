#ifndef LOG_HPP
#define LOG_HPP
#include <string>

struct logger {
  std::string mess;
  int lvl;
  void log_mess(std::string)
};


#endif
