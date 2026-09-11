#include <iostream>

#include "Customer.h"
#include "Vehicle.h"

using namespace std;


int main() {

    Customer c1;
    Vehicle v1;
    int choice;


    do{
        cout << "\n===================================================================================";
        cout << "\n\n========================= EV CHARGING MANAGEMENT SYSTEM =========================" << endl;
        cout << "\n===================================================================================" << endl;

        cout << "1. Register Customer\n";
        cout << "2. Display Customer Details\n";
        cout << "3. Add Vehicle\n";
        cout << "4. Display Vehicle\n";
        cout << "5. Exit\n\n";
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
                cout << "\nExiting Program...";
                break;

            default:
                cout << "\nInvalid Choice! Please try again.\n";
                break;
        }

    }while(choice != 5);

    return 0;
}