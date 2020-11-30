#pragma once
#include <xtd/drawing/color.h>
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      class forms_native_export_ text_box final static_ {
      public:
        static size_t selection_length(intptr_t control);
        static size_t selection_start(intptr_t control);
        static void append(intptr_t control, const std::string& text);
        static void select(intptr_t control, size_t start, size_t length);
        static std::string text(intptr_t control);
        static void text(intptr_t control, const std::string& text);
      };
    }
  }
}
