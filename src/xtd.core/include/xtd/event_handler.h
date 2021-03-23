/// @file
/// @brief Contains xtd::event_handler event handler.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "delegate.h"
#include "event.h"
#include "event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the method that will handle an event that has no event data.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core events
  template<typename type_t>
  using event_handler = xtd::delegate<void(type_t, const event_args&)>;
}
