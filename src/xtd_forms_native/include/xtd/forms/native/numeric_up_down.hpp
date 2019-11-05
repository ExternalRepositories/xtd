#pragma once
#include "../create_params.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class numeric_up_down {
      public:
        numeric_up_down() = delete;
        static void decimal_place(intptr_t control, int32_t decimal_place);
        static void increment(intptr_t control, double increment);
        static void maximum(intptr_t control, double maximum);
        static void minimum(intptr_t control, double minimum);
        static double value(intptr_t control);
        static void value(intptr_t control, double value);
      };
    }
  }
}
