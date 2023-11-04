#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <string>
#include <fstream>
#include "Order.h"
#include "../constats/StockSymbol.h"

class Helper {
public:
    static void saveOrderBookToJson(const std::vector<Order>& orderBook);
    static std::string stockSymbolToString(StockSymbol symbol);
};

#endif // HELPER_H