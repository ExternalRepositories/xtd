#pragma once
#include <xtd/drawing/color.hpp>
#include <xtd/drawing/font.hpp>
#include <xtd/drawing/system_colors.hpp>
#include <xtd/drawing/system_fonts.hpp>
#include <xtd/forms/window_font_dialog.hpp>
#include "common_dialog.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Prompts the user to choose a font from among those installed on the local computer.
    /// @remarks The inherited member show_dialog must be invoked to create this specific common dialog box. hook_proc can be overridden to implement specific dialog box hook functionality.
    /// @remarks When you create an instance of font_dialog, some of the read/write properties are set to initial values. For a list of these values, see the font_dialog constructor.
    class font_dialog : public common_dialog {
    public:
      /// @brief Initializes a new instance of the font_dialog class.
      /// @remarks When you create an instance of font_dialog, the following read/write properties are initialized.
      /// | Property             | Initial value |
      /// |----------------------|---------------|
      /// | allow_simulations    | true          |
      /// | allow_vector_fonts   | true          |
      /// | allow_vertical_fonts | true          |
      /// | allow_script_shange  | true          |
      /// | color                | color::black  |
      /// | fixed_pitch_only     | false         |
      /// | max_size             | 0             |
      /// | min_size             | 0             |
      /// | scripts_only         | false         |
      /// | show_apply           | false         |
      /// | show_color           | false         |
      /// | show_effects         | true          |
      /// | show_help            | false         |
      /// @remarks You can change the value for any of these properties through a separate call to the property.
      font_dialog() = default;
      
      /// @brief Gets a value indicating whether the user can change the character set specified in the Script combo box to display a character set other than the one currently displayed.
      /// @return true if the user can change the character set specified in the Script combo box; otherwise, false. The default value is true.
      /// @remarks The Script combo box found on the Font dialog box contains character sets associated with the selected font.
      bool allow_script_change() const {return !this->get_option(CF_SELECTSCRIPT);}
      /// @brief Sets a value indicating whether the user can change the character set specified in the Script combo box to display a character set other than the one currently displayed.
      /// @param allow_script_change true if the user can change the character set specified in the Script combo box; otherwise, false. The default value is true.
      /// @remarks The Script combo box found on the Font dialog box contains character sets associated with the selected font.
      font_dialog& allow_script_change(bool allow_script_change) {
        this->set_option(CF_SELECTSCRIPT, !allow_script_change);
        return *this;
      }
      
      /// @brief Gets a value indicating whether the dialog box allows graphics device interface (GDI) font simulations.
      /// @return true if font simulations are allowed; otherwise, false. The default value is true.
      bool allow_simulation() const {return !this->get_option(CF_NOSIMULATIONS);}
      /// @brief Sets a value indicating whether the dialog box allows graphics device interface (GDI) font simulations.
      /// @param allow_simulation true if font simulations are allowed; otherwise, false. The default value is true.
      font_dialog& allow_simulation(bool allow_simulation) {
        this->set_option(CF_NOSIMULATIONS, !allow_simulation);
        return *this;
      }
      
      /// @brief Gets a value indicating whether the dialog box allows vector font selections.
      /// @return true if vector fonts are allowed; otherwise, false. The default value is true.
      bool allow_vector_fonts() const {return !this->get_option(CF_NOVECTORFONTS);}
      /// @brief Sets a value indicating whether the dialog box allows vector font selections.
      /// @param allow_vector_fonts true if vector fonts are allowed; otherwise, false. The default value is true.
      font_dialog& allow_vector_fonts(bool allow_vector_fonts) {
        this->set_option(CF_NOVECTORFONTS, !allow_vector_fonts);
        return *this;
      }

      /// @brief Gets a value indicating whether the dialog box displays both vertical and horizontal fonts or only horizontal fonts.
      /// @return true if both vertical and horizontal fonts are allowed; otherwise, false. The default value is true.
      bool allow_vertical_fonts() const {return !this->get_option(CF_NOVERTFONTS);}
      /// @brief Sets a value indicating whether the dialog box displays both vertical and horizontal fonts or only horizontal fonts.
      /// @param allow_vertical_fonts true if both vertical and horizontal fonts are allowed; otherwise, false. The default value is true.
      font_dialog& allow_vertical_fonts(bool allow_vertical_fonts) {
        this->set_option(CF_NOVERTFONTS, !allow_vertical_fonts);
        return *this;
      }

      /// @brief Gets the selected font color.
      /// @return The color of the selected font. The default value is Black.
      drawing::color color() const {return this->color_;}
      /// @brief Sets the selected font color.
      /// @param color The color of the selected font. The default value is Black.
      font_dialog& color(const drawing::color& color) {
        this->color_ = color;
        return *this;
      }
      
      /// @brief Gets a value indicating whether the dialog box allows only the selection of fixed-pitch fonts.
      /// @return true if only fixed-pitch fonts can be selected; otherwise, false. The default value is false.
      bool fixed_pitch_only() const {return this->get_option(CF_FIXEDPITCHONLY);}
      /// @brief Sets a value indicating whether the dialog box allows only the selection of fixed-pitch fonts.
      /// @param fixed_pitch_only true if only fixed-pitch fonts can be selected; otherwise, false. The default value is false.
      font_dialog& fixed_pitch_only(bool fixed_pitch_only) {
        this->set_option(CF_FIXEDPITCHONLY, fixed_pitch_only);
        return *this;
      }

      /// @brief Gets the selected font.
      /// @return The selected font.
      drawing::font font() const {return this->font_;}
      /// @brief Sets the selected font.
      /// @param font The selected font.
      font_dialog& font(const drawing::font& font) {
        this->font_ = font;
        return *this;
      }
      
      /// @brief Gets a value indicating whether the dialog box specifies an error condition if the user attempts to select a font or style that does not exist.
      /// @return true if the dialog box specifies an error condition when the user tries to select a font or style that does not exist; otherwise, false. The default is false.
      bool font_must_exist() const {return this->get_option(CF_FORCEFONTEXIST);}
      /// @brief Sets a value indicating whether the dialog box specifies an error condition if the user attempts to select a font or style that does not exist.
      /// @param font_must_exist true if the dialog box specifies an error condition when the user tries to select a font or style that does not exist; otherwise, false. The default is false.
      font_dialog& font_must_exist(bool font_must_exist) {
        this->set_option(CF_FORCEFONTEXIST, font_must_exist);
        return *this;
      }
      
      /// @brief Gets the maximum point size a user can select.
      /// @return The maximum point size a user can select. The default is 0.
      size_t max_size() const {return this->max_size_;}
      /// @brief Sets the maximum point size a user can select.
      /// @param max_size The maximum point size a user can select. The default is 0.
      font_dialog& max_size(size_t max_size) {
        this->max_size_ = max_size;
        return *this;
      }
      
      /// @brief Gets the minimum point size a user can select.
      /// @return The minimum point size a user can select. The default is 0.
      size_t min_size() const {return this->min_size_;}
      /// @brief Sets the minimum point size a user can select.
      /// @param min_size The minimum point size a user can select. The default is 0.
      font_dialog& min_size(size_t min_size) {
        this->min_size_ = min_size;
        return *this;
      }
      
      /// @brief Gets values to initialize the font_dialog.
      /// @return A bitwise combination of internal values that initializes the font_dialog.
      /// @remarks The options property corresponds to the flags used to initialize a color dialog box using Win32. Use the properties of the font_dialog class to get and set the options.
      size_t options() const {return this->options_;}
      
      /// @brief Gets a value indicating whether the dialog box allows selection of fonts for all non-OEM and Symbol character sets, as well as the ANSI character set.
      /// @return true if selection of fonts for all non-OEM and Symbol character sets, as well as the ANSI character set, is allowed; otherwise, false. The default value is false.
      bool script_only() const {return this->get_option(CF_SCRIPTSONLY);}
      /// @brief Sets a value indicating whether the dialog box allows selection of fonts for all non-OEM and Symbol character sets, as well as the ANSI character set.
      /// @param script_script = true if selection of fonts for all non-OEM and Symbol character sets, as well as the ANSI character set, is allowed; otherwise, false. The default value is false.
      font_dialog& script_only(bool script_only) {
        this->set_option(CF_SCRIPTSONLY, script_only);
        return *this;
      }
      
      /// @brief Gets a value indicating whether the dialog box contains an Apply button.
      /// @return true if the dialog box contains an Apply button; otherwise, false. The default value is false.
      bool show_apply() const {return this->get_option(CF_APPLY);}
      /// @brief Sets a value indicating whether the dialog box contains an Apply button.
      /// @param show_apply true if the dialog box contains an Apply button; otherwise, false. The default value is false.
      font_dialog& show_apply(bool show_apply) {
        this->set_option(CF_APPLY, show_apply);
        return *this;
      }
      
      /// @brief Gets a value indicating whether the dialog box displays the color choice.
      /// @return true if the dialog box displays the color choice; otherwise, false. The default value is false.
      bool show_color() const {return this->show_color_;}
      /// @brief Sets a value indicating whether the dialog box displays the color choice.
      /// @param show_color true if the dialog box displays the color choice; otherwise, false. The default value is false.
      font_dialog& show_color(bool show_color) {
        this->show_color_ = show_color;
        return *this;
      }
      
      /// @brief Gets a value indicating whether the dialog box contains controls that allow the user to specify strikethrough, underline, and text color options.
      /// @return true if the dialog box contains controls to set strikethrough, underline, and text color options; otherwise, false. The default value is true.
      bool show_effect() const {return this->get_option(CF_EFFECTS);}
      /// @brief Sets a value indicating whether the dialog box contains controls that allow the user to specify strikethrough, underline, and text color options.
      /// @param show_effect true if the dialog box contains controls to set strikethrough, underline, and text color options; otherwise, false. The default value is true.
      font_dialog& show_effect(bool show_effect) {
        this->set_option(CF_EFFECTS, show_effect);
        return *this;
      }
      
      /// @brief Gets a value indicating whether the dialog box displays a Help button.
      /// @return true if the dialog box displays a Help button; otherwise, false. The default value is false.
      bool show_help() const {return this->get_option(CF_SHOWHELP);}
      /// @brief Sets a value indicating whether the dialog box displays a Help button.
      /// @param show_help true if the dialog box displays a Help button; otherwise, false. The default value is false.
      font_dialog& show_help(bool show_help) {
        this->set_option(CF_SHOWHELP, show_help);
        return *this;
      }

      /// @brief Occurs when the user clicks the Apply button in the font dialog box.
      /// @remarks Every time the Apply button is clicked, another apply event is raised.
      event<font_dialog, event_handler<component&>> apply;
      
      /// @brief Resets all dialog box options to their default values.
      /// @remarks When the options are reset, the strikethrough, underline, and color effects are enabled. The fonts listed include only the screen fonts supported by the system.
      void reset() override;
      
    protected:
      /// @brief Raises the apply event.
      /// @param e An event_args that contains the data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      /// @par Notes to Inheritors
      /// When overriding on_apply(const event_args&) in a derived class, be sure to call the base class's on_apply(const event_args&) method.
      virtual void on_apply(const event_args& e);
      
      /// @return Specifies a file dialog box.
      /// @param owner The window handle of the owner window for the common dialog box.
      /// @return true if the dialog box was successfully run; otherwise, false.
      /// @remarks The run_dialog method is invoked when the user of a font dialog box calls the show_dialog method.
      bool run_dialog(intptr_t owner) override;

    private:
      bool get_option(size_t flag) const {return (this->options_ & flag) == flag;}
      void set_option(size_t flag, bool value) {this->options_ = value ? this->options_ | flag : this->options_ & ~flag;}

      drawing::color color_ = drawing::system_colors::control_text();
      drawing::font font_ = drawing::system_fonts::default_font();
      size_t max_size_ = 0;
      size_t min_size_ = 0;
      size_t options_ = CF_TTONLY;
      bool show_color_ = false;
    };
  }
}
