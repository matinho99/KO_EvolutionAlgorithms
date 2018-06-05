#ifndef EVOEXCEPTION_H_
#define EVOEXCEPTION_H_

#include <exception>

class EvoZeroDivisionException : public std::exception {
public:
	const char* what() const throw() { return "Dzielenie przez zero niedozwolone"; };
};

class EvoNullPointerException : public std::exception {
public:
	const char* what() const throw() { return "Odwolanie do pustego wskaznika"; };
};

#endif /* EVOEXCEPTION_H_ */