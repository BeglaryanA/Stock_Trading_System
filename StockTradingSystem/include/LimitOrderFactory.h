#ifndef LIMITORDERFACTORY_H
#define LIMITORDERFACTORY_H

#include "OrderFactory.h"

class LimitOrderFactory : public OrderFactory {
public:
    Order createOrder(int traderId, StockSymbol stockSymbol, int quantity, double price) override;
};

#endif // LIMITORDERFACTORY_H