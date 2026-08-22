#ifndef JOURNAL_HPP
#define JOURNAL_HPP
#include <string>
#include <iostream>

struct journal {
  string s;
  int lvl;
  string imp;
  journal(string name, int l) {
    s = name;
    lvl = lvl;
  }
  void print_info() {
    cout << "name " << s << "\nlevel " << lvl;
  }
};

#endif
