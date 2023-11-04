#include "../include/Order.h"

Order::Order()
: m_traderId{}, m_stockSymbol(), m_quantity{}, m_price{} {}

Order::Order(int traderId, StockSymbol stockSymbol, int quantity, double price)
: m_traderId(traderId), m_stockSymbol(stockSymbol), m_quantity(quantity), m_price(price) {}

int Order::getTraderId() const
{
    return m_traderId;
}

StockSymbol Order::getStockSymbol() const
{
    return m_stockSymbol;
}

int Order::getQuantity() const
{
    return m_quantity;
}

double Order::getPrice() const
{
    return m_price;
}