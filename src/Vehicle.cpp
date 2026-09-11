#include "Vehicle.h"

#include <iostream>

using namespace std;

Vehicle::Vehicle()
{
    vehicleId = 0;
    model = "";
    type = "";
    batteryCapacity = 0;
    currentSOC = 0;
}

void Vehicle::inputVehicle() {
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

void Vehicle::displayVehicle() const {
	cout << "\n================ Vehicle Details ================\n";
	cout << "Vehicle ID: " << vehicleId << '\n';
	cout << "Vehicle Model: " << model << '\n';
	cout << "Vehicle Type: " << type << '\n';
	cout << "Vehicle Battery Capacity: " << batteryCapacity << '\n';
	cout << "Vehicle Current SOC: " << currentSOC << '\n';
}
