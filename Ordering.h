/*

Final Project Milestone 5
Module: Ordering
Filename: Ordering.h
Version 1.0
Author: Taejong Hwang
Revision History
-----------------------------------------------------------
Date      Reason
2025/3/07  Preliminary release
2025/03/10 Added extra char index for null terminator, setEmpty Function.
2025/03/18 Added Milestone 2 Requirements.
2025/03/29 Added Milestone 3 Requirements.
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include "constants.h"
#include "Food.h"
#include "Drink.h"
#ifndef SENECA_H_ORDERING
#define SENECA_H_ORDERING

namespace seneca {


	class Ordering {

		size_t	drinkCount=0;
		size_t	foodCount=0;
		
		size_t	billCount=0;
		size_t	billNum=1;
		
		Drink*	drinkArray = nullptr;
		Food*	foodArray	= nullptr;
		

        Billable* billArray[MaximumNumberOfMenuItems] = {nullptr};

		std::ostream& billTitlePrint(std::ostream& ostr = std::cout) const;
		std::ostream& printTotal(std::ostream& ostr = std::cout, double total=0) const;
		size_t countRecords(const char* file) const;

	public:
		Ordering(const char* drinkFile, const char* foodFile);
		~Ordering();
		operator bool () const;

		size_t noOfBillItems();
		bool hasUnsavedBill();

		void listFoods() const;
		void listDrinks() const;
		void orderFood();
		void orderDrink();
		void printBill(std::ostream& ostr = std::cout) const;
		void resetBill();
	};
}
#endif // !SENECA_H_ORDERING
