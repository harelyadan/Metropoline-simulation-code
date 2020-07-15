/*
 * LuxuryCar.h
 *
 *  Created on: Jun 11, 2020
 *      Author: Harel Yada'n
 */

#ifndef LUXURYCAR_H_
#define LUXURYCAR_H_
#include "Car.h"

///סיכויים להשאר בצומת הוא 50 אחוז

class LuxuryCar : virtual public car::Car{
protected:
	static const int poll = 3;
public:
	LuxuryCar(string name){ this->name = name; }

	inline crossroads::Crossroads* beat(crossroads::Crossroads* current){
		int stay = rand() % 1 + 0;
		if( stay == 0 ) return current;
		int choice =  rand() % current->getNumberOfRoads() + 1;
		return current->getCR( choice - 1 );
	}
	inline int getPoll()const{ return poll; }
	virtual ~LuxuryCar(){}
};


#endif /* LUXURYCAR_H_ */
