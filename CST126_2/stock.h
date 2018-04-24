//--------------------------------------------------------------------
// stock.h
//     
//--------------------------------------------------------------------
#include <iostream>

class Stock {
public:
	Stock();
	Stock(std::string symbol, std::string name, double price, double earnings);
	~Stock();
	std::string getSymbol() const { return m_symbol; }
	std::string getName() const { return m_name; }
	double getPrice() const { return m_price; }
	double getEarnings() const { return m_earnings; }

private:
	std::string m_symbol;
	std::string m_name;
	double m_price;
	double m_earnings;
};