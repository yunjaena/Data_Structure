#include"AlgorithmCommonHeader.h"
class NYJAlgorithmA{

private:

	TimeUtil mTime; // �ð� ���� util
	__int64 mSumNumber; // �� �ϰ� ���� ��
	__int64 mAnswerNumber;// ���� ��
	double mTakeTime;// �ɸ� �ð�
	int mTimeStatus;// MicroSeconds : 0 , MilliSeconds : 1, Seconds : 2

	void algorithmA(){
		mAnswerNumber=(mSumNumber*(mSumNumber+1))/2; // ���� ���� ���� ���� ������ ���� 1�� ���Ѱ��� ���ؼ� 2�� ������.  
	}

public:


	NYJAlgorithmA(__int64 sumNumber = 0):mSumNumber(0),mAnswerNumber(0),mTakeTime(0.0){
		mSumNumber = sumNumber;
		mTime.setTimeValueMicroSeconds();
	}

	void timeAlgorithmA(){
		mTime.startCounter();
		algorithmA();
		mTakeTime = mTime.getCounter();
	}

	void setTimeValueMicroSeconds(){
		mTime.setTimeValueMicroSeconds();
		mTimeStatus = 0;
	}

	void setTimeValueMilliSeconds(){
		mTime.setTimeValueMilliSeconds();
		mTimeStatus = 1;
	}
	void setTimeValueSeconds(){
		mTime.setTimeValueSeconds();
		mTimeStatus = 2;
	}

	void setSumValue(__int64 number){
		mSumNumber = number;
	}

	void reset(){
		mTime.resetCounter();
		mAnswerNumber= 0;
	}

	double getTime(){
		return mTakeTime;
	}

	__int64 getSumNumber(){

		return mAnswerNumber;
	}

	void printAlgorithmA(){
		if(mTimeStatus == 0)
			printf(" O1 �ð� : %10.5lf us",mTakeTime);
		else if(mTimeStatus ==1)
			printf(" O1 �ð� : %10.5lf ms",mTakeTime);
		else
			printf(" O1 �ð� : %10.5lf s",mTakeTime);
	}


};