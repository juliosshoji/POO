/*
Júlio Shoji Zotovici Kobayashi
Class SysInfo
June, 2024
*/
#ifndef SYSINFO_HPP_

#define SYSINFO_HPP_

#include <string>
#include <vector>

using namespace std;

class sysinfo{

    private:
        string universityName = "UNICAMP - Universidade Estadual de Campinas";
        //Adicionar seus nome aqui
        vector<string> creatorsNames {"Júlio Shoji Zotovici Kobayashi"}; 
        string professorName = "Professor Doutor Andre F. Angelis";
        string instituteName = "FT - Faculdade de Tecnologia";
        string contact = "j245708@dac.unicamp.br";
        string campusAddres = "R. Paschoal Marmo, 1888 - Jardim Nova Italia, Limeira - SP, 13484-332";
        string getUniversity();
        vector<string> getCreators();
        string getProfessor();
        string getInstitute();
        string getContact();
        string getCampus();
    public:
        string getInfo();
};

#endif