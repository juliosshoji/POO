/* 
Júlio Shoji Zotovici Kobayashi
Class SeriesDAO
June, 2024
*/

#include "SeriesDAO.hpp"

SeriesDAO::SeriesDAO(ServerDBconnection* serverConn) :  serverConn(serverConn){

};

void SeriesDAO::addSeries(Series* serie){
    try
    {
        sql::PreparedStatement* statement(serverConn->getConnection()->prepareStatement(this->addSeriesTxt));
        statement->setInt(1, serie->getInternal_id());
        statement->setString(2, serie->getSeries_name());
        statement->setInt(3, serie->getRelease_year());
        statement->setInt(4, serie->getSeason());
        statement->setInt(5, serie->getEpisode_count());
        statement->setString(6, serie->getMain_actors());
        statement->setString(7, serie->getMain_characters());
        statement->setString(8, serie->getNetwork());
        statement->setInt(9, serie->getRating());
        statement->executeQuery();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
  
};

void SeriesDAO::updateSeries(Series* serie){

    try
    {
        sql::PreparedStatement* statement(serverConn->getConnection()->prepareStatement(this->updateSeriesTxt));
        statement->setString(1, serie->getSeries_name());
        statement->setInt(2, serie->getRelease_year());
        statement->setInt(3, serie->getSeason());
        statement->setInt(4, serie->getEpisode_count());
        statement->setString(5, serie->getMain_actors());
        statement->setString(6, serie->getMain_characters());
        statement->setString(7, serie->getNetwork());
        statement->setInt(8, serie->getRating());
        statement->setInt(9, serie->getInternal_id());
        statement->executeQuery();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
};

void SeriesDAO::deleteSeries(Series* serie){
    
    try
    {
        sql::PreparedStatement* statement(serverConn->getConnection()->prepareStatement(this->deleteSeriesTxt));
        statement->setInt(1, serie->getInternal_id());
        statement->executeQuery();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

};

Series* SeriesDAO::getSeriesbyID(int internal_id){
    Series* RequestedSeries;
    try
    {
        sql::PreparedStatement* statement(serverConn->getConnection()->prepareStatement(this->getSeriesbyIDTxt));
        statement->setInt(1, internal_id);
        sql::ResultSet *ResultReq = statement->executeQuery();
        if(ResultReq->next()){
            
            RequestedSeries->setInternal_id(ResultReq->getInt(1));
            RequestedSeries->setSeries_name((ResultReq->getString(2)).c_str());
            RequestedSeries->setRelease_year(ResultReq->getInt(3));               ResultReq->getInt(4),
            RequestedSeries->setSeason(ResultReq->getInt(4));
            RequestedSeries->setEpisode_count(ResultReq->getInt(5));
            RequestedSeries->setMain_actors((ResultReq->getString(6)).c_str());
            RequestedSeries->setMain_characters((ResultReq->getString(7)).c_str());
            RequestedSeries->setNetwork((ResultReq->getString(8)).c_str());
            RequestedSeries->setRating(ResultReq->getInt(9));
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return RequestedSeries;
};

vector<Series *> SeriesDAO::getSeriesOrderByTitle(){
    vector<Series *> SeriesByTitle;
    try
    {
        sql::Statement* statement(serverConn->getConnection()->createStatement());
        sql::ResultSet *ResultReq = statement->executeQuery(this->getSeriesOrderbyTitleTxt);
        Series* RequestedSeries;
        while(ResultReq->next()){
                RequestedSeries->setInternal_id(ResultReq->getInt(1));
                RequestedSeries->setSeries_name((ResultReq->getString(2)).c_str());
                RequestedSeries->setRelease_year(ResultReq->getInt(3));
                RequestedSeries->setSeason(ResultReq->getInt(4));
                RequestedSeries->setEpisode_count(ResultReq->getInt(5));
                RequestedSeries->setMain_actors((ResultReq->getString(6)).c_str());
                RequestedSeries->setMain_characters((ResultReq->getString(7)).c_str());
                RequestedSeries->setNetwork((ResultReq->getString(8)).c_str());
                RequestedSeries->setRating(ResultReq->getInt(9));

                SeriesByTitle.push_back(RequestedSeries);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return SeriesByTitle;
};

vector<Series *> SeriesDAO::getSeriesOrderbyNetwork(){
    vector<Series *> SeriesByNetwork;
    try
    {
        
        sql::Statement* statement(serverConn->getConnection()->createStatement());
        sql::ResultSet *ResultReq = statement->executeQuery(this->getSeriesOrderbyNetworkTxt);
        Series* RequestedSeries;
        while(ResultReq->next()){
                RequestedSeries->setInternal_id(ResultReq->getInt(1));
                RequestedSeries->setSeries_name((ResultReq->getString(2)).c_str());
                RequestedSeries->setRelease_year(ResultReq->getInt(3));
                RequestedSeries->setSeason(ResultReq->getInt(4));
                RequestedSeries->setEpisode_count(ResultReq->getInt(5));
                RequestedSeries->setMain_actors((ResultReq->getString(6)).c_str());
                RequestedSeries->setMain_characters((ResultReq->getString(7)).c_str());
                RequestedSeries->setNetwork((ResultReq->getString(8)).c_str());
                RequestedSeries->setRating(ResultReq->getInt(9));

                SeriesByNetwork.push_back(RequestedSeries);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return SeriesByNetwork;
};
vector<Series *> SeriesDAO::getSeriesOrderbyYear(){
    vector<Series *> SeriesByYear;
    try
    {
        
        sql::Statement* statement(serverConn->getConnection()->createStatement());
        sql::ResultSet *ResultReq = statement->executeQuery(this->getSeriesOrderbyYearTxt);
        Series* RequestedSeries;
        while(ResultReq->next()){
                RequestedSeries->setInternal_id(ResultReq->getInt(1));
                RequestedSeries->setSeries_name((ResultReq->getString(2)).c_str());
                RequestedSeries->setRelease_year(ResultReq->getInt(3));
                RequestedSeries->setSeason(ResultReq->getInt(4));
                RequestedSeries->setEpisode_count(ResultReq->getInt(5));
                RequestedSeries->setMain_actors((ResultReq->getString(6)).c_str());
                RequestedSeries->setMain_characters((ResultReq->getString(7)).c_str());
                RequestedSeries->setNetwork((ResultReq->getString(8)).c_str());
                RequestedSeries->setRating(ResultReq->getInt(9));

                SeriesByYear.push_back(RequestedSeries);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return SeriesByYear;
};
vector<Series *> SeriesDAO::getSeriesOrderbyRating(){
    vector<Series *> SeriesByRating;
    try
    {
        sql::Statement* statement(serverConn->getConnection()->createStatement());
        sql::ResultSet *ResultReq = statement->executeQuery(this->getSeriesOrderbyRatingTxt);
        Series* RequestedSeries;
        while(ResultReq->next()){
                RequestedSeries->setInternal_id(ResultReq->getInt(1));
                RequestedSeries->setSeries_name((ResultReq->getString(2)).c_str());
                RequestedSeries->setRelease_year(ResultReq->getInt(3));
                RequestedSeries->setSeason(ResultReq->getInt(4));
                RequestedSeries->setEpisode_count(ResultReq->getInt(5));
                RequestedSeries->setMain_actors((ResultReq->getString(6)).c_str());
                RequestedSeries->setMain_characters((ResultReq->getString(8)).c_str());
                RequestedSeries->setRating(ResultReq->getInt(9));

                SeriesByRating.push_back(RequestedSeries);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return SeriesByRating;
};