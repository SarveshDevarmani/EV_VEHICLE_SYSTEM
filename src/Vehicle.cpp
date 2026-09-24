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

	cout << "Enter Battery Capacity(kWh): ";
	cin >> batteryCapacity;

	cout << "Enter Current SOC(%): ";
	cin >> currentSOC;

	cout << "\nVehicle added successfully!\n";
}

void Vehicle::displayVehicle() const {
	cout << "\n================ Vehicle Details ================\n";
	cout << "Vehicle ID: " << vehicleId << '\n';
	cout << "Vehicle Model: " << model << '\n';
	cout << "Vehicle Type: " << type << '\n';
	cout << "Vehicle Battery Capacity: " << batteryCapacity << '\n';
	cout << "Vehicle Current SOC: " << currentSOC << '\n';
}

void Vehicle::updateSOC(double newSOC) {
	if(newSOC >= 0 && newSOC <= 100) {
		currentSOC = newSOC;
		cout << "\nSOC updated successfully!\n";
	} else {
		cout << "\nInvalid SOC! Enter value between 0 and 100.\n";
	}
}

double Vehicle::calculateChargingTime(double chargerPower) {
	if(chargerPower <= 0) {
		cout << "\nInvalid charger power!\n";
		return 0;
	}

	double requiredEnergy = batteryCapacity * (100-currentSOC) / 100;
	double chargingTime = requiredEnergy / chargerPower;

	return chargingTime;
}

double Vehicle::getBatteryCapacity() {
	return batteryCapacity;
}

double Vehicle::getCurrentSOC() {
	return currentSOC;
}