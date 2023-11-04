#ifndef LIMITMATHCINGSTRATEGY_H
#define LIMITMATHCINGSTRATEGY_H

#include "MatchingStrategy.h"
#include "Helper.h"

class LimitMatchingStrategy : public MatchingStrategy {
public:
    LimitMatchingStrategy(std::vector<Order>& orders, std::mutex& mutex);
public:
    void executeOrder(Order& newOrder) override;

private:
    std::vector<Order>& m_orders;
    std::mutex& m_mutex;
};
#endif // LIMITMATHCINGSTRATEGY_H