#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char* argv[]) {
	
	char** pWordList = NULL;
	char newWord[102];
	int wordCounter = 0;
	while (fgets(newWord, 101, stdin) != NULL)
		{
			//find the true ending of string
			//if empty begin with next word
			char* pCharFinder = strchr(newWord, '\n');      // strchr: searches for the first occurrence of the character '\n' in the string
			if (pCharFinder != NULL) *pCharFinder = '\0';
			if (strlen(newWord) == 0) continue;            // strlen: computes the length of the string up to, but not including the terminating null character.
			wordCounter++;
			
			//new word found, expand wordlist
			if(sizeof(*pWordList)/sizeof(char*) < wordCounter) 
			{
				char** pTemp = realloc(pWordList, sizeof(*pWordList)+sizeof(char*));
				if (pTemp == NULL) 
				{
					//TODO: Fehlerbehandlung
				}
				pWordList = pTemp;
			}

			//create character array
			char* pTemp = malloc(sizeof((strlen(newWord)+1)*sizeof(char)));
			pWordList[wordCounter] = pTemp;
			for (int i = 0; strlen(newWord)+1 >= i; i++)
				pWordList[wordCounter][i] = newWord[i];				
		}
		
	exit(EXIT_SUCCESS);
}

