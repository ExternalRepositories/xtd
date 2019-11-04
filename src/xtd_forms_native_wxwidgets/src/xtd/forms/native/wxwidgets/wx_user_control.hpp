#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <wx/panel.h>
#include <wx/scrolwin.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_user_control : public control_handler {
      public:
        wx_user_control(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<wxScrolled<wxPanel>>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
          this->control()->SetSize(create_params.width(), create_params.height());
          static_cast<wxScrolled<wxPanel>*>(this->control())->SetVirtualSize(this->control()->GetSize());
          static_cast<wxScrolled<wxPanel>*>(this->control())->Scroll(0, 0);
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = wxHSCROLL | wxVSCROLL;
          
          if ((style & WS_HSCROLL) == WS_HSCROLL) wx_style |= wxHSCROLL;
          if ((style & WS_VSCROLL) == WS_VSCROLL) wx_style |= wxVSCROLL;
          if (((style & WS_HSCROLL) == WS_HSCROLL || (style & WS_VSCROLL) == WS_VSCROLL) && (ex_style & WS_EX_AUTOSCROLL) != WS_EX_AUTOSCROLL) wx_style |= wxALWAYS_SHOW_SB;

          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_SIMPLE;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_THEME;
          else wx_style |= wxBORDER_NONE;

          return wx_style;
        }
      };
    }
  }
}
