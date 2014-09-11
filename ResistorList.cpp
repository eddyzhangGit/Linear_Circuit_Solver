#include"ResistorList.h"


void Resistor_List::insert_R_end(string label, double new_resistance_, int endpoint0, int endpoint1)
{
	Resistor *p = head;
	Resistor *prev = NULL;
	Resistor *new_R = new Resistor(label, new_resistance_, endpoint0, endpoint1);
	while (p != NULL)
	{
		prev = p;
		p = p->get_next();

	}
	//cout << "the resistor" << label << " has been inserted" << "at" << endpoint0 << "end" << endpoint1 << endl;
	//cout.flush();
	new_R->set_next(p);
	if (prev == NULL)
		head = new_R;
	else
		prev->set_next(new_R);

}
Resistor *Resistor_List::Find_R(string label_)
{
	Resistor *p = head;
	while (p != NULL)
	{
		if (p->get_Label() == label_)
		{
			return p;
		}
		p = p->get_next();
	}
	return NULL;

}
void Resistor_List::deleteR(Resistor *target)
{
	Resistor *p = head;
	Resistor *prev = NULL;
	string Label__ = target->get_Label();
	//cout << Label__ << endl;

	while (p != NULL)
	{
		if ((p->get_Label()) == (Label__))
		{
			if (prev == NULL)
			{
				if (p->get_next() == NULL)
				{
					head = NULL;
					p->set_next(NULL);
					delete p;
					return;
				}
				head = p->get_next();
				p->set_next(NULL);
				delete p;
				return;

			}
			prev->set_next(p->get_next());
			p->set_next(NULL);
			delete p;
			return;
		}
		prev = p;
		p = p->get_next();
	}

}

void Resistor_List::printall(void)
{
	Resistor *p = head;
	while (p != NULL)
	{
		p->print_resistor();
		p = p->get_next();
	}

}
int Resistor_List::Find_number_of_resistors(void)
{
	Resistor *p = head;
	int number_of_resistor = 0;
	while (p != NULL)
	{
		number_of_resistor++;
		p = p->get_next();
	}
	return number_of_resistor;

}
double Resistor_List::get_resistance(int i)
{
	Resistor *p = head;
	int k = 0;
	for (k = 0; k<i; k++)
		p = p->get_next();
	return p->get_resistance();
}
int Resistor_List::get_next_Node_id_list(int i, int current_Node_ID)
{
	int k = 0;
	Resistor *p = head;
	for (k = 0; k<i; k++)
	{
		p = p->get_next();
	}
	int *endpoints_ = p->get_endpoint();
	if (endpoints_[0] != current_Node_ID)
		return endpoints_[0];
	else
		return endpoints_[1];

}