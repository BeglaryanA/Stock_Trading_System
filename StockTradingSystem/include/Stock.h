#ifndef STOKC_H
#define STOKC_H

#include <string>
#include <vector>
#include "Order.h"

class Stock {
public:
    Stock();
    Stock(const Stock&);
    Stock(Stock&&);
    ~Stock();
private:
    std::string symbol;   // Stock symbol (e.g., "AAPL" for Apple Inc.)
    double price;         // Current price per share
};

#endif // STOKC_H
