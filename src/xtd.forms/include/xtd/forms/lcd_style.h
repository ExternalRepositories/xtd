/// @file
/// @brief Contains xtd::forms::lcd_style enum class.
#pragma once
#include <xtd/strings.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
  enum class lcd_style {
    seven_segment_display,
    nine_segment_display,
    fourteen_segment_display,
    sixteen_segment_display,
    dot_matrix_display,
  };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, lcd_style value) {return os << to_string(value, {{lcd_style::seven_segment_display, "seven_segment_display"}, {lcd_style::nine_segment_display, "nine_segment_display"}, {lcd_style::fourteen_segment_display, "fourteen_segment_display"}, {lcd_style::sixteen_segment_display, "sixteen_segment_display"}, {lcd_style::dot_matrix_display, "dot_matrix_display"}});}
    inline std::wostream& operator<<(std::wostream& os, lcd_style value) {return os << to_string(value, {{lcd_style::seven_segment_display, L"seven_segment_display"}, {lcd_style::nine_segment_display, L"nine_segment_display"}, {lcd_style::fourteen_segment_display, L"fourteen_segment_display"}, {lcd_style::sixteen_segment_display, L"sixteen_segment_display"}, {lcd_style::dot_matrix_display, L"dot_matrix_display"}});}
    /// @endcond
  }
}
