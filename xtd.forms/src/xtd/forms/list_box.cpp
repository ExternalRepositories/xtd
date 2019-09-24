#include <xtd/forms/native/control.hpp>
#include <xtd/forms/native/list_box.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include <xtd/forms/native/window_list_box.hpp>
#include "../../../include/xtd/forms/list_box.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

list_box::list_box() {
  this->back_color_ = this->default_back_color();
  this->fore_color_ = this->default_fore_color();
  this->size_ = this->default_size();

  this->items_.item_added += [&](size_t pos, const item& item) {
    native::list_box::insert_item(this->handle_, pos, item.value());
    if (this->sorted_) std::sort(this->items_.begin(), this->items_.end());
    list_box::item selected_item;
    if (this->selected_index_ != -1 && this->selected_index_ < this->items_.size()) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);
  };

  this->items_.item_erased += [&](size_t pos, const item& item) {
    native::list_box::delete_item(this->handle_, pos);

    list_box::item selected_item;
    if (this->selected_index_ != -1 && this->selected_index_ < this->items_.size()) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);
  };
}

list_box& list_box::border_style(forms::border_style border_style) {
  if (this->border_style_ != border_style) {
    this->border_style_ = border_style;
    this->recreate_handle();
  }
  return *this;
}

list_box& list_box::selected_index(size_t selected_index) {
  if (this->selected_index_ != selected_index) {
    if (selected_index != -1 && selected_index > this->items_.size()) throw invalid_argument("out of range index");
    this->selected_index_ = selected_index;
    native::list_box::selected_index(this->handle_, this->selected_index_);

    item selected_item;
    if (this->selected_index_ != -1) selected_item = this->items_[this->selected_index_];
    this->selected_item(selected_item);

    this->on_selected_index_changed(event_args::empty);
  }
  return *this;
}

vector<size_t> list_box::selected_indices() const {
  return native::list_box::selected_indices(this->handle_);
}

list_box& list_box::selected_item(const item& selected_item) {
  if (this->selected_item_ != selected_item) {
    this->selected_item_ = selected_item;
    auto it = std::find(this->items_.begin(), this->items_.end(), selected_item);
    size_t index = -1;
    if (it != this->items_.end()) index = it - this->items_.begin();
    this->selected_index(index);
    if (index == -1) this->selected_item_ = "";
    this->on_selected_value_changed(event_args::empty);
  }
  return *this;
}


vector<list_box::item> list_box::selected_items() const {
  vector<item> items;
  for (size_t index : this->selected_indices())
    items.push_back(this->items_[index]);
  return items;
}

list_box& list_box::selection_mode(forms::selection_mode selection_mode) {
  if (this->selection_mode_ != selection_mode) {
    this->selection_mode_ = selection_mode;
    this->recreate_handle();
  }
  return *this;
}

list_box& list_box::sorted(bool sorted) {
  if (this->sorted_ != sorted) {
    this->sorted_ = sorted;
    if (this->sorted_) std::sort(this->items_.begin(), this->items_.end());
    this->recreate_handle();
  }
  return *this;
}

forms::create_params list_box::create_params() const {
  forms::create_params create_params = this->list_control::create_params();

  create_params.class_name("listbox");
  create_params.style(create_params.style() | LBS_HASSTRINGS);

  switch (this->selection_mode_) {
  case selection_mode::none: create_params.style(create_params.style() | LBS_NOSEL); break;
  case selection_mode::one:  break;
  case selection_mode::multi_simple: create_params.style(create_params.style() | LBS_MULTIPLESEL); break;
  case selection_mode::multi_extended: create_params.style(create_params.style() | LBS_MULTIPLESEL | LBS_EXTENDEDSEL); break;
  default: break;
  }

  if (this->sorted_) create_params.style(create_params.style() | LBS_SORT);

  if (this->border_style_ == forms::border_style::fixed_single) create_params.style(create_params.style() | WS_BORDER);
  else if (this->border_style_ == forms::border_style::fixed_3d) create_params.ex_style(create_params.ex_style() | WS_EX_CLIENTEDGE);

  return create_params;
}

void list_box::on_handle_created(const event_args& e) {
  this->list_control::on_handle_created(e);
  for (size_t index = 0; index < this->items_.size(); ++index)
    native::list_box::insert_item(this->handle_, index, this->items_[index].value());
  if (this->selection_mode_ == forms::selection_mode::none) this->selected_index(-1);
  native::list_box::selected_index(this->handle_, this->selected_index_);
  if (this->selected_index_ != -1) this->selected_item_ = this->items_[this->selected_index_];
}

void list_box::wnd_proc(message& message) {
  switch (message.msg()) {
  case WM_LBUTTONDOWN: this->wm_mouse_down(message); break;
  case WM_LBUTTONUP: this->wm_mouse_up(message); break;
  case WM_LBUTTONDBLCLK: this->wm_mouse_double_click(message); break;
  case WM_REFLECT + WM_COMMAND: wm_reflect_command(message); break;
  default: this->list_control::wnd_proc(message);
  }
}

void list_box::wm_mouse_double_click(message& message) {
  this->selected_index(native::list_box::selected_index(this->handle_));
  this->selected_item_ = this->items_[this->selected_index_];
  if (this->selection_mode() != forms::selection_mode::none)
    this->list_control::wnd_proc(message);
}

void list_box::wm_mouse_down(message& message) {
  if (this->selection_mode() != forms::selection_mode::none)
    this->list_control::wnd_proc(message);
}

void list_box::wm_mouse_up(message& message) {
  this->selected_index(native::list_box::selected_index(this->handle_));
  this->selected_item_ = this->items_[this->selected_index_];
  if (this->selection_mode() != forms::selection_mode::none)
    this->list_control::wnd_proc(message);
}

void list_box::wm_reflect_command(message& message) {
  this->def_wnd_proc(message);
  this->selected_index(native::list_box::selected_index(this->handle_));
  this->selected_item_ = this->items_[this->selected_index_];
  this->on_selected_index_changed(event_args::empty);
  this->on_selected_value_changed(event_args::empty);
}
