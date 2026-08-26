#define BOOST_TEST_MODULE test_journal
#include <boost/test/included/unit_test.hpp>
#include "../pt1/journal.hpp"
#include <string>

BOOST_AUTO_TEST_CASE(test_init) {
  std::string s = "hello";
  int c = 1;
  journal master{s, c};
  BOOST_CHECK_EQUAL(1, master.lvl);
  BOOST_CHECK_EQUAL("hello", master.name);
  BOOST_CHECK_EQUAL("usual", master.lvl_name);
}
