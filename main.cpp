#include <iostream>

#include "Customer.h"
#include "Vehicle.h"
#include "chargingStation.h"
#include "charger.h"

using namespace std;


int main() {

    Customer c1;
    Vehicle v1;
    chargingStation chs1;
    charger ch1;

    int choice;


    do{
        cout << "\n===================================================================================";
        cout << "\n\n========================= EV CHARGING MANAGEMENT SYSTEM =========================" << endl;
        cout << "\n===================================================================================" << endl;

        cout << "1. Register Customer\n";
        cout << "2. Display Customer Details\n";
        cout << "3. Add Vehicle\n";
        cout << "4. Display Vehicle\n";
        cout << "5. Charging Station\n";
        cout << "6. Display Charging Station\n";
        cout << "7. Charger\n";
        cout << "8. Display Charger\n";
        cout << "9. Exit\n\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                c1.inputCustomer();
                
                break;

            case 2:
                c1.displayCustomer();
                break;

            case 3:
                v1.inputVehicle();
                break;

            case 4:
                v1.displayVehicle();
                break;

            case 5:
                chs1.inputStation();
                break;

            case 6:
                chs1.displayStation();
                break;

            case 7:
                ch1.inputCharger();
                break;

            case 8:
                ch1.displayCharger();
                break;

            case 9:
                cout << "\nExiting Program...";
                break;

            default:
                cout << "\nInvalid Choice! Please try again.\n";
                break;
        }

    }while(choice != 9);

    return 0;
}