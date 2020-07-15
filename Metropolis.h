//
// Created by Harel Yada'n on 20-May-20.
//

#ifndef CPP2020_HW3_METROPOLIS_H
#define CPP2020_HW3_METROPOLIS_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>
#include <bits/stdc++.h>
#include "Crossroads.h"
#include "Road.h"
#include "Maserati.h"
#include "FamilyCar.h"
#include "Map.h"

using namespace std;

namespace met {
    class Metropolis {
    private:
        int size, number_of_roads, number_of_cars;
        double **graph; 
        crossroads::Crossroads **crossroads; // Pointer to array of crossroads
        road::Road **roads; // Pointer to array of roads
        Map<string, int> *map;
        car::Car *headCars = NULL, *tailCars = NULL; // Linked List of Cars
    public:
        Metropolis(double**, int , int );
        virtual ~Metropolis();
        void addCar( car::Car* );
        void placeCarOnCrossroads(int cr_number, string);
        void startSimulation( int );
        void IncreaseAPL( crossroads::Crossroads*, crossroads::Crossroads* , int);
        crossroads::Crossroads* findCRbyCarName( string );
    };

}


#endif //CPP2020_HW3_METROPOLIS_H
