#include <iostream>
#include "../include/menu.h"
#include "../include/colors.h"
#include "../include/arrowGet.h"
#include "../include/menuApp.h"
#include <thread>
#include <chrono>



#include <cstdio>    
#ifndef _WIN32
#include <unistd.h>
#endif







menuApp::menuApp(){


empCount=0;
currentIndex=0;
userColor="yellow";
 options[0]= "New Screen";
 options[1]= "Display Screen" ;
 options[2]="Exit" ;
 
    menuSize=3;
    
   x_axis=10;
   y_axis=10;

}
void menuApp::setCurrentIndex(int currentIndex){
this->currentIndex=currentIndex;
}

int menuApp::getCurrentIndex(){
return currentIndex;
}




void menuApp::setUserColor(std::string_view color){
this->userColor=color;
}

std::string_view menuApp::getUserColor(){
return userColor;
}


void menuApp::getCurrentCoordinates(int &x_axis,int &y_axis){
x_axis= this->x_axis;
y_axis= this->y_axis;
}



void menuApp::displayMenu(){
std::cout<<"\033[2J\033[H"<<std::flush;
for(int i=0;i<menuSize;i++){
    goToXY(x_axis, y_axis + i);
if (i== currentIndex){
    std::cout << "\033[1;37m";
    std::cout<<setColor(userColor) <<"→ "<<options[i] <<Color::RESET<<"\n" ;
}else{
    std::cout <<"  "<<options[i]<<"\n" ;

}

}
}



void menuApp::observeUserKeys(){


    std::printf("Press the arrow keys to test the program (press 'q' to quit):\n");
    char byte1='q';
    char byte2='q';
    char byte3='q';

    do{
         std::cout<<"\033[2J\033[H"<<std::flush;
      
        displayMenu();
        byte1= getch_linux();
      
        if (byte1 == '\033') {

            byte2=getch_linux();

            byte3=getch_linux();
           
            switch (byte3) {
                case 'A'://up
                  
                    currentIndex=(currentIndex-1+menuSize)%menuSize;
                    break;

                case 'B': //down
                    currentIndex=(currentIndex+1)%menuSize;
                    break;

                case 'C':
                    std::printf("→ Right Arrow\n");
                    break;

                case 'D':
                    std::printf("← Left Arrow\n");
                    break;
                case 'H':
                    currentIndex=0;
                    break;
                case 'F':
                   currentIndex=3;
                    break;
            }
        }else if(byte1=='\n' || byte1=='\r'){
            switch (currentIndex){
                case 0:
                    addNewEmployee();
                break;
                case 1:
                   displayAllEmployees();
                break;
                case 2:
                std::cout<<"\033[2J\033[H"<<std::flush;
                std::cout<<"Quitted!";
                byte1='q';
                return;
              
                break;
            
            }
        }

        std::cout<<"================================="<<std::endl;
    }while(byte1 != 'q' && byte1 != 'Q');        // Exit the program if the user presses Q or q
    // Exit the program successfully
 std::cout<<"\033[2J\033[H"<<std::flush;

}

void menuApp::addNewEmployee(){
std::string name;
int age;
std::string department;
double salary;
char cont;

 std::cout<<"\033[2J\033[H"<<std::flush;
std::cout<<"=========================== ADD EMPLOYEE SCREEN ============================\n\n";

do{

if(empCount==20){
    std::cout<<"The DB is full now ,can't add another employee!";
    return;
}
std::cout<<"Enter employee name : \n";
std::cin>>name;


std::cout<<"Enter employee age : \n";
std::cin>>age;
if(age<=0){
    std::cout<<"Try again with a valid age!"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return;
}

std::cout<<"Enter employee department (e.g HR,Finance,..) : \n";
std::cin>>department;

std::cout<<"Enter employee salary: \n";
std::cin>>salary;
if(salary<=0){
    std::cout<<"Try again with a valid salary!"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    return;
}

 employees[empCount]= Employee(name,age,department,salary);
empCount++;
std::cout<<empCount;
std::cout<<"Do you want to continue? y/n\n";
std::cin>>cont;
}while(cont=='y' || cont=='Y');
}

void menuApp::displayAllEmployees(){
    std::cout<<"\033[2J\033[H"<<std::flush;
     std::cout<<"=========================== DISPLAY OUR EMPLOYEES ==========================\n";
    for(int i=0;i<empCount;i++){
    std::cout<<"\n"<<"Employee : "<<i+1 <<" \n";
    std::cout<<"Name : "<<employees[i].getName()<<"\n";
    std::cout<<"Age : "<<employees[i].getAge()<<"\n";
    std::cout<<"Department : "<<employees[i].getDepartment()<<"\n";
    std::cout<<"Salary : "<<employees[i].getSalary()<<"\n";
    std::cout<<"========================";
    }
    std::cin.ignore();
    std::cin.get();
}




