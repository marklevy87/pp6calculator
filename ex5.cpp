#include <iostream>
#include <cmath>
#include <climits>

double multiplication(double a, double b)
{
	return a*b;
}

double addition(double a, double b)
{
	return a+b;
}

double subtraction(double a, double b)
{
	return a-b;
}

double division(double a, double b)
{
	return a/b;
}

double inputerrorcheck(double a)
{
	
int main()
{
	double a,b,c;
        double d;
        bool error=0;
        int i=0;

	while(i==0){
	while (!error){ 						//While loop to check for various input errors 
	std::cout<<"Which operation would you like to perform on the numbers? Use the following notation\n1 = addition\n2 = subtraction\n3 = multiplication\n4 = division\nType '5' to quit\n";

	std::cin>>d;

	if(!std::cin){
		std::cout<<"That is not one of the options!\n";		//Check for non numeric input
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
        else if((d>=6)||(d<=0)){					//Check for input that is not an option
		std::cout<<"This is not one of the options!\n";
	}
	else if(floor(d)!=d){						//Check for non integer input
		std::cout<<"This is not one of the options!\n";
	}
	else {error=1;}							//Clearing the error flag
	}


	if(d==5){							//Breaking loop if user has asked to quit
	std::cout<<"Goodbye!\n";
	break;
	}
		
	std::cout<<"Please enter first integer number.\n";
	std::cin>>a;
	std::cout<<"And the second...\n";
	std::cin>>b;

	if(d==1){
		c=addition(a,b);
	}
	else if (d==2){
		c=subtraction(a,b);
	}
	else if (d==3){
		c=multiplication(a,b);
	}
	else if (d==4){
		c=division(a,b);
	}

	std::cout<<"And your answer is\n"<<c<<std::endl;
	error=0;
	}
	return 0;
}
