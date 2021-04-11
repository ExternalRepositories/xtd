/// @file
/// @brief Contains xtd::forms::native::menu API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Menu native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native
      /// @warning Internal use only
      class forms_native_export_ menu final static_ {
      public:
        /// @brief Creates menu.
        /// @param text The text associated with this menu.
        /// @param menu_items A menu item handles array.
        /// @return The created menu handle.
        /// @warning Internal use only
        static intptr_t create(const std::string& text, const std::vector<intptr_t>& items);
        /// @brief Destroy menu.
        /// @param main_menu Menu handle.
        /// @warning Internal use only
        static void destroy(intptr_t menu);
      };
    }
  }
}
