/* 
Júlio Shoji Zotovici Kobayashi
Class sysinfo
June, 2024
*/

#include "sysinfo.hpp"

using namespace std;

string sysinfo::getUniversity(){
    return this->universityName;
};
vector<string> sysinfo::getCreators(){
    this->creatorsNames;
};
string sysinfo::getProfessor(){
    return this->professorName;
};
string sysinfo::getInstitute(){
    return this->instituteName;
};
string sysinfo::getContact(){
    return this->contact;
};
string sysinfo::getCampus(){
    return this->campusAddres;
};
string sysinfo::getInfo(){
    string info = this->getUniversity() + "\n";
    for(string name : this->creatorsNames){
        info += "\n" + name;
    }
    info += this->getProfessor()+ "\n" + this->getInstitute() + "\n" + this->getContact() + "\n" + this->getCampus() + "\n";
    return info;
};
