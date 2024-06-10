/* 
Júlio Shoji Zotovici Kobayashi
Class SeriesDAO
June, 2024
*/

#ifndef SERIESDAO_HPP_

#define SERIESDAO_HPP_

#include <algorithm>
#include "ServerDBconnection.hpp"
#include "Series.hpp"

using namespace std;

//Cria um objeto dessa classe quando entra no menu Series e dependendo do que o usuario ecolher, chama cada metodo diferente

class SeriesDAO {

    private:
        //Mensagens padrao
        //Classe para conexao e transferencia de dados
        ServerDBconnection* serverConn;

    public:

        SeriesDAO(ServerDBconnection* serverConn);
        //Funcoes de request do menu
        virtual Series getSeriesbyID(int internal_id);
        vector<Series> getSeriesOrderByTitle();
        vector<Series> getSeriesOrderbyNetwork();
        vector<Series> getSeriesOrderbyYear();
        vector<Series> getSeriesOrderbyRating();

};



#endif