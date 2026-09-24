#include "Customer.h"

#include <iostream>

using namespace std;

Customer::Customer(){
    customerId = 0;
    name = "";
    email = "";
    phone = "";
    password = "";
}
void Customer::inputCustomer() {
    cout << "Enter Customer ID: ";
    cin >> customerId;

    cout << "Enter Customer Name: ";
    cin >> name;

    cout << "Enter Customer Email: ";
    cin >> email;

    cout << "Enter Customer Mobile Number: ";
    cin >> phone;

    cout << "Enter Customer Password: ";
    cin >> password;

    cout << "\nCustomer Registered Successfully!\n";
}

void Customer::displayCustomer() const {
    cout << "\n========== Customer Details ==============\n";
    cout << "Customer ID: " << customerId << '\n';
    cout << "Customer Name: " << name << '\n';
    cout << "Customer Email: " << email << '\n';
    cout << "Customer Mobile Number: " << phone << '\n';
}

bool Customer::login(string enteredEmail, string enteredPassword) {
    if(email == enteredEmail && password == enteredPassword) {
        return true;
    } else {
        return false;
    }
}
