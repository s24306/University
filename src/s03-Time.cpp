#include "../include/s24306/Time.h"
#include <cstdint>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

namespace s24306 {
    Time::Time(short h, short m, short s) :
            hour{h}, minute{m}, second{s} {}

    void Time::next_hour(){
        hour++;
        if(hour > 23)
            hour = 0;
    }

    void Time::next_minute(){
        minute++;
        if(minute > 59) {
            minute = 0;
            next_hour();
        }
    }

    void Time::next_second(){
        second++;
        if(second > 59) {
            second = 0;
            next_minute();
        }
    }

    auto Time::to_string() const -> std::string{
        std::ostringstream out {};

        out << std::setfill('0') << std::setw(2) << hour << ":"
            << std::setfill('0') << std::setw(2) << minute << ":"
            << std::setfill('0') << std::setw(2) << second;

        return out.str();
    }

    std::string const Time::to_string(Time::Time_of_day time_of_day){
        switch(time_of_day) {
            case Time_of_day::Morning:
                return "Morning";
            case Time_of_day::Day:
                return "Day";
            case  Time_of_day::Evening:
                return "Evening";
            case Time_of_day::Night:
                return "Night";
            default:
                throw "UwU you bwoke something >w<";
        };
    }

    Time::Time_of_day const Time::time_of_day(){
        if(hour >= 6 && hour <= 11)
            return Time::Time_of_day::Morning;
        else if(hour >= 12 && hour <= 18)
            return Time::Time_of_day::Day;
        else if(hour >= 19 && hour <= 22)
            return Time::Time_of_day::Evening;
        else
            return Time::Time_of_day::Night;
    }

    std::uint64_t const Time::count_seconds(){
        std::uint64_t seconds_since_midnight = 0;
        seconds_since_midnight += hour * 60 * 60;
        seconds_since_midnight += minute * 60;
        seconds_since_midnight += second;
        return seconds_since_midnight;
    }

    std::uint64_t const Time::count_minutes(){
        std::uint64_t minutes_since_midnight = 0;
        minutes_since_midnight += hour * 60;
        minutes_since_midnight += minute;
        return minutes_since_midnight;
    }

    Time const Time::time_to_midnight(){
        Time two_minutes_to_midnight; //:^)
        if(second > 0)
            two_minutes_to_midnight.second = 60 - second;
        else
            two_minutes_to_midnight.second = 59;

        if(minute > 0)
            two_minutes_to_midnight.minute = 59 - minute;
        else
            two_minutes_to_midnight.minute = 59;

        if(hour < 24)
            two_minutes_to_midnight.hour = 23 - hour;
        else
            two_minutes_to_midnight.hour = 24 - hour;

        return two_minutes_to_midnight;
    }

    Time const Time::operator+ (Time const& plus_operator){
        short hh = hour;
        short mm = minute;
        short ss = second;
        ss += plus_operator.second;
        while(ss > 59){
            ss -= 60;
                mm++;
        }
        mm += plus_operator.minute;
        while(mm > 59) {
            mm -= 60;
            hh++;
        }
        hh += plus_operator.hour;
        while(hh > 23)
            hh -= 24;

        return Time(hh, mm, ss);
    }

    Time const Time::operator- (Time const& minus_operator){
        short hh = hour;
        short mm = minute;
        short ss = second;
        ss -= minus_operator.second;
        while(ss < 0) {
            ss += 60;
            mm--;
            if (-60 < ss < 0){
                ss = 60 - ss;
            }
        }
        mm -= minus_operator.minute;
        while(mm < 0) {
            mm += 60;
            hh--;
            if (-60 < mm < 0){
                mm = 60 - mm;
            }
        }
        hh -= minus_operator.hour;
        while(hh < 0) {
            hh += 24;
            if (-24 < hh < 0){
                hh = 24 - hh;
            }
        }

        return Time(hh, mm, ss);
    }

    bool const Time::operator< (Time const& less_operator){
        if(hour < less_operator.hour)
            return true;
        if(hour != less_operator.hour)
            return false;
        if(minute < less_operator.minute)
            return true;
        if(minute != less_operator.minute)
            return false;
        if(second < less_operator.second)
            return true;
        if(second != less_operator.minute)
            return false;
        return false;
    }

    bool const Time::operator> (Time const& more_operator){
        if(hour > more_operator.hour)
            return true;
        if(hour != more_operator.hour)
            return false;
        if(minute > more_operator.minute)
            return true;
        if(minute != more_operator.minute)
            return false;
        if(second > more_operator.second)
            return true;
        if(second != more_operator.minute)
            return false;
        return false;
    }

    bool const Time::operator== (Time const& equal_operator){
        return (hour == equal_operator.hour && minute == equal_operator.minute && second == equal_operator.second);
    }

    bool const Time::operator!= (Time const& not_equal_operator){
        return !(hour == not_equal_operator.hour
        && minute == not_equal_operator.minute
        && second == not_equal_operator.second);
    }
}

auto main() -> int {
    auto time = s24306::Time(23, 59, 59);

    std::cout << time.to_string() << "\n";

    time.next_hour();

    std::cout << time.to_string() << "\n";

    time.next_minute();

    std::cout << time.to_string() << "\n";

    time.next_second();

    std::cout << time.to_string() << "\n";

    std::cout << time.to_string(time.time_of_day()) << "\n";

    std::cout << "seconds since midnight: " << time.count_seconds() << "\n";

    std::cout << "minutes since midnight: " << time.count_minutes() << "\n";

    std::cout << "Iron Maiden: " << time.time_to_midnight().to_string() << "\n";

    s24306::Time test_time1 {11, 11, 11};
    s24306::Time test_time2 {22, 22, 22};

    std::cout << "Time 1: " << test_time1.to_string() << "\n";
    std::cout << "Time 2: " << test_time2.to_string() << "\n";

    std::cout << "Adding Time 2 to Time 1: " << (test_time1 + test_time2).to_string() << "\n";
    std::cout << "Subtracting Time 2 from Time 1: " << (test_time1 - test_time2).to_string() << "\n";
    std::cout << "Time 1 greater than Time 2: " << std::boolalpha << (test_time1 > test_time2) << "\n";
    std::cout << "Time 1 lesser than Time 2: " << (test_time1 < test_time2) << "\n";
    std::cout << "Time 1 equal Time 2: " << (test_time1 == test_time2) << "\n";
    std::cout << "Time 1 not equal Time 2: " << (test_time1 != test_time2) << "\n";

    return 0;
}
