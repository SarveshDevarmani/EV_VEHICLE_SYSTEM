#include<iostream>
using namespace std;

class Customer{
    int customerId;
    string name;
    string email;
    string phone;
    string password;

    public:

        Customer() {
            customerId = 0;
            name = "";
            email = "";
            phone = "";
            password = "";
        }

        void inputCustomer() {
            cout << "Enter Customer ID: ";
            cin >> customerId;
   
            cout << "Enter Customer Name: ";
            cin >> name;

            cout << "Enter Customer Email: ";
            cin >> email;

            cout << "Enter Customer Mobile Number: ";
            cin >> phone;

            cout << "Enter Customer Password: ";
            cin >> password;

            cout << "\nCustomer Registered Successfully!\n";
        }       
        
        void displayCustomer() {
            cout << "\n========== Customer Details ==============" << endl;
            cout << "Customer ID: " << customerId << endl;
            cout << "Customer Name: " << name << endl;
            cout << "Customer Email: " << email << endl;
            cout << "Customer Mobile Number: " << phone << endl;
        }

};

class Vehicle{
    int vehicleId;
    string model;
    string type;
    double batteryCapacity;
    double currentSOC;

    public:

    Vehicle(){
        vehicleId = 0;
        model = "";
        type = "";
        batteryCapacity = 0;
        currentSOC = 0;
    }

    void inputVehicle() {
        cout << "Enter Vehicle ID: ";
        cin >> vehicleId;
        cout << "Enter Vehicle Model: ";
        cin >> model;
        cout << "Enter Vehicle Type: ";
        cin >> type;
        cout << "Enter Battery Capacity: ";
        cin >> batteryCapacity;
        cout << "Enter Current SOC: ";
        cin >> currentSOC;
    }

    void displayVehicle() {
        cout << "\n================ Vehicle Details ================" << endl;
        cout << "Vehicle ID: " << vehicleId << endl;
        cout << "Vehicle Model: " << model << endl;
        cout << "Vehicle Type: " << type << endl;
        cout << "Vehicle Battery Capacity: " << batteryCapacity << endl;
        cout << "Vehicle Current SOC: " << currentSOC << endl;
    }
};


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

    }while(choice != 4);

    return 0;
}