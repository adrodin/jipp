#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "hrms.h"
#include "employee.h"

using namespace std;

HRMS::HRMS() {};

bool HRMS::isEmployeeInSystem(string employeeId) {
    return this->employees.find(employeeId) != this->employees.end();
}

void HRMS::add(Employee employee, double salary) {
    if (salary<=0) {
        throw invalid_argument("Salary shold be greather than 0\n");
    }

    if(isEmployeeInSystem(employee.getId())){
        throw invalid_argument("Employee with this id already exist!\n");
    }

    this->employees[employee.getId()] = employee;
    this->salaries[employee.getId()] = salary;
    this->idMap[employee.getDepartmentId()].push_back(employee.getId());
}

void HRMS::printDepartment(string departmentId) {
    cout <<"Department id: "<<departmentId<<endl;
    cout<<"employees:"<<endl;

   Employee employee;
   for(auto e: idMap[departmentId]){
       employee=this->employees[e];
        cout<<employee.getName()<<" "<<employee.getSurname()<<" "<<employee.getPosition()<<endl;

   }
}

void HRMS::changeSalary(string employeeId, double salary) {
    if(salary<=0){
        throw invalid_argument("Salary shold be greather than 0\n");
    }
    if(!isEmployeeInSystem(employeeId)){
        this->employees.erase(employeeId);
        throw invalid_argument("Employee with this id does not exist!\n");
    }
    this->salaries[employeeId]=salary;
}

void HRMS::printSalaries() {
    Employee employee;
    for (auto e: this->salaries) {
        employee=this->employees[e.first];
        cout<<employee.getName()<<" "<<employee.getSurname()<<" "<<employee.getDepartmentId()<<" "<<employee.getPosition()<<" "<<e.second<<endl;
    }
}

void HRMS::printSalariesSorted() {
    vector<pair<string, double>> toSort;

    for (auto e : this->salaries) {
        toSort.push_back(e);
    }

    sort(toSort.begin(), toSort.end(),[](pair<string, double> &a, pair<string, double>&b) -> bool {return a.second < b.second;});

    Employee employee;
    for (auto e : toSort) {

        employee = this->employees[e.first];
        cout<<employee.getName()<<" "<<employee.getSurname()<<" "<<employee.getDepartmentId()<<" "<<employee.getPosition()<<" "<<e.second<<endl;
    }
}

