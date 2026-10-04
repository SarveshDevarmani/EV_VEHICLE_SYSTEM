#ifndef ADMIN_H
#define ADMIN_H
#include <string>
using namespace std;

class Admin
{
private:
    int adminId;
    string name;
    string email = "admin@123";
    string password = "123";

public:
    Admin();

    bool login(string email, string password);
    void displayMenu();
    void manageCustomers();
    void manageStations();
    void ManageChargers();
};
#endif