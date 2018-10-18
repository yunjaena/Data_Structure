#include"NYJAlgorithmA.h"
#include"NYJAlgorithmB.h"
#include"NYJAlgorithmC.h"

#define SUMNUMBER 10000
#define SUMTESTNUMBER 20
void printIntro();
void alogorithmSumTest(NYJAlgorithmA mNyjAlgirithmA,NYJAlgorithmB mNyjAlgirithmB,NYJAlgorithmC mNyjAlgirithmC);
void algorithmTimeTest(NYJAlgorithmA mNyjAlgirithmA,NYJAlgorithmB mNyjAlgirithmB,NYJAlgorithmC mNyjAlgirithmC);

int main(){
	NYJAlgorithmA mNyjAlgirithmA; //NYJAlgorithmA 변수 선언
	NYJAlgorithmB mNyjAlgirithmB; //NYJAlgorithmB 변수 선언
	NYJAlgorithmC mNyjAlgirithmC; //NYJAlgorithmC 변수 선언

	printIntro();
	alogorithmSumTest(mNyjAlgirithmA,mNyjAlgirithmB,mNyjAlgirithmC);
	algorithmTimeTest(mNyjAlgirithmA,mNyjAlgirithmB,mNyjAlgirithmC);

	getchar();
	getchar();
}

void printIntro(){
	cout<<"************** [ 2018년도 2학기 자료구조 실습과제 1 ] **************"<<endl<<endl;
	cout<<"            1. 시간복잡도 (Time Complexity)"<<endl<<endl;
	cout<<" 학번 : 2015136046  이름 : 나윤재"<<endl<<endl;
}

void algorithmTimeTest(NYJAlgorithmA mNyjAlgirithmA,NYJAlgorithmB mNyjAlgirithmB,NYJAlgorithmC mNyjAlgirithmC){
	__int64 mInputNumber =0;

	while(true){

		/* setting algorithm */
		mNyjAlgirithmA.setTimeValueMicroSeconds(); // 시간복잡도가 O1인 알고리즘 us단위로 setting
		mNyjAlgirithmA.setSumValue(mInputNumber); // 계산하고 싶은 값 대입
		mNyjAlgirithmA.timeAlgorithmA(); // 시간 측정

		mNyjAlgirithmB.setTimeValueMilliSeconds();// 시간복잡도가 On인 알고리즘 ms단위로 setting
		mNyjAlgirithmB.setSumValue(mInputNumber); // 계산하고 싶은 값 대입
		mNyjAlgirithmB.timeAlgorithmB(); // 시간 측정

		mNyjAlgirithmC.setTimeValueMilliSeconds();// 시간복잡도가 Onn인 알고리즘 ms단위로 setting
		mNyjAlgirithmC.setSumValue(mInputNumber); // 계산하고 싶은 값 대입
		mNyjAlgirithmC.timeAlgorithmC(); // 시간 측정

		/* print algorithm timing */ 
		if(mNyjAlgirithmC.getTime()<5000){// AlgirithmC가 5초 이상일때 종료
			mNyjAlgirithmA.printAlgorithmA(); //측정 결과 print
			mNyjAlgirithmA.reset(); // reset
			mNyjAlgirithmB.printAlgorithmB(); //측정 결과 print
			mNyjAlgirithmB.reset(); // reset
			mNyjAlgirithmC.printAlgorithmC(); //측정 결과 print
			mNyjAlgirithmC.reset();} // reset
		else
			break;

		mInputNumber += SUMNUMBER; // mInputNumber에다가 SUMNUMBER만큼 증가 시킨다. 
		cout<<endl;

	}
}

void alogorithmSumTest(NYJAlgorithmA mNyjAlgirithmA,NYJAlgorithmB mNyjAlgirithmB,NYJAlgorithmC mNyjAlgirithmC){
	mNyjAlgirithmA.setTimeValueMicroSeconds(); // 시간복잡도가 O1인 알고리즘 us단위로 setting
	mNyjAlgirithmA.setSumValue(SUMTESTNUMBER); // 계산하고 싶은 값 대입
	mNyjAlgirithmA.timeAlgorithmA(); // 시간 측정

	mNyjAlgirithmB.setTimeValueMilliSeconds();// 시간복잡도가 On인 알고리즘 ms단위로 setting
	mNyjAlgirithmB.setSumValue(SUMTESTNUMBER); // 계산하고 싶은 값 대입
	mNyjAlgirithmB.timeAlgorithmB(); // 시간 측정

	mNyjAlgirithmC.setTimeValueMilliSeconds();// 시간복잡도가 Onn인 알고리즘 ms단위로 setting
	mNyjAlgirithmC.setSumValue(SUMTESTNUMBER); // 계산하고 싶은 값 대입
	mNyjAlgirithmC.timeAlgorithmC(); // 시간 측정

	cout<<" -1부터 "<<SUMTESTNUMBER<<"까지의 합-"<<endl;
	cout<<" Algorithm A : "<<mNyjAlgirithmA.getSumNumber()<<"       Algorithm B : "<<mNyjAlgirithmB.getSumNumber()<<"       Algorithm C : "<<mNyjAlgirithmC.getSumNumber()<<endl<<endl;
}