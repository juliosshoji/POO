/* 
Júlio Shoji Zotovici Kobayashi
Class operation
June, 2024
*/

#ifndef OPERATION_HPP_

#define OPERATION_HPP_

#include "menu.hpp"
#include "Series.hpp"

using namespace std;

class operation : public menu {
    private:
        vector<string> questions;

    public:

        operation(vector<string> &question, string title, string pattern);
        vector<string *> doUserQA();
        void setWidth();

};

#endif