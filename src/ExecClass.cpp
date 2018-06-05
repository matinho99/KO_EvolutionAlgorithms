#include "ExecClass.h"

ExecClass::ExecClass() {
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

Population& ExecClass::getPopulation() {
	return pop;
}

FitnessFunction& ExecClass::getFitnessFunction() {
	return ff;
}

MutationFunction& ExecClass::getMutationFunction() {
	return mf;
}

CrossoverFunction& ExecClass::getCrossoverFunction() {
	return cf;
}

EvoAlgorithm* ExecClass::getAlgorithm() {
	return alg;
}

void ExecClass::setPopulation(const Population& p) {
	pop = p;
}

void ExecClass::setFitnessFunction(const FitnessFunction& f) {
	ff = f;
}

void ExecClass::setMutationFunction(const MutationFunction& f) {
	mf = f;
}

void ExecClass::setCrossoverFunction(const CrossoverFunction& f) {
	cf = f;
}

void ExecClass::setAlgorithm(EvoAlgorithm* ea) {
	alg = ea;
}

void ExecClass::generateNextPopulation() {
	pop = alg->execAlgorithm(pop, ff, mf, cf);
}

void ExecClass::showPopulationFitness() {
	for(Individual i : pop.getIndividuals()) {
		std::cout << i.getValue() << " - fitness = " << ff.calculateFitness(i.getValue()) << " - function value = " << ff.calculateFunctionValue(i.getValue()) << std::endl;
	}
}
