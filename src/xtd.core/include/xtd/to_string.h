/// @file
/// @brief Contains xtd::to_string methods.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

/// @cond
#define __XTD_CORE_INTERNAL__
#include "internal/__binary_formater.h"
#include "internal/__boolean_formater.h"
#include "internal/__character_formater.h"
#include "internal/__currency_formater.h"
#include "internal/__date_time_formater.h"
#include "internal/__duration_formater.h"
#include "internal/__enum_formater.h"
#include "internal/__fixed_point_formater.h"
#include "internal/__natural_formater.h"
#include "internal/__numeric_formater.h"
#include "internal/__string_formater.h"
#undef __XTD_CORE_INTERNAL__
/// @endcond
#include <string>
#include "types.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<typename value_t>
  inline std::string to_string(const value_t& value, const std::string& fmt, const std::locale& loc) {return __to_string_enum(value, fmt, loc, std::is_enum<value_t>());}
  
  template<>
  inline std::string to_string(const bool& value, const std::string& fmt, const std::locale& loc) {return __boolean_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const int8_t& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const char& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const unsigned char& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const short& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const unsigned short& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const int& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const unsigned int& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const long& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const unsigned long& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const long long& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const unsigned long long& value, const std::string& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const float& value, const std::string& fmt, const std::locale& loc) {return __fixed_point_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const double& value, const std::string& fmt, const std::locale& loc) {return __fixed_point_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const long double& value, const std::string& fmt, const std::locale& loc) {return __fixed_point_formater(fmt, value, loc);}

  template<>
  inline std::string to_string(const std::chrono::system_clock::time_point& value, const std::string& fmt, const std::locale& loc) {return __date_time_formater(fmt, std::chrono::system_clock::to_time_t(value), loc);}

  template<>
  inline std::string to_string(const std::tm& value, const std::string& fmt, const std::locale& loc) {return __date_time_formater(fmt, value, loc);}

  template<typename type_t, typename Period>
  inline std::string to_string(const std::chrono::duration<type_t, Period>& value, const std::string& fmt, const std::locale& loc) {return __duration_formater(fmt, value, loc);}

  template<>
  inline std::string to_string(const char8_t& value, const std::string& fmt, const std::locale& loc) {return __character_formater(fmt, value, loc);}

  template<>
  inline std::string to_string(const char16_t& value, const std::string& fmt, const std::locale& loc) {return __character_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const char32_t& value, const std::string& fmt, const std::locale& loc) {return __character_formater(fmt, value, loc);}
  
  template<>
  inline std::string to_string(const wchar_t& value, const std::string& fmt, const std::locale& loc) {return __character_formater(fmt, value, loc);}

  /// @cond
  std::string to_string(const char* value, const std::string& fmt, const std::locale& loc);
  std::string to_string(const char8_t* value, const std::string& fmt, const std::locale& loc);
  std::string to_string(const char16_t* value, const std::string& fmt, const std::locale& loc);
  std::string to_string(const char32_t* value, const std::string& fmt, const std::locale& loc);
  std::string to_string(const wchar_t* value, const std::string& fmt, const std::locale& loc);
  std::string to_string(const std::string& value, const std::string& fmt, const std::locale& loc);
  std::string to_string(const xtd::ustring& value, const std::string& fmt, const std::locale& loc);
  std::string to_string(const std::u8string& value, const std::string& fmt, const std::locale& loc);
  std::string to_string(const std::u16string& value, const std::string& fmt, const std::locale& loc);
  std::string to_string(const std::u32string& value, const std::string& fmt, const std::locale& loc);
  std::string to_string(const std::wstring& value, const std::string& fmt, const std::locale& loc);
  /// @endcond
  
  template<typename value_t>
  inline std::string to_string(const value_t& value, const std::string& fmt) {return to_string(value, fmt, std::locale());}

  /// @cond
  inline std::string to_string(const char*  value, const std::string& fmt) {return to_string(value, fmt, std::locale());}
  /// @endcond
  
  template<typename value_t>
  inline std::wstring to_string(const value_t& value, const std::wstring& fmt, const std::locale& loc) {return __to_string_enum(value, fmt, loc, std::is_enum<value_t>());}

  template<>
  inline std::wstring to_string(const bool& value, const std::wstring& fmt, const std::locale& loc) {return __boolean_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const int8_t& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const char& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const unsigned char& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const short& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const unsigned short& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const int& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const unsigned int& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const long& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const unsigned long& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const long long& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const unsigned long long& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const float& value, const std::wstring& fmt, const std::locale& loc) {return __fixed_point_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const double& value, const std::wstring& fmt, const std::locale& loc) {return __fixed_point_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const long double& value, const std::wstring& fmt, const std::locale& loc) {return __fixed_point_formater(fmt, value, loc);}

  template<>
  inline std::wstring to_string(const std::chrono::system_clock::time_point& value, const std::wstring& fmt, const std::locale& loc) {return __date_time_formater(fmt, std::chrono::system_clock::to_time_t(value), loc);}
 
  template<>
  inline std::wstring to_string(const std::tm& value, const std::wstring& fmt, const std::locale& loc) {return __date_time_formater(fmt, value, loc);}

  template<typename type_t, typename Period>
  inline std::wstring to_string(const std::chrono::duration<type_t, Period>& value, const std::wstring& fmt, const std::locale& loc) {return __duration_formater(fmt, value, loc);}

  template<>
  inline std::wstring to_string(const std::wstring& value, const std::wstring& fmt, const std::locale& loc) {return __string_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const char8_t& value, const std::wstring& fmt, const std::locale& loc) {return __character_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const char16_t& value, const std::wstring& fmt, const std::locale& loc) {return __character_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const char32_t& value, const std::wstring& fmt, const std::locale& loc) {return __character_formater(fmt, value, loc);}
  
  template<>
  inline std::wstring to_string(const wchar_t& value, const std::wstring& fmt, const std::locale& loc) {return __character_formater(fmt, value, loc);}

  /// @cond
  inline std::wstring to_string(const wchar_t*  value, const std::wstring& fmt, const std::locale& loc) {return __string_formater(fmt, value, loc);}
  /// @endcond

  template<typename value_t>
  inline std::wstring to_string(const value_t& value, const std::wstring& fmt) {return to_string(value, fmt, std::locale());}

  /// @cond
  inline std::wstring to_string(const wchar_t*  value, const std::wstring& fmt) {return to_string(value, fmt, std::locale());}
  /// @endcond
}

