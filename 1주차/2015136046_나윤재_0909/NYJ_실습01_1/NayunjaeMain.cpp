#include"NYJAlgorithmA.h"
#include"NYJAlgorithmB.h"
#include"NYJAlgorithmC.h"

#define SUMNUMBER 10000
#define SUMTESTNUMBER 20
void printIntro();
void alogorithmSumTest(NYJAlgorithmA mNyjAlgirithmA,NYJAlgorithmB mNyjAlgirithmB,NYJAlgorithmC mNyjAlgirithmC);
void algorithmTimeTest(NYJAlgorithmA mNyjAlgirithmA,NYJAlgorithmB mNyjAlgirithmB,NYJAlgorithmC mNyjAlgirithmC);

int main(){
	NYJAlgorithmA mNyjAlgirithmA; //NYJAlgorithmA ���� ����
	NYJAlgorithmB mNyjAlgirithmB; //NYJAlgorithmB ���� ����
	NYJAlgorithmC mNyjAlgirithmC; //NYJAlgorithmC ���� ����

	printIntro();
	alogorithmSumTest(mNyjAlgirithmA,mNyjAlgirithmB,mNyjAlgirithmC);
	algorithmTimeTest(mNyjAlgirithmA,mNyjAlgirithmB,mNyjAlgirithmC);

	getchar();
	getchar();
}

void printIntro(){
	cout<<"************** [ 2018�⵵ 2�б� �ڷᱸ�� �ǽ����� 1 ] **************"<<endl<<endl;
	cout<<"            1. �ð����⵵ (Time Complexity)"<<endl<<endl;
	cout<<" �й� : 2015136046  �̸� : ������"<<endl<<endl;
}

void algorithmTimeTest(NYJAlgorithmA mNyjAlgirithmA,NYJAlgorithmB mNyjAlgirithmB,NYJAlgorithmC mNyjAlgirithmC){
	__int64 mInputNumber =0;

	while(true){

		/* setting algorithm */
		mNyjAlgirithmA.setTimeValueMicroSeconds(); // �ð����⵵�� O1�� �˰��� us������ setting
		mNyjAlgirithmA.setSumValue(mInputNumber); // ����ϰ� ���� �� ����
		mNyjAlgirithmA.timeAlgorithmA(); // �ð� ����

		mNyjAlgirithmB.setTimeValueMilliSeconds();// �ð����⵵�� On�� �˰��� ms������ setting
		mNyjAlgirithmB.setSumValue(mInputNumber); // ����ϰ� ���� �� ����
		mNyjAlgirithmB.timeAlgorithmB(); // �ð� ����

		mNyjAlgirithmC.setTimeValueMilliSeconds();// �ð����⵵�� Onn�� �˰��� ms������ setting
		mNyjAlgirithmC.setSumValue(mInputNumber); // ����ϰ� ���� �� ����
		mNyjAlgirithmC.timeAlgorithmC(); // �ð� ����

		/* print algorithm timing */ 
		if(mNyjAlgirithmC.getTime()<5000){// AlgirithmC�� 5�� �̻��϶� ����
			mNyjAlgirithmA.printAlgorithmA(); //���� ��� print
			mNyjAlgirithmA.reset(); // reset
			mNyjAlgirithmB.printAlgorithmB(); //���� ��� print
			mNyjAlgirithmB.reset(); // reset
			mNyjAlgirithmC.printAlgorithmC(); //���� ��� print
			mNyjAlgirithmC.reset();} // reset
		else
			break;

		mInputNumber += SUMNUMBER; // mInputNumber���ٰ� SUMNUMBER��ŭ ���� ��Ų��. 
		cout<<endl;

	}
}

void alogorithmSumTest(NYJAlgorithmA mNyjAlgirithmA,NYJAlgorithmB mNyjAlgirithmB,NYJAlgorithmC mNyjAlgirithmC){
	mNyjAlgirithmA.setTimeValueMicroSeconds(); // �ð����⵵�� O1�� �˰��� us������ setting
	mNyjAlgirithmA.setSumValue(SUMTESTNUMBER); // ����ϰ� ���� �� ����
	mNyjAlgirithmA.timeAlgorithmA(); // �ð� ����

	mNyjAlgirithmB.setTimeValueMilliSeconds();// �ð����⵵�� On�� �˰��� ms������ setting
	mNyjAlgirithmB.setSumValue(SUMTESTNUMBER); // ����ϰ� ���� �� ����
	mNyjAlgirithmB.timeAlgorithmB(); // �ð� ����

	mNyjAlgirithmC.setTimeValueMilliSeconds();// �ð����⵵�� Onn�� �˰��� ms������ setting
	mNyjAlgirithmC.setSumValue(SUMTESTNUMBER); // ����ϰ� ���� �� ����
	mNyjAlgirithmC.timeAlgorithmC(); // �ð� ����

	cout<<" -1���� "<<SUMTESTNUMBER<<"������ ��-"<<endl;
	cout<<" Algorithm A : "<<mNyjAlgirithmA.getSumNumber()<<"       Algorithm B : "<<mNyjAlgirithmB.getSumNumber()<<"       Algorithm C : "<<mNyjAlgirithmC.getSumNumber()<<endl<<endl;
}