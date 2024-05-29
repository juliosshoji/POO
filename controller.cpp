/* 
Júlio Shoji Zotovici Kobayashi
Class controller
June, 2024
*/
#include "controller.hpp"

using namespace std;

controller::controller(int code){
    this->start();
};
controller::~controller(){};
void controller::start(){
    vector<string> mainItens {"Series","Relatorios", "Ajuda", "Creditos"};
    vector<void (controller:: *)()> actions {&controller::menuSeries, &controller::menuReport, &controller::menuHelp, &controller::menuInfo};
    this->doAction("Main Menu", mainItens, actions);
};

void controller::doAction(string menuTitle, vector<string> nameItens, vector<void (controller:: *)()> actions){
    unique_ptr<menu> doMenu(new menu(nameItens, menuTitle, "*"));
    doMenu->drawMenu();
    int choice = doMenu->getChoice();
    cout << choice << endl;
    if(choice != 0)
        (this->*actions.at(choice - 1))();
    else
        cout << "Saindo!" << endl;
};

void controller::menuHelp(){

    cout << "Menu Ajuda" << endl;

};

void controller::menuInfo(){
    cout << "Menu Creditos" << endl;
};

void controller::menuReport(){
    cout << "Menu Relatorios" << endl;
};

void controller::menuSeries(){
    cout << "Menu Series" << endl;
};