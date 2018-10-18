#include"AlgorithmCommonHeader.h"
class NYJAlgorithmC{

private:

	TimeUtil mTime; // �ð� ���� util
	int mSumNumber; // �� �ϰ� ���� ��
	__int64 mAnswerNumber;// ���� ��
	double mTakeTime;// �ɸ� �ð�
	int mTimeStatus;// MicroSeconds : 0 , MilliSeconds : 1, Seconds : 2

	void algorithmC(){
		int tempNumber = 0;
		// 1�� ������Ű�鼭 �����ְ� �����ذ� mAnswer���ٰ� �����ش�.
		for(int a=0 ;a <= mSumNumber ; a++){
			for(int b = 0 ; b< a; b++){
				tempNumber++;
			}
			mAnswerNumber += tempNumber;
			tempNumber =0 ;
		}
	}

public:


	NYJAlgorithmC(__int64 sumNumber = 0):mSumNumber(0),mAnswerNumber(0),mTakeTime(0.0){
		mSumNumber = sumNumber;
		mTime.setTimeValueMicroSeconds();
	}

	void timeAlgorithmC(){
		mTime.startCounter();
		algorithmC();
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

	void printAlgorithmC(){
		if(mTimeStatus == 0)
			printf(" Onn �ð� : %10.5lf us",mTakeTime);
		else if(mTimeStatus ==1)
			printf(" Onn �ð� : %10.5lf ms",mTakeTime);
		else
			printf(" Onn �ð� : %10.5lf s",mTakeTime);
	}


};