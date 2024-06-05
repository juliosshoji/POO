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
        const string addSeriesTxt = "insert into SERIES (SERIESName, SERIESType) values (?,?)";
        //Classe para conexao e transferencia de dados
        ServerDBconnection* serverConn;


    public:

        //Funcoes de request do menu

};



#endif