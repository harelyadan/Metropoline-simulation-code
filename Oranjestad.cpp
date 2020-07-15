#include "Metropolis.h"


bool isInt( string );
bool isDouble( string );
int stringToInt( string );
double stringToDouble( string );
bool insertLineIntoGraph(double**, int, string, int&, int& );
bool convertLineToVehicleLocations( met::Metropolis*, string);

int main( int argc, char* argv[] ) {
	ifstream met_graph( argv[1] ), vehicle_locations( argv[2] );
	string line, beats;
	int size = 0, row = 0, number_of_roads = 0;
	double** graph;
	met::Metropolis* metropolis;

	if( met_graph.is_open() ){

		getline( met_graph , line );
		if( isInt( line ) ) {
			size = stringToInt(line);
			if( size < 0 ) { cerr << "ERROR: invalid input." << endl; return 0; }
		}
		else { cerr << "ERROR: invalid input." << endl; return 0; }

		//----Allocating 2D double array ( graph )----//
		graph = new double *[size];
		for( int i = 0; i < size; i++ )
			graph[i] = new double[size];

		while( getline( met_graph , line ) )
			if( !insertLineIntoGraph( graph, size, line, row, number_of_roads ) ) { cerr << "ERROR: invalid input." << endl; return 0; }

		metropolis = new met::Metropolis( graph, size, number_of_roads );
		met_graph.close();
	}
	else { cerr << "ERROR: invalid input." << endl; return 0; }
	if( vehicle_locations.is_open() ){

		row = 0;
		while( getline( vehicle_locations, line ) ){
			if( row == size || !convertLineToVehicleLocations( metropolis, line) ){ cerr << "ERROR: invalid input." << endl; return 0; }
			row++;
		}
		vehicle_locations.close();
	}
	else { cerr << "ERROR: invalid input." << endl; return 0; }
	//cout << "11111111111111111" << endl;
	cin >> beats;
	if( !isInt( beats  ) || stringToInt( beats ) < 0 ) { cerr << "ERROR: invalid input." << endl; return 0; }
	metropolis->startSimulation( stringToInt( beats ) );
	return 0;
}

//----Check if int----//
bool isInt( string myString ) {
	istringstream iss(myString);
	int f;
	iss >> noskipws >> f;
	return iss.eof() && !iss.fail();
}

//----Convert string to int----//
int stringToInt( string myString ){
	int n;
	stringstream to_int( myString );
	to_int >> n;
	return n;
}

//----Check if double----//
bool isDouble( string myString ){
	istringstream iss(myString);
	double f;
	iss >> noskipws >> f;
	return iss.eof() && !iss.fail();
}

//----Convert string to double----//
double stringToDouble( string num ){
	double n;
	stringstream to_double( num );
	to_double >> n;
	return n;
}

bool insertLineIntoGraph( double** graph, int size, string line, int& row, int& number_of_roads ){
	if( row == size ) return false;
	stringstream ss( line );
	string str;
	int j = 0;
	double tm;
	while( getline( ss, str, ' ' ) ){
		if( !isDouble( str ) ) return false;
		else tm = stringToDouble( str );
		if( j < size ){
			if( tm < 0 ) return false;
			else if ( tm == 0 ) graph[row][j] = 0;
			else { graph[row][j] = tm; number_of_roads++; }
		}
		else break;
		j++;
	}
	row++;
	return true;
}

bool isCorrectCarName(string car){
	if(car[0] != 'L' && car[0] != 'F' && car[0] != 'M' && car[0] != 'S') return false;
	string num = car.substr(1,car.size() - 1);
	return isInt( num ) && stringToInt( num ) > 0;
}

bool convertLineToVehicleLocations( met::Metropolis* metropolis, string line){
	//cout << size << endl;
	stringstream ss( line );
	string str;
	getline( ss, str, ' ' );
	stringstream ss1( str );
	getline( ss1, str, ':' );
	int cr;// j = 0;
	if( !isInt( str ) ) return false;
	cr = stringToInt( str );
	while( getline( ss, str, ' ' ) ){
		if( !isCorrectCarName( str ) ) return false;
		metropolis->placeCarOnCrossroads( cr, str );
	}
	return true;
}

