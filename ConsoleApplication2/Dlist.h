#include"Dnode.h"
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
        if (p->next != trailer) {
            sorting();
        }
    }
    void print() {
        double sum = 0;
        double avg;
        Dnode<any>* p = header->next;
        while (p != trailer) {
            std::cout << "name:" << p->data.name << " ";
            std::cout << "ID:" << p->data.id << " ";
            std::cout << "numof grades:" << p->data.numOfgrades << " ";
            for (int i = 0; i < p->data.grades.size(); i++) {
                sum += p->data.grades[i];
            }
            avg = sum / p->data.numOfgrades;
            std::cout << "avarge: " << avg << std::endl;
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
                if (temp2->data.name < temp->data.name)
                {
                    std::string strtemp = "";
                    int i, num;
                    std::vector<int>g;
                    strtemp = temp->data.name;
                    temp->data.name = temp2->data.name;
                    temp2->data.name = strtemp;
                    i = temp->data.id;
                    temp->data.id = temp2->data.id;
                    temp2->data.id = i;
                    num = temp->data.numOfgrades;
                    temp->data.numOfgrades = temp2->data.numOfgrades;
                    temp2->data.numOfgrades = num;
                    g = temp->data.grades;
                    temp->data.grades = temp2->data.grades;
                    temp2->data.grades = g;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }
    void printReverse() {
        Dnode<any>* p = trailer->prev;
        std::cout << std::endl << "Reversing The List" << std::endl << std::endl;
        while (p != header) {
            std::cout << "Name: " << p->data.name << " ";
            std::cout << "ID: " << p->data.id << " ";
            std::cout << "Grades: " << " ";
            for (int i = 0; i < p->data.grades.size(); i++) {
                std::cout << p->data.grades[i] << "  ";
            }
            std::cout << "Number Of Grades: " << p->data.numOfgrades << " ";
            p = p->prev;
        std::cout << std::endl;
        }
    }
};
