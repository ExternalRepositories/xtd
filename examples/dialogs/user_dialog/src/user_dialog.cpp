#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class user_input_dialog : public form {
public:
  user_input_dialog() {
    client_size({200, 80});
    start_position(form_start_position::center_parent);
    text("Input dialog");
    controls().push_back_range({input, button_ok, button_cancel});

    input.location({10, 10});
    input.width(180);

    button_ok.dialog_result(forms::dialog_result::ok);
    button_ok.location({10, 50});
    button_ok.text("OK");

    button_cancel.dialog_result(forms::dialog_result::cancel);
    button_cancel.location({110, 50});
    button_cancel.text("Cancel");
  }
  
  virtual std::string input_text() const {return input.text();}
  virtual user_input_dialog& input_text(const std::string& input_text) {
    input.text(input_text);
    return *this;
  }

private:
  text_box input;
  button button_ok;
  button button_cancel;
};

class form1 : public form {
public:
  form1() {
    controls().push_back_range({button_dialog, input_text});
    start_position(form_start_position::center_screen);
    size({800, 450});
    text("User dialog exemple");
    
    input_text.auto_size(true);
    input_text.location({10, 50});
    input_text.text("User input text");
    
    button_dialog.location({10, 10});
    button_dialog.text("Dialog...");
    button_dialog.click += [this] {
      user_input_dialog dialog;
      dialog.input_text(input_text.text());
      if (dialog.show_dialog() == forms::dialog_result::ok)
        input_text.text(dialog.input_text());
    };
  }
  
private:
  button button_dialog;
  label input_text;
};

int main() {
  application::run(form1());
}
