#include <iomanip>
#include <sstream>

struct Time{
    int hour{5};
    int minute{0};
    int second{0};

    std::string const to_string();
};

std::string const Time::to_string(){
    std::ostringstream out;
    out << std::internal << std::setfill('0') << std::setw(2) << hour << '\n';
    return out.str();
}
