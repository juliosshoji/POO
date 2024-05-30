/* 
Júlio Shoji Zotovici Kobayashi
Class Controle do projeto de POO I
Junho de 2024
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
    unique_ptr<sysinfo> sys_on(new sysinfo());
    cout << sys_on->getInfo() << endl;
};

void controller::menuReport(){
    vector<string> reportItens {"Ordenar por titulo","Ordenar por canal/streaming", "Ordenar por ano", "Ordenar por nota"};
    vector<void (controller:: *)()> actions {&controller::titleReport, &controller::channelReport, &controller::yearReport, &controller::gradeReport};
    this->doAction("Menu de Relatorio", reportItens, actions);
};

void controller::menuSeries(){
    vector<string> seriesItens {"Novo registro","Recuperar registro", "Editar registro", "Excluir registro"};
    vector<void (controller:: *)()> actions {&controller::includeSeries, &controller::recoverySeries, &controller::editSeries, &controller::deleteSeries};
    this->doAction("Menu de Series", seriesItens, actions);
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
