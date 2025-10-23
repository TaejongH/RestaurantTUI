/*

Final Project Milestone 5
Module: Ordering
Filename: Ordering.cpp
Version 1.1
Author: Taejong Hwang
Revision History
-----------------------------------------------------------
Date      Reason
2025/04/01  Preliminary release
2025/04/10 Fixed printFunction to use the filename returned from Utility.h
2025/04/10 Fixed printBill() by passing ostr to ostream calls within the function.
2025/04/10 Fixed print() price precision to two decimal places.

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "Ordering.h"
#include "Menu.h"
#include "Utils.h"
#include <fstream>
#include <iomanip>


std::ostream& seneca::Ordering::billTitlePrint(std::ostream& ostr) const
{
	ostr << "Bill # ";
	ostr << std::setw(3) << std::right << std::setfill('0') << billNum << " =============================" << std::endl;
	// TODO: insert return statement here
	return ostr;
}

std::ostream& seneca::Ordering::printTotal(std::ostream& ostr, double total) const
{
    ostr << "                     " << std::left << std::setw(10) << std::setfill(' ') << "Total:" << std::right << std::setw(9) << std::setfill(' ') << std::fixed << std::setprecision(2) << total << std::endl;
    ostr << "                     " << std::left << std::setw(10) << std::setfill(' ') << "Tax:" << std::right << std::setw(9) << std::setfill(' ') << std::fixed << std::setprecision(2) << total*Tax << std::endl;

	ostr << "                     " << std::left << std::setw(10) << std::setfill(' ') << "Total+Tax:" << std::right << std::setw(9) << std::setfill(' ') << std::fixed << std::setprecision(2) << (total * Tax + total) << std::endl;

	ostr << "========================================" << std::endl;
	// TODO: insert return statement here
	return ostr;
}

size_t seneca::Ordering::countRecords(const char* file) const
{
	size_t lineCounter = 0;
	std::ifstream datafile(file);
	
	while (datafile)
	{
		char read = datafile.get();
		if (datafile && read == '\n') lineCounter++;
	}
	return lineCounter;
}

seneca::Ordering::Ordering(const char* drinkFile, const char* foodFile)
{
	size_t drinkLines = countRecords(drinkFile);
	size_t foodLines = countRecords(foodFile);

	std::ifstream drinkData(drinkFile);
	std::ifstream foodData(foodFile);


	if (drinkData && foodData)
	{
        drinkArray = new Drink[drinkLines];
        foodArray = new Food[foodLines];

        size_t drinksReadcounter;
        size_t foodReadcounter;
        
		for ( drinksReadcounter = 0; drinksReadcounter < drinkLines && drinkData ; drinksReadcounter++)//Drink file reading operation
		{
			drinkArray[drinksReadcounter].read(drinkData);
		}

		for ( foodReadcounter = 0; foodReadcounter < foodLines && foodData ; foodReadcounter++)//Food file reading operation
		{
            foodArray[foodReadcounter].read(foodData);
		}

		if (drinksReadcounter != drinkLines || foodReadcounter != foodLines) //Check if all lines read
		{
			delete[] drinkArray;
			delete[] foodArray;

			drinkArray = nullptr;
			foodArray = nullptr;
		}

		else drinkCount = drinkLines; foodCount = foodLines;
	}
}

seneca::Ordering::~Ordering()
{
	delete[] drinkArray;
	delete[] foodArray;

	for (size_t i = 0; i < billCount; i++)
	{
		delete billArray[i];
	}
}

seneca::Ordering::operator bool () const
{
	return (drinkArray != nullptr && foodArray != nullptr) ? true : false;
}

size_t seneca::Ordering::noOfBillItems()
{
	return billCount;
}

bool seneca::Ordering::hasUnsavedBill()
{
	return billCount > 0;
}

void seneca::Ordering::listFoods() const
{
	std::cout << "List Of Avaiable Meals" << std::endl;
	std::cout << "========================================" << std::endl;
	for (size_t i = 0; i < foodCount; i++) {
        foodArray[i].print() <<  std::endl;;

        
	}
    std::cout  <<"========================================" << std::endl;
}

void seneca::Ordering::listDrinks() const
{
	std::cout << "List Of Avaiable Drinks" << std::endl;
	std::cout << "========================================" << std::endl;
	for (size_t i = 0; i < drinkCount; i++) {
		drinkArray[i].print() << std::endl;
	}
	std::cout << "========================================" << std::endl;
}

void seneca::Ordering::orderFood()
{
	Menu menuobject("Food Menu", "Back to Order", 2);

	for (size_t i = 0; i < foodCount; i++)
	{
		menuobject << foodArray[i];
	}
    size_t choice= 0u;
    choice = menuobject.select();
	if (choice != 0)
	{
        choice--;
		billArray[billCount] = new Food(foodArray[choice]);
		if (billArray[billCount]->order()) {
			billCount++;
		}
		else {
			delete billArray[billCount];
		}
	}
	 
}

void seneca::Ordering::orderDrink()
{
	Menu menuobject("Drink Menu", "Back to Order", 2);

	for (size_t i = 0; i < drinkCount; i++)
	{
		menuobject << drinkArray[i];
	}
	size_t choice = menuobject.select();
	if (choice != 0)
	{
        choice--;
		billArray[billCount] = new Drink(drinkArray[choice]);
		if (billArray[billCount]->order()) {
			billCount++;
		}
		else {
			delete billArray[billCount];
		}
	}
}

void seneca::Ordering::printBill(std::ostream& ostr) const
{
	double total = 0.0;
	billTitlePrint(ostr);

	for (size_t i = 0; i < billCount; i++)
	{
        billArray[i]->print(ostr) << std::endl;
		total += billArray[i]->price();
		
	}
	printTotal(ostr, total);
}


void seneca::Ordering::resetBill()
{
	char* billfile = new char[100];
	billfile = ut.makeBillFileName(billfile, billNum);
	std::ofstream bill(billfile);
	printBill(bill);
	std::cout << "Saved bill number " << billNum << std::endl;
	std::cout << "Starting bill number " << billNum+1 << std::endl;

	for (size_t i = 0; i < billCount; i++)
	{
		delete billArray[i];
	}
    delete[] billfile;
    billfile=nullptr;
	billNum++;
	billCount = 0u;
}
