/* 
Júlio Shoji Zotovici Kobayashi
Class ServerDBConnection
June, 2024
*/

#ifndef SERVERDBCONNECTION_HPP_

#define SERVERDBCONNECTION_HPP_

#include <vector>
#include <iostream>
#include <string>
#include <mariadb/conncpp.hpp>
#include "Series.hpp"

using namespace std;

class ServerDBconnection {

    private:

		vector<Series *> serieMem;

    public:
		ServerDBconnection();
		virtual ~ServerDBconnection();
		void addSeries(Series* serie);
		void deleteSeries(Series* serie);
		void updateSeries(Series* serie);
		vector<Series* > getSeries();
		close();
};

#endif