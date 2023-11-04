#include "../include/MarketOrderFactory.h"

Order MarketOrderFactory::createOrder(int traderId, StockSymbol stockSymbol, int quantity, double price) {
    return Order(traderId, stockSymbol, quantity, price);
}