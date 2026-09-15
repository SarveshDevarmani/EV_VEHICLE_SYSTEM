#include "PricingEngine.h"
#include <iostream>

using namespace std;

    PricingEngine:: PricingEngine(){
        normalRate=10;
        peakRate=15;
        offPeakRate=8;
     }
     void PricingEngine::setRate(double normal,double peak,double off ){
        normalRate=normal;
        peakRate=peak;
        offPeakRate=off;
     }
     double PricingEngine::calculateCharge(double energyConsumed,int timeType){
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
double PricingEngine::getNormalRate()
    {
        return normalRate;
    }

    double PricingEngine::getPeakRate()
    {
        return peakRate;
    }

    double PricingEngine::getOffPeakRate()
    {
        return offPeakRate;
    }

