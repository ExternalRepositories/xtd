#include <xtd/io/end_of_stream_exception.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_end_of_stream_exception) {
  public:
    void test_method_(default_creator) {
      end_of_stream_exception e;
      assert::are_equal_(std::system_category(), e.error().category());
      assert::is_false_(e.inner_exception().has_value());
      assert::is_empty(e.file_path());
      assert::is_empty(e.help_link());
      assert::are_equal_(0, e.error().value());
      assert::are_equal_(0U, e.line_numer());
      assert::is_empty(e.member_name());
      assert::are_equal_("Attempted to read past the end of the stream.", e.message());
      assert::are_equal_("xtd::io::end_of_stream_exception", e.name());
      assert::is_empty(e.stack_trace());
      assert::are_equal_("xtd::io::end_of_stream_exception : Attempted to read past the end of the stream.", e.to_string());
      assert::are_equal_("Attempted to read past the end of the stream.", e.what());
    }

    void test_method_(default_creator_with_caller_info) {
      auto info = caller_info_;
      end_of_stream_exception e(info);
      assert::are_equal_(std::system_category(), e.error().category());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(info.file_path(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::are_equal_(0, e.error().value());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Attempted to read past the end of the stream.", e.message());
      assert::are_equal_("xtd::io::end_of_stream_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::io::end_of_stream_exception : Attempted to read past the end of the stream.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Attempted to read past the end of the stream.", e.what());
    }
    
    void test_method_(creator_with_empty_message) {
      end_of_stream_exception e("");
      assert::are_equal_(0, e.error().value());
      assert::are_equal_(std::system_category(), e.error().category());
      assert::is_empty(e.file_path());
      assert::is_empty(e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(0U, e.line_numer());
      assert::is_empty(e.member_name());
      assert::are_equal_("", e.message());
      assert::are_equal_("xtd::io::end_of_stream_exception", e.name());
      assert::is_empty(e.stack_trace());
      assert::are_equal_("xtd::io::end_of_stream_exception", e.to_string());
      assert::are_equal_("xtd::io::end_of_stream_exception", e.what());
    }
    
    void test_method_(creator_with_message_empty_and_caller_info) {
      auto info = caller_info_;
      end_of_stream_exception e("", info);
      assert::are_equal_(info.file_path(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::are_equal_(0, e.error().value());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(std::system_category(), e.error().category());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("", e.message());
      assert::are_equal_("xtd::io::end_of_stream_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::io::end_of_stream_exception\n" + info.to_trace(), e.to_string());
      assert::are_equal_("xtd::io::end_of_stream_exception", e.what());
    }

    void test_method_(creator_with_message) {
      end_of_stream_exception e("Test excpetion message.");
      assert::are_equal_(0, e.error().value());
      assert::are_equal_(std::system_category(), e.error().category());
      assert::is_empty(e.file_path());
      assert::is_empty(e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(0U, e.line_numer());
      assert::is_empty(e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::io::end_of_stream_exception", e.name());
      assert::is_empty(e.stack_trace());
      assert::are_equal_("xtd::io::end_of_stream_exception : Test excpetion message.", e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }

    void test_method_(creator_with_message_and_caller_info) {
      auto info = caller_info_;
      end_of_stream_exception e("Test excpetion message.", info);
      assert::are_equal_(info.file_path(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::are_equal_(0, e.error().value());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(std::system_category(), e.error().category());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::io::end_of_stream_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::io::end_of_stream_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }

    void test_method_(creator_with_message_error_and_caller_info) {
      auto info = caller_info_;
      end_of_stream_exception e("Test excpetion message.", std::error_code(EBUSY, std::generic_category()), info);
      assert::are_equal_(EBUSY, e.error().value());
      assert::are_equal_(std::generic_category(), e.error().category());
      assert::are_equal_(info.file_path(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::io::end_of_stream_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::io::end_of_stream_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }

    void test_method_(creator_with_message_help_link_and_caller_info) {
      auto info = caller_info_;
      end_of_stream_exception e("Test excpetion message.", "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal_(0, e.error().value());
      assert::are_equal_(std::system_category(), e.error().category());
      assert::are_equal_(info.file_path(), e.file_path());
      assert::are_equal_("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::io::end_of_stream_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::io::end_of_stream_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }

    void test_method_(creator_with_message_error_help_link_and_caller_info) {
      auto info = caller_info_;
      end_of_stream_exception e("Test excpetion message.", std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal_(EBUSY, e.error().value());
      assert::are_equal_(std::generic_category(), e.error().category());
      assert::are_equal_(info.file_path(), e.file_path());
      assert::are_equal_("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::io::end_of_stream_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::io::end_of_stream_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }

    void test_method_(creator_with_message_and_inner_exception) {
      system_exception inner_exception;
      end_of_stream_exception e("Test excpetion message.", inner_exception);
      assert::are_equal_(0, e.error().value());
      assert::are_equal_(std::system_category(), e.error().category());
      assert::is_empty(e.file_path());
      assert::is_empty(e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(0U, e.line_numer());
      assert::is_empty(e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::io::end_of_stream_exception", e.name());
      assert::is_empty(e.stack_trace());
      assert::are_equal_("xtd::io::end_of_stream_exception : Test excpetion message.", e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_inner_exception_and_caller_info) {
      system_exception inner_exception;
      auto info = caller_info_;
      end_of_stream_exception e("Test excpetion message.", inner_exception, info);
      assert::are_equal_(info.file_path(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::are_equal_(0, e.error().value());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(std::system_category(), e.error().category());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::io::end_of_stream_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::io::end_of_stream_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_inner_exception_error_and_caller_info) {
      system_exception inner_exception;
      auto info = caller_info_;
      end_of_stream_exception e("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), info);
      assert::are_equal_(EBUSY, e.error().value());
      assert::are_equal_(std::generic_category(), e.error().category());
      assert::are_equal_(info.file_path(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::io::end_of_stream_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::io::end_of_stream_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_inner_exception_help_link_and_caller_info) {
      system_exception inner_exception;
      auto info = caller_info_;
      end_of_stream_exception e("Test excpetion message.", inner_exception, "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal_(0, e.error().value());
      assert::are_equal_(std::system_category(), e.error().category());
      assert::are_equal_(info.file_path(), e.file_path());
      assert::are_equal_("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::io::end_of_stream_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::io::end_of_stream_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_inner_exception_error_help_link_and_caller_info) {
      system_exception inner_exception;
      auto info = caller_info_;
      end_of_stream_exception e("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal_(EBUSY, e.error().value());
      assert::are_equal_(std::generic_category(), e.error().category());
      assert::are_equal_(info.file_path(), e.file_path());
      assert::are_equal_("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::io::end_of_stream_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::io::end_of_stream_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(copy_constructor) {
      system_exception inner_exception;
      auto info = caller_info_;
      end_of_stream_exception e = end_of_stream_exception("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal_(EBUSY, e.error().value());
      assert::are_equal_(std::generic_category(), e.error().category());
      assert::are_equal_(info.file_path(), e.file_path());
      assert::are_equal_("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::io::end_of_stream_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::io::end_of_stream_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }

    void test_method_(copy_operator) {
      system_exception inner_exception;
      auto info = caller_info_;
      end_of_stream_exception e;
      e = end_of_stream_exception("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal_(EBUSY, e.error().value());
      assert::are_equal_(std::generic_category(), e.error().category());
      assert::are_equal_(info.file_path(), e.file_path());
      assert::are_equal_("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::io::end_of_stream_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::io::end_of_stream_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
  };
}
