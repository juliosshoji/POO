#include "controller.hpp"
#include <iostream>
#include <memory>

int main(){
    try {
        int code = 11;
        unique_ptr<controller> SysControl(new controller(code)); 
    }
    catch(exception& except){
        cerr << "An error ocurred: " << except.what();
    };
};