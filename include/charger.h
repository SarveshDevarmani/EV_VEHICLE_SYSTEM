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
        void inputCharger();
        void displayCharger() const;
        void updateStatus(bool newStatus);
        bool checkAvailability();
};

#endif