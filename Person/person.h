#ifndef PERSON_H
#define PERSON_H
#include<string>
#include<vector>

struct First_Name{
    std::string f_name;
    int year;

};

struct Last_Name{
    std::string l_name;
    int year;

};

class Person
{
public:
    Person(std::string f_name,std::string l_name, int dob);
//    Person(std::string f_name,std::string l_name);

public:
    void ChangeFirstName(int year, const std::string& first_name);
    void ChangeLastName(int year, const std::string& last_name);
    std::string GetFullName(int year);
    std::string GetFullNameWithHistory(int year);
private:
    std::string first_name;
    std::string last_name;
    int date_of_birth;
    std::vector<First_Name> v_of_First_Name;
    std::vector<Last_Name> v_of_Last_Name;



};

#endif // PERSON_H
