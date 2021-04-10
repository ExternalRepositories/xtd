/// @file
/// @brief Contains xtd::forms::native::button API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/drawing/image.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains button native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native
      /// @warning Internal use only
      class forms_native_export_ button final static_ {
      public:
        /// @brief Mark button as default.
        /// @param control Button window handle.
        /// @warning Internal use only
        static void set_default_button(intptr_t control);
      };
    }
  }
}
