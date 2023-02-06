#include <stdlib.h>
#include <iostream>

class Employee
{
private:
    int salary;
public:
    Employee()
    {
        setSalary(100);
    }
    void setSalary(int n)
    {
        this->salary = n;
    }
    void addSalary(int n)
    {
        this->salary += n;
    }
    int getSalary()
    {
        return this->salary;
    }
};

class Programmer:public Employee
{
public:
    Programmer()
    {
        setSalary(500);
    }
};

class Manager: public Employee
{
public:
    Manager()
    {
        setSalary(1000);
    }
    void bonusSalary(int n)
    {
        int salary;
        std::cout << "Manager salary: " << salary << std::endl;
        salary *= n;
        std::cout << "Manager salary: " << salary << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Employee e;
    Programmer p;
    Manager m;
    p.addSalary(500);
    m.bonusSalary(2);
    std::cout << e.getSalary() << std::endl;
    std::cout << p.getSalary() << std::endl;
    std::cout << m.getSalary() << std::endl;
    return 0;
}