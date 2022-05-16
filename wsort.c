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
			if(sizeof(*pWordList)/sizeof(char*) < wordCounter)    // ??? sizeof(*pWordList)/sizeof(char*) = Anzahl der Wörter in der pWordList?
			{
				char** pTemp = realloc(pWordList, sizeof(*pWordList)+sizeof(char*));
				if (pTemp == NULL) 
				{
					//TODO: Fehlerbehandlung
					printf('realloc of new word failed');
				}
				pWordList = pTemp;
			}


			//create character array
			char* pTemp = malloc(sizeof((strlen(newWord)+1)*sizeof(char)));
			pWordList[wordCounter] = pTemp;
			for (int i = 0; strlen(newWord)+1 >= i; i++)
				pWordList[wordCounter][i] = newWord[i];				
		}


		//sorting array with bubblesort
		int compare = 0;
		for(int i = 0, i < wordCounter, i++){
			for(int p = 0, p < wordCounter -i -1 , p++){
				char* str1 = pWordList[p];
				char* str2 = pWordList[p+1];;
			    compare = strcmp(str1, str2);

				if(compare > 0){      // str2 is less than str1 -> they have to be switched
                    char* temp = pWordList[p];
					pWordList[p] = pWordList[p+1];
					pWordList[p+1] = temp;
				}
		    }
		}
		
	exit(EXIT_SUCCESS);
}

