#include <iostream>
#include <string>
using namespace std;
int totalbfoodcal;
int losscal,gaincal,maintaincal;
void variables(int l,int g,int m)
{
    losscal= l;
    gaincal=g;
    maintaincal =m;
}
void breakfast()
{
    cout<<" please enter nmber of items you eat in breakfaast"<<endl;
    int itemsb;
    cin>>itemsb;
    string bfooditems[itemsb];
    int bfooditemscal[itemsb];
    for(int i =0;i<itemsb;i++)
    {
        cout<<"enter food name "<<endl;
        cin>>bfooditems[i];
        cout<<"enter the calories  of "<<bfooditems[i]<<endl;
        cin>>bfooditemscal[i];
        totalbfoodcal+=bfooditemscal[i];
    }
}
 int totallfoodcal;
void  lunch()
{
    cout<<" please enter nmber of items you eat in lunch"<<endl;
    int itemsl;
    cin>>itemsl;
    string lfooditems[itemsl];
    int lfooditemscal[itemsl];
   
    for(int i =0;i<itemsl;i++)
    {
        cout<<"enter food name "<<endl;
        cin>>lfooditems[i];
        cout<<"enter the calories  of "<<lfooditems[i]<<endl;
        cin>>lfooditemscal[i];
        totallfoodcal+=lfooditemscal[i];
    }
}
int  totalsfoodcal;
void snacks()
{
    cout<<" please enter nmber of items you eat in snacks"<<endl;
    int itemss;
    cin>>itemss;
    string sfooditems[itemss];
    int sfooditemscal[itemss];
   
    for(int i =0;i<itemss;i++)
    {
        cout<<"enter food name "<<endl;
        cin>>sfooditems[i];
        cout<<"enter the calories  of "<<sfooditems[i]<<endl;
        cin>>sfooditems[i];
        totalsfoodcal=totalsfoodcal+sfooditemscal[i];
    }
}
int totaldfoodcal;
void dinner(){
    cout<<" please enter nmber of items you eat in snacks"<<endl;
    int itemsd;
    cin>>itemsd;
    string dfooditems[itemsd];
    int dfooditemscal[itemsd];
   
    for(int i =0;i<itemsd;i++)
    {
        cout<<"enter food name "<<endl;
        cin>>dfooditems[i];
        cout<<"enter the calories  of "<<dfooditems[i]<<endl;
        cin>>dfooditems[i];
        totaldfoodcal=totaldfoodcal +dfooditemscal[i];
    }
}
int finalcalories= totalbfoodcal+totallfoodcal+totalsfoodcal+totaldfoodcal;
void display(string goals) 
{
    cout<< "your total calories are"<<finalcalories<<endl;
    if(goals=="Underweight")
    {
        cout<<"your reqired calories are"<<losscal<<endl;//need to enter required caloreies;
        if(finalcalories-losscal>0)
        {
            cout << "you need to create a deficit of" <<(finalcalories-losscal)<<endl;//need to enter finalcalories -requiredcalories and either deficit or surplus
        }
        else if(finalcalories-losscal<=0)
        {
            cout << "you can continue your diet plan" <<(finalcalories-losscal)<<endl;//need to enter finalcalories -requiredcalories and either deficit or surplus
        }
    }  
    if(goals=="Overweight")
    {
        cout<<"your reqired calories are"<<gaincal<<endl;//need to enter required caloreies;
        if(finalcalories-gaincal>0)
        {
            cout << "you need to create a deficit of"<<(finalcalories-gaincal) <<endl;//need to enter finalcalories -requiredcalories and either deficit or surplus
        }
        else if(finalcalories-gaincal<=0)
        {
            cout << "you can continue your diet plan"<<(finalcalories-gaincal)<<endl;//need to enter finalcalories -requiredcalories and either deficit or surplus
        }
    }
    if(goals=="Healthy")
    {
        cout<<"your reqired calories are"<<maintaincal<<endl;//need to enter required caloreies;
        if(finalcalories-maintaincal>0)
        {
            cout << "you need to create a deficit of"<<(finalcalories-maintaincal) <<endl;
        }
        else if(finalcalories-maintaincal==0)
        {
            cout << "you can continue your diet plan" <<endl;
        }
        else
        {
            cout<< "you need to create a surplus of"<<(finalcalories-maintaincal)<<endl;
        }
}
}


