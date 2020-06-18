#ifndef OUTORDER_H_INCLUDED
#define OUTORDER_H_INCLUDED

#include "Order.h"

class OutOrder : public Order
{
    string info;
public:
    OutOrder();
    OutOrder(const string n, const string b, const int d, const int m, const int y, const int dc, const int s, const string i);

    void setInfo(const string i);
    string getInfo() const;

    void print(string const o) override;
};

#endif // OUTORDER_H_INCLUDED
