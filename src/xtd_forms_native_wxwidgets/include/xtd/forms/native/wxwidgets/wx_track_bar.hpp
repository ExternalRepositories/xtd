#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <xtd/forms/native/track_bar_styles.hpp>
#include <wx/slider.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_track_bar : public control_handler {
      public:
        wx_track_bar(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<wxSlider>(reinterpret_cast<control_handler*>(create_params.parent())->container(), wxID_ANY, 0, 0, 10, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;
          
          if ((style & TBS_VERT) == TBS_VERT) wx_style |= wxSL_VERTICAL | wxSL_INVERSE;
          else wx_style |= wxSL_HORIZONTAL;
          
          if ((style & TBS_BOTH) == TBS_BOTH) wx_style |= wxSL_BOTH;
          else if ((style & TBS_NOTICKS) != TBS_NOTICKS) {
            wx_style |= wxSL_AUTOTICKS;
            if ((style & TBS_VERT) == TBS_VERT) {
              if ((style & TBS_LEFT) == TBS_LEFT) wx_style |= wxSL_LEFT;
              else wx_style |= wxSL_RIGHT;
            } else {
              if ((style & TBS_TOP) == TBS_TOP) wx_style |= wxSL_TOP;
              else wx_style |= wxSL_BOTTOM;
            }
          }

          return wx_style;
        }
      };
    }
  }
}
