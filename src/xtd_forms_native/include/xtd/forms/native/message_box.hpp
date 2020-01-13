#pragma once
#include <cstdint>
#include <string>
#include <xtd/static.hpp>

namespace xtd {
  namespace forms {
    namespace native {
      class message_box static_ {
      public:
        static int32_t show(intptr_t hwnd, const std::string& text, const std::string& caption, uint32_t options, bool display_help_button);
      };
    }
  }
}
