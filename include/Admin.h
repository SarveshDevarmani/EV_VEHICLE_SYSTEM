#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "chargingStation.h"

using namespace std;

class Admin
{
private:
    int adminId;
    string name;
    string email;
    string password;

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
