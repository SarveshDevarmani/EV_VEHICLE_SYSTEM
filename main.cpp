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
        cout << "\n3.  Customer Login";
        cout << "\n4.  Add Vehicle";
        cout << "\n5.  Display Vehicle";
        cout << "\n6.  Update Vehicle";
        cout << "\n7.  Calculate Charging Time";
        cout << "\n8.  Charging Station";
        cout << "\n9.  Display Charging Station";
        cout << "\n10. Charger";
        cout << "\n11. Display Charger";
        cout << "\n12. Admin Menu";
        cout << "\n13. Display Maintenance Record";
        cout << "\n14. Assign Technician";
        cout << "\n15. Update Maintenance Record";
        cout << "\n16. Exit\n\n";

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

            case 4:
                v1.inputVehicle();
                break;

            case 5:
                v1.displayVehicle();
                break;

            case 6:
            {
                double newSOC;
                cout << "\nEnter New SOC(%): ";
                cin >> newSOC;

                v1.updateSOC(newSOC);
                break;
            }
            
            case 7:
            {
                double chargerPower;
                cout << "\nEnter Charger Pwer(kWh): ";
                cin >> chargerPower;

                double time = v1.calculateChargingTime(chargerPower);

                if(time > 0) {
                    cout << "\nRequired Charging Time: " << time << "hours\n";
                }
                break;
            }

            case 8:
                chs1.inputStation();
                break;

            case 9:
                chs1.displayStation();
                break;

            case 10:
                ch1.inputCharger();
                break;

            case 11:
                ch1.displayCharger();
                break;

            case 12:
                admin.displayMenu();
                break;

            case 13:
                maintenance.displayMaintenanceRecord();
                break;

            case 14:
            {
                int technicianId;

                cout << "\nEnter Technician ID: ";
                cin >> technicianId;

                maintenance.assignTechnician(technicianId);
                break;
            }

            case 15:
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

            case 16:
                cout << "\nExiting Program...";
                break;

            default:
                cout << "\nInvalid Choice! Please try again.\n";
                break;
        }

    } while(choice != 16);

    return 0;
}

