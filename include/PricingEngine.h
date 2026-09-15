#ifndef PRICINGENGINE_H
#define PRICINGENGINE_H

class PricingEngine{
  private:
    double normalRate;
    double peakRate;
    double offPeakRate;

  public:
       PricingEngine();
       
       void setRate(double normal,double peak,double off);
       double calculateCharge(double energyConsumed,int timeType);
       double getNormalRate();
       double getPeakRate();
       double getOffPeakRate();
};

#endif