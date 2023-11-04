#ifndef MATCHINGSTRATEGY_H
#define MATCHINGSTRATEGY_H
#include <mutex>
#include <algorithm>

#include "Order.h"


class MatchingStrategy {
public:
    virtual void executeOrder(Order& newOrder) = 0;
    virtual ~MatchingStrategy() = default;
};


#endif // MATCHINGSTRATEGY_H