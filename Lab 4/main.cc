#include <iostream>
#include <string>
#include "Library.cc"
using namespace std;

void Circut1(int const iterations, int const lines, double const time, double const voltage=24) {
	Connection P{};
	Connection N{};
	Connection R124{};
	Connection R23{};
	Circut circ1{};

	
	Battery Bat{"Bat",voltage,&P,&N};
	Resistor R1{"R1",time,6,&P,&R124};
	Resistor R2{ "R2",time,4,&R124,&R23 };
	Resistor R3{ "R3",time,8,&R23,&N };
	Resistor R4{ "R4",time,12,&R124,&N };
	circ1.add_component(&Bat);
	circ1.add_component(&R1);
	circ1.add_component(&R2);
	circ1.add_component(&R3);
	circ1.add_component(&R4);
	circ1.header();
	circ1.iterate(iterations, lines);

}
void Circut2(int const iterations, int const lines, double const time, double const voltage) {
	Connection P{};
	Connection N{};
	Connection L{};
	Connection R{};
	Circut circ1{};

	Battery Bat{"Bat",voltage,&P,&N};
	Resistor R1{"R1",time,150,&P,&L};
	Resistor R2{ "R2",time,50,&P,&R };
	Resistor R3{ "R3",time,100,&R,&L };
	Resistor R4{ "R4",time,300,&L,&N };
	Resistor R5{ "R5",time,250,&R,&N };

	circ1.add_component(&Bat);
	circ1.add_component(&R1);
	circ1.add_component(&R2);
	circ1.add_component(&R3);
	circ1.add_component(&R4);
	circ1.add_component(&R5);

	circ1.header();
	circ1.iterate(iterations, lines);

}

void Circut3(int const iterations, int const lines, double const time, double const voltage) {
	Connection P{};
	Connection N{};
	Connection L{};
	Connection R{};
	Circut circ1{};

	Battery Bat{"Bat",voltage,&P,&N};
	Resistor R1{"R1",time,150,&P,&L};
	Resistor R2{ "R2",time,50,&P,&R };
	Capacitor C3{"C3",time,1.0,&L,&R};
	Resistor R4{ "R4",time,300,&L,&N };
	Capacitor C5{"C5",time,0.75,&N,&R};


	circ1.add_component(&Bat);
	circ1.add_component(&R1);
	circ1.add_component(&R2);
	circ1.add_component(&C3);
	circ1.add_component(&R4);
	circ1.add_component(&C5);
	circ1.header();
	circ1.iterate(iterations, lines);

}





int main(int argc, char* argv[])
{
	try {
		if (argc != 5) {
			cout << "Error: Wrong number of arguments. You must enter 5" << endl;
			return -1;
		}
		if (!((stoi(argv[1]) >= 0) & (stoi(argv[2]) >= 0) & (stod(argv[3]) > 0) & (stod(argv[4]) > 0))) {
			cout << "Error: All numbers should be non negative" << endl;
			return -1;
		}

		Circut1(stoi(argv[1]), stoi(argv[2]), stod(argv[3]), stod(argv[4]));
		Circut2(stoi(argv[1]), stoi(argv[2]), stod(argv[3]), stod(argv[4]));
		Circut3(stoi(argv[1]), stoi(argv[2]), stod(argv[3]), stod(argv[4]));
		return 0;
	}
	catch (const std::out_of_range& e) {
		cout << "Error: Numbers are too big! Make a smaller model!" << endl;
	}

}

