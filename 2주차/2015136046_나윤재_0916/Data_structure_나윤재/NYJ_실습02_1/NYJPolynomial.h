#include<cstdio>
#define MAX_DEGREE 80
class NYJPolynomial{

	int degree;
	float coef[MAX_DEGREE];

public:
	NYJPolynomial(){degree = 0;}

	void Read(char *str ="A"){
		printf("다항식%s의 최고차수를 입력하시오: ",str);
		scanf("%d", &degree);
		printf("각 항의 계수를 입력하시오 (총 %d): ",degree+1);
		for(int i=0; i <= degree; i++)
			scanf("%f", coef+i);
	}
	// 다항식의 내용을 화면에 출력하는 함수
	void display2(char *str =" Poly = "){
		printf("\t%s",str);
		for(int i=0 ; i<degree ; i++){
			if(coef[i] == 0.0) continue;
			printf("%5.1f x^%d", coef[i], degree-i);
			if(coef[i+1]>=0.0)
				printf(" + ");
		}
		if(coef[degree] != 0.0)
			printf("%4.1f\n", coef[degree]);
		else
			printf("\n");
	}

	// 다항식의 내용을 화면에 출력하는 함수
	void display(char *str =" Poly = "){
		printf("\t%s",str);
		for(int i=0 ; i<degree ; i++){
			printf("%5.1f x^%d", coef[i], degree-i);
			if(coef[i+1]>=0.0 && i==degree-1)
				printf(" + ");
		}
		printf("%4.1f\n", coef[degree]);
		printf("\n");
	}
	void add(NYJPolynomial a, NYJPolynomial b){
		if(a.degree > b.degree){
			*this =a;
			for(int i=0 ; i<=b.degree ; i++)
				coef[i+(degree - b.degree)] += b.coef[i];
		}
		else{
			*this = b;
			for(int i=0 ; i<=a.degree ; i++)
				coef[i+(degree - a.degree)] += a.coef[i];
		}
	}

	void Sub(NYJPolynomial a , NYJPolynomial b){
		int index =0;
		if(a.degree > b.degree){
			degree = a.degree;
		}
		else{
			degree = b.degree;
		}
		for(int i=0 ; i<=degree; i++){
			coef[i] = 0.0;
		}

		for(int i=0 ; i<=degree; i++){
			coef[degree-a.degree+i] = a.coef[i];
		}
		for(int i=0; i<=degree ; i++)
			coef[degree-b.degree+i]  -= b.coef[i];

	}

	void Mult(NYJPolynomial a, NYJPolynomial b){
		degree = a.degree + b.degree;
		for(int i = 0 ; i <= degree ; i++)
			coef[i] = 0.0;
		for(int x=0; x<=a.degree ; x++)
			for(int y=0; y<=b.degree ; y++)
				coef[x+y] += a.coef[x]*b.coef[y];
	}


	bool isZero(){return degree ==0;} // 최고 차수가 0인가?

	void negate(){
		for(int i=0 ; i<=degree ; i++)
			coef[i] = -coef[i];
	}

	void Trim(){
		int index = 0;
		int a=0;

		float tempArray[MAX_DEGREE];
		for(int i =0 ; i<= degree; i++)
			tempArray[i] = coef[i];


		for(int i = 0; i<=degree ; i++){
			if(coef[i]!=0.0){
				for(int index = i ; index <= degree; index++){
					coef[a] = tempArray[index];
					a++;
				}
				degree =  a-1;
				break;


			}

			if(coef[i] == 0.0 && i == degree)
			{
				degree = 0;
				break;
			}
		}


		a=0;
	}
};
