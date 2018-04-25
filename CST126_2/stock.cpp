//--------------------------------------------------------------------
// stock.cpp
//--------------------------------------------------------------------
#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "stock.h"

using namespace std;

Stock::Stock() :
	m_symbol{}, m_name{}, m_price{}, m_earnings{}
{
}
Stock::Stock(std::string symbol, std::string name, double price, double earnings) :
	m_symbol{ symbol }, m_name{ name }, m_price{ price }, m_earnings{ earnings }
{
}

Stock::~Stock()
{
}

void Stock::printStock()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.setf(ios::left);
	cout.precision(2);
	cout << setw(4) << m_symbol << " "
		 << setw(25) << m_name << " "
		 << "Price: " << setw(9) << m_price << " "
		 << "Earnings " << setw(6) << m_earnings << " "
		 << "P/E " << getPricePerEarnings() << "\n";
}