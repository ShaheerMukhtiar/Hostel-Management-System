#ifndef OUTPASS_H_
#define OUTPASS_H_

#include "utility.h"
#include "student.h"
struct std_data 
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
int outpass (struct std_data *a,int s_no,int *outpass_no)
{
    std::string place;
    std::cout<<"Where will you be proceeding to?";
    std::getline(std::cin>>std::ws,place);
    std::cout << "Enter the initial date (DD MM YYYY): ";
    std::cin >> a[s_no].day1 >> a[s_no].month1 >> a[s_no].year1;
    std::cout << "Enter the final date (DD MM YYYY): ";
    std::cin>>a[s_no].day2>>a[s_no].month2>>a[s_no].year2 ;
    // Converting the dates to time_t format
    struct tm time1 = {0, 0, 0, a[s_no].day1, a[s_no].month1 - 1, a[s_no].year1 - 1900};
    struct tm time2 = {0, 0, 0, a[s_no].day2,a[s_no].month2 - 1,a[s_no].year2 - 1900};
    time_t t1 = mktime(&time1);
    time_t t2 = mktime(&time2);
    int difference = (int) difftime(t2, t1) / (60 * 60 * 24);
    std::cout << "You're applying for "<< difference+1 << " days leave." <<std::endl;
    *outpass_no+=1;
    a[s_no].op_no=*outpass_no;
    std::cout<<"Outpass No."<<a[s_no].op_no<<std::endl<<a[s_no].cat<<" "<<a[s_no].name<<" from "<<a[s_no].dept<<"-"<<a[s_no].degree<<" having registration no. "<<a[s_no].reg_no<<" is allowed to proceed to "<<place<<" from "<<a[s_no].day1<<"/"<<a[s_no].month1<<"/"<<a[s_no].year1<<" to "<<a[s_no].day2<<"/"<<a[s_no].month2<<"/"<<a[s_no].year2<<".\n";
    return *outpass_no;
}
void Outpass ()
{
    std::string in_data1;
    int in_data2=0;
    const int a=1;
    struct std_data arr [a];
    int outpass_no=0;
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
            s_no=i;
            break;
        }
    }
    do{
        std::cout<<"1: apply for outpass\n0: exit\n";
        std::cout<<"Enter your choice: ";
        std::cin>>opcode;
        std::cout<<std::endl;
        if(opcode!=0)
            outpass_no=outpass(&arr[s_no],s_no,&outpass_no);
        else
            break;
    }while(opcode!=0);
    
}
#endif