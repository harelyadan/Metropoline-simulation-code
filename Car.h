//
// Created by Harel Yada'n on 20-May-20.
//

#ifndef CPP2020_HW3_CAR_H
#define CPP2020_HW3_CAR_H

#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include <string>
#include "Crossroads.h"

namespace car {

class Car {
protected:
	string name;
	//crossroads::Crossroads* currentCR = NULL; // The current crossroad this car is place on.
public:
	Car* next =  NULL; // Pointer to next Car ( Linked list of cars - Metropolos ).
	virtual ~Car(){ }
	string getName() const { return name; }
	bool isEquals( Car * car ){ return car->getName() == name; }
	virtual crossroads::Crossroads* beat(crossroads::Crossroads*) = 0;
	virtual int getPoll() const = 0;
	//----Return the current crossroad----//
	//inline crossroads::Crossroads* getCurrentCrossroad() const{ return currentCR; }

	//----Place the car in a different crossroad----//
	//inline void placeCR( crossroads::Crossroads* cr ){ currentCR = cr; }
};
}

#endif //CPP2020_HW3_CAR_H
