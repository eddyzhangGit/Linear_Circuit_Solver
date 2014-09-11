#include"Resistor.h"


Resistor::Resistor(string Label_, double resistance_, int endpoint0_, int endpoint1_)
{
	Label = Label_;
	endpoint[0] = endpoint0_;
	endpoint[1] = endpoint1_;
	resistance = resistance_;
	next = NULL;
}
void Resistor::set_next(Resistor *next_)
{
	next = next_;
}
void Resistor::set_Label(string label_)
{
	Label = label_;
	cout << "new label is" << Label << endl;
	cout.flush();
}
void Resistor::set_resistance(double new_resistance)
{
	resistance = new_resistance;
}
void Resistor::print_resistor(void)
{
	cout << setw(20) << left << Label;
	cout << setprecision(2) << fixed << setw(8) << right << resistance << " Ohms " << endpoint[0] << " -> " << endpoint[1] << endl;
	cout.flush();
	
}

