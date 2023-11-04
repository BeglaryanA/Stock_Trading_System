#ifndef ORDERFACTORY_H
#define ORDERFACTORY_H

#include "Order.h"

class OrderFactory {
public:
    virtual Order createOrder(int traderId, StockSymbol stockSymbol, int quantity, double price) = 0;
    virtual ~OrderFactory() = default;
};

#endif // ORDERFACTORY_H