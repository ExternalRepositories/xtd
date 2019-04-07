#include <xtd/strings>
#include <xtd/tunit>

#include <time.h>
#if defined (WIN32)
static time_t __make_local_date_time(struct tm *tm) noexcept {return mktime(tm);}
static time_t __make_utc_date_time(struct tm *tm) noexcept {return _mkgmtime(tm);}
#else
static time_t __make_local_date_time(struct tm *tm) noexcept {return mktime(tm);}
static time_t __make_utc_date_time(struct tm *tm) noexcept {return timegm(tm);}
#endif

using namespace std;
using namespace std::string_literals;
using namespace xtd;
using namespace xtd::tunit;

namespace {
  static std::tm to_local_time(time_t time) noexcept {return *std::localtime(&time);}
  //static std::tm to_local_time(const std::chrono::system_clock::time_point& time) noexcept {return to_local_time(std::chrono::system_clock::to_time_t(time));}
  static std::tm to_local_time(std::tm time) noexcept {
    if (xtd::to_string(time, "Z") != "" && xtd::to_string(time, "Z") == "UTC") return to_local_time(__make_utc_date_time(&time));
    return to_local_time(__make_local_date_time(&time));
  }
  
  static std::tm to_universal_time(time_t time) noexcept {return *std::gmtime(&time);}
  static std::tm to_universal_time(const std::chrono::system_clock::time_point& time) noexcept {return to_universal_time(std::chrono::system_clock::to_time_t(time));}
  static std::tm to_universal_time(std::tm time) noexcept {
    if (xtd::to_string(time, "Z") != "" && xtd::to_string(time, "Z") == "UTC") return to_universal_time(__make_local_date_time(&time));
    return to_universal_time(__make_utc_date_time(&time));
  }

  std::tm make_time(int year, int month, int day, int hour, int minute, int second, bool utc = false) {
	  std::tm time;
	  time.tm_year = year - 1900;
	  time.tm_mon = month - 1;
	  time.tm_mday = day;
	  time.tm_hour = hour;
	  time.tm_min = minute;
	  time.tm_sec = second;
	  time.tm_wday = 0;
	  time.tm_yday = 0;
	  time.tm_isdst = -1;
#if !defined (WIN32)
	  time.tm_gmtoff = 0;
	  time.tm_zone = nullptr;
#endif

	  return utc ? to_universal_time(time) : to_local_time(time);
  }

  std::tm make_time(int year, int month, int day, bool utc=false) {return make_time(year, month, day, 0, 0, 0, utc); }
   
  template<typename Time>
  Time make_time(int year, int month, int day, int hour, int minute, int second, bool utc=false);
  
  template<>
  std::tm make_time<std::tm>(int year, int month, int day, int hour, int minute, int second, bool utc) {return make_time(year, month, day, hour, minute, second, utc);}
  
  template<>
  std::chrono::system_clock::time_point make_time<std::chrono::system_clock::time_point>(int year, int month, int day, int hour, int minute, int second, bool utc) {
    std::tm time = make_time(year, month, day, hour, minute, second, utc);
    return std::chrono::system_clock::from_time_t(mktime(&time));
  }
  
  template<typename Time>
  Time make_time(int year, int month, int day, bool utc=false);
  
  template<>
  std::tm make_time<std::tm>(int year, int month, int day, bool utc) {return make_time(year, month, day, utc);}
  
  template<>
  std::chrono::system_clock::time_point make_time<std::chrono::system_clock::time_point>(int year, int month, int day, bool utc) {
    std::tm time = make_time(year, month, day, utc);
    return std::chrono::system_clock::from_time_t(mktime(&time));
  }
}

namespace unit_tests {
  template <typename Value>
  class test_wstring_date_time_format;
  
  test_class_attribute<test_wstring_date_time_format<std::tm>> test_wstring_date_time_format_class_std_tm_attr {"test_wstring_date_time_format<std::tm>"};
  test_class_attribute<test_wstring_date_time_format<std::chrono::system_clock::time_point>> test_wstring_date_time_format_class_std_chrono_system_clock_time_point_attr {"test_wstring_date_time_format<std::chrono::system_clock::time_point>"};

  template<typename Value>
  class test_wstring_date_time_format : public test_class {
  public:
    static void class_initialize_(class_initialize) {
      std::locale::global(std::locale("en_US.UTF-8"));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_default_argument) {
#if __APPLE__
      assert::are_equal(L"Wed Jan  2 03:04:05 2019", strings::format(L"{0}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"1/2/2019 3:04:05 AM", strings::format(L"{0}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"Wed 02 Jan 2019 03:04:05 AM", strings::format(L"{0}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#endif
    }
    
    void test_method_(format_date_time_local_with_left_alignment) {
#if __APPLE__
      assert::are_equal(L"           Wed Jan  2 03:04:05 2019", strings::format(L"{0, 35}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"                1/2/2019 3:04:05 AM", strings::format(L"{0, 35}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"    Wed 02 Jan 2019 03:04:05 AM", strings::format(L"{0, 35}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#endif
    }
    
    void test_method_(format_date_time_local_with_left_alignment_wth_plus) {
#if __APPLE__
      assert::are_equal(L"           Wed Jan  2 03:04:05 2019", strings::format(L"{0,+35}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"                1/2/2019 3:04:05 AM", strings::format(L"{0,+35}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"    Wed 02 Jan 2019 03:04:05 AM", strings::format(L"{0,+35}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#endif
    }

    void test_method_(format_date_time_local_with_left_to_zero) {
#if __APPLE__
      assert::are_equal(L"Wed Jan  2 03:04:05 2019", strings::format(L"{0,0}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"1/2/2019 3:04:05 AM", strings::format(L"{0,0}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"Wed 02 Jan 2019 03:04:05 AM", strings::format(L"{0,0}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#endif
    }
    
    void test_method_(format_date_time_local_with_right_alignment) {
#if __APPLE__
      assert::are_equal(L"Wed Jan  2 03:04:05 2019           ", strings::format(L"{0,-35}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"1/2/2019 3:04:05 AM                ", strings::format(L"{0,-35}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"Wed 02 Jan 2019 03:04:05 AM", strings::format(L"{0,-35}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#endif
    }

    void test_method_(format_date_time_local_with_right_alignment_to_zero) {
#if __APPLE__
      assert::are_equal(L"Wed Jan  2 03:04:05 2019", strings::format(L"{0,-0}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"1/2/2019 3:04:05 AM", strings::format(L"{0,-0}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"Wed 02 Jan 2019 03:04:05 AM", strings::format(L"{0,-0}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#endif
    }
    
    void test_method_(format_date_time_local_with_alignment_empty) {
#if __APPLE__
      assert::are_equal(L"Wed Jan  2 03:04:05 2019", strings::format(L"{0,}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"1/2/2019 3:04:05 AM", strings::format(L"{0,}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"Wed 02 Jan 2019 03:04:05 AM", strings::format(L"{0,}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#endif
    }
    
    void test_method_(format_date_time_local_with_alignment_invalid) {
      assert::throws<std::invalid_argument>([]{strings::format(L"{0,a}", make_time<Value>(2019, 1, 2, 3, 4, 5));});
    }

    void test_method_(format_date_time_local_with_std_tm_with_date_argument_and_zero_fill) {
      assert::are_equal(L"01/02/2019", strings::format(L"{0:d}", make_time<Value>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_date_argument) {
      assert::are_equal(L"1/02/2019", strings::format(L"{0:D}", make_time<Value>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_utc_with_std_tm_with_alternative_full_date_time_argument) {
#if __APPLE__
      assert::are_equal(L"Wed Jan  2 03:04:05 2019", strings::format(L"{0:f}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"1/2/2019 3:04:05 AM", strings::format(L"{0:f}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"Wed 02 Jan 2019 03:04:05 AM", strings::format(L"{0:f}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#endif
    }
    
    void test_method_(format_date_time_utc_with_std_tm_with_full_date_time_argument) {
#if __APPLE__
      assert::are_equal(L"Wed Jan  2 03:04:05 2019", strings::format(L"{0:F}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"1/2/2019 3:04:05 AM", strings::format(L"{0:F}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"Wed 02 Jan 2019 03:04:05 AM", strings::format(L"{0:F}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#endif
    }

    void test_method_(format_date_time_local_with_std_tm_with_alternative_general_argument) {
#if __APPLE__
      assert::are_equal(L"Wed Jan  2 03:04:05 2019", strings::format(L"{0:g}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"1/2/2019 3:04:05 AM", strings::format(L"{0:g}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"Wed 02 Jan 2019 03:04:05 AM", strings::format(L"{0:g}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#endif
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_general_argument) {
#if __APPLE__
      assert::are_equal(L"Wed Jan  2 03:04:05 2019", strings::format(L"{0:G}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#elif WIN32
      assert::are_equal(L"1/2/2019 3:04:05 AM", strings::format(L"{0:G}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#else
      string_assert::starts_with(L"Wed 02 Jan 2019 03:04:05 AM", strings::format(L"{0:G}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
#endif
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_brief_weekday_name_argument) {
      assert::are_equal(L"Wed", strings::format(L"{0:h}", make_time<Value>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_weekday_name_argument) {
      assert::are_equal(L"Wednesday", strings::format(L"{0:H}", make_time<Value>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_day_argument_and_zero_fill) {
      assert::are_equal(L"02", strings::format(L"{0:i}", make_time<Value>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_day_argument) {
      assert::are_equal(L"2", strings::format(L"{0:I}", make_time<Value>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_brief_month_name_argument) {
      assert::are_equal(L"Jan", strings::format(L"{0:j}", make_time<Value>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_month_name_argument) {
      assert::are_equal(L"January", strings::format(L"{0:J}", make_time<Value>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_month_argument_and_zero_fill) {
      assert::are_equal(L"01", strings::format(L"{0:k}", make_time<Value>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_month_argument) {
      assert::are_equal(L"1", strings::format(L"{0:K}", make_time<Value>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_year_on_two_digits_argument) {
      assert::are_equal(L"19", strings::format(L"{0:l}", make_time<Value>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_year_argument) {
      assert::are_equal(L"2019", strings::format(L"{0:L}", make_time<Value>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_month_and_day_argument) {
      assert::are_equal(L"January 2", strings::format(L"{0:M}", make_time<Value>(2019, 1, 2)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_natural_date_argument) {
      assert::are_equal(L"Wednesday, 2 January 2019", strings::format(L"{0:n}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_natural_date_time_argument) {
      assert::are_equal(L"Wednesday, 2 January 2019 3:04:05", strings::format(L"{0:N}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_ordinary_date_argument) {
      assert::are_equal(L"2 January 2019", strings::format(L"{0:O}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_sortable_argument) {
      assert::are_equal(L"2019-01-02T03:04:05", strings::format(L"{0:s}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_time_argument_and_zero_fill) {
      assert::are_equal(L"03:04:05", strings::format(L"{0:t}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_time_argument) {
      assert::are_equal(L"3:04:05", strings::format(L"{0:T}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_alternative_universale_argument_and_zero_fill) {
      assert::are_equal(L"2019-01-02 03:04:05", strings::format(L"{0:u}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_universale_argument_and_zero_fill) {
      assert::are_equal(L"Wednesday, 2 January 2019 3:04:05", strings::format(L"{0:U}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_time_without_seconds_argument_and_zero_fill) {
      assert::are_equal(L"03:04", strings::format(L"{0:v}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_time_without_seconds_argument) {
      assert::are_equal(L"3:04", strings::format(L"{0:V}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_month_and_year_on_two_digits_argument) {
      assert::are_equal(L"January 19", strings::format(L"{0:y}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_month_and_year_argument) {
      assert::are_equal(L"January 2019", strings::format(L"{0:Y}", make_time<Value>(2019, 1, 2, 3, 4, 5)));
    }
    
    void test_method_(format_date_time_local_with_std_tm_with_time_zone_argument) {
#if __APPLE__
      assert::are_equal(L"UTC", strings::format(L"{0:Z}", to_universal_time(make_time<Value>(2019, 1, 2, 3, 4, 5))));
#elif WIN32
      assert::are_equal(L"Coordinated Universal Time", strings::format(L"{0:Z}", to_universal_time(make_time<Value>(2019, 1, 2, 3, 4, 5))));
#else
      assert::are_equal(L"GMT", strings::format(L"{0:Z}", to_universal_time(make_time<Value>(2019, 1, 2, 3, 4, 5))));
#endif
    }
  };
}
