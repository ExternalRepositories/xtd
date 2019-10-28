#include <iostream>
#include <xtd/xtd.io>
#include <xtd/xtd.drawing>
#include "logo.xpm"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

void to_ppm(const xtd::ustring& filename, const xtd::drawing::bitmap& bitmap, const color& transparent_color = color::white) {
  std::vector<xtd::ustring> lines;
  lines.push_back("P3");
  lines.push_back("# Ppm.ppm");
  lines.push_back(xtd::strings::format("{} {}", bitmap.width(), bitmap.height()));
  lines.push_back("255");
  lines.push_back("");
  for (int y = 0; y < bitmap.height(); y++) {
    for (int x = 0; x < bitmap.width(); x++)
      if (bitmap.get_pixel(x, y).a() == 0)
        lines.push_back(strings::format("{, 3} {, 3} {, 3}", transparent_color.r(), transparent_color.g(), transparent_color.b()));
      else
        lines.push_back(strings::format("{, 3} {, 3} {, 3}", bitmap.get_pixel(x, y).r(), bitmap.get_pixel(x, y).g(), bitmap.get_pixel(x, y).b()));
    lines.push_back("");
  }
  xtd::io::file::write_all_lines(filename, lines);
}

void to_ppm(const xtd::ustring& filename, const color& transparent_color = color::white) {
  to_ppm(xtd::io::path::combine(xtd::io::path::get_directory_name(filename), xtd::strings::format("{}{}", xtd::io::path::get_file_name_without_extension(filename), ".ppm")), bitmap(filename), transparent_color);
}

int main() {
  //to_ppm("/Users/yves/Desktop/test.png");
  bitmap img = bitmap(logo_xpm);
  //to_ppm("/Users/yves/Desktop/logo.ppm", img, color::magenta);
  cout << format("flags = {}", static_cast<imaging::image_flags>(img.flags())) << endl;
  //cout << format("frmae dimension list = {}", strings::join(", ", img.pixel_format())) << endl;
  cout << format("handle = 0x{:X}", img.handle()) << endl;
  cout << format("horizontal resolution = {}", img.horizontal_resolution()) << endl;
  cout << format("physical dimension = {}", img.physical_dimension()) << endl;
  cout << format("raw format = {}", img.raw_format()) << endl;
  cout << format("vertcal resolution = {}", img.vertical_resolution()) << endl;
  cout << format("size = {}", img.size()) << endl;
}
