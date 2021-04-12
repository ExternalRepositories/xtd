/// @file
/// @brief Contains xtd::forms::native::tab_page API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.#pragma once
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
      /// @brief Contains tab page native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native
      /// @warning Internal use only
      class forms_native_export_ tab_page final static_ {
      public:
        /// @brief Sets image index associate to the page.
        /// @param control Tab page window handle.
        /// @param image_index The image index.
        /// @warning Internal use only
        static void image_index(intptr_t control, size_t image_index);
        /// @brief Sets text associate to the page.
        /// @param control Tab page window handle.
        /// @param text The text string.
        /// @warning Internal use only
        static void text(intptr_t control, const std::string& text);
      };
    }
  }
}
