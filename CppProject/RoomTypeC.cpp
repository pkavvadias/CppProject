//#include <atomic>
#include <string>
#include "ReservationHeader.h"
#include "RoomHeader.h"
typedef basic_string < char > string;

RoomTypeC::RoomTypeC() {};
void RoomTypeC::setMinimumDays(int i){
    MinimumDays=i;
}
int RoomTypeC::getMinimumDays(){
    return MinimumDays;
}
void RoomTypeC::setMinimumPeople(int i){
    MinimumPeople=i;
}
int RoomTypeC::getMinimumPeople(){
    return MinimumPeople;
}
/* This implementation of addReservation(Reservation*) checks if the requested number of people and duration of stay meet the respective
** maximum and/or minimum requirements of the room. If those conditions are met, it checks if the room is available for the requested
** duration of stay, and returns the appropriate boolean value. If initial conditions are not met, a false boolean value is returned.*/
bool RoomTypeC::addReservation(Reservation* res){
	
		bool a = true;
		for (int i = res->getArrival(); i < (res->getArrival() + res->getDaysOfStay()); i++)
		{
			if (Availability[i] == nullptr &&res->getNumberOfPeople() <= getMaxCapacity() && res->getDaysOfStay() >= MinimumDays&&res->getNumberOfPeople() >= MinimumPeople)
			{

				Availability[i] = res;
				Availability[i]->setReservationNumber(res->getReservationNumber());
				res->setRoom(this);
				a = true;
			}
			else
			{
				a = false;
			}

		}
		return a;
	
}
