#ifndef CHARGINGSTATION_H
#define CHARGINGSTATION_H

#include<string>
using namespace std;

class chargingStation {
    private:
        int stationId;
        string stationName;
        string location;
        double totalCharges;    
    
    public:

        chargingStation();
        void inputStation();
        void displayStation() const;
};

#endif