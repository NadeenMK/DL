// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include "Dlist.h"
using namespace std;


// takes array of char and character to look for then returns the index of it, else returns null
int indexOfChar(char token[], char character) {
    for (int i = 0; i < strlen(token); i++) {
        if (token[i] == character) {
            return i;
        }
    }
    return 0;
}
bool find(string s, string f) {
    string m;
    for (int i = 0, j = 0; i < s.length(), j < f.length(); i++,j++){
        if (s[i] == f[j]) {
            m += s[i];
        }
    }
    if (m.length() == f.length()) {
        if(m==f){
         return true;
        }
    }
    return false;
}

void extractData(char token[], studant &s) {
    string strToken(token);
    int expNumber = 0;
    string finalData; // represents the size of the exponent
    int nameIndex = indexOfChar(token, ':');
    if (find(strToken, "Name")){
        for (int i = nameIndex + 1; i < strlen(token); i++) {
            finalData += token[i];
        }
        s.name = finalData;
    }else if (find(strToken, "ID")){
        for (int i = nameIndex + 1; i < strlen(token); i++) {
            finalData += token[i];
        }
        s.id = stoi(finalData);
    }else if (find(strToken, "Grades")) {
        vector<int> grades;
        char* sPtr = token;
        char* sPtr2;
        string gradeFinalData;
        int nameIndex = indexOfChar(sPtr, ':');
        string newString;
        for (int i = nameIndex + 1; i < strlen(sPtr); i++) {
           if (sPtr[i] != '-') {
               newString.push_back(sPtr[i]);
           }
           else {
               grades.push_back(stoi(newString));
               newString = "";
           }
            gradeFinalData += sPtr[i];
        }
        grades.push_back(stoi(gradeFinalData));
        s.grades = grades;
        s.numOfgrades = grades.size();
    }
    
}

int main()
{
    doublyList<studant>Dl;
    ifstream myfile;
    myfile.open("studant file.txt");
    if (!myfile) {
        cout << "File not found";
        return 0;
    }
    while (myfile)
    {
        string line;
        studant student;
        getline(myfile, line);
        char* sArr = new char[line.length() +1];
        strcpy(sArr, line.c_str());
        char* sPtr;
        sPtr = strtok(sArr, ",");
        string N;
        int i, num;
        vector<int>g;
        while (sPtr != NULL)
        {
            string strToken(sPtr);
            extractData(sPtr, student);
            sPtr = strtok(NULL, ",");
        }

        if (student.name != "" || student.numOfgrades != 0 || student.grades.size() != 0)
            Dl.addInorder(student);
    }
    Dl.print();
    Dl.printReverse();
    return 0;
}
