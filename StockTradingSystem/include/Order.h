#ifndef ORDRE_H
#define ORDRE_H

#include <iostream>
#include <string>
#include <vector>
#include "../constats/StockSymbol.h"


class Order {
public:
    Order();
    Order(int traderId, 
          StockSymbol stockSymbol, 
          int quantity, 
          double price);

    int getTraderId() const;
    StockSymbol getStockSymbol() const;
    int getQuantity() const;
    double getPrice() const;

private:
    int m_traderId;
    StockSymbol m_stockSymbol;
    int m_quantity;
    double m_price;
};

#endif // ORDRE_H