#include "EvoAlgorithm.h"
#include "ExecClass.h"

#include <cstdint>
#include <string>

#include "boost/test/unit_test.hpp"

BOOST_AUTO_TEST_SUITE(EvoTests)

BOOST_AUTO_TEST_CASE(GivenOneThingAnotherThingHappens)  // proof that Boost tests work
{
	BOOST_CHECK_EQUAL(2+2,4);
}

/* Individual class testing */
BOOST_AUTO_TEST_CASE(WhenIndividualDefaultConstructThenValueIsZero) {
	Individual ind;
	BOOST_CHECK_EQUAL(0.0f, ind.getValue());
}

BOOST_AUTO_TEST_CASE(WhenIndividualConstructWithValueThenValueIsCorrect) {
	Individual ind(10.0f);
	BOOST_CHECK_EQUAL(10.0f, ind.getValue());
}

BOOST_AUTO_TEST_CASE(WhenSettingIndividualValueThenValueIsCorrect) {
	Individual ind;
	ind.setValue(5.0f);
	BOOST_CHECK_EQUAL(5.0f, ind.getValue());
}

/* Population class testing */
BOOST_AUTO_TEST_CASE(WhenPopulationDefualtConstructThenItIsEmpty) {
	Population pop;
	BOOST_CHECK_EQUAL(true, pop.getIndividuals().empty());
}

BOOST_AUTO_TEST_CASE(WhenAddingOneIndividualToPopulationThenItIsNotEmpty) {
	Population pop;
	Individual ind;
	pop.addIndividual(ind);
	BOOST_CHECK_EQUAL(false, pop.getIndividuals().empty());
}

BOOST_AUTO_TEST_CASE(WhenTwoIndividualsAddedToPopulationThenLastOnesValueIsCorrect) {
	Population p;
	Individual ind1(4.0f);
	Individual ind2(6.0f);
	p.addIndividual(ind1);
	p.addIndividual(ind2);
	float checkVal = p.getIndividuals().back().getValue();
	BOOST_CHECK_EQUAL(6.0f, checkVal);
}

/* FitnessFunction class testing */
BOOST_AUTO_TEST_CASE(WhenFitnessFunctionDefualtConstructThenNumeratorIsEmptyAndDenominatorIsEmptyAndTargetIsZero) {
	FitnessFunction ff;
	BOOST_CHECK_EQUAL(true, ff.getNumeratorFactors().empty());
	BOOST_CHECK_EQUAL(true, ff.getDenominatorFactors().empty());
	BOOST_CHECK_EQUAL(0.0f, ff.getTarget());
}

BOOST_AUTO_TEST_CASE(WhenFitnessFunctionDefaultConstructThenFunctionValueIsZero) {
	FitnessFunction ff;
	BOOST_CHECK_EQUAL(0.0f, ff.calculateFunctionValue(2.0f));
	BOOST_CHECK_EQUAL(0.0f, ff.calculateFunctionValue(20.0f));
}

BOOST_AUTO_TEST_CASE(WhenFitnessFunctionDefaultConstructThenFitnessIsZero) {
	FitnessFunction ff;
	BOOST_CHECK_EQUAL(1/1000.0f, ff.calculateFitness(2.0f));
	BOOST_CHECK_EQUAL(1/1000.0f, ff.calculateFitness(20.0f));
}

BOOST_AUTO_TEST_CASE(WhenFitnessFunctionConstructWithNumeratorDenominatorAndTargetThenTheyAreSetCorrectly) {
	std::vector<float> numFact {1, 1, 1};
	std::vector<float> denomFact {1, 0, 0};
	FitnessFunction ff(numFact, denomFact, 10.0f);
	BOOST_CHECK(numFact == ff.getNumeratorFactors());
	BOOST_CHECK(denomFact == ff.getDenominatorFactors());
	BOOST_CHECK_EQUAL(10.0f, ff.getTarget());
}

BOOST_AUTO_TEST_CASE(WhenFitnessFunctionSettingNumeratorDenominatorAndTargetThenTheyAreSetCorrectly) {
	FitnessFunction ff;
	std::vector<float> numFact {1, 1, 1};
	std::vector<float> denomFact {1, 0, 0};
	ff.setNumeratorFactors(numFact);
	ff.setDenominatorFactors(denomFact);
	ff.setTarget(10.0f);
	BOOST_CHECK(numFact == ff.getNumeratorFactors());
	BOOST_CHECK(denomFact == ff.getDenominatorFactors());
	BOOST_CHECK_EQUAL(10.0f, ff.getTarget());
}

BOOST_AUTO_TEST_CASE(WhenFitnessFunctionConstructWithNumeratorDenominatorAndTargetThenFunctionValueIsCorrect) {
	FitnessFunction ff;
	std::vector<float> numFact {1, 1, 1};
	std::vector<float> denomFact {1, 0, 0};
	ff.setNumeratorFactors(numFact);
	ff.setDenominatorFactors(denomFact);
	BOOST_CHECK_EQUAL(7.0f, ff.calculateFunctionValue(2.0f));
	BOOST_CHECK_EQUAL(111.0f, ff.calculateFunctionValue(10.0f));
}

BOOST_AUTO_TEST_CASE(WhenFitnessFunctionConstructWithNumeratorDenominatorAndTargetThenFitnessIsCorrect) {
	std::vector<float> numFact {1, 1, 1};
	std::vector<float> denomFact {1, 0, 0};
	FitnessFunction ff(numFact, denomFact, 10.0f);
	BOOST_CHECK_EQUAL(1/(10.0f-7.0f), ff.calculateFitness(2.0f));
	BOOST_CHECK_EQUAL(1/(111.0f-10.0f), ff.calculateFitness(10.0f));
}

/* MutationFunction class testing */
BOOST_AUTO_TEST_CASE(WhenMutationDefaultConstructThenMutatorIsZero) {
	MutationFunction mf;
	BOOST_CHECK_EQUAL(0.0f, mf.getMutator());
}

BOOST_AUTO_TEST_CASE(WhenMutationIsSetThenMutatorIsCorrect) {
	MutationFunction mf;
	mf.setMutator(5.0f);
	BOOST_CHECK_EQUAL(5.0f, mf.getMutator());
}

/* CrossoverFunction class testing */
BOOST_AUTO_TEST_CASE(WhenCrossoverDefaultConstructThenCrossoverFactorIsZero) {
	CrossoverFunction cf;
	BOOST_CHECK_EQUAL(0.0f, cf.getCrossFactor());
}

BOOST_AUTO_TEST_CASE(WhenCrossoverIsSetThenCrossoverFactorIsCorrect) {
	CrossoverFunction cf;
	cf.setCrossFactor(5.0f);
	BOOST_CHECK_EQUAL(5.0f, cf.getCrossFactor());
}

/* ExecClass class testing */
BOOST_AUTO_TEST_CASE(WhenExecClassDefaultConstructThenPopulationIsEmptyAndFunctionsAndAlgorithmAreNull) {
	ExecClass e;
	BOOST_CHECK_EQUAL(true, e.getPopulation().getIndividuals().empty());
}

BOOST_AUTO_TEST_SUITE_END()

