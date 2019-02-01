#include <iostream>
#include <employee.h>
#include <vector>


int main()
{
        std::vector<Employee> umichWorks;
        // Создайте несколько экземплятов класса Employee и добавьте их в вектор umichWorks
        Employee d("Egor", "Petrov", Male, 20, 2);
        Employee a("Egor", "Petrov", Male, 20, 2);
        Employee b("Elena", "Romanova", Female, 22, 2);
        Employee c("Kurt", "Cobain",Male,27,10);
        for( auto employee:  umichWorks)
        umichWorks.push_back(d);
        umichWorks.push_back(a);
        umichWorks.push_back(b);
        umichWorks.push_back(c);


        std::cout << std::endl << "Welcome to umichWorks! Here are our loyal employees: " << std::endl;
        for( auto employee:  umichWorks)
        {
            employee.printInfo();
        }
        // Повысьте категорию одному из работников и понизьте всем остальным
        for( int i =0; i < umichWorks.size()-1; i++){
            umichWorks[i].demote();
        }
        umichWorks[umichWorks.size()-1].promote();

        std::cout << "Here is the new info for the employees of umichWorks: " << std::endl;
        for( auto employee:  umichWorks)
        {
            employee.printInfo();
        }
        return 0;
}
