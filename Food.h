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
#include "Billable.h"



#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H

namespace seneca {
	class Food : public Billable {
		bool m_ordered;
		bool m_child;
		char* m_customize = nullptr;


	public:
		Food();
		Food(const Food& source);
		Food& operator=(const Food& source);
		~Food();
		virtual double price() const;
		virtual std::ostream& print(std::ostream& ostr = std::cout)const ;
		virtual bool order();
		virtual bool ordered() const;
		virtual std::ifstream& read(std::ifstream& file);

	};
}
#endif // !SENECA_DRINK_H
