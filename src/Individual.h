/*
 * \class Individual
 *
 * \brief Class that holds the value of an individual.
 *
 * Class that holds the value describing the individual
 * and methods for setting and returning it.
 *
 * Created on: 28.04.2018
 */

#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_


class Individual {
public:
	Individual();
	Individual(float v);
	float getValue();
	void setValue(float v);
private:
	float value;			///< The value describing the individual.
};


#endif /* INDIVIDUAL_H_ */
