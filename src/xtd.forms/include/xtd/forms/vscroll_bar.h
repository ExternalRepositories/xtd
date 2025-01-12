/// @file
/// @brief Contains xtd::forms::vscroll_bar control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "scroll_bar.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows vscroll_bar.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of vscroll_bar control.
    /// @include vscroll_bar.cpp
    /// @par Windows
    /// @image html vscroll_bar_w.png
    /// <br>
    /// @image html vscroll_bar_wd.png
    /// @par macOS
    /// @image html vscroll_bar_m.png
    /// <br>
    /// @image html vscroll_bar_md.png
    /// @par Gnome
    /// @image html vscroll_bar_g.png
    /// <br>
    /// @image html vscroll_bar_gd.png
    class forms_export_ vscroll_bar : public scroll_bar {
    public:
      /// @brief Initializee a new instance of vscroll_bar class.
      vscroll_bar();
      xtd::drawing::size default_size() const override {return {17, 80};}
      
    protected:
      xtd::forms::create_params create_params() const override;
    };
  }
}
