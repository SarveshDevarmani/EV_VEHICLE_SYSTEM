
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
    void viewAllCustomers();
    void searchCustomer(int id);
    void deleteCustomer(int id);

    void manageStations();
    void ManageChargers();

    // Customer access to Admin's existing data
    int getStationCount() const;
    const chargingStation& getStation(int index) const;

    int getChargerCount() const;
    charger& getCharger(int index);
    const charger& getCharger(int index) const;
};

#endif
