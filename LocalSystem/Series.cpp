/* 
Júlio Shoji Zotovici Kobayashi
Class Series
June, 2024
*/

#include "Series.hpp"

using namespace std;

Series::Series(int internal_id, string series_name, int release_year, int season, int episode_count, string main_actors, string main_characters, string network, int rating) : internal_id(internal_id),
series_name(series_name), release_year(release_year), season(season), episode_count(episode_count), main_actors(main_actors), main_characters(main_characters), network(network), rating(rating){

};

Series::Series(string series_name, int release_year, int season, int episode_count, string main_actors, string main_characters, string network, int rating) : series_name(series_name), release_year(release_year), season(season), episode_count(episode_count), main_actors(main_actors), main_characters(main_characters), network(network), rating(rating){
    try
    {
        ifstream lastIDfile;
        lastIDfile.open("lastcreatedID.txt", fstream::in);
        string lastID;
        getline(lastIDfile, lastID);
        this->setInternal_id(stoi(lastID) + 1);
        lastIDfile.close();
        remove("lastcreatedID.txt");
        ofstream newIDfile;
        newIDfile.open("lastcreatedID.txt", fstream::out);
        newIDfile << this->getInternal_id();
        newIDfile.close();
    }   
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }       
};

Series::Series(){};

int Series::getInternal_id(){
    return this->internal_id;
};
string Series::getSeries_name(){
    return this->series_name;
};
int Series::getRelease_year(){
    return this->release_year;
};
int Series::getSeason(){
    return this->season;
};
int Series::getEpisode_count(){
    return this->episode_count;
};
string Series::getMain_actors(){
    return this->main_actors;
};
string Series::getMain_characters(){
    return this->main_characters;
};
string Series::getNetwork(){
    return this->network;
};
int Series::getRating(){
    return this->rating;
};

void Series::setInternal_id(int internal_id){
    this->internal_id = internal_id;
};
void Series::setSeries_name(string series_name){
    this->series_name = series_name;
};
void Series::setRelease_year(int release_year){
    this->release_year = release_year;
};
void Series::setSeason(int season){
    this->season = season;
};
void Series::setEpisode_count(int episode_count){
    this->episode_count = episode_count;
};
void Series::setMain_actors(string main_actors){
    this->main_actors = main_actors;
};
void Series::setMain_characters(string getMain_characters){
    this->main_characters = main_characters;
};
void Series::setNetwork(string network){
    this->network = network;
}
void Series::setRating(int rating){
    this->rating = rating;
};

void Series::printSeries(){
    cout << endl << "Codigo da serie: " << this->internal_id << endl;
    cout << "Nome da serie: " << this->series_name << endl;
    cout << "Ano de lancamento: " << this->release_year << endl;
    cout << "Numero de Temporadas: " << this->season << endl;
    cout << "Numero de episodios: " << this->episode_count << endl;
    cout << "Principais atores/atrizes: " << this->main_actors << endl;
    cout << "Principais personagens: " << this->main_characters << endl;
    cout << "Canal/Streaming: " << this->network << endl;
    cout << "Nota: " << this->rating << endl << endl;
};