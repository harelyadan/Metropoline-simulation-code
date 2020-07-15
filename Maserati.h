/*
 * Maserati.h
 *
 *  Created on: Jun 11, 2020
 *      Author: Harel Yada'n
 */

#ifndef MASERATI_H_
#define MASERATI_H_
#include "LuxuryCar.h"
#include "SportCar.h"


///כמו רכב ספורט

class Maserati : public SportsCar, public LuxuryCar {

public:
	inline Maserati(string name):SportsCar(name), LuxuryCar(name){ }
	crossroads::Crossroads* beat(crossroads::Crossroads* current){ return SportsCar::beat(current); }
	int getPoll()const{ return LuxuryCar::getPoll(); }
	virtual ~Maserati(){}

};


#endif /* MASERATI_H_ */
