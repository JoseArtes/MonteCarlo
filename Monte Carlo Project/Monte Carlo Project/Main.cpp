#include "Numbers.h"

int main()
{
	srand(unsigned(time(NULL)));

	int sims;

	cout << "How many simulations do you wish to perform?: " << endl;
	cin >> sims;

	cout << endl;

	Number *number1 = new Pi(sims);
	double pi_estimate = number1->compute();

	cout << "Your pi estimate is: " << pi_estimate  << endl;
	cout << "The error is: " << number1->error(pi_estimate) << endl;

	Number *number2 = new Exp(sims);
	double e_estimate = number2->compute();

	cout << endl;

	cout << "Your e estimate is: " << e_estimate << endl;
	cout << "The error is: " << number2->error(e_estimate) << endl;



	delete number1, number2;
	
	system("pause");
	return 0;
}