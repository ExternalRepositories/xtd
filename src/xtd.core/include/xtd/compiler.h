#pragma once
#include <vector>
#include "build_type.h"
#include "compiler_id.h"
#include "format.h"
#include "version.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents information about c++ libraries, such as the version and standard identifier. This class cannot be inherited.
  /// @remarks The compiler class contains information about c++ libraries.
  /// @remarks For information about current c++ libraries, retrieve the compiler object returned by the xtd::environment::compiler_version method.
  /// @remarks By design, the operating_system class is not a general purpose means of describing an operating system, and you cannot derive a more inclusive type from the operating_system class. If you need a type to contain other information about C++ libraries, create your own type, then include a field of typecompiler and any additional fields or methods that you require.
  class compiler final {
  public:
    compiler(xtd::compiler_id compiler_id) : compiler_id_(compiler_id) {}
    
    /// @cond
    compiler() = default;
    compiler(const compiler&) = default;
    compiler& operator=(const compiler&) = default;
    friend std::ostream& operator <<(std::ostream& os, const compiler& compiler) noexcept {return os << compiler.to_string();}
    /// @endcond
    
    xtd::build_type build_type() const noexcept {return build_type_;}
    
    xtd::compiler_id compiler_id() const noexcept {return compiler_id_;}
    
    bool is_build_type_debug() const noexcept {return build_type_ == xtd::build_type::debug; }
    
    static bool is_64_bit() noexcept {return sizeof(size_t) == 8;}

    std::string name() const noexcept {
      static std::map<xtd::compiler_id, std::string> names {{compiler_id::unknown, "<unknown>"}, {compiler_id::microsoft_visual_studio, "Microsoft Visual Studio"}, {compiler_id::clang, "clang"}, {compiler_id::gcc, "gcc"}};
      return names[compiler_id()];
    }
    
    std::string version_string() const noexcept {
      return format("{} {}", name(), version());
    }
    
    const xtd::version& version() const noexcept {return version_;}
    
    /// @brief Converts the value of this operating_system object to its equivalent string representation.
    /// @return The string representation of the values returned by the platform, version, and service_pack methods.
    std::string to_string() const noexcept {return version_string();}
    
  private:
#if _MSC_VER
    xtd::compiler_id compiler_id_ = xtd::compiler_id::microsoft_visual_studio;
#elif __clang__
    xtd::compiler_id compiler_id_ = xtd::compiler_id::clang;
#elif __GNUC__
    xtd::compiler_id compiler_id_ = xtd::compiler_id::gcc;
#else
    xtd::compiler_id compiler_id_ = xtd::compiler_id::unknown;
#endif
#if _MSC_VER
    xtd::version version_ {_MSC_VER/100, _MSC_VER%100, 0};
#elif __clang__
    xtd::version version_ {__clang_major__ , __clang_minor__, __clang_patchlevel__};
#elif __GNUC__
    xtd::version version_ {__GNUC__ , __GNUC_MINOR__, __GNUC_PATCHLEVEL__};
#else
    xtd::version version_;
#endif
#if NDEBUG
    xtd::build_type build_type_ = xtd::build_type::release;
#else
    xtd::build_type build_type_ = xtd::build_type::debug;
#endif
  };
}
