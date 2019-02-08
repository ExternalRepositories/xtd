/// @file
/// @brief Contains __get_err_rdbuf method.
#pragma once
#include <iostream>

/// @cond
template<class Char>
inline std::basic_streambuf<Char>* __get_err_rdbuf() {return nullptr;};

template<>
inline std::basic_streambuf<char>* __get_err_rdbuf<char>() {
  static std::basic_streambuf<char>* rdbuf = std::cerr.rdbuf();
  return rdbuf;
};

template<>
inline std::basic_streambuf<wchar_t>* __get_err_rdbuf<wchar_t>() {
  static std::basic_streambuf<wchar_t>* rdbuf = std::wcerr.rdbuf();
  return rdbuf;
};
/// @endcond
