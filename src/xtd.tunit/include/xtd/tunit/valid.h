/// @file
/// @brief Contains xtd::tunit::valid class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "assert.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The valid class contains a collection of static methods that implement the most common assertions used in xtd::tUnit.
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit
    /// @par Examples
    /// This example show how to used some methods :
    /// @include valid.cpp
    class valid final : private base_assert {
    public:
      /// @cond
      valid() = delete;
      /// @endcond
      
      /// @brief Valids that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::are_equal(24, int(24)); // test ok.
      /// xtd::tunit::valid::are_equal(23, int(24)); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual) {are_equal(expected, actual, "", line_info());}
      
      /// @brief Valids that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::are_equal(24, int(24), line_info_); // test ok.
      /// xtd::tunit::valid::are_equal(23, int(24), line_info_); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      
      /// @brief Valids that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::are_equal(24, int(24), "User message..."); // test ok.
      /// xtd::tunit::valid::are_equal(23, int(24), "User message..."); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual, const xtd::ustring& message) {are_equal(expected, actual, message, line_info());}
      
      /// @brief Valids that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::are_equal(24, int(24), "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::are_equal(23, int(24), "User message...", line_info_); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::are_equal(expected, actual, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @cond
      static void are_equal(const char* expected, const char* actual, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try{
          assert::are_equal(expected, actual, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void are_equal(const char8_t* expected, const char8_t* actual, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::are_equal(expected, actual, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void are_equal(const char16_t* expected, const char16_t* actual, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::are_equal(expected, actual, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }

      static void are_equal(const char32_t* expected, const char32_t* actual, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::are_equal(expected, actual, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }

      static void are_equal(const wchar_t* expected, const wchar_t* actual, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::are_equal(expected, actual, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }

      static void are_equal(float expected, float actual, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::are_equal(expected, actual, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void are_equal(double expected, double actual, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::are_equal(expected, actual, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void are_equal(long double expected, long double actual, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::are_equal(expected, actual, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      /// @endcond
      
      /// @brief Valids that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @par Examples
      /// @code
      /// float f = 0.00007999999999f;
      /// xtd::tunit::valid::are_equal_(0.00008f, f, 0.0000000000001f); // test ok.
      /// xtd::tunit::valid::are_equal_(0.00008f, f, 0.00000000000001f); // test fails.
      /// @endcode
      static void are_equal(float expected, float actual, float tolerance) {are_equal(expected, actual, tolerance, "", line_info_);}
      
      /// @brief Valids that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// float f = 0.00007999999999f;
      /// xtd::tunit::valid::are_equal_(0.00008f, f, 0.0000000000001f, line_info_); // test ok.
      /// xtd::tunit::valid::are_equal_(0.00008f, f, 0.00000000000001f, line_info_); // test fails.
      /// @endcode
      static void are_equal(float expected, float actual, float tolerance, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, tolerance, "", line_info);}
      
      /// @brief Valids that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// float f = 0.00007999999999f;
      /// xtd::tunit::valid::are_equal_(0.00008f, f, 0.0000000000001f, "User message..."); // test ok.
      /// xtd::tunit::valid::are_equal_(0.00008f, f, 0.00000000000001f, "User message..."); // test fails.
      /// @endcode
      static void are_equal(float expected, float& actual, float tolerance, const xtd::ustring& message) {are_equal(expected, actual, tolerance, message, line_info());}
      
      /// @brief Valids that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// float f = 0.00007999999999f;
      /// xtd::tunit::valid::are_equal_(0.00008f, f, 0.0000000000001f, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::are_equal_(0.00008f, f, 0.00000000000001f, "User message...", line_info_); // test fails.
      /// @endcode
      static void are_equal(float expected, float actual, float tolerance, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::are_equal(expected, actual, tolerance, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @par Examples
      /// @code
      /// double d = 0.00007999999999;
      /// xtd::tunit::valid::are_equal_(0.00008, d, 0.0000000000001); // test ok.
      /// xtd::tunit::valid::are_equal_(0.00008, d, 0.00000000000001); // test fails.
      /// @endcode
      static void are_equal(double expected, double actual, double tolerance) {are_equal(expected, actual, tolerance, "", line_info_);}
      
      /// @brief Valids that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// double d = 0.00007999999999;
      /// xtd::tunit::valid::are_equal_(0.00008, d, 0.0000000000001, line_info_); // test ok.
      /// xtd::tunit::valid::are_equal_(0.00008, d, 0.00000000000001, line_info_); // test fails.
      /// @endcode
      static void are_equal(double expected, double actual, double tolerance, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, tolerance, "", line_info);}
      
      /// @brief Valids that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// double d = 0.00007999999999;
      /// xtd::tunit::valid::are_equal_(0.00008, d, 0.0000000000001, "User message..."); // test ok.
      /// xtd::tunit::valid::are_equal_(0.00008, d, 0.00000000000001, "User message..."); // test fails.
      /// @endcode
      static void are_equal(double expected, double actual, double tolerance, const xtd::ustring& message) {are_equal(expected, actual, tolerance, message, line_info());}
      
      /// @brief Valids that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// double d = 0.00007999999999;
      /// xtd::tunit::valid::are_equal_(0.00008, d, 0.0000000000001, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::are_equal_(0.00008, d, 0.00000000000001, "User message...", line_info_); // test fails.
      /// @endcode
      static void are_equal(double expected, double actual, double tolerance, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::are_equal(expected, actual, tolerance, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @par Examples
      /// @code
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::valid::are_equal_(0.00008l, ld, 0.0000000000001l); // test ok.
      /// xtd::tunit::valid::are_equal_(0.00008l, ld, 0.00000000000001l); // test fails.
      /// @endcode
      static void are_equal(long double expected, long double actual, long double tolerance) {are_equal(expected, actual, tolerance, "", line_info_);}
      
      /// @brief Valids that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::valid::are_equal_(0.00008l, ld, 0.0000000000001l, line_info_); // test ok.
      /// xtd::tunit::valid::are_equal_(0.00008l, ld, 0.00000000000001l, line_info_); // test fails.
      /// @endcode
      static void are_equal(long double expected, long double actual, long double tolerance, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, tolerance, "", line_info);}
      
      /// @brief Valids that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::valid::are_equal_(0.00008l, ld, 0.0000000000001l, "User message..."); // test ok.
      /// xtd::tunit::valid::are_equal_(0.00008l, ld, 0.00000000000001l, "User message..."); // test fails.
      /// @endcode
      static void are_equal(long double expected, long double actual, long double tolerance, const xtd::ustring& message) {are_equal(expected, actual, tolerance, message, line_info());}
      
      /// @brief Valids that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::valid::are_equal_(0.00008l, ld, 0.0000000000001l, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::are_equal_(0.00008l, ld, 0.00000000000001l, "User message...", line_info_); // test fails.
      /// @endcode
      static void are_equal(long double expected, long double actual, long double tolerance, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::are_equal(expected, actual, tolerance, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::are_not_equal(23, int(24)); // test ok.
      /// xtd::tunit::valid::are_not_equal(24, int(24)); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual) {are_not_equal(expected, actual, "", line_info());}
      
      /// @brief Valids that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::are_not_equal(23, int(24), line_info_); // test ok.
      /// xtd::tunit::valid::are_not_equal(24, int(24), line_info_); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual, const xtd::tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
      
      /// @brief Valids that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::are_not_equal(23, int(24), "User message..."); // test ok.
      /// xtd::tunit::valid::are_not_equal(24, int(24), "User message..."); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual, const xtd::ustring& message) {are_not_equal(expected, actual, message, line_info());}
      
      /// @brief Valids that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::are_not_equal(23, int(24), "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::are_not_equal(24, int(24), "User message...", line_info_); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::are_not_equal(expected, actual, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }

      /// @cond
      static void are_not_equal(const char* expected, const char* actual, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::are_not_equal(expected, actual, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void are_not_equal(const char8_t* expected, const char8_t* actual, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::are_not_equal(expected, actual, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void are_not_equal(const char16_t* expected, const char16_t* actual, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::are_not_equal(expected, actual, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void are_not_equal(const char32_t* expected, const char32_t* actual, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::are_not_equal(expected, actual, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void are_not_equal(const wchar_t* expected, const wchar_t* actual, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::are_not_equal(expected, actual, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      /// @endcond

      /// @brief Valids that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::valid::are_not_same(c, a); // test ok.
      /// xtd::tunit::valid::are_not_same(b, a); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_same(const expected_t& expected, const actual_t& actual) {are_not_same(expected, actual, "", line_info());}
      
      /// @brief Valids that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::valid::are_not_same(c, a, line_info_); // test ok.
      /// xtd::tunit::valid::are_not_same(b, a, line_info); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_same(const expected_t& expected, const actual_t& actual, const xtd::tunit::line_info& line_info) {are_not_same(expected, actual, "", line_info);}
      
      /// @brief Valids that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::valid::are_not_same(c, a, "User message..."); // test ok.
      /// xtd::tunit::valid::are_not_same(b, a, "User message..."); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_same(const expected_t& expected, const actual_t& actual, const xtd::ustring& message) {are_not_same(expected, actual, message, line_info());}
      
      /// @brief Valids that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::valid::are_not_same(c, a, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::are_not_same(b, a, "User message...", line_info); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_same(const expected_t& expected, const actual_t& actual, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::are_not_same(expected, actual, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::valid::are_same(b, a); // test ok.
      /// xtd::tunit::valid::are_same(c, a); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_same(const expected_t& expected, const actual_t& actual) {are_same(expected, actual, "", line_info());}
      
      /// @brief Valids that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::valid::are_same(b, a, line_info_); // test ok.
      /// xtd::tunit::valid::are_same(c, a, line_info_); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_same(const expected_t& expected, const actual_t& actual, const xtd::tunit::line_info& line_info) {are_same(expected, actual, "", line_info);}
      
      /// @brief Valids that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::valid::are_same(b, a, "User message..."); // test ok.
      /// xtd::tunit::valid::are_same(c, a, "User message..."); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_same(const expected_t& expected, const actual_t& actual, const xtd::ustring& message) {are_same(expected, actual, message, line_info());}
      
      /// @brief Valids that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::valid::are_same(b, a, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::are_same(c, a, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_same(const expected_t& expected, const actual_t& actual, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::are_same(expected, actual, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::valid::contains(2, v1); // test ok.
      /// xtd::tunit::valid::contains(4, v1); // test fails.
      /// @endcode
      template<typename item_t, typename collection_t>
      static void contains(const item_t& item, const collection_t& collection) {contains(item, collection, "", line_info());}
      
      /// @brief Valids that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::valid::contains(2, v1, line_info_); // test ok.
      /// xtd::tunit::valid::contains(4, v1, line_info_); // test fails.
      /// @endcode
      template<typename item_t, typename collection_t>
      static void contains(const item_t& item, const collection_t& collection, const xtd::tunit::line_info& line_info) {contains(item, collection, "", line_info);}
      
      /// @brief Valids that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::valid::contains(2, v1, "User message..."); // test ok.
      /// xtd::tunit::valid::contains(4, v1, "User message..."); // test fails.
      /// @endcode
      template<typename item_t, typename collection_t>
      static void contains(const item_t& item, const collection_t& collection, const xtd::ustring& message) {contains(item, collection, message, line_info());}
      
      /// @brief Valids that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::valid::contains(2, v1, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::contains(4, v1, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename item_t, typename collection_t>
      static void contains(const item_t& item, const collection_t& collection, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::contains(item, collection, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename item_t, typename value_t>
      static void contains(const item_t& item, const std::initializer_list<value_t>& values) {contains(item, values, "", line_info());}
      template<typename item_t, typename value_t>
      static void contains(const item_t& item, const std::initializer_list<value_t>& values, const xtd::tunit::line_info& line_info) {contains(item, values, "", line_info);}
      template<typename item_t, typename value_t>
      static void contains(const item_t& item, const std::initializer_list<value_t>& values, const xtd::ustring& message) {contains(item, values, message, line_info());}
      template<typename item_t, typename value_t>
      static void contains(const item_t& item, const std::initializer_list<value_t>& values, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::contains(item, values, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void contains(char item, const char* values, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::contains(item, values, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void contains(char8_t item, const char8_t* values, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::contains(item, values, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void contains(char16_t item, const char16_t* values, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::contains(item, values, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void contains(char32_t item, const char32_t* values, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::contains(item, values, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }

      static void contains(wchar_t item, const wchar_t* values, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::contains(item, values, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      /// @endcond
      
      /// @brief Valids that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::valid::does_not_throw([&] {v1.at(2);}); // test ok.
      /// xtd::tunit::valid::does_not_throw([&] {v1.at(5);}); // test fails.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement) {does_not_throw(statement, "", line_info());}
      
      /// @brief Valids that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::valid::does_not_throw([&] {v1.at(2);}, line_info_); // test ok.
      /// xtd::tunit::valid::does_not_throw([&] {v1.at(5);}, line_info_); // test fails.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement, const xtd::tunit::line_info& line_info) {does_not_throw(statement, "", line_info);}
      
      /// @brief Valids that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::valid::does_not_throw([&] {v1.at(2);}, "User message..."); // test ok.
      /// xtd::tunit::valid::does_not_throw([&] {v1.at(5);}, "User message..."); // test fails.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement, const xtd::ustring& message) {does_not_throw(statement, message, line_info());}
      
      /// @brief Valids that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::valid::does_not_throw([&] {v1.at(2);}, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::does_not_throw([&] {v1.at(5);}, "User message...", line_info_); // test fails.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::does_not_throw(statement, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
     
      /// @brief Valids that collection contains an item.
      /// @param value The value to check is empty.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::valid::is_empty(v1); // test ok.
      /// xtd::tunit::valid::is_empty(v2); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_empty(const value_t& value) {is_empty(value, "", line_info());}
      
      /// @brief Valids that collection contains an item.
      /// @param value The value to check is empty.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::valid::is_empty(v1, line_info_); // test ok.
      /// xtd::tunit::valid::is_empty(v2, line_info_); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_empty(const value_t& value, const xtd::tunit::line_info& line_info) {is_empty(value, "", line_info);}
      
      /// @brief Valids that collection contains an item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::valid::is_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_empty(v2, "User message..."); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_empty(const value_t& value, const xtd::ustring& message) {is_empty(value, message, line_info());}
      
      /// @brief Valids that collection contains an item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::valid::is_empty(v1, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_empty(v2, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_empty(const value_t& value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_empty(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename value_t>
      static void is_empty(const std::initializer_list<value_t>& value) {is_empty(value, "", line_info());}
      template<typename value_t>
      static void is_empty(const std::initializer_list<value_t>& value, const xtd::tunit::line_info& line_info) {is_empty(value, "", line_info);}
      template<typename value_t>
      static void is_empty(const std::initializer_list<value_t>& value, const xtd::ustring& message) {is_empty(value, message, line_info());}
      template<typename value_t>
      static void is_empty(const std::initializer_list<value_t>& values, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_empty(values, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void is_empty(const char* value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_empty(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void is_empty(const char8_t* value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_empty(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void is_empty(const char16_t* value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_empty(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void is_empty(const char32_t* value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_empty(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }

      static void is_empty(const wchar_t* value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_empty(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      /// @endocnd
      
      /// @brief Valids that ta condition is false.
      /// @param condition The condition to check is false.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::valid::is_false(std::empty(s1)); // test ok.
      /// xtd::tunit::valid::is_false(std::empty(s2)); // test fails.
      /// @endcode
      static void is_false(bool condition) {is_false(condition, "", line_info());}
      
      /// @brief Valids that a condition is false.
      /// @param condition The condition to check is false.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::valid::is_false(std::empty(s1), line_info_); // test ok.
      /// xtd::tunit::valid::is_false(std::empty(s2), line_info_); // test fails.
      /// @endcode
      static void is_false(bool condition, const xtd::tunit::line_info& line_info) {is_false(condition, "", line_info);}
      
      /// @brief Valids that a condition is false.
      /// @param condition The condition to check is false.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::valid::is_false(std::empty(s1), "User message..."); // test ok.
      /// xtd::tunit::valid::is_false(std::empty(s2), "User message..."); // test fails.
      /// @endcode
      static void is_false(bool condition, const xtd::ustring& message) {is_false(condition, message, line_info());}
      
      /// @brief Valids that a condition is false.
      /// @param condition The condition to check is false.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::valid::is_false(std::empty(s1), "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_false(std::empty(s2), "User message...", line_info_); // test fails.
      /// @endcode
      static void is_false(bool condition, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_false(condition, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_greater(24, 12); // test ok.
      /// xtd::tunit::valid::is_greater(24, 48); // test fails.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater(const value1_t& val1, const value2_t& val2) {is_greater(val1, val2, "", line_info());}
      
      /// @brief Valids that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_greater(24, 12, line_info_); // test ok.
      /// xtd::tunit::valid::is_greater(24, 48, line_info_); // test fails.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater(const value1_t& val1, const value2_t& val2, const xtd::tunit::line_info& line_info) {is_greater(val1, val2, "", line_info);}
      
      /// @brief Valids that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_greater(24, 12, "User message..."); // test ok.
      /// xtd::tunit::valid::is_greater(24, 48, "User message..."); // test fails.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater(const value1_t& val1, const value2_t& val2, const xtd::ustring& message) {is_greater(val1, val2, message, line_info());}
      
      /// @brief Valids that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_greater(24, 12, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_greater(24, 48, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater(const value1_t& val1, const value2_t& val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_greater(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @cond
      static void is_greater(const char* val1, const char* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_greater(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void is_greater(const char8_t* val1, const char8_t* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_greater(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void is_greater(const char16_t* val1, const char16_t* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_greater(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }

      static void is_greater(const char32_t* val1, const char32_t* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_greater(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }

      static void is_greater(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_greater(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      /// @endcond

      /// @brief Valids that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_greater_or_equal(24, 12); // test ok.
      /// xtd::tunit::valid::is_greater_or_equal(24, 24); // test ok.
      /// xtd::tunit::valid::is_greater_or_equal(24, 48); // test fails.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater_or_equal(const value1_t& val1, const value2_t& val2) {is_greater_or_equal(val1, val2, "", line_info());}
      
      /// @brief Valids that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_greater_or_equal(24, 12, line_info_); // test ok.
      /// xtd::tunit::valid::is_greater_or_equal(24, 24, line_info_); // test ok.
      /// xtd::tunit::valid::is_greater_or_equal(24, 48, line_info_); // test fails.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater_or_equal(const value1_t& val1, const value2_t& val2, const xtd::tunit::line_info& line_info) {is_greater_or_equal(val1, val2, "", line_info);}
      
      /// @brief Valids that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_greater_or_equal(24, 12, "User message..."); // test ok.
      /// xtd::tunit::valid::is_greater_or_equal(24, 24, "User message..."); // test ok.
      /// xtd::tunit::valid::is_greater_or_equal(24, 48, "User message..."); // test fails.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater_or_equal(const value1_t& val1, const value2_t& val2, const xtd::ustring& message) {is_greater_or_equal(val1, val2, message, line_info());}
      
      /// @brief Valids that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_greater_or_equal(24, 12, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_greater_or_equal(24, 24, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_greater_or_equal(24, 48, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater_or_equal(const value1_t& val1, const value2_t& val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_greater_or_equal(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @cond
      static void is_greater_or_equal(const char* val1, const char* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_greater_or_equal(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void is_greater_or_equal(const char8_t* val1, const char8_t* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_greater_or_equal(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void is_greater_or_equal(const char16_t* val1, const char16_t* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_greater_or_equal(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void is_greater_or_equal(const char32_t* val1, const char32_t* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_greater_or_equal(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }

      static void is_greater_or_equal(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_greater_or_equal(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      /// @endcond

      /// @brief Valids that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::valid::is_instance_of<std::logic_error>(except); // test ok.
      /// xtd::tunit::valid::is_instance_of<std::bad_cast>(except); test fails
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_instance_of(const value_t& value) {is_instance_of<type_t>(value, "", line_info());}
      
      /// @brief Valids that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::valid::is_instance_of<std::logic_error>(except, line_info_); // test ok.
      /// xtd::tunit::valid::is_instance_of<std::bad_cast>(except, line_info_); test fails
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_instance_of(const value_t& value, const xtd::tunit::line_info& line_info) {is_instance_of<type_t>(value, "", line_info);}
      
      /// @brief Valids that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::valid::is_instance_of<std::logic_error>(except, "User message..."); // test ok.
      /// xtd::tunit::valid::is_instance_of<std::bad_cast>(except, "User message..."); test fails
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_instance_of(const value_t& value, const xtd::ustring& message) {is_instance_of<type_t>(value, message, line_info());}
      
      /// @brief Valids that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::valid::is_instance_of<std::logic_error>(except, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_instance_of<std::bad_cast>(except, "User message...", line_info_); test fails
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_instance_of(const value_t& value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_instance_of<type_t>(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_less(24, 48); // test ok.
      /// xtd::tunit::valid::is_less(24, 12); // test fails.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less(const value1_t& val1, const value2_t& val2) {is_less(val1, val2, "", line_info());}
      
      /// @brief Valids that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_less(24, 48, line_info_); // test ok.
      /// xtd::tunit::valid::is_less(24, 12, line_info_); // test fails.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less(const value1_t& val1, const value2_t& val2, const xtd::tunit::line_info& line_info) {is_less(val1, val2, "", line_info);}
      
      /// @brief Valids that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_less(24, 48, "User message..."); // test ok.
      /// xtd::tunit::valid::is_less(24, 12, "User message..."); // test fails.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less(const value1_t& val1, const value2_t& val2, const xtd::ustring& message) {is_less(val1, val2, message, line_info());}
      
      /// @brief Valids that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_less(24, 48, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_less(24, 12, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less(const value1_t& val1, const value2_t& val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_less(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @cond
      static void is_less(const char* val1, const char* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_less(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void is_less(const char8_t* val1, const char8_t* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_less(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void is_less(const char16_t* val1, const char16_t* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_less(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void is_less(const char32_t* val1, const char32_t* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_less(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }

      static void is_less(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_less(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      /// @endcond

      /// @brief Valids that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_less_or_equal(24, 48); // test ok.
      /// xtd::tunit::valid::is_less_or_equal(24, 24); // test ok.
      /// xtd::tunit::valid::is_less_or_equal(24, 12); // test fails.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less_or_equal(const value1_t& val1, const value2_t& val2) {is_less_or_equal(val1, val2, "", line_info());}
      
      /// @brief Valids that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_less_or_equal(24, 48, line_info_); // test ok.
      /// xtd::tunit::valid::is_less_or_equal(24, 24, line_info_); // test ok.
      /// xtd::tunit::valid::is_less_or_equal(24, 12, line_info_); // test fails.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less_or_equal(const value1_t& val1, const value2_t& val2, const xtd::tunit::line_info& line_info) {is_less_or_equal(val1, val2, "", line_info);}
      
      /// @brief Valids that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_less_or_equal(24, 48, "User message..."); // test ok.
      /// xtd::tunit::valid::is_less_or_equal(24, 24, "User message..."); // test ok.
      /// xtd::tunit::valid::is_less_or_equal(24, 12, "User message..."); // test fails.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less_or_equal(const value1_t& val1, const value2_t& val2, const xtd::ustring& message) {is_less_or_equal(val1, val2, message, line_info());}
      
      /// @brief Valids that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_less_or_equal(24, 48, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_less_or_equal(24, 24, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_less_or_equal(24, 12, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less_or_equal(const value1_t& val1, const value2_t& val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_less_or_equal(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @cond
      static void is_less_or_equal(const char* val1, const char* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_less_or_equal(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void is_less_or_equal(const char8_t* val1, const char8_t* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_less_or_equal(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void is_less_or_equal(const char16_t* val1, const char16_t* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_less_or_equal(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void is_less_or_equal(const char32_t* val1, const char32_t* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_less_or_equal(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }

      static void is_less_or_equal(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_less_or_equal(val1, val2, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      /// @endcond

      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::valid::is_NaN(v1); // test ok.
      /// xtd::tunit::valid::is_NaN(v2); // test fails.
      /// @endcode
      static void is_NaN(double value) {is_NaN(value, "", line_info());}
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::valid::is_NaN(v1, line_info_); // test ok.
      /// xtd::tunit::valid::is_NaN(v2, line_info_); // test fails.
      /// @endcode
      static void is_NaN(double value, const xtd::tunit::line_info& line_info) {is_NaN(value, "", line_info);}
      
      /// @brief Valids that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::valid::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_NaN(v2, "User message..."); // test fails.
      /// @endcode
      static void is_NaN(double value, const xtd::ustring& message) {is_NaN(value, message, line_info());}
      
      /// @brief Valids that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::valid::is_NaN(v1, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_NaN(v2, "User message...", line_info_); // test fails.
      /// @endcode
      static void is_NaN(double value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_NaN(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @par Examples
      /// @code
      /// long double v1 = std::numeric_limits<double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::valid::is_NaN(v1); // test ok.
      /// xtd::tunit::valid::is_NaN(v2); // test fails.
      /// @endcode
      static void is_NaN(long double value) {is_NaN(value, "", line_info());}
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// long double v1 = std::numeric_limits<long double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::valid::is_NaN(v1, line_info_); // test ok.
      /// xtd::tunit::valid::is_NaN(v2, line_info_); // test fails.
      /// @endcode
      static void is_NaN(long double value, const xtd::tunit::line_info& line_info) {is_NaN(value, "", line_info);}
      
      /// @brief Valids that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// long double v1 = std::numeric_limits<long double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::valid::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_NaN(v2, "User message..."); // test fails.
      /// @endcode
      static void is_NaN(long double value, const xtd::ustring& message) {is_NaN(value, message, line_info());}
      
      /// @brief Valids that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// long double v1 = std::numeric_limits<long double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::valid::is_NaN(v1, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_NaN(v2, "User message...", line_info_); // test fails.
      /// @endcode
      static void is_NaN(long double value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_NaN(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::valid::is_NaN(v1); // test ok.
      /// xtd::tunit::valid::is_NaN(v2); // test fails.
      /// @endcode
      static void is_NaN(float value) {is_NaN(value, "", line_info());}
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::valid::is_NaN(v1, line_info_); // test ok.
      /// xtd::tunit::valid::is_NaN(v2, line_info_); // test fails.
      /// @endcode
      static void is_NaN(float value, const xtd::tunit::line_info& line_info) {is_NaN(value, "", line_info);}
      
      /// @brief Valids that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::valid::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_NaN(v2, "User message..."); // test fails.
      /// @endcode
      static void is_NaN(float value, const xtd::ustring& message) {is_NaN(value, message, line_info());}
      
      /// @brief Valids that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::valid::is_NaN(v1, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_NaN(v2, "User message...", line_info_); // test fails.
      /// @endcode
      static void is_NaN(float value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_NaN(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that ta condition is negative.
      /// @param value The value to check is negative.
      /// @par Examples
      /// @code
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::valid::is_negative(i1); // test ok.
      /// xtd::tunit::valid::is_negative(i2); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_negative(const value_t& value) {is_negative(value, "", line_info());}
      
      /// @brief Valids that ta condition is negative.
      /// @param value The value to check is negative.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::valid::is_negative(i1, line_info_); // test ok.
      /// xtd::tunit::valid::is_negative(i2, line_info_); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_negative(const value_t& value, const xtd::tunit::line_info& line_info) {is_negative(value, "", line_info);}
      
      /// @brief Valids that ta condition is negative.
      /// @param value The value to check is negative.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::valid::is_negative(i1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_negative(i2, "User message..."); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_negative(const value_t& value, const xtd::ustring& message) {is_negative(value, message, line_info());}
      
      /// @brief Valids that ta condition is negative.
      /// @param value The value to check is negative.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::valid::is_negative(i1, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_negative(i2, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_negative(const value_t& value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_negative(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that collection oes not contain any item.
      /// @param value The value to check is empty.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::valid::is_not_empty(v1); // test ok.
      /// xtd::tunit::valid::is_not_empty(v2); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_not_empty(const value_t& value) {is_not_empty(value, "", line_info());}
      
      /// @brief Valids that collection does not contain any item.
      /// @param value The value to check is empty.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::valid::is_not_empty(v1, line_info_); // test ok.
      /// xtd::tunit::valid::is_not_empty(v2, line_info_); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_not_empty(const value_t& value, const xtd::tunit::line_info& line_info) {is_not_empty(value, "", line_info);}
      
      /// @brief Valids that collection does not contain any item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::valid::is_not_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_not_empty(v2, "User message..."); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_not_empty(const value_t& value, const xtd::ustring& message) {is_not_empty(value, message, line_info());}
      
      /// @brief Valids that collection does not contain any item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::valid::is_not_empty(v1, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_not_empty(v2, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_not_empty(const value_t& value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_not_empty(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename value_t>
      static void is_not_empty(const std::initializer_list<value_t>& value) {is_not_empty(value, "", line_info());}
      template<typename value_t>
      static void is_not_empty(const std::initializer_list<value_t>& value, const xtd::tunit::line_info& line_info) {is_not_empty(value, "", line_info);}
      template<typename value_t>
      static void is_not_empty(const std::initializer_list<value_t>& value, const xtd::ustring& message) {is_not_empty(value, message, line_info());}
      template<typename value_t>
      static void is_not_empty(const std::initializer_list<value_t>& value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_not_empty(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void is_not_empty(const char* value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_not_empty(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void is_not_empty(const char8_t* value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_not_empty(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void is_not_empty(const char16_t* value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_not_empty(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      static void is_not_empty(const char32_t* value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_not_empty(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }

      static void is_not_empty(const wchar_t* value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_not_empty(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      /// @endcond
      
      /// @brief Valids that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::valid::is_not_instance_of<std::bad_cast>(except); // test ok.
      /// xtd::tunit::valid::is_not_instance_of<std::logic_error>(except); test fails
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_not_instance_of(const value_t& value) {is_not_instance_of<type_t>(value, "", line_info());}
      
      /// @brief Valids that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::valid::is_not_instance_of<std::bad_cast>(except, line_info_); // test ok.
      /// xtd::tunit::valid::is_not_instance_of<std::logic_error>(except, line_info_); test fails
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_not_instance_of(const value_t& value, const xtd::tunit::line_info& line_info) {is_not_instance_of<type_t>(value, "", line_info);}
      
      /// @brief Valids that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::valid::is_not_instance_of<std::bad_cast>(except, "User message..."); // test ok.
      /// xtd::tunit::valid::is_not_instance_of<std::logic_error>(except, "User message..."); test fails
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_not_instance_of(const value_t& value, const xtd::ustring& message) {is_not_instance_of<type_t>(value, message, line_info());}
      
      /// @brief Valids that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::valid::is_not_instance_of<std::bad_cast>(except, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_not_instance_of<std::logic_error>(except, "User message...", line_info_); test fails
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_not_instance_of(const value_t& value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_not_instance_of<type_t>(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::valid::is_not_null(s1); // test ok.
      /// xtd::tunit::valid::is_not_null(s2); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const pointer_t* pointer) {is_not_null(pointer, "", line_info());}
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::valid::is_not_null(s1, line_info_); // test ok.
      /// xtd::tunit::valid::is_not_null(s2, line_info_); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const pointer_t* pointer, const xtd::tunit::line_info& line_info) {is_not_null(pointer, "", line_info);}
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::valid::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_not_null(s2, "User message..."); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const pointer_t* pointer, const xtd::ustring& message) {is_not_null(pointer, message, line_info());}
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::valid::is_not_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_not_null(s2, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const pointer_t* pointer, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_not_null(pointer, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1); // test ok.
      /// xtd::tunit::valid::is_not_null(s2); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::unique_ptr<pointer_t>& pointer) {is_not_null(pointer, "", line_info());}
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1, line_info_); // test ok.
      /// xtd::tunit::valid::is_not_null(s2, line_info_); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::unique_ptr<pointer_t>& pointer, const xtd::tunit::line_info& line_info) {is_not_null(pointer, "", line_info);}
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_not_null(s2, "User message..."); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::unique_ptr<pointer_t>& pointer, const xtd::ustring& message) {is_not_null(pointer, message, line_info());}
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_not_null(s2, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::unique_ptr<pointer_t>& pointer, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_not_null(pointer, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1); // test ok.
      /// xtd::tunit::valid::is_not_null(s2); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::shared_ptr<pointer_t>& pointer) {is_not_null(pointer, "", line_info());}
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1, line_info_); // test ok.
      /// xtd::tunit::valid::is_not_null(s2, line_info_); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::shared_ptr<pointer_t>& pointer, const xtd::tunit::line_info& line_info) {is_not_null(pointer, "", line_info);}
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_not_null(s2, "User message..."); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::shared_ptr<pointer_t>& pointer, const xtd::ustring& message) {is_not_null(pointer, message, line_info());}
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_not_null(s2, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::shared_ptr<pointer_t>& pointer, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_not_null(pointer, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1); // test ok.
      /// xtd::tunit::valid::is_not_null(s2); // test ok.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::weak_ptr<pointer_t>& pointer) {is_not_null(pointer, "", line_info());}
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1, line_info_); // test ok.
      /// xtd::tunit::valid::is_not_null(s2, line_info_); // test ok.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::weak_ptr<pointer_t>& pointer, const xtd::tunit::line_info& line_info) {is_not_null(pointer, "", line_info);}
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_not_null(s2, "User message..."); // test ok.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::weak_ptr<pointer_t>& pointer, const xtd::ustring& message) {is_not_null(pointer, message, line_info());}
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_not_null(s2, "User message...", line_info_); // test ok.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::weak_ptr<pointer_t>& pointer, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {assert::succeed(message, line_info);}
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_not_null(nullptr); // test fails.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer) {is_not_null(pointer, "", line_info());}
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_not_null(nullptr, line_info_); // test fails.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer, const xtd::tunit::line_info& line_info) {is_not_null(pointer, "", line_info);}
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_not_null(nullptr, "User message..."); // test fails.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer, const xtd::ustring& message) {is_not_null(pointer, message, line_info());}
      
      /// @brief Valids that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_not_null(nullptr, "User message...", line_info_); // test fails.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_not_null(pointer, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @par Examples
      /// @code
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::valid::is_not_zero(i1); // test ok.
      /// xtd::tunit::valid::is_not_zero(i2); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_not_zero(const value_t& value) {is_not_zero(value, "", line_info());}
      
      /// @brief Valids that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::valid::is_not_zero(i1, line_info_); // test ok.
      /// xtd::tunit::valid::is_not_zero(i2, line_info_); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_not_zero(const value_t& value, const xtd::tunit::line_info& line_info) {is_not_zero(value, "", line_info);}
      
      /// @brief Valids that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::valid::is_not_zero(i1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_not_zero(i2, "User message..."); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_not_zero(const value_t& value, const xtd::ustring& message) {is_not_zero(value, message, line_info());}
      
      /// @brief Valids that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::valid::is_not_zero(i1, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_not_zero(i2, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_not_zero(const value_t& value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_zero(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::valid::is_null(s1); // test ok.
      /// xtd::tunit::valid::is_null(s2); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const pointer_t* pointer) {is_null(pointer, "", line_info());}
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::valid::is_null(s1, line_info_); // test ok.
      /// xtd::tunit::valid::is_null(s2, line_info_); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const pointer_t* pointer, const xtd::tunit::line_info& line_info) {is_null(pointer, "", line_info);}
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::valid::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_null(s2, "User message..."); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const pointer_t* pointer, const xtd::ustring& message) {is_null(pointer, message, line_info());}
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::valid::is_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_null(s2, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const pointer_t* pointer, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_null(pointer, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::valid::is_null(s1); // test ok.
      /// xtd::tunit::valid::is_null(s2); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::unique_ptr<pointer_t>& pointer) {is_null(pointer, "", line_info());}
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::valid::is_null(s1, line_info_); // test ok.
      /// xtd::tunit::valid::is_null(s2, line_info_); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::unique_ptr<pointer_t>& pointer, const xtd::tunit::line_info& line_info) {is_null(pointer, "", line_info);}
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::valid::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_null(s2, "User message..."); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::unique_ptr<pointer_t>& pointer, const xtd::ustring& message) {is_null(pointer, message, line_info());}
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::valid::is_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_null(s2, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::unique_ptr<pointer_t>& pointer, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_null(pointer, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::valid::is_null(s1); // test ok.
      /// xtd::tunit::valid::is_null(s2); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::shared_ptr<pointer_t>& pointer) {is_null(pointer, "", line_info());}
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::valid::is_null(s1, line_info_); // test ok.
      /// xtd::tunit::valid::is_null(s2, line_info_); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::shared_ptr<pointer_t>& pointer, const xtd::tunit::line_info& line_info) {is_null(pointer, "", line_info);}
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::valid::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_null(s2, "User message..."); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::shared_ptr<pointer_t>& pointer, const xtd::ustring& message) {is_null(pointer, message, line_info());}
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::valid::is_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_null(s2, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::shared_ptr<pointer_t>& pointer, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_null(pointer, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @remarks Always false, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::valid::is_null(s1); // test fails.
      /// xtd::tunit::valid::is_null(s2); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::weak_ptr<pointer_t>& pointer) {is_null(pointer, "", line_info());}
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always false, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::valid::is_null(s1, line_info_); // test fails.
      /// xtd::tunit::valid::is_null(s2, line_info_); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::weak_ptr<pointer_t>& pointer, const xtd::tunit::line_info& line_info) {is_null(pointer, "", line_info);}
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @remarks Always false, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::valid::is_null(s1, "User message..."); // test fails.
      /// xtd::tunit::valid::is_null(s2, "User message..."); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::weak_ptr<pointer_t>& pointer, const xtd::ustring& message) {is_null(pointer, message, line_info());}
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always false, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::valid::is_null(s1, "User message...", line_info_); // test fails.
      /// xtd::tunit::valid::is_null(s2, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::weak_ptr<pointer_t>& pointer, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_null(pointer, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_null(nullptr); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer) {is_null(pointer, "", line_info());}
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_null(nullptr, line_info_); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer, const xtd::tunit::line_info& line_info) {is_null(pointer, "", line_info);}
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_null(nullptr, "User message..."); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer, const xtd::ustring& message) {is_null(pointer, message, line_info());}
      
      /// @brief Valids that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::valid::is_null(nullptr, "User message...", line_info_); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {assert::succeed(message, line_info);}
      
      /// @brief Valids that ta condition is positive.
      /// @param value The value to check is positive.
      /// @par Examples
      /// @code
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::valid::is_positive(i1); // test ok.
      /// xtd::tunit::valid::is_positive(i2); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_positive(const value_t& value) {is_positive(value, "", line_info());}
      
      /// @brief Valids that ta condition is positive.
      /// @param value The value to check is positive.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::valid::is_positive(i1, line_info_); // test ok.
      /// xtd::tunit::valid::is_positive(i2, line_info_); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_positive(const value_t& value, const xtd::tunit::line_info& line_info) {is_positive(value, "", line_info);}
      
      /// @brief Valids that ta condition is positive.
      /// @param value The value to check is positive.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::valid::is_positive(i1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_positive(i2, "User message..."); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_positive(const value_t& value, const xtd::ustring& message) {is_positive(value, message, line_info());}
      
      /// @brief Valids that ta condition is positive.
      /// @param value The value to check is positive.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::valid::is_positive(i1, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_positive(i2, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_positive(const value_t& value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_positive(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that ta condition is true.
      /// @param condition The condition to check is true.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::valid::is_false(std::empty(s1)); // test ok.
      /// xtd::tunit::valid::is_false(std::empty(s2)); // test fails.
      /// @endcode
      static void is_true(bool condition) {is_true(condition, "", line_info());}
      
      /// @brief Valids that a condition is true.
      /// @param condition The condition to check is true.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::valid::is_false(std::empty(s1), line_info_); // test ok.
      /// xtd::tunit::valid::is_false(std::empty(s2), line_info_); // test fails.
      /// @endcode
      static void is_true(bool condition, const xtd::tunit::line_info& line_info) {is_true(condition, "", line_info);}
      
      /// @brief Valids that a condition is true.
      /// @param condition The condition to check is true.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::valid::is_false(std::empty(s1), "User message..."); // test ok.
      /// xtd::tunit::valid::is_false(std::empty(s2), "User message..."); // test fails.
      /// @endcode
      static void is_true(bool condition, const xtd::ustring& message) {is_true(condition, message, line_info());}
      
      /// @brief Valids that a condition is true.
      /// @param condition The condition to check is true.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::valid::is_false(std::empty(s1), "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_false(std::empty(s2), "User message...", line_info_); // test fails.
      /// @endcode
      static void is_true(bool condition, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_true(condition, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that ta condition is zero.
      /// @param value The value to check is zero.
      /// @par Examples
      /// @code
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::valid::is_zero(i1); // test ok.
      /// xtd::tunit::valid::is_zero(i2); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_zero(const value_t& value) {is_zero(value, "", line_info());}
      
      /// @brief Valids that ta condition is zero.
      /// @param value The value to check is zero.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::valid::is_zero(i1, line_info_); // test ok.
      /// xtd::tunit::valid::is_zero(i2, line_info_); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_zero(const value_t& value, const xtd::tunit::line_info& line_info) {is_zero(value, "", line_info);}
      
      /// @brief Valids that ta condition is zero.
      /// @param value The value to check is zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::valid::is_zero(i1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_zero(i2, "User message..."); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_zero(const value_t& value, const xtd::ustring& message) {is_zero(value, message, line_info());}
      
      /// @brief Valids that ta condition is zero.
      /// @param value The value to check is zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::valid::is_zero(i1, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::is_zero(i2, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename value_t>
      static void is_zero(const value_t& value, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::is_zero(value, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that the statement throws a particular exception when called.
      /// @tparam exception_t The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::valid::throws<std::out_of_range>([&] {v1.at(5);}); // test ok.
      /// xtd::tunit::valid::throws<std::out_of_range>([&] {v1.at(2);}); // test fails.
      /// @endcode
      template<typename exception_t>
      static void throws(const std::function<void()>& statement) {throws<exception_t>(statement, "", line_info());}
      
      /// @brief Valids that the statement throws a particular exception when called.
      /// @tparam exception_t The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::valid::throws<std::out_of_range>([&] {v1.at(5);}, line_info_); // test ok.
      /// xtd::tunit::valid::throws<std::out_of_range>([&] {v1.at(2);}, line_info_); // test fails.
      /// @endcode
      template<typename exception_t>
      static void throws(const std::function<void()>& statement, const xtd::tunit::line_info& line_info) {throws<exception_t>(statement, "", line_info);}
      
      /// @brief Valids that the statement throws a particular exception when called.
      /// @tparam exception_t The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::valid::throws<std::out_of_range>([&] {v1.at(5);}, "User message..."); // test ok.
      /// xtd::tunit::valid::throws<std::out_of_range>([&] {v1.at(2);}, "User message..."); // test fails.
      /// @endcode
      template<typename exception_t>
      static void throws(const std::function<void()>& statement, const xtd::ustring& message) {throws<exception_t>(statement, message, line_info());}
      
      /// @brief Valids that the statement throws a particular exception when called.
      /// @tparam exception_t The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::valid::throws<std::out_of_range>([&] {v1.at(5);}, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::throws<std::out_of_range>([&] {v1.at(2);}, "User message...", line_info_); // test fails.
      /// @endcode
      template<typename exception_t>
      static void throws(const std::function<void()>& statement, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::throws<exception_t>(statement, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @brief Valids that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::valid::throws_any([&] {v1.at(5);}); // test ok.
      /// xtd::tunit::valid::throws_any([&] {v1.at(2);}); // test fails.
      /// @endcode
      static void throws_any(const std::function<void()>& statement) {throws_any(statement, "", line_info());}
      
      /// @brief Valids that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::valid::throws_any([&] {v1.at(5);}, line_info_); // test ok.
      /// xtd::tunit::valid::throws_any([&] {v1.at(2);}, line_info_); // test fails.
      /// @endcode
      static void throws_any(const std::function<void()>& statement, const xtd::tunit::line_info& line_info) {throws_any(statement, "", line_info);}
      
      /// @brief Valids that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::valid::throws_any([&] {v1.at(5);}, "User message..."); // test ok.
      /// xtd::tunit::valid::throws_any([&] {v1.at(2);}, "User message..."); // test fails.
      /// @endcode
      static void throws_any(const std::function<void()>& statement, const xtd::ustring& message) {throws_any(statement, message, line_info());}
      
      /// @brief Valids that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::valid::throws_any([&] {v1.at(5);}, "User message...", line_info_); // test ok.
      /// xtd::tunit::valid::throws_any([&] {v1.at(2);}, "User message...", line_info_); // test fails.
      /// @endcode
      static void throws_any(const std::function<void()>& statement, const xtd::ustring& message, const xtd::tunit::line_info& line_info) {
        try {
          assert::throws_any(statement, message, line_info);
        } catch (...) {
          base_assert::error();
        }
      }
    };
  }
}
