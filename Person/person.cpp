#include "person.h"
#include<iostream>


Person::Person(std::string f_name,std::string l_name, int dob):
    first_name(f_name), last_name(l_name), date_of_birth(dob)
{
    ChangeFirstName(date_of_birth,first_name);
    ChangeLastName(date_of_birth, last_name);
}


void Person::ChangeFirstName(int year, const std::string &first_name)
{
    if (v_of_First_Name.size() > 0 && v_of_First_Name.at(0).year > year) return; //игнор
    First_Name a;
    a.f_name = first_name;
    a.year = year;
    v_of_First_Name.push_back(a);

}

void Person::ChangeLastName(int year, const std::string &last_name)
{
    if (v_of_Last_Name.size() > 0 && v_of_Last_Name.at(0).year > year) return; //игнор
    Last_Name a;
    a.l_name = last_name;
    a.year = year;
    v_of_Last_Name.push_back(a);
}

std::string Person::GetFullName(int year)
{
    //Нахождение самого первого изменения
    std::string full_name = "";
    int l_min = -1, f_min = -1;
    if (v_of_Last_Name.size()) l_min = v_of_Last_Name.at(0).year;
    if (v_of_First_Name.size()) f_min = v_of_First_Name.at(0).year;
    for (int i = 0; i < v_of_First_Name.size(); i++){
        if (v_of_First_Name.at(i).year < f_min) f_min = v_of_First_Name.at(i).year;
    }
    for (int i = 0; i < v_of_Last_Name.size(); i++){
        if (v_of_Last_Name.at(i).year < l_min) l_min = v_of_Last_Name.at(i).year;
    }
    // Вариант инкогнито
    if ((year < l_min && year < f_min) || (v_of_Last_Name.size() == 0  && v_of_Last_Name.size() == 0)) return "No person";
    // Определение ближайшего изменения
    std::string f= "", l="";
    int min_diff = -1;
    for (int i = 0; i < v_of_First_Name.size(); i++)
    {
        int diff = year-v_of_First_Name.at(i).year;
        if (diff >= 0 && min_diff == -1)
        {
            min_diff = diff; //запись первого изминения до конца года
            f = v_of_First_Name.at(i).f_name + " ";
        }
        if(min_diff > diff && diff >= 0)
        {
            min_diff = diff; // если нашлось ближе к указанному году
            f = v_of_First_Name.at(i).f_name + " ";
        }
   //     if (min_diff == 0)  f = v_of_First_Name.at(i).f_name; // если год совпал
    }
    if (!f.size()) f = " with unknown first name"; // не нашли имя
    min_diff = -1;
    for (int i = 0; i < v_of_Last_Name.size(); i++)
    {
        int diff = year - v_of_Last_Name.at(i).year;
        if (diff >= 0 && min_diff == -1)
        {
            min_diff = diff;//запись первого изминения до конца года
            l = v_of_Last_Name.at(i).l_name + " ";
        }
        if(min_diff > diff && diff >= 0)
        {
            min_diff = diff;// если нашлось ближе к указанному году
            l = v_of_Last_Name.at(i).l_name + " ";
        }
   //     if (min_diff == 0)  l = v_of_Last_Name.at(i).l_name;// если год совпал
    }
    if (!l.size()) l = " with unknown last name"; //не нашли фамилию
    //вывод с учетом, того было ли изменения имениили фамилии
    if (!f.size()) full_name = l+f;
    else full_name = f+l;

    return  full_name;

}

std::string Person::GetFullNameWithHistory(int year)
{
    std::string full_name = "";
    int l_min = -1, f_min = -1;
    if (v_of_Last_Name.size()) l_min = v_of_Last_Name.at(0).year;
    if (v_of_First_Name.size()) f_min = v_of_First_Name.at(0).year;
    for (int i = 0; i < v_of_First_Name.size(); i++){
        if (v_of_First_Name.at(i).year < f_min) f_min = v_of_First_Name.at(i).year;
    }
    for (int i = 0; i < v_of_Last_Name.size(); i++){
        if (v_of_Last_Name.at(i).year < l_min) l_min = v_of_Last_Name.at(i).year;
    }
    // Вариант инкогнито
    if ((year < l_min && year < f_min) || (v_of_Last_Name.size() == 0  && v_of_Last_Name.size() == 0)) return "No person";
    // Определение ближайшего изменения
    std::string f= "", l="",b_l = "",b_f ="";
    int min_diff = -1;
    for (int i = 0; i < v_of_First_Name.size(); i++)
    {
        int diff = year-v_of_First_Name.at(i).year;
        if (diff >= 0 && min_diff == -1)
        {
            min_diff = diff; //запись первого изминения до конца года
            f = v_of_First_Name.at(i).f_name + " ";
        }
        if(min_diff > diff && diff >= 0)
        {
            min_diff = diff; // если нашлось ближе к указанному году
            f = v_of_First_Name.at(i).f_name + " ";
        }
   //     if (min_diff == 0)  f = v_of_First_Name.at(i).f_name; // если год совпал
    }
    if (v_of_First_Name.size()>1 && f != v_of_First_Name.at(0).f_name + " " ) b_f = " (" + v_of_First_Name.at(0).f_name + ") ";
    min_diff = -1;
    for (int i = 0; i < v_of_Last_Name.size(); i++)
    {
        int diff = year - v_of_Last_Name.at(i).year;
        if (diff >= 0 && min_diff == -1)
        {
            min_diff = diff;//запись первого изминения до конца года
            l = v_of_Last_Name.at(i).l_name + " ";
        }
        if(min_diff > diff && diff >= 0)
        {
            min_diff = diff;// если нашлось ближе к указанному году
            l = v_of_Last_Name.at(i).l_name + " ";
        }
   //     if (min_diff == 0)  l = v_of_Last_Name.at(i).l_name;// если год совпал
    }
    if (v_of_Last_Name.size() > 1 && l != v_of_Last_Name.at(0).l_name + " " ) b_l = " (" + v_of_Last_Name.at(0).l_name + ") ";
    //вывод с учетом, того было ли изменения имениили фамилии

    full_name = f+b_f+l+b_l;
    return  full_name;

}




