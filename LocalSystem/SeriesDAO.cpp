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
    unique_ptr<vector<Series>> SeriesByTitle(new vector<Series>);
    try
    {   
        string s1, s2;
        Series auxiliar;
        SeriesByTitle = serverConn->getSeries();
        vector<Series>::iterator listIterator = SeriesByTitle->begin();
        for(size_t index1 = 0; index1 < SeriesByTitle->size(); index1++){
            for(size_t index2 = 0; index2 < SeriesByTitle->size(); index2++){
                s1 = SeriesByTitle[index2].getSeries_name(); 
                s2 = SeriesByTitle[index2+1].getSeries_name(); 
                if(s1[0] > s2[0]){
                    auxiliar = SeriesByTitle[index2];
                    SeriesByTitle[index2] = SeriesByTitle[index2+1];
                    SeriesByTitle[index2+1] = auxiliar; 
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