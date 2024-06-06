/* 
Júlio Shoji Zotovici Kobayashi
Class SeriesDAO
June, 2024
*/

#include "SeriesDAO.hpp"

SeriesDAO(ServerDBconnection* serverConn) : serverConn(serverConn){

};

void SeriesDAO::addSeries(Series* serie){
    try
    {
        unique_ptr<sql::PreparedStatement> statement(serverConn->getConnection()->prepareStatement(this->addSeriesTxt));
        statement->setString(1, serie->getInternal_id);
        statement->setString(2, serie->getSeries_name);
        statement->setString(3, serie->getRelease_year);
        statement->setString(4, serie->getSeason);
        statement->setString(5, serie->getEpisode_count);
        statement->setString(6, serie->getMain_actors);
        statement->setString(7, serie->getMain_characters);
        statement->setString(8, serie->getNetwork);
        statement->setString(9, serie->getRating);
        statement->executeQuery();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
  
};