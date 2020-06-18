#include "OutOrder.h"

OutOrder::OutOrder(){};

OutOrder::OutOrder(const string n, const string b, const int d, const int m, const int y, const int dc, const int s, const string i) : Order(n,b,d,m,y,dc,s)
{
    setInfo(i);
}

void OutOrder::setInfo(const string i)
{
    this->info = i;
}

string OutOrder::getInfo() const
{
    return info;
}

void OutOrder::print(string const o)
{
    cout << endl;
    cout << "________________________________________" << endl;
    cout << "          OUTCOMING CASH WARRANT" << endl;
    cout << "Organization: " << o << endl;
    cout << "|" << getDocnumber() << "|" << getDay() << "." << getMonth() << "." << getYear() << endl;
    cout << "Received from " << getName() << endl;
    cout << "Base: " << getBase() << endl;
    cout << "Passport details: " << getInfo() << endl;
    cout << "Sum: " << getMoney() << endl;
    cout << "________________________________________" << endl;
    cout << endl;
}
