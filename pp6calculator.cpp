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

void vectorlength()			//Function calculating vector length
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

void invariantmass()			//Creating invariant mass function
{
	double a, b, mtm1, mtm2, invariant, energy1, energy2, dotmtm;
	double p1[4], p2[4];						//Declaring arrays to store 3 momenta and mass
	bool error=0;
	for(int i=0;i<=1;++i){						//Taking inputs for both particles-looping over particle 1 and 2
		while(!error){						//Taking in mass declarations (0th component of arrays)
			std::cout<<"Please enter the mass of particle "<<i+1<<" in MeV\n";
			std::cin>>a;
			if(!std::cin){nonnumerror();}			//Error proofing
			else if(a<0){
				std::cout<<"Cannot have negative mass!!\n";	
			}
			else{error=1;}		
		}
		error=0;
		if(i==0){
			p1[0]=a;
			for(int j=0;j<=2;++j){		//Looping over iterator to take 1/2/3 component of momentum 
				while(!error){
					std::cout<<"Please enter component "<<j+1<<" of particle "<<i+1<<" in MeV\n";
					std::cin>>b;
					if(!std::cin){nonnumerror();}
					else{
						error=1;
						p1[j+1]=b;
						mtm1=mtm1 + (p1[j+1]*p1[j+1]);		//calculating momentum squared in order to calculate energy
					}
				}
				error=0;
			}
			energy1=(p1[0]*p1[0])+mtm1;		//Calculating energy
		}

		if(i==1){
			p2[0]=a;
			for(int j=0;j<=2;++j){
				while(!error){
					std::cout<<"Please enter component "<<j+1<<" of particle "<<i+1<<" in MeV\n";
					std::cin>>b;
					if(!std::cin){nonnumerror();}
					else{
						error=1;
						p2[j+1]=b;
						mtm2=mtm2 + (p2[j+1]*p2[j+1]);
					}
				}
				error=0;
			}
			energy2=(p2[0]*p2[0])+mtm2;		
		}
	
	}
	for(int ii=1;ii<=3;++ii){
		dotmtm=dotmtm+(p1[ii]*p2[ii]);  //Calculating the dot product of the 3 momenta of particles 1 and 2
	}
	invariant=sqrt((p1[0]*p1[0])+(p2[0]*p2[0])+2*((sqrt(energy1)*sqrt(energy2))-dotmtm)); //Calculating invariant mass
	std::cout<<"The invariant mass of these particles is "<<invariant<<" MeV\n";
}		 	
		
int main()
{
	double a,b,c;
        double d;
        bool error=0;
        int i=0;

	while(i==0){							//Generic while loop to allow user to quit program with specific input
	while (!error){ 						//While loop to check for various input errors 
	std::cout<<"Which operation would you like to perform on the numbers? Use the following notation\n1 = addition\n2 = subtraction\n3 = multiplication\n4 = division\n5 = Calculate x-axis intercept of a straight line\n6 = Find the roots of a quadratic equation\n7 = Find the length of a 3 or 4 vector\n8 = Find invariant mass of two particles\nType '9' to quit\n";

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
	error=0;

	if(d==9){							//Breaking loop if user has asked to quit
	std::cout<<"Goodbye!\n";
	break;
	}
	
	if(d<=4){				
		while(!error){			//Asking for input for standard algebraic functions
		std::cout<<"Please enter first number.\n";
		std::cin>>a;
		if(!std::cin){nonnumerror();}
		else {break;}
		}
		while(!error){
		std::cout<<"And the second...\n";
		std::cin>>b;
		if(!std::cin){nonnumerror();}
		else{break;}
		}
	
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
	}				//Calling various user requested functions	
	else if(d==5){
		xintercept();
	}
	else if(d==6){
		quadratic();
	}
	else if(d==7){
		vectorlength();
	}
	else if(d==8){
		invariantmass();
	}
	error=0;
	}
	return 0;
}
