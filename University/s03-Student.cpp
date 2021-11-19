#include <iostream>
#include <string>
#include "student.h"

int main(){
    Student me{"Dawid", "Hoffmeister", 24306, 1, 5.0};
    std::cout << me.to_string();
    
    return 0;
}
