#pragma once
#include "menu_item.h"
#include "message.h"
#include "theme_images.h"
#include <xtd/drawing/size.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
  /// @cond
  class form;
  /// @endcond
  
    class main_menu : public menu {
    public:      
      main_menu();
      main_menu(const std::initializer_list<menu_item>& menu_items);
      main_menu(const std::vector<menu_item>& menu_items);

      /// @cond
      ~main_menu();
      /// @endcond

      static xtd::forms::main_menu create_standard_items(const xtd::event_handler<xtd::forms::component&>& on_click);
      static xtd::forms::main_menu create_standard_items(const xtd::drawing::size& size, const xtd::event_handler<xtd::forms::component&>& on_click);
      static xtd::forms::main_menu create_standard_items(const std::string& theme, const xtd::event_handler<xtd::forms::component&>& on_click);
      static xtd::forms::main_menu create_standard_items(const std::string& theme, const xtd::drawing::size& size, const xtd::event_handler<xtd::forms::component&>& on_click);
      static xtd::forms::main_menu create_standard_items(const xtd::forms::theme_images& theme, const xtd::drawing::size& size, const xtd::event_handler<xtd::forms::component&>& on_click);

      /// @cond
      template<typename on_click_type>
      static xtd::forms::main_menu create_standard_items(on_click_type on_click) { return create_standard_items(xtd::event_handler<xtd::forms::component&>(on_click)); }
      template<typename on_click_type>
      static xtd::forms::main_menu create_standard_items(const xtd::drawing::size& size, on_click_type on_click) { return create_standard_items(size, xtd::event_handler<xtd::forms::component&>(on_click)); }
      template<typename on_click_type>
      static xtd::forms::main_menu create_standard_items(const std::string& theme, on_click_type on_click) { return create_standard_items(theme, xtd::event_handler<xtd::forms::component&>(on_click)); }
      template<typename on_click_type>
      static xtd::forms::main_menu create_standard_items(const std::string& theme, const xtd::drawing::size& size, on_click_type on_click) { return create_standard_items(theme, size, xtd::event_handler<xtd::forms::component&>(on_click)); }
      template<typename on_click_type>
      static xtd::forms::main_menu create_standard_items(const xtd::forms::theme_images& theme, const xtd::drawing::size& size, on_click_type on_click) { return create_standard_items(theme, size, xtd::event_handler<xtd::forms::component&>(on_click)); }
      /// @endcond
 
    protected:
      intptr_t create_menu_handle() override;
      void destroy_menu_handle(intptr_t handle) override;

    private:
      friend class form;
      void wm_click(message& message);
    };
  }
}
