#ifndef CHARGER_H
#define CHARGER_H

#include<string>
using namespace std;

class charger {
    private:
        int chargerId;
        int stationId;
        string chargerType;
        double power;
        bool status;

   
        
public:
    charger();
    charger(int id, int stationId, string type, double power);

    void inputCharger();
    void displayCharger() const;
    int getChargerId() const;
    int getStationId() const;
    void updateStatus(bool newStatus);
    bool checkAvailability();

};


#endif