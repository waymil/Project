#include "InOrder.h"

InOrder::InOrder(){};

InOrder::InOrder(const string n, const string b, const int d, const int m, const int y, const int dc, const int s, const float v) : Order(n,b,d,m,y,dc,s)
{
    setVat(v);
}

bool InOrder::setVat(const float v)
{
    if(v < 0)
    {
        return false;
    }
    this->vat = v;
    return true;
}

float InOrder::getVat() const
{
    return vat;
}

void InOrder::print(string const o)
{
    cout << endl;
    cout << "________________________________________" << endl;
    cout << "          INCOMING CASH WARRANT" << endl;
    cout << "Organization: " << o << endl;
    cout << "|" << getDocnumber() << "|" << getDay() << "." << getMonth() << "." << getYear() << endl;
    cout << "Received from " << getName() << endl;
    cout << "Base: " << getBase() << endl;
    cout << "Including ";
    if (getVat() == 0)
    {
        cout << "without VAT" << endl;
    }
    else cout << getVat() << endl;
    cout << "Sum: " << getMoney() << endl;
    cout << "________________________________________" << endl;
    cout << endl;
}
