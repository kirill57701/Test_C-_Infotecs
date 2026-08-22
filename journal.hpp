#ifndef JOURNAL_HPP
#define JOURNAL_HPP
#include <string>
#include <iostream>

struct journal {
  std::string s;
  int lvl;
  std::string imp;
  journal(std::string name, int l): s(name), lvl(l)
  {}
  void print_info() {
    std::cout << "name " << s << "\nlevel " << lvl << "\n";
  }
};

#endif
