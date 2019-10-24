#pragma once
#include "panel.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class tab_page : public panel {
    public:
      tab_page();

    protected:
      forms::create_params create_params() const override;
      void on_handle_created(const event_args &e) override;
      void on_handle_destroyed(const event_args &e) override;
      void recreate_handle() override;
    };
  }
}
