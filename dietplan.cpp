#include <iostream>
#include <string>

using namespace std;

class DietType {
public:
    struct DietPlan {
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
    };

public:
    DietType() {
        // Set default values for all variables
        dietPlan.vegbreakfast = "Oatmeal with fruits";
        dietPlan.breakfastCalories = 300;
        dietPlan.veglunch = "Vegetable salad with tofu";
        dietPlan.lunchCalories = 400;
        dietPlan.vegsnacks = "Carrot sticks with hummus";
        dietPlan.snacksCalories = 150;
        dietPlan.vegdinner = "Quinoa with mixed vegetables";
        dietPlan.dinnerCalories = 450;
        dietPlan.nonvegbreakfast = "Scrambled eggs with whole grain toast";
        dietPlan.nonveglunch = "Grilled chicken breast with brown rice";
        dietPlan.nonvegsnacks =  "Greek yogurt with almonds";
        dietPlan.nonvegdinner = "Baked salmon with steamed vegetables" ;
    }

    virtual void printDietPlan() const = 0;

public:
    DietPlan dietPlan;
};

class VegDiet : public DietType {
public:
    VegDiet(string goal) : goal(goal) {
        // Adjust calories based on goal
        if (goal == "Lose") {
            dietPlan.breakfastCalories -= 100;
            dietPlan.lunchCalories -= 100;
            dietPlan.snacksCalories -= 50;
            dietPlan.dinnerCalories -= 100;
        } else if (goal == "Gain") {
            dietPlan.breakfastCalories += 100;
            dietPlan.lunchCalories += 100;
            dietPlan.snacksCalories += 50;
            dietPlan.dinnerCalories += 100;
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
    NonVegDiet(string goal) : goal(goal) {
        // Adjust calories based on goal
        if (goal == "Lose") {
            dietPlan.breakfastCalories -= 100;
            dietPlan.lunchCalories -= 100;
            dietPlan.snacksCalories -= 50;
            dietPlan.dinnerCalories -= 100;
        } else if (goal == "Gain") {
            dietPlan.breakfastCalories += 100;
            dietPlan.lunchCalories += 100;
            dietPlan.snacksCalories += 50;
            dietPlan.dinnerCalories += 100;
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


int main() {
    char dietChoice;
    cout << "Are you vegetarian or non-vegetarian? (V/N): ";
    cin >> dietChoice;

    string goal;
    cout << "Select your weight goal (Maintain/Lose/Gain): ";
    cin >> goal;

    DietType *dietType;

    if (dietChoice == 'V' || dietChoice == 'v') {
        dietType = new VegDiet(goal);
    } else if (dietChoice == 'N' || dietChoice == 'n') {
        dietType = new NonVegDiet(goal);
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    dietType->printDietPlan();

    delete dietType;

    return 0;
}
