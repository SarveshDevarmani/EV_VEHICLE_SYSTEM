#include "Vehicle.h"
#include <iostream>
#include <limits>

using namespace std;

Vehicle::Vehicle()
{
    vehicleId = 0;
    ownerCustomerId = 0;
    model = "";
    type = "";
    batteryCapacity = 0;
    currentSOC = 0;
}

void Vehicle::inputVehicle()
{
    inputVehicle(0);
}

void Vehicle::inputVehicle(int customerId)
{
    ownerCustomerId = customerId;

    cout << "\nEnter Vehicle ID: ";
    cin >> vehicleId;

    if (vehicleId <= 0)
    {
        cout << "Invalid Vehicle ID.\n";
        vehicleId = 0;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Vehicle Model: ";
    getline(cin, model);

    cout << "Enter Vehicle Type (Electric Car/Bike): ";
    getline(cin, type);

    cout << "Enter Battery Capacity (kWh): ";
    cin >> batteryCapacity;

    if (batteryCapacity <= 0)
    {
        cout << "Battery capacity must be greater than zero.\n";
        vehicleId = 0;
        return;
    }

    cout << "Enter Current Battery SOC (%): ";
    cin >> currentSOC;

    if (currentSOC < 0 || currentSOC > 100)
    {
        cout << "SOC must be between 0 and 100.\n";
        vehicleId = 0;
        return;
    }

    cout << "Vehicle details saved.\n";
}

void Vehicle::displayVehicle() const
{
    cout << "\n--- Vehicle Details ---\n";
    cout << "Vehicle ID: " << vehicleId << '\n';
    cout << "Customer ID: " << ownerCustomerId << '\n';
    cout << "Model: " << model << '\n';
    cout << "Type: " << type << '\n';
    cout << "Battery Capacity: " << batteryCapacity << " kWh\n";
    cout << "Current SOC: " << currentSOC << "%\n";
}

void Vehicle::updateSOC(double newSOC)
{
    if (newSOC >= 0 && newSOC <= 100)
    {
        currentSOC = newSOC;
    }
    else
    {
        cout << "SOC must be between 0 and 100.\n";
    }
}

double Vehicle::calculateChargingTime(double chargerPower)
{
    if (chargerPower <= 0)
    {
        return 0;
    }

    double remainingCapacity =
        batteryCapacity * (100 - currentSOC) / 100.0;

    return remainingCapacity / chargerPower;
}

int Vehicle::getVehicleId() const
{
    return vehicleId;
}

int Vehicle::getOwnerCustomerId() const
{
    return ownerCustomerId;
}

double Vehicle::getBatteryCapacity() const
{
    return batteryCapacity;
}

double Vehicle::getCurrentSOC() const
{
    return currentSOC;
}