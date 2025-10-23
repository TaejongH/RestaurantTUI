/***********************************************************************
// OOP244 Project, Utils Module
//
// File	Utils.h
// Version 0.3
// started by Fardad
// Description
// utility function to be used in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Taejong       03-14-2025  Added getInt() functions
//Taejong       03-18-2025  Added getInt(min,max) function
//Taejong       04-01-2025  Added makeBillFileName as given in Milestone 4 spec
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Utils.h"

#define INPUT_CHAR 10

using namespace std;
namespace seneca {
    Utils ut;

    char* Utils::alocpy(const char* src) const {
        char* des{};
        return alocpy(des, src);
    }

    char* Utils::alocpy(char*& des, const char* src)const {
        delete[] des;
        des = nullptr;
        if (src) {
            des = new char[strlen(src) + 1];
            strcpy(des, src);
        }
        return des;
    }
    char* Utils::strcpy(char* des, const char* src)const {
        int i;
        for (i = 0; src[i]; i++) des[i] = src[i];
        des[i] = char(0);
        return des;
    }
    int Utils::strlen(const char* str)const {
        int len;
        for (len = 0; str[len]; len++);
        return len;
    }

    bool Utils::isspace(char ch)const {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
    }

    bool Utils::isspace(const char* cstring) const {
        while (cstring && isspace(*cstring)) {
            cstring++;
        }
        return cstring && *cstring == 0;
    }

    int Utils::getInt()
    {
        int number;
        char input[INPUT_CHAR] = { 0 };
        bool isNumber;

        do {
            number = 0;
            isNumber = true;
            cin.getline(input, INPUT_CHAR);
            cin.clear();
            if (input[0] == 0) { //EMPTY INPUT
                cout << "You must enter a value:" << endl;
                isNumber = false;
            }

            else if (!isdigit(input[0])) {//First char is not a number
                cout << "Invalid integer:" << endl;
                isNumber = false;
            }
            else {
                for (int i = 0; i < ut.strlen(input); i++) {
                    if (isdigit(input[i])) {
                        number = (number * 10) + (input[i] - '0');
                    }
                    else {
                        cout << "Only an integer please:" << endl;
                        i = ut.strlen(input);
                        isNumber = false;

                    }
                }

            }

        } while (isNumber == false);


        return number;
    }

    int Utils::getInt(int min, int max)
    {
        int input;
        do {
            input = getInt();
            if (input < min || input >max) {
                cout << "Invalid value: [min <= value <= max], try again:" << endl;
            }
        } while (input < min || input >max);
        return input;
    }

    char* Utils::makeBillFileName(char* filename, size_t billNo)const {
        char billFileName[21] = "bill_";
        size_t temp = billNo;
        int cnt = 5;
        int length;
        // Calculate the number of digits
        do {
            cnt++;
            temp /= 10;
        } while (temp > 0);
        length = cnt;
        // Convert each digit to character from the end
        while (billNo > 0) {
            billFileName[--cnt] = (billNo % 10) + '0';
            billNo /= 10;
        }
        // Handle the case when billNo is 0
        if (billFileName[cnt - 1] == '\0') {
            billFileName[--cnt] = '0';
        }
        // Attach .txt to the end of the file name
        for (int i = 0; ".txt"[i]; i++) {
            billFileName[length++] = ".txt"[i];
        }
        billFileName[length] = '\0';
        strcpy(filename, billFileName);
        return filename;
    }


}
