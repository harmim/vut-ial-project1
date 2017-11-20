/**/
/************************* c202-advanced-test.c *******************************/
/*  Předmět: Algoritmy (IAL) - FIT VUT v Brně                                 */
/*  Úkol: c202 - Zásobník znaků v poli                                        */
/*  Vytvořil: Václav Topinka, září 2005                                       */
/*  Úpravy: Bohuslav Křena, říjen 2016                                        */
/* ************************************************************************** */

/* Pokročilé testy pro c202.c */

#include "c202.h"

#include <stdio.h>
#include <stdlib.h>

tStack* ptrstack;                                        /* pracovní zásobník */
int STACK_SIZE;                               /* efektivní velikost zásobníku */
int err_flag;                                              /* indikátor chyby */
int solved;                                        /* indikátor řešení funkce */

/****************************************************************************** 
 * Speciální ošetření testovaných funkcí.                                     *
 ******************************************************************************/

                                                 /* Vytiskne obsah zásobníku. */
void stackPrint( tStack* ptrstack) {
	if ( solved ) {
		int maxi = ptrstack->top;
		if ( ptrstack->top > STACK_SIZE-1 ) {
			printf ( "Warning: ptrstack->top (value: %i) is out of range STACK_SIZE (%i).\n", ptrstack->top, STACK_SIZE );
			maxi = STACK_SIZE-1;
		}
		printf ("--- BOTTOM [ ");
		for ( int i=0; i<=maxi; i++ )
			putchar ( ptrstack->arr[i] );
		printf (" ] TOP ---\n");
	}
}

         /* Zavolá funkci stackInit a v případě, že nebyla řešena, ohlásí to. */
void use_stack_init ( tStack* ptrstack ) {
	solved = 1;
	stackInit( ptrstack );
	if ( ! solved )
		printf("[W] Funkce stackInit nebyla implementována.\n");
}

                             /* Zavolá funkci stackEmpty a vytiskne výsledek. */
void use_stack_empty ( tStack* ptrstack ) {
	solved = 1;
	int i =stackEmpty( ptrstack );
	if ( ! solved )
		printf("[W] Funkce stackEmpty nebyla implementována.\n");
	else
		printf("stackEmpty returned '%s'\n", i ? "TRUE" : "FALSE" );
}

                              /* Zavolá funkci stackFull a vytiskne výsledek. */
void use_stack_full ( tStack* ptrstack ) {
	solved = 1;
	int i = stackFull( ptrstack );
	if ( ! solved )
		printf("[W] Funkce stackFull nebyla implementována.\n");
	else
		printf("stackFull returned '%s'\n", i ? "TRUE" : "FALSE" );
}

                               /* Zavolá funkci stackTop a vytiskne výsledek. */
void use_stack_top ( tStack* ptrstack ) {
	solved = 1;
	err_flag = 0;
	char c;
  stackTop( ptrstack, &c );
	if ( ! solved )
		printf("[W] Funkce stackTop nebyla implementována.\n");
	else if ( !err_flag )
		printf("stackTop returned '%c'\n", c );
}

                                                   /* Zavolá funkci stackPop. */
void use_stack_pop ( tStack* ptrstack ) {
	solved = 1;
	stackPop( ptrstack );
	if ( ! solved )
		printf("[W] Funkce stackPop nebyla implementována.\n");
}

                                                  /* Zavolá funkci stackPush. */
void use_stack_push ( tStack* ptrstack, char c ) {
	solved = 1;
	stackPush( ptrstack, c );
	if ( ! solved )
		printf("[W] Funkce stackPush nebyla implementována.\n");
}

/****************************************************************************** 
 * Vlastní testování                                                          *
 ******************************************************************************/

int main ( int argc, char* argv[] ) {
	printf ("C202 - Stack Implemented Using an Array - Advanced Tests\n");
	printf ("--------------------------------------------------------\n");

	STACK_SIZE = 1;
	ptrstack = (tStack*) malloc(sizeof(tStack));

	printf("\n[TEST01] Initialization with NULL pointer should cause an error but not a crash.\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  use_stack_init(NULL);

	printf("\n[TEST02] We check a stack of size 1.\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  use_stack_init(ptrstack);
	stackPrint(ptrstack);
	use_stack_empty(ptrstack);
	use_stack_full(ptrstack);

	printf("\n[TEST03] Pop should do nothing here ...\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  use_stack_pop(ptrstack);
	stackPrint(ptrstack);
	use_stack_empty(ptrstack);
	use_stack_full(ptrstack);

	printf("\n[TEST04] ... while Top should cause an error.\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  use_stack_top(ptrstack);
	stackPrint(ptrstack);
	use_stack_empty(ptrstack);
	use_stack_full(ptrstack);

	printf("\n[TEST05] We push 'O' as the first item.\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	use_stack_push(ptrstack, 'O');
	stackPrint(ptrstack);
	use_stack_empty(ptrstack);
	use_stack_full(ptrstack);

	printf("\n[TEST06] We try to push another item. It should cause an error.\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	use_stack_push(ptrstack, 'K');
	stackPrint(ptrstack);
	use_stack_empty(ptrstack);
	use_stack_full(ptrstack);

	printf("\n[TEST07] And once again.\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
	use_stack_push(ptrstack, '!');
	stackPrint(ptrstack);
	use_stack_empty(ptrstack);
	use_stack_full(ptrstack);

	printf("\n[TEST08] What is on the top now?\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	use_stack_top(ptrstack);

	printf("\n[TEST09] We remove it ...\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  use_stack_pop(ptrstack);
	stackPrint(ptrstack);
	use_stack_empty(ptrstack);
	use_stack_full(ptrstack);

 	printf("\n[TEST10] ... and check behaviour of Pop and Top.\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  use_stack_pop(ptrstack);
  use_stack_top(ptrstack);
	stackPrint(ptrstack);
	use_stack_empty(ptrstack);
	use_stack_full(ptrstack);

	STACK_SIZE = MAX_STACK;

	printf("\n[TEST11] Now, we check a stack of maximum size.\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  use_stack_init(ptrstack);
	stackPrint(ptrstack);
	use_stack_empty(ptrstack);
	use_stack_full(ptrstack);
	
	printf("\n[TEST12] Pop should do nothing here ...\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  use_stack_pop(ptrstack);
	stackPrint(ptrstack);
	use_stack_empty(ptrstack);
	use_stack_full(ptrstack);

	printf("\n[TEST13] ... while Top should cause an error.\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  use_stack_top(ptrstack);
	stackPrint(ptrstack);
	use_stack_empty(ptrstack);
	use_stack_full(ptrstack);

	printf("\n[TEST14] Pushing small letters (but we have no enough space for that).\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	for (int i=0; i<26; i++)
		use_stack_push(ptrstack, 'a'+i);
	stackPrint(ptrstack);
	use_stack_empty(ptrstack);
	use_stack_full(ptrstack);

	printf("\n[TEST15] What is on the top now?\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	stackPrint(ptrstack);
	use_stack_top(ptrstack);

	printf("\n[TEST16] Pushing another item should cause another error.\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	use_stack_push(ptrstack, 'X');
	use_stack_empty(ptrstack);
	use_stack_full(ptrstack);

 	printf("\n[TEST17] The top item should be the same.\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	stackPrint(ptrstack);
	use_stack_top(ptrstack);

	printf("\n[TEST18] We remove all items without proper counting ...\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	for (int i=0; i<2*MAX_STACK; i++)
		use_stack_pop(ptrstack);
	stackPrint(ptrstack);
	use_stack_empty(ptrstack);
	use_stack_full(ptrstack);

 	printf("\n[TEST19] ... and check behaviour of Pop and Top.\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  use_stack_pop(ptrstack);
  use_stack_pop(ptrstack);
  use_stack_top(ptrstack);
  use_stack_top(ptrstack);
	stackPrint(ptrstack);
	use_stack_empty(ptrstack);
	use_stack_full(ptrstack);

	printf("\n\n----- C202 - The End of Advanced Tests -----\n");

	free(ptrstack);
	return(0);
}

/* Konec c202-advanced-test.c */
/**/
