#include "node.h"
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Node * head = NULL;
	int number;
	do {
		scanf("%d", &number);
		if ( number != -1 ) {
			// add to linked-list
			Node *p = (Node*)malloc(sizeof(Node));
			p->value = number;
			p->next = NULL;
		}
	}while ( number != -1 );
	
	return 0;
}
