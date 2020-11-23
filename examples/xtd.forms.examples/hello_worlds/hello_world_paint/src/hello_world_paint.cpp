#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class main_form : public form {
  public:
    main_form() {
      text("Hello world (paint)");
      client_size({300, 300});

      paint += [&](control& sender, paint_event_args& e) {
        e.graphics().draw_string("Hello World!", {font(), 32, font_style::bold | font_style::italic}, brushes::blue(), e.clip_rectangle(), string_format().alignment(string_alignment::center).line_alignment(string_alignment::center));
      };
    }
  };
}

int main() {
  application::run(examples::main_form());
}
