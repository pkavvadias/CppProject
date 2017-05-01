//#include <atomic>
#include <string>
#include "ReservationHeader.h"
#include "RoomHeader.h"
typedef basic_string < char > string;

/* Children under 3 years of age have special beds and pay
** half the price per person each day.*/

RoomTypeD::RoomTypeD() {};
void RoomTypeD::setNumberOfChildrenBeds(int i){
    NumberOfChildrenBeds=i;
}
int RoomTypeD::getNumberOfChildrenBeds(){
    return NumberOfChildrenBeds;
}
/* This implementation of costCalculate() calculates and returns the monthly income generated by this room, by calculating and adding
** all daily incomes of the month. Daily income is calculated by multiplying a standard, fixed price with the number of adults in the
** room, and adding this result to the result of the multiplication of the number of children in the room with half the standard price.*/
double RoomTypeD::costCalculate(){
    double cost=0;
    for(int i=0; i<30; i++){
        if(getAvailabilityI(i)!=nullptr){
            cost+=((getAvailabilityI(i)->getNumberOfPeople()-NumberOfChildrenBeds)*getPricePerPerson())+(NumberOfChildrenBeds)*(0.5*getPricePerPerson());
        }
    }
    return cost;
}
