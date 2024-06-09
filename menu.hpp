/* 
Júlio Shoji Zotovici Kobayashi
Class menu
June, 2024
*/

#ifndef MENU_HPP_

#define MENU_HPP_

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "Series.hpp"

using namespace std;
class menu {

    private: 
        vector<string> option;
        
        bool isValidChoice(int choice);

    protected:
        string title;
        string pattern;
        int width;

    public:
        menu(vector<string> &option, string title = "Menu", string pattern = "*");
        menu(string title, string pattern);
        ~menu();
        void setPattern(const string &pattern);
        void setTitle(const string &title);
        virtual void setWidth();
        void setDecorator();
        int getChoice();
        void drawLine();
        void drawMenu();
        void drawReport(vector<Series* > reportResult);
        vector<string> doUserQA();
       
};

#endif