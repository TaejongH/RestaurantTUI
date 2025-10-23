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
#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
namespace seneca {
    class Utils {
    public:
        char* alocpy(const char* src)const;
        char* alocpy(char*& des, const char* src)const;
        char* strcpy(char* des, const char* src)const;
        int strlen(const char* str)const;
        bool isspace(char ch)const;
        bool isspace(const char* cstring)const;
        int getInt();
        int getInt(int min, int max);
        char* makeBillFileName(char* filename, size_t billNo) const;
    };
    extern Utils ut;   // makes the ut object available where Utils.h is included
    // to call a Utils function call it as follows
    // ut.strcpy(des, src);
}

#endif // !SENECA_UTILS_H
