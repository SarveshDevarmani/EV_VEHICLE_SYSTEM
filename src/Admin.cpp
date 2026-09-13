#include "Admin.h"
#include <iostream>

using namespace std;

Admin::Admin()
{
    adminId = 0;
    name = "";
    email = "";
    password = "";
}
bool Admin::login(string email, string password)
{

    if (this->email == email && this->password == password)
    {
        cout << "Login Successfull" << endl;
        return true;
    }

    cout << "Invalid email or password" << endl;
    return false;
}
void Admin::displayMenu()
{
    int choice;
    do
    {
        cout << "\n===== Admin Menu =====" << endl;
        cout << "1. Manage Customers" << endl;
        cout << "2. Manage Stations" << endl;
        cout << "3. Manage Chargers" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Admin::manageCustomers();
            break;
            case 2:
            /* code */Admin::manageStations();
            break;
            case 3:
            /* code */Admin::ManageChargers();
            break;
            case 4:
                    cout << "\nExiting Program...";
            break;

        default:
            break;
        }
    } while (choice != 4);
}
void Admin::manageCustomers()
{
    cout << "Customer Management Selected." << endl;
}
void Admin::manageStations()
{
    cout << "Station Management Selected." << endl;
}
void Admin::ManageChargers()
{
    cout << "Charger Management Selected." << endl;
}