#include <xtd/xtd.strings>
#include <xtd/tunit>

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_wstring_string_format) {
  public:
    void test_method_(format_string_with_default_argument) {
      assert::are_equal(L"string", strings::format(L"{0}", L"string"));
    }
    
    void test_method_(format_string_with_left_alignment) {
      assert::are_equal(L"    string", strings::format(L"{0,10}", L"string"));
    }
    
    void test_method_(format_string_with_right_alignment) {
      assert::are_equal(L"string    ", strings::format(L"{0, -10}", L"string"));
    }
    
    void test_method_(format_string_with_left_alignment_to_zero) {
      assert::are_equal(L"string", strings::format(L"{0,0}", L"string"));
    }
    
    void test_method_(format_string_with_invalid_format) {
      assert::are_equal(L"string", strings::format(L"{0:invalid}", L"string"));
    }
    
    void test_method_(format_string_with_decimal_format) {
      assert::are_equal(L"string", strings::format(L"{0:D}", L"string"));
    }
  };
}
