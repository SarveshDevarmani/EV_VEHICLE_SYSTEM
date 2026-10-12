
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
    Booking();

    void createBooking();

    void createBooking(
        int bId,
        int cId,
        int vId,
        int chId,
        string bookingDate,
        string bookingTime
    );

    void displayBooking() const;
    void cancelBooking();
    void checkBookingStatus() const;

    int getBookingId() const;
    int getCustomerId() const;
    int getVehicleId() const;
    int getChargerId() const;

    string getDate() const;
    string getTime() const;
    string getStatus() const;
};

#endif
