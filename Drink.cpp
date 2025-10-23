/*

Final Project Milestone 5
Module: Drink
Filename: Drink.cpp
Version 1.1
Author: Taejong Hwang
Revision History
-----------------------------------------------------------
Date      Reason
2025/03/29 Added Milestone 3 Requirements.
2025/04/10 Fixed print() price precision to two decimal places with std::fixed.
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "Drink.h"
#include "Menu.h"
#include "Utils.h"
#include <iomanip>
#include <fstream>

std::ostream& seneca::Drink::print(std::ostream& ostr) const
{
	char* name=nullptr;

	char size[4] = { '\0'};
	switch (m_size)
	{
	case 'S':
		ut.strcpy(size, "SML");
		break;
	case 'M':
		ut.strcpy(size, "MID");
		break;
	case 'L':
		ut.strcpy(size, "LRG");
		break;
	case 'X':
		ut.strcpy(size, "XLR");
		break;
	default:
		break;
	}

	ut.alocpy(name, static_cast<const char*>(*this));

	if (ordered()) {
		ostr << std::left << std::setw(25) << std::setfill('.') << name << "..." << size << ".."
			<< std::right << std::setw(7) << std::setfill(' ') << std::fixed << std::setprecision(2) << price();
	}

	else {
		ostr << std::left << std::setw(25) << std::setfill('.') << name << "..." << "....."
			<< std::right << std::setw(7) << std::setfill(' ') << std::fixed << std::setprecision(2) << price();
	}

	delete[] name;
	return ostr;
}

bool seneca::Drink::order()
{	
	//Menu(const char* title, const char* exitText = "Exit", size_t indentNum = 0, size_t indentSize = 3);
	Menu drinksMenu("Drink Size Selection","Back",3,3);

	drinksMenu << "Small" << "Medium" << "Larg" << "Extra Large";

	size_t choice = drinksMenu.select();
	switch (choice)
	{
	case 0:
		m_size = '0';
		break;
	case 1:
		m_size = 'S';
		break;
	case 2:
		m_size = 'M';
		break;
	case 3:
		m_size = 'L';
		break;
	case 4:
		m_size = 'X';
		break;
	default:
		break;
	}
	return m_size != '0' ? true:false;
}

bool seneca::Drink::ordered() const
{
	return m_size != '0' ? true : false;
}

std::ifstream& seneca::Drink::read(std::ifstream& file)
{
	char input[100];
	if(file.getline(input, 99, ',')){
		Billable::name(input);


		double price;
		file >> price;
		Billable::price(price);
		file.ignore(1000, '\n');
		m_size = '0';
	}

	return file;
}

double seneca::Drink::price() const
{
	double price = 0.0;

	switch (m_size)
	{
	case '0':
		price = Billable::price();
		break;
	case 'S':
		price = Billable::price()*0.5;
		break;
	case 'M':
		price =  Billable::price()*0.75;
		break;
	case 'L':
		price = Billable::price();
		break;
	case 'X':
		price = Billable::price() * 1.5;
	break;
	default:
		break;
	}

	return price;
}

