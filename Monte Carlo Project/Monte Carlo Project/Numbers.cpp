#include "Numbers.h"

///*Base class*///

// Constructor
Number::Number(){}

// Destructor
Number::~Number(){}


///*Derived class 1: Pi*///

// Constructor
Pi::Pi(const int& sims)
{
	this->sims = sims; // Initialise simulation variable
	random = new Uniform(-1, 1); // Initialise constructor such that we have a U(-1,1) object
}

// Destructor
Pi::~Pi()
{
	delete random; // We free up the allocated heap memory
}

// Compute
double Pi::compute() const
{
	int sums_dummy = 0; // Summing dummy variable
	double x, y; 
	double z;

	for (int i = 0; i < sims; i++)
	{
		x = random->generate(); // U(-1,1) random variate 1
		y = random->generate(); // U(-1,1) random variate 2
		z = x * x + y * y; // Radius
		if (z <= 1)
			sums_dummy += 1;
	}

	return (static_cast<double>(sums_dummy) / sims) * 4;
}

// Error
double Pi::error(const double& pi) const
{
	double piEstimate = fabs(pi - PI); // Absolute error
	return piEstimate;
}

// Setter method
void Pi::setSims(const int& sims)
{
	this->sims = sims; // Re-initialise the simulation variable
}


///*Derived class 2: Exp*///

// Constructor
Exp::Exp(const int& sims)
{
	this->sims = sims; // Initialise simulation variable
	random = new Uniform(0, 1); // Initialise constructor such that we have a U(0,1) object
}

// Destructor
Exp::~Exp()
{
	delete random;
}

// Compute
double Exp::compute() const
{
	double uni_number; // U(0,1) random variate
	int trial_sums = 0; // Trials sum dummy variable

	for (int i = 0; i < sims; i++)
	{
		double double_sums = 0; // Sum dummy variable for doubles
		int draw_sums = 0; // Sum dummy variable for number of draws of U(0,1) random variates
		do
		{
			uni_number = random->generate(); // U(0,1) random variate
			double_sums += uni_number;
			draw_sums += 1;
		} while (double_sums <= 1);
			trial_sums += draw_sums;
	}

	return static_cast<double>(trial_sums)/ sims;
}

// Error
double Exp::error(const double& exp) const
{
	double expEstimate = fabs(exp - E); // Absolute error
	return expEstimate;
}

// Setter method
void Exp::setSims(const int& sims)
{
	this->sims = sims; // Re-initialise the simulation variable
}