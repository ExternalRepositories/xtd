[![console](docs/pictures/header.png)](https://gammasoft71.wixsite.com/gammasoft)

[![Build Status](https://travis-ci.org/gammasoft71/xtd.svg?branch=master)](https://travis-ci.org/gammasoft71/xtd)
[![Build status](https://ci.appveyor.com/api/projects/status/uqn1xbctwy88eghu?svg=true)](https://ci.appveyor.com/project/gammasoft71/xtd)
[![codecov](https://codecov.io/gh/gammasoft71/xtd/branch/master/graph/badge.svg)](https://codecov.io/gh/gammasoft71/xtd)
[![Documented](https://codedocs.xyz/gammasoft71/xtd.svg)](https://codedocs.xyz/gammasoft71/xtd/)
[![Documentation](https://img.shields.io/badge/wiki-Documentation-brightgreen.svg)](./docs/home.md)
[![Website](https://img.shields.io/website-up-down-green-red/http/shields.io.svg?label=xtd-console%20website)](https://gammasoft71.wixsite.com/xtd-console)
[![license](https://img.shields.io/github/license/gammasoft71/xtd.svg)](LICENSE.md)
[![Download xtd](https://img.shields.io/sourceforge/dt/xtdpro.svg)](https://sourceforge.net/projects/xtdpro/files/latest/download)
[![GitHub top language](https://img.shields.io/github/languages/top/gammasoft71/xtd.svg)](README.md)
[![Windows](https://img.shields.io/badge/os-Windows-004080.svg)](README.md)
[![macOS](https://img.shields.io/badge/os-macOS-004080.svg)](README.md)
[![Linux](https://img.shields.io/badge/os-Linux-004080.svg)](README.md)

# Notes

[xtd is under development](docs/development_status.md).

# Features

* a collection of native C++ classes libraries, to complete std;
* written in efficient, modern C++17;
* and highly portable and available on many different platforms (Windows, macOS, Linux, iOS and android);

For more information see [documentations](docs/home.md) ([xtd website](https://gammasoft71.wixsite.com/gammasoft)) and [Reference Guide](https://codedocs.xyz/gammasoft71/xtd/).

# Examples

The classic first application 'Hello World'.

## Console

hello_world_console.cpp:

```c++
#include <xtd/xtd>

using namespace xtd;

int main() {
  console::background_color(console_color::blue);
  console::foreground_color(console_color::white);
  console::write_line("Hello, World!");
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(hello_world_console)
find_package(xtd REQUIRED)
add_executable(${PROJECT_NAME} hello_world_console.cpp)
target_link_libraries(${PROJECT_NAME} xtd)
```

## Forms

hello_world_forms.cpp:

```c++
#include <xtd/xtd>

using namespace xtd::forms;

int main() {
  button button;
  button.text("Click me");
  button.location({10, 10});
  button.click += [] {
    message_box::show("Hello, World!");
  };
  
  form form;
  form.text("Hello World Form");
  form.controls().push_back(button);
  
  application::run(form);
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(hello_world_forms)
find_package(xtd REQUIRED)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE hello_world_forms.cpp)
target_link_libraries(${PROJECT_NAME} xtd)
```

## Unit tests

hello_world_tunit.cpp:

```c++
#include <xtd/xtd>
#include <string>

using namespace std;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(hello_world_test) {
  public:
    void test_method_(create_string_from_literal) {
      string s = "Hello, World!";
      valid::are_equal(13, s.size());
      assert::are_equal("Hello, World!", s);
    }
    
    void test_method_(create_string_from_chars) {
      string s = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
      valid::are_equal(13, s.size());
      string_assert::starts_with("Hello,", s);
      string_assert::ends_with(" World!", s);
    }
  };
}

int main() {
  return console_unit_test().run();
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.3)

project(hello_world_tunit)
find_package(xtd REQUIRED)
add_executable(${PROJECT_NAME} hello_world_tunit.cpp)
target_link_libraries(${PROJECT_NAME} xtd)
```

For more examples see [examples](examples/README.md)

# Download and install

Before running examples you must download and install xtd. To download and install it read Downloads file.

