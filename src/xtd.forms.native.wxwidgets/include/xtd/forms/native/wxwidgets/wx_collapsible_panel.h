#pragma once
#include <stdexcept>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/create_params.h>
#include <wx/collpane.h>
#include <wx/scrolwin.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_collapsible_panel : public control_handler {
      public:
        wx_collapsible_panel(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<wxCollapsiblePane>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxString(create_params.caption().c_str(), wxMBConvUTF8()), wxPoint(create_params.x(), create_params.y()));
#if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
            control()->GetChildren()[0]->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->GetChildren()[0]->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
            control()->GetChildren()[1]->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->GetChildren()[1]->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
#endif
          //static_cast<wxCollapsiblePane*>(control())->Layout();
          static_cast<wxCollapsiblePane*>(control())->Collapse(false);
          static_cast<wxCollapsiblePane*>(control())->Collapse(true);
        }

        wxWindow* main_control() const override {
          return static_cast<wxCollapsiblePane*>(control())->GetPane();
        }

        void SetClientSize(int32_t width, int32_t height) override {
        }
        
        void SetSize(int32_t width, int32_t height) override {
        }
      };
    }
  }
}
