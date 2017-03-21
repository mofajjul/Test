#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int b[11],a[11];
int tempa[11];
int temp1[11] = { 0 };
int Ci[11], Di[11];
int numOfdigit = 0;
int N;
int bi[11];
int visited[11] = {0};
int count;

int num = 0;
void makeDigitA(int n)
{
	int k = 0;
	while (n>0)
	{
		a[k]= n % 10;
		n = n / 10;
		k++;
	}
}
void makeDigitB(int n)
{
	int k = 0;
	while (n> 0)
	{
		b[k] = n % 10;
		n = n / 10;
		k++;
	}
}
int checkCi(int ci)
{
	/*count = 0;
	int j, l, m;
	for (j = 0; j < 5; j++)
	{
		if (a[j] == b[j])
		{
			count++;
			a[j] = 0;
			b[j] = 0;
			num++;
		}
	}
	int check = 0;
	for (j = 0; j < 5; j++)
	{
		if (a[j] == 0)
		{
			continue;
		}
		a[check] = a[j];
		check++;
	}
	int check1 = 0;
	for (j = 0; j < 5; j++)
	{
		if (b[j] == 0)
		{
			continue;
		}
		b[check1] = b[j];
		check1++;
	}
	if (count == ci)
	{
		return 1;
	}
	 return 0;*/


	int i, j = 0;
	int counter = 0;
	for (i = 0; i < 5; i++)
	{
		if (a[i] == b[i])
		{
			counter++;
			continue;
		}
		tempa[j] = a[i];
		b[j] = b[i];
		j++;
	}
	numOfdigit = j;
	if (counter == ci)
		return 1;
	return 0;
}
int checkDi(int di)
{
	/*int count1 = 0;
	int j, l;

	for (j = 0; j < 5 - num; j++)
	{
		for (l = 0; l < 5 - num; l++)
		{
			if (a[j] == b[l] && temp1[a[j]] == 0 && temp1[b[l]] == 0)
			{
				count1++;
				temp1[a[j]] = 1;
				temp1[b[l]] = 1;
			}
		}
	}
	if (count1==di)
	{
		return 1;
	}
	return 0;*/
	int i, j, counter = 0;
	for (i = 0; i < numOfdigit; i++)
	{
		for (j = 0; j < numOfdigit; j++)
		{
			if (tempa[i] == b[j] && visited[b[j]] == 0 && visited[tempa[i]]==0){
				counter++;
				visited[b[j]] = 1;
				visited[tempa[i]] = 1;
			}
		}
	}
	for (i = 0; i < 11; i++)
		visited[i] = 0;
	if (counter == di){
		return 1;
	}
	return 0;
}

void randomGen()
{
	int res, res1, res2;
	int i,a;
	int counter = 0;
	//printf("Hello");
	for (a = 10000; a<= 99999; a++)
	{
		makeDigitA(a);
		for (i = 0; i < N; i++)
		{
			makeDigitB(bi[i]);
			res = checkCi(Ci[i]);
			res1 = checkDi(Di[i]);
			if (res == 0 || res1 == 0) break;
		}
		if (res == 1 && res1 == 1){
			counter++;
		}
	}
	printf("%d\n",counter);

}
void readCase(){
	scanf("%d",&N);
	int i;
	for (i = 0; i < N; i++){
		scanf("%d%d%d",&bi[i],&Ci[i],&Di[i]);
	}
}
void solveCase(){
	int ci, di, counter = 0;
	int i, a;
	for (a = 10000; a <= 99999; a++){
		makeDigitA(a);
		for (i = 0; i < N; i++){
			makeDigitB(bi[i]);
			ci = checkCi(Ci[i]);
			di = checkDi(Di[i]);
			if (di == 0 || ci == 0){
				break;
			}
		}
		if (di == 1 && ci == 1){
			counter++;
		}
	}
	printf("%d\n",counter);
}
int main()
{
	int T, t_case;
	int bi,i;
	freopen("input.txt","r",stdin);
	scanf("%d", &t_case);
	for (T = 1; T <= t_case; T++)
	{
		printf("#%d ", T);
		readCase();
		randomGen();
		//solveCase();


	}
	return 0;
}
