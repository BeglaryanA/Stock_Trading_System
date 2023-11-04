#ifndef STOCKHELPER_H
#define STOCKHELPER_H
#include <map>
#include <string>

#include "../constats/StockSymbol.h"

class StockHelper {
public:
    StockHelper();
public:
    StockSymbol getStockSymbol(const std::string&);
private:
    void init();
private:
    std::map<std::string, StockSymbol> m_stockMapper;
};

#endif // STOCKHELPER_H