#ifndef MENUAPP_H
#define MENUAPP_H
#include "../include/employee.h"
#include <iostream>


#include <cstdio>     
#ifndef _WIN32
#include <unistd.h>
#endif



class menuApp
{
private:
  int currentIndex;
  const char* options[4] ;
  std::string_view userColor;
  int x_axis;
  int y_axis;
  Employee employees[20];
  int empCount;
 int menuSize;


public:
menuApp();
void setCurrentIndex(int currentIndex);
int getCurrentIndex();



void setUserColor(std::string_view color);

std::string_view  getUserColor();

void getCurrentCoordinates(int &x_axis,int &y_axis);


void observeUserKeys( );
void displayMenu();

void addNewEmployee();

void displayAllEmployees();

};

#endif