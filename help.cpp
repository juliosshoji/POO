/*
Júlio Shoji Zotovici Kobayashi
Class help
June, 2024
*/

#include "help.hpp"

help::help(){
    cout << this->helpPage() << endl;
};

string help::helpPage(){
    
    string finalHelp;
    try
    {
        string buffer;
        ifstream helpArchive;
        helpArchive.open("helpArchive.txt", fstream::in);
        finalHelp = "";
        while(!helpArchive.eof()){
            getline(helpArchive, buffer);
            finalHelp += buffer;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return finalHelp;
};