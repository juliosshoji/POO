/* 
Júlio Shoji Zotovici Kobayashi
Class operation
June, 2024
*/

#include "operation.hpp"

using namespace std;


operation::operation(vector<string> &questions, string title, string pattern) : menu(title,pattern){
    this->questions = questions;
};

void operation::setWidth(){
    string bigquestion = this->questions[0];
    for (string questions : this->questions)
    {
        if(questions.length() > bigquestion.length()) {bigquestion = questions;}
    }
    if(this->title.length() > bigquestion.length())
        this->width = this->title.length();
    else
        this->width = bigquestion.length() * 3;
};
vector<string> operation::doUserQA(){
    this->drawLine();
    cout << setw((this->width/2)+(this->title.length()/2)) << endl << this->title << endl;
    this->drawLine();
    vector<string> answers;
    string singleAnswer;
    for (size_t i = 0; i < this->questions.size(); i++){
        cout << endl;
        cout << setw(this->width/this->title.length()) << this->questions[i] << endl;
        cin >> singleAnswer;
        answers.push_back(singleAnswer);
    }
    this->drawLine();

    return answers;
};

