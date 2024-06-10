/*
Júlio Shoji Zotovici Kobayashi
Class help
June, 2024
*/

#include "help.hpp"

help::help(){
    this->helpPage();
};

void help::helpPage(){

    try
    {
        string buffer;
        ifstream helpArchive;
        helpArchive.open("helpArchive.txt", fstream::in);

        while(!helpArchive.eof()){
            getline(helpArchive, buffer);
            cout << buffer << endl;
        }
        cout << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
};