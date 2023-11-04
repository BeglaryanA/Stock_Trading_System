#include "../include/Helper.h"
#include "../include/Json.hpp"
using json = nlohmann::json;

void Helper::saveOrderBookToJson(const std::vector<Order>& orderBook) {
    nlohmann::json orderBookJson;

    for (const auto& order : orderBook) {
        nlohmann::json orderJson = {
            {"TraderId", order.getTraderId()},
            {"StockSymbol", stockSymbolToString(order.getStockSymbol())},
            {"Quantity", order.getQuantity()},
            {"Price", order.getPrice()}
        };

        orderBookJson.push_back(orderJson);
    }

    // Save the order book to a JSON file
    std::ofstream outFile("order_book.json");
    outFile << orderBookJson.dump(4);  // The "4" parameter is for pretty-printing JSON
    outFile.close();
}


std::string Helper::stockSymbolToString(StockSymbol symbol) {
    switch (symbol) {
        case StockSymbol::AAPL: return "AAPL";
        case StockSymbol::GOOGL: return "GOOGL";
        case StockSymbol::MSFT: return "MSFT";
        case StockSymbol::AMZN: return "AMZN";
        case StockSymbol::TSLA: return "TSLA";
        case StockSymbol::FB: return "FB";
        case StockSymbol::NVDA: return "NVDA";
        case StockSymbol::NFLX: return "NFLX";
        case StockSymbol::INTC: return "INTC";
        case StockSymbol::AMD: return "AMD";
    }
    return "UNKNOWN";
}