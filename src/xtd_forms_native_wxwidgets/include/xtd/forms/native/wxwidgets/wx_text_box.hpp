#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <xtd/forms/native/text_box_styles.hpp>
#include <wx/textctrl.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_text_box : public control_handler {
      public:
        wx_text_box(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");

          int32_t height = create_params.height();
#if defined(__WXGTK__)
          if (height < 32) height = 32;
#endif
          this->control_handler::create<wxTextCtrl>(reinterpret_cast<control_handler*>(create_params.parent())->container(), wxID_ANY, wxString(create_params.caption().c_str(), wxMBConvUTF8()), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), height), style_to_wx_style(create_params.style(), create_params.ex_style()));
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;
          
          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_DEFAULT;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_THEME;
          else wx_style |= wxBORDER_NONE;
          
          if ((style & ES_MULTILINE) == ES_MULTILINE) wx_style |= wxTE_MULTILINE;
          if ((style & ES_PASSWORD) == ES_PASSWORD) wx_style |= wxTE_PASSWORD;
          if ((style & ES_READONLY) == ES_READONLY) wx_style |= wxTE_READONLY;
          if ((style & ES_AUTOHSCROLL) == ES_AUTOHSCROLL) wx_style |= wxTE_DONTWRAP;

          return wx_style;
        }
      };
    }
  }
}
