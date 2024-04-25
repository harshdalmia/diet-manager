#include <iostream>
#include "DietInput.cpp"
#include "dietplan.cpp"
#include "usserdiet.cpp"
#include "drinkingwater.cpp"
using namespace std;

int main()
{   
    int choice;
    cout<<"Hello User!, Please Enter Your details"<<endl;
    dietdetails d;
    d.inputUserDetails();
    d.determineDietPlan();
    cout<<d.fname<<", You are "<<d.goal<<endl;
    string goal=d.goal;
    bool veg=d.veg;
    DietType *s;
    bool isok=false;
    while(!isok)
    {
    cout << "Please Select an option below:" << endl;
    cout << "1. Create your own diet plan" << endl;
    cout << "2. Suggestion of our diet plan" << endl;
    cout<< "3. Or would you like to proceed with drinking water recording system "<<endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    if(choice==2)
    {
        
        if(veg==true){
            VegDiet a(goal);
            a.printDietPlan();
        }
        else {
            NonVegDiet a(goal);
            a.printDietPlan();
        }
        isok=true;
        

        }
        
    if(choice==1)
    {
        breakfast();
        lunch();
        snacks();
        dinner();
        display(goal);
        isok=true;
    }
    if(choice==4)
    {
        cout<<"Successfully Exited...";
        isok=true;
    }
    if(choice==3)
    {
        manageWater();
    }
    if(choice<=0||choice>4)
    {
        cout<<"Invalid Input, Please try again"<<endl;
        isok=false;
    }
    }
}