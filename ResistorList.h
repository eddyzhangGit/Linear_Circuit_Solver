using namespace std;
#ifndef RESISTORLIST_H
#define RESISTORLIST_H
#include <cstdlib>
#include <iostream>
#include<sstream>
#include<iomanip>
#include<math.h>
#include"Resistor.h"
#define MIN_ITERATION_CHANGE 0.0001 

class Resistor_List{

private:
	Resistor* head;

public:
	Resistor_List(){ head = NULL; }
	~Resistor_List(){ if (head != NULL)delete head; }
	void deleteR_list(){ if (head != NULL) delete head; head = NULL; }
	void insert_R_end(string, double, int, int); //Insert a resistor at the end of the list 
	Resistor *Find_R(string);                    // Find a resistor by name, returning a pointer to it, return null if did not find
	void deleteR(Resistor *);                    // Delete a resistor given a pointer, assume the address is a valid resistor.
	void printall(void);
	int Find_number_of_resistors(void);          //return the number of resistors at this node
	double get_resistance(int);
	int get_next_Node_id_list(int, int);
        


};

#endif	/* RESISTOR_H */