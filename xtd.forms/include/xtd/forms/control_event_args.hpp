#pragma once
#include <cstdint>
#include <xtd/event_args.hpp>
#include <xtd/drawing/point.hpp>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond
    class control_event_args : public event_args {
    public:
      control_event_args() = default;
      
      control_event_args(const forms::control& control) : control_(&control) {}
      
      /// @cond
      control_event_args(const control_event_args& control_event_args) = default;
      control_event_args& operator=(const control_event_args& control_event_args) = default;
      /// @endcond
      
      const forms::control& control() const {return *this->control_;}
      
    private:
      const forms::control* control_ = nullptr;
    };
  }
}
