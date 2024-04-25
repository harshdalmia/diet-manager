#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

class WaterManager {
private:
    double totalDrinkingWater;
    time_t lastReminderTime;

public:
    WaterManager() : totalDrinkingWater(0), lastReminderTime(0) {}

    void recordDrinkingWater(double amount) {
        totalDrinkingWater += amount;
    }

    double getTotalDrinkingWater() const {
        return totalDrinkingWater;
    }

    void setLastReminderTime() {
        lastReminderTime = time(nullptr);
    }

    bool shouldRemind() const {
        // Remind if it's been more than 1 hour since the last reminder
        return (time(nullptr) - lastReminderTime) >= 3600;
    }
};

void manageWater() {
    WaterManager manager;

    cout << "Welcome to the Drinking Water Management System!" << endl;

    int choice;
    do {
        cout << "\nMenu:\n1. Record Drinking Water Consumption\n2. View Total Drinking Water Consumption\n3. Get Reminder\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double amount;
                cout << "Enter the amount of drinking water consumed (in liters): ";
                cin >> amount;
                manager.recordDrinkingWater(amount);
                cout << "Drinking water consumption recorded successfully." << endl;
                break;
            }
            case 2:
                cout << "Total drinking water consumption: " << fixed << setprecision(2) << manager.getTotalDrinkingWater() << " liters" << endl;
                break;
            case 3:
                if (manager.shouldRemind()) {
                    cout << "Reminder: Don't forget to drink water!" << endl;
                    manager.setLastReminderTime();
                } else {
                    cout << "You've already been reminded recently. Drink water regularly!" << endl;
                }
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
}


