#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer {
private:
    int customerId;
    string name;
    string email;
    string phone;
    string password;

public:
    Customer();

    void inputCustomer();
    void displayCustomer() const;
    bool login(string enteredEmail, string enteredPassword);
};

#endif
