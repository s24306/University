#include <iostream>
#include <string>
#include "student.h"

int main(){
    Student me{};
    std::cout << me.to_string();
    
    return 0;
}
