
#include <iostream>
#include "Booking.h"

using namespace std;

Booking::Booking()
{
    bookingId = 0;
    customerId = 0;
    vehicleId = 0;
    chargerId = 0;
    date = "";
    time = "";
    status = "Not Booked";
}

void Booking::createBooking()
{
    cout << "\nEnter Booking ID: ";
    cin >> bookingId;

    cout << "Enter Customer ID: ";
    cin >> customerId;

    cout << "Enter Vehicle ID: ";
    cin >> vehicleId;

    cout << "Enter Charger ID: ";
    cin >> chargerId;

    cout << "Enter Date (YYYY-MM-DD): ";
    cin >> date;

    cout << "Enter Time (HH:MM): ";
    cin >> time;

    status = "Booked";

    cout << "Booking created successfully.\n";
}

void Booking::createBooking(
    int bId,
    int cId,
    int vId,
    int chId,
    string bookingDate,
    string bookingTime)
{
    bookingId = bId;
    customerId = cId;
    vehicleId = vId;
    chargerId = chId;
    date = bookingDate;
    time = bookingTime;
    status = "Booked";
}

void Booking::displayBooking() const
{
    cout << "\nBooking ID: " << bookingId;
    cout << "\nCustomer ID: " << customerId;
    cout << "\nVehicle ID: " << vehicleId;
    cout << "\nCharger ID: " << chargerId;
    cout << "\nDate: " << date;
    cout << "\nTime: " << time;
    cout << "\nStatus: " << status << "\n";
}

void Booking::cancelBooking()
{
    if (status == "Booked")
    {
        status = "Cancelled";
        cout << "Booking cancelled successfully.\n";
    }
    else
    {
        cout << "This booking cannot be cancelled.\n";
    }
}

void Booking::checkBookingStatus() const
{
    cout << "Booking Status: " << status << "\n";
}

int Booking::getBookingId() const
{
    return bookingId;
}

int Booking::getCustomerId() const
{
    return customerId;
}

int Booking::getVehicleId() const
{
    return vehicleId;
}

int Booking::getChargerId() const
{
    return chargerId;
}

string Booking::getDate() const
{
    return date;
}

string Booking::getTime() const
{
    return time;
}

string Booking::getStatus() const
{
    return status;
}
