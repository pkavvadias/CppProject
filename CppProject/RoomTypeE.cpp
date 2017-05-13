#include "ReservationHeader.h"
#include "RoomHeader.h"

/* E-type room reservations can only be cancelled during a limited time window.
** Variable CancellationPermittedThreshold represents the day of the month that
** immediately follows the last day on which this kind of reservation can be cancelled.*/

RoomTypeE::RoomTypeE() {};
void RoomTypeE::setCancellationPermittedThreshold(int i){
    CancellationPermittedThreshold=i;
}
int RoomTypeE::getCancellationPermittedThreshold(){
    return CancellationPermittedThreshold;
}
void RoomTypeE::setCurrentDate(int i){
    CurrentDate=i;
}
int RoomTypeE::getCurrentDate(){
    return CurrentDate;
}
/* This implementation of cancel(int) checks if the current date is within the permitted time window.
** If this condition is met, the reservation is cancelled and value true is returned, otherwise the
** reservation remains as is and boolean value false is returned.*/
bool RoomTypeE::cancel(int ReservationId) {
    if (CurrentDate< CancellationPermittedThreshold) {
        return false;
    }
    else {
        for (int i=0; i<30; i++) {
            if (Room::getAvailabilityI(i) != nullptr) {
                if (Room::getAvailabilityI(i)->getReservationNumber() == ReservationId) {
                    Room::setAvailabilityI(i, nullptr);
                }
            }
        }
        return true;
    }
}
