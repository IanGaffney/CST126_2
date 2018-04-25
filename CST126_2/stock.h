//--------------------------------------------------------------------
// stock.h
//     
//--------------------------------------------------------------------
#include <iostream>

#ifndef H_STOCK
#define H_STOCK

class Stock {
public:
	Stock();
	Stock(std::string symbol, std::string name, double price, double earnings);
	~Stock();
	std::string getSymbol() const { return m_symbol; }
	std::string getName() const { return m_name; }
	double getPrice() { return m_price; }
	double getEarnings() const { return m_earnings; }
	void adjustStockPrice(double adjustPercent) { m_price = (m_price / 100.0) * (100.0 + adjustPercent); }
	
	void printStock();

private:
	std::string m_symbol;
	std::string m_name;
	double m_price;
	double m_earnings;
	double getPricePerEarnings() { return m_price / fabs(m_earnings); }
};

#endif /* H_STOCK */