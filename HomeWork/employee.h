#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>

 enum e_gender {
 Male, Female
};

class Employee
{
public:
    Employee(std::string f_name,std::string l_name,e_gender gender_l,int age_l,int cat_l);
    void promote();
    void demote();
    void printInfo();
private:
   std::string first_name;
   std::string last_name;
   e_gender gender;
   int age;
   int cat;
};

#endif // EMPLOYEE_H
