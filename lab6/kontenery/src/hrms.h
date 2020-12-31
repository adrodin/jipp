#include <map>
#include <vector>
#include "employee.h"

using namespace std;

#ifndef __HRMS__
#define __HRMS__

class HRMS {
private:
    map<string, Employee> employees;
    map<string, vector<string>> idMap;
    map<string, double> salaries;

    bool isEmployeeInSystem(string employeeId);
public:
    HRMS();
    void add(Employee employee, double salary);
    void printDepartment(string departmentId);
    void changeSalary(string employeeId, double salary);
    void printSalaries();
    void printSalariesSorted();
};

#endif