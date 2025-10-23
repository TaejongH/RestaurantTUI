/*

Final Project Milestone 5
Module: Food
Filename: Food.h
Version 1.0
Author: Taejong Hwang
Revision History
-----------------------------------------------------------
Date      Reason
2025/03/29 Added Milestone 3 Requirements.
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "Food.h"
#include "Menu.h"
#include "Utils.h"
#include <iomanip>
#include <fstream>


seneca::Food::Food()
{
	m_ordered = false;
}

seneca::Food::Food(const Food& source)
{
	if (this != &source) {

		m_child = false;
		Billable::name(source);
		Billable::price(source.Billable::price());

		m_ordered = source.m_ordered;
		m_child = source.m_child;
		ut.alocpy(m_customize, source.m_customize);
		
	}
}

seneca::Food& seneca::Food::operator=(const Food& source)
{
	m_child = false;
	Billable::name(source);
	Billable::price(source.Billable::price());

	m_ordered	= source.m_ordered;
	m_child		= source.m_child;
	ut.alocpy(m_customize,source.m_customize);
	// TODO: insert return statement here
	return *this;
}

seneca::Food::~Food()
{
	delete[] m_customize;
}

double seneca::Food::price() const
{
	return m_child ? Billable::price()*0.5 : Billable::price();
}

std::ostream& seneca::Food::print(std::ostream& ostr) const
{
	char* name = nullptr;


	ut.alocpy(name, static_cast<const char*>(*this));


	if (ordered()) {
		ostr << std::left << std::setw(25) << std::setfill('.') << name << "..." << (m_child ? "Child" : "Adult")
			<< std::right << std::setw(7) << std::setfill(' ') << std::fixed << std::setprecision(2) << price();

	}

	else {
		ostr << std::left << std::setw(25) << std::setfill('.') << name << "..." << "....."
			<< std::right << std::setw(7) << std::setfill(' ') << std::fixed << std::setprecision(2) << price();
	}

	if (m_customize !=nullptr && &ostr == &std::cout) {
		ostr << " >> ";
		for (int i = 0; i < ut.strlen(m_customize) && i<30; i++)
		{
			ostr << m_customize[i];
		}

	}
	delete[] name;
	return ostr;
}

bool seneca::Food::order()
{
	//Menu(const char* title, const char* exitText = "Exit", size_t indentNum = 0, size_t indentSize = 3);
	Menu drinksMenu("Food Size Selection", "Back", 3, 3);
	drinksMenu << "Adult" << "Child";
	size_t choice = drinksMenu.select();

	char customize[100] = {'\0'};
	//CHANGE TO IF STATEMENTS
	if (choice == 0) {
		m_ordered = false;
		delete[] m_customize;
		m_customize = nullptr;
	}
	else if (choice == 1 || choice == 2) {

		//child = 2 -1   adult = 1-1
		choice == 1 ? m_child = 0 : m_child = 1;
		m_ordered = true;


		std::cout << "Special instructions" << std::endl;
		std::cout << "> ";
		std::cin.getline(customize, 100);
		if (customize[0] == '\0') {
			delete[] m_customize;
			m_customize = nullptr;
		}
		else {
			ut.alocpy(m_customize, customize);
		}
	}
	
	return m_ordered;
}

bool seneca::Food::ordered() const
{
	return m_ordered;
}

std::ifstream& seneca::Food::read(std::ifstream& file)
{
	char input[100];
	if (file.getline(input, 99, ',')) {
		Billable::name(input);


		double price;
		file >> price;
		Billable::price(price);
		file.ignore(1000, '\n');
		delete[] m_customize;
		m_customize = nullptr;
		m_ordered = false;
		m_child = false;
	}
	// TODO: insert return statement here
	return file;
}
