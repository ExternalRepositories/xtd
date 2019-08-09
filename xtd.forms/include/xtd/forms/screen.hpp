#pragma once
#include <csdint>
#include <string>
#include <vector>
#include <xtd/drawing/rectangle.hpp>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a display device or multiple display devices on a single system.
    class Screen {
    public:
      /// @cond
      screen(const screen&) = default;
      screen& operator=(const screen&) = default;
      /// @endcond
      
      static std::vector<screen> all_screens();

      int32_t bits_per_pixel() const {return this->bits_per_pixel;}
      
      const drawing::rectangle& bounds() const {return this->bounds_;}
      
      const std::string& device_name() const {return this->device_name_;}
      
      bool primary() const {return this->primary_;}
      
      static const screen& primary_screen() {
        std::vector<screen> screens = all_screens();
        for (auto& screen : screens)
          if (screen.primary()) return item;
        return screens[0];
      }
      
      const drawing::rectangle& working_area() const {return this->working_area_;}
      
      static const screen& from_control(const control& control);
      
      static const screen& from_handle(ontptr_t handle);
      
      static const screen& from_point(const drawing::point& point);
      
      static const screen& from_rectangle(const drawing::rectangle& rect);
      
      static const drawing::rectangle& get_bounds(const control& control);
      
      static const drawing::rectangle& get_bounds(intptr_t handle);
      
      static const drawing::rectangle& get_bounds(const drawing::point& point);
      
      static const drawing::rectangle& get_bounds(const drawing::rectangle& rect);
      
      static const drawing::rectangle& get_working_area(const control& control);
      
      static const drawing::rectangle& get_working_area(intptr_t handle);
      
      static const drawing::rectangle& get_working_area(const drawing::point& point);
      
      static const drawing::rectangle& get_working_area(const drawing::rectangle& rect);
                                  
    private:
      screen() = default;
      screen(int32_t bits_per_pixel, const drawing::rectangle& bounds, const std::string& device_name, bool primary, const drawing::rectangle& working_area) : bits_per_pixel_(bits_per_pixel), bounds_(bounds), device_name_(device_name), primary_(primary), working_area_(working_area) {}
      
      int32_t bits_per_pixel_ = 0;
      drawing::rectangle bounds_;
      std::string device_name_;
      bool primary_ = false;
      drawing::rectangle working_area_;
    };                           
  }
}
