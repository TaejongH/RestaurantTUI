/*

Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
Version 1.3
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
#include <iostream>
#include "constants.h"
#ifndef SENECA_MENU_H
#define SENECA_MENU_H

namespace seneca {
	class Menu;
	class MenuItem {
		char* m_menuItem;
		size_t m_numIndent;
		size_t m_sizeIndent;
		int m_menuIndex;

		friend class Menu;

		MenuItem(const char* menuItem, size_t numIndent, size_t sizeIndent, int menuindex);
		MenuItem(const MenuItem& source) = delete;
		MenuItem& operator=(const MenuItem& source) = delete;
		~MenuItem();
		operator bool() const;
		std::ostream& display(std::ostream& ostr = std::cout) const;

	};

	class Menu {

		size_t m_indentNum;
		size_t m_indentSize;
		size_t m_numMenuItems;
		MenuItem** m_itemarray = new MenuItem * [MaximumNumberOfMenuItems];
		MenuItem m_title;
		MenuItem m_exitText;
		MenuItem m_selectionEntry;

	public:
		Menu(const char* title, const char* exitText = "Exit", size_t indentNum = 0, size_t indentSize = 3);
		seneca::Menu& operator<<(const char* name);
		Menu(const Menu& source) = delete;
		Menu& operator=(const Menu& source) = delete;

		size_t select() const;
		~Menu();


	};
	size_t operator<<(std::ostream& ostr, const Menu& m);


}

#endif // !SENECA_MENU_H
