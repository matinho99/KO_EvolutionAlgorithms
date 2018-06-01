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

float FitnessFunction::calculateFitness(float val) {
	float numeratorValue = 0;
	float denominatorValue = 0;
	float fitness;

	for(int i = 0; i < numeratorFactors.size(); i++) {
		numeratorValue += numeratorFactors[i]*pow(val, i);
	}

	for(int i = 0; i < denominatorFactors.size(); i++) {
		denominatorValue += denominatorFactors[i]*pow(val, i);
	}

	fitness = numeratorValue/denominatorValue;
	return fitness;
}




