#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <xtd/forms/native/date_time_picker_styles.hpp>
#include <wx/datectrl.h>
#include <wx/timectrl.h>
#include <wx/dateevt.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_date_time_picker : public control_handler {
      public:
        wx_date_time_picker(const xtd::forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          if ((create_params.style() & DTS_TIMEFORMAT) == DTS_TIMEFORMAT)
            this->control_handler::create<wxTimePickerCtrl>(reinterpret_cast<control_handler*>(create_params.parent())->container(), wxID_ANY, wxDefaultDateTime, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
          else
            this->control_handler::create<wxDatePickerCtrl>(reinterpret_cast<control_handler*>(create_params.parent())->container(), wxID_ANY, wxDefaultDateTime, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;
          
          if ((style & DTS_UPDOWN) == DTS_UPDOWN) wx_style |= wxDP_SPIN;
          else wx_style |= wxDP_DROPDOWN;
          if ((style & DTS_SHOWNONE) == DTS_SHOWNONE) wx_style |= wxDP_ALLOWNONE;
          if ((style & DTS_SHORTDATECENTURYFORMAT) == DTS_SHORTDATECENTURYFORMAT) wx_style |= wxDP_SHOWCENTURY;
          if ((style & DTS_LONGDATEFORMAT) == DTS_LONGDATEFORMAT) wx_style |= wxDP_SHOWCENTURY;

          return wx_style;
        }

        virtual void SetPosition(const wxPoint& pt) override {
          control_handler::SetPosition(pt);
        }

        wxSize GetClientSize() const override {
          return control()->GetSize();
        }
        
        void SetClientSize(int32_t width, int32_t height) override {
          SetSize(width, height);
        }
      };
    }
  }
}
