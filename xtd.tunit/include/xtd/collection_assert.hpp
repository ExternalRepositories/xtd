/// @file
/// @brief Contains xtd::tunit::assert class.
#pragma once
#include "assert.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The string_assert class contains a collection of static methods that implement the most string assertions used in xtd::tUnit.
    /// @par Examples
    /// This example show how to used some methods :
    /// @include assert.cpp
    class collection_assert final {
    public:
      /// @cond
      collection_assert() = delete;
      /// @endcond

      /// @brief Asserts that all collection items are of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
      /// xtd::tunit::collection_assert::collection_assert::all_items_are_instances_of<std::ios_base*>(a); // test ok.
      /// xtd::tunit::collection_assert::collection_assert::all_items_are_instances_of<std::basic_ostream<char>*>(a); test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TCollection>
      static void all_items_are_instances_of(const TCollection& collection) {all_items_are_instances_of<TExpected>(collection, "", line_info());}

      /// @brief Asserts that all collection items are of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
      /// xtd::tunit::collection_assert::collection_assert::all_items_are_instances_of<std::ios_base*>(a, "User message..."); // test ok.
      /// xtd::tunit::collection_assert::collection_assert::all_items_are_instances_of<std::basic_ostream<char>*>(a, "User message..."); test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TCollection>
      static void all_items_are_instances_of(const TCollection& collection, const std::string& message) {all_items_are_instances_of<TExpected>(collection, message, line_info());}

      /// @brief Asserts that all collection items are of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
      /// xtd::tunit::collection_assert::collection_assert::all_items_are_instances_of<std::ios_base*>(a, line_info_); // test ok.
      /// xtd::tunit::collection_assert::collection_assert::all_items_are_instances_of<std::basic_ostream<char>*>(a, line_info_); test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TCollection>
      static void are_equal(const TCollection& collection, const xtd::tunit::line_info& line_info) {all_items_are_instances_of<TExpected>(collection, "", line_info);}
      
      /// @brief Asserts that all collection items are of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
      /// xtd::tunit::collection_assert::collection_assert::all_items_are_instances_of<std::ios_base*>(a, "User message...", line_info_); // test ok.
      /// xtd::tunit::collection_assert::collection_assert::all_items_are_instances_of<std::basic_ostream<char>*>(a, "User message...", line_info_); test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TCollection>
      static void all_items_are_instances_of(const TCollection& collection, const std::string& message, const xtd::tunit::line_info& line_info) {
        for (auto it = collection.begin(); it != collection.end(); ++it)
          if (dynamic_cast<TExpected>(*it) == nullptr) {
            assert::fail("all items instance of <" + __demangle(typeid(TExpected).name()) + ">", __join__items(collection), message, line_info);
            return;
          }
        assert::succeed(message, line_info);
      }
   };
  }
}
