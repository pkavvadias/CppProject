#ifndef HOTELHEADER_H_INCLUDED
#define HOTELHEADER_H_INCLUDED
#include<vector>
using namespace std;
class Room;
class Reservation;
class Hotel
{
private:
	string HotelName;
	vector<Room*> rooms;
	vector<Reservation*> reservations;
public:
	void addRoom(Room*);
	void setHotelName(string);
	string getHotelName();
	vector<Room*> getRoom();
	void setReservations(Reservation*);
	vector<Reservation*> getReservations();
	Room* retrieveRoomFromNumber(int);
	Reservation* retrieveReservationFromNumber(int);
	bool addReservationToRoom(Reservation*, int);
	int addReservationToFirstRoom(Reservation*);
	void cancelReservation(int);
	double incomeCalculate(int);
	double incomeCalculate();
	void reservationPlan();
};
#endif