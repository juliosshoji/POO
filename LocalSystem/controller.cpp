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

    unique_ptr<help> doHelp(new help());
    getchar();
    cout << endl << "Pressione Enter para continuar..." << endl;
    getchar();

};

void controller::menuInfo(){

    getchar();
    unique_ptr<sysinfo> sys_on(new sysinfo());
    cout << endl << sys_on->getInfo() << endl;
    cout << "Pressione Enter para continuar..." << endl;
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
    includeSeriesOp->drawLine();
    addingSerie->printSeries();
    includeSeriesOp->drawLine();
    cout << endl << "Enter para confirmar" << endl;
    char sendConfirm = getchar();
    if(sendConfirm == 42){
        cout << "Cancelado!" << endl;
        return;
    }
    this->serverConn->addSeries(*addingSerie);
    cout << endl << "Novo Registro Criado" << endl;
    cout << endl << "Pressione Enter para continuar..." << endl;
};
void controller::recoverySeries(){
    vector<string> questions {"Qual o ID da serie?"};
    unique_ptr<menu> includeSeriesOp(new menu(questions, "Recuperando um registro", "*"));
    vector<string> answers = includeSeriesOp->doUserQA();
    int internal_id = stoi(answers[0]);
    Series recoveredSeries = this->SeriesDB->getSeriesbyID(internal_id);
    includeSeriesOp->drawLine();
    recoveredSeries.printSeries();
    includeSeriesOp->drawLine();
    cout << endl << "Registro Recuperado" << endl;
    cout << endl << "Pressione Enter para continuar..." << endl;

};
void controller::editSeries(){
    vector<string> questions {"Digite o ID da serie:", "Qual o nome da serie?","Em que ano essa serie foi lancada? ", "Quantas temporadas possui?", "Quantos episodios possui?", "Quais os atores principais?", "Quais os personagens principais?", "Em qual canal/streaming e possivel assistir?", "Qual a nota dessa serie?"};
    unique_ptr<menu> includeSeriesOp(new menu(questions, "Editando Registro", "*"));
    vector<string> answers = includeSeriesOp->doUserQA();
    unique_ptr<Series> updatingSerie(new Series(stoi(answers[0]),answers[1], stoi(answers[2]), stoi(answers[3]), stoi(answers[4]), answers[5], answers[6], answers[7], stoi(answers[8])));
    includeSeriesOp->drawLine();
    updatingSerie->printSeries();
    includeSeriesOp->drawLine();
    cout << endl << "Enter para confirmar ou * para cancelar" << endl;
    char sendConfirm = getchar();
    if(sendConfirm == 42){
        cout << "Cancelado!" << endl;
        return;
    }
    this->serverConn->updateSeries(*updatingSerie);
    cout << endl << "Mudancas aplicadas" << endl;
    cout << endl << "Pressione Enter para continuar..." << endl;
};
void controller::deleteSeries(){
    vector<string> questions {"Qual o ID da serie?"};
    unique_ptr<menu> includeSeriesOp(new menu(questions, "Deletando um registro", "*"));
    vector<string> answers = includeSeriesOp->doUserQA();
    int internal_id = stoi(answers[0]);
    Series recoveredSeries = this->SeriesDB->getSeriesbyID(internal_id);
    includeSeriesOp->drawLine();
    recoveredSeries.printSeries();
    includeSeriesOp->drawLine();
    cout << endl << "Enter para prosseguir ou * para cancelar" << endl;
    char sendConfirm = getchar();
    if(sendConfirm == 42){
        cout << "Cancelado!" << endl;
        return;
    }
    this->serverConn->deleteSeries(recoveredSeries.getInternal_id());
    cout << endl << "Serie deletada!" << endl;
    cout << endl << "Pressione Enter para continuar..." << endl;
};

void controller::titleReport(){

    unique_ptr<menu> reportMenu(new menu("Relatorio por titulo", "*"));
    reportMenu->drawReport(this->SeriesDB->getSeriesOrderByTitle());
    cout << endl << "Pressione Enter para continuar..." << endl;
    getchar();
};

void controller::channelReport(){

    unique_ptr<menu> reportMenu(new menu("Relatorio por canal/streaming", "*"));
    reportMenu->drawReport(this->SeriesDB->getSeriesOrderbyNetwork());
    cout << endl << "Pressione Enter para continuar..." << endl;
    getchar();
};
void controller::yearReport(){
    unique_ptr<menu> reportMenu(new menu("Relatorio por ano", "*"));
    reportMenu->drawReport(this->SeriesDB->getSeriesOrderbyYear());
    cout << endl << "Pressione Enter para continuar..." << endl;
    getchar();
};
void controller::gradeReport(){
    unique_ptr<menu> reportMenu(new menu("Relatorio por nota", "*"));
    reportMenu->drawReport(this->SeriesDB->getSeriesOrderbyRating());
    cout << endl << "Pressione Enter para continuar..." << endl;
    getchar();
};

