#ifndef JOURNAL_HPP
#define JOURNAL_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

struct journal {
  std::string name;
  int lvl;
  std::string txt;
  tm* timer;
  journal(std::string name_init, int l_init): name(name_init), lvl(l_init)
  {}
  void print_info() {
    std::cout << "name " << name << "\nlevel " << lvl << "\nmessage " << txt << "\ntime ";
    std::printf("%d:%d:%d\n", timer->tm_hour, timer->tm_min, timer->tm_sec);
  }
  void save_mess(std::string mess, int l) {
    if (l >= lvl) {
      if (mess.size() == 0) {
        throw std::logic_error("err, enter message and time");
      }
      txt = mess;
      time_t t = std::time(nullptr);
      timer = localtime(&t);
      std::printf("%d:%d:%d\n", timer->tm_hour, timer->tm_min, timer->tm_sec);
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
    out << "name " << name << "\nlevel " << lvl << "\nmessage " << txt << "\ntime " << timer->tm_hour << ':' << timer->tm_min << ':' << timer->tm_sec;
    out.close();
  }
  void save_file() {
    std::string s;
    std::cin >> s;
    std::ofstream out;
    out.open(s);
    out << "name " << name << "\nlevel " << lvl << "\nmessage " << txt << "\ntime " << timer->tm_hour << ':' << timer->tm_min << ':' << timer->tm_sec;
    out.close();
  }
};

#endif
