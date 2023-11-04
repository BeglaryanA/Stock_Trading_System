#ifndef MARKETORDERFACTORY_H
#define MARKETORDERFACTORY_H

#include "OrderFactory.h"

class MarketOrderFactory : public OrderFactory {
public:
    Order createOrder(int traderId, StockSymbol stockSymbol, int quantity, double price) override;
};

#endif // MARKETORDERFACTORY_H