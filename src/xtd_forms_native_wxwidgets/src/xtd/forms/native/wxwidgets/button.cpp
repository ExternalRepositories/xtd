#include <xtd/forms/native/button.hpp>
#include <xtd/forms/native/content_alignment.hpp>
#include "wx_button.hpp"

using namespace xtd;
using namespace xtd::forms::native;

void __set_button_bezel_style__(wxButton* control, int32_t x, int32_t y, int32_t width, int32_t height);

void button::default_button(intptr_t control, bool default_button) {
  if (control == 0) return;
  
  wxWindow* top_level_control = static_cast<wxWindow*>(reinterpret_cast<control_handler*>(control)->control());
  while (top_level_control && dynamic_cast<wxTopLevelWindow*>(top_level_control) == nullptr && top_level_control->GetParent() != nullptr)
    top_level_control = top_level_control->GetParent();
  if (top_level_control && dynamic_cast<wxTopLevelWindow*>(top_level_control) != nullptr)
    static_cast<wxTopLevelWindow*>(top_level_control)->SetDefaultItem(default_button ? static_cast<wxWindow*>(reinterpret_cast<control_handler*>(control)->control()) : nullptr);
}

void button::image(intptr_t control, const drawing::image& image) {
  if (control == 0 || image.handle() == 0) return;
  wxPoint location = reinterpret_cast<control_handler*>(control)->control()->GetPosition();
  wxSize size = reinterpret_cast<control_handler*>(control)->control()->GetSize();
  static_cast<wxButton*>(reinterpret_cast<control_handler*>(control)->control())->SetBitmapLabel(wxBitmap(*reinterpret_cast<wxImage*>(image.handle())));
  reinterpret_cast<control_handler*>(control)->control()->SetPosition(location);
  reinterpret_cast<control_handler*>(control)->control()->SetSize(size);
  __set_button_bezel_style__(static_cast<wxButton*>(reinterpret_cast<control_handler*>(control)->control()), location.x, location.y, size.GetWidth(), size.GetHeight());
}

void button::image_align(intptr_t control, uint32_t align) {
  if (control == 0) return;

  wxPoint location = reinterpret_cast<control_handler*>(control)->control()->GetPosition();
  wxSize size = reinterpret_cast<control_handler*>(control)->control()->GetSize();
  switch (align) {
    case CA_TOP_LEFT: static_cast<wxButton*>(reinterpret_cast<control_handler*>(control)->control())->SetBitmapPosition(wxLEFT); break;
    case CA_TOP_CENTER: static_cast<wxButton*>(reinterpret_cast<control_handler*>(control)->control())->SetBitmapPosition(wxTOP); break;
    case CA_TOP_RIGHT: static_cast<wxButton*>(reinterpret_cast<control_handler*>(control)->control())->SetBitmapPosition(wxRIGHT); break;
    case CA_MIDDLE_LEFT: static_cast<wxButton*>(reinterpret_cast<control_handler*>(control)->control())->SetBitmapPosition(wxLEFT); break;
    case CA_MIDDLE_CENTER: break;
    case CA_MIDDLE_RIGHT: static_cast<wxButton*>(reinterpret_cast<control_handler*>(control)->control())->SetBitmapPosition(wxRIGHT); break;
    case CA_BOTTOM_LEFT: static_cast<wxButton*>(reinterpret_cast<control_handler*>(control)->control())->SetBitmapPosition(wxDirection::wxLEFT); break;
    case CA_BOTTOM_CENTER: static_cast<wxButton*>(reinterpret_cast<control_handler*>(control)->control())->SetBitmapPosition(wxBOTTOM); break;
    case CA_BOTTOM_RIGHT: static_cast<wxButton*>(reinterpret_cast<control_handler*>(control)->control())->SetBitmapPosition(wxDirection::wxRIGHT); break;
  }
  reinterpret_cast<control_handler*>(control)->control()->SetPosition(location);
  reinterpret_cast<control_handler*>(control)->control()->SetSize(size);
  __set_button_bezel_style__(static_cast<wxButton*>(reinterpret_cast<control_handler*>(control)->control()), location.x, location.y, size.GetWidth(), size.GetHeight());
}
