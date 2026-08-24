#ifndef JOURNAL_HPP
#define JOURNAL_HPP
#include <string>
#include <iostream>
#include <fstream>

struct journal {
  std::string name;
  int lvl;
  std::string txt;
  std::string time;
  journal(std::string name_init, int l_init): name(name_init), lvl(l_init)
  {}
  void print_info() {
    std::cout << "name " << name << "\nlevel " << lvl << "\nmessage " << txt << "\ntime " << time << "\n";
  }
  void save_mess(std::string mess, std::string time_save, int l) {
    if (l >= lvl) {
      if (mess.size() == 0 || time_save.size() == 0) {
        throw std::logic_error("err, enter message and time");
      }
      txt = mess;
      time = time_save;
    } else {
      throw std::logic_error("err, lvl is small");
    }
  }
  void change_lvl(int new_lvl) {
    if (new_lvl < lvl) {
      return;
    } else {
      lvl = new_lvl;
    }
  }
  void save_file(std::string s) {
    std::ofstream out;
    out.open(s);
    out << "name: " << name << "\nlevel: " << lvl << "\nmessage: " << txt << "\ntime: " << time << "\n";
    out.close();
  }
  void save_file() {
    std::string s;
    std::cin >> s;
    std::ofstream out;
    out.open(s);
    out << "name: " << name << "\nlevel: " << lvl << "\nmessage: " << txt << "\ntime: " << time << "\n";
    out.close();
  }
};

#endif
