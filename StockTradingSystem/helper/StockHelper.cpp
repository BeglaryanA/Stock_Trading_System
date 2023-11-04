#include "../include/StockHelper.h"

StockHelper::StockHelper() {
    init();
}

void StockHelper::init() {
    m_stockMapper["AAPL"] = StockSymbol::AAPL;
    m_stockMapper["GOOGL"] = StockSymbol::GOOGL;
    m_stockMapper["MSFT"] = StockSymbol::MSFT;
    m_stockMapper["AMZN"] = StockSymbol::AMZN;
    m_stockMapper["TSLA"] = StockSymbol::TSLA;
    m_stockMapper["FB"] = StockSymbol::FB;
    m_stockMapper["NVDA"] = StockSymbol::NVDA;
    m_stockMapper["NFLX"] = StockSymbol::NFLX;
    m_stockMapper["INTC"] = StockSymbol::INTC;
    m_stockMapper["AMD"] = StockSymbol::AMD;
}


StockSymbol StockHelper::getStockSymbol(const std::string& sybmol) {
    return m_stockMapper[sybmol];
}