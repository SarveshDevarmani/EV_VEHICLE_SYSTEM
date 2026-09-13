#include "charger.h"

#include<iostream>
using namespace std;

charger::charger() {
    chargerId = 0;
    stationId = 0;
    chargerType = "";
    power = 0;
    status = true;
}

void charger::inputCharger() {
    cout << "Enter Charger ID: ";
    cin >> chargerId;

    cout << "Enter Station ID: ";
    cin >> stationId;

    cout << "Enter Charger Type(AC/DC): ";
    cin >> chargerType;

    cout << "Enter Charging Power(KW): ";
    cin >> power;

    status = true;

}

void charger::displayCharger() const{
    cout << "\n============ CHARGER DETAILS =============\n";
    cout << "Charger ID: " << chargerId << endl;
    cout << "Station ID: " << stationId << endl;
    cout << "Charger Type: " << chargerType << endl;
    cout << "Charger Power: " << power << endl;
    
    if(status) {
        cout << "Status : Available" << endl;
    } else {
        cout << "status : Occupied" << endl;
    }

}

void charger::updateStatus(bool newStatus) {
    status = newStatus;
}

bool charger::checkAvailability() {
    return status;
}