#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <string>
using namespace std;

class Maintenance
{
private:
    int maintenanceId;
    int chargerId;
    int technicianId;
    string issue;
    string maintenanceDate;
    string status;

public:
    Maintenance();

    void displayMaintenanceRecord();
    void updateMaintenanceRecord(string issue, string date, string status);
    void assignTechnician(int technicianId);
};

#endif