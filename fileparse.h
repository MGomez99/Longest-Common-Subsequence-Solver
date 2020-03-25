#ifndef PARSER_H
#define PARSER_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;

#define FILE1 "filex.txt"
#define FILE2 "filey.txt"
string getInput(string file){
    //reads file to get the string located on the first line
    ifstream infile(file);
    if(infile.good()){
        string line;
        getline(infile, line);
        infile.close();
        return line;
    }
    cout << "Error reading file content";
    return "";
}

#endif