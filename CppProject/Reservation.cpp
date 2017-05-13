#include <string>
#include "ReservationHeader.h"
#include "RoomHeader.h"

int Reservation::id = 1;
Room* room = nullptr;
Reservation::Reservation() {
	ReservationNumber = id;
	id++;
}
void Reservation::setRoom(Room* r) {
	room = r;
}
Room* Reservation::getRoom() {
	return room;
}
void Reservation::setArrival(int i) {
	Arrival = i;
}
int Reservation::getArrival() {
	return Arrival;
}
void Reservation::setDaysOfStay(int i) {
	DaysOfStay = i;
}
int Reservation::getDaysOfStay() {
	return DaysOfStay;
}
void Reservation::setNumberOfPeople(int i) {
	NumberOfPeople = i;
}
int Reservation::getNumberOfPeople() {
	return NumberOfPeople;
}
void Reservation::setReservationNumber(int i) {
	ReservationNumber = i;
}
int Reservation::getReservationNumber() {
	return ReservationNumber;
}
void Reservation::setClient(string s) {
	Client = s;
}
string Reservation::getClient() {
	return Client;
}
