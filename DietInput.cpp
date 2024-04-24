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
public:
    string fname;
    string lname;
    char sex;
    string bloodType;
    float height;
    float weight;
    int age;
    string dietype;
    string goal;
    

    bool veg;
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

        isvalid = false;

        while (!isvalid) 
        {
            cout << "Enter blood type: ";
            cin >> bloodType;

            if (bloodType != "A+" && bloodType != "A-" && bloodType != "B+" && bloodType != "B-" &&bloodType != "AB+" && bloodType != "AB-" && bloodType != "O+" && bloodType != "O-") {
                isvalid = false;
                cout << "Invalid Input. Please try again using A+/B- in the exact way." << endl;
            } 
            else {
                isvalid = true;
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
            cout << "Enter Diet(Vegetarian/Non-Vegetarian): ";
            cin >> dietype;
            if(dietype!="Vegetarian" && dietype!="Non-Vegetarian" && dietype!="vegetarian" && dietype!="non-vegetarian" && dietype!="Non-vegetarian"){
                cout<<"Invalid input. please type between Vegetarian or Non-vegetarian"<<endl;

            }
            else{
                isvalid=true;
                break;
            }


        }
        if(dietype=="Vegetarian"&&"vegetarian")
            {
                veg=true;
            }
        else{
            veg=false;
        }

    };

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
            return (1.2 * bmi) + (0.23 * age) - 16.2 ;
        } else {
            return (1.2 * bmi) + (0.23 * age) - 5.4;
        }
    }

    // Function to determine diet plan
    void determineDietPlan()
    {
    float bmi = calculateBMI();
    float fatPercentage = calculateFatPercentage();

    cout << "BMI: " << bmi << endl;
    cout << "Fat Percentage: " << fatPercentage << endl;
    

    if (sex == 'M') {
        if (bmi < 18.5) {
            goal = "Underweight";
        } else if (bmi >= 18.5 && bmi < 25) {
            goal = "Healthy";
        } else {
            goal = "Overweight";
        }
    } else if (sex == 'F') {
        if (bmi < 18.5) {
            goal = "Underweight";
        } else if (bmi >= 18.5 && bmi < 25) {
            goal = "Healthy";
        } else {
            goal = "Overweight";
        }
    
    }
    
    

    }
}; 
