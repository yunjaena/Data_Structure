#include<ctime>
#include "NYJBankSimulator.h"
void main(){
	srand((unsigned int)time(NULL));
	BankSimulator sim;
	sim.readSimulationParameters();
	sim.run();
	sim.printStat();
}