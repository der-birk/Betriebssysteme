#include <stdio.h>
#include <stdlib.h>



typedef struct ListNode {
char* word;
struct ListNode* next;
} node;

node* listHead = NULL;


//fügt das Wort auf das "letter" zeigt, an den richtigen Platz in der Liste ein
static int insertElement(char* letter) {
	
}

static void outputWords(void){

}


int main (int argc, char* argv[]) {
	
	//einlesen der Wörter
    fgets(str, 101, stdin);
	
	//Fehlerbehandelung
	if(str == NULL){
		
	}
    else{
		insertElement(str);
	}

	exit(EXIT_SUCCESS);
}
