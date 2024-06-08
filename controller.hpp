/* 
Júlio Shoji Zotovici Kobayashi
Class Controller
June, 2024
*/

#ifndef CONTROLLER_HPP_

#define CONTROLLER_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "menu.hpp"
#include "sysinfo.hpp"
#include "SeriesDAO.hpp"

using namespace std;

class controller {

    private:
    public:
        controller();
        ~controller();
        void start();
        bool doAction(string menuTitle, vector<string> nameItens, vector<void (controller:: *)()> actions);
        void menuReport();
        void menuSeries();
        void menuHelp();
        void menuInfo();

        void includeSeries();
        void recoverySeries();
        void editSeries();
        void deleteSeries();

        void titleReport();
        void channelReport();
        void yearReport();
        void gradeReport();

        SeriesDAO SeriesDB; 
};

#endif
