#include"EvalPostfix.h"

inline int precedence(char op){
	switch(op){
	case '(' : case ')' : return 0;
	case '+' : case '-' : return 1;
	case '*' : case '/' : return 2;
	}
	return -1;
}

void infix2Postfix(FILE * fp =stdin){
	char c,op;
	double val;
	stack<char> st;
	string value = "";
	FILE * fp2 = fopen("temp.txt","w");


	while((c= getc(fp)) != '\n'){
		

		if((c >= '0' && c <= '9')){
			ungetc(c,fp);
			fscanf(fp,"%lf",&val);
			char buffer[32];
			sprintf(buffer, "%g", val);
			value += buffer;
			value += " ";
			printf("%4.1f", val);
		}
		else if( c=='(') st.push(c);
		else if( c== ')'){
			while(!st.empty()){
				op = st.top();
				st.pop();
				if(op == '(') break;
				else
				{
					printf("%c",op);
					value += " ";
					value += op ;
					value += " ";
				}
			}
		}

		else if(c =='+'|| c == '-' || c == '*' || c=='/'){
			while(!st.empty()){
				op=st.top();

				if(precedence(c)<=precedence(op)){
					printf("%c",op);
					value += " ";
					value += op;
					value += " ";
					st.pop();
				}
				else break;
			}
			st.push(c);
		}
		
	}
	while(!st.empty()){
		printf("%c",st.top());
		value += " ";
		value += st.top() ;
		value += " ";
		st.pop();
	}
	printf("\n");
	value += "\n";
	for(int index = 0 ; index < value.length() ; index++){
		fprintf(fp2, "%c", value[index]);
        }
	fclose(fp2);
	fp2 = fopen("temp.txt","r");
	printf("계산 결과 : %lf\n",calcPostfixExpr(fp2));
	fclose(fp2);
}

void main(){
	printf("수식 입력(Infix) = ");
	infix2Postfix();
	getchar();
	getchar();
}