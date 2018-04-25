// CST126_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "stock.h"

//--------------------------------------------------------------------
bool openFile(ifstream& input_file);
void fillStockFromFile(Stock &, ifstream &);
void tokenizer(char line[], string & symbol, string & name_with_quotes, double & price, double & earnings);
size_t numOfStockInFile(ifstream &inFile);

int main(void)
{
	//  STUDENT TASK - define your variables
	Stock * stock = nullptr;
	ifstream stockFile;

	// STUDENT TASK - look these up and add a comment to each one to describe what they are doing
	cout.setf(ios::fixed);   // write floating-point values in fixed-point notation (cplusplus.com)
	cout.setf(ios::showpoint); // always show the decimal point
	cout.precision(2);  // max number of digits after the decimal point

	cout << "Welcome to the Stock Picker" << endl << endl;

	if (openFile(stockFile)) {
		size_t numberOfStock{ numOfStockInFile(stockFile) };
		stock = new Stock[numberOfStock];
		size_t stockNumber{ 0 };
		while (!stockFile.eof()) {
			fillStockFromFile(*(stock+stockNumber), stockFile);
			stockNumber++;
		}
		cout << endl;
		// STUDENT TASK - Loop through your stocks and print them
		for (int i{}; i < numberOfStock; i++) {
			stock[i].printStock();
		}
		cout << endl;
		cout << endl;
		cout << "If you had a 10% appreciation in price the values would be" << endl;
		// STUDENT TASK - Loop through your stocks and 1 - give them a 10% price increase 2 - print them
		for (int i{}; i < numberOfStock; i++)
		{
			stock[i].adjustStockPrice(10.0);
			stock[i].printStock();
		}

		delete [] stock;
	}

	return 0;
}

//--------------------------------------------------------------------
// Functions
//--------------------------------------------------------------------
//--------------------------------------------------------------------
// bool    OpenFile(file)
// Input:  file name (retrieved from user);
// Output: file pointer. 
//         Returns true if able to open file and false if 
//           unable to open file
//  Hint:  we've had hands on that did this.
bool openFile(ifstream& input_file)
{
	string filename{};
	// STUDENT TASK - Prompt the end user for the name of the file like in the sample output.  
	//cout << "Please enter the input file name including extension : " << flush;
	//cin >> filename;

	input_file = ifstream("quotes.csv");

	if (input_file.fail())
	{
		//  STUDENT TASK:  GIVE THE USER AN ERROR MESSAGE
		cout << "ERROR - Could not open file!" << endl;
		return false;
	}
	else
	{
		return true;
	}
}

//--------------------------------------------------------------------
//void fill_stock_from_file(Stock & s, ifstream & in_file)
void fillStockFromFile(Stock &stock, ifstream &in_file)  // temporary starting version.
{
	char line[81];

	//  STUDENT TASK - you'll need some variables.
	string symbol{}, name_with_quotes{};
	double price{}, earnings{};

	in_file.getline(line, 80);
	if (!in_file.eof()) {
		tokenizer(line, symbol, name_with_quotes, price, earnings);
	//  STUDENT TASK -  update your stock here
		stock = Stock(symbol, name_with_quotes, price, earnings);
	}
}

// count the number of stock provided in the file
size_t numOfStockInFile(ifstream &inFile)
{
	size_t stockNum = 0;
	char line[81];
	bool eofFound{false};
	// loop through each line in the file until we reach eof, counting each line
	while (!eofFound) {
		inFile.getline(line, 80);
		if (inFile.eof())
			eofFound = true;
		else {
			stockNum++;
		}
	}
	// found with google, to clear the eof flag and move pointer back to the begining of the file
	inFile.clear();
	inFile.seekg(0, ios::beg);
	return stockNum;
}

// pull stock information from the file
void tokenizer(char line[], string & symbol,string & name_with_quotes,double & price, double & earnings)
{
	string token;
	istringstream iss(line);

	std::getline(iss, symbol, ',');
	std::getline(iss, name_with_quotes, ',');
	std::getline(iss, token, ',');
	price = atof(token.c_str());
	std::getline(iss, token, ',');
	earnings = atof(token.c_str());
}