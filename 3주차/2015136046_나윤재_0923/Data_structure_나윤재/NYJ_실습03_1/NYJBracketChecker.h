#include<stack>
using namespace std;
class NYJBracketChecker{

public:
	bool CheckMatching(char* filename){
		FILE *fp = fopen(filename,"r");

		if(fp==NULL)
			error("Error: ���� �������� �ʽ��ϴ�.\n");

		int nLine = 1;
		int nChar = 0;
		NYJArrayStack stack;
		char ch;

		while((ch = getc(fp)) != EOF){
			if( ch== '\n')nLine++;
			nChar++;
			if(ch=='[' || ch=='(' || ch=='{')
				stack.push(ch);
			else if(ch ==']' || ch ==')' || ch =='}' ){
				int prev = stack.pop();
				if((ch == ']'&& prev!='[')
					||(ch == ')' &&prev!='(')
					||(ch == '}' &&prev!='{'))break;
			}
		}



		fclose(fp);
		printf("[%s] ���� �˻���:\n",filename);
		if(!stack.isEmpty())
			printf("Error: �����߰�!(���μ�=%d, ���ڼ�=%d)\n\n",nLine,nChar);
		else
			printf(" OK: ��ȣ�ݱ�����!(���μ�=%d, ���ڼ�=%d)\n\n",nLine,nChar);
		return stack.isEmpty();


	}



	bool CheckMatching2(char* filename){

		stack<char> stack;

		bool mDoubleQuoteFlag = false;
		bool mIsSingleQuote =false;
		bool mIsDoubleQuote =false;
		bool mIsBackSlash = false;
		bool mIsSimpleComment =false;
		bool mIsSpecificComment = false;
		bool mIsSlash = false;
		bool mIsEscape = false;
		int nLine = 1;
		int nChar = 0;
		int prev= 0;
		int mBackSlash = 92;
		int mSlash = 47;
		int mDoubleQuote = 34;
		int mSingleQuote = 39;
		char ch;


		FILE *fp = fopen(filename,"r");

		if(fp==NULL)
			error("Error: ���� �������� �ʽ��ϴ�.\n");


		while((ch=getc(fp))!=EOF){

			if(ch =='\n') nLine++;
			nChar++;

			// ���ڿ� �߿� '\\' , '\"' , '\''  ���ڿ� �� �˻��ϰ� flag�� ����
			if(ch == mBackSlash) mIsBackSlash = true;
			else mIsBackSlash = false;
			if(ch == mDoubleQuote) mIsDoubleQuote = true;
			else mIsDoubleQuote = false;
			if(ch == mSingleQuote) mIsSingleQuote = true;
			else mIsSingleQuote = false;
			if(ch == mBackSlash) { mIsEscape = true;}
			if(ch == mSlash)  mIsSlash = true;
			else mIsSlash = false;


			// Escape Sequence �˻縦 ���ش�.
			if(mIsEscape == true)
			{   ch=getc(fp);
			if(ch=='a' || 'b' || 'f' || 'n' || 'r' || 't' || 'v' || mBackSlash || mDoubleQuote || mSingleQuote){
				mIsEscape = false;
				continue;
			}
			else{
				mIsEscape = true;
				break;
			}

			}


			/* ���� '/' �� �Է� �޾����� �˻縦 ���ش�.
			 * //�ϰ�쿡�� mIsSimpleComment �ּ����� ����
			 *  �ּ�ó��
			 */ 
			if(mIsSlash && !mIsSimpleComment)
			{ 
				ch=getc(fp);
				if(ch==mSlash){
					if(!stack.empty() && (stack.top() != mDoubleQuote)){
						mIsSimpleComment = true;
						mIsSlash = false;
						continue;
					}
					else if(stack.empty()){
						mIsSimpleComment = true;
						continue;

					}
				}
				else if(ch == '*'){
					mIsSpecificComment = true;
					mIsSlash = false;
					stack.push(ch);
					continue;
				}
				else
				{	if(!stack.empty()&& (stack.top() == mSingleQuote))
				{mIsSlash =false;
				if(ch == mSingleQuote)
					mIsSingleQuote = true;
				}
				if(!stack.empty()&& (stack.top() == mDoubleQuote))
				{mIsSlash =false;
				if(ch == mDoubleQuote)
					mIsDoubleQuote = true;
				}
				


				}
			}


			// ���� �ּ��� ���
			if(mIsSimpleComment)
			{
				if(ch != '\n') continue;
				else
				{
					mIsSimpleComment = false;
					continue;
				}
			}

			/*
			 * ���� �ּ��� ���
			 */
			if(mIsSpecificComment || (!stack.empty() && stack.top() == '*'))
			{
				if(ch== '*')
				{
					ch=getc(fp);
					if(ch =='/')
					{
						mIsSpecificComment = false;
						stack.pop();
						continue;
					}
					else
						continue;
				}
				else continue;

			}










			// ū ����ǥ �϶�
			if( !stack.empty() && (stack.top() == ch) && (ch == mDoubleQuote))
			{stack.pop(); continue;
			}	
			if( !stack.empty() && stack.top() == mDoubleQuote) continue;
			if(ch == mDoubleQuote){stack.push(ch); continue; }

			// ���� ����ǥ �϶�
			if( !stack.empty() && (stack.top() != mSingleQuote) && mIsSingleQuote){
				stack.push(ch); continue;}
			else if(stack.empty() && mIsSingleQuote) 
			{
				stack.push(ch); continue;
			}
			if( !stack.empty() && (stack.top() == mSingleQuote) && !mIsSingleQuote){
				continue;
			}

			if( !stack.empty() && (stack.top() == mSingleQuote) && mIsSingleQuote){
				stack.pop(); continue;
			}







			/*
			 * ��ȣ ¦ ó��
			 */
			if(stack.empty())
			{	if(ch == '(' || ch == '{' || ch == '[')
			{stack.push(ch); continue;}
			if(ch == ')' || ch == '}' || ch == ']'){
				{stack.push(ch); break;}
			}

			}
			else if(!stack.empty() && (stack.top() != mDoubleQuote) && (stack.top() !=  mSingleQuote)){
				if(ch == '(' || ch == '{' || ch == '[')
				{stack.push(ch);
				continue;
				}
				if(!stack.empty()&& (ch == ')' || ch == ']' || ch == '}')){
					if(stack.top() == '(' && ch == ')'){ stack.pop(); continue;}
					if(stack.top() == '[' && ch == ']'){ stack.pop(); continue;}
					if(stack.top() == '{' && ch == '}') { stack.pop(); continue;}
					else break;
				}
			}
		}


		fclose(fp);

		printf("[%s] ���� �˻���:\n",filename);
		if(!stack.empty()){
			printf("Error: ���ڿ� : %c �����߰�!(���μ�=%d, ���ڼ�=%d)\n\n",stack.top(),nLine,nChar);
		}
		else
			if(!mIsSpecificComment)
				printf(" OK: ��ȣ�ݱ�����!(���μ�=%d, ���ڼ�=%d)\n\n",nLine,nChar);
			else
				printf("Error : �ּ�ó�� ����");
		return stack.empty();

	}



};