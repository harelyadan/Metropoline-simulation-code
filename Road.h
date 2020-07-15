//
// Created by Harel Yada'n on 20-May-20.
//

#ifndef CPP2020_HW3_ROAD_H
#define CPP2020_HW3_ROAD_H
#include <cstddef>
#include "Crossroads.h"

namespace road {
class Road {
private:
	double length, air_pollution_level;
	crossroads::Crossroads *cr1 = NULL, *cr2 = NULL; // 2 Crossroads that make the road
public:
	inline Road( double len, crossroads::Crossroads* cr1, crossroads::Crossroads* cr2 ):
		air_pollution_level(0){ length = len; this->cr1 = cr1; this->cr2 = cr2; }
	inline virtual ~Road(){}
	
	//----Increase air pollution by c / length----//
	inline void increasePollution( int c ){ air_pollution_level += c / length; }

	inline void setLength( double len ){ length = len;  }

	//----Return true if the road contains this crossroad----// 
	inline bool crsInclude( crossroads::Crossroads* cr1, crossroads::Crossroads* cr2 ){
		return ( this->cr1 == cr1 || this->cr1 == cr2 ) && ( this->cr2 == cr1 || this->cr2 == cr2 ); }
	inline double getAPL( ) const { return air_pollution_level; }
};

}
#endif //CPP2020_HW3_ROAD_H
