/* 
Júlio Shoji Zotovici Kobayashi
Class Controller
June, 2024
*/

#ifndef ABSTRACTSERIESDAO_HPP_

#define ABSTRACTSERIESDAO_HPP_

using namespace std;

class AbstractSeriesDAO 
    public:
        virtual void connectDB();

        virtual void includeRegister() = 0;
        virtual void recoveryRegister() = 0;
        virtual void editRegister() = 0;
        virtual void deleteRegister() = 0;

};

#endif