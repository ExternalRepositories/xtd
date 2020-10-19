#pragma once
#include <cstdint>
#include <string>
#include <xtd/delegate.h>
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class input_dialog static_ {
      public:
        static bool run_dialog(intptr_t hwnd, const std::string& text, const std::string& message, std::string& value, int32_t character_casting, bool multiline, bool use_system_password_char);
        static void run_sheet(xtd::delegate<void(int32_t)> on_dialog_closed, intptr_t hwnd, const std::string& text, const std::string& message, std::string& value, int32_t character_casting, bool multiline, bool use_system_password_char);
        //static int32_t show_sheet_dialog(intptr_t hwnd, const std::string& text, const std::string& message, std::string& value, int32_t character_casting, bool multiline, bool use_system_password_char);
      };
    }
  }
}
