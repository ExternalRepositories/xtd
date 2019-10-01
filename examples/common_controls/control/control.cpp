#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Control example");

      control1.parent(*this);
      control1.cursor(cursors::hand());
      control1.back_color(color::spring_green);
      control1.location({50, 50});
      control1.size({100, 50});
      control1.click += [this](const control& sender, const event_args& e) {
        control1.back_color(control1.back_color() == color::spring_green ? color::orange_red : color::spring_green);
      };
    }
    
  private:
    control control1;
  };
}

int main() {
  application::run(examples::form1());
}
