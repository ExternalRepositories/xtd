#include <xtd/environment.hpp>
#include <xtd/diagnostics/cdebug.hpp>
#include <xtd/forms/native/radio_button.hpp>
#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/window_button.hpp>
#include "../../../include/xtd/forms/radio_button.hpp"

using namespace xtd;
using namespace xtd::forms;

radio_button::radio_button() {
  this->size_ = this->default_size();
}

radio_button& radio_button::appearance(forms::appearance appearance) {
  if (this->appearance_ != appearance) {
    this->appearance_ = appearance;
    this->recreate_handle();
    this->on_appearance_changed(event_args::empty);
  }
  return *this;
}

radio_button& radio_button::auto_check(bool auto_check) {
  if (this->auto_check_ != auto_check) {
    this->auto_check_ = auto_check;
  }
  return *this;
}

radio_button& radio_button::checked(bool checked) {
  if (this->checked_ != checked) {
    this->checked_ = checked;
    native::radio_button::checked(this->handle_, this->checked_);
    this->on_checked_changed(event_args::empty);
    if (this->checked_ == true && this->auto_check_ == true && this->parent_) {
      for (auto control : this->parent().controls()) {
        if (dynamic_cast<radio_button*>(&control.get()) != nullptr && &control.get() != this && static_cast<radio_button&>(control.get()).auto_check_ == true)
          static_cast<radio_button&>(control.get()).checked(false);
      }
    }
  }
  return *this;
}

void radio_button::perform_click() {
  this->on_click(event_args::empty);
}

forms::create_params radio_button::create_params() const {
  forms::create_params create_params = this->button_base::create_params();
  
  create_params.class_name("radiobutton");
  if (this->auto_check_) create_params.style(create_params.style() | BS_AUTORADIOBUTTON);
  else create_params.style(create_params.style() | BS_RADIOBUTTON);
  if (this->appearance_ == forms::appearance::button) create_params.style(create_params.style() | BS_PUSHLIKE);

  return create_params;
}

drawing::size radio_button::measure_control() const {
  return this->button_base::measure_text() + drawing::size(20, 0);
}

void radio_button::on_handle_created(const event_args &e) {
  this->button_base::on_handle_created(e);
  native::radio_button::checked(this->handle_, this->checked_);
}

void radio_button::wnd_proc(message &message) {
  switch (message.msg()) {
    case WM_LBUTTONDOWN: break;
    case WM_LBUTTONDBLCLK: this->wm_mouse_double_click(message); break;
    case WM_LBUTTONUP: this->wm_mouse_up(message); break;
    default: this->button_base::wnd_proc(message);
  }
}

void radio_button::wm_mouse_double_click(message& message) {
  this->on_double_click(event_args::empty);
}

void radio_button::wm_mouse_up(message& message) {
  if (this->auto_check_) this->checked(true);
  this->on_click(event_args::empty);
}

