#include "Payment.h"
#include <iostream>

using namespace std;

Payment::Payment(){
    paymentId=0;
    sessionId=0;
    amount=0;
    paymentMethod="Not Selected";
    paymentStatus="Pending";
}
void Payment::makePayment(int pId, int sId, double amt, string method){
    paymentId=pId;
    sessionId=sId;
    amount=amt;
    paymentMethod = method;
    paymentStatus = "Successful";
}
void Payment::displayPayment()
{ cout<<"\n";
    cout <<"---* Payment Details *---"<<endl;
    cout <<"Payment ID: "<<paymentId<<endl;
    cout <<"Session ID: "<<sessionId<<endl;
    cout <<"Amount: Rs. "<<amount << endl;
    cout <<"Payment Method: "<<paymentMethod<<endl;
    cout <<"Payment Status: "<<paymentStatus<<endl;
}
void Payment::generateReceipt()
{
    cout<<"\n--- Payment Receipt ---"<<endl;
    cout<<"Payment ID: "<<paymentId<<endl;
    cout<<"Session ID: "<<sessionId<<endl;
    cout<<"Amount Paid: Rs. "<<amount<<endl;
    cout<<"Method: "<<paymentMethod<<endl;
    cout<<"Status: "<<paymentStatus<<endl;
}

string Payment::checkPaymentStatus()
{
    return paymentStatus;
}