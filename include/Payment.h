#ifndef PAYMENT_H
#define PAYMENT_H

#include<string>
using namespace std;

class Payment{
    private:
      int paymentId;
      int sessionId;
      double amount;
      string paymentMethod;
      string paymentStatus;

    public:
    Payment();
      void makePayment(int pId, int sId, double amt, string method);
       void displayPayment();
      void generateReceipt();
      string checkPaymentStatus();    
};

#endif