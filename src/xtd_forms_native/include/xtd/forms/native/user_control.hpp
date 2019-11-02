#pragma once
#include "../create_params.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class user_control {
      public:
        user_control() = delete;
        static void virtual_size(intptr_t control, const drawing::size& size);
      };
    }
  }
}
