#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

using namespace std;

class Vehicle {
private:
    int vehicleId;
    string model;
    string type;
    double batteryCapacity;
    double currentSOC;

public:
    Vehicle();

    void inputVehicle();
    void displayVehicle() const;
};

#endif
