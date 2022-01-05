#ifndef S1234_TIME_H
#define S1234_TIME_H

#include <cstdint>
#include <string>

namespace s24306 {

    struct Time {
        short hour = 0;
        short minute = 0;
        short second = 0;
        enum class Time_of_day {
            Morning,
            Day,
            Evening,
            Night,
        };

        Time() = default;
        Time(short, short, short);

        void next_hour();
        void next_minute();
        void next_second();
        auto to_string() const -> std::string;
        std::string const to_string(Time_of_day);
        Time_of_day const time_of_day();
        std::uint64_t const count_seconds();
        std::uint64_t const count_minutes();
        Time const time_to_midnight();

        Time const operator+  (Time const&);
        Time const operator-  (Time const&);
        bool const operator<  (Time const&);
        bool const operator>  (Time const&);
        bool const operator== (Time const&);
        bool const operator!= (Time const&);
    };

}

#endif // S1234_TIME_H