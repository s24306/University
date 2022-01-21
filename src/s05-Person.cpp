#include <iostream>
#include "../include/s24306/Person.h"


int main(){
    Mr GioGio("Giorno" , "Giovanna" );
    Mrs JoJo("Jolyne" , "KuJo" );
    Queen valleyGurl("Yasss", "totes");
    King korwin("Ozjasz", "Koran-Mekka");

    Hello hello;
    Good_evening good_evening;
    Farewell farewell;

    std::cout << who_is_it(GioGio) << std::endl;
    std::cout << who_is_it(JoJo) << std::endl;
    std::cout << who_is_it(valleyGurl) << std::endl;
    std::cout << who_is_it(korwin) << std::endl;
    std::cout << hello.greet(GioGio) << std::endl;
    std::cout << good_evening.greet(JoJo) << std::endl;
    std::cout << farewell.greet(korwin) << std::endl;

    return 0;
}
