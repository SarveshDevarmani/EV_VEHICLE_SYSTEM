#include "Booking.h"
#include <iostream>

using namespace std;

void Booking::createBooking()
{
    cout << "Enter Booking ID: ";
    cin >> bookingId;

    cout << "Enter Customer ID: ";
    cin >> customerId;

    cout << "Enter Vehicle ID: ";
    cin >> vehicleId;

    cout << "Enter Charger ID: ";
    cin >> chargerId;

    cout << "Enter Date: ";
    cin >> date;

    cout << "Enter Time: ";
    cin >> time;

    status = "Booked";

    cout << "Booking created successfully." << endl;
}

void Booking::displayBooking()
{
    cout << "\nBooking Details" << endl;
    cout << "Booking ID: " << bookingId << endl;
    cout << "Customer ID: " << customerId << endl;
    cout << "Vehicle ID: " << vehicleId << endl;
    cout << "Charger ID: " << chargerId << endl;
    cout << "Date: " << date << endl;
    cout << "Time: " << time << endl;
    cout << "Status: " << status << endl;
}

void Booking::cancelBooking()
{
    if (status == "Booked")
    {
        status = "Cancelled";
        cout << "Booking cancelled successfully." << endl;
    }
    else
    {
        cout << "Booking cannot be cancelled." << endl;
    }
}

void Booking::checkBookingStatus()
{
    cout << "Booking Status: " << status << endl;
}