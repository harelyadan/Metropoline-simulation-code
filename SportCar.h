/*
 * SportsCar.h
 *
 *  Created on: Jun 11, 2020
 *      Author: Harel Yada'n
 */

#ifndef SPORTCAR_H_
#define SPORTCAR_H_
#include "Car.h"


class SportsCar : virtual public car::Car {
private:
	static const int poll = 4;
public:
	SportsCar(string name){ this->name = name; }
	inline crossroads::Crossroads* beat(crossroads::Crossroads* current){
		//cout << "Sport Car -beat- : " << current->getCRnumber() << endl;
		int choice = 0;
		//cout << "number of roads: " << current->getNumberOfRoads() << endl;
		if( current->getNumberOfRoads() > 0 ){
			choice = rand() % current->getNumberOfRoads() + 1;
			return current->getCR( choice - 1 );
		}
		else return current;
	}
	inline int getPoll()const{ return poll; }

	virtual ~SportsCar(){}
};

#endif /* SPORTCAR_H_ */
