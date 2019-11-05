#pragma once
#include "border_style.hpp"
#include "text_box_base.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class text_box : public text_box_base {
    public:
      text_box();

      virtual forms::border_style border_style() const {return this->border_style_;}
      virtual text_box& border_style(forms::border_style border_style);
      
      drawing::color default_back_color() const override {return drawing::system_colors::window();}
      
      drawing::color default_fore_color() const override {return drawing::system_colors::window_text();}
      
      drawing::size default_size() const override {return {100, 20};}

      using text_box_base::text;
      control& text(const ustring& text) override;
      
    protected:
      forms::create_params create_params() const override;
      
      drawing::size measure_control() const override;

      forms::border_style border_style_ = forms::border_style::fixed_single;
    };
  }
}
