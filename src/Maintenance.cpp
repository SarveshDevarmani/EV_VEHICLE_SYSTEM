#include "Maintenance.h"
#include <iostream>

using namespace std;

Maintenance::Maintenance()
{
    maintenanceId = 0;
    chargerId = 0;
    technicianId = 0;
    issue = "";
    maintenanceDate = "";
    status = "Pending";
}

void Maintenance::displayMaintenanceRecord()
{
    cout << "\n===== MAINTENANCE RECORD =====" << endl;

    cout << "Maintenance ID: " << maintenanceId << endl;
    cout << "Charger ID: " << chargerId << endl;
    cout << "Technician ID: " << technicianId << endl;
    cout << "Issue: " << issue << endl;
    cout << "Maintenance Date: " << maintenanceDate << endl;
    cout << "Status: " << status << endl;
}

void Maintenance::updateMaintenanceRecord(
    string issue,
    string date,
    string status)
{
    this->issue = issue;
    this->maintenanceDate = date;
    this->status = status;

    cout << "Maintenance record updated." << endl;
}

void Maintenance::assignTechnician(int technicianId)
{
    this->technicianId = technicianId;

    cout << "Technician assigned successfully." << endl;
}