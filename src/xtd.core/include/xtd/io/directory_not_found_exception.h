#pragma once
#include "ioexception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief The exception that is thrown when part of a file or directory cannot be found.
    /// @par Library
    /// xtd.core
    /// @par Examples
    /// The following example demonstrates how to throw and catch an directory_not_found_exception.
    /// @include directory_not_found_exception.cpp
    class directory_not_found_exception :public ioexception {
    public:
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      /// @remarks Message is set with the default message associate to the exception.
      directory_not_found_exception(const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(default_message(), info) {}
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit directory_not_found_exception(const std::string& message, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, info) {}
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit directory_not_found_exception(const std::string& message, const std::error_code& error, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, error, info) {}
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit directory_not_found_exception(const std::string& message, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, help_link, info) {}
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      explicit directory_not_found_exception(const std::string& message, const std::error_code& error, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, error, help_link, info) {}
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      /// @remarks Message is set with the default message associate to the exception.
      directory_not_found_exception(const std::exception& inner_exception, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(default_message(), inner_exception, info) {}
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit directory_not_found_exception(const std::string& message, const std::exception& inner_exception, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, inner_exception, info) {}
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit directory_not_found_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, inner_exception, error, info) {}
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit directory_not_found_exception(const std::string& message, const std::exception& inner_exception, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, inner_exception, help_link, info) {}
      /// @brief Create a new instance of class directory_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit directory_not_found_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, inner_exception, error, help_link, info) {}
      
      /// @cond
      directory_not_found_exception(const directory_not_found_exception&) = default;
      directory_not_found_exception& operator=(const directory_not_found_exception&) = default;
      /// @endcond
      
    private:
      const char* default_message() const {return "Attempted to access a path that is not on the disk."_t;}
    };
  }
}
