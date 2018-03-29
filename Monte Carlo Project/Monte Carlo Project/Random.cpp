#include "Random.h"

// Base class: Random

// Constructor
Random::Random() {}

// Destructor
Random::~Random() {}


// Derived class 1: Uniform

// Constructor
Uniform::Uniform(const double& a, const double& b)
{
	this->a = a;
	this->b = b;
}

// Destructor

Uniform::~Uniform() {}

// Setter method
void Uniform::setParam(const double& a, const double& b)
{
	this->a = a;
	this->b = b;
}

// Generate number method
double Uniform::generate() const
{
	return ((b - a)*(static_cast<double>(rand()) / RAND_MAX)) + a;
}