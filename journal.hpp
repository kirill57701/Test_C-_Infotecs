#ifndef JOURNAL_HPP
#define JOURNAL_HPP
#include <string>
#include <iostream>

struct journal {
  std::string s;
  int lvl;
  std::string imp;
  std::string txt;
  std::string t;
  journal(std::string name, int l): s(name), lvl(l)
  {}
  void print_info() {
    std::cout << "name " << s << "\nlevel " << lvl << "\nmessage " << txt << "\ntime " << t;
  }
  void save_mess(std::string mess, std::string time) {
    if (mess.size() == 0 || time.size() == 0) {
      throw std::logic_error("err, enter message and time");
    }
    txt = mess;
    t = time;
  }
};

#endif
