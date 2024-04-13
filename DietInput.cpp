#include <iostream>
#include <string>
using namespace std;
#include <limits>

#define MIN_AGE 0
#define MAX_AGE 90
#define MIN_HEIGHT 1.0
#define MAX_HEIGHT 3.0
#define MIN_WEIGHT 1.0
#define MAX_WEIGHT 500.0

class dietdetails 
{
private:
    string fname;
    string lname;
    char sex;
    string bloodType;
    float height;
    float weight;
    int age;

public:
    // Function to input user details
    void inputUserDetails() 
    {
        
           
            bool isvalid=false;
            while(!isvalid)
            {
            cout << "Enter First name: ";
            cin>>fname;
            for(char c:fname)
            {
                if(!isalpha(c))
                {
                    cout<<"Invalid Input. Please try again.."<<endl;
                    isvalid=false;
                    break;
                }
                isvalid=true;
            }
            
            }
            isvalid=false;
            while(!isvalid)
            {
            cout << "Enter last name: ";
            cin>>lname;
            for(char c:lname)
            {
                if(!isalpha(c))
                {
                    cout<<"Invalid Input. Please try again.."<<endl;
                    isvalid=false;
                    break;
                }
                isvalid=true;
            }
            }
            isvalid=false;
            
            
            
            while (!isvalid) {   
            cout << "Enter sex (M/F): ";
            cin >> sex;
            if (sex != 'M' && sex != 'F') {
                isvalid = false;
                cout << "Invalid Input. Please try Again" << endl;
            } else {
                isvalid = true;
            }
            }   

            isvalid=false;
            while(!isvalid)
            {
            cout << "Enter blood type: ";
            cin.ignore(); 
            cin>>bloodType;
            if(bloodType != "A+" && bloodType != "A-" &&bloodType != "B+" && bloodType != "B-" &&bloodType != "AB+" && bloodType != "AB-" &&bloodType != "O+" && bloodType != "O-")
            {
                isvalid=false;
                cout<<"Invalid Input. Please try Again \n Tip: (Please add postive(+) and negative(-) and try again."<<endl;
            }
            else{
                isvalid=true;
            }
            }
            isvalid=false;
            while(!isvalid)
            {
                cout << "Enter height (in meters): ";
                cin >> height;
                if (cin.fail() || height < MIN_HEIGHT || height > MAX_HEIGHT) {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Invalid input. Please enter a number between " << MIN_HEIGHT << " and " << MAX_HEIGHT << "." << endl;
                    isvalid=false;
                } 
                else 
                {
                    isvalid=true;
                    break; 
                }
            }
    
            
            isvalid=false;
            while(!isvalid)
            {
                cout << "Enter weight (in kilograms): ";
                cin >> weight;
                if (cin.fail() || weight < MIN_WEIGHT || weight > MAX_WEIGHT) {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Invalid input. Please enter a number between " << MIN_WEIGHT << " and " << MAX_WEIGHT << "." << endl;
                    isvalid=false;
                } 
                else {
                    isvalid=true;
                    break; 
                }
            }
            isvalid=false;
            while(!isvalid)
            {
                cout << "Enter age: ";
                cin >> age;
                if (cin.fail() || age < MIN_AGE || age > MAX_AGE) {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Invalid input. Please enter a number between " << MIN_AGE << " and " << MAX_AGE << "." << endl;
                    isvalid=false;
                } 
                else 
                {
                    isvalid=true;
                    break; 
                }
            }
            
            
    }

    // Function to calculate BMI
    float calculateBMI() 
    {
        return weight / (height * height);
    }

    // Function to calculate Fat Percentage
    float calculateFatPercentage() 
    {
        float bmi = calculateBMI();
        if (sex == 'M') {
            return (1.2 * bmi) + (0.23 * age) - 5.4 - (10.8 * (sex == 'M'));
        } else {
            return (1.2 * bmi) + (0.23 * age) - 16.2 - (10.8 * (sex == 'F'));
        }
    }

    // Function to determine diet plan
    void determineDietPlan() {
        float bmi = calculateBMI();
        float fatPercentage = calculateFatPercentage();

        cout << "BMI: " << bmi << endl;
        cout << "Fat Percentage: " << fatPercentage << endl;

        if (bmi < 18.5 || (sex == 'M' && fatPercentage < 14) || (sex == 'F' && fatPercentage < 20)) {
            cout <<"yaha apna normal logo ka diet plan aayega" << endl;
        } else {
            
            cout << "idhar apne usse khud ka diet plan banwayenge " << endl;
        }
    }
};