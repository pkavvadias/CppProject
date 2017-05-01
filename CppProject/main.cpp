#include <iostream>
//#include <random>
#include <string>
#include "ReservationHeader.h"
#include "RoomHeader.h"
#include <HotelHeader.h>
#include <ctime>
#include <iomanip>


//typedef basic_string < char > string;
using namespace std;

int main()
{
	string clientName;
	int number;
	int arrivalDay;
	int daysToStay;
	int roomiddecider;
	int roomid;
	Hotel* hotel=new Hotel();
	hotel->setHotelName("Hotel");
	int userinput;//Will be used for user input
				  //First names taken from wikipedia's list of most common names in Greece
	string firstNames[] = { "George", "Giannis", "Konstantinos", "Kostas", "Dimitris", "Nikos", "Panagiotis", "Vasilis",
		"Christos", "Thanasis", "Michalis", "Maria", "Eleni", "Vasiliki", "Sofia", "Aggeliki", "Dimitra", "Kwstantina" };
	//Last names taken from wikipedia's list of most common last names in Greece
	string lastNames[] = { "Papadopoulos", "Vlachos   ", "Angelopoulos", "Nikolaidis", "Georgiou   ", "Athanasiadis",
		"Dimitriadis", "Papadakis  ", "Panagiotopoulos", "Antoniou    ", "Papantoniou ", "Petridis    " };//Spaces required for better aligning

	//Block for first room
	
		Room* room1 = new Room();
		room1->setPricePerPerson(20);
		room1->setMaxCapacity(4);
		hotel->addRoom(room1);

	
	//Block for second room
	
		Room* room2 = new Room();
		room2->setPricePerPerson(15);
		room2->setMaxCapacity(2);
		hotel->addRoom(room2);
	
	//Block for third room
	
		RoomTypeA* room3 = new RoomTypeA();
		room3->setPricePerDay(10);
		room3->setPricePerPerson(5);
		room3->setMaxCapacity(2);
		hotel->addRoom(room3);
	
	//Block for forth room
	
		RoomTypeB* room4 = new RoomTypeB();
		room4->setDiscountPerDay(5);
		room4->setPricePerDay(15);
		room4->setPricePerPerson(25);
		room4->setMaxCapacity(4);
		hotel->addRoom(room4);
	

		//Block for fifth room

		RoomTypeC* room5 = new RoomTypeC();
		room5->setMinimumDays(4);
		room5->setMinimumPeople(5);
		room5->setMaxCapacity(6);
		room5->setPricePerPerson(20);
		hotel->addRoom(room5);

		//Block for sixth room

		RoomTypeD* room6 = new RoomTypeD();
		room6->setNumberOfChildrenBeds(2);
		room6->setPricePerPerson(14);
		room6->setMaxCapacity(5);
		hotel->addRoom(room6);

		//Block for seventh room

		RoomTypeE* room7 = new RoomTypeE();
		room7->setPricePerPerson(19);
		room7->setMaxCapacity(4);
		room7->setCancellationPermittedThreshold(3);
		room7->setCurrentDate(5);
		hotel->addRoom(room7);

		//Block for eighth room

		Room* room8 = new Room();
		room8->setPricePerPerson(8);
		room8->setMaxCapacity(2);
		hotel->addRoom(room8);

		//Block for ninth room

		RoomTypeA* room9 = new RoomTypeA();
		room9->setPricePerDay(30);
		room9->setPricePerPerson(15);
		room9->setMaxCapacity(2);
		hotel->addRoom(room9);

		//Block for tenth room

		RoomTypeB* room10 = new RoomTypeB();
		room10->setDiscountPerDay(3);
		room10->setPricePerPerson(10);
		room10->setPricePerDay(30);
		room10->setMaxCapacity(3);
		hotel->addRoom(room10);
		srand(time(NULL));//Randomize rand values based on time
		int k = 0;
		int term = 0;
		int random_cancel;
		//for (int i = 0;; i++) {
	while(term!=-1){
			while (k == 0) {
				string fullName = firstNames[rand() % (sizeof(firstNames) / sizeof(firstNames[0]))] + " " + lastNames[rand() % (sizeof(lastNames) / sizeof(lastNames[0]))];
				Reservation* reservation = new Reservation();
				reservation->setClient(fullName);
				reservation->setArrival((rand() % 30)+1);
				reservation->setDaysOfStay(rand() % (31 - reservation->getArrival())+1);
				reservation->setNumberOfPeople(rand() % 5 + 1);
				hotel->addReservationToFirstRoom(reservation);
				hotel->setReservations(reservation);
				random_cancel = rand() % 3;
				if (random_cancel == 2)
				{
					int resget = rand() % hotel->getReservations().size()+1;
					
					hotel->cancelReservation(resget);

				}
				k = 1;
			}
			cout << "Press 1 for next repeat(program continues)" << endl;
			cout << "Press 2 to add a reservation" << endl;
			cout << "Press 3 to cancel a reservation" << endl;
			cout << "Press 4 to view reservations" << endl;
			cout << "Press 5 to view rooms" << endl;
			cout << "Press 6 to view reservation plan" << endl;
			cout << "Press 7 to view income" << endl;
			cout << "Press any other number to exit" << endl;
			cin >> userinput;
			if (userinput < 1 || userinput > 7) 
			{
				term = -1;
			}
			switch(userinput)
			{
			case 1:
				k = 0;//Controls the while statement
				break;
			case 2:
			{
				cin.clear();//Required to clear buffer
				Reservation* newres = new Reservation();
				cout << "Insert name" << endl;
				cin >> clientName;
				cout << "Insert arrival day" << endl;
				cin >> arrivalDay;

				while (cin.fail()) {//Checks for correct input
					cout << "Wrong input,please try again" << endl;
					cin.clear();
					cin.ignore(256, '\n');//Required else loops infinitely
					cin >> arrivalDay;
				}
				cout << "Insert days of stay" << endl;
				cin >> daysToStay;

				while (cin.fail()) {
					cout << "Wrong input,please try again" << endl;
					cin.clear();
					cin.ignore(256, '\n');//Required else loops infinitely
					cin >>daysToStay;
				}
				cout << "Insert number of people" << endl;
				cin >> number;

				while (cin.fail()) {
					cout << "Wrong input,please try again" << endl;
					cin.clear();
					cin.ignore(256, '\n');//Required else loops infinitely
					cin >> number;
				}
				cout << "Press 1 if you want to enter specific room id or press any other number to automatically assign it " << endl;
				cin >> roomiddecider;
				while (cin.fail()) {
					cout << "Wrong input,please try again" << endl;
					cin.clear();
					cin.ignore(256, '\n');//Required else loops infinitely
					cin >> roomiddecider;
				}
				if (roomiddecider == 1) {
					cout << "Insert room id" << endl;
					cin >> roomid;
				}
				else {
					roomid = -1;
				}
				newres->setArrival(arrivalDay - 1);//Required else wrong results
				newres->setDaysOfStay(daysToStay);
				newres->setClient(clientName);
				newres->setNumberOfPeople(number);
				if (roomid != -1) {
					hotel->addReservationToRoom(newres, roomid);
				}
				else {
					hotel->addReservationToFirstRoom(newres);
					hotel->setReservations(newres);
				}
			}
					break;
				
			case 3:
				int idToCancel;
				cout << "Insert reservation id to cancel" << endl;
				cin >> idToCancel;
				while (cin.fail()) {
					cout << "Wrong input,please try again" << endl;
					cin.clear();
					cin.ignore(256, '\n');//Required else loops infinitely
					cin >> idToCancel;
				}
				hotel->cancelReservation(idToCancel);
				break;
			case 4:
				cout<<"ID \t Client name \t\t     Room number "<<endl;
				for (Reservation* r : hotel->getReservations()) {
					//The above if statement is required to avoid exception if no room was available(so reservation not saved)
					if (r->getRoom() == nullptr) { cout<<""; }
					else {

						cout << r->getReservationNumber() << "\t" << r->getClient() << "\t\t " << r->getRoom()->getRoomNumber() << endl;

					}
				}
				break;
			case 5:
				cout << "ID \t Fullness \t Income \t" << endl;
				for (Room* r : hotel->getRoom())
				{
					cout << r->getRoomNumber() << " \t " << setprecision(4) << r->occupiedPercentage() << " \t\t " << hotel->incomeCalculate(r->getRoomNumber()) << " \t " << endl;

				}
				break;
			case 6:
				hotel->reservationPlan();
				break;
			case 7:
				int roomind;
				cout << "Press 1 if you want to search income of specific room or an other number to find total income" << endl;
				cin >> roomind;
				while (cin.fail()) {
					cout << "Wrong input,please try again" << endl;
					cin.clear();
					cin.ignore(256, '\n');//Required else loops infinitely
					cin >> roomind;
				}
				if (roomind == 1)
				{
					int roomnumb;
					int rtester=-1;
					cout << "Enter room number" << endl;
					cin >> roomnumb;
					while (cin.fail()) {
						cout << "Wrong input,please try again" << endl;
						cin.clear();
						cin.ignore(256, '\n');//Required else loops infinitely
						cin >> roomnumb;
					}
					for(Room* r:hotel->getRoom())
					{
						if (roomnumb == r->getRoomNumber()) { rtester = 0; break; }
					}
					if (rtester != -1)
					{
						cout << "Income of room with room number " << roomnumb << " is " << hotel->incomeCalculate(roomnumb) << " euros" << endl;
						break;
					}
					else
					{
						cout << "Room with id " <<roomnumb <<" does not exist" << endl;
					}
				}
				else {

					cout << "Total income is " << hotel->incomeCalculate() << endl;

				}
				break;
			default:
				break;
			}
		}
	getchar();
}

	
