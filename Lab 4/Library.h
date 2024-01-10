#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include<string>


class Connection {
public:
	Connection();
	double charge;
	~Connection() = default;
};



class Components {
public:
	Components(std::string const& name, Connection* const& term1, Connection* const& term2);
	Components(std::string const& name, double const timeStamp, Connection* const& term1, Connection* const& term2);

	double get_voltage() const;
	std::string get_name() const;
	virtual double get_current()const = 0;
	virtual void update() = 0;

	virtual ~Components() = default;

protected:
	std::string name;
	Connection* terminal1;
	Connection* terminal2;
	double timeStamp;
};

class Circut {
public:
	Circut();
	void iterate(int const iterations, int const lines);
	void header();
	void add_component(Components* const& comp);
	~Circut() = default;
private:
	std::vector<Components*> circut;
};


class Battery : public Components {
public:
	Battery(std::string const& name, double const volt, Connection* const& term1, Connection* const& term2);
	void update() override;
	double get_current()const;
private:
	double voltage;
};

class Resistor : public Components {
public:
	Resistor(std::string const& name, double const time, double const resis, Connection* const& term1, Connection* const& term2);
	void update() override;
	double get_current() const override;
private:
	double resistance;
};

class Capacitor : public Components {
public:
	Capacitor(std::string const& name, double const cap, double const timeStamp, Connection* const& term1, Connection* const& term2);
	void update() override;
	double get_current() const override;
private:
	double current;
	double capacitance;
};

#endif