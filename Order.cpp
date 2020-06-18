#include "Order.h"

Order::Order(){};

Order::Order(const string n, const string b, const int d, const int m, const int y, const int dc, const int s)
{
    setName(n);
    setBase(b);
    setDay(d);
    setMonth(m);
    setYear(y);
    setDocnumber(dc);
    setMoney(s);
}

void Order::setName(const string n)
{
    this->name = n;
}

void Order::setBase(const string b)
{
    this->base = b;
}

bool Order::setDay(const int d)
{
    if((d > 31)&&(d <= 0))
    {
        return false;
    }
    this->day = d;
    return true;
}

bool Order::setMonth(const int m)
{
    if((m > 12)&&(m <= 0))
    {
        return false;
    }
    this->month = m;
    return true;
}

bool Order::setYear(const int y)
{
    if((y > 2020)&&(y < 1980))
    {
        return false;
    }
    this->year = y;
    return true;
}

bool Order::setDocnumber(const int dc)
{
    if(dc <= 0)
    {
        return false;
    }
    this->docnumber = dc;
    return true;
}

bool Order::setMoney(const int s)
{
    if(s <= 0)
    {
        return false;
    }
    this->money = s;
    return true;
}

string Order::getName() const
{
    return name;
}

string Order::getBase() const
{
    return base;
}

int Order::getDay() const
{
    return day;
}

int Order::getMonth() const
{
    return month;
}

int Order::getYear() const
{
    return year;
}

int Order::getDocnumber() const
{
    return docnumber;
}

int Order::getMoney() const
{
    return money;
}
