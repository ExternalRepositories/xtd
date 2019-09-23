#pragma once
#include <cstdint>
#include <xtd/drawing/point.hpp>
#include <xtd/drawing/size.hpp>

namespace xtd {
  namespace forms {
    namespace native {
      class cursor {
      public:
        cursor() = delete;
        static intptr_t create();
        static intptr_t copy(intptr_t cursor);
        static void destroy(intptr_t cursor);
        static void hide();
        static drawing::point hot_spot(intptr_t cursor);
        static drawing::point position();
        static void position(const drawing::point& position);
        static drawing::size size(intptr_t cursor);
        static void show();
      };
    }
  }
}
