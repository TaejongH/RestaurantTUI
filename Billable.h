/*

Final Project Milestone 5
Module: Billable
Filename: Billable.h
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
#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H
#include <iostream>


namespace seneca {
	class Billable{
		char* m_name=nullptr;
		double m_price;

	protected:
		void price(double value);
		void name(const char* name);
	public:
		Billable();
		Billable(const Billable& source);
		Billable& operator=(const Billable& source);
		virtual ~Billable();

		virtual double price() const;
		virtual std::ostream& print(std::ostream& ostr = std::cout)const = 0;
		virtual bool order() = 0;
		virtual bool ordered() const = 0;
		virtual std::ifstream& read(std::ifstream& file) = 0;
		operator const char*() const;


	};
	double operator+(double money, const Billable& B);
	double& operator+=(double& money, const Billable& B);
}


#endif // !SENECA_BILLABLE_H
