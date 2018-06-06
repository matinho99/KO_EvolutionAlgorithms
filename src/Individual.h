/*
 * @class Individual
 *
 * Created on: 28.04.2018
 */

#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

/**
 * @brief Class that holds the value of an individual.
 *
 * Class that holds the value describing the individual
 * and methods for setting and returning it.
 */
class Individual {
public:
	Individual();
	Individual(float v);
	float getValue();				///< Get the value of the individual.
	void setValue(float v);			///< Set the value of the individual.
private:
	float value;
};


#endif /* INDIVIDUAL_H_ */
