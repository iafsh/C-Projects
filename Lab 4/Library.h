#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include<string>
using std::string;


class Connection {
public:
	Connection();
	double charge;
	~Connection()= default;
};



class Components {
public:
	Components(string name,Connection* const& term1, Connection* const& term2);
	Components(string name, double timeStamp, Connection* const& term1, Connection* const& term2);

	double get_voltage() const;
	string get_name() const;
	virtual double get_current()const = 0;
	virtual void update() = 0;

	virtual ~Components()= default;

protected:
	string name;
	Connection* terminal1;
	Connection* terminal2;
	double timeStamp;
};

class Circut{
public:
	Circut();
	void iterate(int iterations, int lines);
	void header();
	void add_component(Components* comp);
	~Circut()= default;
private:
	std::vector<Components*> circut;
};


class Battery : public Components {
public:
	Battery(string name,double volt, Connection* const& term1, Connection* const& term2);
	void update() override;
	double get_current()const;
	~Battery()= default;
private:
	double voltage;
};

class Resistor : public Components {
public:
	Resistor(string name, double time, double resis, Connection* const& term1, Connection* const& term2);
	void update() override;
	double get_current() const override;
	~Resistor()= default;
private:
	double resistance;
};

class Capacitor : public Components {
public:
	Capacitor(string name, double cap, double timeStamp, Connection* const& term1, Connection* const& term2);
	void update() override;
	~Capacitor()= default;
	double get_current() const override;
private:
	double current;
	double capacitance;
};

#endif