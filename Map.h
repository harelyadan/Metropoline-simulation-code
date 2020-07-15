/*
 * Map.h
 *
 *  Created on: Jun 9, 2020
 *      Author: Harel Yada'n
 */

#ifndef MAP_H_
#define MAP_H_

#include <sstream>
#include <cstdio>
#include <string>
#include <iostream>

template <class key, class value>

class Object{
private:
	key k;
	value v;
public:
	Object<key, value> *next;
	inline Object( key newKey, value newValue ):next(NULL){ k = newKey; v = newValue; }
	inline value getValue() const{ return v; }
	inline key getKey() const{return k;}
	inline bool operator<(const Object& other ){ return k < other.k; }
	inline bool operator==( const key other ){ return k == other;}
	inline friend ostream& operator<<(ostream& out, Object& obj){ out << obj.k << " " <<  obj.v << '\n'; return out; }

	virtual ~Object(){}
};

template <class key1, class value1>

class Map{
private:
	int current;
	Object<key1, value1> *head;
public:
	inline Map(): current(0), head(NULL){ }
	inline void add( key1 newKey, value1 newValue ){
		Object<key1, value1> *obj = new Object<key1, value1>(newKey, newValue);
		if( head == NULL )
			head = obj;
		else{
			Object<key1, value1> *temp = head;
			Object<key1, value1> *pre = head;
			for( int i = 0; i < current; i++ ){
				if( obj->getKey() < temp->getKey() ){
					if( temp == head ){
						obj->next = temp;
						head = obj;
						break;
					}
					else{
						pre->next = obj;
						obj->next = temp;
						break;
					}
				}
				else{ pre = temp; temp = temp->next; }
			}
			if( temp == NULL )pre->next = obj;
		}
		current++;
	}


	inline value1 get( key1 key ) const{
		Object<key1, value1> *temp = head;
		for( int i = 0; i < current; i++ ){
			if( temp->operator ==(key) ) return temp->getValue();
			temp = temp->next;
		}
		return 0;
	}

	inline void deleteObject( key1 key ){
		Object<key1, value1> *temp = head;
		Object<key1, value1> *pre = head;
		for( int i = 0; i < current; i ++ ){
			if( temp->operator ==(key) ){
				if( temp == head ){
					head = temp->next;
					delete temp;
					current--;
					break;
				}
				else{
					pre->next = temp->next;
					delete temp;
					current--;
					break;
				}
			}
			pre = temp;
			temp = temp->next;
		}
	}

	inline void clear(){
		Object<key1, value1> *temp = head;
		Object<key1, value1> *pre = head;
		for( int i = 0; i < current; i ++ ){
			temp = temp->next;
			delete pre;
			pre = temp;
		}
		current = 0;
	}

	inline void print(){
		Object<key1, value1> *temp = head;
		for( int i = 0; i < current; i ++ ){
			cout << temp << endl;
			temp = temp->next;
		}
	}
	inline int size(){ return current; }

	virtual ~Map(){}
};


#endif /* MAP_H_ */
