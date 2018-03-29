#include "Random.h"

#ifndef NUMBERS_H
#define NUMBERS_H

// Base class
class Number
{
protected:
	int sims; // Simulations
	const double PI = 4 * atan(1.0); // Number pi
	const double E = exp(1); // Number e
	Random *random; // Random number pointer
public:
	// Constructor
	Number();

	// Virtual destructor
	virtual ~Number();

public:
	// Compute number
	virtual double compute() const = 0;

	// Compute error
	virtual double error(const double&) const = 0;

	// Setter method
	virtual void setSims(const int& sims) = 0;
};

// Derived class 1
class Pi : public Number
{
public:
	// Constructor
	Pi(const int& sims);

	// Virtual destructor
	virtual ~Pi();

public:
	// Compute number
	virtual double compute() const;

	// Compute error
	virtual double error(const double& pi) const;

	// Setter method
	virtual void setSims(const int& sims);
};


// Derived class 2
class Exp : public Number
{
public:
	// Constructor
	Exp(const int& sims);

	// Destructor
	virtual ~Exp();

public:
	// Compute number
	virtual double compute() const;
	
	// Compute error
	virtual double error(const double& exp) const;

	// Setter method
	virtual void setSims(const int& sims);
};
#endif