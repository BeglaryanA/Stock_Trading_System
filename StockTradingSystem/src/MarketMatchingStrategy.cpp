#include "../include/MarketMatchingStrategy.h"

void MarketMatchingStrategy::executeOrder(Order &newOrder) {
    std::cout << "Matched market order for trader " << newOrder.getTraderId() << " for stock "
              << Helper::stockSymbolToString(newOrder.getStockSymbol()) << " at price " << newOrder.getPrice() << std::endl;
}