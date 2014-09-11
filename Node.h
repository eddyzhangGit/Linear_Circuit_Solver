using namespace std;
#ifndef NODE_H
#define NODE_H
#include <cstdlib>
#include <iostream>
#include<sstream>
#include<iomanip>
#include<math.h>
#include"Resistor.h"
#include"ResistorList.h"
class Node{
private:
	double voltage;
	int Node_ID;
	Node *next;
	Resistor_List R_list;
	bool set;
        bool used_yet;
public:
	Node(){ next = NULL; voltage = -2; Node_ID = 0; set = false;}   //defualt contructor
	Node(int, double);                        //Constructor:set ID and voltage, next to NULL
	Node(int);                               //Constructor:set ID to the int input, set Votage =0; set next=NULL;
	~Node(){  delete next; }//Destructor: delete next;
	double get_voltage(void);               //return the voltage of the Node
	int get_Node_ID(void);                  //return the Node_ID
	Node* get_next(void);                   //return what is the next point to
	void set_next(Node *);                  //take an address as parameter and make the next point to the address
	void set_voltage(double);
	void set_voltage_and_set(double);
	void unset(){ set = false; }
	bool check_set(void){ return set; }
	//handle the resistors helpers
	bool Resistor_Exist_Node(string);       //Determine if a resistor with a given label exists in this Nodes
	bool Change_resistor_name_Node(string); //change the resistor name to the given parameter, return false if the resistor does not exist in this node
	bool Delete_resistor_by_name_Node(string);//Delete a resistor in this node by name (or return a failure indication if the resistor is not in this node)
	void Insert_resistor_Node(string, double, int, int);//insert a resistor to the end of the R_list
	void Modify_resistor_Node(string, double); //Modify the resistor value to the parameter double
	void print_resistor_Node_list(string);           //given a string parameter as resistor label and print the resistor in this node
	Resistor *Searching_Resistor(string);            //return a resistor pointer to the resistor name  
	void print_R_list(void);                                //print all the resistor in this node;
	int Find_number_of_resistors_node(void);           //return number of resistors in this node
	double get_resistance(int);
	int get_next_Node_id(int, int);

};

#endif	/* node_H */