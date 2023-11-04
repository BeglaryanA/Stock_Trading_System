#include "../include/LimitOrderFactory.h"

Order LimitOrderFactory::createOrder(int traderId, StockSymbol stockSymbol, int quantity, double price) {
    return Order(traderId, stockSymbol, quantity, price);
}