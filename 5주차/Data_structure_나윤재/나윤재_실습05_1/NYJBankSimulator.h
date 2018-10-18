#include"NYJCustomer.h"
#include <queue>
#include <vector>
using namespace std;
class BankSimulator
{
	int nSimulation;
	double probArrival;
	int tMaxService;
	int totalWaitTime;
	int nCustomers;
	int nServedCustomers;
	int nCounter;
	queue<Customer> que;

	double Random() { return rand()/(double)RAND_MAX;}
	bool IsNewCustomer() { return Random() < probArrival;}
	int RandServiceTime() { return (int) (tMaxService * Random()) +1; }

	void InsertCustomer(int arrivalTime){
		Customer a(++nCustomers , arrivalTime , RandServiceTime());
		printf(" 고객 %d 방문 (서비스 시간:%d분)\n" , a.id , a.tService);
		que.push(a);
	}


public:
	BankSimulator(): nCustomers(0),totalWaitTime(0),nServedCustomers(0) {}

	void readSimulationParameters(){
		printf("시뮬레이션 할 최대 시간 (예:10) = ");
		scanf("%d", &nSimulation);
		printf("단위시간에 도착하는 고객수 (예 :0.7) =");
		scanf("%lf", &probArrival);
		printf("한 고객에 대한 최대 서비스 시간 (에: 5) = ");
		scanf("%d", &tMaxService);
		printf("카운터 수 (에: 2) = ");
		scanf("%d", &nCounter);
		printf("============================================================\n");
	}

	void run(){
		int clock =0;
		int serviceTime = -1;
		vector<int> counterTime(nCounter,0);
		while( clock < nSimulation){
			clock++;
			printf("현재시각=%d\n",clock);

			if(IsNewCustomer())
				InsertCustomer(clock);
			/*if(serviceTime > 0) serviceTime--;
			else{
			if(que.empty())continue;
			Customer  a = que.front();
			que.pop();
			nServedCustomers++;
			totalWaitTime+= clock - a.tArrival;
			printf(" 고객 %d 서비스 시작 (대기시간:%d분)\n",
			a.id, clock-a.tArrival);
			serviceTime = a.tService -1;
			}*/
			for(int x = 0 ; x<nCounter ; x++)
			{
				if(counterTime.at(x) > 0) counterTime.at(x) --;
				else{
					if(que.empty())continue;
					Customer  a = que.front();
					que.pop();
					nServedCustomers++;
					totalWaitTime+= clock - a.tArrival;
					printf(" [카운터 %d] 고객 %d 서비스 시작 (대기시간:%d분)\n",
						x+1,a.id, clock-a.tArrival);
					counterTime.at(x) = a.tService -1;
				}
			}
		}
	}

	void printStat()
	{
		printf("============================================================\n");
		printf(" 서비스 받은 고객수      = %d\n",nServedCustomers);
		printf(" 전체 대기 시간 고객수   = %d분\n",totalWaitTime);
		printf(" 서비스고객 평균대기시간 = %-5.2f분\n",(double)totalWaitTime/nServedCustomers);
		printf(" 현재 대기 고객 수         = %d\n",nCustomers - nServedCustomers);
	}
};

