#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define LINE 256
#define WORD 30

//this function gets a string line from the input and initialize it to s and returns the sum of s
int getline_length(char s[])
{
    	int len = 0;
    	char c  = getchar();
    	while(c != '\n' && c != '\r' && c != '\0' && c != EOF && len < LINE -1)
    	{
        	s[len++] = c;
        	c=getchar();
    	}
    	s[len] = '\0';
    	if(c == EOF)
    		return EOF;
    	return len;
}




int getword_length(char w[])
{
    	int len = 0;
    	char c = getchar();
    	while(c != '\n' && c != '\t' && c != '\r' && c != '\0' && c !=' ' && c != EOF && len < WORD -1)
    	{
         	w[len++] = c;
         	c = getchar();
    	}
    	w[len] = '\0';
    	if(c == EOF)
    		return EOF;
    	return len;
}


size_t string_parser( const char *input, char ***word_array) 
{
    size_t n = 0;
    const char *p = input;

    while ( *p )
    {
        while ( isspace( ( unsigned char )*p ) ) ++p;
        n += *p != '\0';
        while ( *p && !isspace( ( unsigned char )*p ) ) ++p;
    }

    if ( n )
    {
        size_t i = 0;

        *word_array = malloc( n * sizeof( char * ) ); 

        p = input;

        while ( *p )
        {
            while ( isspace( ( unsigned char )*p ) ) ++p;
            if ( *p )
            {
                const char *q = p;
                while ( *p && !isspace( ( unsigned char )*p ) ) ++p;

                size_t length = p - q;

                ( *word_array )[i] = ( char * )malloc( length + 1 );

                strncpy( ( *word_array )[i], q, length );
                ( *word_array )[i][length] = '\0';

                ++i;
            }
        }           
    }

    return n;
}  

//this function returns if the string str1 contains the string str2
int substring(char * str1, char * str2)
{
	int  str1len = strlen(str1);
int  str2len = strlen(str2);
char check[256];
memset(check, 0, sizeof check);

for (size_t i = 0; i < str2len; i++)
{

for (int j= 0; j < str1len; j++)
{
if(str1[j]==str2[i])
{
	check[i]=str2[i];
}
}
}



if(str1len==str2len || str1len-1==str2len)
{
if(strcmp(check,str2)==0)
{
return TRUE;

}
}


return FALSE;
	}
	

//the function returns if the string t is similar to string s with omitting n leters from s
int similar(char *s, char *t, int n)
{
    	int s_len, t_len;
    	s_len = strlen(s);
    	t_len = strlen(t);

    	if(s_len - n != t_len)
        	return FALSE;
   
    	int count = 0;
    	int i = 0, j = 0;
    	while(i < s_len)
    	{
        	if(*(s+i) == *(t+j))
        	{
            		i++;
            		j++;
        	}
        	else
        	{
           		count++;
            		i++;
        	}
        	if(count > n)
            		return FALSE;
    	}
    	if(count == n)
        	return TRUE;
    	else
        	return FALSE;
}

//this function prints all lines from input that contains the string str
void print_lines(char * str)
{
    	char s[LINE];
    	while(getline_length(s) != EOF)
    	{
			int check = 0;
   char ** word_array = NULL;

    size_t n = string_parser( s, &word_array );

    for ( size_t i = 0; i < n; i++ ) 
	{
		  	if(substring(word_array[i] ,str) == TRUE)
			  {
  printf("%s\n" , s);
									 break;
			  }
			  
			  	}
				 

			
      
    	 }	
}

//this function prints all words from input that are similar by omitting 1,0 leters to the string str
void print_similar_words(char * str)
{
    	char s[WORD];
    	while(getword_length(s) != EOF)
    	{
        	if(similar(s,str,1) == 1 || similar(s,str,0))
            		printf("%s\n" , s);
    	}
}


int main()
{
    	char word[WORD];
    	char  action;
    	getword_length(word);
    	scanf("%c", &action);
   	
   	getchar();
   	getchar();
   	
   	printf("\n");
    	if (action == 'a')
        	print_lines(word);
    	else if (action == 'b')
        	print_similar_words(word);
       else
       	printf("ivalid input\n");
       
       printf("\n");
   
    return 0;
}