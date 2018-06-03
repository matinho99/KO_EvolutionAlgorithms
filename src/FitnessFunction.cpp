#include "FitnessFunction.h"

FitnessFunction::FitnessFunction() : target(0.0f) {}

FitnessFunction::FitnessFunction(std::vector<float> numFact, std::vector<float> denomFact, float t) : numeratorFactors(numFact), denominatorFactors(denomFact), target(t) {}

std::vector<float> FitnessFunction::getNumeratorFactors() {
	return numeratorFactors;
}

std::vector<float> FitnessFunction::getDenominatorFactors() {
	return denominatorFactors;
}

float FitnessFunction::getTarget() {
	return target;
}

void FitnessFunction::setNumeratorFactors(std::vector<float> numFact) {
	numeratorFactors = numFact;
}

void FitnessFunction::setDenominatorFactors(std::vector<float> denomFact) {
	denominatorFactors = denomFact;
}

void FitnessFunction::setTarget(float t) {
	target = t;
}

float FitnessFunction::calculateFunctionValue(float x) {
	float numeratorValue = 0.0f;
	float denominatorValue = 0.0f;
	float result = 0.0f;

	for(int i = 0; i < numeratorFactors.size(); i++) {
		numeratorValue += numeratorFactors[i]*pow(x, i);
	}

	for(int i = 0; i < denominatorFactors.size(); i++) {
		denominatorValue += denominatorFactors[i]*pow(x, i);
	}

	if(denominatorValue != 0.0f) {
		result = numeratorValue/denominatorValue;
	}

	return result;
}

float FitnessFunction::calculateFitness(float x) {	
	float result = calculateFunctionValue(x);
	return (result - target == 0) ? 1/1000.0f : 1.0f/(fabs(result - target));
}




