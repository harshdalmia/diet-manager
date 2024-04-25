#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class DietType
{
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
    DietType()
    {
        // Set default values for all variables
        vegbreakfast = "Masala Dosa with Sambar and fatless Coconut Chutney";
        breakfastCalories = 500;
        veglunch = "Vegetable Soya Pulao with Raita";
        lunchCalories = 600;
        vegsnacks = "Vegetable Pakoras with mint chutney";
        snacksCalories = 350;
        vegdinner = "Palak Paneer with Chapati and Kachumber Salad";
        dinnerCalories = 650;
        nonvegbreakfast = "Masala Omelette with Whole Wheat Paratha and Sliced Avocado";
        nonveglunch = "Tandoori Chicken Salad with Mint Yogurt Dressing";
        nonvegsnacks = "Tandoori Fish Tikka with Lemon and Cilantro";
        nonvegdinner = "Butter Chicken with Jeera Rice and Grilled Vegetables";
        mcal = 2100;
        gcal = 2550;
        lcal = 1650;
    }

    virtual void printDietPlan() const = 0;
};

class VegDiet : public DietType
{
public:
    VegDiet(string goal)
    {
        
        // Adjust calories based on goal
        if (goal == "Underweight")
        {
            breakfastCalories += 100;
            lunchCalories += 100;
            snacksCalories += 50;
            dinnerCalories += 200;
        }
        else if (goal == "Overweight")
        {
            breakfastCalories -= 100;
            lunchCalories -= 100;
            snacksCalories -= 50;
            dinnerCalories -= 200;
        }
    }

    void printDietPlan() const override
    {
        cout << "Vegetarian Menu:" << endl;
        cout << "------------------------------------------------------------------" << endl;
        cout << "| Breakfast: " << setw(55) << left << vegbreakfast << "   | Calories: " << setw(5) << right << breakfastCalories << " |" << endl;
        cout << "| Lunch:     " << setw(55) << left << veglunch << "   | Calories: " << setw(5) << right << lunchCalories << " |" << endl;
        cout << "| Snacks:    " << setw(55) << left << vegsnacks << "   | Calories: " << setw(5) << right << snacksCalories << " |" << endl;
        cout << "| Dinner:    " << setw(55) << left << vegdinner << "   | Calories: " << setw(5) << right << dinnerCalories << " |" << endl;
        cout << "------------------------------------------------------------------" << endl;

        cout << endl;
    }
};

class NonVegDiet : public DietType
{
public:
    NonVegDiet(string goal)
    {
        // Adjust calories based on goal
        if (goal == "Underweight")
        {
            breakfastCalories += 100;
            lunchCalories += 100;
            snacksCalories += 50;
            dinnerCalories += 200;
        }
        else if (goal == "Overweight")
        {
            breakfastCalories -= 100;
            lunchCalories -= 100;
            snacksCalories -= 50;
            dinnerCalories -= 200;
        }
    }

    void printDietPlan() const override
    {
        cout << "Non-vegetarian Menu:" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "| Breakfast: " << setw(55) << left << nonvegbreakfast << "   | Calories: " << setw(5) << right << breakfastCalories << " |" << endl;
        cout << "| Lunch:     " << setw(55) << left << nonveglunch << "   | Calories: " << setw(5) << right << lunchCalories << " |" << endl;
        cout << "| Snacks:    " << setw(55) << left << nonvegsnacks << "   | Calories: " << setw(5) << right << snacksCalories << " |" << endl;
        cout << "| Dinner:    " << setw(55) << left << nonvegdinner << "   | Calories: " << setw(5) << right << dinnerCalories << " |" << endl;
        cout << "------------------------------------------------------------------" << endl;

        cout << endl;
    }

};

