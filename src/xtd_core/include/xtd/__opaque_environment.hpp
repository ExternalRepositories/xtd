/// @file
/// @brief Contains xtd::environment class.
#pragma once
#include "guid.hpp"
#include "platform_id.hpp"
#include "version.hpp"

/// @cond
namespace xtd {
  class environment;
  struct guid;
}

class __opaque_environment final {
  friend class xtd::environment;
  friend struct xtd::guid;
  
  static std::string get_current_directory() noexcept;
  static std::string get_environment_variable(const std::string& variable) noexcept;
  static std::string get_know_folder_path(int id) noexcept;
  static std::string get_machine_name() noexcept;
  static xtd::platform_id get_os_platform_id() noexcept;
  static int get_os_version(int& major, int& minor, int& build, int& revision) noexcept;
  static std::string get_service_pack() noexcept;
  static unsigned int get_processor_count() noexcept;
  static size_t get_system_page_size() noexcept;
  static unsigned int get_tick_count() noexcept;
  static std::string get_user_domain_name() noexcept;
  static std::string get_user_name() noexcept;
  static xtd::version get_version() noexcept;
  static bool is_os_64_bit() noexcept;
  static xtd::guid new_guid() noexcept;
  static std::string new_line() noexcept;
  static int set_current_directory(const std::string& directory_name) noexcept;
  static int set_env(const std::string& name, const std::string& value) noexcept;
  static int unset_env(const std::string& name) noexcept;
};
/// @endcond
