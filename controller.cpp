/* 
Júlio Shoji Zotovici Kobayashi
Class controller
June, 2024
*/

#include "controller.hpp"

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
    try
    {
        vector<string> questions {"Qual o nome da serie?","Em que ano essa serie foi lancada? ", "Quantas temporadas possui?", "Quantos episodios possui?", "Quais os atores principais?", "Quais os personagens principais?", "Em qual canal/streaming e possivel assistir?", "Qual a nota dessa serie?"};
        unique_ptr<menu> includeSeriesOp(new menu(questions, "Novo Registro", "*"));
        
        
        string series_name;
        cout << questions[0] << endl;
        cin >> series_name;
        int release_year;
        cout << questions[1] << endl;
        cin >> release_year;
        int season;
        cout << questions[2] << endl;
        cin >> season;
        int episode_count;
        cout << questions[3] << endl;
        cin >> episode_count;
        string main_actors;
        cout << questions[4] << endl;
        cin >> main_actors;
        string main_characters;
        cout << questions[5] << endl;
        cin >> main_characters;
        string network;
        cout << questions[6] << endl;
        cin >> network;
        int rating;
        cout << questions[7] << endl;
        cin >> rating;
        unique_ptr<Series> newSeries(new Series(series_name, release_year, season, episode_count, main_actors, main_characters, network, rating));
        cout << newSeries->getInternal_id() << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "including series " << '\n';
    }
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

