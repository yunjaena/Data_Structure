#include"iostream"
#include<Windows.h>

#define MICROSECONDS 1000000.0
#define MILLISECONDS 1000.0
#define SECONDS 1

using namespace std;

class TimeUtil{

private:

	double mPcFreq;
	__int64 mCounterStart;
	double mTimeValue;


public:
	//멤버 초기화 리스트로 측정 시간 초기화 단위는 ms로 default
	TimeUtil():mPcFreq(0.0),mCounterStart(0),mTimeValue(1000.0){
	}

	//counter  초기화
	void resetCounter(){
		mPcFreq=0.0;
		mCounterStart=0;
	}

	void setTimeValueMicroSeconds(){
		mTimeValue = MICROSECONDS;
	}

	void setTimeValueMilliSeconds(){
		mTimeValue = MILLISECONDS;
	}
	void setTimeValueSeconds(){
		mTimeValue =  SECONDS;
	}	

	/**QueryPerformanceCounter를 한번실행하고 수행후 
	 *다시 콜함으로써 각각 얻어진 카운터값의 차이를 구함으로써 
	 *수행시간을 판단
	 */

	void startCounter()	 
	{
		LARGE_INTEGER li;
		if(!QueryPerformanceFrequency(&li))
			cout << "QueryPerformanceFrequency failed!\n";

		mPcFreq = double(li.QuadPart)/mTimeValue; // 측정단위 설정

		QueryPerformanceCounter(&li);
		mCounterStart = li.QuadPart;
	}

	double getCounter()
	{
		LARGE_INTEGER li;
		QueryPerformanceCounter(&li);
		return double(li.QuadPart-mCounterStart)/mPcFreq;
	}

};