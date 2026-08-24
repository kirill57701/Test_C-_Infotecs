#ifndef JOURNAL_HPP
#define JOURNAL_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

struct journal {
  std::string name;
  int lvl;
  std::string lvl_name;
  journal(std::string name_init, int l_init): name(name_init), lvl(l_init) {
    if (lvl == 1) {
      lvl_name = "usual";
    } else if (lvl == 2) {
      lvl_name = "attention";
    } else {
      lvl_name = "err";
    }
  }
  void save_mess(std::string mess, int l) {
    if (l >= lvl) {
      if (mess.size() == 0) {
        throw std::logic_error("err, enter message and time");
      }
      time_t t = std::time(nullptr);
      tm* timer = localtime(&t);
      std::ofstream out;
      out.open(name);
      out << "name: " << name << "\nlevel: " << lvl << "\nmessage: " << mess << "\ntime: " << timer->tm_hour << ':' << timer->tm_min << ':' << timer->tm_sec;
      out.close();
    } else {
      throw std::logic_error("err, lvl is small");
    }
  }
  void change_lvl(int new_lvl) {
    if (new_lvl < lvl) {
      return;
    } else {
      lvl = new_lvl;
      if (lvl == 1) {
        lvl_name = "usual";
      } else if (lvl == 2) {
        lvl_name = "attention";
      } else {
        lvl_name = "err";
      }
    }
  }
};

#endif
