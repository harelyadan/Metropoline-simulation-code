//
// Created by Harel Yada'n on 20-May-20.
//

#ifndef CPP2020_HW3_CROSSROADS_H
#define CPP2020_HW3_CROSSROADS_H
#include <cstddef>
using namespace std;

namespace crossroads {
class Crossroads {
private:
	Crossroads **crossroadsArr;
	int cr_number, number_of_cars, number_of_roads;
public:
	inline Crossroads( int cr, int number_of_roads ):number_of_cars(0){
		cr_number = cr;
		this->number_of_roads = number_of_roads;
		crossroadsArr = new Crossroads *[number_of_roads];
		for( int i = 0; i < number_of_roads; i++ )
			crossroadsArr[i] = NULL;
	}
	virtual ~Crossroads(){
		delete[] crossroadsArr;
	}
	
	//----Icrease by 1 number of cars----//
	inline Crossroads operator++( int ){
		Crossroads temp( *this );
		number_of_cars++;
		return temp;
	}
	
	//----Add another crossroad to crossroadsArr----//
	//-----Connect another crossroad-----//
	inline void addCR( Crossroads* cr ){
		for( int i = 0; i < number_of_roads; i++ )
			if( crossroadsArr[i] == NULL ) crossroadsArr[i] = cr;
	}
	
	//----Return another crossroad by index ( random choice )----//
	inline Crossroads* getCR( int choice ){ return crossroadsArr[ choice ]; }
	
	
	inline int getNumberOfRoads() const { return number_of_roads; }
	inline int getCRnumber() const { return cr_number; }
};

}
#endif //CPP2020_HW3_CROSSROADS_H
