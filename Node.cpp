#include"Node.h"


double Node::get_voltage()
{
	return voltage;
}

int Node::get_Node_ID()
{
	return Node_ID;
}

Node* Find_Node(int);

Node* Node::get_next()
{
	return next;
}
void Node::set_next(Node *next_to)
{
	next = next_to;
}
Node::Node(int Node_ID_, double vol)
{
	//cout << "Node " << Node_ID_ << "CREATED" << endl;
	//cout.flush();
	voltage = vol;
	Node_ID = Node_ID_;
	next = NULL;
	set = false;
}
Node::Node(int Node_ID_)
{
	voltage = 0;
	Node_ID = Node_ID_;
	next = NULL;
	set = false;
}
bool Node::Resistor_Exist_Node(string label_)
{
	if (R_list.Find_R(label_) == NULL)
		return false;
	else
		return true;
}
bool Node::Change_resistor_name_Node(string label_)
{
	Resistor *p = R_list.Find_R(label_);
	if (p == NULL)
		return false;
	else
	{
		p->set_Label(label_);

		return true;
	}
}
bool Node::Delete_resistor_by_name_Node(string label_)
{
	Resistor *p = R_list.Find_R(label_);
	if (p == NULL)
		return false;
	else
	{
		R_list.deleteR(p);
		return true;
	}
}
void Node::Modify_resistor_Node(string label_, double new_resistance)
{
	Resistor *p = R_list.Find_R(label_);
	double temp = p->get_resistance();
	p->set_resistance(new_resistance);
	//cout << "Mofified " << label_ << " from " << temp << " to " << p->get_resistance() << endl;
	//cout.flush();

}
void Node::Insert_resistor_Node(string label_, double new_resistance_, int node0, int node1)
{
	R_list.insert_R_end(label_, new_resistance_, node0, node1);
}

Resistor *Node::Searching_Resistor(string label_)
{
	return R_list.Find_R(label_);
}
void Node::print_R_list(void)
{
	cout << "Connections at node " << Node_ID << ": " << R_list.Find_number_of_resistors() << " resistor(s)" << endl;
	cout.flush();
	R_list.printall();
}
int Node::Find_number_of_resistors_node(void)
{
	return R_list.Find_number_of_resistors();
}
void Node::set_voltage(double voltage_)
{
	voltage = voltage_;
}
void Node::set_voltage_and_set(double voltage_)
{
	voltage = voltage_;
	set = true;
}
double Node::get_resistance(int i)
{
	return R_list.get_resistance(i);
}
int Node::get_next_Node_id(int i, int current_Node_ID)
{
	return R_list.get_next_Node_id_list(i, current_Node_ID);
}