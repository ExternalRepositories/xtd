#pragma once
#include <cstdint>
#include <string>
#include <vector>

/// @cond
namespace xtd {
  namespace drawing {
    namespace native {
      class font_family {
      public:
        font_family() = delete;
        static void destroy(intptr_t font_family);
        static intptr_t from_name(const std::string& name);
        static std::string generic_serif_name();
        static std::string generic_sans_serif_name();
        static std::string generic_monospace_name();
        static std::vector<std::string> installed_font_families();
        static int32_t get_cell_ascent(intptr_t font_family, bool bold, bool italic, bool underline, bool strikeout);
        static int32_t get_cell_descent(intptr_t font_family, bool bold, bool italic, bool underline, bool strikeout);
        static int32_t get_em_height(intptr_t font_family, bool bold, bool italic, bool underline, bool strikeout);
        static int32_t get_line_spacing(intptr_t font_family, bool bold, bool italic, bool underline, bool strikeout);
        static std::string get_name(intptr_t font_family, int32_t language);
        static bool is_style_avaible(intptr_t font_family, bool bold, bool italic, bool underline, bool strikeout);
      };
    }
  }
}
/// @endcond
