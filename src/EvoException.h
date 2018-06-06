/*
 * @class EvoZeroDivisionException
 * @class EvoNullPointerException
 * @class UIInputException
 *
 * Created on: 4.06.2018
 */

#ifndef EVOEXCEPTION_H_
#define EVOEXCEPTION_H_

#include <exception>

/**
 * @brief Exception for dividing by zero.
 */
class EvoZeroDivisionException : public std::exception {
public:
	const char* what() const throw() { return "Dzielenie przez zero niedozwolone"; };
};

/**
 * @brief Exception for calling a null pointer.
 */
class EvoNullPointerException : public std::exception {
public:
	const char* what() const throw() { return "Odwolanie do pustego wskaznika"; };
};

/**
 * @brief Exception for giving a wrong value.
 */
class UIInputException : public std::exception {
public:
	const char* what() const throw() { return "Podano niewlasciwa wartosc na wejscie"; };
};

#endif /* EVOEXCEPTION_H_ */
