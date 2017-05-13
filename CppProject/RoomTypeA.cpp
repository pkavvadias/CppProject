#include "ReservationHeader.h"
#include "RoomHeader.h"
RoomTypeA::RoomTypeA(){}
void RoomTypeA::setPricePerDay(double i){
    PricePerDay=i;
}
double RoomTypeA::getPricePerDay(){
    return PricePerDay;
}
/* This implementation of costCalculate also calculates and returns the monthly income generated
** by this room, taking into consideration the fact that the room is associated with a fixed daily price.*/
double RoomTypeA::costCalculate(){
    double cost=0;
        for(int i=0; i<30; i++){
            if(getAvailabilityI(i)!=nullptr){
                cost+=PricePerDay;
            }
        }
    return cost;
}
