#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
void inicio(double *un, double *uv, double dt, double dx, int n, double c);
void cambio(double *un, double *uv, double *up , int n);
void evolucion(double *un, double *uv, double *up, double dt, double dx, int n, double c);

void inicio(double *un, double *uv, double dt, double dx, int n, double c)
{
	double a = pow(c*dt/dx,2);
	uv[0] = 0.0;
	uv[n-1] = 0.0;
	double x = 0.0;
	for (int i = 1; i < n-1; i ++)
	{
		x += i*dx;
		uv[i] = exp(-pow(x, 2));
	}
	for (int i = 0; i < n; i ++)
	{
		un[i] = a*(uv[i+1]+uv[i-1])/2 + (1-a)*uv[i];
		up[i] = un[i];	
	}
}

void cambio (double *un, double *uv, double *up, int n)
{
	for(int i = 0; i < n; i++)
	{
		uv[i] = up[i];
		up[i] = un[i];
	}
}

void evolucion(double *un, double *uv, double *up, double dt, double dx, int n, double c)
{
	double a = pow((c*dt/dx),2);
	for(int i = 0; i < n; i++)
	{
		un[i] = a*(up[i+1]+up[i-1]) + 2*(1-a)*up[i] - uv[i];
	}
}



int main()
{
	double x_max = 1.0;
	double dt = 0.001;
	double dx = 0.001;
	double c = 1.0;
	int n = x_max/dx;
	double *un = new double [n];
	double *up = new double [n];
	double *uv = new double [n];
	inicio(un, uv, dt, dx, n, c);
	cambio(un, uv, up, n);
	double x = 0;
	for (int i =0; i <n; i++ )
	{
		x += i*dx;
		cout << un[i] << " "<< x << endl;  
	}  

	return 0;
}
