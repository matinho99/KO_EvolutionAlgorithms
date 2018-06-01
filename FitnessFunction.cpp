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

float FitnessFunction::calculateValue(float x) {
	float numeratorValue = 0;
	float denominatorValue = 0;
	float result;

	for(int i = 0; i < numeratorFactors.size(); i++) {
		numeratorValue += numeratorFactors[i]*pow(x, i);
	}

	for(int i = 0; i < denominatorFactors.size(); i++) {
		denominatorValue += denominatorFactors[i]*pow(x, i);
	}

	result = numeratorValue/denominatorValue;
	return result;
}




