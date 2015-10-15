// Program Design - COP 3514
// Matthew Coplan
//
// This program calculates the voltage across the capacitor on the circuit between 0 and 1 in increments of 1/15
//
// voltage.c

#include <stdio.h>
#include <math.h>

#define RESISTANCE  3000    // Constants
#define CAPACITANCE .00005
#define VOLTS 10

int main(void)
{
	double voltage = 0;        // voltage of the capacitor at the current time
	double timeElapsed = 0;    // time elapsed of the capacitor
	double timeConstant = 0;   // time constant, t = R x C
	
	timeConstant = RESISTANCE * CAPACITANCE;  // equation for timeConstant

	printf("time(sec)\tvoltage\n");
	
	int i = 0;   // initalize the variable before loop

	for ( ; i < 16 ; i++) {                                                        // for loop for counting voltage at current time
		timeElapsed = (double) i / 15; 	                                       // convert time to increments of 1/15 between 0 and 1
		voltage =  VOLTS * ( 1 - ( exp (( -timeElapsed / timeConstant ))) );    // equation for voltage
		printf("%.2lf\t\t%.2lf\n", timeElapsed, voltage);                      // print
	}
	
	return 0;

}
