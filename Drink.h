/*

Final Project Milestone 5
Module: Drink
Filename: Drink.h
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

#ifndef SENECA_DRINK_H
#define SENECA_DRINK_H

#include "Billable.h"

namespace seneca {
	class Drink : public Billable
	{
		char m_size='0';
	public:
		virtual std::ostream& print(std::ostream& ostr = std::cout)const;
		virtual bool order();
		virtual bool ordered() const;
		virtual std::ifstream& read(std::ifstream& file);
		virtual double price() const;

	};

}
#endif // !SENECA_DRINK_H
