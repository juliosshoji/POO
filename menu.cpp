/* 
Júlio Shoji Zotovici Kobayashi
Class menu
June, 2024
*/

#include "menu.hpp"

using namespace std;

bool isValidChoice(int choice);

menu::menu(vector<string> &option, string title, string pattern) : option(option), title(title), pattern(pattern){
    this->setWidth();
};

menu::menu(string title, string pattern) : title(title), pattern(pattern) {
    this->setWidth();
};

menu::~menu(){
};

void menu::setWidth(){
    string bigoption = option[0];
    for (string option : this->option)
    {
        if(option.length() > bigoption.length()) {bigoption = option;}
    }
    if(this->title.length() > bigoption.length())
        this->width = this->title.length();
    else
        this->width = bigoption.length() * 3;
};

void menu::setPattern(const string &pattern){
    this->pattern = pattern;
};

void menu::setTitle(const string &title){
    this->title = title;
};

void menu::drawMenu(){
    
    drawLine();
    cout << setw((this->width/2)+(this->title.length()/2)) << endl << this->title << endl;
    drawLine();
    for(int index = 0; index < this->option.size(); index++){
        if(index == 0){
            cout << endl;
            cout << setw(this->width/this->title.length()) << index << ". ";
            cout << "Sair" << endl;
        }
        cout << endl;
        cout << setw(this->width/this->title.length()) << index + 1 << ". ";
        cout << this->option[index] << endl;
    }
    drawLine();
    drawLine();
    cout << endl;

};

void menu::drawLine(){
    cout << endl;
    for(int position = 0; position <= this->width; position++){
        cout << this->pattern;
    }
    cout << endl;
};

int menu::getChoice(){
    int choice;
    do{
        cout << "Enter valid input: ";
        cin >> choice;
    }while(!this->isValidChoice(choice));
    
    return choice;
};

bool menu::isValidChoice(int choice){
    return ((choice >= 0) && (choice <= this->option.size()));
};

vector<string> menu::doUserQA(){
    vector<string> answers;
    try
    {
        this->drawLine();
        cout << setw((this->width/2)+(this->title.length()/2)) << endl << this->title << endl;
        this->drawLine();
        getchar();
        string singleAnswer;
        for (size_t i = 0; i < this->option.size(); i++){
            cout << endl;
            cout << setw(this->width/this->title.length()) << this->option[i] << endl;
            getline(cin, singleAnswer);
            answers.push_back(singleAnswer);
        }
        this->drawLine();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "UserQA" << '\n';
    }
    
    return answers;
};