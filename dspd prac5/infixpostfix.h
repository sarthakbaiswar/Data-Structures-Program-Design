#include"stack2.h"
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define L -5
#define R -6
#define O -7
#define d -8

//POPULATE 
void populate(char vararr[])
{
    int i;
	for(i=0;i<=50;i++)
		vararr[i]='#';
	return;
}

//TOKEN EXISTENCE CHECK

int is_ExistToken(char vararr[], char token)
{
    int i;
	for(i=0;i<=50;i++)
		{
		    if(vararr[i]==token)
			    return 1;
		}
	return 0;
}
	

//CREATE VARIABLE TABLE
void CreateVarTable(char vararr[], char rpn[])
{
	populate(vararr);
	int i=0,j=0;
	int t;
	char token;
	while(rpn[j]!='\0')
	{
		if(rpn[j] >= 'A' && rpn[j] <= 'Z')
		{
			token=rpn[j];//take character from rpn and save in token
		
		    t = is_ExistToken(vararr,token);	
				if(t==0)
				{   vararr[i]=token;//put token in var table 
					i++;
				}
		}
		j++;
	}
	vararr[i]='\0';
}
		
//VALIDATION OF EXPRESSION
void validate(char infix[])
{
 	char ch1,ch2,ch;
 	int i=0;
 	char array[50];
 	int k=0;
 	
 	while(infix[i]!='\0')
 	{
 		ch=infix[0];
 		
 		if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='^')
 		{
 			printf("\nInvalid Expression....%d\n",i);
 			exit(0);
 		}
 		
		else
		{
 			ch1=infix[i];
 			ch2=infix[i+1];
 			
 			if(	(ch1 >='A' && ch1 <= 'Z') && (ch2 >='A' && ch2 <= 'Z'))	{
 				printf("\nInvalid Expression........%d\n",i);
 				exit(0);
 			}
 			else 
 			{
 			if((ch1=='+' || ch1=='-' || ch1=='*' || ch1=='/' || ch1=='%' || ch1=='^') && (ch2=='+' || ch2=='-' || ch2=='*' || ch2=='/' || ch2=='%' || ch2=='^'))
 					{
 						printf("\nInvalid Expression..........%d\n",i);
 						exit(0);
 					}
 		    }
 		}
 	i++;
 	}
 	int j=0;
 	ch=infix[j+1];
	if(ch=='\0')
	{
		printf("\nInvalid Expression.........%d\n",i);
		exit(0);
	}
	
	j=0;
	int count1=0,count2=0;
	char ch4='(',ch5=')';
	while(infix[j]!='\0')
	{
	        if(infix[j]==ch4)
	            count1++;
	        if(infix[j]==ch5)
	            count2++;
	  j++;
    }
    if(count1!=count2)
    {
        printf("Invalid expression\n");
        exit(0);
    }
	        
	return;
}

//TAKE VALUES FOR VARIABLES AND DISPLAYING THEM

void menu(char vararr[],char rpn[],int valarr[])
{
    int i=0,j=0,k=0;
	CreateVarTable(vararr,rpn);
	
	while(vararr[i]!='\0')
	{
		printf("Value for %c: ",vararr[i]);
		scanf("%d",&valarr[i]);
		i++;
	}
	printf("VarTable\tValTable\n");
	for(k=0,j=0;k<i;k++,j++)
	printf("%c\t\t%d\n",vararr[j],valarr[k]);

}

//PRIORITY OF OPERATORS

int priority(char ch)
{
	switch (ch)
	{
		case '#' : return 0;
		
		case '(' : return 0;
		
		case '+' : return 1;
		
		case '-' : return 1;
	
		case '%' : return 2;
		
		case '*' : return 3;
		
		case '/' : return 3;
		
		case '^' : return 4;
		
	}
}

//CREATION OF STACK FOR EVALUATION
int CreateStack(char vararr[],int valarr[],int stack[],int top)
{
	int j;
	for(j=0;vararr[j]!='\0';j++)
	{
	    if( vararr[j] >='A' && vararr[j] <= 'Z')
		    top=push(stack,top,valarr[j]);
	}
	
	display(stack,top);
	return top;
}
	
//EVALAUTE OPERATION

int evaluateop(char ch,int op1,int op2)
{
	int c=1;
	switch(ch)
	{
	
	    case '#':	
				    break;
				
	    case '+':	return op1+op2;
				    break;
				
	    case '-':	return op1-op2;
				    break;
				
	    case '*':	return op1*op2;
				    break;
				
	    case '/':	if(op2==0)
	                {
					    printf("invalid expression\n");
					    exit(0);
				    }
				    return op1/op2;
				    break;
				
	    case '%':	if(op2==0)
	                {
					    printf("invalid expression\n");
					    exit(0);
				    }
				    return op1%op2;
				    break;
				
	    case '^':	while(op2!=0)
	                {
					    c=c*op1;
					    op2--;
				    }
				    return c;
				    break;
				
	    default:    printf("Invalid operator in expression\n");
				    break;
	}
	
return 0;
}


//EVALUATE STACK
int EvaluateStack(char infix[],char vararr[],char rpn[],int valarr[],int stack[],int top,int result)
{
	int j=0,i=0;
	int z1,z2;
	char ch;
	while(rpn[j]!='\0')
	{
		ch=rpn[j];
			if( ch>='A' && ch <= 'Z')
			{
				int count=0;
				while(ch!=vararr[count])
				{
					count++;
				}
				top=push(stack,top,valarr[count]);
				
			}
		
			if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='^')
			{
				top=pop(stack,top,&z2);
				top=pop(stack,top,&z1);
				result=evaluateop(ch,z1,z2);
				top=push(stack,top,result);
				
			}
	
		j++;
		
	}
	printf("Infix expression is:%s\n\n",infix);
	
    printf("Postfix expression is:%s\n\n",rpn);
	
	printf("Answer is :%d\n\n",result);
	return top;
}

//PUSH
int pushExp(char postfix[],char symbol,int TOP)
{
	TOP+=1;
	postfix[TOP]=symbol;
	return TOP;
}

//POP
int popExp(char postfix[],int TOP,char *symbol){
	if(TOP==-1)
	{
		printf("stack is empty \n");
		exit(0);
	}
	
	*symbol=postfix[TOP];
	TOP=TOP-1;
	
	return TOP;
}


int fun(char ch)
{
	switch(ch)
	{
		case '(':return L;
	
		case ')':return R;
		
		case '+':
		case '-':
		case '*':
		case '/':
		case '^': 
		case '%':return O;
		
		default :return d;
	}
	
}

//Infix to Postfix Conversion function

void InfixtoPostfix(char infix[],char postfix[],char final[],int TOP,int p)
{
	int i=0,j=0,len;
	int pre1,pre2;
	char c,c1,c2,g;
	int charac;
	while(infix[i]!='\0')
	{
		charac=fun(infix[i]);
		
		switch(charac){
			case L :  TOP=pushExp(postfix,infix[i],TOP);
			          for(int i=TOP;i>=0;i--)
			          {
			                if(i==TOP)
			                    printf("\t\t");
			                printf(" %c", postfix[i]);
			          }
			          printf("\n");
					  break;
						
			case R :  do
			         {
						TOP=popExp(postfix,TOP,&c);
						for(int i=TOP;i>=0;i--)
			            {
			                if(i==TOP)
			                    printf("\t\t");
			                printf(" %c", postfix[i]);
			            }
			            printf("\n");
						final[p]=c;
						len=strlen(final);
						for(int i=0;i<len;i++)
			            {
			                printf("%c",final[i]);
			                if(i==len-1)
			                printf("\t\t");
			            }
			          printf("\n");
						p++;
				     }while(postfix[TOP]!='(');
				     
					 TOP=popExp(postfix,TOP,&g);
					 for(int i=TOP;i>=0;i--)
			          {
			                if(i==TOP)
			                    printf("\t\t");
			                printf(" %c", postfix[i]);
			          }
			          printf("\n");
					 break;
						
			case d : final[p]=infix[i];
					 p++;
					 len=strlen(final);
			            for(int i=0;i<len;i++)
			            {
							    printf("%c",final[i]);
							    if(i==len-1)
							    printf("\t\t");
					    }
						printf("\n");
					 break;
			
			case O : pre1=priority(infix[i]);
					 pre2=priority(postfix[TOP]);
					 while(pre1<=pre2)
					 {
							TOP=popExp(postfix,TOP,&c1);
							for(int i=TOP;i>=0;i--)
							{
							 if(i==TOP)
						        printf("\t\t");
							    printf("  %c",postfix[i]);
							}
							printf("\n");

							final[p]=c1;
							
							len=strlen(final);
							for(int i=0;i<len;i++)
							{
							    printf("%c",final[i]);
							    if(i==len-1)
							    printf("\t\t");
							}
							printf("\n");

							p++;
							pre2=priority(postfix[TOP]);
							
					 }
						
				    TOP=pushExp(postfix,infix[i],TOP);
				    for(int i=TOP;i>=0;i--)
				    {
						if(i==TOP)
						        printf("\t\t");
						        	printf("  %c",postfix[i]);
					}
						printf("\n");
							

				    break;
		}
		i++;
	}
	
	while(TOP!=-1 && postfix[TOP]!='#')
	{
		TOP=popExp(postfix,TOP,&c2);
		final[p]=c2;
		p++;
	}
	
	len=strlen(final);
	for(int i=0;i<len;i++){
        printf("%c",final[i]);
        if(i==len-1)
        printf("\t\t");
    } 
     
	printf("\n");

	final[p]='\0';
	printf("Infix expression is:%s\n",infix);
	
    printf("Postfix expression is:%s\n",final);
}
