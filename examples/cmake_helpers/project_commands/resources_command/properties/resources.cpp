#pragma region xtd generated code
// This code was generated by CMake script.
//
// Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.

#include <exception>
#include "resources.hpp"

const xtd::drawing::bitmap& resources_example::properties::resources::gammasoft() {
  static xtd::drawing::bitmap bitmap(xtd::io::path::combine(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]), "..", "resources", "gammasoft.png"));
  return bitmap;
}

const std::string& resources_example::properties::resources::information() {
  static std::string text = xtd::io::file::read_all_text(xtd::io::path::combine(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]), "..", "resources", "information.txt"));
  return text;
}

const std::string& resources_example::properties::resources::readme() {
  static std::string text = xtd::io::file::read_all_text(xtd::io::path::combine(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]), "..", "resources", "readme.md"));
  return text;
}

const xtd::object& resources_example::properties::resources::sound() {
  throw std::logic_error("not yet implemented");
}

const xtd::drawing::bitmap& resources_example::properties::resources::xtd() {
  static xtd::drawing::bitmap bitmap(xtd::io::path::combine(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]), "..", "resources", "xtd.gif"));
  return bitmap;
}

const xtd::drawing::icon& resources_example::properties::resources::xtd_forms() {
  static xtd::drawing::icon icon(xtd::io::path::combine(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]), "..", "resources", "xtd_forms.ico"));
  return icon;
}

#pragma endregion
