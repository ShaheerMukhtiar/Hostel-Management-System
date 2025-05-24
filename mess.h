#include "utility.h"
#ifndef MESS_H
#define MESS_H
#include "student.h"

                                //Mess management data

                                //day generator
void day(std::string &d){
    time_t now = time(nullptr);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%A", localtime(&now));
    d=buffer;
    }

                            // Month Name Generator
void month_name(std::string &monthName2){
    std::string currentDate = __DATE__;
    std::string monthName = currentDate.substr(0, 3);
    monthName2=monthName;
    
}
void read(student_data* student,std::string filename,std::string reg)
{
    std::fstream id_data;
    
    std::string reg_no;

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
            if(student->reg_no==reg)
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
void update(std::string filename,int tuckbill,int m_bill,std::string reg_no)
{
    
    student_data studentstr;
    std::fstream id_data;
    id_data.open(filename,std::ios::in);
    std::string line,new_password,replacestr;
    size_t comma1, comma2, comma3,comma4,comma5,comma6;
    std::cin.ignore();
    system("cls");
    Sleep(40);

    read(&studentstr,filename,reg_no);

    
    replacestr=studentstr.reg_no+','+studentstr.name+','+studentstr.password+','+studentstr.dept+','
        +studentstr.messbill+','+studentstr.tuckbill+','+ studentstr.laundrybill;

    
    int numberTuck;
    numberTuck=numberTuck+tuckbill;    
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
        studentstr.messbill=m_bill;

        studentstr.tuckbill=std::to_string(numberTuck);
        std::cin.ignore();
        Sleep(40);    

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

//days out
int days_out(int difference){
    // Getting the initial date from the user
    int day1, month1, year1;
    std::cout << "Want your mess out \nFrom (DD MM YYYY): ";
    std::cin >> day1 >> month1 >> year1;

    // Getting the final date from the user
    int day2, month2, year2;
    std::cout << "Till (DD MM YYYY): ";
    std::cin >> day2 >> month2 >> year2;

    // Converting the dates to time_t format
    struct tm time1 = {0, 0, 0, day1, month1 - 1, year1 - 1900};
    struct tm time2 = {0, 0, 0, day2, month2 - 1, year2 - 1900};
    time_t t1 = mktime(&time1);
    time_t t2 = mktime(&time2);

    // Calculating the difference in days
    difference = (int) difftime(t2, t1) / (60 * 60 * 24);
    return difference;
}



//Menu function
void menu(){
    system("cls");
    int choice;
    std::cout<<"\n\nWhat do you want to check\n1.Todays Menu\n2.Weekly Menu\n3.Enter 3 to return to main mess function:\n";
    std::cin>>choice;
    std::cout<<choice<<" is the choice";
    std::string d;
    day(d);

    while(choice!=3){
        switch(choice){
            case 1:
            system("cls");
            std::cout<<"\n\nToday's Menu\n";
            if(d=="Monday"){
                std::cout<<"Breakfast"<<std::setw(17)<<"Lunch"<<std::setw(17)<<"Dinner"<<std::endl;
                std::cout<<std::setw(19)<<"Bhujiya-Paratha-Tea"<<std::setw(17)<<"Daal-Meal-Achar"<<std::setw(17)<<"Beef Pulao-Raita";
            }
            else if(d=="Tuesday"){
                std::cout<<"Breakfast"<<std::setw(19)<<"Lunch"<<std::setw(27)<<"Dinner"<<std::endl;
                std::cout<<std::setw(15)<<"Egg-Paratha-Tea"<<std::setw(31)<<"Boiled Rice-Salad-Fruit"<<std::setw(28)<<"Chicken Haleem-Naan-Salad"<<std::endl;
            }
            else if(d=="Wednesday"){
                std::cout<<"Breakfast"<<std::setw(22)<<"Lunch"<<std::setw(23)<<"Dinner"<<std::endl;
                std::cout<<std::setw(19)<<"Channay-Paratha-Tea"<<std::setw(23)<<"Kari Pakora-Meal"<<std::setw(27)<<"Chicken Boneless-Meal"<<std::endl;
            }
            else if(d=="Thursday"){
                std::cout<<"Breakfast"<<std::setw(25)<<"Lunch"<<std::setw(18)<<"Dinner"<<std::endl;
                std::cout<<std::setw(21)<<"Slice-Jam-Egg-Paratha"<<std::setw(17)<<"Daal-Meal"<<std::setw(33)<<"Chicken Biryani-Ice Cream"<<std::endl;
            }
            else if(d=="Friday"){
                std::cout<<"Breakfast"<<std::setw(21)<<"Lunch"<<std::setw(28)<<"Dinner"<<std::endl;
                std::cout<<std::setw(17)<<"Slice-Jam--Egg-Tea"<<std::setw(25)<<"Chicken Kari-Pulao"<<std::setw(27)<<"Mix Vegetable-Meal"<<std::endl;
            }
            else if(d=="Saturday"){
                std::cout<<"Breakfast"<<std::setw(15)<<"Lunch"<<std::setw(22)<<"Dinner"<<std::endl;
                std::cout<<std::setw(15)<<"Egg-Paratha-Tea"<<std::setw(22)<<"Chicken Kari-Pulao"<<std::setw(15)<<"Channay-Pulao"<<std::endl;
            }
            else if(d=="Sunday"){
                std::cout<<"Breakfast"<<std::setw(18)<<"Lunch"<<std::setw(16)<<"Dinner"<<std::endl;
                std::cout<<std::setw(20)<<"Chicken Channay-Naan"<<std::setw(15)<<"Biryani-Salad"<<std::setw(21)<<"Chicken Achari-Meal"<<std::endl;
            }
            break;
        
                                                   //Weekly Menu
            case 2:
            system("cls");
            std::cout<<"\n\nWeekly Menu:\n";
            std::cout<<"Day"<<std::setw(20)<<"Breakfast"<<std::setw(24)<<"Lunch"<<std::setw(30)<<"Dinner"<<std::endl;
            std::cout<<"Monday"<<std::setw(27)<<"Bhujiya-Paratha-Tea"<<std::setw(24)<<"Daal-Meal-Achar"<<std::setw(30)<<"Beef Pulao-Raita"<<std::endl;
            std::cout<<"Tuesday"<<std::setw(22)<<"Egg-Paratha-Tea"<<std::setw(36)<<"Boiled Rice-Salad-Fruit"<<std::setw(33)<<"Chicken Haleem-Naan-Sa>>lad"<<std::endl;
            std::cout<<"Wednesday"<<std::setw(24)<<"Channay-Paratha-Tea"<<std::setw(25)<<"Kari Pakora-Meal"<<std::setw(34)<<"Chicken Boneless-Meal"<<std::endl;
            std::cout<<"Thursday"<<std::setw(27)<<"Slice-Jam-Egg-Paratha"<<std::setw(16)<<"Daal-Meal"<<std::setw(45)<<"Chicken Biryani-Ice Cream"<<std::endl;
            std::cout<<"Friday"<<std::setw(26)<<"Slice-Jam--Egg-Tea"<<std::setw(28)<<"Chicken Kari-Pulao"<<std::setw(29)<<"Mix Vegetable-Meal"<<std::endl;
            std::cout<<"Saturday"<<std::setw(21)<<"Egg-Paratha-Tea"<<std::setw(31)<<"Chicken Kari-Pulao"<<std::setw(24)<<"Channay-Pulao"<<std::endl;
            std::cout<<"Sunday"<<std::setw(28)<<"Chicken Channay-Naan"<<std::setw(21)<<"Biryani-Salad"<<std::setw(35)<<"Chicken Achari-Meal"<<std::endl;
            break;

            case3:
            break;

            default:
            std::cout<<"Invalid Input.\n";
            break;
            }


        std::cout<<"\n\nWant to do anything else\n1.Todays Menu\n2.Weekly Menu\n3.Enter 3 to return to main mess function:\nYour Choice: ";
        std::cin>>choice;
    }
}

                                                // In/Out Function
int out(int days){
    int choice;

    std::cout<<"\n\n\nWhat do you want to do\n1. Out Your Mess\n2. Want to leave in/out function.\nYour Choice: ";
    std::cin>>choice;

    while(choice !=2){
        if(choice==1){
            days=days_out(days);
            return days;
        }
        std::cout<<"Press 2 to return to the main mess menu";
        std::cin>>choice;
    }
    
}

                                                    //tukshop management
int tukshop(int tuck_bill)
{
    int ch,quantity;
    tuck_bill=0;
    system("cls");
    std::cout<<"\nWhat you want to buy from tuck shop.\n\n"<<std::setw(8)<<"Menu "<<std::setw(19)<<" unit price";
    std::cout<<"\n1. Nuggets"<<std::setw(13)<<" RS-20\n"<<"2. Kababs"<<std::setw(15) <<" RS-50 \n"<<"3. Sausages"<<std::setw(11)<<" RS-30"
    <<"\n4. Juices"<<std::setw(14)<<" RS-40\n"<<"5. Coldrinks"<<std::setw(10)<<" RS-40"<<
    "\n\n6.Want to return to the mess management:\nYour choice: ";
    std::cin>>ch;

    while(ch!=6){
        system("cls");
        switch (ch)
        {
        case 1:
            std::cout<<"How many Nuggets want you want to buy(RS-20 each): ";
            std::cin>>quantity;
            tuck_bill+=(quantity)*20;
            break;
        case 2:
            std::cout<<"How many Kababs want you want to buy(RS-50 each): ";
            std::cin>>quantity;
            tuck_bill+=(quantity)*50;
            break;
        case 3:
            std::cout<<"How many Sausages want you want to buy(RS-30 each): ";
            std::cin>>quantity;
            tuck_bill+=(quantity)*30;
            break;
        
        case 4:
            std::cout<<"How many Juices want you want to buy(RS-40 each): ";
            std::cin>>quantity;
            tuck_bill+=(quantity)*40;
            break;
        
        case 5:
            std::cout<<"How many Cold Drinks want you want to buy(RS-40 each): ";
            std::cin>>quantity;
            tuck_bill+=(quantity)*40;
            break;

        case 6:
        break;

        default:
        std::cout<<"Invalid request";
        break;
        }

        std::cout<<"\n\nWant to buy anything else:" ;
        std::cout<<"\n1. Nuggets"<<std::setw(13)<<" RS-20\n"<<"2. Kababs"<<std::setw(15) <<" RS-50 \n"<<"3. Sausages"<<std::setw(11)<<" RS-30"
        <<"\n4. Juices"<<std::setw(14)<<" RS-40\n"<<"5. Coldrinks"<<std::setw(10)<<" RS-40"<<
        "\n\n6.Want to return to the mess management:\nyour Choice: ";
        std::cin>>ch;
    }
    return tuck_bill;
}

                      //Monthly Bill
int monthly_bill(int days_out,int tuck_bill)
{
    std::string m_name;
    int m_bill,total_bill;
    month_name(m_name);

    //Monthly Mess bill with days out of mess for months having 31 days.
    if(m_name=="January"||m_name=="March"||m_name=="May"||m_name=="July"||m_name=="August"||m_name=="October"||m_name=="December"){
        m_bill=(31-days_out)*330;
        total_bill=m_bill+tuck_bill;
    }

        //Monthly Mess bill with days out of mess for months having 30 days.
    else if(m_name=="April"||m_name=="June"||m_name=="September"||m_name=="November"){
        m_bill=(30-days_out)*330;
        total_bill=m_bill+tuck_bill;
    }

    //Monthly Mess bill with days out of mess for Febuary.
    else if(m_name=="Febuary"){
        m_bill=(28-days_out)*330;
        total_bill=m_bill+tuck_bill;
    }

    //Total Bill
    return total_bill;
}

                                //main maintain data entry save and choice of the user.
void mess(std::string filename,std::string reg_no){
    int tuckbill,days_out;
    int m_bill;
    std::ofstream record;
    student_data student;
    system("cls");
    std::cout<<"Welcome! to mess managemt system";
   
    //asking the user what to do.
    int op;
    std::cout<<"\n\nWhat you want to do:\n1. Check Menu\n2. Out Your Mess \n3. Want to buy something from Tuk Shop\n4. Check Your Monthly Bill\n5. Want to leave the mess management:\nYour Choice: ";
        std::cin>>op;

    while(op!=5){
        switch (op){
            case 1:
            menu();
            break;

            case 2:
                days_out=out(days_out);
            break;

            case 3:
                tuckbill=tukshop(tuckbill); 
            break;

            case 4:
                m_bill=monthly_bill(days_out,tuckbill);
            break;

            case 5:
            break;

            default:
                std::cout<<"Invalid input.";
            break;
            }            
    
    std::cout<<"\n\nWant to do anything else:\n1. Check Menu\n2. Mess Out \n3. Want to buy something from Tuk Shop\n4. Check Your Monthly Bill\n5. Want to leave the mess management.\nYour choice: ";
    std::cin>>op;
    }
    update(filename,tuckbill,m_bill,reg_no);
    std::cout<<"Thanks for using EME mess services.\n\n";
    return;
}
#endif