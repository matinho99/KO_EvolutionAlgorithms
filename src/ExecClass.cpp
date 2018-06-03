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
}

ExecClass::~ExecClass() {}

Population ExecClass::getPopulation() {
	return pop;
}

FitnessFunction *ExecClass::getFitnessFunction() {
	return ff;
}

MutationFunction *ExecClass::getMutationFunction() {
	return mf;
}

CrossoverFunction *ExecClass::getCrossoverFunction() {
	return cf;
}

EvoAlgorithm *ExecClass::getAlgorithm() {
	return alg;
}

void ExecClass::setPopulation(Population p) {
	pop = p;
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
	pop = alg->execAlgorithm(pop, ff, mf, cf);
}

void ExecClass::showPopulationFitness() {
	for(Individual i : pop.getIndividuals()) {
		std::cout << i.getValue() << " - fitness = " << ff->calculateFitness(i.getValue()) << " - function value = " << ff->calculateFunctionValue(i.getValue()) << std::endl;
	}
	std::cout << std::endl;
}
