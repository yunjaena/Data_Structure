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
		printf(" �� %d �湮 (���� �ð�:%d��)\n" , a.id , a.tService);
		que.push(a);
	}


public:
	BankSimulator(): nCustomers(0),totalWaitTime(0),nServedCustomers(0) {}

	void readSimulationParameters(){
		printf("�ùķ��̼� �� �ִ� �ð� (��:10) = ");
		scanf("%d", &nSimulation);
		printf("�����ð��� �����ϴ� ���� (�� :0.7) =");
		scanf("%lf", &probArrival);
		printf("�� ���� ���� �ִ� ���� �ð� (��: 5) = ");
		scanf("%d", &tMaxService);
		printf("ī���� �� (��: 2) = ");
		scanf("%d", &nCounter);
		printf("============================================================\n");
	}

	void run(){
		int clock =0;
		int serviceTime = -1;
		vector<int> counterTime(nCounter,0);
		while( clock < nSimulation){
			clock++;
			printf("����ð�=%d\n",clock);

			if(IsNewCustomer())
				InsertCustomer(clock);
			/*if(serviceTime > 0) serviceTime--;
			else{
			if(que.empty())continue;
			Customer  a = que.front();
			que.pop();
			nServedCustomers++;
			totalWaitTime+= clock - a.tArrival;
			printf(" �� %d ���� ���� (���ð�:%d��)\n",
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
					printf(" [ī���� %d] �� %d ���� ���� (���ð�:%d��)\n",
						x+1,a.id, clock-a.tArrival);
					counterTime.at(x) = a.tService -1;
				}
			}
		}
	}

	void printStat()
	{
		printf("============================================================\n");
		printf(" ���� ���� ����      = %d\n",nServedCustomers);
		printf(" ��ü ��� �ð� ����   = %d��\n",totalWaitTime);
		printf(" ���񽺰� ��մ��ð� = %-5.2f��\n",(double)totalWaitTime/nServedCustomers);
		printf(" ���� ��� �� ��         = %d\n",nCustomers - nServedCustomers);
	}
};

