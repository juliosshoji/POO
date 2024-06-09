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
        this->width = this->title.length() * 2;
    else
        this->width = bigoption.length() * 2;
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
    
    
    return answers;
};

void menu::drawReport(vector<Series* > reportResult){
    this->width = 122;
    this->drawLine();
    cout << setw((this->width/2)+(this->title.length()/2)) << endl << this->title << endl;
    this->drawLine();
    cout << this->pattern << setw(this->width) << this->pattern << endl;
    cout << this->pattern << " " << setw(3) << "ID";
    cout << " " << this->pattern << " " << setw(10) << "Nome";
    cout << " " << this->pattern << " " << setw(5) << "Ano";
    cout << " " << this->pattern << " " << setw(4) << "Temp";
    cout << " " << this->pattern << " " << setw(11) << "Episodios";
    cout << " " << this->pattern << " " << setw(19) << "Principais Atores";
    cout << " " << this->pattern << " " << setw(24) << "Principais Personagens";
    cout << " " << this->pattern << " " << setw(12) << "Plataforma";
    cout << " " << this->pattern << " " << setw(3) << "Nota" << " " << this->pattern << " " << endl;
    for(Series* serie : reportResult){
        cout << this->pattern << " " << setw(3) << serie->getInternal_id();
        cout << " " << this->pattern << " " << setw(10) << serie->getSeries_name();
        cout << " " << this->pattern << " " << setw(5) << serie->getRelease_year();
        cout << " " << this->pattern << " " << setw(4) << serie->getSeason();
        cout << " " << this->pattern << " " << setw(11) << serie->getEpisode_count();
        cout << " " << this->pattern << " " << setw(19) << serie->getMain_actors();
        cout << " " << this->pattern << " " << setw(24) << serie->getMain_characters();
        cout << " " << this->pattern << " " << setw(12) << serie->getNetwork();
        cout << " " << this->pattern << " " << setw(5) << serie->getRating() << " " << this->pattern << " " << endl;
    }
    cout << this->pattern << setw(this->width) << this->pattern << endl;
    this->drawLine();
    cout << endl << this->title << endl;
    this->drawLine();
};