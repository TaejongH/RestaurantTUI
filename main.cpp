/*

Final Project Milestone 5
Module: Main Program
Filename: main.cpp
Version 1.0
Author: Taejong Hwang
Revision History
-----------------------------------------------------------
Date      Reason
2025/04/10 Initial Version.
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include <iostream>
#include <fstream>
#include "Menu.h"
#include "Ordering.h"
#define INDENTNUM 0
#define INDENTSIZE 0

using namespace seneca;


int main(int argc, const char * argv[]) {
//    Menu Title: "Seneca Restaurant"
//    Exit Option: "End Program"
//    Menu Options:
    //    Order
    //    Print Bill
    //    Start a New Bill
    //    List Foods
    //    List Drinks

    Ordering orders("drinks.csv", "foods.csv");
    if(!orders) std::cout << "Failed to open data files or the data files are corrupted!";
    
    Menu senecaMenu("Seneca Restaurant ","End Program",INDENTNUM,INDENTSIZE);
    senecaMenu << "Order" << "Print Bill" << "Start a New Bill" << "List Foods" << "List Drinks";
    
    Menu orderMenu("Order Menu","Back to main menu",INDENTNUM+1,INDENTSIZE+3);
    orderMenu << "Food" << "Drink";
    
    Menu confirmationMenu("You have bills that are not saved. Are you sure you want to exit?","No",INDENTNUM,INDENTSIZE);
    confirmationMenu << "Yes";
    size_t choice = 0;
    bool exitProgram = false;
    while(exitProgram == false){
       
        choice =  senecaMenu.select();
        switch (choice) {
            case 0:
                if(orders.hasUnsavedBill()){
                    choice = confirmationMenu.select();
                    if(choice){exitProgram =true;}
                    
                    
                }
                else{exitProgram =true;}
                break;
                
            case 1:
                while(choice != 0){
                    choice = orderMenu.select();
                    switch (choice) {
                        case 0:
                            break;
                        case 1:
                            orders.orderFood();
                            break;
                        case 2:
                            orders.orderDrink();
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 2:
                orders.printBill();
                break;
            case 3:
                orders.resetBill();
                break;
            case 4:
                orders.listFoods();
                break;
            case 5:
                orders.listDrinks();
                break;
            default:
                break;
        }
    }

    return 0;
}
