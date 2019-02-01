#include "employee.h"

Employee::Employee(std::string f_name,std::string l_name,e_gender gender_l,int age_l,int cat_l):
    first_name(f_name),last_name(l_name),gender(gender_l),age(age_l),cat(cat_l)
{

}

void Employee::promote()
{
    cat++;
}

void Employee::demote()
{
    cat--;
}

void Employee::printInfo()
{

    std::cout << first_name << "  ";

    std::cout << last_name << "  ";

    gender == Male?
                std::cout << "Male" << "  ":
                std::cout << "Female" << "  ";
    std::cout << age << "  ";
    std::cout << cat << std::endl;
}
