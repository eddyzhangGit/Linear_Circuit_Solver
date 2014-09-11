using namespace std;
#ifndef RESISTOR_H
#define RESISTOR_H
#include <cstdlib>
#include <iostream>
#include<sstream>
#include<iomanip>
#include<math.h>
class Resistor{
private:
	Resistor* next;
	string Label;
	double resistance;
	int endpoint[2];
public:
	Resistor(){ next = NULL; }    //defualt contructor
	Resistor(string, double, int, int); //set label and endpoint 0, endpoint 1, next to NULL
	~Resistor(){if (next != NULL) delete next; }
	//basic enable functions
	int* get_endpoint(void){ return endpoint; }   //return a array of 2 elements which consist of 2 nodes ID
	string get_Label(void){ return Label; }       //return the name of the resistor
	double get_resistance(void){ return resistance; }
	Resistor* get_next(void){ return next; }      //return a the address which the pointer is point to right now
	void set_next(Resistor *);                  //take a address , then make the next point to it.
	void set_Label(string);
	void set_resistance(double);
	void print_resistor(void);                  //print the resistor

};

#endif	/* RESISTOR_H */