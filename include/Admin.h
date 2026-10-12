#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <vector>
#include "charger.h"
#include "chargingStation.h"

using namespace std;

class Admin
{
private:
    int adminId;
    string name;
    string email;
    string password;

    vector<charger> chargers;
    chargingStation stations[100];
    int stationCount;

public:
    Admin();

    bool login(string email, string password);
    void displayMenu();

    void manageCustomers();
    void manageStations();
    void ManageChargers();
};

#endif
