#pragma once
#include <cstdint>
#include "../forms_export.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides the base implementation and enables object sharing between applications.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    /// @remarks component is the base class for all components and controls.
    class component {
    public:
      
    protected:
      component() = default;
      
      /// @cond
      virtual ~component() = default;
      /// @endcond
      
      /// @brief Gets a value indicating whether the component can raise an event.
      /// @return true if the component can raise events; otherwise, false. The default is true.
      /// @remarks The default implementation of this property always returns true. Classes that inherit from the Component class should override this property to provide the ability to disable the raising of events.
      virtual bool can_raise_events() const {return true;}
      
      /// @brief Gets a value that indicates whether the component is currently in design mode.
      /// @return true if the component is in design mode; otherwise, false.
      bool design_mode() const {return design_mode_;}
      
    private:
      bool design_mode_ = false;
    };
  }
}
