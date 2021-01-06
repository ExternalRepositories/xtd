# css_writer

Shows how to use [xtd::html::css:writer](../../../../src/xtd.core/include/xtd/html/css/writer.h) class.

## Sources

[src/css_parser.cpp](src/css_writer.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
String stream :
---------------
.user_box {
  background: #4080FA;
  display: none;
  filter: alpha(opacity=40);
  height: 100%;
  left: 300;
  opacity: 0.4;
  position: fixed;
  top: 200;
  width: 100%;
  z-index: 100;
}
```
