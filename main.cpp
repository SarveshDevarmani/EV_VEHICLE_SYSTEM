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
        cout << "\n2.  Display Customer Details";
        cout << "\n3.  Add Vehicle";
        cout << "\n4.  Display Vehicle";
        cout << "\n5.  Charging Station";
        cout << "\n6.  Display Charging Station";
        cout << "\n7.  Charger";
        cout << "\n8.  Display Charger";
        cout << "\n9.  Admin Menu";
        cout << "\n10. Display Maintenance Record";
        cout << "\n11. Assign Technician";
        cout << "\n12. Update Maintenance Record";
        cout << "\n13. Exit\n\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
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
                admin.displayMenu();
                break;

            case 10:
                maintenance.displayMaintenanceRecord();
                break;

            case 11:
            {
                int technicianId;

                cout << "\nEnter Technician ID: ";
                cin >> technicianId;

                maintenance.assignTechnician(technicianId);
                break;
            }

            case 12:
            {
                string issue;
                string date;
                string status;

                cout << "\nEnter Issue: ";
                cin.ignore();

                getline(cin, issue);

                cout << "Enter Maintenance Date: ";
                getline(cin, date);

                cout << "Enter Status: ";
                getline(cin, status);

                maintenance.updateMaintenanceRecord(
                    issue,
                    date,
                    status
                );

                break;
            }

            case 13:
                cout << "\nExiting Program...";
                break;

            default:
                cout << "\nInvalid Choice! Please try again.\n";
                break;
        }

    } while(choice != 13);

    return 0;
}

