#include "../include/xtd/environment"

#if defined(_WIN32)
__declspec(dllimport) extern char** environ;
__declspec(dllimport) extern int __argc;
__declspec(dllimport) extern char** __argv;
#else
extern char** environ;
extern int __argc;
extern char** __argv;
#endif

std::vector<std::string> xtd::environment::get_command_line_args() noexcept {
  return {__argv, __argv + __argc};
}

std::map<std::string, std::string>& xtd::environment::get_environment_variables(environment_variable_target target) {
  if (target == environment_variable_target::process) {
    static std::map<std::string, std::string> envs;
    if (envs.size() == 0) {
      for (size_t index = 0; environ[index] != nullptr; index++) {
        std::vector<std::string> key_value = xtd::strings::split(environ[index], {'='});
        if (key_value.size() == 2)
          envs[key_value[0]] = key_value[1];
      }
    }
    return envs;
  }
  
  if(target == environment_variable_target::user || target == environment_variable_target::machine) {
    static std::map<std::string, std::string> envs;
    envs.clear();
    //microsoft::win32::registry_key key = target == environment_variable_target::user ? microsoft::win32::registry::current_user().create_sub_key("Environment") : microsoft::win32::registry::local_machine().create_sub_key("System").create_sub_key("CurrentControlSet").create_sub_key("Control").create_sub_key("Session Manager").create_sub_key("Environment");
    //for (auto name : key.get_value_names())
    //  envs[name] = key.get_value(name).to_string();
    return envs;
  }
  
  throw std::invalid_argument("invalid environment_variable_target value");
}

