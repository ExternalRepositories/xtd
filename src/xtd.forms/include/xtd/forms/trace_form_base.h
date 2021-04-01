/// @file
/// @brief Contains xtd::forms::trace_form_base dialog.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <chrono>
#include <xtd/drawing/font_family.h>
#include "form.h"
#include "text_box.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a base form for ebug and trace form.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms forms
    class trace_form_base : public xtd::forms::form {
    public:
      xtd::forms::control& dock(xtd::forms::dock_style dock) override {
        if (dock == xtd::forms::dock_style::left) bounds({xtd::forms::screen::get_working_area(handle_).left(), xtd::forms::screen::get_working_area(handle_).top(), xtd::forms::screen::get_working_area(handle_).width() / 4, xtd::forms::screen::get_working_area(handle_).height()});
        else if (dock == xtd::forms::dock_style::top) bounds({xtd::forms::screen::get_working_area(handle_).left(), xtd::forms::screen::get_working_area(handle_).top(), xtd::forms::screen::get_working_area(handle_).width(), xtd::forms::screen::get_working_area(handle_).height() / 4});
        else if (dock == xtd::forms::dock_style::right) bounds({xtd::forms::screen::get_working_area(handle_).left() + xtd::forms::screen::get_working_area(handle_).width() - xtd::forms::screen::get_working_area(handle_).width() / 4, xtd::forms::screen::get_working_area(handle_).top(), xtd::forms::screen::get_working_area(handle_).width() / 4, xtd::forms::screen::get_working_area(handle_).height()});
        else if (dock == xtd::forms::dock_style::bottom) bounds({xtd::forms::screen::get_working_area(handle_).left(), xtd::forms::screen::get_working_area(handle_).top() + xtd::forms::screen::get_working_area(handle_).height() - xtd::forms::screen::get_working_area(handle_).height() / 4, xtd::forms::screen::get_working_area(handle_).width(), xtd::forms::screen::get_working_area(handle_).height() / 4});
        else if (dock == xtd::forms::dock_style::fill) bounds({xtd::forms::screen::get_working_area(handle_).left(), xtd::forms::screen::get_working_area(handle_).top(), xtd::forms::screen::get_working_area(handle_).width(), xtd::forms::screen::get_working_area(handle_).height()});
        return xtd::forms::control::dock(dock);
      }
      
      bool show_date() const {return show_date_;}
      void show_date(bool value) {
        if (show_date_ != value) {
          show_date_ = value;
          update_format();
        }
      }
      
      bool show_time() const {return show_time_;}
      void show_time(bool value) {
        if (show_time_ != value) {
          show_time_ = value;
          update_format();
        }
      }

    protected:
      trace_form_base(const std::string& text) {
        name("__xtd_forms_trace_form");
        text_.name("__xtd_forms_trace_form_text");

        dock(xtd::forms::dock_style::bottom);
        start_position(xtd::forms::form_start_position::manual);
        font(xtd::drawing::font(xtd::drawing::font_family::generic_monospace(), font().size()));
        this->text(text);
        
        text_.dock(xtd::forms::dock_style::fill);
        text_.multiline(true);
        text_.parent(*this);
        text_.read_only(true);
        text_.word_wrap(false);
        update_format();
      }
      
      void on_form_closing(form_closing_event_args& e) override {
        e.cancel(true);
        window_state(form_window_state::minimized);
        form::on_form_closing(e);
      }

      virtual void write(const std::string& trace) {
        if (need_header()) write_header();
        text_.append_text(trace);
      }
      
      virtual void write_line(const std::string& trace) {
        if (need_header()) write_header();
        text_.append_text(trace);
        text_.append_text("\n");
        need_header(true);
      }
      
      void write_header() {
        auto now =  std::chrono::system_clock::now();
        text_.append_text(xtd::strings::format(format_, now, (std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch())).count() % 1000000));
        need_header_ = false;
      }
      
      bool need_header() const {return need_header_;}
      void need_header(bool value) {need_header_ = value;}

    private:
      void update_format() {
        format_ = "";
        if (show_date_ && show_time_) format_ = "{0:u}.{1:D6} - " + format_;
        else if (show_date_) format_ = "{0:L}-{0:k}-{0:i} - " + format_;
        else if (show_time_) format_ = "{0:t}.{1:D6} - " + format_;
      }

      bool need_header_ = true;
      bool show_date_ = true;
      bool show_time_ = true;
      std::string format_ = "{0}";
      xtd::forms::text_box text_;
    };
  }
}
