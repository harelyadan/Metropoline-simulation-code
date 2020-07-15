//
// Created by Harel Yada'n on 20-May-20.
//

#include "Metropolis.h"

met::Metropolis::~Metropolis() {

	for( int i = 0; i < size; i++ )
		delete[] graph[i];
	delete[] graph;

	for( int i = 0; i < size; i++ )
		delete[] crossroads[i];
	delete[] crossroads;

	for( int i = 0; i < number_of_roads; i++ )
		delete[] roads[i];
	delete[] roads;

	//	car::Car* temp = headCars;
	//	for( int i = 0; i < number_of_cars; i++ ){
	//		delete temp;
	//		temp = temp->next;
	//	}
}

met::Metropolis::Metropolis( double **graph, int size, int number_of_roads ) {
	map = new Map<string, int>();
	this->size = size; this->number_of_roads = number_of_roads, number_of_cars = 0;
	this->graph = graph;

	int countRoads = 0;
	crossroads = new crossroads::Crossroads*[size];
	for ( int i = 0; i < size; i++ ){
		for( int j = 0; j < size; j++ )
			if( graph[i][j] > 0 ) countRoads++;
		crossroads[i] = new crossroads::Crossroads( i + 1, countRoads );
		countRoads = 0;
	}

	countRoads = 0;
	roads = new road::Road *[number_of_roads];
	for( int i = 0; i < size; i++ )
		for ( int j = 0; j < size; j++ )
			if( graph[i][j] > 0 ){
				crossroads[i]->addCR( crossroads[j] );
				roads[countRoads++] = new road::Road( graph[i][j], crossroads[i], crossroads[j] );
			}

	for( int i = 0; i < size; i++ )
		for ( int j = 0; j < size; j++ )
			this->graph[i][j] = 0;

}

void met::Metropolis::addCar( car::Car* car ) {
	if( headCars == NULL ){ headCars = car; tailCars = headCars; }
	else{ tailCars->next = car; tailCars = tailCars->next; }
	number_of_cars++;
}

void met::Metropolis::placeCarOnCrossroads( int cr_number, string carName ) {
	switch( carName[0] ){
	case 'S':
	{
		car::Car* sc = new SportsCar( carName );
		map->add(carName, cr_number);
		addCar( sc );
		break;
	}
	case 'F':
	{
		car::Car* fc = new FamilyCar( carName );
		map->add(carName, cr_number);
		addCar( fc );
		break;
	}
	case 'L':
	{
		car::Car* lc = new LuxuryCar( carName );
		map->add(carName, cr_number);
		addCar( lc );
		break;
	}
	case 'M':
		car::Car* mc = new Maserati( carName );
		map->add(carName, cr_number);
		addCar( mc );
		break;
	}
}

void met::Metropolis::IncreaseAPL( crossroads::Crossroads* cr1, crossroads::Crossroads* cr2, int poll ){
	if( cr1 == cr2 ) return;
	for( int i = 0; i < number_of_roads; i++ ){
		if( roads[i]->crsInclude( cr1, cr2 ) ){
			roads[i]->increasePollution( poll );
			graph[cr1->getCRnumber() - 1][cr2->getCRnumber() - 1] = roads[i]->getAPL();
		}
	}
}

crossroads::Crossroads* met::Metropolis::findCRbyCarName( string carName ){
	//cout << carName << "   findCRbyCarName"<< endl;
	int cr_number = map->get( carName );
	//cout << cr_number << endl;
	for( int i = 0; i < size; i ++ )
		if( crossroads[i]->getCRnumber() == cr_number ) return crossroads[i];
	return NULL;
}

void met::Metropolis::startSimulation( int beats ){
	for( int beat = 0; beat < beats; beat++ ){
		//cout << beat << endl;
		car::Car* temp = headCars;
		for( int i = 0; i < number_of_cars; i++ ){
			//cout << i  + 1  << endl;
			crossroads::Crossroads* cr1 = findCRbyCarName(temp->getName());
			//cout << "car: " << temp->getName() << "| cr1: " << cr1->getCRnumber() << endl;
			crossroads::Crossroads* cr2 = temp->beat( cr1 );
			//cout << "car: " << temp->getName() << "| cr2: " << cr2->getCRnumber() << endl;
			if( cr1 != cr2 ){
				map->deleteObject(temp->getName());
				map->add(temp->getName(), cr2->getCRnumber());
				IncreaseAPL( cr1, cr2, temp->getPoll() );
			}
			temp = temp->next;
		}
	}

	if( beats > 0){
		for( int i = 0; i < size; i++ )
			for( int j = 0; j < size; j++ )
				if( j < size - 1 ) cout << round( 100 * graph[i][j] ) / 100 << " ";
				else cout << round( 100 * graph[i][j] ) / 100 << endl;
	}


	for( int i = 0; i < size; i++ ){
		car::Car* temp = headCars;
		cout << i + 1 << ":";
		for( int j = 0; j < number_of_cars; j++ ){
			if( findCRbyCarName(temp->getName())->getCRnumber() == i + 1 )
				cout << " " << temp->getName();
			temp = temp->next;
		}
		cout << endl;
	}
}







