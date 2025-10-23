/*

Final Project Milestone 5
Module: Billable
Filename: Billable.cpp
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

#include <iostream>
#include <iomanip>
#include "constants.h"
#include "Utils.h"
#include "Billable.h"

void seneca::Billable::price(double value)
{
	m_price = value;
}

void seneca::Billable::name(const char* name)
{
	ut.alocpy(m_name, name);
}

seneca::Billable::Billable(){
	m_name = nullptr;
	m_price = -1.0;
}

seneca::Billable::Billable(const Billable& source) {

	ut.alocpy(m_name, source.m_name);
	m_price = source.m_price;
}

seneca::Billable& seneca::Billable::operator=(const Billable& source)
{
	ut.alocpy(m_name, source.m_name);
	m_price = source.m_price;

	return *this;
	// TODO: insert return statement here
}

seneca::Billable::~Billable()
{
	delete[] m_name;
}

double seneca::Billable::price() const
{
	return m_price;
}

seneca::Billable::operator const char* () const
{
	return m_name;
}

double seneca::operator+(double money, const Billable& B)
{
	return B.price() + money;
}

double& seneca::operator+=(double& money, const Billable& B)
{
	money += B.price();
	// TODO: insert return statement here
	return money;
}
