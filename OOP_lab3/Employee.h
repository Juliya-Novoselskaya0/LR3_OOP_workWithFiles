#pragma once
#include <string>
#include<istream>
#include <istream>


class Employee
{
	std::string fullName;
	int departmentNumber;
	std::string position;
	std::string startDateOfWork;
public:
	Employee(std::string fn, int dn, std::string pos, std::string stDW)
	{
		fullName = fn;
		departmentNumber = dn;
		position = pos;
		startDateOfWork = stDW;
	}
	Employee()
	{
		fullName = "";
		departmentNumber = 0;
		position = "";
		startDateOfWork = "";
	}
	std::string getFullName();
	int getDepNum();
	int getDepNum(Employee& ob);
	std::string getPosition();
	std::string getStartDateOfWork();
	friend std::ostream& operator<<(std::ostream& out, Employee& ob);
	friend std::istream& operator>>(std::istream& in, Employee& ob);
};

