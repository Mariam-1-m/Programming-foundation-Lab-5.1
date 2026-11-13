#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>


class Employee{


private:
std::string name;
int age;
std::string department;
double salary;


public:
Employee(std::string name,int age,std::string department,double salary);
Employee();
void setName(std::string name);
std::string getName();

void setAge(int age);
int getAge();

void setDepartment(std::string name);
std::string getDepartment();

void setSalary(int age);
double getSalary();












};




#endif
