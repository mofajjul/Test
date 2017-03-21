#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max_M 51
int Grid[max_M][max_M];
int M, N;

int checkVert(int i, int j)
{
	int k, count;
	count = 1;
	for (k = i - 1; k >= 0; k--)
	{
		if (Grid[i][j] == Grid[k][j])
		{
			count++;
		}
		else break;
	}
	//for downward
	for (k = i + 1; k < M ; k ++)
	{
		if (Grid[i][j] == Grid[k][j])
		{
			count++;
		}
		else break;
	}
	if (count == N)
	{
		return 1;
	}
	else return 0;

}
int checkHori(int i, int j)
{
	int k, count;
	count = 1;
	for (k = j - 1; k >= 0; k--)
	{
		if (Grid[i][j] == Grid[i][k])
		{
			count++;
		}
		else break;
	}
	//for right

	for (k = j + 1; k < M ; k++)
	{
		if (Grid[i][j] == Grid[i][k])
		{
			count++;
		}
		else break;
	}
	if (count == N)
	{
		return 1;
	}
	else return 0;
}

int checkLeftDiag(int i, int j)
{
	int k, count;
	count = 1;
	for (k = 1; i - k >= 0 && j - k >= 0; k++)
	{
		if (Grid[i][j] == Grid[i - k][j - k])
		{
			count++;
		}
		else break;
	}
	for (k = 1; i + k < M && j + k < M; k++)
	{
		if (Grid[i][j] == Grid[i + k][j + k])
		{
			count++;
		}
		else break;
	}
	if (count==N)
	{
		return 1;

	}
	else return 0;
}
int checkRightDiag(int i, int j)
{
	int k, count;
	count = 1;
	for (k = 1; i - k >= 0 && j + k < M; k++)
	{
		if (Grid[i][j] == Grid[i - k][j + k])
		{
			count++;
		}
		else break;
	}
	for (k = 1; i + k < M && j - k >= 0; k++)
	{
		if (Grid[i][j] == Grid[i + k][j - k])
		{
			count++;
		}
		else return 0;
	}
	if (count==N)
	{
		return 1;

	}
	else return 0;
}
void Input()
{
	int i, j;
	scanf("%d%d", &M, &N);
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &Grid[i][j]);
		}
	}
}
void Solve()
{
	int V, H, LD, RD;
	int i, j;
	//for A
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			V = checkVert(i, j);
			H = checkHori(i, j);
			LD = checkLeftDiag(i, j);
			RD = checkRightDiag(i, j);
			if (V == 1 || H == 1 || LD == 1 || RD == 1)
			{
				if (Grid[i][j] == 1)
				{
					printf("%d\n",Grid[i][j]);
					return;
				}
			}
		}
	}
	//for B
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (Grid[i][j] == 0)
			{
				Grid[i][j] = 2;
				V = checkVert(i, j);
				H = checkHori(i, j);
				LD = checkLeftDiag(i, j);
				RD = checkRightDiag(i, j);
				if (V == 1 || H == 1 || LD == 1 || RD == 1)
				{
					printf("%d\n", Grid[i][j]);
					return;
				}
				Grid[i][j] = 0;
			}
		}
	}
	printf("-1\n");
}
int main()
{

	int t_case;
	freopen("input.txt", "r", stdin);
	scanf("%d", &t_case);
	int  T;
	for (T = 1; T <= t_case; T++)
	{
		printf("#%d ", T);
		Input();
		Solve();


	}
	return 0;
}
