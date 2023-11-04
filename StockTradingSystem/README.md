Stock Trading System
Overview
The Stock Trading System is a C++ application that simulates a stock exchange where multiple traders can buy and sell stocks. The system is designed with the following key features:

Object-Oriented Design: The application follows good object-oriented design principles. It models entities like Trader, Stock, and OrderBook as separate classes.

Design Patterns:

Factory Method Pattern: Used for creating orders of different types (Market Order, Limit Order).
Strategy Pattern: Used for implementing matching algorithms for orders.
Multi-Threading: The order book is implemented in a multi-threaded fashion using C++ threads to simulate multiple traders sending buy/sell orders concurrently.

STL Containers: The application leverages C++ Standard Library (STL) containers like std::vector, std::map for efficient data management and algorithms.

Classes and Components
Trader
Represents a trader participating in the stock exchange.
Stores trader-specific information such as ID, name, balance, and owned stocks.
Can send buy or sell orders to the market.
Order
Represents an order to buy or sell a specific quantity of a stock at a specified price.
Contains information about the trader, stock symbol, quantity, and price.
OrderFactory
Abstract base class for creating different types of orders.
Derived classes include MarketOrderFactory and LimitOrderFactory.
MatchingStrategy
Abstract base class for implementing different matching algorithms for orders.
Derived classes include MarketMatchingStrategy and LimitMatchingStrategy.
MarketOrder
A type of order that is executed immediately at the current market price.
LimitOrder
A type of order that specifies a price at which the trader is willing to buy or sell, and it may not be executed immediately.
OrderBook
Represents the collection of all active orders in the market.
Multi-threaded to allow concurrent access by multiple traders.
Usage
Compile and run the application.

Traders can enter commands in the following format:

Buy: buy [symbol] [quantity] [price] (e.g., buy AAPL 10 150.0)
Sell: sell [symbol] [quantity] [price] (e.g., sell AAPL 5 155.0)
The application processes the orders and matches them based on the chosen strategy (Market or Limit).

Traders are notified of matched orders, and the order book is updated.

Makefile
The provided Makefile simplifies the build process of the Stock Trading System. Here's a breakdown of what the Makefile does:

Compiler and Flags: It defines the C++ compiler (g++) and compiler flags, including the C++11 standard, as well as enabling warnings.

Directories: Specifies project directories such as SRC_DIR, OBJ_DIR, BIN_DIR, and INCLUDE_DIR.

Source Files: It identifies source files in the SRC_DIR, HELPER_DIR, and MAIN_FILE, and generates object files (OBJ_FILES) for these source files.

Target Binary: The main target is the stock_trading_system binary.

Main Target: It compiles the target binary using the object files.

Build Object Files: Rules for building object files for both source files and helper files are defined.

Create Directories: It creates the necessary directories (OBJ_DIR and BIN_DIR) if they do not exist.

Cleaning: A clean target is defined to remove build artifacts when make clean is executed.

1. **Navigate to Project Directory**: Open a terminal and navigate to the project directory where the Makefile and source files are located.

2. **Compile the Program**: Run the following command to compile the program:
   ```bash
   make

Execute the Program: Once the compilation is successful, you can execute the program with
the following command:
  **./bin/stock_trading_system**


Error Handling
The application performs error checking to ensure that traders have sufficient funds and stocks to execute orders.
If there are issues, such as insufficient funds or stocks, the application displays error messages and rejects the order.
Data Persistence
The order book is periodically serialized and saved to a JSON file (order_book.json) for data persistence.
Dependencies
The project uses the nlohmann JSON library for JSON serialization and deserialization.
Future Enhancements
Additional stock symbols and trading features can be added.
Improved error handling and validation can be implemented.
User-friendly interfaces (GUI or web) can be integrated for better usability.