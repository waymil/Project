#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Order
{
    string name, base;
    int docnumber, money;
    int day, month, year;
protected:
    Order(const string n, const string b, const int d, const int m, const int y, const int dc, const int s);
public:
    Order();

    void setName(const string n);
    void setBase(const string b);
    bool setDay(const int d);
    bool setMonth(const int m);
    bool setYear(const int y);
    bool setDocnumber(const int dc);
    bool setMoney(const int s);

    string getName() const;
    string getBase() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    int getDocnumber() const;
    int getMoney() const;

    virtual void print(string const o) = 0;
};

#endif // ORDER_H_INCLUDED
