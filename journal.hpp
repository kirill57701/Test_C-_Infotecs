#ifndef JOURNAL_HPP
#define JOURNAL_HPP
#include <string>
#include <iostream>
#include <fstream>

struct journal {
  std::string s;
  int lvl;
  std::string txt;
  std::string t;
  journal(std::string name, int l): s(name), lvl(l)
  {}
  void print_info() {
    std::cout << "name " << s << "\nlevel " << lvl << "\nmessage " << txt << "\ntime " << t << "\n";
  }
  void save_mess(std::string mess, std::string time, int l) {
    if (l >= lvl) {
      if (mess.size() == 0 || time.size() == 0) {
        throw std::logic_error("err, enter message and time");
      }
      txt = mess;
      t = time;
    } else {
      throw std::logic_error("err, lvl is small");
    }
  }
  void change_lvl(int new_lvl) {
    if (new_lvl < lvl) {
      throw std::logic_error("err, lvl small");
    } else {
      lvl = new_lvl;
    }
  }
  void save_file(std::string s) {
    std::ofstream out;
    out.open(s);
    out << "name: " << s << "\nlevel: " << lvl << "\nmessage: " << txt << "\ntime: " << t << "\n";
    out.close();
  }
  void save_file() {
    std::string s;
    std::cin >> s;
    std::ofstream out;
    out.open(s);
    out << "name: " << s << "\nlevel: " << lvl << "\nmessage: " << txt << "\ntime: " << t << "\n";
    out.close();
  }
};

#endif
