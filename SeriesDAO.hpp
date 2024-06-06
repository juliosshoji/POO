/* 
Júlio Shoji Zotovici Kobayashi
Class SeriesDAO
June, 2024
*/

#ifndef SERIESDAO_HPP_

#define SERIESDAO_HPP_

#include "AbstractSeriesDAO.hpp"
#include "ServerDBconnection.hpp"
#include "Series.hpp"

using namespace std;

//Cria um objeto dessa classe quando entra no menu Series e dependendo do que o usuario ecolher, chama cada metodo diferente

class SeriesDAO final : public AbstractSeriesDAO {

    private:
        //Mensagens padrao
        const string addSeriesTxt = "insert into SERIES (Field, Type) values (?,?)";
        const string getSeriesbyIDTxt = "select * from SERIES where internal_id = ?";
        const string getSeriesOrderbyTitleTxt = "select * from SERIES order by Field";
        const string getSeriesOrderbyNetworkTxt = "select * from SERIES order by network";
        const string getSeriesOrderbyYearTxt = "select * from SERIES order by release_year";
        const string getSeriesOrderbyRatingTxt = "select * from SERIES order by rating";
        const string updateSeriesTxt = "update SERIES set  series_name = ?, Type = ? where internal_id = ?";
        const string deleteSeriesTxt = "delete from SERIES where internal_id = ?";

        //Classe para conexao e transferencia de dados
        ServerDBconnection* serverConn;

    public:

        SeriesDAO(ServerDBconnection* serverConn);
        //Funcoes de request do menu
        void addSeries(Series* Serie);
        void updateSeries(Series* Serie);
        void deleteSeries(Series* Serie);
        Series* getSeriesbyID(int internal_id);
        vector<Series *> getSeriesOrderByTitle();
        vector<Series *> getSeriesOrderbyNetwork();
        vector<Series *> getSeriesOrderbyYear();
        vector<Series *> getSeriesOrderbyRating();

};



#endif