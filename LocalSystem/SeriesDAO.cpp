/* 
Júlio Shoji Zotovici Kobayashi
Class SeriesDAO
June, 2024
*/

#include "SeriesDAO.hpp"

SeriesDAO::SeriesDAO(ServerDBconnection* serverConn) :  serverConn(serverConn){

};

Series SeriesDAO::getSeriesbyID(int internal_id){
    Series RequestedSeries;
    try
    {
        vector<Series> serieList = this->serverConn->getSeries();
        for(Series serie : serieList){
            if(serie.getInternal_id() == internal_id){
                serie.printSeries();
                RequestedSeries = serie;
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return RequestedSeries;
};

vector<Series> SeriesDAO::getSeriesOrderByTitle(){
    vector<Series> SeriesByTitle;
    try
    {   
        string s1, s2;
        Series auxiliar;
        vector<Series> serieList = serverConn->getSeries();
        vector<Series>::iterator listIterator = serieList.begin();
        while(listIterator != serieList.end()){
            s1 = listIterator->getSeries_name();
            s2 = (++listIterator)->getSeries_name();
            if(s2[0] > s1[0]){
                auxiliar = listIterator;
                listIterator = (++listIterator);
                (++listIterator) = auxiliar;
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return SeriesByTitle;
};

vector<Series> SeriesDAO::getSeriesOrderbyNetwork(){
    vector<Series> SeriesByNetwork;
    try
    {
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return SeriesByNetwork;
};
vector<Series> SeriesDAO::getSeriesOrderbyYear(){
    vector<Series> SeriesByYear;
    try
    {
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return SeriesByYear;
};
vector<Series> SeriesDAO::getSeriesOrderbyRating(){
    vector<Series> SeriesByRating;
    try
    {
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return SeriesByRating;
};