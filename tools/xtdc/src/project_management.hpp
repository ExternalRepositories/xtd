#pragma once
#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <map>
#include <string>
#include <vector>
#include <xtd/bit_converter.hpp>
#include <xtd/environment.hpp>
#include <xtd/action.hpp>
#include <xtd/file.hpp>
#include <xtd/path.hpp>
#include <xtd/strings.hpp>

#include "project_language.hpp"
#include "project_sdk.hpp"
#include "project_type.hpp"

namespace xtdc_command {
  class project_management {
    class change_current_directory {
    public:
      change_current_directory(const std::string& current_directory) {xtd::environment::current_directory(current_directory);}
      ~change_current_directory() {xtd::environment::current_directory(previous_current_directoy_);}
    private:
      std::string previous_current_directoy_ = xtd::environment::current_directory();
    };

  public:
    explicit project_management(const std::filesystem::path& output) : path_(output) {}

    static std::vector<project_sdk> get_valid_sdks(project_type type) {
      switch (type) {
        case project_type::blank_solution: return {project_sdk::xtd};
        case project_type::console: return {project_sdk::none, project_sdk::xtd};
        case project_type::gui: return {project_sdk::xtd, project_sdk::win32, project_sdk::gtk2, project_sdk::gtk3, project_sdk::cocoa, project_sdk::gtkmm, project_sdk::wxwidgets, project_sdk::qt5, project_sdk::winforms, project_sdk::wpf};
        case project_type::shared_library: return {project_sdk::none, project_sdk::xtd};
        case project_type::static_library: return {project_sdk::none, project_sdk::xtd};
        case project_type::unit_test_application: return {project_sdk::xtd, project_sdk::gtest, project_sdk::catch2};
      }
      throw std::invalid_argument("type is not project_type valid value");
    }
    
    static std::vector<project_language> get_valid_languages(project_sdk sdk) {
      switch (sdk) {
        case project_sdk::none: return {project_language::cpp, project_language::c, project_language::objectivec, project_language::csharp};
        case project_sdk::xtd: return {project_language::cpp};
        case project_sdk::win32: return {project_language::c, project_language::cpp};
        case project_sdk::gtk2: return {project_language::c, project_language::cpp};
        case project_sdk::gtk3: return {project_language::c, project_language::cpp};
        case project_sdk::cocoa: return {project_language::objectivec};
        case project_sdk::gtkmm: return {project_language::cpp};
        case project_sdk::wxwidgets: return {project_language::cpp};
        case project_sdk::qt5: return {project_language::cpp};
        case project_sdk::winforms: return {project_language::csharp};
        case project_sdk::wpf: return {project_language::csharp};
        case project_sdk::gtest: return {project_language::c, project_language::cpp};
        case project_sdk::catch2: return {project_language::c, project_language::cpp};
      }
      throw std::invalid_argument("sdk is not project_sdk valid value");
    }
    
    std::string create(const std::string& name, project_type type, project_sdk sdk, project_language language) const {
      auto sdks = get_valid_sdks(type);
      if (std::find(sdks.begin(), sdks.end(), sdk) == sdks.end()) return "The sdk param not valid with type param! Create project aborted.";
      auto languages = get_valid_languages(sdk);
      if (std::find(languages.begin(), languages.end(), language) == languages.end()) return "The language param not valid with sdk param! Create project aborted.";
      if (is_path_already_exist_and_not_empty(path_)) return xtd::strings::format("Path {0} already exists and not empty! Create project aborted.", path_);
      if (sdk == project_sdk::qt5 && xtd::environment::get_environment_variable("CMAKE_PREFIX_PATH").empty()) return "Set your CMAKE_PREFIX_PATH environment variable to the Qt 5 installation prefix! Create project aborted.";
      std::filesystem::create_directories(std::filesystem::path {path_}/"build");
      std::map<project_type, xtd::action<const std::string&, project_sdk, project_language>> {{project_type::blank_solution, {*this, &project_management::create_blank_solution}}, {project_type::console, {*this, &project_management::create_console}}, {project_type::gui, {*this, &project_management::create_gui}}, {project_type::shared_library, {*this, &project_management::create_shared_library}}, {project_type::static_library, {*this, &project_management::create_static_library}}, {project_type::unit_test_application, {*this, &project_management::create_unit_test_application}}}[type](name, sdk, language);
      generate(name);
      return xtd::strings::format("Project {} created", path_);
    }

    std::string build(const std::string& target, bool clean_first, bool release) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::strings::format("Path {0} does not exists or is empty! Build project aborted.", path_);
      generate();
      if (xtd::environment::os_version().is_windows_platform() || xtd::environment::os_version().is_osx_platform())
        system(xtd::strings::format("cmake --build {} --parallel {} --config {}{}{}", build_path(), xtd::environment::processor_count(), (release ? "Release" : "Debug"), target.empty() ? "" : xtd::strings::format(" --target {}", target), clean_first ? " --clean-first {}" : "").c_str());
      else
        system(xtd::strings::format("cmake --build {}{}", build_path()/(release ? "Release" : "Debug"), target.empty() ? "" : xtd::strings::format(" --target {}", target), clean_first ? " --clean-first {}" : "").c_str());
      return xtd::strings::format("Project {0} builded", path_);
    }

    std::string clean(bool release) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::strings::format("Path {0} does not exists or is empty! Clean project aborted.", path_);
      if (xtd::environment::os_version().is_windows_platform() || xtd::environment::os_version().is_osx_platform())
        std::filesystem::remove_all( build_path());
      else
        std::filesystem::remove_all( build_path()/(release ? "Release" : "Debug"));
      generate();
      return xtd::strings::format("Project {0} cleaned", path_);
    }

    std::string open(bool release) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::strings::format("Path {0} does not exists or is empty! Open project aborted.", path_);
      generate();
      if (xtd::environment::os_version().is_windows_platform())
        system(xtd::strings::format("explorer {}.sln", (build_path()/get_name()).string()).c_str());
      else if (xtd::environment::os_version().is_osx_platform())
        system(xtd::strings::format("open {}.xcodeproj", (build_path()/get_name()).string()).c_str());
      else
        system(xtd::strings::format("xdg-open {}.cbp>nul", (build_path()/(release ? "Release" : "Debug")/get_name()).string()).c_str());
      return xtd::strings::format("Project {0} opened", get_name());
    }

    std::string run(const std::string& target, bool release) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::strings::format("Path {} does not exists or is empty! Rn project aborted.", path_);
      build(target, false, release);
      auto target_path = target.empty() ? get_first_target_path(release) : get_target_path(target, release);
      if (target_path.empty()) return "The target does not exist! Run project aborted.";
      system(target_path.c_str());
      return "";
    }
    
    std::vector<std::string>& targets() const {
      static std::vector<std::string> targets;
      if (targets.size() == 0)
        for (const auto& line : get_system_information())
          if (xtd::strings::index_of(line, "_BINARY_DIR:STATIC=") != -1)
            targets.push_back(xtd::strings::substring(line, 0, xtd::strings::index_of(line, "_BINARY_DIR:STATIC=")));
      return targets;
    }

  private:
    std::string& get_name() const {
      static std::string name;
      if (name.empty()) {
        for (const auto& line : get_system_information()) {
          if (xtd::strings::starts_with(line, "CMAKE_PROJECT_NAME:STATIC=")) {
            name = xtd::strings::replace(line, "CMAKE_PROJECT_NAME:STATIC=", "");
            break;
          }
        }
      }
      if (name.empty()) name = path_.filename();
      return name;
    }
    
    std::string get_target_path(const std::string& target, bool release) const {
      for (const auto& line : get_system_information())
        if (xtd::strings::starts_with(line, xtd::strings::format("{}_BINARY_DIR:STATIC=", target)))
          return make_platform_target_path({xtd::strings::replace(line, xtd::strings::format("{}_BINARY_DIR:STATIC=", target), "")}, target, release);
      return build_path()/(release ? "RElease" : "Debug")/target/target;
    }
    
    std::string get_first_target_path(bool release) const {
      for (const auto& line : get_system_information())
        if (xtd::strings::index_of(line, "_BINARY_DIR:STATIC=") != -1)
          return make_platform_target_path({xtd::strings::replace(line, xtd::strings::format("{}_BINARY_DIR:STATIC=", xtd::strings::substring(line, 0, xtd::strings::index_of(line, "_BINARY_DIR:STATIC="))), "")}, xtd::strings::substring(line, 0, xtd::strings::index_of(line, "_BINARY_DIR:STATIC=")), release);
      return build_path()/(release ? "RElease" : "Debug")/path_.filename()/path_.filename();
    }
    
    std::string make_platform_target_path(const std::filesystem::path& path, const std::string& target, bool release) const {
      if (xtd::environment::os_version().is_windows_platform() && is_windows_gui_app(path/(release ? "Release" : "Debug")/xtd::strings::format("{}.exe", target)))
        return xtd::strings::format("start \"{}\" {}", target, (path/(release ? "Release" : "Debug")/xtd::strings::format("{}.exe", target)).string());
      else if (xtd::environment::os_version().is_windows_platform() && std::filesystem::exists(path/(release ? "Release" : "Debug")/xtd::strings::format("{}.exe", target)))
        return (path/(release ? "Release" : "Debug")/xtd::strings::format("{}.exe", target)).string();
      else if (xtd::environment::os_version().is_osx_platform() && std::filesystem::exists(path/(release ? "Release" : "Debug")/xtd::strings::format("{}.app", target)))
        return xtd::strings::format("open {}", path/(release ? "Release" : "Debug")/xtd::strings::format("{}.app", target));
      else if (xtd::environment::os_version().is_osx_platform() && std::filesystem::exists(path/(release ? "Release" : "Debug")/target))
        return (path/(release ? "Release" : "Debug")/target).string();
      else if (xtd::environment::os_version().is_linux_platform() && is_linux_gui_app(path, target))
        return xtd::strings::format("xdg-open {}", path/target);
      else if (xtd::environment::os_version().is_linux_platform() && std::filesystem::exists(path/target))
        return (path/target).string();
      return "";
    }
    
    bool is_windows_gui_app(const std::filesystem::path& app_path) const {
      if (!std::filesystem::exists(app_path)) return false;
      auto bytes = xtd::io::file::read_all_bytes(app_path);
      // read PE Format : https://docs.microsoft.com/en-us/windows/win32/debug/pe-format
      if (bytes[0] != 'M' || bytes[1] != 'Z') return false;
      return xtd::bit_converter::to_uint16(bytes, xtd::bit_converter::to_uint16(bytes, 0x3C) + 92) == 2;
    }
    
    bool is_linux_gui_app(const std::filesystem::path& path, const std::filesystem::path& target) const {
      if (!std::filesystem::exists(path/target)) return false;
      auto lines = xtd::io::file::read_all_lines(std::filesystem::path(xtd::environment::get_folder_path(xtd::environment::special_folder::home))/".local"/"share"/"applications"/xtd::strings::format("{}.desktop", target));
      for (auto line : lines)
        if (xtd::strings::to_lower(line) == "terminael=false") return true;
      return false;
    }
    
    std::vector<std::string>& get_system_information() const {
      static std::vector<std::string> system_information;
      if (system_information.size() == 0) {
        if (!std::filesystem::exists(build_path()/"xtd_si.txt")) {
          change_current_directory system_information_directory {build_path().string()};
          system(xtd::strings::format("cmake --system-information xtd_si.txt").c_str());
        }
        system_information = xtd::io::file::read_all_lines(build_path()/"xtd_si.txt");
      }
      return system_information;
    }
    
    std::filesystem::path build_path() const {return path_/"build";}
    std::filesystem::path working_dir() const {return path_/"build";}

    void create_blank_solution(const std::string& name, project_sdk sdk, project_language language) {
      create_doxygen_txt(name);
      create_blank_solution_cmakelists_txt(name);
    }
    
    void create_blank_solution_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.3)",
        "",
        "# Solution",
        xtd::strings::format("project({0})", name),
        "find_package(xtd REQUIRED)",
        "add_projects(",
        ")",
        "",
        "# Install",
        "install_package()"
      };
      xtd::io::file::write_all_lines(path_/"CMakeLists.txt", lines);
    }

    void create_console(const std::string& name, project_sdk sdk, project_language language) const {
      create_doxygen_txt(name);
      if (sdk == project_sdk::xtd)
        create_xtd_console(name, sdk, language);
      else
        std::map<project_language, xtd::action<const std::string&, project_sdk, project_language>> {{project_language::c, {*this, &project_management::create_c_console}}, {project_language::cpp, {*this, &project_management::create_cpp_console}}, {project_language::csharp, {*this, &project_management::create_csharp_console}}, {project_language::objectivec, {*this, &project_management::create_objectivec_console}}}[language](name, sdk, language);
    }

    void create_c_console(const std::string& name, project_sdk sdk, project_language language) const {
      create_c_console_solution_cmakelists_txt(name);
      std::filesystem::create_directories(path_/name/"src");
      create_c_console_cmakelists_txt(name);
      create_c_console_source(name);
    }
    
    void create_c_console_solution_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.3)",
        "",
        "# Solution",
        xtd::strings::format("project({0})", name),
        xtd::strings::format("add_subdirectory({0})", name)
      };
      xtd::io::file::write_all_lines(path_/"CMakeLists.txt", lines);
    }
    
    void create_c_console_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.3)",
        "",
        "# Project",
        xtd::strings::format("project({0} VERSION 1.0.0)", name),
        "set(SOURCES",
        xtd::strings::format("  src/{0}.c", name),
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set(CMAKE_C_STANDARD 11)",
        "set(CMAKE_C_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} ${SOURCES})"
      };
      
      xtd::io::file::write_all_lines(path_/name/"CMakeLists.txt", lines);
    }

    void create_c_console_source(const std::string& name) const {
      std::vector<std::string> lines {
        "/**",
        " * @file",
        " * @brief Contains main method.",
        " */",
        "#include <stdio.h>",
        "",
        "/**",
        " * @brief The main entry point for the application.",
        " * @param argc Size of array of char* that represent the arguments passed to the program from the execution environment.",
        " * @param argv An array of char* that represent the arguments passed to the program from the execution environment.",
        " */",
        "int main(int argc, char* argv[]) {",
        "  printf(\"Hello, World!\\n\");",
        "}"
      };
      
      xtd::io::file::write_all_lines(path_/name/"src"/xtd::strings::format("{0}.c", name), lines);
    }

    void create_cpp_console(const std::string& name, project_sdk sdk, project_language language) const {
      create_cpp_console_solution_cmakelists_txt(name);
      std::filesystem::create_directories(path_/name/"src");
      create_cpp_console_cmakelists_txt(name);
      create_cpp_console_source(name);
    }
    
    void create_cpp_console_solution_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.3)",
        "",
        "# Solution",
        xtd::strings::format("project({0})", name),
        xtd::strings::format("add_subdirectory({0})", name)
      };
      xtd::io::file::write_all_lines(path_/"CMakeLists.txt", lines);
    }
    
    void create_cpp_console_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.3)",
        "",
        "# Project",
        xtd::strings::format("project({0} VERSION 1.0.0)", name),
        "set(SOURCES",
        xtd::strings::format("  src/{0}.cpp", name),
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "set_property(GLOBAL PROPERTY USE_FOLDERS ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} ${SOURCES})"
      };
      
      xtd::io::file::write_all_lines(path_/name/"CMakeLists.txt", lines);
    }
    
    void create_cpp_console_source(const std::string& name) const {
      std::vector<std::string> lines {
        "/// @file",
        "/// @brief Contains main method.",
        "#include <iostream>",
        "",
        "using namespace std;",
        "",
        "/// @brief The main entry point for the application.",
        "/// @param argc Size of array of char* that represent the arguments passed to the program from the execution environment.",
        "/// @param argv An array of char* that represent the arguments passed to the program from the execution environment.",
        "int main(int argc, char* argv[]) {",
        "  cout << \"Hello, World!\" << endl;",
        "}"
      };
      
      xtd::io::file::write_all_lines(path_/name/"src"/xtd::strings::format("{0}.cpp", name), lines);
    }

    void create_csharp_console(const std::string& name, project_sdk sdk, project_language language) const {
      create_csharp_console_solution_cmakelists_txt(name);
      std::filesystem::create_directories(path_/name/"src");
      create_csharp_console_cmakelists_txt(name);
      create_csharp_console_source(name);
    }
    
    void create_csharp_console_solution_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Solution",
        xtd::strings::format("project({0})", name),
        xtd::strings::format("add_subdirectory({0})", name)
      };
      xtd::io::file::write_all_lines(path_/"CMakeLists.txt", lines);
    }
    
    void create_csharp_console_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Project",
        xtd::strings::format("project({0}  VERSION 1.0.0 LANGUAGES CSharp)", name),
        "include(CSharpUtilities)",
        "set(SOURCES",
        xtd::strings::format("  src/{0}.cs", name),
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} ${SOURCES})"
      };
      
      xtd::io::file::write_all_lines(path_/name/"CMakeLists.txt", lines);
    }
    
    void create_csharp_console_source(const std::string& name) const {
      std::vector<std::string> lines {
        "/// @file",
        "/// @brief Contains Program class.",
        "using System;",
        "",
        xtd::strings::format("namespace {} {{", name),
        "  class Program {",
        "    /// @brief The main entry point for the application.",
        "    /// @param args An array of string that represent the arguments passed to the program from the execution environment.",
        "    static void Main(string[] args) {",
        "      Console.WriteLine(\"Hello, World!\");",
        "    }",
        "  }",
        "}"
      };
      
      xtd::io::file::write_all_lines(path_/name/"src"/xtd::strings::format("{0}.cs", name), lines);
    }

    void create_objectivec_console(const std::string& name, project_sdk sdk, project_language language) const {
      create_objectivec_console_solution_cmakelists_txt(name);
      std::filesystem::create_directories(path_/name/"src");
      create_objectivec_console_cmakelists_txt(name);
      create_objectivec_console_source(name);
    }
    
    void create_objectivec_console_solution_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Solution",
        xtd::strings::format("project({0})", name),
        xtd::strings::format("add_subdirectory({0})", name)
      };
      xtd::io::file::write_all_lines(path_/"CMakeLists.txt", lines);
    }
    
    void create_objectivec_console_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Project",
        xtd::strings::format("project({0}  VERSION 1.0.0)", name),
        "set(SOURCES",
        xtd::strings::format("  src/{0}.m", name),
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} ${SOURCES})"
      };
      
      xtd::io::file::write_all_lines(path_/name/"CMakeLists.txt", lines);
    }
    
    void create_objectivec_console_source(const std::string& name) const {
      std::vector<std::string> lines {
        "/// @file",
        "/// @brief Contains main method.",
        "#import <Foundation/Foundation.h>",
        "",
        "/// @brief The main entry point for the application.",
        "/// @param argc Size of array of char* that represent the arguments passed to the program from the execution environment.",
        "/// @param argv An array of char* that represent the arguments passed to the program from the execution environment.",
        "int main(int argc, const char * argv[]) {",
        "  @autoreleasepool {",
        "    NSLog(@\"Hello, World!\");",
        "  }",
        "  return 0;",
        "}"
      };
      
      xtd::io::file::write_all_lines(path_/name/"src"/xtd::strings::format("{0}.m", name), lines);
    }

    void create_xtd_console(const std::string& name, project_sdk sdk, project_language language) const {
      create_xtd_console_solution_cmakelists_txt(name);
      std::filesystem::create_directories(path_/name/"src");
      create_xtd_console_cmakelists_txt(name);
      create_xtd_console_source(name);
    }
    
    void create_xtd_console_solution_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.3)",
        "",
        "# Solution",
        xtd::strings::format("project({0})", name),
        "find_package(xtd REQUIRED)",
        "add_projects(",
        xtd::strings::format("  {0}", name),
        ")",
        "",
        "# Install",
        "install_package()"
      };
      xtd::io::file::write_all_lines(path_/"CMakeLists.txt", lines);
    }
    
    void create_xtd_console_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.3)",
        "",
        "# Project",
        xtd::strings::format("project({0})", name),
        "find_package(xtd REQUIRED)",
        "add_sources(",
        xtd::strings::format("  src/{0}.cpp", name),
        ")",
        "target_type(CONSOLE_APPLICATION)",
        "",
        "# Install",
        "install_component()",
      };
      
      xtd::io::file::write_all_lines(path_/name/"CMakeLists.txt", lines);
    }
    
    void create_xtd_console_source(const std::string& name) const {
      std::vector<std::string> lines {
        "/// @file",
        "/// @brief Contains main method.",
        "#include <xtd/xtd.console>",
        "",
        "using namespace xtd;",
        "",
        "/// @brief The main entry point for the application.",
        "/// @param argc Size of array of char* that represent the arguments passed to the program from the execution environment.",
        "/// @param argv An array of char* that represent the arguments passed to the program from the execution environment.",
        "int main(int argc, char* argv[]) {",
        "  console::write_line(\"Hello, World!\");",
        "}"
      };
      
      xtd::io::file::write_all_lines(path_/name/"src"/xtd::strings::format("{0}.cpp", name), lines);
    }

    void create_gui(const std::string& name, project_sdk sdk, project_language language) const {
      create_doxygen_txt(name);
      std::map<project_sdk, xtd::action<const std::string&, project_sdk, project_language>> {{project_sdk::cocoa, {*this, &project_management::create_cocoa_gui}}, {project_sdk::gtk2, {*this, &project_management::create_gtk2_gui}}, {project_sdk::gtk3, {*this, &project_management::create_gtk3_gui}}, {project_sdk::gtkmm, {*this, &project_management::create_gtkmm_gui}}, {project_sdk::qt5, {*this, &project_management::create_qt5_gui}}, {project_sdk::win32, {*this, &project_management::create_win32_gui}}, {project_sdk::winforms, {*this, &project_management::create_winforms_gui}}, {project_sdk::wpf, {*this, &project_management::create_wpf_gui}}, {project_sdk::xtd, {*this, &project_management::create_xtd_gui}}}[sdk](name, sdk, language);
    }
    
    void create_cocoa_gui(const std::string& name, project_sdk sdk, project_language language) const {
      create_cocoa_gui_solution_cmakelists_txt(name);
      std::filesystem::create_directories(path_/name/"src");
      create_cocoa_gui_cmakelists_txt(name);
      create_cocoa_gui_source(name);
    }
    
    void create_cocoa_gui_solution_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Solution",
        xtd::strings::format("project({0})", name),
        xtd::strings::format("add_subdirectory({0})", name)
      };
      xtd::io::file::write_all_lines(path_/"CMakeLists.txt", lines);
    }
    
    void create_cocoa_gui_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Project",
        xtd::strings::format("project({0}  VERSION 1.0.0)", name),
        "set(SOURCES",
        xtd::strings::format("  src/{0}.m", name),
        ")",
        "source_group(src FILES ${SOURCES})",
        "",
        "# Options",
        "set(CMAKE_EXE_LINKER_FLAGS \"${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa\")",
        "set(MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION})",
        xtd::strings::format("set(MACOSX_BUNDLE_COPYRIGHT \"Copyright © {:L}\")", std::chrono::system_clock::now()),
        xtd::strings::format("set(MACOSX_BUNDLE_INFO_STRING \"{} application\")", name),
        xtd::strings::format("set(MACOSX_BUNDLE_GUI_IDENTIFIER \"org.Company.{}\")", name),
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SOURCES})"
      };
      
      xtd::io::file::write_all_lines(path_/name/"CMakeLists.txt", lines);
    }
    
    void create_cocoa_gui_source(const std::string& name) const {
      std::vector<std::string> lines {
        "/// @file",
        "/// @brief Contains main method.",
        "#import <Cocoa/Cocoa.h>",
        "",
        "/// @brief Represents the main NSWindow",
        "@interface Window1 : NSWindow {",
        "}",
        " /// @brief Initializes a new instance of the Window1 class.",
        "- (instancetype)init;",
        "- (BOOL)windowShouldClose:(id)sender;",
        "@end",
        "",
        "@implementation Window1",
        "- (instancetype)init {",
        "  [super initWithContentRect:NSMakeRect(100, 500, 800, 450) styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable | NSWindowStyleMaskResizable backing:NSBackingStoreBuffered defer:NO];",
        "  [self setTitle:@\"Form1\"];",
        "  [self setIsVisible:YES];",
        "  return self;",
        "}",
        "",
        "- (BOOL)windowShouldClose:(id)sender {",
        "   [NSApp terminate:sender];",
        "   return NO;",
        "}",
        "@end",
        "",
        "/// @brief The main entry point for the application.",
        "/// @param argc Size of array of char* that represent the arguments passed to the program from the execution environment.",
        "/// @param argv An array of char* that represent the arguments passed to the program from the execution environment.",
        "int main(int argc, char* argv[]) {",
        "  [NSApplication sharedApplication];",
        "  [[[[Window1 alloc] init] autorelease] makeMainWindow];",
        "  [NSApp run];",
        "}",
      };
      
      xtd::io::file::write_all_lines(path_/name/"src"/xtd::strings::format("{0}.m", name), lines);
    }

    void create_gtk2_gui(const std::string& name, project_sdk sdk, project_language language) const {
      create_gtk2_gui_solution_cmakelists_txt(name);
      std::filesystem::create_directories(path_/name/"src");
      create_gtk2_gui_cmakelists_txt(name);
      create_gtk2_gui_source(name);
    }
    
    void create_gtk2_gui_solution_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Solution",
        xtd::strings::format("project({0})", name),
        xtd::strings::format("add_subdirectory({0})", name)
      };
      xtd::io::file::write_all_lines(path_/"CMakeLists.txt", lines);
    }
    
    void create_gtk2_gui_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Project",
        xtd::strings::format("project({0}  VERSION 1.0.0)", name),
        "set(SOURCES",
        xtd::strings::format("  src/{0}.cpp", name),
        ")",
        "source_group(src FILES ${SOURCES})",
        "find_package(PkgConfig)",
        "pkg_check_modules(GTK gtk+-2.0)",
        "include_directories(${GTK_INCLUDE_DIRS})",
        "link_directories(${GTK_LIBRARY_DIRS})",
        "link_libraries(${GTK_LIBRARIES})",
        "",
        "# Options",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})"
      };
      
      xtd::io::file::write_all_lines(path_/name/"CMakeLists.txt", lines);
    }
    
    void create_gtk2_gui_source(const std::string& name) const {
      std::vector<std::string> lines {
        "/// @file",
        "/// @brief Contains main funcxtion.",
        "#include <gtk/gtk.h>",
        "",
        "/// @brief The main entry point for the application.",
        "/// @param argc Size of array of char* that represent the arguments passed to the program from the execution environment.",
        "/// @param argv An array of char* that represent the arguments passed to the program from the execution environment.",
        "int main(int argc, char* argv[]) {",
        "  gtk_init(&argc, &argv);",
        "",
        "  GtkWidget* window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);",
        "  gtk_window_set_title(GTK_WINDOW(window1), \"Window1\");",
        "  gtk_window_move(GTK_WINDOW(window1), 100, 100);",
        "  gtk_window_resize(GTK_WINDOW(window1), 800, 450);",
        "  g_signal_connect (window1, \"destroy\", G_CALLBACK(+[](GtkWidget* widget, gpointer data) {",
        "    gtk_main_quit();",
        "  }), nullptr);",
        "  gtk_widget_show(window1);",
        "  gtk_main();",
        "}",
      };
      
      xtd::io::file::write_all_lines(path_/name/"src"/xtd::strings::format("{0}.cpp", name), lines);
    }

    void create_gtk3_gui(const std::string& name, project_sdk sdk, project_language language) const {
      create_gtk3_gui_solution_cmakelists_txt(name);
      std::filesystem::create_directories(path_/name/"src");
      create_gtk3_gui_cmakelists_txt(name);
      create_gtk3_gui_source(name);
    }
    
    void create_gtk3_gui_solution_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Solution",
        xtd::strings::format("project({0})", name),
        xtd::strings::format("add_subdirectory({0})", name)
      };
      xtd::io::file::write_all_lines(path_/"CMakeLists.txt", lines);
    }
    
    void create_gtk3_gui_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Project",
        xtd::strings::format("project({0}  VERSION 1.0.0)", name),
        "set(SOURCES",
        xtd::strings::format("  src/{0}.cpp", name),
        ")",
        "source_group(src FILES ${SOURCES})",
        "find_package(PkgConfig)",
        "pkg_check_modules(GTK gtk+-3.0)",
        "include_directories(${GTK_INCLUDE_DIRS})",
        "link_directories(${GTK_LIBRARY_DIRS})",
        "link_libraries(${GTK_LIBRARIES})",
        "",
        "# Options",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})"
      };
      
      xtd::io::file::write_all_lines(path_/name/"CMakeLists.txt", lines);
    }
    
    void create_gtk3_gui_source(const std::string& name) const {
      std::vector<std::string> lines {
        "/// @file",
        "/// @brief Contains main funcxtion.",
        "#include <gtk/gtk.h>",
        "",
        "/// @brief The main entry point for the application.",
        "/// @param argc Size of array of char* that represent the arguments passed to the program from the execution environment.",
        "/// @param argv An array of char* that represent the arguments passed to the program from the execution environment.",
        "int main(int argc, char* argv[]) {",
        "  gtk_init(&argc, &argv);",
        "",
        "  GtkWidget* window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);",
        "  gtk_window_set_title(GTK_WINDOW(window1), \"Window1\");",
        "  gtk_window_move(GTK_WINDOW(window1), 100, 100);",
        "  gtk_window_resize(GTK_WINDOW(window1), 800, 450);",
        "  g_signal_connect (window1, \"destroy\", G_CALLBACK(+[](GtkWidget* widget, gpointer data) {",
        "    gtk_main_quit();",
        "  }), nullptr);",
        "  gtk_widget_show(window1);",
        "  gtk_main();",
        "}",
      };
      
      xtd::io::file::write_all_lines(path_/name/"src"/xtd::strings::format("{0}.cpp", name), lines);
    }

    void create_gtkmm_gui(const std::string& name, project_sdk sdk, project_language language) const {
      create_gtkmm_gui_solution_cmakelists_txt(name);
      std::filesystem::create_directories(path_/name/"src");
      create_gtkmm_gui_cmakelists_txt(name);
      create_gtkmm_gui_source(name);
    }
    
    void create_gtkmm_gui_solution_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Solution",
        xtd::strings::format("project({0})", name),
        xtd::strings::format("add_subdirectory({0})", name)
      };
      xtd::io::file::write_all_lines(path_/"CMakeLists.txt", lines);
    }
    
    void create_gtkmm_gui_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Project",
        xtd::strings::format("project({0}  VERSION 1.0.0)", name),
        "set(SOURCES",
        xtd::strings::format("  src/{0}.cpp", name),
        ")",
        "source_group(src FILES ${SOURCES})",
        "find_package(PkgConfig)",
        "pkg_check_modules(GTKMM gtkmm-3.0)",
        "include_directories(${GTKMM_INCLUDE_DIRS})",
        "link_directories(${GTKMM_LIBRARY_DIRS})",
        "link_libraries(${GTKMM_LIBRARIES})",
        "",
        "# Options",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})"
      };
      
      xtd::io::file::write_all_lines(path_/name/"CMakeLists.txt", lines);
    }
    
    void create_gtkmm_gui_source(const std::string& name) const {
      std::vector<std::string> lines {
        "/// @file",
        "/// @brief Contains Window1 class.",
        "#include <gtkmm.h>",
        "",
        "using namespace Gtk;",
        "",
        xtd::strings::format("namespace {} {{", name),
        "  /// @brief Represent the main window",
        "  class Window1 : public Window {",
        "  public:",
        "    /// @brief Initializes a new instance of the Window1 class.",
        "    Window1() {",
        "      scrolledWindow.add(fixed);",
        "",
        "      set_title(\"Window1\");",
        "      move(100, 100);",
        "      resize(800, 450);",
        "      add(scrolledWindow);",
        "    }",
        "",
        "  private:",
        "    ScrolledWindow scrolledWindow;",
        "    Fixed fixed;",
        "  };",
        "}",
        "",
        "/// @brief The main entry point for the application.",
        "/// @param argc Size of array of char* that represent the arguments passed to the program from the execution environment.",
        "/// @param argv An array of char* that represent the arguments passed to the program from the execution environment.",
        "int main(int argc, char* argv[]) {",
        "  auto application = Application::create(argc, argv);",
        xtd::strings::format("  {}::Window1 window1;", name),
        "  window1.show_all();",
        "  return application->run(window1);",
        "}",
      };
      
      xtd::io::file::write_all_lines(path_/name/"src"/xtd::strings::format("{0}.cpp", name), lines);
    }

    void create_qt5_gui(const std::string& name, project_sdk sdk, project_language language) const {
      create_qt5_gui_solution_cmakelists_txt(name);
      std::filesystem::create_directories(path_/name/"src");
      create_qt5_gui_cmakelists_txt(name);
      create_qt5_gui_source(name);
    }
    
    void create_qt5_gui_solution_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Solution",
        xtd::strings::format("project({0})", name),
        xtd::strings::format("add_subdirectory({0})", name)
      };
      xtd::io::file::write_all_lines(path_/"CMakeLists.txt", lines);
    }
    
    void create_qt5_gui_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.8)",
        "",
        "# Project",
        xtd::strings::format("project({0}  VERSION 1.0.0)", name),
        "set(SOURCES",
        xtd::strings::format("  src/{0}.cpp", name),
        ")",
        "source_group(src FILES ${SOURCES})",
        "find_package(Qt5 COMPONENTS Widgets REQUIRED)",
        "",
        "# Options",
        "set(CMAKE_CXX_STANDARD 17)",
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)",
        "",
        "# Application properties",
        "add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})",
        "target_link_libraries(${PROJECT_NAME} Qt5::Widgets)"
      };
      
      xtd::io::file::write_all_lines(path_/name/"CMakeLists.txt", lines);
    }
    
    void create_qt5_gui_source(const std::string& name) const {
      std::vector<std::string> lines {
        "/// @file",
        "/// @brief Contains Window1 class.",
        "#include <QApplication>",
        "#include <QMainWindow>",
        "",
        xtd::strings::format("namespace {} {{", name),
        "  /// @brief Represent the main window",
        "  class Window1 : public QMainWindow {",
        "  public:",
        "    /// @brief Initializes a new instance of the Window1 class.",
        "    Window1() {",
        "      setWindowTitle(\"Window1\");",
        "      move(100, 100);",
        "      resize(800, 450);",
        "    }",
        "  };",
        "}",
        "",
        "/// @brief The main entry point for the application.",
        "/// @param argc Size of array of char* that represent the arguments passed to the program from the execution environment.",
        "/// @param argv An array of char* that represent the arguments passed to the program from the execution environment.",
        "int main(int argc, char* argv[]) {",
        "  QApplication application(argc, argv);",
        xtd::strings::format("  {}::Window1 window1;", name),
        "  window1.show();",
        "  return application.exec();",
        "}",
      };
      
      xtd::io::file::write_all_lines(path_/name/"src"/xtd::strings::format("{0}.cpp", name), lines);
    }

    void create_win32_gui(const std::string& name, project_sdk sdk, project_language language) const {
    }
    
    void create_winforms_gui(const std::string& name, project_sdk sdk, project_language language) const {
    }
    
    void create_wpf_gui(const std::string& name, project_sdk sdk, project_language language) const {
    }
    
    void create_wxwidgets_gui(const std::string& name, project_sdk sdk, project_language language) const {
    }
    
    void create_xtd_gui(const std::string& name, project_sdk sdk, project_language language) const {
      create_xtd_gui_solution_cmakelists_txt(name);
      std::filesystem::create_directories(path_/name/"src");
      create_xtd_gui_cmakelists_txt(name);
      create_xtd_gui_source(name);
   }
    
    void create_xtd_gui_solution_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.3)",
        "",
        "# Solution",
        xtd::strings::format("project({0})", name),
        "find_package(xtd REQUIRED)",
        "add_projects(",
        xtd::strings::format("  {0}", name),
        ")",
        "",
        "# Install",
        "install_package()"
      };
      xtd::io::file::write_all_lines(path_/"CMakeLists.txt", lines);
    }
    
    void create_xtd_gui_cmakelists_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "cmake_minimum_required(VERSION 3.3)",
        "",
        "# Project",
        xtd::strings::format("project({0})", name),
        "find_package(xtd REQUIRED)",
        "add_sources(",
        xtd::strings::format("  src/{0}.cpp", name),
        ")",
        "target_type(GUI_APPLICATION)",
        "",
        "# Install",
        "install_component()",
      };
      
      xtd::io::file::write_all_lines(path_/name/"CMakeLists.txt", lines);
    }
    
    void create_xtd_gui_source(const std::string& name) const {
      std::vector<std::string> lines {
        "/// @file",
        "/// @brief Contains form1 class.",
        "#include <xtd/xtd.forms>",
        "",
        "using namespace xtd::forms;",
        "",
        xtd::strings::format("namespace {} {{", name),
        "  /// @brief Represents the main form",
        "  class form1 : public form {",
        "  public:",
        "    /// @brief Initializes a new instance of the form1 class.",
        "    form1() {",
        "      text(\"form1\");",
        "      client_size({800, 450});",
        "    }",
        "  };",
        "}",
        "",
        "/// @brief The main entry point for the application.",
        "/// @param argc Size of array of char* that represent the arguments passed to the program from the execution environment.",
        "/// @param argv An array of char* that represent the arguments passed to the program from the execution environment.",
        "int main(int argc, char* argv[]) {",
        xtd::strings::format("  application::run({}::form1());", name),
        "}"
      };
      
      xtd::io::file::write_all_lines(path_/name/"src"/xtd::strings::format("{0}.cpp", name), lines);
    }

    void create_shared_library(const std::string& name, project_sdk sdk, project_language language) const {
      create_doxygen_txt(name);
    }
    
    void create_static_library(const std::string& name, project_sdk sdk, project_language language) const {
      create_doxygen_txt(name);
    }
    
    void create_unit_test_application(const std::string& name, project_sdk sdk, project_language language) const {
      create_doxygen_txt(name);
    }
    
    void create_doxygen_txt(const std::string& name) const {
      std::vector<std::string> lines {
        "#---------------------------------------------------------------------------\n",
        "# Project related configuration options\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        xtd::strings::format("PROJECT_NAME           = \"{} - Reference Guide\"\n", name),
        "PROJECT_NUMBER         = 0.1.0\n",
        "PROJECT_BRIEF          = \n",
        "PROJECT_LOGO           = \n",
        "OUTPUT_DIRECTORY       = \n",
        "ALWAYS_DETAILED_SEC    = YES\n",
        "INLINE_INHERITED_MEMB  = NO\n",
        "FULL_PATH_NAMES        = NO\n",
        "STRIP_FROM_PATH        = \n",
        "STRIP_FROM_INC_PATH    = \n",
        "TAB_SIZE               = 2\n",
        "TOC_INCLUDE_HEADINGS   = 0\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Build related configuration options\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "SORT_BRIEF_DOCS        = YES\n",
        "SORT_MEMBERS_CTORS_1ST = YES\n",
        "SORT_GROUP_NAMES       = YES\n",
        "SORT_BY_SCOPE_NAME     = YES\n",
        "#MAX_INITIALIZER_LINES  = 0\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to warning and progress messages\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "WARN_LOGFILE           = doxygen_warnings.txt\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the input files\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "INPUT                  = src\n",
        "RECURSIVE              = YES\n",
        "EXCLUDE_PATTERNS       = \n",
        "EXAMPLE_PATH           = \n",
        "EXAMPLE_PATTERNS       = *\n",
        "EXAMPLE_RECURSIVE      = YES\n",
        "IMAGE_PATH             = \n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to source browsing\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the alphabetical class index\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "COLS_IN_ALPHA_INDEX    = 1\n",
        "IGNORE_PREFIX          = \n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the HTML output\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "HTML_OUTPUT            = ReferenceGuide\n",
        "HTML_HEADER            = \n",
        "HTML_FOOTER            = \n",
        "HTML_STYLESHEET        = \n",
        "HTML_EXTRA_STYLESHEET  = \n",
        "HTML_EXTRA_FILES       = \n",
        "HTML_COLORSTYLE_HUE    = 220\n",
        "HTML_COLORSTYLE_SAT    = 100\n",
        "HTML_COLORSTYLE_GAMMA  = 80\n",
        "HTML_TIMESTAMP         = YES\n",
        "HTML_DYNAMIC_SECTIONS  = NO\n",
        "HTML_INDEX_NUM_ENTRIES = 100\n",
        "GENERATE_DOCSET        = NO\n",
        "GENERATE_HTMLHELP      = NO\n",
        "GENERATE_QHP           = NO\n",
        "QCH_FILE               = \n",
        "GENERATE_ECLIPSEHELP   = NO\n",
        "DISABLE_INDEX          = NO\n",
        "GENERATE_TREEVIEW      = YES\n",
        "ENUM_VALUES_PER_LINE   = 1\n",
        "TREEVIEW_WIDTH         = 250\n",
        "EXT_LINKS_IN_WINDOW    = NO\n",
        "FORMULA_FONTSIZE       = 10\n",
        "FORMULA_TRANSPARENT    = YES\n",
        "USE_MATHJAX            = NO\n",
        "SEARCHENGINE           = YES\n",
        "SERVER_BASED_SEARCH    = NO\n",
        "EXTERNAL_SEARCH        = NO\n",
        "SEARCHENGINE_URL       = \n",
        "SEARCHDATA_FILE        = searchdata.xml\n",
        "EXTERNAL_SEARCH_ID     = \n",
        "EXTRA_SEARCH_MAPPINGS  = \n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the LaTeX output\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "GENERATE_LATEX         = NO\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the RTF output\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the man page output\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the XML output\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the DOCBOOK output\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options for the AutoGen Definitions output\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the Perl module output\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the preprocessor\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "MACRO_EXPANSION        = YES\n",
        "EXPAND_ONLY_PREDEF     = YES\n",
        "SEARCH_INCLUDES        = YES\n",
        "INCLUDE_PATH           = \n",
        "INCLUDE_FILE_PATTERNS  = \n",
        "PREDEFINED             = \"static_=final : public xtd::static\"\n",
        "EXPAND_AS_DEFINED      = \n",
        "SKIP_FUNCTION_MACROS   = YES\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to external references\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "#---------------------------------------------------------------------------\n",
        "# Configuration options related to the dot tool\n",
        "#---------------------------------------------------------------------------\n",
        "\n",
        "CLASS_DIAGRAMS         = YES\n",
        "MSCGEN_PATH            = \n",
        "DIA_PATH               = \n",
        "HIDE_UNDOC_RELATIONS   = YES\n",
        "HAVE_DOT               = NO\n",
        "DOT_NUM_THREADS        = 0\n",
        "DOT_FONTNAME           = Helvetica\n",
        "DOT_FONTSIZE           = 10\n",
        "DOT_FONTPATH           = \n",
        "CLASS_GRAPH            = YES\n",
        "COLLABORATION_GRAPH    = YES\n",
        "GROUP_GRAPHS           = YES\n",
        "UML_LOOK               = NO\n",
        "UML_LIMIT_NUM_FIELDS   = 10\n",
        "TEMPLATE_RELATIONS     = NO\n",
        "INCLUDE_GRAPH          = YES\n",
        "INCLUDED_BY_GRAPH      = YES\n",
        "CALL_GRAPH             = NO\n",
        "CALLER_GRAPH           = NO\n",
        "GRAPHICAL_HIERARCHY    = YES\n",
        "DIRECTORY_GRAPH        = YES\n",
        "DOT_IMAGE_FORMAT       = png\n",
        "INTERACTIVE_SVG        = NO\n",
        "DOT_PATH               = \n",
        "DOTFILE_DIRS           = \n",
        "MSCFILE_DIRS           = \n",
        "DIAFILE_DIRS           = \n",
        "PLANTUML_JAR_PATH      = \n",
        "PLANTUML_CFG_FILE      = \n",
        "PLANTUML_INCLUDE_PATH  = \n",
        "DOT_GRAPH_MAX_NODES    = 50\n",
        "MAX_DOT_GRAPH_DEPTH    = 0\n",
        "DOT_TRANSPARENT        = NO\n",
        "DOT_MULTI_TARGETS      = NO\n",
        "GENERATE_LEGEND        = YES\n",
        "DOT_CLEANUP            = YES\n",
      };
      xtd::io::file::write_all_lines(path_/".doxygen.txt", lines);
   }

    void generate() const {generate("");}

    void generate(std::string name) const {
      bool first_generation = !std::filesystem::exists(build_path());
      std::filesystem::create_directories(build_path());
      if (!first_generation && name.empty()) name = get_name();
      if (xtd::environment::os_version().is_windows_platform() && (first_generation || !std::filesystem::exists(build_path()/xtd::strings::format("{}.sln", name))))
        system(xtd::strings::format("cmake -S {} -B {}", path_, build_path()).c_str());
      else if (xtd::environment::os_version().is_osx_platform() && (first_generation || !std::filesystem::exists(build_path()/xtd::strings::format("{}.xcodeproj", name))))
        system(xtd::strings::format("cmake -S {} -B {} -G \"Xcode\"", path_, build_path()).c_str());
      else if (xtd::environment::os_version().is_linux_platform() && (first_generation || !std::filesystem::exists(build_path()/"Debug"/xtd::strings::format("{}.cbp", name)))) {
        std::filesystem::create_directories(build_path()/"Debug");
        system(xtd::strings::format("cmake -S {} -B {} -G \"CodeBlocks - Unix Makefiles\"", path_, build_path()/"Debug").c_str());
      } else if (xtd::environment::os_version().is_linux_platform() && (first_generation || !std::filesystem::exists(build_path()/"Release"/xtd::strings::format("{}.cbp", name)))) {
        std::filesystem::create_directories(build_path()/"Release");
        system(xtd::strings::format("cmake -S {} -B {} -G \"CodeBlocks - Unix Makefiles\"", path_, build_path()/"Release").c_str());
      }
    }

    bool is_path_already_exist_and_not_empty(const std::filesystem::path& path) const {
      if (!std::filesystem::exists({path_})) return false;
      if (std::filesystem::is_empty({path_})) return false;
      if (xtd::environment::os_version().is_osx_platform() && std::count_if(std::filesystem::directory_iterator(path_), std::filesystem::directory_iterator(), [](auto item) {return item.path().filename().string() != ".DS_Store";}) == 0) return false;
      return true;
    }
    
    std::filesystem::path path_ {xtd::environment::current_directory()};
  };
}
