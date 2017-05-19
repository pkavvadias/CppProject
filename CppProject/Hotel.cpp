#include "ReservationHeader.h"
#include "RoomHeader.h"
#include "HotelHeader.h"
#include <vector>
#include <iostream>
#include <iomanip>//Required for aligning of reservation plan

/*
 * Overloading operator '-'
 */
void operator-(vector<Reservation*>&v, int resid) //Test for operator overloading
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->getReservationNumber() == resid)
		{
			v[i]->getRoom()->cancel(resid);
			delete v[i];
			v.erase(v.begin() + i);
		}
	}
}

/*
 * Overloading operator '+='
 */
double operator+=(double,vector<Room*>&v)
{
	double income=0;
	for(Room* r:v)
	{
		income += r->costCalculate();
	}
	return income;
}

/*
 * Overloading operator '+'
 */
void operator+(vector<Reservation*>&v,Reservation* &res)
{
	v.push_back(res);
}

void Hotel::addRoom(Room* r)
{
	rooms.push_back(r);
}
void Hotel::setHotelName(string s)
{
	HotelName = s;
}
string Hotel::getHotelName()
{
	return HotelName;
}
vector<Room*> Hotel::getRoom()
{
	return rooms;
}
void Hotel::setReservations(Reservation* res)
{
	reservations.push_back(res);
}
vector<Reservation*> Hotel::getReservations()
{
	return reservations;
}
Room* Hotel:: retrieveRoomFromNumber(int roomid)
{
	Room* c = nullptr;
	for (Room* rg : rooms) {
		if (rg->getRoomNumber() == roomid)
		{
			c = rg; break;
		}
		else {

			c = nullptr;
		}
	}
	return c;
}
Reservation* Hotel:: retrieveReservationFromNumber(int resid)
{
	Reservation* a = nullptr;
	for (int i = 0; i < reservations.size(); i++) {
		if(reservations[i]->getReservationNumber()==resid)
		{
			a = reservations[i];
			break;
		}
		
	}
	return a;
}
bool Hotel::addReservationToRoom(Reservation* r, int rnumb)
{
	bool a = true;
	if (retrieveRoomFromNumber(rnumb) == nullptr)
	{
		cout << "Room not found so reservation was not added"<<endl;
		a = false;
	}
	else
	{
		for (int k = r->getArrival(); k < (r->getArrival() + r->getDaysOfStay()); k++)
		{
			if (retrieveRoomFromNumber(rnumb)->getAvailabilityI(k) != nullptr) 
			{
				cout << "Reservation was not added.Room is occupied"<<endl;
				a = false;
				break;
			}
			else
			{
				r->setRoom(retrieveRoomFromNumber(rnumb));
				if (retrieveRoomFromNumber(rnumb)->addReservation(r) == false)
				{
					r->getRoom()->cancel(r->getReservationNumber());
					cout << "Reservation not added.Check room's requirements"<<endl;
					a = false;
					break;
				}
				cout << "Reservation with reservation id " << r->getReservationNumber() << " added successfully to room with id " << rnumb<<endl;
				//reservations.push_back(r);
				reservations + r;//Overloaded operator '+'
				a = true;
				break;
			}

		}
		if (a == false) { delete r; }
	}
	return a;
}
int Hotel::addReservationToFirstRoom(Reservation* reserv)
{
	int a=0 ;
	int stopper = 0;
	int reservid=-1;
	for (int i = 0; i < rooms.size(); i++) {
		for (int k = reserv->getArrival(); k < (reserv->getArrival() + reserv->getDaysOfStay()); k++)
		{
			if (rooms[i]->getAvailabilityI(k) != nullptr) //Checks if room i is available the reservation dates
			{
				
				a = 0;
			}
			else
			{
				if (rooms[i]->addReservation(reserv) == false)
				{
					rooms[i]->cancel(reserv->getReservationNumber());
					if (i < rooms.size() + 1) {
						i = i + 1;
					}
					else {
						a = 0;
						
					}
					break;

				}
				else
				{
					reserv->setRoom(rooms[i]);
					a = rooms[i]->getRoomNumber();
					rooms[i]->addReservation(reserv);//Adds reservation to the room of the array
					retrieveRoomFromNumber(rooms[i]->getRoomNumber())->addReservation(reserv);
					reservid = reserv->getReservationNumber();
					//reservations.push_back(reserv);
					reservations + reserv;//Overloaded operator '+'
					stopper = 1;
				}

			}

			if (a != 0)
			{
				break;
			}//Loop needs to stop when an available room is found
		}
		if (stopper == 1) { break; }//Required else reservation was added multiple times
	}
		if (a == 0)
		{
			delete reserv;
			cout<<"No available room found"<<endl;
			return a;
		}
		else {

			cout<<"Reservation with reservation id " << reservid << " added successfully to room with room number " << a << ""<<endl;

			return a;
		}
}
void Hotel::cancelReservation(int reservationid)
{
	if (retrieveReservationFromNumber(reservationid) != nullptr)
	{/**
		for(int i=0;i<reservations.size();i++)
		{
			if(reservations[i]->getReservationNumber()==reservationid)
			{
				reservations[i]->getRoom()->cancel(reservationid);
				delete reservations[i];//Test for deleting pointer
				reservations.erase(reservations.begin()+i);
			}
		}
		*/
		reservations - reservationid;//Overloaded operator '-'
		cout<< "Reservation with reservation id " << reservationid << " was canceled"<<endl;
	}

	else
	{
		cout << "Reservation with reservation id " << reservationid << " was not canceled"<<endl;
	}
			
}

double Hotel::incomeCalculate(int roomnumb)
{
	double earnings;
	earnings = retrieveRoomFromNumber(roomnumb)->costCalculate();
	return earnings;
}

double Hotel::incomeCalculate()
{/**
	double income = 0;
	for (Room* r : rooms)
	{
		income += r->costCalculate();
	}
	return income;
	*/
	double earnings = 0;
	return earnings += rooms;//Overloaded operator '+='
	
}

void Hotel::reservationPlan()
{
	cout << "Room\t";
	for (int i = 1; i < 31; i++) {
		cout << setw(3) << i;} //Prints days
	cout << endl;
	for (Room* roomavailable : rooms) {
		cout <<roomavailable->getRoomNumber() << "      ";//Prints room number of all available rooms
		for (int k = 0; k < 30; k++) //Checks availability array and prints from it
		{
			if (roomavailable->getAvailabilityI(k) == nullptr) {
				cout << " - ";
			}
			else {
			 cout << " * ";
			}

		}
		cout <<endl;
	}
}
