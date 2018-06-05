#include "ui.h"

std::string getFunctionString(FitnessFunction &ff) {
	std::string function;
	std::vector<float> num = ff.getNumeratorFactors();
	std::vector<float> denom = ff.getDenominatorFactors();
	int numSize = num.size();
	int denomSize = denom.size();
	function += "(";

	if(numSize > 0) {
		for(int i=0; i<numSize; i++) {
			function += std::to_string(num.at(i))+"*x^"+std::to_string(i);

			if(i < numSize-1) {
				function += " + ";
			}
		}
	}

	function += ") / (";

	if(denomSize > 0) {
		for(int i=0; i<denomSize; i++) {
			function += std::to_string(denom.at(i))+"*x^"+std::to_string(i);

			if(i < denomSize-1) {
				function += " + ";
			}
		}
	}

	function += ")";
	return function;
}

void ui(ExecClass &e) {
	int popno = 0;
	int choice;
	std::string functionString = getFunctionString(e.getFitnessFunction());

	while(1) {
		std::cout << "----------" << std::endl;
		std::cout << "Funkcja oceny: " << functionString << std::endl;
		std::cout << "Wartosc docelowa: " << e.getFitnessFunction().getTarget() << std::endl;
		std::cout << "Wspolczynnik mutacji: " << e.getMutationFunction().getMutator() << std::endl;
		std::cout << "Wspolczynnik krzyzowania: " << e.getCrossoverFunction().getCrossFactor() << std::endl;
		std::cout << "Opcje:\n";
		std::cout << "1: Nowa populacja\n";
		std::cout << "2: Wygeneruj kolejna populacje\n";
		std::cout << "3: Wygeneruj kolejne N populacji\n";
		std::cout << "4: Zmien licznik funkcji oceny\n";
		std::cout << "5: Zmien mianownik funkcji oceny\n";
		std::cout << "6: Zmien wartosc docelowa\n";
		std::cout << "7: Zmien parametr mutacji\n";
		std::cout << "8: Zmien parametr krzyzowania\n";
		std::cout << "0: Zamknij program\n";
		std::cout << "\nWybor: ";
		std::cin >> choice;
		std::cout << std::endl;

		switch(choice) {
			case 1: {
				int popSize;
				Population newPop;
				popno = 0;
				std::cout << "Jak duza ma byc nowa populacja?: ";
				std::cin >> popSize;
				
				for(int i = 0; i < popSize; ++i) {
					float val = rand() % 20 + (float)rand()/RAND_MAX;
					Individual ind(val);
					newPop.addIndividual(ind);
				}

				e.setPopulation(newPop);
				break;
			}
			case 2:
				e.generateNextPopulation();
				std::cout << "Populacja numer: " << ++popno << std::endl;
				e.showPopulationFitness();
				break;
			case 3:
				int N;
				std::cout << "N = ";
				std::cin >> N;
				std::cout << std::endl;

				if(N > 0) {
					for(int i = 0; i < N; ++i) {
						e.generateNextPopulation();
						std::cout << "Populacja numer: " << ++popno << std::endl;
						e.showPopulationFitness();
					}
				} else {
					std::cout << "N musi byc wieksze od 0\n";
				}
				break;
			case 4:
				int numRank;
				std::cout << "Podaj stopien wielomianu licznika: ";
				std::cin >> numRank;

				if(numRank >= 0) {
					std::vector<float> factors;

					for(int i=0; i<numRank+1; ++i) {
						float fact;
						std::cout << "Podaj wspolczynnik dla wyrazu x^" << i << ": ";
						std::cin >> fact;
						factors.push_back(fact);
					}

					e.getFitnessFunction().setNumeratorFactors(factors);
					functionString = getFunctionString(e.getFitnessFunction());
				} else {
					std::cout << "Stopien wielomianu nie moze byc mniejszy od zera\n";
				}
				break;
			case 5:
				int denomRank;
				std::cout << "Podaj stopien wielomianu mianownika: ";
				std::cin >> denomRank;

				if(denomRank >= 0) {
					std::vector<float> factors;

					for(int i=0; i<denomRank+1; ++i) {
						float fact;
						std::cout << "Podaj wspolczynnik dla wyrazu x^" << i << ": ";
						std::cin >> fact;
						factors.push_back(fact);
					}

					e.getFitnessFunction().setDenominatorFactors(factors);
					functionString = getFunctionString(e.getFitnessFunction());
				} else {
					std::cout << "Stopien wielomianu nie moze byc mniejszy od zera\n";
				}
				break;
			case 6:
				float target;
				std::cout << "Wartosc docelowa = ";
				std::cin >> target;
				e.getFitnessFunction().setTarget(target);
				break;
			case 7:
				float cmf;
				std::cout << "Parametr mutacji = ";
				std::cin >> cmf;
				e.getMutationFunction().setMutator(cmf);
				break;
			case 8:
				float ccf;
				std::cout << "Parametr krzyzowania = ";
				std::cin >> ccf;
				e.getCrossoverFunction().setCrossFactor(ccf);
				break;
			case 0:
				return;
			default:
				std::cout << "Zla opcja\n";
				break;
		}
	}
}
