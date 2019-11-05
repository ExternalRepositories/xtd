#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <xtd/forms/native/combo_box_styles.hpp>
#include <wx/combobox.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_combo_box : public control_handler {
      public:
        wx_combo_box(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
#if defined(__WXMSW__)
          int32_t height = (create_params.style() & CBS_SIMPLE) != CBS_SIMPLE && create_params.height() != 23 ? 23 : create_params.height();
#else
          int32_t height = 23;
#endif
          this->control_handler::create<wxComboBox>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, wxEmptyString, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), height), 0, nullptr, style_to_wx_style(create_params.style(), create_params.ex_style()));
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;

          if ((style & CBS_SORT) == CBS_SORT) wx_style |= wxCB_SORT;
          
          if ((style & CBS_DROPDOWNLIST) == CBS_DROPDOWNLIST) wx_style |= wxCB_READONLY;
          else if ((style & CBS_DROPDOWN) == CBS_DROPDOWN) wx_style |= wxCB_DROPDOWN;
          else if ((style & CBS_SIMPLE) == CBS_SIMPLE) wx_style |= wxCB_SIMPLE;

          return wx_style;
        }
        
        void SetClientSize(int32_t width, int32_t height) override {
          // Do not change size when running wxW
        }

        void SetSize(int32_t width, int32_t height) override {
        }
      };
    }
  }
}
