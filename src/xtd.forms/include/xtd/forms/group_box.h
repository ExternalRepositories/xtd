/// @file
/// @brief Contains xtd::forms::group_box container.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "border_style.h"
#include "flat_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class forms_export_ group_box : public control {
    public:
      group_box();

      virtual forms::auto_size_mode auto_size_mode() const {return auto_size_mode_;}
      virtual group_box& auto_size_mode(forms::auto_size_mode value);
      
      drawing::size default_size() const override {return {200, 100};}
      
    protected:
      forms::create_params create_params() const override;
      
      drawing::size measure_control() const override;
      
      void on_font_changed(const xtd::event_args& e) override;
      
      void on_resize(const xtd::event_args& e) override;
      
      void on_text_changed(const xtd::event_args& e) override;
      
      /// @cond
      xtd::forms::flat_style flat_style_ = xtd::forms::flat_style::system;
      /// @endcond
    };
  }
}
