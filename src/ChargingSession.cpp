#include "ChargingSession.h"
#include <iostream>

using namespace std;

void ChargingSession::startSession()
{
    cout << "Enter Session ID: ";
    cin >> sessionId;

    cout << "Enter Booking ID: ";
    cin >> bookingId;

    cout << "Enter Starting SOC: ";
    cin >> startSOC;

    energyConsumed = 0;

    cout << "Charging session started." << endl;
}

void ChargingSession::endSession()
{
    cout << "Enter Ending SOC: ";
    cin >> endSOC;

    cout << "Enter End Time: ";
    cin >> endTime;

    calculateEnergyConsumed();

    cout << "Charging session ended." << endl;
}

void ChargingSession::calculateEnergyConsumed()
{
    energyConsumed = endSOC - startSOC;
}

void ChargingSession::displaySession()
{
    cout << "\nCharging Session Details" << endl;
    cout << "Session ID: " << sessionId << endl;
    cout << "Booking ID: " << bookingId << endl;
    cout << "Start SOC: " << startSOC << "%" << endl;
    cout << "End SOC: " << endSOC << "%" << endl;
    cout << "Energy Consumed: " << energyConsumed << "%" << endl;
    cout << "End Time: " << endTime << endl;
}