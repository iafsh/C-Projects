#include "Library.h"
#include "cmath"
#include <iostream>
#include <iomanip>
using std::fixed;
using std::setw;
using std::setprecision;
using std::string;

Connection::Connection() :charge{ 0 } {}


Circut::Circut() : circut{} {}
void Circut::iterate(int const iterations, int const lines) {

	int iterationPerLine = iterations / lines;
	int numberOfComp = circut.size();
	for (int i = 0; i < iterations; i++)
	{
		//std::cout<<"here";

		for (int j = 0; j < numberOfComp; j++)
		{
			//std::cout<<"there";
			circut[j]->update();
			if ((i % iterationPerLine == 0)) {
				std::cout << fixed << setprecision(2) << setw(5) <<
					circut[j]->get_voltage() << " " << fixed << setprecision(2) <<
					setw(5) << circut[j]->get_current() << " ";
			}
		}
		if ((i % iterationPerLine == 0)) {
			std::cout << std::endl;
		}
	}
}

void Circut::header() {

	int numberOfComp = circut.size();
	for (int j = 0; j < numberOfComp; j++)
	{
		std::cout << std::setw(10) << circut[j]->get_name();

	}
	std::cout << std::endl;
	for (int j = 0; j < numberOfComp; j++)
	{
		std::cout << std::setw(6) << "Volt" <<
			std::setw(6) << "Curr";
	}
	std::cout << std::endl;
}


void Circut::add_component(Components* const& comp) {
	circut.push_back(comp);
}




Components::Components(string const& nam, Connection* const& term1, Connection* const& term2) :
	name{ nam }, terminal1{ term1 }, terminal2{ term2 }{}
Components::Components(string const& nam, double timeStamp, Connection* const& term1, Connection* const& term2) :
	name{ nam },
	terminal1{ term1 }, terminal2{ term2 }, timeStamp{ timeStamp }{}


double Components::get_voltage() const {
	return std::abs(terminal1->charge - terminal2->charge);
}



//void Components::update(){this->update();}

string Components::get_name() const {
	return name;
}





Battery::Battery(string const& name, double const volt, Connection* const& term1, Connection* const& term2) :
	Components(name, term1, term2), voltage{ volt }{}



void Battery::update() {
	terminal1->charge = voltage;
	terminal2->charge = 0;
}

double Battery::get_current()const { return 0; }


Resistor::Resistor(string const& name, double const time, double const resis, Connection* const& term1, Connection* const& term2) :
	Components(name, time, term1, term2), resistance{ resis }{}

double Resistor::get_current() const {

	double voltage = get_voltage();
	return voltage / resistance;
}


void Resistor::update() {

	double moveCharge = (std::abs(terminal1->charge - terminal2->charge) / resistance) * timeStamp;
	//find most charged terminal
	if (terminal1->charge > terminal2->charge) {
		terminal1->charge -= moveCharge;
		terminal2->charge += moveCharge;
	}
	else {

		terminal1->charge += moveCharge;
		terminal2->charge -= moveCharge;
	}
}





Capacitor::Capacitor(string const& name, double const cap, double const timeStamp, Connection* const& term1, Connection* const& term2) :
	Components{ name,timeStamp,term1,term2 }, current{ 0 }, capacitance{ cap }{}


void Capacitor::update() {
	//find most charged terminal
	Connection* Bterm{ terminal1 };
	Connection* Sterm{ terminal2 };
	if (terminal1->charge < terminal2->charge) {
		Bterm = terminal2;
		Sterm = terminal1;
	}
	double moveCharge = ((Bterm->charge - Sterm->charge - current) * capacitance) * timeStamp;

	Bterm->charge -= moveCharge;
	Sterm->charge += moveCharge;
	current += moveCharge;
}
double Capacitor::get_current() const {
	double voltage = get_voltage();
	return capacitance * (voltage - current);
}
