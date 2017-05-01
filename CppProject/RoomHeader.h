#ifndef ROOMHEADER_H_INCLUDED
#define ROOMHEADER_H_INCLUDED

#include <string>
using namespace std;

class Reservation;
class Room {
private:
	int RoomNumber;
	int MaxCapacity;
	double PricePerPerson;
	//Reservation* Availability[30];
	static int RoomId;
//protected:
public:Reservation* Availability[30];
public:
	Room();
	int getRoomNumber();
	void setMaxCapacity(int);
	int getMaxCapacity();
	void setPricePerPerson(double);
	double getPricePerPerson();
	virtual bool addReservation(Reservation*);
	virtual double costCalculate();
	virtual bool cancel(int);
	float occupiedPercentage();
	Reservation* getAvailabilityI(int);
	void setAvailabilityI(int, Reservation*);
};

class RoomTypeA : public Room {
private:
	double PricePerDay;
public:
	RoomTypeA();
	void setPricePerDay(double);
	double getPricePerDay();
	virtual double costCalculate() override;
};

class RoomTypeB : public RoomTypeA {
private:
	int DiscountPerDay;
public:
	RoomTypeB();
	void setDiscountPerDay(int);
	int getDiscountPerDay();
	virtual double costCalculate() override;
	virtual bool cancel(int) override;
};

class RoomTypeC : public Room {
private:
	int MinimumDays;
	int MinimumPeople;
public:
	RoomTypeC();
	void setMinimumDays(int);
	int getMinimumDays();
	void setMinimumPeople(int);
	int getMinimumPeople();
	virtual bool addReservation(Reservation*) override;
};

class RoomTypeD : public Room {
private:
	int NumberOfChildrenBeds;
public:
	RoomTypeD();
	void setNumberOfChildrenBeds(int);
	int getNumberOfChildrenBeds();
	virtual double costCalculate() override;
};

class RoomTypeE : public Room {
private:
	int CancellationPermittedThreshold;
	int CurrentDate;
public:
	RoomTypeE();
	void setCancellationPermittedThreshold(int);
	int getCancellationPermittedThreshold();
	void setCurrentDate(int);
	int getCurrentDate();
	virtual bool cancel(int) override;
};

#endif //ROOMHEADER_H_INCLUDED
