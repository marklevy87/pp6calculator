#include <iostream>
#include <cmath>
#include <climits>

void nonnumerror()
{	
	std::cout<<"That is not one of the options!\n";		//Check for non numeric input
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}		

double multiplication(double a, double b)	//Creating mutliplication function
{
	return a*b;
}

double addition(double a, double b)		//Creating addition function
{
	return a+b;
}

double subtraction(double a, double b)		//Creating subtraction function
{
	return a-b;
}

double division(double a, double b)		//Creating division function
{
	while(b==0){
		std::cout<<"Cannot divide by zero!! Please enter a non-zero denominator\n";	//Error proofing against dividing by zero
		std::cin>>b;
	}
	return a/b;		
}

void xintercept()				//Creating x-intercept function
{
	double m, cons, x;
	bool error=0;

	while(!error){
	std::cout<<"For a line of the type y=mx+c, please enter your value for the gradient, m\n";
	std::cin>>m;

	if(!std::cin){nonnumerror();}			//Error checking	
	else{error=1;}
	}
	error=0;
	if (m==0){
		std::cout<<"A line with no coefficient in x does not cross the x-axis!\n";	//Generating output if there is no x-intercept
	}
	else{
		while(!error){
		std::cout<<"And your value of the constant c.\n";	//Taking y=mx+c inputs and generating solution using division function
		std::cin>>cons;
		if(!std::cin){nonnumerror();}				//Error checking
		else{error=1;}
		}
		cons=-1*cons;
		x=division(cons,m);
		std::cout<<"c="<<cons<<std::endl;
		std::cout<<"This line crosses the x axis at x="<<x<<std::endl;	//Solution printing
	}
}

void quadratic()		//Creating quadratic root finder function
{
	double a,b,c, surd;
	bool error=0;	
	
	while(!error){
	std::cout<<"For a quadratic of the type y =ax^2+bx+c, please enter a value for a\n";	//Accepting inputs and error checking
	std::cin>>a;
	if(!std::cin){nonnumerror();}
	else{error=1;}
	}
	error=0;
	while(!error){
	std::cout<<"And b\n";	
	std::cin>>b;
	if(!std::cin){nonnumerror();}
	else{error=1;}
	}
	error=0;
	while(!error){
	std::cout<<"And finally c\n";
	std::cin>>c;
	if(!std::cin){nonnumerror();}
	else{error=1;}
	}

	surd=(multiplication(b,b)-4*multiplication(a,c));
	
	if (surd>=0){
		double x1=division(-b+sqrt(surd),2*a);	//Using quadratic formula to solve the equation
		double x2=division(-b-sqrt(surd),2*a);
		std::cout<<"The first root of this equation is "<<x1<<std::endl;
		std::cout<<"The second root of this equation is "<<x2<<std::endl;
	}
	else{
		surd= -1*surd;					//Creating answer in the scenario where the roots are complex
		double x1=division(-b,2*a);
		double xi1=division(sqrt(surd),2*a);
		std::cout<<"The first root of this equation is "<<x1<<"+ "<<xi1<<"i"<<std::endl;
		std::cout<<"The second root of this equation is "<<x1<<"- "<<xi1<<"i"<<std::endl;
	} 
}

void vectorlength()
{	
	double a, vtype;
	bool error=0;
	
	while(!error){
	std::cout<<"Would you like to calculate the length of a three or four vector (type '3'' or '4')?\n";	//Option of 3/4 vector
	std::cin>>vtype;
	
	
	if(!std::cin){nonnumerror();}	
	else if ((vtype!=3)&&(vtype!=4)){
		std::cout<<"This is not an option! Please declare either a 3 or 4 vector\n";
		}
	else {error=1;}
	}
	
	error=0;								//Resetting error boolean
	double length = 0;								//defining length 
	if(vtype==3){								//Generating method of finding length for three vector
		for (int i=1; i<=vtype; ++i){					//Looping over given number to accept number of co-ordinates 
			while(!error){
			std::cout<<"Please enter co-ordinate "<<i<<std::endl;
			std::cin>>a;
			if(!std::cin){nonnumerror();}
			else{error=1;}
			}
			length=length+multiplication(a,a);			//Iterating to generate a total length squared
			error=0;
		}
		length =sqrt(length);
		std::cout<<"The length of your vector is "<<length<<std::endl;	//This is square rooter to give the length of three vector
	}
	else if(vtype==4){							//Generating method of finding length for four vector
		for(int i=1;i<=vtype; ++i){
			if(i==1){						//First specifying time-like component of four vector
				while(!error){
				std::cout<<"Please enter the time-like component of your four vector (co-ordinate 1)\n";
				std::cin>>a;
				if(!std::cin){nonnumerror();}
				else{error=1;}
				length=length+multiplication(a,a);
				}
				error=0;
			}
			else{
				while(!error){
				std::cout<<"Please enter co-ordinate "<<i<<std::endl;	//Then asking for space like components
				std::cin>>a;
				if(!std::cin){nonnumerror();}
				else{error=1;}
				length=length-multiplication(a,a);
			}	
			error=0;
			}
		}
		std::cout<<"The length (squared) of your four vector is "<<length<<std::endl;	//Leaving in terms of length squared
	}
}	


	
	
int main()
{
	double a,b,c;
        double d;
        bool error=0;
        int i=0;

	while(i==0){							//Generic while loop to allow user to quit program with specific input
	while (!error){ 						//While loop to check for various input errors 
	std::cout<<"Which operation would you like to perform on the numbers? Use the following notation\n1 = addition\n2 = subtraction\n3 = multiplication\n4 = division\n5 = Calculate x-axis intercept\n6 = Find the roots of a quadratic equation\n7 = Find the length of a 3 or 4 vector\n8 = Find invariant mass of two particles\nType '9' to quit\n";

	std::cin>>d;

	if(!std::cin){nonnumerror();}

        else if((d>=10)||(d<=0)){					//Check for input that is not an option
		std::cout<<"This is not one of the options!\n";
	}
	else if(floor(d)!=d){						//Check for non integer input
		std::cout<<"This is not one of the options!\n";
	}
	else {error=1;}							//Clearing the error flag
	}


	if(d==9){							//Breaking loop if user has asked to quit
	std::cout<<"Goodbye!\n";
	break;
	}
	
	if(d<=4){							//Asking for input for standard algebraic functions
		std::cout<<"Please enter first integer number.\n";
		std::cin>>a;
		std::cout<<"And the second...\n";
		std::cin>>b;
	
		if(d==1){						//This section calls on specific algebraic functions
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
	else if(d==5){
		xintercept();
	}
	else if(d==6){
		quadratic();
	}
	else if(d==7){
		vectorlength();
	}
	error=0;
	}
	return 0;
}
