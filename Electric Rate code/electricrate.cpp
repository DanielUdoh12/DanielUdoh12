#include <iostream>
#include <map>
#include <iterator>
#include <fstream>
#include <sstream>


#include "rates.h"

using namespace std;

int main(){

    ifstream ratesFile;
    ratesFile.open("iouzipcodes2015.csv");
    map<string, Provider> ratesHash; // map to store zip as key and provider info class as value
    map<string, Provider>:: iterator it;

    string line = "";
    // skip first line of csv file
    while(getline(ratesFile, line)) // loop to parse data from csv into hashMap
    {
        string zip;
        string eiaid;
        string utilityName;
        string state;
        string service;
        string ownership;
        string commRate;
        string indRate;
        string resRate;

        stringstream inputString(line);
        getline(inputString, zip, ',');
        getline(inputString, eiaid, ',');
        getline(inputString, utilityName, ',');
        getline(inputString, state, ',');
        getline(inputString, service, ',');
        getline(inputString, ownership, ',');
        getline(inputString, commRate, ',');
        getline(inputString, indRate, ',');
        getline(inputString, resRate, ',');

        Provider currentProvider(utilityName, commRate, indRate, resRate); // create provider object for current line of the csv    
        ratesHash.insert(pair<string, Provider>(zip, currentProvider)); // put provider object into hash map using the zip code as the key
        
    }

    string input;
    
    do
    {
        cout << "Enter zip code (enter 0 to stop): " << endl;
        cin >> input;

        if (input == "0")
        {
            break;
        }
        it = ratesHash.find(input);

        if (it == ratesHash.end()){
            cout << "Zip code not found" << endl; // zip code not in hash table
            
        }
        else{
            it->second.displayInfo(); // calls display function to output relevant info from zip code
            cout << endl;
    } 
    }while (input != "0");

    return 0;
}
