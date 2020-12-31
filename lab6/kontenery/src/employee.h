#include <iostream>
#include <string>


using namespace std;

#ifndef __EMPLOYEE__
#define __EMPLOYEE__

class Employee{
private:
    string id;
    string name;
    string surname;
    string departmentId;
    string position;

public:
    Employee(string id, string name, string surname, string departmentId, string position);
    Employee();
    string getId();
    string getName();
    string getSurname();
    string getPosition();
    string getDepartmentId();
};

#endif