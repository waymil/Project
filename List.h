#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Contractor
{
    string name;
    int day, month, year, money;
    Contractor *next;
    friend class List;
};

class List
{
    Contractor *head;
    int count = 0;
public:
    List();
    ~List();

    void search(int num);
    void clear();
    void show();
    void savefile();
    void uploadfile();

    Contractor* add(string n, int d, int m, int y, int s);
    bool empty();

    string getName(Contractor *temp) const;
    int getDay(Contractor *temp) const;
    int getMonth(Contractor *temp) const;
    int getYear(Contractor *temp) const;
    int getMoney(Contractor *temp) const;
};

#endif // LIST_H_INCLUDED
