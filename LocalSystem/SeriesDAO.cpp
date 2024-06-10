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
   vector<Series>SeriesByTitle;
    try
    {   
        string s1, s2;
        SeriesByTitle = this->serverConn->getSeries();
        Series auxiliar;
        for(size_t indexSecondery = 0; indexSecondery < SeriesByTitle.size(); indexSecondery++){
            for(size_t indexPrimary = 0; indexPrimary <= indexSecondery; indexPrimary++){
                auxiliar = SeriesByTitle.at(indexPrimary+1);
                s1 = SeriesByTitle[indexPrimary].getSeries_name();
                s2 = auxiliar.getSeries_name();
                if(s1[0] > s2[0]){
                    SeriesByTitle.at(indexPrimary+1) = SeriesByTitle.at(indexPrimary);
                    SeriesByTitle.at(indexPrimary) = auxiliar;
                }
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