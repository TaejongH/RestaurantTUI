/*

Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
Version 1.2
Author: Taejong Hwang
Revision History
-----------------------------------------------------------
Date      Reason
2025/3/07  Preliminary release
2025/03/10 Added extra char index for null terminator, setEmpty Function.
2025/03/18 Added Milestone 2 Requirements.
2025/03/29 Added Milestone 3 Requirements.
2025/04/10 Changed getInt in select() to have min/max according m_numMenuItems
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include <iomanip>
#include "Menu.h"
#include "constants.h"
#include "Utils.h"


/*
A C-string holding the content. This should be stored dynamically in the MenuItem content.
The number of indentations.
The size of each indentation.
An integer for the row number (only used for numbered menu items).
*/
seneca::MenuItem::MenuItem(const char* menuItem, size_t numIndent, size_t sizeIndent, int menuindex)
{


	if (numIndent <= 4 && sizeIndent <= 4 && menuindex <= int(MaximumNumberOfMenuItems) && menuItem != nullptr) {
		m_numIndent = numIndent;
		m_sizeIndent = sizeIndent;
		m_menuIndex = menuindex;

		m_menuItem = new char[ut.strlen(menuItem)];
		int startingIndex = 0;
		while (isspace(menuItem[startingIndex]))startingIndex++;
		ut.alocpy(m_menuItem, menuItem + startingIndex);
	}
	else {
		m_menuItem = nullptr;


	}
}

seneca::MenuItem::~MenuItem()
{
	delete[] m_menuItem;
}

seneca::MenuItem::operator bool() const
{
	return m_menuItem != nullptr;
}



std::ostream& seneca::MenuItem::display(std::ostream& ostr) const
{
	if (*this) {
		for (size_t i = 0; i < m_numIndent; i++) {
			for (size_t j = 0; j < m_sizeIndent; j++)
			{
				ostr << " ";
			}
		}
		if (m_menuIndex >= 0) ostr << std::setw(2) << m_menuIndex << "- ";
		ostr << m_menuItem;
	}
	else {
		ostr << "??????????";
	}
	// TODO: insert return statement here
	return ostr;
}

seneca::Menu::Menu(const char* title, const char* exitText, size_t indentNum, size_t indentSize)
	: m_title(title, indentNum, indentSize, -1), m_exitText(exitText, indentNum, indentSize, 0), m_selectionEntry("> ", indentNum, indentSize, -1)
{/*
		size_t m_indentNum; DONE
		size_t m_m_indentSize; DONE
		size_t m_numMenuItems; DONE
		MenuItem* m_itemarray[MaximumNumberOfMenuItems]; DONE
		MenuItem m_title; DONE ON INITIALIZER
		MenuItem m_exitText; DONE ON INITIALIZER
		MenuItem m_selectionEntry; DONE ON INITIALIZER
 */
	m_indentNum = indentNum;
	m_indentSize = indentSize;
	m_numMenuItems = 0;
	for (size_t i = 0; i < MaximumNumberOfMenuItems; i++) m_itemarray[i] = nullptr; //set all elements to nullptr
}

seneca::Menu& seneca::Menu::operator<<(const char* content)
{
	if (m_numMenuItems < MaximumNumberOfMenuItems) {

		m_itemarray[m_numMenuItems] = new MenuItem(content, m_indentNum, m_indentSize, (int)m_numMenuItems + 1);
		m_numMenuItems++;
	}
	return *this;
	// TODO: insert return statement here
}


size_t seneca::Menu::select() const
{
	size_t input = -1;
	if (m_title) {
		m_title.display() << std::endl;
	}
	for (size_t i = 0; i < m_numMenuItems; i++)
	{
		m_itemarray[i]->display() << std::endl;
	}

	m_exitText.display() << std::endl;

	m_selectionEntry.display();
	input = ut.getInt(0,m_numMenuItems);
    
	return input;
}

seneca::Menu::~Menu()
{
	for (size_t i = 0; i < MaximumNumberOfMenuItems; i++) {
		delete m_itemarray[i];
		m_itemarray[i] = nullptr; //set all elements to nullptr
	}
	delete[] m_itemarray;
	m_itemarray = nullptr;
}

size_t seneca::operator<<(std::ostream& ostr, const Menu& m)
{
	size_t input = 0;
	if (&ostr == &std::cout) {
		input = m.select();
	}
	return input;
}
