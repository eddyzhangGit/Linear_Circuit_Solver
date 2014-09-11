#include"NodeList.h"
#include <cmath>


Node* Node_List::insertNode(int ID, double Vot)
{
	Node *p = head;
	Node *Prev = NULL;
	Node* Node_return = Find_Node(ID);
	if (Node_return != NULL)
	{
		//cout << "The node is already exist" << endl;
		return Node_return;;
	}
	Node *n = new Node(ID, Vot);
	//start searching
	while ((p != NULL) && (p->get_Node_ID()<ID))
	{
		Prev = p;
		p = p->get_next();
	}
	n->set_next(p);
	if (Prev == NULL)
	{
		head = n;
		return n;
	}
	else
	{
		Prev->set_next(n);
		return n;
	}

	cout << "Votage inserted " << Vot << " V" << endl;
	cout.flush();
}


bool Node_List::VoltageExist(double Vot)
{
	Node *p = head;

	while (p != NULL)
	{
		if ((p->get_voltage()) == Vot)
			return true;
		else
			p = p->get_next();
	}

	return false;

}
Node* Node_List::Find_Node(int ID)
{
	Node *p = head;

	while (p != NULL)
	{
		if ((p->get_Node_ID()) == ID)
			return p;
		else if ((p->get_Node_ID())>ID)
			return NULL;
		else
			p = p->get_next();
	}

	return NULL;

}

bool Node_List::Resistor_Exist_Node_List(string label_)
{
	Node *p = head;
	while (p != NULL)
	{
		if ((p->Resistor_Exist_Node(label_)) == true)
			return true;
		p = p->get_next();

	}
}
bool Node_List::Change_resistor_name_Node_list(string label_)
{
	Node *p = head;
	while (p != NULL)
	{
		if (p->Change_resistor_name_Node(label_) == true)
			return true;
		else
			p = p->get_next();
	}
	return false;
}
bool Node_List::Modify_resistor_Node_list(string label_, double new_resistance)
{
	bool found = false;
	Node *p = head;
	bool printed = false;
	while (p != NULL)
	{
		if (p->Resistor_Exist_Node(label_) == true)
		{
			Resistor *Rp = p->Searching_Resistor(label_);
			if (!printed)
			{
				cout << "Modified: resistor " << label_ << " from " << Rp->get_resistance() << " Ohms to " << new_resistance <<" Ohms"<< endl;
				cout.flush();
				printed = true;
			}
			p->Modify_resistor_Node(label_, new_resistance);
			found = true;
		}
		p = p->get_next();
	}
	if (!found)
	{
		cout << "Error: resistor " << label_ << " not found" << endl;
		cout.flush();
	}
	return found;


}
bool Node_List::Delete_resistor_by_name_Node_list(string label_)
{
	bool found = false;
	Node *p = head;
	bool printed = false;
	while (p != NULL)
	{
		if (p->Delete_resistor_by_name_Node(label_) == true)
		{
			found = true;
			if (!printed)
			{
				cout << "Deleted: resistor " << label_ << endl;
				cout.flush();
				printed = true;
			}
		}
		p = p->get_next();
	}
	if (!found)
	{
		cout << "Error: resistor " << label_ << " not found" << endl;
		cout.flush();
	}
	return found;
}
void Node_List::Insert_resistor_Node_list(string label_, double new_resistance_, int node0, int node1)
{
	Node*p = insertNode(node0, 0);
	p->Insert_resistor_Node(label_, new_resistance_, node0, node1);
	p = insertNode(node1, 0);
	p->Insert_resistor_Node(label_, new_resistance_, node0, node1);
	cout << "Inserted: resistor " << label_ << " " << new_resistance_ << " Ohms " << node0 << " -> " << node1 << endl;
	cout.flush();
}
bool Node_List::print_resistor_Node_list(string label_)
{
	bool found = false;
	Node *p = head;
	Resistor *R;
	while (p != NULL)
	{
		R = p->Searching_Resistor(label_);
		if (R != NULL)
		{
			cout << "Print:" << endl;
			cout.flush();
			R->print_resistor();
			found = true;
			break;
		}
		p = p->get_next();
	}
	if (!found)
	{
		cout << "Error: resistor " << label_ << " not found" << endl;
		cout.flush();
	}
	return found;

}

void Node_List::print_Node(int Node_ID_)
{

	Node* p = Find_Node(Node_ID_);
	cout << "Print:" << endl;
	if (p != NULL)
		p->print_R_list();

}
void Node_List::print_ALL(void)
{
	cout << "Print:" << endl;
	cout.flush();
	Node*p = head;
	while (p != NULL)
	{
            if(p->Find_number_of_resistors_node()>0)
            {
		p->print_R_list();
		
            }
            p = p->get_next();
	}


}

void Node_List::Set_Node_voltage(int Node_ID_, double voltage_)
{
	Node *p = Find_Node(Node_ID_);
        if(p==NULL)
        {
          p= insertNode(Node_ID_, voltage_); 
        }
	p->set_voltage_and_set(voltage_);
	cout << "Set: node " << Node_ID_ << " to " << voltage_ << " Volts" << endl;
	cout.flush();
}
void Node_List::unset_node(int Node_ID_)
{
	Node *p = Find_Node(Node_ID_);
        if(p==NULL)
        {
            p= insertNode(Node_ID_, 0); 
            
        }
	if (p != NULL)
	{
		p->unset();
		p->set_voltage(0);
	}

	cout << "Unset: the solver will determine the voltage of node " << Node_ID_ << endl;
	cout.flush();
}
int Node_List::Number_of_node(void)
{
	int count = 0;
	Node *p = head;
	while (p != NULL)
	{
		count++;
		p = p->get_next();
	}
	return count;
}
double Node_List::get_node_voltage(int Node_ID_)
{
	Node *p = Find_Node(Node_ID_);
	return p->get_voltage();
}
int Node_List::get_node_ID(int i, int current_node_id)
{
	Node *p = Find_Node(current_node_id);
	return p->get_next_Node_id(i, current_node_id);
}
void Node_List::solve_Node_List(void)
{   //MIN_ITERATION_CHANGE
	Node *pp = head;
	bool Node_set = false;
	while (pp != NULL)
	{
		if (pp->check_set())
			Node_set = true;
		pp = pp->get_next();
	}
	if (Node_set == false)
	{
		cout << "Error: no nodes have their voltage set" << endl;
		cout.flush();
		return;
	}
	Node  *p1 = head;
	int k;
	double MAX_ITERATION_CHANGE = 0;
	double first_term = 0;
	double second_term = 0;
	double new_voltage = 0;
	double diff;
	int count = 0;
	bool first_in = true;
	while (MIN_ITERATION_CHANGE<MAX_ITERATION_CHANGE|| first_in)     
	{
		Node *p = head;
		//cout<<" iam here"<<endl;
		//cout.flush();
		count++;
		first_in = false;
		double max_time_turn = 0;
		for (k = 0; k<(Number_of_node()); k++)
		{

			if (!p->check_set())
			{
				//cout<<"i am here??"<< k<<"number of node is"<<Number_of_node()<< endl;
				// cout.flush();
				int i;
				for (i = 0; i<(p->Find_number_of_resistors_node()); i++)
				{
					// cout<<"i am here??"<< i<<"number of node is"<<p->Find_number_of_resistors_node()<< endl;
					first_term = first_term + 1 / (p->get_resistance(i));
					// cout<<"(p->get_resistance(i) is "<<p->get_resistance(i)<<endl;
					second_term = second_term + get_node_voltage(get_node_ID(i, p->get_Node_ID())) / (p->get_resistance(i));
					// cout<<"get_node_voltage(get_node_ID(i,p->get_Node_ID())) is "<<get_node_voltage(get_node_ID(i,p->get_Node_ID()))<<endl;
					cout.flush();
				}
				new_voltage = (1 / first_term)*second_term;
				//cout << "new_voltageis " << new_voltage << endl;
				//cout.flush();

				diff = new_voltage - p->get_voltage();
				if (abs(diff) > max_time_turn)
				{
					max_time_turn=abs(diff);
				}


				p->set_voltage(new_voltage);
				// cout<<"diff is"<<diff<<endl;
				// cout.flush();set
				first_term = 0;
				second_term = 0;

				//  cout<<"MAX_ITERATION_CHANGE is "<<MAX_ITERATION_CHANGE<<endl;
			}
			p = p->get_next();
		}
		MAX_ITERATION_CHANGE = max_time_turn;

	}
	cout << "Solve:" << endl;
	cout.flush();
	for (k = 0; k<Number_of_node(); k++)
	{
		cout << "  Node " << p1->get_Node_ID() << ": " << round(p1->get_voltage() * 100) / 100 << " V" << endl;
		cout.flush();
		if (!p1->check_set())
			p1->set_voltage(0);

		p1 = p1->get_next();
	}

}
void Node_List::deleteNode_with_0_resistor(void)
{
    Node *p=head;
    Node *Prev=NULL;
    if(p->Find_number_of_resistors_node()==0)
    {
        head=head->get_next();
        p->set_next(NULL);
        delete p;
    }
    while(p!=NULL)
    {
        if(p->Find_number_of_resistors_node()==0)
        {
            Prev->set_next(p->get_next());
            p->set_next(NULL);
            delete p;
        }
        Prev=p;
        p=p->get_next();
    }
}