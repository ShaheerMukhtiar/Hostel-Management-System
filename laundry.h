#ifndef LAUNDRY_H
#define LAUNDRY_H
#include "utility.h"
#include "student.h"
struct laundry{
    char name[30];
    std::string categ;
    std::string hotel_no;
    int room_no;
    char washer_no[15];
};

void regData(student_data* student,std::string filename,std::string reg_no)
{
    std::fstream id_data;
    std::cin.ignore();
  
    
    id_data.open(filename, std::ios::in);
    std::string line;
    bool isFound = false;
    size_t comma1, comma2, comma3,comma4,comma5,comma6;
    console_sleep();
    while (getline(id_data, line))
    {
        if (line.find(reg_no) != std::string::npos)
        {
            
            comma1 = line.find(',');
            comma2 = line.find(',', comma1+1 );
            comma3 = line.find(',', comma2+1 );
            comma4 = line.find(',', comma3+1 );
            comma5 = line.find(',', comma4+1 );
            comma6 = line.find(',', comma5+1 );
            student->reg_no = line.substr(0, comma1);
            if (student->reg_no==reg_no)
            {
                student->name = line.substr(comma1+1, comma2 - comma1 -1);
                student->password = line.substr(comma2+1, comma3 - comma2 -1);
                student->dept = line.substr(comma3+1,comma4-comma3-1);
                student->messbill = line.substr(comma4+1, comma5 - comma4 -1);
                student->tuckbill = line.substr(comma5+1, comma6 - comma5 -1);
                student->laundrybill = line.substr(comma6+1);
                isFound=true;
                student->isfound = true;
                break;
            }
            else
            {
                continue;
            }   
        }
    }
  
    id_data.close();
}
void Laundry(std::string filename,std::string reg_no,std::string studentname){

    std::ofstream record;
    record.open("Laundry.txt",std::ios::app );
    int choice,quantity;
    std::string s;
    laundry student;
    std::cout<<"\tWELCOME TO EME LAUNDRY SERVICES\n";
    std::cout<<"\n\nKindly Enter the following data:";
    std::cout<<"\nName: "<<studentname;
   //std::getline(std::cin, student.name);
    std::cout<<"\nEnter your category: ";
    std::cin>>student.categ;
    std::cout<<"\nHostel No: ";
    std::cin>>student.hotel_no;
   
    do{
        std::cout<<"\nRoom No: ";
        std::cin>>student.room_no;
        if(student.room_no>0)
        {
            continue;
        }
        else
        {
            std::cout<<"Invalid Output."<<std::endl;
        }
    }
    while(student.room_no<=0);
    std::cout<<"\nWasherman No: ";
    std::cin>>student.washer_no;

    record<<"\n"<<"                     "<<__DATE__<<std::endl<<std::endl;    
    record<<"Name: "<<studentname<<std::endl;
    record<<"Category: "<<student.categ<<std::endl;
    record<<"Hostel No: "<<student.hotel_no<<std::endl;
   
    record<<"Room No: "<<student.room_no<<std::endl;
    record<<"Washerman No: "<<student.washer_no<<std::endl;


    while(choice!=9){
        std::cout<<"\nWhat do you want to be washed";
        std::cout<<"\n1. Towel\n2. Sheet\n3. Shalwar Kamees\n4. Pant\n5. Shirt\n6. Trouser\n7. Nicker\n8. T-Shirt\n9. Want to leave the laundry function:\n";
        std::cin>>choice;
        if(choice==1){
            std::cout<<"Enter Quantity of Towels: ";
            std::cin>>quantity;
            record<<std::endl<<"Towels = "<<quantity;   
        }
        else if(choice==3){
            std::cout<<"Enter Quantity of Shalwar Kamees: ";
            std::cin>>quantity;
            record<<std::endl<<"Shalwar Kamees = "<<quantity;
        }
        else if(choice==4){
            std::cout<<"Enter Quantity of Pants: ";
            std::cin>>quantity;
            record<<std::endl<<"Pants = "<<quantity;
        }
        else if(choice==2){
            std::cout<<"Enter Quantity of Sheets: ";
            std::cin>>quantity;
            record<<std::endl<<"Sheets = "<<quantity;
        }
        else if(choice==5){
            std::cout<<"Enter Quantity of Shirts: ";
            std::cin>>quantity;
            record<<std::endl<<"Shirts = "<<quantity;
        }
        else if(choice==6){
            std::cout<<"Enter Quantity of Trousers: ";
            std::cin>>quantity;
            record<<std::endl<<"Trousers = "<<quantity;
        }
        else if(choice==7){
            std::cout<<"Enter Quantity of Nickers: ";
            std::cin>>quantity;
            record<<std::endl<<"Nickers = "<<quantity;
        }
        else if(choice==8){
            std::cout<<"Enter Quantity of T-Shirts: ";
            std::cin>>quantity;
            record<<std::endl<<"T-Shirts = "<<quantity;
        }
        else if(choice==9){
            record<<std::endl<<",";
            while(record.eof())     // read till end of file        
                { 
                    record<<s;
                    if (s==",")
                    {

                    }
                    else
                        std::cout << s << std::endl;  
          
                }
    
            break;
        }

        else{
            std::cout<<"Invalid Input.";
        }
    }

    
    while(record.eof())     // read till end of file        
    { 
        
        
        std::cout << s << std::endl;  
          
    }
    record.close();
    
}
#endif