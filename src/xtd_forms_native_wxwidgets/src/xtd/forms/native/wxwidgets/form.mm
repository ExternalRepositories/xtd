#if defined(__APPLE__)
#include <xtd/forms/native/form.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_form.h"
#include <AppKit/AppKit.h>

using namespace xtd::forms::native;

bool __toogle_full_screen_frame__(wxTopLevelWindow* control) {
  if (control == 0) return false;
  return ([[control->GetHandle() window] styleMask] & NSWindowStyleMaskFullScreen) == NSWindowStyleMaskFullScreen;
}

void __toogle_full_screen_frame__(wxTopLevelWindow* control, bool full_screen) {
  if (control == 0) return;
  if (full_screen != __toogle_full_screen_frame__(control)) [[control->GetHandle() window] toggleFullScreen:[control->GetHandle() window]];
}
#endif
