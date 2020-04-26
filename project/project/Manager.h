#ifndef _MANAGER_H_
#define _MANAGER_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
using namespace std;
struct Date {
    int date, month, year;
};
struct Information {
    string id;
    string password;
    string fullname;
    Date dob;
    int male;//1:male,0:female
    string  degree; 
    int type; // 0: staff; 1: lecturer; 2: student
    int active;// 0:unactive; 1:active
};
void  first_menu();
void is_log_out();
void show_menu_staff() ; 
void show_menu_lecturer();
void show_menu_student();
void showInfo(Information person);
int login(fstream& fstu, fstream& fsta, fstream& flec);

#endif
