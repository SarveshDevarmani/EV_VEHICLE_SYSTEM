#include<iostream>
using namespace std;

class PricingEngine{
 
   private:
    double normalRate;
    double peakRate;
    double offPeakRate;

   public:
     PricingEngine(){
        normalRate=10;
        peakRate=15;
        offPeakRate=8;
     }
     void setRate(double normal,double peak,double off ){
        normalRate=normal;
        peakRate=peak;
        offPeakRate=off;
     }
     double calculateCharge(double energyConsumed,int timeType){
        double rate;

        if(timeType==1){
            rate=normalRate;
        }
        else if(timeType==2){
            rate=peakRate;
        }
        else{
            rate=offPeakRate;
        }
        return energyConsumed*rate;
     }
double getNormalRate()
    {
        return normalRate;
    }

    double getPeakRate()
    {
        return peakRate;
    }

    double getOffPeakRate()
    {
        return offPeakRate;
    }


};

int main(){

}