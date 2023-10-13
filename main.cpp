#include <iostream>
#include <vector>
#include <string>

void printMenu()
{
    std::cout << "1: Print help" << std::endl;
    std::cout << "2: Print exchange stats" << std::endl;
    std::cout << "3: Place an ask" << std::endl;
    std::cout << "4: Place a bid" << std::endl;
    std::cout << "5: Print wallet" << std::endl;
    std::cout << "6: Continue" << std::endl;
    std::cout << "----" << std::endl;
}

int getUserOption()
{
    int userOption;
    std::cout << "Type in 1-6" << std::endl;
    std::cin >> userOption;

    return userOption;
}

void printErrorMsg()
{
    std::cout << "No way!" << std::endl;
    std::cout << "Type in 1-6" << std::endl;
}

void printHelp()
{
    std::cout << "Help - choose options from the menu" << std::endl;
    std::cout << "and follow the on screen instructions." << std::endl;
}

void printMarketStats()
{
    std::cout << "Exchange stats - waite..." << std::endl;
    std::cout << "I have to finish other lesson to get this :)" << std::endl;
}

void enterAsk()
{
    std::cout << "Place an ask - are you sure!!!" << std::endl;
    std::cout << "Can I finish other lessons before this :)" << std::endl;
}

void enterBid()
{
    std::cout << "Place a bid - Are you serious?" << std::endl;
    std::cout << "Investments are subject to market risks :) :) " << std::endl;
}

void printWallet()
{
    std::cout << "Wallet - I can't believe it! its zeros now  " << std::endl;
    std::cout << "Don't show up this to any one else :D" << std::endl;
}

void gotoNextTimeframe()
{
    std::cout << "Continue - Why not! " << std::endl;
    std::cout << "You carry on..." << std::endl;
}

void processUserOption(int userOption)
{
    if ((userOption < 1) || (userOption > 6))
    {
        printErrorMsg();
    }
    if (userOption == 1)
    {
        printHelp();
    }
    if (userOption == 2)
    {
        printMarketStats();
    }
    if (userOption == 3)
    {
        enterAsk();
    }
    if (userOption == 4)
    {
        enterBid();
    }
    if (userOption == 5)
    {
        printWallet();
    }
    if (userOption == 6)
    {
        gotoNextTimeframe();
    }
}

enum class OrderBookType
{
    bid,
    ask
};

class OrderBookEntry // this is the name of the class
{
public: // parts of the class that can be seen from outside
    /** Create a new OrderBookEntry with the price
    * set to the sent value
    */
    OrderBookEntry(std::string _timestamp, std::string _product, OrderBookType _oderType, double _price, double _amount);

    std::string timestamp;
    std::string product;
    OrderBookType oderType;
    double price;
    double amount;
}; // note the semi-colon

OrderBookEntry::OrderBookEntry(std::string _timestamp, std::string _product, OrderBookType _oderType, double _price, double _amount)
    :   timestamp(_timestamp),
        product(_product),
        oderType(_oderType),
        price(_price),
        amount(_amount)
{
}

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
        if(lowPrice > e.price)
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
        if(highPrice < e.price)
        {
            highPrice = e.price;
        }
    }    
    return highPrice;
}
double computePriceSpread(std::vector<OrderBookEntry> &entries)
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
    std::cout << "Average = "<< avg << std::endl;
}