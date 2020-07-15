/*
 * FamilyCar.h
 *
 *  Created on: Jun 11, 2020
 *      Author: Harel Yada'n
 */

#ifndef FAMILYCAR_H_
#define FAMILYCAR_H_
#include "Car.h"

class FamilyCar : public car::Car {

private:
	static const int poll = 2;
public:
	FamilyCar( string name ){ this->name = name; }
	inline crossroads::Crossroads* beat(crossroads::Crossroads* current){
		//cout << name << "     " << current->getCRnumber() << endl;
		int choice =  rand() % current->getNumberOfRoads() + 0;
		if( choice > 0 ) return current->getCR( choice );
		return current;
	}
	inline int getPoll()const{ return poll; }
	virtual ~FamilyCar(){}
};


#endif /* FAMILYCAR_H_ */
