/* 
Júlio Shoji Zotovici Kobayashi
Class controller
June, 2024
*/

#include "controller.hpp"

using namespace std;

void exitPress();

controller::controller(){
    this->serverConn = new ServerDBconnection();
    this->SeriesDB = new SeriesDAO(serverConn);
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
    getchar();
};

void controller::menuReport(){
    vector<string> reportItens {"Ordenar por titulo","Ordenar por canal/streaming", "Ordenar por ano", "Ordenar por nota"};
    vector<void (controller:: *)()> actions {&controller::titleReport, &controller::channelReport, &controller::yearReport, &controller::gradeReport};
    while(this->doAction("Menu de Relatorio", reportItens, actions)){
        getchar();
    };
};

void controller::menuSeries(){
    vector<string> seriesItens {"Novo registro","Recuperar registro", "Editar registro", "Excluir registro"};
    vector<void (controller:: *)()> actions {&controller::includeSeries, &controller::recoverySeries, &controller::editSeries, &controller::deleteSeries};
    while(this->doAction("Menu de Series", seriesItens, actions)){
        getchar();
    }
};

void controller::includeSeries(){
    vector<string> questions {"Qual o nome da serie?","Em que ano essa serie foi lancada? ", "Quantas temporadas possui?", "Quantos episodios possui?", "Quais os atores principais?", "Quais os personagens principais?", "Em qual canal/streaming e possivel assistir?", "Qual a nota dessa serie?"};
    unique_ptr<menu> includeSeriesOp(new menu(questions, "Novo Registro", "*"));
    vector<string> answers = includeSeriesOp->doUserQA();
    unique_ptr<Series> addingSerie(new Series(answers[0], stoi(answers[1]), stoi(answers[2]), stoi(answers[3]), answers[4], answers[5], answers[6], stoi(answers[7])));
    this->SeriesDB->addSeries(&*addingSerie);
    cout << endl << "Novo Registro Criado" << endl;
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

