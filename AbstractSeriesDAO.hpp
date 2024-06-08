/* 
Júlio Shoji Zotovici Kobayashi
Class AbstractSeriesDAO
June, 2024
*/

#ifndef ABSTRACTSERIESDAO_HPP_

#define ABSTRACTSERIESDAO_HPP_

#include "Series.hpp"
using namespace std;

class AbstractSeriesDAO {
    public:
        AbstractSeriesDAO();
        virtual void adduser() = 0;
        virtual Series* getSeriesbyID() = 0;
        virtual void updateSeries() = 0;
        virtual void deleteSeries() = 0;

};

#endif