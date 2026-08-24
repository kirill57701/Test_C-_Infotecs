#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include "journal.hpp"

journal::journal(std::string name_init, int l_init): name(name_init), lvl(l_init){
  if (lvl == 1) {
    lvl_name = "usual";
  } else if (lvl == 2) {
    lvl_name = "attention";
  } else {
    lvl_name = "err";
  }
}

void journal::change_lvl(int new_lvl) {
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

void journal::save_mess(std::string mess, int l) {
  if (l >= lvl) {
    if (mess.size() == 0) {
      throw std::logic_error("err, enter message and time");
    }
    time_t t = std::time(nullptr);
    tm* timer = localtime(&t);
    std::ofstream out;
    out.open(name, std::ios::app);
    out << "name: " << name << "\nlevel: " << lvl << "\nmessage: " << mess << "\ntime: " << timer->tm_hour << ':' << timer->tm_min << ':' << timer->tm_sec;
    out.close();
  } else {
    throw std::logic_error("err, lvl is small");
  }
}
