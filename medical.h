#ifndef MEDICAL_H
#define MEDICAL_H
#include "utility.h"
#include "student.h"
void medical (void);
void medical(void)
{
    int opcode_m=0;
    std::cout<<"1: book ur appointment\n2: check doctor's availability\n3: check ambulance's availability\n4: call ambulance\n0: exit\n";
    std::cout<<"Enter your choice: ";
    std::cin>>opcode_m;
    std::cout<<std::endl;
    switch(opcode_m)
    {
        case 1:
        {
            std::cout<<"You have booked your appointment on "<<(1 + rand() % 31)<<"/"<<(1 + rand() % 12)<<"/2023 at "<<(1+rand()%24)<<":"<<1+rand()%60<<".\n"<<std::endl;
            break;
        }
        case 2:
        {
            if(rand()%2==0)
                std::cout<<"Doctor is available.\n";
            else 
                        std::cout<<"Doctor isn't available.\n";
                    break;
        }
        case 3:
        {
            if(rand()%2==0)
                std::cout<<"Ambulance is available.\n";
            else 
                std::cout<<"Ambulance isn't available.\n";
                break;
        }
        case 4:
        {
            std::cout<<"Call 051-1111111\n";
            break;
        }
        case 0:
        {
            break;
        }
    }
}
void Medical ()
{
    int opcode=0; 
    do{
        std::cout<<"1:medical facilities\n0: exit\n";
        std::cout<<"Enter your choice: ";
        std::cin>>opcode;
        std::cout<<std::endl;
        if(opcode==1)
            medical ();
        else
            break;
    }while(opcode!=0);
    
}
#endif