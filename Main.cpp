/*
* File:   main.cpp
* Author: zhangz64
*
* Created on October 28, 2013, 7:55 PM
*/
#include"Resistor.h"
#include"ResistorList.h"
#include"Node.h"
#include"NodeList.h"
#include"Rparser.h"
using namespace std;

int main(int argc, char** argv) {
	cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	cout.precision(2);
	Node_List mylist;
	//ifstream input_commands;
	//input_commands.open("input.txt");
	//if (input_commands.fail())
	//{
	//	cout << "cant open file" << endl;
	//	cout.flush();
	//}
	while (1)
	{
		string line = Phaser();
		//..string line;
		//getline(input_commands, line);
		if (line=="0")
		{
			mylist.DeleteALL();
			int a;
			cin >> a;
			return 0;
		}
		//if (line == EOF)
	//	{
			// cout<< " iam at main"<<endl;
		//	mylist.DeleteALL();
		//	return 0;
		//}
		stringstream lineStream(line);
		stringstream whatever(line);
		string command;
		lineStream >> command;
		if (lineStream.fail())
		{
			//cin.clear();
			//  cin.ignore(1000,'\n');
			continue;

		}
		else if (command == "insertR"){
			string label;
			double resistance;
			int node0, node1;
			lineStream >> label >> resistance >> node0 >> node1;
			DBentry *DBP = new DBentry("h", 2234, false);
			myDB.insert(DBP);
			mylist.Insert_resistor_Node_list(label, resistance, node0, node1);
			continue;
		}

		else if (command == "modifyR"){
			string label;
			double new_resistance;
			lineStream >> label >> new_resistance;
			mylist.Modify_resistor_Node_list(label, new_resistance);
			continue;

		}
		else if (command == "printR"){

			string label;
			lineStream >> label;
			mylist.print_resistor_Node_list(label);
			continue;
		}
		else if (command == "printNode"){
			int node_ID;
			string garbage, all;
			lineStream >> node_ID;
			whatever >> garbage >> all;
			if (all == "all")
				mylist.print_ALL();
			else
                mylist.print_Node(node_ID);

			continue;

		}
		else if (command == "deleteR"){
			string command_delete;
			lineStream >> command_delete;
			if (command_delete == "all")
                        {
				mylist.DeleteALL();
                                cout<<"Deleted: all resistors"<<endl;
                                cout.flush();
                                
                        }
			else
                        {
				mylist.Delete_resistor_by_name_Node_list(command_delete);
                              //  mylist.deleteNode_with_0_resistor();
                        }
			continue;

		}
		else if (command == "unsetV"){
			int node_ID;
			lineStream >> node_ID;
			mylist.unset_node(node_ID);
			continue;

		}
		else if (command == "setV"){
			int node_ID;
			double voltage;
			lineStream >> node_ID >> voltage;
                         
			mylist.Set_Node_voltage(node_ID, voltage);
			continue;

		}
		else if (command == "solve"){
			mylist.solve_Node_List();
			continue;
		}
		else{
            cout << "Error: invalid command" << endl;
			cout.flush();
			continue;
		}


	}
	 //mylist.DeleteALL();

	return 0;
}
