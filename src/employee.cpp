
#include "../include/employee.h"
#include <iostream>
using namespace std;





Employee::Employee(std::string name,int age,std::string department,double salary){
this->name=name;
this->age=age;
this->department=department;
this->salary=salary;

}

Employee::Employee(){
name="unknown";
age=20;
department="finanicial";
salary=10000;
}

void Employee::setName(std::string name){
    this->name=name;
}
std::string Employee::getName(){
return  this->name;
}

void Employee::setAge(int age){
this->age=age;
}
int Employee::getAge(){
return this->age;
}

void Employee::setDepartment(std::string department){
this->department=department;
}
std::string Employee::getDepartment(){
return this->department;
}

void Employee::setSalary(int salary){
this->salary=salary;
}
double Employee::getSalary(){
return this->salary;
}

