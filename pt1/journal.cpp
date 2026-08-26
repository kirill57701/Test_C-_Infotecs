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
  lvl = new_lvl;
  if (lvl == 1) {
    lvl_name = "usual";
  } else if (lvl == 2) {
    lvl_name = "attention";
  } else {
    lvl_name = "err";
  }
}

void journal::save_mess(std::string mess, int l) {
  if (l >= lvl) {
    if (mess.size() == 0) {
      std::cerr << "err";
      return;
    }
    time_t t = std::time(nullptr);
    tm* timer = localtime(&t);
    std::ofstream out;
    out.open(name, std::ios::app);
    out << "\nname: " << name << "\nlevel: " << (l == 1 ? "usual" : (l == 2 ? "attention" : "err")) << "\nmessage: " << mess << "\ntime: " << timer->tm_hour << ':' << timer->tm_min << ':' << timer->tm_sec << "\n";
    out.close();
  } else {
    std::cerr << "err, lvl small\n";
    return;
  }
}
