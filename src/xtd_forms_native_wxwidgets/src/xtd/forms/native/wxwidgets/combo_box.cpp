#include <stdexcept>
#include <xtd/drawing/system_colors.hpp>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/combo_box.hpp>
#include "wx_combo_box.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void combo_box::begin_update(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Freeze();
}

void combo_box::delete_item(intptr_t control, size_t index) {
  if (control == 0) return;
  static_cast<wxComboBox*>(reinterpret_cast<control_handler*>(control)->control())->Delete(index);
}

void combo_box::end_update(intptr_t control) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->Thaw();
}

void combo_box::insert_item(intptr_t control, size_t index, const ustring& value) {
  if (control == 0) return;
  if (!static_cast<wxComboBox*>(reinterpret_cast<control_handler*>(control)->control())->IsSorted())
    static_cast<wxComboBox*>(reinterpret_cast<control_handler*>(control)->control())->Insert(value, index);
  else
    static_cast<wxComboBox*>(reinterpret_cast<control_handler*>(control)->control())->Append(value);
}

size_t combo_box::selected_index(intptr_t control) {
  if (control == 0) return -1;
  return static_cast<wxComboBox*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection();
}

void combo_box::selected_index(intptr_t control, size_t index) {
  if (control == 0) return;
  return static_cast<wxComboBox*>(reinterpret_cast<control_handler*>(control)->control())->SetSelection(index);
}
