#ifndef ADMIN_H
#define ADMIN_H
#include "utility.h"



void replacer(std::string filename)
{
    
    student_data studentstr;
    std::fstream id_data;
    id_data.open(filename,std::ios::in);
    std::string line,new_password,replacestr;
    size_t comma1, comma2, comma3,comma4,comma5,comma6;
   
    system("cls");
    Sleep(40);

    readData(&studentstr,filename);

    replacestr=studentstr.reg_no+','+studentstr.name+','+studentstr.password+','+studentstr.dept+','
        +studentstr.messbill+','+studentstr.tuckbill+','+ studentstr.laundrybill;
    
    
    
    if(studentstr.isfound)
    {
        std::cout<<"Enter new password: ";
        getline(std::cin,studentstr.password);
        std::fstream id_data;
        std::vector<std::string> lines;

        id_data.open(filename, std::ios::in);
        while (getline(id_data, line)) // Till end of file
        {
            lines.push_back(line);
        }
        id_data.close();
        id_data.open(filename);

        for(int j=0;j<lines.size();j++)
        {
        
            if (lines[j] != replacestr)
            {
                id_data
                    <<lines[j]<<std::endl;
                
            }
            else
            {
                id_data<<studentstr.reg_no+','+studentstr.name+','+studentstr.password+','+studentstr.dept+','
                    +studentstr.messbill+','+studentstr.tuckbill+','+studentstr.laundrybill<< std::endl;
            }
        }
        id_data.close(); 
        std::cout<<"Successfully changed"<<std::endl;
        
        system("cls");
        Sleep(40);
        return;
    }
}
void delline(std::string filename)
{
    student_data studentstr;
    std::fstream id_data;
    id_data.open(filename,std::ios::in);
    std::string line,replacestr;
    size_t comma1, comma2, comma3,comma4,comma5,comma6;
    std::cin.ignore();
    system("cls");
    Sleep(40);

    readData(&studentstr,filename);

    replacestr=studentstr.reg_no+','+studentstr.name+','+studentstr.password+','+studentstr.dept+','
        +studentstr.messbill+','+studentstr.tuckbill+','+ studentstr.laundrybill;
   

    
    
    std::cout<<replacestr<<std::endl;
    if(studentstr.isfound)
    {
        std::fstream id_data;
        std::vector<std::string> lines;

        id_data.open(filename, std::ios::in);
        while (getline(id_data, line)) // Till end of file
        {
            lines.push_back(line);
        }
        id_data.close();
        id_data.open(filename);


        

        for(int j=0;j<lines.size();j++)
        {
        
            if (lines[j] != replacestr)
            {
                id_data
                    <<lines[j]<<std::endl;
                
            }
            else
            {
                continue;
                

            }
        }
        id_data.close(); 
        std::cout<<"Data deleted.."<<std::endl;
        
        system("cls");
        Sleep(40);
        return;
    }   
    return;

}   
    

void writeData(std::string filename)
{
    std::fstream id_data;
    student_data student;
    int range;
    id_data.open(filename, std::ios::out | std::ios::app);
    std::cout << "Enter No of students for data input: ";
    std::cin >> range;

    for (int i = 0; i < range; i++)
    {

        std::cout << "---------------------" << std::endl;
        std::cout << "\tStudent " << i + 1 << std::endl;
        std::cout << "Name: ";
        std::cin.ignore();
        getline(std::cin, student.name);

        std::cout << "Registration Number: ";
        getline(std::cin, student.reg_no);

        std::cout << "Password: ";
        std::cin >> student.password;

        std::cout << "Enter Department: ";
        std::cin.ignore();
        std::cin >> student.dept;

        std::cout << "---------------------" << std::endl;

        id_data 
            << student.reg_no << "," << student.name << "," << student.password << "," << student.dept <<","
            << student.messbill << "," <<student.tuckbill << "," << student.laundrybill << std::endl;
    }
    id_data.close();
}
void allprint(std::string filename)
{
    int count = 0;
    std::fstream id_data;
    student_data student;
    size_t comma1, comma2, comma3,comma4,comma5,comma6,space;
    id_data.open(filename, std::ios::in);
    std::string line;
    console_sleep();

    while (getline(id_data, line)) // Till end of file
    {
        if (line == "")
        {
            continue;
        }
     
            comma1 = line.find(',');
            comma2 = line.find(',', comma1+1 );
            comma3 = line.find(',', comma2+1 );
            comma4 = line.find(',', comma3+1 );
            comma5 = line.find(',', comma4+1 );
            comma6 = line.find(',', comma5+1 );
            student.reg_no = line.substr(0, comma1);
            student.name = line.substr(comma1+1, comma2 - comma1 -1);
            student.password = line.substr(comma2+1, comma3 - comma2 -1);
            student.dept = line.substr(comma3+1,comma4-comma3-1);
            student.messbill = line.substr(comma4+1, comma5 - comma4 -1);
            student.tuckbill = line.substr(comma5+1, comma6 - comma5 -1);
            student.laundrybill = line.substr(comma6+1);
            
        std::cout << "---------------------" << std::endl;
        std::cout << "( " << ++count << " ) " << std::endl;
        std::cout<< "Name: " << student.name;
        std::cout << "\n  Reg No: " << student.reg_no;
        std::cout << "\n  password: " << student.password;
        std::cout << "\n  Department: " << student.dept;
        std::cout << "\n  Mess bill: " << student.messbill;
        std::cout << "\n  Tuck bill: " << student.tuckbill;
        std::cout << "\n  Laundry bill: " << student.laundrybill;
        std::cout << "\n-----------------------" << std::endl;   
    }
    id_data.close();
    std::cout << "\n\n\nPress any key to return to Administrator Menu... ";
    getch();
    system("cls");
}
void selectivestudent(std::string filename)
{
    struct student_data student;
    readData(&student,filename);
    if(student.isfound)
    {  
        
        std::cout << "---------------------" << std::endl;
        std::cout << "Name: " << student.name;
        std::cout << "\nReg No: " << student.reg_no;
        std::cout << "\npassword: " << student.password;
        std::cout << "\nDepartment: " << student.dept;
        std::cout << "\nMess bill: " << student.messbill;
        std::cout << "\nTuck bill: " << student.tuckbill;
        std::cout << "\nLaundry bill: " << student.laundrybill;
 
        std::cout << "\n---------------------" << std::endl;
    }

    std::cout << "\n\n\nPress any key to return to Administrator Menu... ";
    getch();
    system("cls");
    
}

void administrator(std::string filename)
{

    int choice;

    while (1)
    {
        system("cls");
        Sleep(160);
        std::cout << "\t\tAdministrator\n\n\n";
        std::cout << "Press 1. Input Students data." << std::endl;
        std::cout << "Press 2. Output Students data." << std::endl;
        std::cout << "Press 3. Change Students password." << std::endl;
        std::cout << "Press 4. To Delete the data." << std::endl;
        std::cout << "Press 5. To Return to Main Menu" << std::endl;
        std::cout << "\nEnter your Choice: ";
        std::cin >> choice;
        if (choice == 1)
        {
            console_sleep();
            system("cls");
            std::cout << "\t\tStudents Data Input\n\n";
            writeData(filename);
        }
        else if (choice == 2)
        {
            system("cls");
            std::cout << "\t\tStudents Data Output\n\n";
            std::cout << "Press 1. Print all students data." << std::endl;
            std::cout << "Press 2. Enter student data you want to search for." << std::endl;
            std::cout << "\n\nEnter your Choice: ";
            std::cin >> choice;
            if (choice == 1)
            {
                console_sleep();
                system("cls");
                std::cout << "\t\tAll Students Data \n\n";
                allprint(filename);
            }
            else if (choice == 2)
            {
                console_sleep();
                system("cls");
                std::cout << "\t\tSelective Students Data \n";
                selectivestudent(filename);
            }
        }
        else if (choice == 3)
        {
            console_sleep();
            system("cls");
            replacer(filename);   
            return;
        }
        else if (choice == 4)
        {            
            console_sleep();
            system("cls");
            delline(filename);   
            return;
        }
        else if (choice == 5)
        {
            console_sleep();  
            return;
        }
        else
        {
            
            std::cout << "Invalid option!";
            std::cin.ignore();
            system("cls");
            
        }
    }
}
#endif