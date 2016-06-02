#include <stdio.h>
#define N 11

void ADD(int);
void SUB(int);
void MUL(int);

int i,j,ex=0, a=0; // i:숫자 개수 j:자릿수 ex:for문 탈출 a:숫자 개수
int p_num[N]={0}, dot_pos[N]={0}; // p_num:자리수 dot_pos;점의 자리수
char num[N][60]={0}, op[N-1]={0}, tmp=0; // num:정수부 op:연산자 tmp:임시저장
int result[N][60]={0};


int main(void)
{
	//수 입력받기

	for(i=1; i<N; i++)
	{
		for(j=1; j<60; j++)
		{
			tmp=getchar();

			if(48<=tmp && tmp<=57)
				num[i][j]=tmp-'0';
			else if(tmp=='.')
			{
				dot_pos[i]=j;
				j=j-1;
			}
			else if(tmp==' ')
			{
				op[i]=getchar();
				getchar();
				break;
			}
			else if(tmp=='\n')
			{
				a=i;
				ex=1;
				break;
			}
		}
		p_num[i]=j-1;

		if(ex)
			break;
	}


	//입력받은 수 뒤쪽으로 몰아 넣기

	for(i=1; i<=a; i++)
	{
		for(j=1; j<=p_num[i]; j++)
			num[i][50-p_num[i]+j]=num[i][j];
		for(j=1; j<=50-p_num[i]; j++)
			num[i][j]=0;
	}


	//계산하기

	for(i=1; i<=1; i++)
	{

		switch(op[i])
		{
			case'+':ADD(i);
					break;
			case'-':SUB(i);
					break;
			case'*':MUL(i);
					break;
			case'/':DIV;
					break;
					/*case'%': */
		}
	}
	i=1;


	//결과 출력하기

	for(j=1; j<60; j++)
	{
		if(result[i][j]!=0)
			for(; j<60; j++)
				printf("%d", result[i][j]);	
	}
	printf("\n");
}



// 덧셈
void ADD(int i)
{
	for(j=50; j>0; j--)
	{
		result[i][j]=(num[i][j]+num[i+1][j])%10;
		num[i][j-1]+=(num[i][j]+num[i+1][j])/10;
	}
}

// 뺄셈
void SUB(int i)
{
	int k=0;

	//두 수의 자릿수가 다를 때
	if(p_num[i]>p_num[i+1])
		for(j=50; j>0; j--)
		{
			result[i][j]=num[i][j]-num[i+1][j];
			if(result[i][j]<0)
			{
				result[i][j]+=10;
				num[i][j-1]-=1;
			}
		}
	else if(p_num[i]<p_num[i+1])
		for(j=50; j>0; j--)
		{
			result[i][j]=num[i+1][j]-num[i][j];
			if(result[i][j]<0)
			{
				result[i][j]+=10;
				num[i][j-1]-=1;
			}
		}
	else //두 수의 자릿수가 같을 때
	{
		for(j=50-p_num[i]+1; j<=50; j++) //각 자리마다 수 비교
		{
			if(num[i][j]>num[i+1][j])
			{
				for(j=50; j>0; j--)
				{
					result[i][j]=num[i][j]-num[i+1][j];
					if(result[i][j]<0)
					{
						result[i][j]+=10;
						num[i][j-1]-=1;
					}
				}

				break;
			}
			else if(num[i][j]<num[i+1][j])
			{
				for(j=50; j>0; j--)
				{
					result[i][j]=num[i+1][j]-num[i][j];
					if(result[i][j]<0)
					{
						result[i][j]+=10;
						num[i+1][j-1]-=1;
					}
				}
				printf("-");
				break;
			}
			else //두 수가 완전히 같은수라면 결과값은 '0'
			{
				k++;
				if(k==p_num[i])
				{
					for(j=1; j<=50; j++)
						result[i][j]=0;
					printf("0");
				}
				else
					;
			}

		}
	}
}

// 곱셈
void MUL(int i)
{
	int k;
	int h=0,g;
	int tmp_M[N][60]={0};

	for(k=50; k>50-p_num[i+1]; k--)
	{
		for(j=50; j>50-p_num[i]; j--)
		{
			h=num[i][j]*num[i+1][k];

			h+=tmp_M[i][j-(50-k)];

			tmp_M[i][j-(50-k)]=h%10;

			tmp_M[i][j-(50-k)-1]+=h/10;
		}
		for(j=k; j>0; j--)
		{
			result[i][j]+=tmp_M[i][j];
			tmp_M[i][j]=0;
		}
	}
	for(j=50; j>0; j--)
	{
		result[i][j-1]+=result[i][j]/10;
		result[i][j]=result[i][j]%10;
	}
}

// 나눗셈
void DIV(int i)
{















