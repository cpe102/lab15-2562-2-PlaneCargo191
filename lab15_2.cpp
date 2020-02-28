#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randData(double *,int,int);

void findColSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,result,N,M); 
	showData(result,1,M);
}

void randData(double *a, int n, int m)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			*a = (rand()%101)/100.00;
			a++;
		}
	}
}

void showData(double *b, int n, int m)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cout << *b << " ";
			b++;
		}
		cout << "\n";
	}
}

void findColSum(const double *c, double *d, int n, int m)
{
	double sum;
	for(int i; i<n*m; i++)
	{
		sum += *c;
		if((i+1)%n == 0)
		{
			*d = sum;
			sum = 0;
			c -= m*(n-1)-1;
			d++;
		}
		else
		{
			c += m;
		}
	}
}