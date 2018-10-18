#include"AlgorithmCommonHeader.h"
class NYJAlgorithmB{

private:

	TimeUtil mTime; // 시간 측정 util
	int mSumNumber; // 더 하고 싶은 수
	__int64 mAnswerNumber;// 더한 수
	double mTakeTime;// 걸린 시간
	int mTimeStatus;// MicroSeconds : 0 , MilliSeconds : 1, Seconds : 2

	void algorithmB(){
		for(int a=0 ;a <= mSumNumber ; a++){
			mAnswerNumber += a; // 대입 받은 수만큼 반복해서 더해준다.
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
			printf(" On 시간 : %10.5lf usec",mTakeTime);

		else if(mTimeStatus ==1)
			printf(" On 시간 : %10.5lf ms",mTakeTime);
		else
			printf(" On 시간 : %10.5lf s",mTakeTime);;
	}


};