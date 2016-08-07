*/
//equation solutions
//D > 0 - two roots x1, x2
//D == 0 - two same roots x1 = x2
//D < 0 - there is no root -INF, -INF
// INF, INF - infinity number of roots
// x, -INF - one root

#include <iostream>
#include <limits>
#include <math.h>
#include <float.h>


struct Pair
{
	double first;
	double second;
};

void eq_solution( double a, double b, double c, Pair &root )
{
	double inf = std::numeric_limits<double>::infinity();
	
	double D = 0.0;						//discriminant
	double eps = 0.000001;				//epsilon. if mod(number) < epsilon - number = 0 
	double x1 = 0.0, x2 = 0.0;			//solutions
	//root->first = 0;
	//root->second = 0;

	if ( a == 0 && b == 0 && c == 0 )
	{
		root.first = inf;
		root.second = inf;
		return;
	}

	if ( a == 0 && b == 0 && c != 0 )
	{
		root.first = -inf;
		root.second = -inf;
		return;
	}

	if ( ( a != 0 && b == 0 && c == 0 ) )
	{
		root.first = 0.0;
		root.second = 0.0;
		return;
	}

		if (( a == 0 && b != 0 && c == 0 ))
	{
		root.first = 0.0;
		root.second = -inf;
		return;
	}



	if (a != 0)
	{
		D = b*b - 4*a*c;
		if ( D > 0)
		{
			root.first = (-b + sqrt(D))/2/a;
	 		root.second = (-b - sqrt(D))/2/a;
		}
		else
		{
			if( abs(D) < eps )
				root.first = root.second = -b/2/a;
			else 
				root.first = root.second = -inf;

		}
	}
	else
	{	
		root.first = -c/b;
		root.second = -inf;
	}

return;
}
void test( );

int main()
{				
	test();
	return 0;
}

void test( )
{
	Pair root;
    root.first = 0; root.second = 0;
    
	printf("Coefficients a, b, c: 0.0, 0.0, 0.0\n" );
	eq_solution(0.0, 0.0, 0.0, root );
	printf("Roots: %f, %f\n",root.first, root.second);
	printf("Coefficients a, b, c: 0.0, 0.0, 1.0\n" );
	eq_solution(0.0, 0.0, 1.0, root);
	printf("Roots: %f, %f\n",root.first, root.second);
	printf("Coefficients a, b, c: 2.0, 0.0, 0.0\n" );
	eq_solution(2.0, 0.0, 0.0, root);
	printf("Roots: %f, %f\n",root.first, root.second);
	printf("Coefficients a, b, c: 0.0, 4.0, 0.0\n" );
	eq_solution(0.0, 4.0, 0.0, root);
	printf("Roots: %f, %f\n",root.first, root.second);
	printf("Coefficients a, b, c: 1.0, 2.0, -3.0. D > 0\n" );
	eq_solution(1.0, 2.0, -3.0, root);
	printf("Roots: %f, %f\n",root.first, root.second);
	printf("Coefficients a, b, c: 1.0, 2.0, 1.0. D = 0\n" );
	eq_solution(1.0, 2.0, 1.0, root);
	printf("Roots: %f, %f\n",root.first, root.second);
	printf("Coefficients a, b, c: 2.0, 3.0, 4.0. D < 0\n" );
	eq_solution(2.0, 3.0, 4.0, root); 
	printf("Roots: %f, %f\n",root.first, root.second);
	
}