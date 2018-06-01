#include "ExecClass.h"

ExecClass::ExecClass() {
	ff = nullptr;
	mf = nullptr;
	cf = nullptr;
	alg = nullptr;
}

ExecClass::ExecClass(int popSize) : ExecClass() {
	for(int i = 0; i<popSize; i++) {
		float val = rand() % 20 + (float)rand()/RAND_MAX;
		Individual ind(val);
		pop.addIndividual(ind);
	}

	std::cout << pop;
}

ExecClass::~ExecClass() {}

FitnessFunction *ExecClass::getFitnessFunction() {
	return ff;
}

MutationFunction *ExecClass::getMutationFunction() {
	return mf;
}

CrossoverFunction *ExecClass::getCrossoverFunction() {
	return cf;
}

void ExecClass::setFitnessFunction(FitnessFunction *f) {
	ff = f;
}

void ExecClass::setMutationFunction(MutationFunction *f) {
	mf = f;
}

void ExecClass::setCrossoverFunction(CrossoverFunction *f) {
	cf = f;
}

void ExecClass::setAlgorithm(EvoAlgorithm *ea) {
	alg = ea;
}

void ExecClass::generateNextPopulation() {
	alg->execAlgorithm();
}

void ExecClass::showPopulationFitness() {
	for(Individual i : pop.getPopulation()) {
		std::cout << i.getValue() << " - " << ff->calculateFitness(i.getValue()) << std::endl;
	}
}
