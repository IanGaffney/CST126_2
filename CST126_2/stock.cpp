//--------------------------------------------------------------------
// stock.cpp
//--------------------------------------------------------------------
#include "stdafx.h"
#include "stock.h""

Stock::Stock() :
	m_symbol{ "" }, m_name{ "" }, m_price{ 0.0 }, m_earnings{0.0}
{
}
Stock::Stock(std::string symbol, std::string name, double price, double earnings) :
	m_symbol{ symbol }, m_name{ name }, m_price{ price }, m_earnings{ earnings }
{
}

Stock::~Stock()
{
}

