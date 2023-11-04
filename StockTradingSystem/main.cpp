#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>
#include <fstream>
#include "./include/LimitOrderFactory.h"
#include "./include/MarketOrderFactory.h"
#include "./include/Trader.h"
#include "./include/MarketMatchingStrategy.h"
#include "./include/LimitMatchingStrategy.h"
#include "./include/Helper.h"
#include "./include/StockHelper.h"

int main() {
    StockHelper stockHelper;
    MarketOrderFactory marketOrderFactory;
    LimitOrderFactory limitOrderFactory;
    std::vector<Order> orderBook;
    std::mutex orderBookMutex;

    MarketMatchingStrategy marketMatchingStrategy;
    LimitMatchingStrategy limitMatchingStrategy(orderBook, orderBookMutex);

    // Create traders with initial balances
    Trader trader1(1, "Trader1", 10000.0, marketOrderFactory, marketMatchingStrategy, orderBook, orderBookMutex);
    Trader trader2(2, "Trader2", 10000.0, limitOrderFactory, limitMatchingStrategy, orderBook, orderBookMutex);

    // Initialize owned stocks for each trader
    trader1.updateOwnedStocks(StockSymbol::AAPL, 10); // Trader 1 owns 10 AAPL stocks initially
    trader2.updateOwnedStocks(StockSymbol::GOOGL, 5); // Trader 2 owns 5 GOOGL stocks initially

    while (true) {
        std::cout << "Enter command (buy/sell symbol quantity price, e.g., buy AAPL 10 150.0 or sell AAPL 5 155.0): ";
        std::string command;
        std::cin >> command;
        if (command == "buy" || command == "sell") {
            StockSymbol stockSymbol;
            int quantity;
            double price;
            std::string symbolStr;
            std::cin >> symbolStr >> quantity >> price;

            stockSymbol = stockHelper.getStockSymbol(symbolStr);
            Trader& trader = (command == "buy") ? trader1 : trader2;
            trader.sendOrder(command, stockSymbol, quantity, price);
        } else {
            std::cout << "Invalid command. Please use 'buy' or 'sell'." << std::endl;
        }
    }

    return 0;
}
