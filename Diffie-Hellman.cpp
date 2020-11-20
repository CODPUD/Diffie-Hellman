#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

const int MINIMUM = 1000000;
const int MAXIMUM = 16777215; //24 bit also we can use 0xFFFFFF

//Function to check number is Prime or not.
bool cechkPrime(int n) {
	if (n <= 3) {
		return n > 1;
	}
	else if (n % 2 == 0 || n % 3 == 0) {
		return false;
	}
	else {
		int i = 5;
		while (i * i <= n) {
			if (n % i == 0 || n % (i + 2) == 0) {
				return false;
			}
			i += 6;
		}
		return true;
	}
}

//Function will generate random numbers until find prime number.
int generatePrime() {
	int temp = (rand() % (MAXIMUM - MINIMUM)) + MINIMUM;
	while (!cechkPrime(temp)) {
		temp = (rand() % (MAXIMUM - MINIMUM)) + MINIMUM;
	}
	return temp;
}

bool checkPrimeSafe(int n) {
	return cechkPrime((n - 1) / 2);
}

int SafePrime() {
	int temp = generatePrime();
	while (!checkPrimeSafe(temp)) {
		temp = generatePrime();
	}
	return temp;
}

//Function to calculate without using ** modulo power of some expression with big int.
unsigned long long int modpow(unsigned long int num, unsigned long int pow, unsigned long int mod)
{
	unsigned long long int result;
	unsigned long long int n = num;
	for (result = 1; pow; pow >>= 1)
	{
		if (pow & 1)
			result = ((result % mod) * (n % mod)) % mod;
		n = ((n % mod) * (n % mod)) % mod;
	}
	return result;
}

bool checkGenerator(int p, int g) {
	unsigned long long int result = modpow(g, (p-1)/2, p);
	if (result == 1) {
		return false;
	}
	else {
		return true;
	}
}

 int Generator(int p) {
	int g = (rand() % ((p-1) - 2)) + 2;
	while (!checkGenerator(p, g))
		g = (rand() % ((p - 1) - 2)) + 2;
	return g;
}


int main()
{
	srand(time(NULL));
	int p = SafePrime();
	int g = Generator(p);
	cout << "p = " << p << endl << "g = " << g << endl;
}