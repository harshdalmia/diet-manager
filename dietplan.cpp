#include <iostream>
#include <string>
using namespace std;

class DietType {
public:
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

public:
    DietType() {
        // Set default values for all variables
        vegbreakfast = "Oatmeal with fruits";
        breakfastCalories = 500;
        veglunch = "Vegetable salad with tofu";
        lunchCalories = 600;
        vegsnacks = "Carrot sticks with hummus";
        snacksCalories = 350;
        vegdinner = "Quinoa with mixed vegetables";
        dinnerCalories = 650;
        nonvegbreakfast = "Scrambled eggs with whole grain toast";
        nonveglunch = "Grilled chicken breast with brown rice";
        nonvegsnacks =  "Greek yogurt with almonds";
        nonvegdinner = "Baked salmon with steamed vegetables" ;
        mcal = 2100;
        gcal = 2550;
        lcal = 1650;
    }

    virtual void printDietPlan() const = 0;

};

class VegDiet : public DietType {
public:
    VegDiet(string goal) {
    this->goal = goal;
        // Adjust calories based on goal
        if (goal == "Underweight") {
            breakfastCalories -= 100;
            lunchCalories -= 100;
            snacksCalories -= 50;
            dinnerCalories -= 200;
        } else if (goal == "Overweight") {
            breakfastCalories += 100;
            lunchCalories += 100;
            snacksCalories += 50;
            dinnerCalories += 200;
        }
    }

    void printDietPlan() const override {
        cout << "----- Veg Diet Plan -----" << endl;
        cout << "Breakfast: " << vegbreakfast << " (Calories: " << breakfastCalories << ")" << endl;
        cout << "Lunch: " << veglunch << " (Calories: " << lunchCalories << ")" << endl;
        cout << "Snacks: " <<vegsnacks << " (Calories: " << snacksCalories << ")" << endl;
        cout << "Dinner: " <<vegdinner << " (Calories: " << dinnerCalories << ")" << endl;
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
            breakfastCalories -= 100;
            lunchCalories -= 100;
            snacksCalories -= 50;
            dinnerCalories -= 200;
        } else if (goal == "Overweight"){
        breakfastCalories += 100;    
        lunchCalories += 100;   
        snacksCalories += 50;    
        dinnerCalories += 200;
        }
    }

    void printDietPlan() const override {
        cout << "----- Non Veg Diet Plan -----" << endl;
        cout << "Breakfast: " << nonvegbreakfast << " (Calories: " <<breakfastCalories << ")" << endl;
        cout << "Lunch: " << nonveglunch << " (Calories: " << lunchCalories << ")" << endl;
        cout << "Snacks: " <<nonvegsnacks << " (Calories: " <<snacksCalories << ")" << endl;
        cout << "Dinner: " <<nonvegdinner << " (Calories: " <<dinnerCalories << ")" << endl;
    }

public:
    string goal;
};
