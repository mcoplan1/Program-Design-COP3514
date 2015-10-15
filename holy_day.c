// Program Design COP 3541
// Matthew Coplan
//
// This program determines the day of the week homework will be due while considering
// the holy days on Friday, Saturday, and Sunday. Those three days must be re-assigned to
// the following Monday
//
// holy_day.c

#include <stdio.h>


int main(void)
{
	int dayEntered = 0; // Initialize variables, dayEntered -> user input
	int amountDays = 0; // amountDays -> amount of days till the homework is due

	printf("Enter todays day of the week: (0 for sunday, 1 for monday, ect.)\n"); // Grab information from user
	scanf("%d", &dayEntered);
	printf("How many days will this homework be assigned?:\n");
	scanf("%d", &amountDays);
	
	if ((dayEntered >= 0) && (dayEntered <= 6))                        // If/Else statement to determine the correct day
	{                                                                  // of the week after assigning amountDays 
	  	 dayEntered = (dayEntered + amountDays) % 7; 
	} else { 							   // else statement to sort out the values that
		 dayEntered = -1;                                          // are not between 0 and 6
 	}

	switch (dayEntered) {
	        case 6:                                                                                          
 	    		 amountDays = amountDays + 2;                                                             // Saturday
			 printf("The assignment will be due on Monday and will be due in %d days\n", amountDays); // Add 2 days for holy day 
		   	 break;
		case 5:	                                                            
		  	 amountDays = amountDays + 3;                                                             // Friday
		   	 printf("The assignment will be due on Monday and will be due in %d days\n", amountDays); // Add 3 days for holy day
		   	 break;
		case 4:                                                       
		  	 printf("The assignment will be due on Thursday and will be due in %d days\n", amountDays); // Thursday
		  	 break;  			                                                            // no extra days needed
		case 3:                                                     
		  	 printf("The assignment will be due on Wed and will be due in %d days\n", amountDays);      // Wed
		  	 break;                                                                                     // no extra days needed
		case 2:	                                                      
		  	 printf("The assignment will be due on Tuesday and will be due in %d days\n", amountDays);  // Tuesday 
		  	 break;	                                                                                    // no extra days needed
		case 1:	                                                      
		  	 printf("The assignment will be due on Monday and will be due in %d days\n", amountDays);   // Monday
	  	         break;                                                                                     // no extra days needed
		case 0:                                                                
		  	 amountDays = amountDays + 1;                                                               // Sunday
		  	 printf("The assignment will be due on Monday and will be due in %d days\n", amountDays);     // Add 1 day for holy day
		  	 break;
		default:
		  	 printf("The day must be between 0 and 6, Program aborted\n");                                // Error message
		  	 break;
	}
	return 0;
}
