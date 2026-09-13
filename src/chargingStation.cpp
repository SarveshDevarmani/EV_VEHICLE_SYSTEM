#include "chargingStation.h"

#include <iostream>
using namespace std;

chargingStation::chargingStation() {
    stationId = 0;
    stationName = "";
    location = "";
    totalCharges = 0;
}

void chargingStation::inputStation() {
    cout << "Enter Station ID: ";
    cin >> stationId;

    cout << "Enter Station Name: ";
    cin >> stationName;

    cout << "Enter Location: ";
    cin >> location;

    cout << "Enter total charges: ";
    cin >> totalCharges;
}

void chargingStation::displayStation() const{
    cout << "\n================ Charging Station Details ================\n";
    cout << "Station ID: " << stationId << endl;
    cout << "Station Name: " << stationName << endl;
    cout << "Location: " << location << endl;
    cout << "Total Charges: " << totalCharges << endl;
}