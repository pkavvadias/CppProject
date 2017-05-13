#include "ReservationHeader.h"
#include "RoomHeader.h"

RoomTypeB::RoomTypeB(){};
void RoomTypeB::setDiscountPerDay(int i){
    DiscountPerDay=i;
}
int RoomTypeB::getDiscountPerDay(){
    return DiscountPerDay;
}
/* This implementation of costCalculate() calculates and returns the monthly income generated
** by this room, by adding all daily incomes of the month. Daily incomes are calculated by
** applying daily discount rates to a fixed daily sum for each reservation, if said daily sum
** minus discount is lower than or equal to half of the fixed daily sum.*/
double RoomTypeB::costCalculate(){
    double cost=0;
    double finalPricePerDay;
    Reservation* previous=nullptr;
    int dayCounter=0;
    int i;
    for (const auto& r: Availability){
        if (r==nullptr && previous==nullptr){
            //no reservations
            continue;
        }
        else if (r!=nullptr && previous==nullptr){
            //new reservation after room being unreserved for day(s)
            dayCounter=1;
            //(we could have just incremented it, but we chose to assign 1 directly to be sure)
            previous=r;
            continue;
        }
        else if (r!=nullptr && previous!=nullptr && previous!=r){
            //new reservation immediately after the end of the previous reservation
            finalPricePerDay=RoomTypeA::getPricePerDay();
            for (i=0; i<dayCounter; i++){
                cost+=finalPricePerDay;
                if (finalPricePerDay-DiscountPerDay>=(RoomTypeA::getPricePerDay()/2)){
                    finalPricePerDay-=DiscountPerDay;
                }
            }
            dayCounter=1;
            //(this is the first day of the new reservation)
            previous=r;
            continue;
        }
        else if (r==nullptr && previous!=nullptr){
            //end of a reservation followed by unreserved day(s)
            finalPricePerDay=RoomTypeA::getPricePerDay();
            for (i=0; i<dayCounter; i++){
                cost+=finalPricePerDay;
                if (finalPricePerDay-DiscountPerDay>=(RoomTypeA::getPricePerDay()/2)){
                    finalPricePerDay-=DiscountPerDay;
                }
            }
            dayCounter=0;
            previous=r;
            continue;
        }
        else if (r!=nullptr && r==previous){
            //reservation continues
            dayCounter++;
            previous=r;
            continue;
        }
    }
    return cost;
}
/* This implementation of cancel(int) always returns false, as
** cancellations of RoomTypeB reservations are not allowed.*/
bool RoomTypeB::cancel (int ReservationId){
        return false;
}
