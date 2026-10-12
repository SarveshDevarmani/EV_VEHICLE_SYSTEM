
#include <iostream>
#include "Customer.h"

using namespace std;

Customer::Customer()
{
    customerId = 0;
    name = "";
    email = "";
    phone = "";
    password = "";
}

void Customer::inputCustomer()
{
    cout << "\nEnter Customer ID: ";
    cin >> customerId;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Email: ";
    cin >> email;

    cout << "Enter Mobile Number: ";
    cin >> phone;

    cout << "Enter Password: ";
    cin >> password;

    cout << "\nCustomer Registered Successfully!\n";
}

void Customer::displayCustomer() const
{
    cout << "\nCustomer ID: " << customerId;
    cout << "\nName: " << name;
    cout << "\nEmail: " << email;
    cout << "\nMobile: " << phone << endl;
}

bool Customer::login(string enteredEmail, string enteredPassword)
{
    return email == enteredEmail &&
           password == enteredPassword;
}

int Customer::getCustomerId() const
{
    return customerId;
}
