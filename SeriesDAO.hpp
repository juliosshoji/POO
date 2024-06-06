/* 
Júlio Shoji Zotovici Kobayashi
Class SeriesDAO
June, 2024
*/

#ifndef SERIESDAO_HPP_

#define SERIESDAO_HPP_

#include "AbstractSeriesDAO.hpp"
#include "ServerDBconnection.hpp"

using namespace std;

//Cria um objeto dessa classe quando entra no menu Series e dependendo do que o usuario ecolher, chama cada metodo diferente

class SeriesDAO final : public AbstractSeriesDAO {

    private:
        //Mensagens padrao
        const string addSeriesTxt = "insert into SERIES (Field, Type) values (?,?)";
        const string getSeriesbyID = "select * from SERIES where internal_id = ?";
        const string getSeriesOrderbyTitle = "select * from SERIES order by Field";
        const string getSeriesOrderbyNetwork = "select * from SERIES order by network";
        const string getSeriesOrderbyYear = "select * from SERIES order by release_year";
        const string getSeriesOrderbyRating = "select * from SERIES order by rating";
        const string updateSeries = "update SERIES set  series_name = ?, Type = ? where internal_id = ?";
        const string deleteSeries = "delete from SERIES where internal_id = ?";

        //Classe para conexao e transferencia de dados
        ServerDBconnection* serverConn;


    public:
        //Funcoes de request do menu

};



#endif