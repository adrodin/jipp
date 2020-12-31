#include <string>
#include "employee.h"

using namespace std;

Employee::Employee(string id, string name, string surname, string departmentId, string position) {
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->departmentId = departmentId;
    this->position = position;
}

Employee::Employee() {};

string Employee::getId() {
    return this->id;
}

string Employee::getName() {
    return this->name;
}

string Employee::getSurname() {
    return this->surname;
}

string Employee::getDepartmentId() {
    return this->departmentId;
}

string Employee::getPosition() {
    return this->position;
}



