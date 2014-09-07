/**********************************************************************
Name: Jaison Zachariah
Date: February 19, 2012
Assignment: 1
File: Decomment

This program removes comments from source code.
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/* 
*Enumerated state names for clarity 
*/

enum statenames {
	START, 
 	BEGIN_OBJECT, END_OBJECT,
    BEGIN_STRING, IN_STRING, END_STRING,
    COLON, 
    BEGIN_VALUE_STRING, IN_VALUE_STRING, END_VALUE_STRING,
    BEGIN_NUMBER,
    COMMA,
    ESCAPE_CHARACTER,
    BEGIN_ARRAY, END_ARRAY,
    ARRAY_COMMA,
    BEGIN_ARRAY_STRING, IN_ARRAY_STRING, END_ARRAY_STRING,
    BEGIN_ARRAY_NUMBER,
    SUCCESS,
    ERROR
};



/* 
*  Function that handles all matters within Char Literal State.
*  This is reached when we see a ''' from the Letters State.
*/

/*
int char_lithandler(char c) 
{
	int nextstate;
	
	switch(c)
	{
		case '\'':
			nextstate = LETTER;
			putchar(c);
			break;
		case '\\':            
			putchar(c);
			c = getchar();
			putchar(c);
			nextstate = CHAR_LIT;
			break;			
		default:
			nextstate = CHAR_LIT;
			putchar(c);
			break;
	}
	return nextstate;
}
*/

int start_handler(char c) 
{
	int nextstate;
		
	switch(c)
	{
		case '{':
			nextstate = BEGIN_OBJECT;
			break;
		case '[':            
			nextstate = BEGIN_ARRAY;
			break;			
		default:
			nextstate = ERROR;
			break;
	}
	return nextstate;

}

int begin_object_handler(char c) 
{
	int nextstate;
		
	switch(c)
	{
		case '{':
			nextstate = BEGIN_OBJECT;
			break;
		case '[':            
			nextstate = BEGIN_ARRAY;
			break;			
		default:
			nextstate = ERROR;
			break;
	}
	return nextstate;

}

/* 
*  We declare the initial state to be Letter.  The next character is 
*  then gotten.  While the characters being observed are not 'EOF',
*  then enter the states depending on what case we're in.  Within each
*  case, we have functions that make the decision about where to go 
*  next, which is determined by the character being observed.
*/

int main(void) 
{
	int exit_status = EXIT_SUCCESS; /* Status of Exit set to 0  */
	int state = START;              /* Start state is START    */
	char c = getchar();             /* Obtain the 1st character */

	while(c != EOF && exit_status != EXIT_FAILURE) 
	{
		switch(state) 
		{
			case START:
				state = start_handler(c);
				break;
			case BEGIN_OBJECT:
				state = begin_object_handler(c);
				break;
			case ERROR:
				exit_status = EXIT_FAILURE;
				fprintf(stderr, "Error.  Invalid JSON.\n'");
				break;
			case SUCCESS:
				fprintf(stderr, "Success!  Valid JSON.");
				break;
			/*
			case LETTER: 
				state = letterhandler(c);
				c = getchar();
				break;
			case POSS_COMMENT: 
				state = poss_commenthandler(c);
				c = getchar();
				break;
			case COMMENT:
				state = commenthandler(c);
				c = getchar();
				if (c == EOF)
				{
				exit_status = EXIT_FAILURE;
				fprintf(stderr, "Error: line %d: unt",
					linecount);
				fprintf(stderr, "erminated comment\n");
				}
				break;
			case POSS_END: 
				state = poss_endhandler(c);
				c = getchar();
				if (c == EOF)
				{
				exit_status = EXIT_FAILURE;
				fprintf(stderr, "Error: line %d: unt",
					linecount);
				fprintf(stderr, "erminated comment\n");
				putchar(' ');
				}				
				break;
			case STR_LIT: 
				state = str_lithandler(c);
				c = getchar();
				break;
			case CHAR_LIT: 
				state = char_lithandler(c);
				c = getchar();
				break;
			*/
		}
		c = getchar();
	}
	return exit_status;
}



