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
	double getPrice() { return m_price; }
	void setPrice(double price) { m_price = price; }
	void adjustStockPrice(double adjustPercent) { setPrice((m_price / 100.0) * (100.0 + adjustPercent)) ; }
	void printStock();

private:
	std::string m_symbol;
	std::string m_name;
	double m_price;
	double m_earnings;
	double getPricePerEarnings() { return m_price / fabs(m_earnings); }
};

#endif /* H_STOCK */