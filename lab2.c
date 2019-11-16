#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
void leap_year(int year)
	{
	  if(( year%400==0)||(year%4==0&&year%100!=0))
		{
		  printf("leap year \n");
		}
	  else
		{
		  printf("not leap year\n");
		}

	
	}
bool Luhn(char creditcard[])
	{
	  int s1=0;
	  int s2=0;
	  int count=1;
	  for(int i=strlen(creditcard)-1;i>=0;i--)
		{  
		  int digit=atoi(creditcard[i]);
		  if(count%2!=0)
			{
		 	  s1=s1+digit;
			  count++;
			}			  
		  else
			{
			  int mult=digit*2;
			  s2=s2+(mult/10)%10+mult%10;
			  count++;
			}
		}

		return ((s1+s2)%10)==0;


		
	}
int main( int argcount, char*argvalue[])
	{   
	  if(argcount<2)
		{
		   fprintf(stderr,"Usage: %s value1 [value2 ...]\n", argvalue[0]);
		   exit(EXIT_FAILURE);     
		}
	  else
		{
		  for(int i=1; i<argcount;i++)
			{
  			  if(Luhn(argvalue[i]))
				{
				  printf("yes");
				}
			  else
				{
				   printf("no");
				}
			} 
		}		   
		return 0;
	}
