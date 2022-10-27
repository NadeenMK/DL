// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include<vector>
using namespace std;

unordered_map<char, int> char_map;
class studant {
public:
    string name;
    int id;
    int numOfgrades;
    vector<int> grades;
};
template<typename any>
class Dnode {
private:
    any data;
    Dnode<any>* next;
    Dnode<any>* prev;
    template<typename any> friend class doublyList;
};
template<typename any>
class doublyList {
private:
    Dnode<any>* header;
    Dnode<any>* trailer;
public:
    doublyList() {
        header = new Dnode<any>;
        trailer = new Dnode<any>;
        header->next = trailer;
        trailer->prev = header;
    }
    void addInorder(const any& item) {
        Dnode<any>* p = new Dnode<any>;
        p->data = item;
        p->next = header->next;
        header->next->prev = p;
        p->prev = header;
        header->next = p;
        //cout << "before Soring: " << p->data.name << endl;
       if (p->next != trailer) {
            sorting();
       }
    }

    bool compare(string c1, string c2) {
        for (int i = 0; i < min(c1.size(), c2.size()); i++) {
            if (char_map[c1[i]] == char_map[c2[i]])
                continue;
            return char_map[c1[i]] < char_map[c2[i]];
        }
        return c1.size() < c2.size();
    }

    void print() {
        double sum = 0;
        double avg;
        Dnode<any>* p = header->next;
        while (p != trailer) {
            std:: cout << "name:" << p->data.name << " ";
           std::cout << "ID:" << p->data.id<<" ";
           std:: cout <<"numof grades:" << p->data.numOfgrades<<" ";
           for (int i = 0; i < p->data.grades.size(); i++) {
               sum += p->data.grades[i];
           }
           avg = sum / p->data.numOfgrades;
           cout << "avarge: " << avg << endl;
            p = p->next;
            sum = 0;
        }
    }

    void sorting()
    {
        Dnode<any>* temp = header->next;

        while (temp != trailer)
        {
            Dnode<any>* temp2 = temp->next;
            while (temp2 != trailer)
            {
                    if (temp2->data.name < temp->data.name) // make comparison but im not sure wheteris logical or not 
                    {
                        string strtemp = "";
                        int i,num;
                        vector<int>g;
                        strtemp = temp->data.name; // name change
                        temp->data.name = temp2->data.name;
                        temp2->data.name = strtemp;
                        i = temp->data.id;
                        temp->data.id = temp2->data.id;
                        temp2->data.id =i;
                        num = temp->data.numOfgrades;
                        temp->data.numOfgrades = temp2->data.numOfgrades;
                        temp2->data.numOfgrades = num;
                        g = temp->data.grades;
                        temp->data.grades = temp2->data.grades;
                        temp2->data.grades = g;
                        /* 
                        temp->data.grades = temp2->data.grades;
                        temp2->data.grades = g.*/
                    }
                    temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }
    void printReverse() {
        Dnode<any>* p = trailer->prev;
        while (p != header) {
            std::cout << p->data.name << " ";
            std::cout << p->data.id << " ";
            std::cout << p->data.numOfgrades << " ";
            //std::cout << p->data.grades << endl;
            p = p->prev;
        }
    }
};


int main()
{
    doublyList<studant>Dl;
    studant s3;
    s3.name = "yaraa";
    s3.id = 250;
    s3.numOfgrades = 2;
    s3.grades.push_back(1);
    s3.grades.push_back(2);
    Dl.addInorder(s3);
    
    studant s;
    s.name = "manar";
    s.id = 100;
    s.numOfgrades = 3;
    s.grades.push_back(10);
    s.grades.push_back(20);
    s.grades.push_back(30);
    Dl.addInorder(s);
    studant s2;
    s2.name = "zebra";
    s2.id = 300;
    s2.numOfgrades = 2;
    s2.grades.push_back(4);
    s2.grades.push_back(8);

    Dl.addInorder(s2);
    Dl.print();
    Dl.printReverse();

    
    
}
