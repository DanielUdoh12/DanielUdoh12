#ifndef rates_H
#define rates_H

#include <string>
#include <iostream>

using namespace std;

class Provider{

    public:
    
        Provider(string name, string comm_rate, string ind_rate, string res_rate); // constructor
        string getName(); // function to get utility name
        string getComm(); // functin to get commerical rate
        string getInd(); // function to get industrial rate
        string getRes(); // function to get residential rate
        void displayInfo(); // function to display all relevant info of provider
        
    
    private:
        string name;
        string commRate;
        string indRate;
        string resRate; 
        
};

Provider::Provider(string name, string comm_rate, string ind_rate, string res_rate){

    this->name = name;
    this->commRate = comm_rate;
    this->indRate = ind_rate;
    this->resRate = res_rate;
}

string Provider::getName(){
    return name;
}

string Provider::getComm(){
    return commRate;
}

string Provider::getInd(){
    return indRate;
}

string Provider::getRes(){
    return resRate;
}

void Provider::displayInfo(){

    cout << "The name of the provider is: " << name << endl;
    cout << "Commercial Rate: " << commRate;
    cout << "Industrial Rate: " << indRate;
    cout << "Residential Rate: " << resRate; 
}


#endif
