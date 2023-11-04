#ifndef MARKETMATCHINGSTRATEGY_H
#define MARKETMATCHINGSTRATEGY_H

#include "MatchingStrategy.h"
#include "Helper.h"

class MarketMatchingStrategy : public MatchingStrategy {
public:
    void executeOrder(Order &newOrder) override;
};

#endif // MARKETMATCHINGSTRATEGY_H