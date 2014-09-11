

#include"Rparser.h"
using namespace std;

		/*
		*
		*/
string Phaser(void) {

	string line, command;
	cout << "> ";
	cout.flush();
	int k = 0;
	cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	cout.precision(2);
	getline(cin, line); // Get a line from standard input
	while (!cin.eof())
	{
		// Put the line in a stringstream for parsing
		// Making a new stringstream for each line so flags etc. are in a known state
		if (k == 0)
		{
			k = 1;
		}
		else
		{
			cout << "> ";
			cout.flush();
			getline(cin, line);


		}
		stringstream lineStream(line);
		stringstream whatever;

		if (cin.eof())
		{
			//cin.clear();
			//  cin.ignore(1000,'\n');
			return "0";

		}

		lineStream >> command;
		if (lineStream.fail())
		{
			// cin.clear();
			//  cin.ignore(1000,'\n');
			continue;

		}
				else if (command == "insertR") {
					string Resistor_Name;
					lineStream >> Resistor_Name;
					if (lineStream.fail())
					{
						cout << "Error: too few arguments" << endl;
						cout.flush();
						continue;
					}

					double Resistor_Value;

					lineStream >> Resistor_Value;
					if (lineStream.fail())
					{
						if (lineStream.eof())
						{
							if (Resistor_Name == "all")
							{


								cout << "Error: resistor name cannot be the keyword \"all\" " << endl;
								cout.flush();
								continue;

							}
							cout << "Error: too few arguments" << endl;
							cout.flush();
							continue;
						}
						else
						{

							cout << "Error: invalid argument" << endl;
							cout.flush();
							continue;
						}


					}

					if (lineStream.peek() != ' ')
					{
						if (!lineStream.eof())
						{


							cout << "Error: invalid argument" << endl;
							cout.flush();
							continue;
						}
					}

					if (Resistor_Value < 0)
					{
						cout << "Error: negative resistance" << endl;
						cout.flush();
						continue;
					}
					int Node1;

					lineStream >> Node1;
					if (lineStream.fail())
					{
						if (lineStream.eof())
						{
							if (Resistor_Name == "all")
							{


								cout << "Error: resistor name cannot be the keyword \"all\" " << endl;
								cout.flush();
								continue;

							}
							cout << "Error: too few arguments" << endl;
							cout.flush();
							continue;
						}
						else
						{

							cout << "Error: invalid argument" << endl;
							cout.flush();
							continue;
						}


					}
					if (lineStream.peek() != ' ')
					{
						if (!lineStream.eof())
						{


							cout << "Error: invalid argument" << endl;
							cout.flush();
							continue;
						}
					}


					int Node2;
					lineStream >> Node2;
					if (lineStream.fail())
					{
						if (lineStream.eof())
						{
							cout << "Error: too few arguments" << endl;
							cout.flush();
							continue;
						}
						else
						{

							cout << "Error: invalid argument" << endl;
							cout.flush();
							continue;
						}


					}
					if (lineStream.peek() != ' ')
					{
						if (!lineStream.eof())
						{


							cout << "Error: invalid argument" << endl;
							cout.flush();
							continue;
						}
					}

					if (Resistor_Name == "all")
					{


						cout << "Error: resistor name cannot be the keyword \"all\" " << endl;
						cout.flush();
						continue;

					}

					if (Node1 == Node2)
					{
						cout << "Error: both terminals of resistor connect to node " << Node1 << endl;
						cout.flush();
						continue;
					}
					string garbage;
					lineStream >> garbage;
					if (!lineStream.fail())
					{
						cout << "Error: too many arguments" << endl;
						cout.flush();
						continue;
					}
					// cout << "Inserted: resistor "<< Resistor_Name <<" "<< Resistor_Value <<" Ohms " <<Node1 << " -> "<<Node2 <<endl ;
					// cout.flush();

					return line;
				}
				else if (command == "modifyR")
				{
					string Resistor_Name;
					lineStream >> Resistor_Name;
					if (lineStream.fail())
					{
						cout << "Error: too few arguments" << endl;
						cout.flush();
						continue;
					}

					double Resistor_Value;

					lineStream >> Resistor_Value;
					if (lineStream.fail())
					{
						if (lineStream.eof())
						{
							if (Resistor_Name == "all")
							{


								cout << "Error: resistor name cannot be the keyword \"all\" " << endl;
								cout.flush();
								continue;

							}

							cout << "Error: too few arguments" << endl;
							cout.flush();
							continue;
						}
						else
						{

							cout << "Error: invalid argument" << endl;
							cout.flush();
							continue;
						}


					}
					if (lineStream.peek() != ' ')
					{
						if (!lineStream.eof())
						{


							cout << "Error: invalid argument" << endl;
							cout.flush();
							continue;
						}
					}
					if (Resistor_Value < 0)
					{

						cout << "Error: negative resistance" << endl;
						cout.flush();
						continue;
					}
					if (Resistor_Name == "all")
					{


						cout << "Error: resistor name cannot be the keyword \"all\" " << endl;
						cout.flush();
						continue;

					}
					string garbage;
					lineStream >> garbage;
					if (!lineStream.fail())
					{
						cout << "Error: too many arguments" << endl;
						cout.flush();
						continue;
					}
					//cout << "Modified: resistor "<< Resistor_Name <<" to "<< Resistor_Value <<" Ohms " <<endl ;
					//cout.flush();
					return line;

				}
				else if (command == "printR")
				{

					string Resistor_Name;
					lineStream >> Resistor_Name;
					if (lineStream.fail())
					{
						cout << "Error: too few arguments" << endl;
						cout.flush();
						continue;
					}
					string garbage;
					lineStream >> garbage;
					if (!lineStream.fail())
					{
						cout << "Error: too many arguments" << endl;
						cout.flush();
						continue;
					}

					if (Resistor_Name == "all")
					{
						//cout << "Print: all resistors"<<endl;
						//cout.flush();
						//continue;
						return line;
					}
					else
					{
						//cout << "Print: resistor "<<Resistor_Name<<endl;
						//cout.flush();
						//continue;
						return line;
					}
					//cout << "Print: resistor"<< Resistor_Name <<endl ;
					// cout.flush();
					return line;
				}
				else if (command == "printNode")
				{
					string cmd_gar;

					whatever << line;
					whatever >> cmd_gar;

					string Is_all_string;
					whatever >> Is_all_string;

					if (whatever.fail())
					{
						cout << "Error: too few arguments" << endl;
						cout.flush();
						continue;
					}


					if (Is_all_string == "all")
					{
						string garbage;
						whatever >> garbage;
						if (!whatever.fail())
						{
							cout << "Error: too many arguments" << endl;
							cout.flush();
							continue;
						}
						//cout << "Print: all nodes"<<endl;
						// cout.flush();
						// continue;
						return line;
					}

					else
					{
						int print_node;
						lineStream >> print_node;
						if (lineStream.fail())
						{
							if (lineStream.eof())
							{
								cout << "Error: too few arguments" << endl;
								cout.flush();
								continue;
							}
							else
							{

								cout << "Error: invalid argument" << endl;
								cout.flush();
								continue;
							}


						}
						if (lineStream.peek() != ' ')
						{
							if (!lineStream.eof())
							{


								cout << "Error: invalid argument " << endl;
								cout.flush();
								continue;
							}
						}


						string garbage;
						lineStream >> garbage;
						if (!lineStream.fail())
						{
							cout << "Error: too many arguments " << endl;
							cout.flush();
							continue;
						}
						return line;
						//  cout <<"Print: node "<< print_node<< endl;
						// cout.flush();
						// continue;
					}
				}
				else if (command == "solve"){
					return line;
				}
				else if (command == "setV")
				{
					return line;
				}
				else if (command == "unsetV"){
					return line;
				}

				else if (command == "deleteR")
				{

					string Resistor_Name;
					lineStream >> Resistor_Name;
					if (lineStream.fail())
					{
						cout << "Error: too few arguments" << endl;
						cout.flush();
						continue;
					}
					string garbage;
					lineStream >> garbage;
					if (!lineStream.fail())
					{
						cout << "Error: too many arguments" << endl;
						cout.flush();
						continue;
					}

					if (Resistor_Name == "all")
					{
						// cout << "Deleted: all resistors"<<endl;
						// cout.flush();
						// continue;
						return line;
					}
					else
					{
						//cout << "Deleted: resistor "<<Resistor_Name<<endl;
						// cout.flush();
						// continue;
						return line;
					}


				}
				else{

					cout << "Error: invalid command" << endl;
					cout.flush();
					continue;


				}


			} // End input loop until EOF.
			return "0";
		}
