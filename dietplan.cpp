#include <iostream>
#include <string>
#include "DietInput.cpp"
using namespace std;

class DietType {
public:
    struct DietPlan 
    {
        string vegbreakfast;
        int breakfastCalories;
        string veglunch;
        int lunchCalories;
        string vegsnacks;
        int snacksCalories;
        string vegdinner;
        int dinnerCalories;
        string nonvegbreakfast;
        string nonveglunch;
        string nonvegsnacks;
        string nonvegdinner;
        int mcal;
        int gcal;
        int lcal;
    };

public:
    DietType() {
        // Set default values for all variables
        dietPlan.vegbreakfast = "Oatmeal with fruits";
        dietPlan.breakfastCalories = 500;
        dietPlan.veglunch = "Vegetable salad with tofu";
        dietPlan.lunchCalories = 600;
        dietPlan.vegsnacks = "Carrot sticks with hummus";
        dietPlan.snacksCalories = 350;
        dietPlan.vegdinner = "Quinoa with mixed vegetables";
        dietPlan.dinnerCalories = 650;
        dietPlan.nonvegbreakfast = "Scrambled eggs with whole grain toast";
        dietPlan.nonveglunch = "Grilled chicken breast with brown rice";
        dietPlan.nonvegsnacks =  "Greek yogurt with almonds";
        dietPlan.nonvegdinner = "Baked salmon with steamed vegetables" ;
        int mcal = 2100;
        int gcal = 2550;
        int lcal = 1650;
    }

    virtual void printDietPlan() const = 0;

public:
    DietPlan dietPlan;
};

class VegDiet : public DietType {
public:
    VegDiet(string goal) {
    this->goal = goal;
        // Adjust calories based on goal
        if (goal == "Underweight") {
            dietPlan.breakfastCalories -= 100;
            dietPlan.lunchCalories -= 100;
            dietPlan.snacksCalories -= 50;
            dietPlan.dinnerCalories -= 200;
        } else if (goal == "Overweight") {
            dietPlan.breakfastCalories += 100;
            dietPlan.lunchCalories += 100;
            dietPlan.snacksCalories += 50;
            dietPlan.dinnerCalories += 200;
        }
    }

    void printDietPlan() const override {
        cout << "----- Veg Diet Plan -----" << endl;
        cout << "Breakfast: " << dietPlan.vegbreakfast << " (Calories: " << dietPlan.breakfastCalories << ")" << endl;
        cout << "Lunch: " << dietPlan.veglunch << " (Calories: " << dietPlan.lunchCalories << ")" << endl;
        cout << "Snacks: " << dietPlan.vegsnacks << " (Calories: " << dietPlan.snacksCalories << ")" << endl;
        cout << "Dinner: " << dietPlan.vegdinner << " (Calories: " << dietPlan.dinnerCalories << ")" << endl;
    }

public:
    string goal;
};

class NonVegDiet : public DietType {
public:
    NonVegDiet(string goal) {
    this->goal = goal;
        // Adjust calories based on goal
        if (goal == "Underweight") {
            dietPlan.breakfastCalories -= 100;
            dietPlan.lunchCalories -= 100;
            dietPlan.snacksCalories -= 50;
            dietPlan.dinnerCalories -= 200;
        } else if (goal == "Overweight") {
            dietPlan.breakfastCalories += 100;
            dietPlan.lunchCalories += 100;
            dietPlan.snacksCalories += 50;
            dietPlan.dinnerCalories += 200;
        }
    }

    void printDietPlan() const override {
        cout << "----- Non Veg Diet Plan -----" << endl;
        cout << "Breakfast: " << dietPlan.nonvegbreakfast << " (Calories: " << dietPlan.breakfastCalories << ")" << endl;
        cout << "Lunch: " << dietPlan.nonveglunch << " (Calories: " << dietPlan.lunchCalories << ")" << endl;
        cout << "Snacks: " << dietPlan.nonvegsnacks << " (Calories: " << dietPlan.snacksCalories << ")" << endl;
        cout << "Dinner: " << dietPlan.nonvegdinner << " (Calories: " << dietPlan.dinnerCalories << ")" << endl;
    }

public:
    string goal;
};


int func() {
    DietType *dietType;
    dietdetails d;
    d.inputUserDetails();
    d.determineDietPlan();
    string diet;

    if (d.veg==1) {
        diet = new VegDiet(d.goal);
    } else if (d.veg==0) {
        diet = new NonVegDiet(d.goal);
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    diet->printDietPlan();
    return 0;
}
int main() {
    func();
    return 0;
}
