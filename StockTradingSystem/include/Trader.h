#ifndef TRADER_H
#define TRADER_H

#include <string>
#include <vector>
#include <map>
#include "Order.h"
#include "OrderFactory.h"
#include "MatchingStrategy.h"
#include "Helper.h"

class Trader {
public:
    Trader(int id, std::string name, double initialBalance, OrderFactory& orderFactory, MatchingStrategy& matchingStrategy, std::vector<Order>& orderBook, std::mutex& mutex)
        : m_id(id), m_name(name), m_balance(initialBalance), m_orderFactory(orderFactory), m_matchingStrategy(matchingStrategy), m_orderBook(orderBook), m_mutex(mutex) {}

    double getBalance() const { return m_balance; }

    void sendOrder(const std::string& command, StockSymbol stockSymbol, int quantity, double price) {
        double orderCost = quantity * price;

        if (command == "sell") {
            int ownedStockQuantity = getOwnedStockQuantity(stockSymbol);
            if (quantity > ownedStockQuantity) {
                std::cout << "Insufficient stocks to sell." << std::endl;
                return; // Don't execute the order if there are not enough stocks to sell
            }
        }

        if (orderCost > m_balance) {
            std::cout << "Insufficient balance to execute the order." << std::endl;
            return; // Don't execute the order if there's not enough balance
        }

        Order order = m_orderFactory.createOrder(m_id, stockSymbol, quantity, price);
        m_matchingStrategy.executeOrder(order);

        if (order.getQuantity() > 0) {
            std::lock_guard<std::mutex> lock(m_mutex);
            m_orderBook.push_back(order);

            // Serialize and write the order to a JSON file
            Helper::saveOrderBookToJson(m_orderBook);

            // Update the owned stocks when selling
            if (command == "sell") {
                updateOwnedStocks(stockSymbol, -quantity);
            }

            // Deduct funds for buy orders or add funds for sell orders
            if (order.getQuantity() > 0) {
                if (Helper::stockSymbolToString(stockSymbol) == "AAPL") {
                    if (order.getStockSymbol() == StockSymbol::AAPL) {
                        if (order.getQuantity() > 0) {
                            m_balance -= orderCost;
                        } else {
                            m_balance += orderCost;
                        }
                    }
                } else if (Helper::stockSymbolToString(stockSymbol) == "GOOGL") {
                    if (order.getStockSymbol() == StockSymbol::GOOGL) {
                        if (order.getQuantity() > 0) {
                            m_balance -= orderCost;
                        } else {
                            m_balance += orderCost;
                        }
                    }
                } // Add similar conditions for other stock symbols
            }
        }
    }

    // Function to update owned stocks
    void updateOwnedStocks(StockSymbol stockSymbol, int quantity) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_ownedStocks[stockSymbol] += quantity;
    }

    // Function to get the quantity of owned stocks of a specific symbol
    int getOwnedStockQuantity(StockSymbol stockSymbol) {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_ownedStocks[stockSymbol];
    }

private:
    int m_id;
    std::string m_name;
    double m_balance;
    OrderFactory& m_orderFactory;
    MatchingStrategy& m_matchingStrategy;
    std::vector<Order>& m_orderBook;
    std::mutex& m_mutex;
    std::map<StockSymbol, int> m_ownedStocks; // Keep track of owned stocks
};

#endif // TRADER_H
