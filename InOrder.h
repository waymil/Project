#ifndef INORDER_H_INCLUDED
#define INORDER_H_INCLUDED

#include "Order.h"

class InOrder : public Order
{
    float vat;
public:
    InOrder();
    InOrder(const string n, const string b, const int d, const int m, const int y, const int dc, const int s, const float v);

    bool setVat(const float v);
    float getVat() const;

    void print(string const o) override;
};

#endif // INORDER_H_INCLUDED
