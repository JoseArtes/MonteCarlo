#include "MyLibrary.h"

#ifndef RANDOM_H
#define RANDOM_H

class Random
{
public:
	// Constructor
	Random();

	// Virtual destructor
	virtual ~Random() = 0;

public:
	// Generate numbers method
	virtual double generate() const = 0;

};

class Uniform : public Random
{
private:
	// U(a,b) parameters
	double a, b;

public:
	// Constructor
	Uniform(const double& a, const double& b);

	// Virtual destructor
	virtual ~Uniform();

public:
	// Generate numbers method
	virtual double generate() const;

	// Setter methods
	void setParam(const double& a, const double& b);
};

#endif
