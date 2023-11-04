#include "../include/LimitMatchingStrategy.h"

LimitMatchingStrategy::LimitMatchingStrategy(std::vector<Order> &orders, std::mutex &mutex)
    : m_orders(orders), m_mutex(mutex) {}

void LimitMatchingStrategy::executeOrder(Order &newOrder) {
    std::lock_guard<std::mutex> lock(m_mutex);
    for (auto it = m_orders.begin(); it != m_orders.end();)
    {
        Order &existingOrder = *it;
        if (newOrder.getStockSymbol() == existingOrder.getStockSymbol() &&
            newOrder.getQuantity() > 0 && existingOrder.getQuantity() > 0 &&
            newOrder.getPrice() >= existingOrder.getPrice())
        {
            int matchedQuantity = std::min(newOrder.getQuantity(), existingOrder.getQuantity());
            std::cout << "Matched limit order for trader " << newOrder.getTraderId() << " for stock "
                      << Helper::stockSymbolToString(newOrder.getStockSymbol()) << " at price " << existingOrder.getPrice()
                      << " with quantity " << matchedQuantity << std::endl;
            newOrder = Order(newOrder.getTraderId(), newOrder.getStockSymbol(),
                             newOrder.getQuantity() - matchedQuantity, newOrder.getPrice());
            existingOrder = Order(existingOrder.getTraderId(), existingOrder.getStockSymbol(),
                                  existingOrder.getQuantity() - matchedQuantity, existingOrder.getPrice());
            if (existingOrder.getQuantity() == 0)
            {
                it = m_orders.erase(it);
            }
            else
            {
                ++it;
            }
        }
        else
        {
            ++it;
        }
    }
}