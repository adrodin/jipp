#include <iostream>
#include <vector>
#include <map>
#include "hrms.h"
#include "employee.h"

int main() {
    HRMS system;

    vector<pair<Employee, double>> emp;
    emp.push_back(make_pair(Employee("1","Bruno","Fernandes","11","CEO"),4123));
    emp.push_back(make_pair(Employee("2","Harry","Kane","11","Sales Director"),6123));
    emp.push_back(make_pair(Employee("3","Jamie","Vardy","11","PR Director"),7124));
    emp.push_back(make_pair(Employee("4","Patrick","Bamford","51","Graphic Designer"),6154));
    emp.push_back(make_pair(Employee("5","Mohamed","Salah","51","Art Director"),9126));
    emp.push_back(make_pair(Employee("6","Jack","Grealish","51","Graphic Designer"),11412));
    emp.push_back(make_pair(Employee("7","Aaron","Cresswell","51","Graphic Designe"),2147));
    emp.push_back(make_pair(Employee("8","Tomas","Soucek","33","Data Base Administrator"),9684));
    emp.push_back(make_pair(Employee("9","Joao","Cancelo","33","Database Manager"),4129));
    emp.push_back(make_pair(Employee("10","Stuart","Dallas","33","System Analyst"),9651));

    for (auto e : emp) system.add(e.first, e.second);

    system.printDepartment("11");
    cout<<"\nSalaries:\n";
    system.printSalaries();

    system.changeSalary("1", 12512);

    cout<<"\nSorted salaries:\n";
    system.printSalariesSorted();


    return 0;
}