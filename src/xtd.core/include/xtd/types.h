#pragma once
#include <cstdint>
#include <string>
#include <typeinfo>
#include "core_export.h"

#if !defined(__cpp_lib_char8_t)
class char8_t {
public:
  char8_t() {}
  char8_t(char value) : value_(value) {}
  char8_t(const char8_t&) = default;
  char8_t(char8_t&&) = default;
  
  operator char() const {return value_;}
  bool operator==(char8_t c) const {return value_ == c.value_;}
  bool operator!=(char8_t c) const {return value_ != c.value_;}
  bool operator<(char8_t c) const {return value_ < c.value_;}
  bool operator>(char8_t c) const {return value_ > c.value_;}
  bool operator<=(char8_t c) const {return value_ <= c.value_;}
  bool operator>=(char8_t c) const {return value_ >= c.value_;}
  
  char8_t operator+(char8_t c) const {return char8_t(value_ + c.value_);}
  char8_t operator-(char8_t c) const {return char8_t(value_ - c.value_);}
  char8_t& operator=(char8_t c) {value_ = c.value_; return *this;}
  char8_t& operator++() {value_ += 1; return *this;}
  char8_t operator++(int) {char8_t result(*this); ++(*this); return result;}
  char8_t& operator--() {value_ -= 1; return *this;}
  char8_t operator--(int) {char8_t result(*this); --(*this); return result;}
  
  bool operator==(char c) const {return value_ == c;}
  bool operator!=(char c) const {return value_ != c;}
  bool operator<(char c) const {return value_ < c;}
  bool operator>(char c) const {return value_ > c;}
  bool operator<=(char c) const {return value_ <= c;}
  bool operator>=(char c) const {return value_ >= c;}
  
  friend std::ostream& operator <<(std::ostream& os, const char8_t& c) noexcept {return os << std::to_string(static_cast<int32_t>(c.value_));}
  
private:
  char value_ = 0;
};
#endif

using decimal_t = long double;

using single_t = float;

using ushort_t = unsigned short;

using ulong_t = unsigned long;

#if defined(__linux__) && defined(_LP64)
using llong_t = long long int;
using ullong_t = unsigned long long int;
#else
using llong_t = long;
using ullong_t = unsigned long;
#endif

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a 8-bit unsigned integer.
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using byte = uint8_t;
  
  /// @brief Represents a 16-bit unicode character.
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using char8 = char8_t;
  
  /// @brief Represents a 8-bit unicode character.
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using char16 = char16_t;

  /// @brief Represents a 32-bit unicode character.
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using char32 = char32_t;
  
  /// @brief Represents a decimal-precision floating-point number.
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using decimal = decimal_t;
  
  /// @brief Represents a 16-bit signed integer.
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using int16 = int16_t;
  
  /// @brief Represents a 32-bit signed integer.
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using int32 = int32_t;
  
  /// @brief Represents a 64-bit signed integer.
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using int64 = int64_t;
  
  /// @brief Represent a pointer or a handle.
  /// @ingroup types
  using intptr = intptr_t;
  
  /// @brief Represents a null pointer value.
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// std::unique_ptr<foo_class> foo = std::make_unique<foo_class>();
  /// ...
  /// foo = null; // release the unique pointer.
  /// @endcode
  /// @ingroup types
  extern core_export_ std::nullptr_t null;
  
  /// @brief Represents a 8-bit signed integer.
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using sbyte = int8_t;
  
  /// @brief Represents a size of any object in bytes
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using size = size_t;
  
  /// @brief Stores information about a type.
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using type = std::type_info;
  
  /// @brief Represents a 8-bit unsigned integer.
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using uchar = unsigned char;
  
  /// @brief Represents a 32-bit unsigned integer.
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using uint = unsigned int;
  
  /// @brief Represents a 16-bit unsigned integer.
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using uint16 = uint16_t;
  
  /// @brief Represents a 32-bit unsigned integer.
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using uint32 = uint32_t;
  
  /// @brief Represents a 64-bit unsigned integer.
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using uint64 = uint64_t;
  
  /// @brief Represent a pointer or a handle.
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using uintptr = uintptr_t;
  
  /// @brief Represents a 16-bit unsigned integer.
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using ushort = ushort_t;
  
  /// @brief Represents a 32-bit or 64-bit unsigned integer.
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using ulong = ulong_t;
  
  /// @brief Represents a wide character.
  /// @par Library
  /// xtd.core
  /// @ingroup types
  using wchar = wchar_t;
}
