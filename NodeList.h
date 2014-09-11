using namespace std;
#ifndef NODELIST_H
#define NODELIST_H
#include <cstdlib>
#include <iostream>
#include<sstream>
#include<iomanip>
#include<math.h>
#include"Resistor.h"
#include"ResistorList.h"
#include"Node.h"
class Node_List{

private:
	Node* head;

public:
	Node_List(){ head = NULL; }
	~Node_List(){ if (head != NULL)delete head; }
	bool VoltageExist(double);             //check if the voltage exist or not,return a boolen type
	void DeleteALL(void){ if (head != NULL)delete head; head = NULL; }
	Node* insertNode(int, double);          //Accept a node ID and return a pointer to the corresponding Node if it exists, or create a new one
	Node* Find_Node(int);                  //Accept a node ID and return a pointer to the corresponding Node if it exists or return NULL
	//handle the resistors
	bool Resistor_Exist_Node_List(string); //Determine if a resistor with a given label exists in any of the Nodes
	bool Change_resistor_name_Node_list(string);//change the resistor name to the given parameter, return false if the resistor does not exist in any of the node
	bool Delete_resistor_by_name_Node_list(string);//Delete a resistor by name (or return a failure indication if the resistor is not in all the nodes)
	void Insert_resistor_Node_list(string, double, int, int);//insert the resistor to the 2 nodes
	bool Modify_resistor_Node_list(string, double);   //modify the resistor in the node_list with the parameter called string.
	//return false if the resistor is not found.
	bool print_resistor_Node_list(string);           //given a string parameter as resistor label and print all the infor about it  r
	//return false if the resistor is not found.
	void print_Node(int);                            //user give a node id, it will print all resistor in this node.
	void print_ALL(void);                            //print out the the nodes
	void DeleteR(string);
	void Set_Node_voltage(int, double);
	void unset_node(int);
	void solve_Node_List(void);
	int Number_of_node(void);                       //find number of node in the list
	double get_node_voltage(int);                   //find the node votage base on the id number
	int get_node_ID(int, int);                    //part of the slove function is to get the Node id of another node on that resistor
        void deleteNode_with_0_resistor(void);
};

#endif	/* node_H */