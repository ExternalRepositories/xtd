#pragma once
#include "../create_params.hpp"
#include <xtd/drawing/image.hpp>

namespace xtd {
  namespace forms {
    namespace native {
      class button {
      public:
        button() = delete;
        static void default_button(intptr_t control, bool default_button);
        static void image(intptr_t control, const drawing::image& image);
        static void image_align(intptr_t control, uint32_t align);
      };
    }
  }
}
