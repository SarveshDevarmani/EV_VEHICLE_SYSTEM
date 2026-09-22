#ifndef CHARGINGSESSION_H
#define CHARGINGSESSION_H

#include <string>

using namespace std;

class ChargingSession
{
private:
    int sessionId;
    int bookingId;
    string endTime;
    double energyConsumed;
    double startSOC;
    double endSOC;

public:
    void startSession();
    void endSession();
    void calculateEnergyConsumed();
    void displaySession();
};

#endif