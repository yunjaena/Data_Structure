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
	//��� �ʱ�ȭ ����Ʈ�� ���� �ð� �ʱ�ȭ ������ ms�� default
	TimeUtil():mPcFreq(0.0),mCounterStart(0),mTimeValue(1000.0){
	}

	//counter  �ʱ�ȭ
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

	/**QueryPerformanceCounter�� �ѹ������ϰ� ������ 
	 *�ٽ� �������ν� ���� ����� ī���Ͱ��� ���̸� �������ν� 
	 *����ð��� �Ǵ�
	 */

	void startCounter()	 
	{
		LARGE_INTEGER li;
		if(!QueryPerformanceFrequency(&li))
			cout << "QueryPerformanceFrequency failed!\n";

		mPcFreq = double(li.QuadPart)/mTimeValue; // �������� ����

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