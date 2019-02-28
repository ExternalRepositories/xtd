#include "assert_unit_tests.hpp"
#include <xtd/tunit>

namespace unit_tests {
  class test_class_(test_assert_are_equal_float_with_tolerence_succeed) {
  public:
    void test_method_(test_case_succeed) {
      float f = 0.599f;
      xtd::tunit::assert::are_equal(0.6f, f, 0.01f, xtd::tunit::line_info {"test_assert_are_equal_float_with_tolerence_succeed.cpp", 9});
    }
  };
}

void test_(test_assert_are_equal_float_with_tolerence_succeed, test_output) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_are_equal_float_with_tolerence_succeed.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_("Start 1 test from 1 test case\n"
                "  SUCCEED test_assert_are_equal_float_with_tolerence_succeed.test_case_succeed\n"
                "End 1 test from 1 test case ran.\n", ss.str());
}

void test_(test_assert_are_equal_float_with_tolerence_succeed, test_result) {
  std::stringstream ss;
  xtd::tunit::settings::default_settings().exit_status(0);
  xtd::tunit::settings::default_settings().filter_tests("test_assert_are_equal_float_with_tolerence_succeed.*");
  xtd::tunit::settings::default_settings().show_duration(false);
  int result = xtd::tunit::unit_test(std::make_unique<assert_unit_tests::unit_tests_event_listener>(ss)).run();
  assert_value_(0, result);
}
