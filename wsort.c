#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char* argv[]) {

	char** pWordList = NULL;
	char newWord[102];
	int wordCounter = 0;
	while (feof(stdin) == 0)
		{

		    fgets(newWord, 3, stdin);
		    if(feof(stdin) != 0)
            {
                printf("end of stream\n");
                continue;
            }
		    if(pWordList == NULL) printf("empty list\n");
			//find the true ending of string
			//if empty begin with next word
			char* pCharFinder = strchr(newWord, '\n');
			if (pCharFinder != NULL) *pCharFinder = '\0';
			if (strlen(newWord) == 0) continue;

			//new word found, expand wordlist
			{
				char** pTemp = realloc(pWordList, sizeof(char**)*(wordCounter+1));
				if (pTemp == NULL)
				{
					//TODO: Fehlerbehandlung
					printf("realloc of new word failed\n");
				}
				else printf("reallocated\n");
				pWordList = pTemp;
				printf("size of list %d\n",wordCounter+1);
			}
		//create character array
            char* pTemp = malloc(sizeof(char)*(strlen(newWord)+1));
            if (pTemp == NULL) printf("malloc failed");
            else printf("malloced \n");
            for (int i = 0; i < strlen(newWord)+1 ; i++)
                pTemp[i] = newWord[i];
            pWordList[wordCounter] = pTemp;

		//sorting array with bubblesort
		int compare = 0;
		for(int i = 0; i <= wordCounter; i++)
            {
			for(int p = 0; p <= wordCounter -i -1 ; p++)
                {
                    char* str1 = pWordList[p];
                    char* str2 = pWordList[p+1];;
                    compare = strcmp(str1, str2);
                    if(compare > 0)
                        {
                        // str2 is less than str1 -> they have to be switched
                        char* temp = pWordList[p];
                        pWordList[p] = pWordList[p+1];
                        pWordList[p+1] = temp;
                    }
                }
            }
            wordCounter++;
		}
    for (int i = 0; i < wordCounter; i++)
            puts(pWordList[i]);

	exit(EXIT_SUCCESS);
}
