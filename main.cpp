
#include "admin.h"
#include "student.h"

int main()
{

    int choice;
    std::string filename = "database.txt";
    while (1)
    {

        std::cout << "Press 1. Adminstrator: " << std::endl;
        std::cout << "Press 2. Student" << std::endl;
        std::cout << "Press 3. Exit the Program" << std::endl;
        std::cout << "\nEnter your Choice: ";
        std::cin>>choice;
       if(choice==1) {
            administrator(filename);
        }
       else if (choice == 2)
        {
            
            student(filename);
            
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            std::cout<<"Invalid option."<<std::endl;
            system("cls");
        }
    }
    return 0;
}
