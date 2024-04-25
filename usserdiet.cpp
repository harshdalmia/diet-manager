#include <iostream>
#include <string>
#include <limits>
using namespace std;
int totalbfoodcal;
int losscal=2550,gaincal=1650,maintaincal=2100;

void breakfast()
{
    cout<<"Please enter the number of items you eat in breakfast: "<<endl;
    int itemsb;
    cin>>itemsb;
    string bfooditems;
    int bfooditemscal;
    for(int i =0;i<itemsb;i++)
    {
        cout<<"Enter food name "<<i+1<<endl;
        cin>>bfooditems;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Enter the calories of "<<bfooditems<<endl;
        cin>>bfooditemscal;
        totalbfoodcal+=bfooditemscal;
    }
}
int totallfoodcal;
void  lunch()
{
    cout<<"Please enter the number of items you eat in lunch"<<endl;
    int itemsl;
    cin>>itemsl;
    string lfooditems;
    int lfooditemscal;
   
    for(int i =0;i<itemsl;i++)
    {
        cout<<"Enter food name "<<i+1<<endl;
        cin>>lfooditems;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Enter the calories  of "<<lfooditems<<endl;
        cin>>lfooditemscal;
        totallfoodcal+=lfooditemscal;
    }
}
int  totalsfoodcal;
void snacks()
{
    cout<<"Please enter the number of items you eat in snacks"<<endl;
    int itemss;
    cin>>itemss;
    string sfooditems;
    int sfooditemscal;
   
    for(int i =0;i<itemss;i++)
    {
        cout<<"Enter food name "<<i+1<<endl;
        cin>>sfooditems;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Enter the calories  of "<<sfooditems<<endl;
        cin>>sfooditemscal;
        totalsfoodcal=totalsfoodcal+sfooditemscal;
    }
}
int totaldfoodcal;
void dinner(){
    cout<<"Please enter the number of items you eat in dinner "<<endl;
    int itemsd;
    cin>>itemsd;
    string dfooditems;
    int dfooditemscal;
   
    for(int i =0;i<itemsd;i++)
    {
        cout<<"Enter food name "<<i+1<<endl;
        cin>>dfooditems;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Enter the calories  of "<<dfooditems<<endl;
        cin>>dfooditemscal;
        totaldfoodcal=totaldfoodcal +dfooditemscal;
    }
}
int finalcalories;
void display(string goals) 
{
    cout<<goals;
    finalcalories= totalbfoodcal+totallfoodcal+totalsfoodcal+totaldfoodcal;
    cout<< "Your total calories are: "<<finalcalories<<endl;
    if(goals=="Underweight")
    {
        cout<<"Your required calories are "<<losscal<<endl;//need to enter required caloreies;
        if(finalcalories-losscal>0)
        {
            cout << "You need to create diet plan a deficit of " <<(finalcalories-losscal)<<"calories"<<endl;//need to enter finalcalories -requiredcalories and either deficit or surplus
        }
        else if(finalcalories-losscal<=0)
        {
            cout << "You can continue with your diet plan " <<(finalcalories-losscal)<<endl;//need to enter finalcalories -requiredcalories and either deficit or surplus
        }
    }  
    if(goals=="Overweight")
    {
        cout<<"Your required calories are "<<gaincal<<endl;//need to enter required caloreies;
        if(finalcalories-gaincal>0)
        {
            cout << "You need to create a diet plan deficit of "<<(finalcalories-gaincal)<<"calories" <<endl;//need to enter finalcalories -requiredcalories and either deficit or surplus
        }
        else if(finalcalories-gaincal<=0)
        {
            cout << "You can continue with your diet plan "<<(finalcalories-gaincal)<<endl;//need to enter finalcalories -requiredcalories and either deficit or surplus
        }
    }
    if(goals=="Healthy")
    {
        cout<<"Your required calories are: "<<maintaincal<<endl;//need to enter required caloreies;
        if(finalcalories-maintaincal>0)
        {
            cout << "You need to create a diet plan deficit of "<<(finalcalories-maintaincal)<<"calories" <<endl;
        }
        else if(finalcalories-maintaincal==0)
        {
            cout << "You can continue with your diet plan" <<endl;
        }
        else
        {
            cout<< "You need to create a diet plan surplus of "<<(finalcalories-maintaincal)<<"calories"<<endl;
        }
}
}
