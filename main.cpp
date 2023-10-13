#include <iostream>
#include <vector>
#include <string>

/* enum for type of the order in oderBook*/
enum class OrderBookType
{
    bid,
    ask
};

/* OrderBookEntry  class to hold one entry fron oderBook*/
class OrderBookEntry 
{
public: 
    /** Create a new OrderBookEntry */
    OrderBookEntry(std::string _timestamp, std::string _product, OrderBookType _oderType, double _price, double _amount);

    std::string timestamp;
    std::string product;
    OrderBookType oderType;
    double price;
    double amount;
}; 

/* Implimentation of constructre */
OrderBookEntry::OrderBookEntry(std::string _timestamp, std::string _product, OrderBookType _oderType, double _price, double _amount)
    : timestamp(_timestamp),
      product(_product),
      oderType(_oderType),
      price(_price),
      amount(_amount)
{
}

/* Calculating some basic stats by iterating OrderBookEntry*/
double computeAveragePrice(std::vector<OrderBookEntry> &entries)
{
    double avg = 0;
    double total = 0;
    for (OrderBookEntry &e : entries)
    {
        total += e.price;
    }
    avg = total / entries.size();
    return avg;
}
double computeLowPrice(std::vector<OrderBookEntry> &entries)
{
    double lowPrice = 0;
    for (OrderBookEntry &e : entries)
    {
        if (lowPrice > e.price)
        {
            lowPrice = e.price;
        }
    }
    return lowPrice;
}
double computeHighPrice(std::vector<OrderBookEntry> &entries)
{
    double highPrice = 0;
    for (OrderBookEntry &e : entries)
    {
        if (highPrice < e.price)
        {
            highPrice = e.price;
        }
    }
    return highPrice;
}


int main()
{

    /*
    std::vector<std::string> timeStamps;
    std::vector<std::string> products;
    std::vector<OrderBookType> orderTypes;
    std::vector<double> prices;
    std::vector<double> amounts;

    timeStamps.push_back("2020/03/17 17:01:24.884492");
    products.push_back("ETH/BTC");
    orderTypes.push_back(OrderBookType::bid);
    prices.push_back(0.02187308);
    amounts.push_back(7.44564869);

    std::cout << "First :timeStamps: " << timeStamps[0] << std::endl;
    std::cout << "First:products: "  << products[0] << std::endl;
    std::cout << "First:orderTypes: " << prices[0] << std::endl;
    std::cout << "First:prices: " << prices[0] << std::endl;
    std::cout << "First:amounts: " << amounts[0] << std::endl;
*/
    /*while (true)
    {
        printMenu();

        int userOption = 0;

        userOption = getUserOption();

        processUserOption(userOption);

        std::cout << std::endl
                  << std::endl;
    }*/

    // create an object of type OrderBookEntry
    // with a variable name of obe1
    // OrderBookEntry obe1{"2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid, 0.02187308, 7.44564869};
    // OrderBookEntry obe2;
    // OrderBookEntry obe2{"2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid, 0.03387308, 7.55564869};
    OrderBookEntry obe1{"2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid, 0.05, 7.55564869};
    OrderBookEntry obe2{"2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid, 0.07, 7.55564869};

    std::vector<OrderBookEntry> entries;
    entries.push_back(obe1);
    entries.push_back(obe2);

    // for (OrderBookEntry &e : entries)
    // {
    //     std::cout << e.price << std::endl;
    // }
    double avg = computeAveragePrice(entries);
    std::cout << "Average = " << avg << std::endl;
}