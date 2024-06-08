/* 
Júlio Shoji Zotovici Kobayashi
Class SeriesDAO
June, 2024
*/

#ifndef SERIESDAO_HPP_

#define SERIESDAO_HPP_

#include "ServerDBconnection.hpp"
#include "Series.hpp"

using namespace std;

//Cria um objeto dessa classe quando entra no menu Series e dependendo do que o usuario ecolher, chama cada metodo diferente

class SeriesDAO {

    private:
        //Mensagens padrao
        const string addSeriesTxt = "insert into SERIES (Field, Type) values (?,?)";
        const string getSeriesbyIDTxt = "select * from SERIES where internal_id = ?";
        const string getSeriesOrderbyTitleTxt = "select * from SERIES order by series_name";
        const string getSeriesOrderbyNetworkTxt = "select * from SERIES order by network";
        const string getSeriesOrderbyYearTxt = "select * from SERIES order by release_year";
        const string getSeriesOrderbyRatingTxt = "select * from SERIES order by rating";
        const string updateSeriesTxt = "update SERIES set  series_name = ?, release_year = ?, season = ?, episode_count = ?, main_actors = ?, main_characters = ?, network = ?, rating = ? where internal_id = ?";
        const string deleteSeriesTxt = "delete from SERIES where internal_id = ?";

        //Classe para conexao e transferencia de dados
        ServerDBconnection* serverConn;

    public:

        SeriesDAO(ServerDBconnection* serverConn);
        //Funcoes de request do menu
        virtual void addSeries(Series* Serie);
        virtual void updateSeries(Series* Serie);
        virtual void deleteSeries(Series* Serie);
        virtual Series* getSeriesbyID(int internal_id);
        vector<Series *> getSeriesOrderByTitle();
        vector<Series *> getSeriesOrderbyNetwork();
        vector<Series *> getSeriesOrderbyYear();
        vector<Series *> getSeriesOrderbyRating();

};



#endif