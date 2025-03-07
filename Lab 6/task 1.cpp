#include "iostream"
using namespace std;

class Employee{
  protected:
  string name;
  float salary;

  public:
  Employee(string name, float salary) : name(name) , salary(salary){}

  void displaydetails()
  {
      cout << "----------------------------" << endl;
      cout << "Name: " << name << endl;
      cout << "Salary: " << salary << endl;
  }
};

class Manager : public Employee{
    public:
    int bonus;

    Manager(string name , float salary, int bonus) : Employee(name , salary) , bonus(bonus){}

    void displaydetails()
    {
        Employee::displaydetails();
        cout << "Bonus: " << bonus << endl;
    }
};
int main() {
    Manager M("Hammad",500.6,50);
    M.displaydetails();

    return 0;
}
