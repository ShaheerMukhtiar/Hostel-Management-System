#ifndef ROOM_H
#define ROOM_H

#include "utility.h"
#include "student.h"
struct st_data 
{
    std::string name;
    std::string cat;
    int reg_no;
    int degree;
    std::string dept;
    int room_no;
    int op_no;
    int day1,month1,year1;
    int day2,month2,year2;
};
void allocate (int room[],struct st_data *a,int s_no);
void allocate (int room[],struct st_data *a,int s_no)
{
    const int b=4; //length of room array
    int room_pref=0;
    bool allot;
    std::cout<<"Enter your preferred room no(1-4): ";
    std::cin>>room_pref;
    //checking for vacancy
    for(int i=1;i<=b;i++){
        if(a[i].room_no==i)
            room[i]+=1;
    }
    //checking for slot in preffered room no.
    for(int i=1;i<=b;i++){
        if((room[i]<4)&&(i==room_pref)){
            std::cout<<"You have been alloted a slot in room no. "<<i<<std::endl;
            allot=true;
            a[s_no].room_no=i;
            break;
        }
    }
    //in case, slot isn't free in preffered room no.
    if(allot==0){
        for (int i=1;i<=b;i++){
            if(room[i]<4)
                {
                    std::cout<<"Sorry,we can't provide you a slot in room no. "<<room_pref<<".However, you have been alloted a slot in room no."<<i<<std::endl;
                    a[s_no].room_no=i;
                }
        }
    }
}
void room ()
{
    std::string in_data1;
    int in_data2=0;
    const int a=1,b=4;
    struct st_data arr [a];
    int room[b]={};
    int opcode=0,user_reg=0,s_no=0;
    std::fstream stu_data;
    stu_data.open("MISC.txt",std::ios::out);
    if (stu_data.is_open()) {
        //data to be entered by admin
        for (int j=0;j<a;j++)
        {
        std::cout<<"Enter data of student no. "<<j+1<<std::endl;
        std::cout<<"Enter name\n";
        std::getline(std::cin>>std::ws,in_data1);
        stu_data<<in_data1<<std::endl;
        std::cout<<"Enter category (NC/PC/ASC)\n";
        std::getline(std::cin>>std::ws,in_data1);
        stu_data<<in_data1<<std::endl;
        std::cout<<"Enter RFID card no\n";
        std::cin>>in_data2;
        stu_data<<in_data2<<std::endl;
        std::cout<<"Enter degree\n";
        std::cin>>in_data2;
        stu_data<<in_data2<<std::endl;
        std::cout<<"Enter department (CE/ME/EE/MTS)\n";
        std::getline(std::cin>>std::ws,in_data1);
        stu_data<<in_data1<<std::endl;
        std::cout<<"Enter room no.\n";
        std::cin>>in_data2;
        stu_data<<in_data2<<std::endl;
        }
        stu_data.close();
    } 
    stu_data.open("s_info.txt",std::ios::in);
    if(stu_data.is_open()){
        for(int i=0;i<a;i++)
    {
        std::getline(stu_data>>std::ws,arr[i].name);
        std::getline(stu_data>>std::ws, arr[i].cat);
        stu_data >>arr[i].reg_no ;
        stu_data>>arr[i].degree;
        std::getline(stu_data>>std::ws,arr[i].dept);
        stu_data>>arr[i].room_no;
    }
     stu_data.close();
    }
    //data to be entered by student
    std::cout<<"Enter your RFID card no.\n";
    std::cin>>user_reg;
    for(int i=0;i<a;i++)
    {
        if(arr[i].reg_no==user_reg)
        {
            s_no=i; //accessing student's data through RFID card no.
            break;
        }
    }
    do{
        std::cout<<"1: room allocation/deallocation\n0: exit\n";
        std::cout<<"Enter your choice: ";
        std::cin>>opcode;
        std::cout<<std::endl;
        if(opcode==1)
            allocate(room,&arr[s_no],s_no);
        else
            break;
    }while(opcode!=0);
    
}
#endif