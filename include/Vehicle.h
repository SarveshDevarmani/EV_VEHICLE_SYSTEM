
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle
{
private:
    int vehicleId;
    int ownerCustomerId;
    string model;
    string type;
    double batteryCapacity;
    double currentSOC;

public:
    Vehicle();

    void inputVehicle();
    void inputVehicle(int customerId);

    void displayVehicle() const;
    void updateSOC(double newSOC);

    double calculateChargingTime(double chargerPower);

    int getVehicleId() const;
    int getOwnerCustomerId() const;
    double getBatteryCapacity() const;
    double getCurrentSOC() const;
};

#endif
