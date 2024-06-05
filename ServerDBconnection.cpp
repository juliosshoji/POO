/* 
Júlio Shoji Zotovici Kobayashi
Class ServerDBconnection
June, 2024
*/

#include "ServerDBconnection.hpp"

using namespace std;

ServerDBconnection::ServerDBconnection(){
    try
    {
        //Instanciando driver
        this->driver = sql::mariadb::get_driver_instance();
        //Configurando conexão
        sql::SQLString url("jdbc:mariadb://" + this->serverIP + ":" + this->serverPort + "/" + this->serverDatabase);
        sql::Properties properties({{"user", this->serverUser}, {"password", this->serverPassword}});
        //Estabelecendo conexão
        std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));
        this->connection = conn;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
};

sql::Connection* ServerDBconnection::getConnection() const{
    return this->connection;
};