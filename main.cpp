#include <iostream>

#include "Customer.h"
#include "Vehicle.h"
#include "chargingStation.h"
#include "charger.h"
#include "Admin.h"
#include "Maintenance.h"

using namespace std;

int main()
{
    Customer c1;
    Vehicle v1;
    chargingStation chs1;
    charger ch1;
    Admin admin;
    Maintenance maintenance;

    int choice;

    do
    {
        cout << "\n===================================================================================";
        cout << "\n\n========================= EV CHARGING MANAGEMENT SYSTEM =========================";
        cout << "\n===================================================================================\n";

        cout << "\n1.  Register Customer";
        cout << "\n2.  Customer Login";
        cout << "\n3. Admin";
        cout << "\n3. Exit\n\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                c1.inputCustomer();
                break;

            case 2:
            {
                string enteredEmail;
                string enteredPassword;

                cout << "\nEnter Email: ";
                cin >> enteredEmail;

                cout << "\nEnter Password: ";
                cin >> enteredPassword;

                if(c1.login(enteredEmail, enteredPassword)) {
                    cout << "\nLogin Successful\n";
                } else {
                    cout << "\nInvalid Email or Password!\n";
                }
                break;
            }

            case 3:
            {
                string enteredEmail2;
                string enteredPassword2;
                cout << "\nEnter email: ";
                cin >> enteredEmail2;
                cout << "\nEnter password: ";
                cin >> enteredPassword2;

                if(admin.login(enteredEmail2, enteredPassword2)) {
                    admin.displayMenu();
                }
                break;
            }

            case 4:
                cout << "Exiting...";
                break;
        }

    } while(choice != 4);

    return 0;
}

