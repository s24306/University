#include "iostream"

struct this_test{
    std::string that;
    this_test(std::string there){
        that = there;
    }

    void const this_function(){
        std::cout<<"this value: "<< this -> that <<"\n";
    }
};

int main(){
    this_test that("meow meow meow 13% meow meow meow 52%");
    that.this_function();

    std::cout<<"UwU what's this: "<< &that.that <<"\n";
}
