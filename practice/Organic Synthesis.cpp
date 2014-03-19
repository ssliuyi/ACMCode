
/*--------------------------------------------------- -----------------------  

File: synthesis.c  

Description: Provides a program that shows the list of  conversions  for synthesising one compound starting from  another.  

-------------------------------------------------------------------------------*/  

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>  
#include <string.h>

/* The following matrix defines how compounds (labelled  A to T) can be synthesised  to other compounds.  The first letter in each row is  

a starting compound, and  each subsequent letter gives the list of compound to  which this starting   compound can be synthesised.  So the string "OIJN"  

indicates that compound O can  be converted to componds I, J, or N. Note that compounds  that cannot be synthesised  

   to any other compound do not have a corresponding  string in the matrix.  */  


#define MAXSTRING 10  // maximum length of the synthesis  string.  
char synthesisMatrix[][MAXSTRING] =  
{  
     "BAH",  
     "DCI",  
     "EJ",  
     "FK",  
     "GFLM",  
     "HBDG",  
     "ICJ",  
     "JEO",  
     "KFL",  
     "LF",  
     "MQ",  
     "NJ",  
     "OIJN",  
     "QMP",  
     "RQS",  
     "SMT",  
     ""  
};  // Note that last entry is the empty string, which  means that the last row can be   

    // detected when the first character in the row is  the '\0' (nul) character. This  

    // means that is is not necessary to know the number  of rows in the matrix.  

      

// Some definitions  
#define TRUE 1  
#define FALSE 0  
#define MAXNUMCOMPOUNDS 26 // No more than 26 compounds  defined  
#define MINCOMPOUND 'A'  // Smallest letter for compound  
#define MAXCOMPOUND 'T'  // Maximum letter for compound  
  

// Prototypes  
int userInterface(char *, char *);  
void findFirstPath(char *, char , char );  
char findNextCompound(char *, char *);  
char *findSynthesisString(char );  
void printSynthesisPath(char *);  

  

/*-------------------------------------------------------------------------  

Function: main  

Description: Overall control of the program. Calls  
userInterface to get  input from the user. When userInterface  
returns FALSE, it  signals the end of the program.  If it returns  
TRUE, then  it has provided values for initialCompound  
and finalCompound and  calls findFirstPath to try to find a path. If  
a path is found  call printSynthesisPath to print the results,  otherwise  
 print message that path could not be found.  

---------------------------------------------------------------------------*/  

int main()  

{  
    char pathString[MAXNUMCOMPOUNDS+1]; // char array  for storing path  
    char initialCompound;  // character for initial  compound  
    char finalCompound;  // character for final compound  
    int flag;  // flag for controlling the loop  
    do  
    {  
       flag = userInterface(&initialCompound,  &finalCompound);  
       if(flag)  
       {  
          findFirstPath(pathString, initialCompound,  finalCompound);  
          if(*pathString != '\0')  
             printSynthesisPath(pathString);  
          else  
             printf("Synthesis path could not be  found\n");   
       }  
    } while(flag);  
    printf("Terminating...\n");  
   // system("pause");  
}  

/*-------------------------------------------------------------------------  

Function: userInterface  

Description: Gets input from the user. This function  should return either  

             TRUE or FALSE.  If it returns TRUE, then two  different characters  

             should have been obtained from the user and  saved using the  pointers.  

--------------------------------------------------------------------------*/  

int userInterface(char *initialPtr, char *finalPtr)  

{  
	printf("Please input the initial compound and the final compound\n");
	printf("(only two character,such as GP)\n");
	scanf("%c%c",initialPtr,finalPtr);
	getchar();
	if(*initialPtr != *finalPtr
		&& *initialPtr >= MINCOMPOUND && *initialPtr <= MAXCOMPOUND
		&& *finalPtr >=  MINCOMPOUND  && *finalPtr <= MAXCOMPOUND
		)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}  


/*-------------------------------------------------------------------------  
Function: findFirstPath  

Description: The principal function to find a synthesis path.   
--------------------------------------------------------------------------*/  

void findFirstPath(char *pathPtr, char initialCompound, char finalCompound)  
{  
	char alreadySeenArray[MAXNUMCOMPOUNDS+1];
	char * alreadySeenPtr = alreadySeenArray;
	*alreadySeenPtr = '\0';
	char * currentPtr = "";
	currentPtr = pathPtr;
	*currentPtr = initialCompound;
	*(currentPtr + 1) = '\0';
	bool flag = TRUE;

	while (flag)
	{
		if (strchr(alreadySeenArray,*currentPtr) == NULL)
		{
			*alreadySeenPtr = *currentPtr; 
			alreadySeenPtr++;
			*alreadySeenPtr = '\0';
		}
		char * synthesisPtr = findSynthesisString(*currentPtr);

		if(strchr(synthesisPtr,finalCompound) != NULL) //find the path
		{
			currentPtr++;
			*currentPtr = finalCompound;
			*(currentPtr + 1) = '\0';
			flag = FALSE;
		}
		else //go to next
		{
			char nextCompound = findNextCompound(synthesisPtr,alreadySeenArray);
			if (nextCompound != '\0')
			{
				currentPtr++;
				*currentPtr = nextCompound;
				*(currentPtr + 1) = '\0';
			}
			else
			{
				if (*currentPtr == initialCompound) //no answer
				{
					*currentPtr = '\0';
					flag = FALSE;
				}
				else //go back
				{
					*currentPtr = '\0';
					currentPtr--;
				}
			}
		}
	}
}  

/*-------------------------------------------------------------------------  

Function: findNextCompound  
Description: Finds next compound in a synthesis path that  
has not yet been seen. Returns the nul character if all  
compounds in the synthesis path are in the already seen array.  

--------------------------------------------------------------------------*/  

char findNextCompound(char *synthesisPtr, char  *alreadySeenPtr)  
{  
	char *p = synthesisPtr;
	while ( *p!= '\0' && strchr(alreadySeenPtr,*p))
	{
		p++;
	}
	if( *p == '\0')
	{
		return '\0';
	}
	else
	{
		return *p;
	}
}  


/*-------------------------------------------------------------------------  

Function: findSynthesisString  
Description: Finds the synthesis string in the synthesisMatrix (i.e. row) for a given compound.  

--------------------------------------------------------------------------*/  

char *findSynthesisString(char compound)  
{  
	int i=0;
	while(synthesisMatrix[i][0] != '\0')
	{
		if (compound == synthesisMatrix[i][0])
		{
			return synthesisMatrix[i];
		}
		else
		{
			i++;
		}
	}
	return synthesisMatrix[i];
}  

/*-------------------------------------------------------------------------  

Function: printSynthesisPath Description: Prints a synthesis path in the form of  

A->B->H (when path is defined as "ABH". Guard against receiving an empty string.  

--------------------------------------------------------------------------*/  

void printSynthesisPath(char *pathPtr)  

{  
	char *p = pathPtr;
	while(*p != '\0')
	{
		printf("%c",*p);
		if( *++p != '\0' )
		{
			printf("->");
		}
	}
	printf("\n");
}	 
