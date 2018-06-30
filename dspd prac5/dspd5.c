#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"infixpostfix.h"	

int main()
{
	int i=0,j=0,top=-1,result,TOP=-1,p=0;
	char vararr[50]; 
	int valarr[50];
	int stack[50]; 
	char infix[50];
	char postfix[50];
	char final[50]; 
	
	postfix[0]='#';
	TOP+=1;

	
	
	printf("Enter the infix expression\n");
	scanf("%[^\n]s",infix);
	
	int cont;
	int choice;
		
do{
	

	printf("1.Validity of expression\t2.Postfix Expression\t3.Evaluation\n");
	printf("enter the choice:");
	scanf("%d",&choice);
	switch(choice)
	{
	
	    case 1:  validate(infix);
	             printf("Expression is Valid\n");
	             break;
	    
	    case 2:  printf("------------------\n\n");
	             printf("Buffer\t\tOperatorStack\n");
	             InfixtoPostfix(infix,postfix,final,TOP,p);
	             break;
		
	    case 3:  InfixtoPostfix(infix,postfix,final,TOP,p);
	             menu(vararr,final,valarr);
                 top=EvaluateStack(infix,vararr,final,valarr,stack,TOP,result);
	             break;
	}
	printf("Do you want to continue?\t");
	scanf("%d",&cont);
	
}while(cont!=0);
		
	return 0;
}
/*
EXECUTION TRIAL:

Enter the infix expression
A+B-(C-D)*E/F
1.Validity of expression	2.Postfix Expression	3.Evaluation
enter the choice:1
Expression is Valid
Do you want to continue?	2
1.Validity of expression	2.Postfix Expression	3.Evaluation
enter the choice:2
------------------

Buffer		OperatorStack
A		
		  +  #
AB		
		  #
AB+		
		  -  #
		 ( - #
AB+C		
		  -  (  -  #
AB+CD		
		 ( - #
AB+CD-		
		 - #
		  *  -  #
AB+CD-E		
		  -  #
AB+CD-E*]@		
		  /  -  #
AB+CD-E*F@		
AB+CD-E*F/-		
Infix expression is:A+B-(C-D)*E/F
Postfix expression is:AB+CD-E*F/-
Do you want to continue?	1
1.Validity of expression	2.Postfix Expression	3.Evaluation
enter the choice:3
AB+CD-E*F/-		
		  +  #
AB+CD-E*F/-		
		  #
AB+CD-E*F/-		
		  -  #
		 ( - #
AB+CD-E*F/-		
		  -  (  -  #
AB+CD-E*F/-		
		 ( - #
AB+CD-E*F/-		
		 - #
		  *  -  #
AB+CD-E*F/-		
		  -  #
AB+CD-E*F/-		
		  /  -  #
AB+CD-E*F/-		
AB+CD-E*F/-		
Infix expression is:A+B-(C-D)*E/F
Postfix expression is:AB+CD-E*F/-
Value for A: 1
Value for B: 2
Value for C: 4
Value for D: 1
Value for E: 3
Value for F: 1
VarTable	ValTable
A		1
B		2
C		4
D		1
E		3
F		1
Infix expression is:A+B-(C-D)*E/F

Postfix expression is:AB+CD-E*F/-

Answer is :-6

Do you want to continue?	0
EXIT
*/


