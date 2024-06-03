/* 
Júlio Shoji Zotovici Kobayashi
Class Controller
June, 2024
*/

#ifndef SERVERDBCONNECTION_HPP_

#define SERVERDBCONNECTION_HPP_

#include <string>
#include <mariadb/conncpp.hpp>

using namespace std;

class ServerDBconnection {
    private:

		sql::Driver *driver = NULL;
		sql::Connection *connection;
		string serverDatabase = "Si300A2024_11";
        string serverPort = "3306";
		string serverUser = "xxxxxxx";
		string serverPassword = "eT8GhbM1JQ";
        string serverIP = "143.106.243.64";

    public:
		ServerDBconnection();
		virtual ~ServerDBconnection();
		sql::Connection* getConnection() const;

};

#endif