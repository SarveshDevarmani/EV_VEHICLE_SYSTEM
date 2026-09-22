#ifndef BOOKING_H
#define BOOKING_H

#include <string>

using namespace std;

class Booking
{
private:
    int bookingId;
    int customerId;
    int vehicleId;
    int chargerId;
    string date;
    string time;
    string status;

public:
    void createBooking();
    void displayBooking();
    void cancelBooking();
    void checkBookingStatus();
};

#endif