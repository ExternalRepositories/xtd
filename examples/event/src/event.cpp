#include <xtd/xtd.delegates>
#include <iostream>
#include <string>

class control {
public:
  control() = default;

  const std::string& text() const {return text_;}
  void text(const std::string& text) {
    if (text_ != text) {
      text_ = text;
      on_text_changed(xtd::event_args::empty);
    }
  }
  
  xtd::event<control, xtd::event_handler<control&>> text_changed;

protected:
  void on_text_changed(const xtd::event_args& e) {text_changed(*this, e);}
  
private:
  std::string text_;
};

class button : public control {
public:
  button() = default;

  xtd::event<button, xtd::event_handler<control&>> click;
  
  void perform_click() {on_click(xtd::event_args::empty);}
  
protected:
  virtual void on_click(const xtd::event_args& e) {click(*this, e);}
};

int main() {
  button button1;
  
  button1.text_changed += [](control& sender, const xtd::event_args& e)  {
    std::cout << "text_changed [text=" << sender.text() << "]" << std::endl;
  };
  
  button1.click += []  {
    std::cout << "click on button1" << std::endl;
  };
  
  button1.text("button1");
  
  // click simulation
  button1.perform_click();
}
