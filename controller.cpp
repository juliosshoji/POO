/* 
Júlio Shoji Zotovici Kobayashi
Class controller
June, 2024
*/

#include "controller.hpp"
#include "sysinfo.hpp"


using namespace std;

void exitPress();

controller::controller(){
    this->start();
};
controller::~controller(){};
void controller::start(){
    vector<string> mainItens {"Series","Relatorios", "Ajuda", "Creditos"};
    vector<void (controller:: *)()> actions {&controller::menuSeries, &controller::menuReport, &controller::menuHelp, &controller::menuInfo};
    while (this->doAction("Main Menu", mainItens, actions));
};

bool controller::doAction(string menuTitle, vector<string> nameItens, vector<void (controller:: *)()> actions){
    unique_ptr<menu> doMenu(new menu(nameItens, menuTitle, "*"));
    doMenu->drawMenu();
    int choice = doMenu->getChoice();
    if(choice != 0)
        (this->*actions.at(choice - 1))();
    else{
         cout << endl <<  "Saindo!" << endl;
         return false;
    }
    return true;
};

void controller::menuHelp(){

    cout << "Menu Ajuda" << endl;

};

void controller::menuInfo(){
    unique_ptr<sysinfo> sys_on(new sysinfo());
    cout << sys_on->getInfo() << endl;
    getch();
};

void controller::menuReport(){
    vector<string> reportItens {"Ordenar por titulo","Ordenar por canal/streaming", "Ordenar por ano", "Ordenar por nota"};
    vector<void (controller:: *)()> actions {&controller::titleReport, &controller::channelReport, &controller::yearReport, &controller::gradeReport};
    while(this->doAction("Menu de Relatorio", reportItens, actions)){
        getch();
    };
};

void controller::menuSeries(){
    vector<string> seriesItens {"Novo registro","Recuperar registro", "Editar registro", "Excluir registro"};
    vector<void (controller:: *)()> actions {&controller::includeSeries, &controller::recoverySeries, &controller::editSeries, &controller::deleteSeries};
    while(this->doAction("Menu de Series", seriesItens, actions)){
        getch();
    }
};

void controller::includeSeries(){
    cout << "Novo registro" << endl;
};
void controller::recoverySeries(){
    cout << "Recuperando registro" << endl;
};
void controller::editSeries(){
    cout << "Editando registro" << endl;
};
void controller::deleteSeries(){
    cout << "Deletando registro" << endl;
};

void controller::titleReport(){
    cout << "Relatorio por titulo" << endl;
};

void controller::channelReport(){
    cout << "Relatorio por canal" << endl;
};
void controller::yearReport(){
    cout << "Relatorio por ano" << endl;
};
void controller::gradeReport(){
    cout << "Relatorio por nota" << endl;
};

