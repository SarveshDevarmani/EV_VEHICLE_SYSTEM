#ifndef ADMIN_H
#define ADMIN_H
#include <string>
using namespace std;

class Admin
{
private:
    int adminId;
    string name;
    string email;
    string password;

public:
    Admin();

    bool login(string email, string password);
    void displayMenu();
    void manageCustomers();
    void manageStations();
    void ManageChargers();
};
#endif