#include"AlgorithmCommonHeader.h"
class NYJAlgorithmA{

private:

	TimeUtil mTime; // 시간 측정 util
	__int64 mSumNumber; // 더 하고 싶은 수
	__int64 mAnswerNumber;// 더한 수
	double mTakeTime;// 걸린 시간
	int mTimeStatus;// MicroSeconds : 0 , MilliSeconds : 1, Seconds : 2

	void algorithmA(){
		mAnswerNumber=(mSumNumber*(mSumNumber+1))/2; // 대입 받은 수와 대입 받은수 에서 1을 더한것을 곱해서 2로 나눈다.  
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
			printf(" O1 시간 : %10.5lf us",mTakeTime);
		else if(mTimeStatus ==1)
			printf(" O1 시간 : %10.5lf ms",mTakeTime);
		else
			printf(" O1 시간 : %10.5lf s",mTakeTime);
	}


};