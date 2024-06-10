/* 
Júlio Shoji Zotovici Kobayashi
main archive
June, 2024
*/
#include "controller.hpp"
#include <iostream>
#include <memory>

int main(){
    try {
        unique_ptr<controller> SysControl(new controller()); 
    }
    catch(exception& except){
        cerr << "An error ocurred: " << except.what();
    };
    return 0;
};