#include <iostream>
#include "Time.h"
#include <string>

int main(){
    Time czas{1, 1, 1};
    std::cout << czas.to_string();

    return 0;
}
