/// @file
/// @brief Contains xtd::tunit::tunit_event_args class.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @cond
    class unit_test;
    /// @endcond
    
    /// @brief tunit_event_args is the base class for classes containing event data.
    class tunit_event_args {
    public:
      /// @brief Create a new instance of class tunit_event_args
      explicit tunit_event_args(const xtd::tunit::unit_test& unit_test) : ut_(unit_test) {};
      
      /// @cond
      tunit_event_args(const tunit_event_args&) = default;
      tunit_event_args& operator=(const tunit_event_args&) = default;
      virtual ~tunit_event_args() = default;
      /// @endcond
      
      const xtd::tunit::unit_test& unit_test() const {return this->ut_;}

    private:
      const xtd::tunit::unit_test& ut_;
    };
  }
}
