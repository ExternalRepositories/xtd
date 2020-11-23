#include <filesystem>
#include <xtd/xtd>

using namespace std::filesystem;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    if (environment::os_version().is_windows_platform()) file::write_all_text(temp_directory_path()/"say.cmd", "@echo Set Speaker=CreateObject(\"sapi.spvoice\") > %TEMP%\\say.vbs\n@echo Speaker.Speak %* >> %TEMP%\\say.vbs\n@%TEMP%\\say.vbs");
    else if (environment::os_version().is_macos_platform()) file::write_all_text(temp_directory_path()/"say.cmd", "say $*");
    else file::write_all_text(temp_directory_path()/"say.cmd", "spd-say $*");
    permissions(temp_directory_path()/"say.cmd", perms::owner_all);
    
    text("Hello world (say)");
    
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Say...");
    button1.click += [&] {
      process::start(process_start_info().file_name(temp_directory_path()/"say.cmd").arguments("\"Hello, World!\"").window_style(process_window_style::hidden));
    };
  }
  
private:
  button button1;
};

int main() {
  application::run(form1());
}
