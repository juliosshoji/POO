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
    return this->creatorsNames;
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
    string info = this->getUniversity() + "\n" + "Alunos desenvolvedores: ";
    for(string name : this->creatorsNames){
        info += "\n" + name;
    }
    info += "\nProfessor responsavel: " +  this->getProfessor() + "\n" + this->getInstitute() + "\n" + this->getContact() + "\n" + this->getCampus() + "\n";
    return info;
};
