#include"AlgorithmCommonHeader.h"
class NYJAlgorithmB{

private:

	TimeUtil mTime; // �ð� ���� util
	int mSumNumber; // �� �ϰ� ���� ��
	__int64 mAnswerNumber;// ���� ��
	double mTakeTime;// �ɸ� �ð�
	int mTimeStatus;// MicroSeconds : 0 , MilliSeconds : 1, Seconds : 2

	void algorithmB(){
		for(int a=0 ;a <= mSumNumber ; a++){
			mAnswerNumber += a; // ���� ���� ����ŭ �ݺ��ؼ� �����ش�.
		}
	}

public:


	NYJAlgorithmB(__int64 sumNumber = 0):mSumNumber(0),mAnswerNumber(0),mTakeTime(0.0){
		mSumNumber = sumNumber;
		mTime.setTimeValueMicroSeconds();
	}

	void timeAlgorithmB(){
		mTime.startCounter();
		algorithmB();
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

	void printAlgorithmB(){

		  cout.setf(ios::left);
		if(mTimeStatus == 0)
			printf(" On �ð� : %10.5lf usec",mTakeTime);

		else if(mTimeStatus ==1)
			printf(" On �ð� : %10.5lf ms",mTakeTime);
		else
			printf(" On �ð� : %10.5lf s",mTakeTime);;
	}


};