/* ******************************* c204.c *********************************** */
/*  Předmět: Algoritmy (IAL) - FIT VUT v Brně                                 */
/*  Úkol: c204 - Převod infixového výrazu na postfixový (s využitím c202)     */
/*  Referenční implementace: Petr Přikryl, listopad 1994                      */
/*  Přepis do jazyka C: Lukáš Maršík, prosinec 2012                           */
/*  Upravil: Kamil Jeřábek, říjen 2017                                        */
/*  Implementace: Dominik Harmim <xharmi00@stud.fit.vutbr.cz>, říjen 2017     */
/* ************************************************************************** */
/*
** Implementujte proceduru pro převod infixového zápisu matematického
** výrazu do postfixového tvaru. Pro převod využijte zásobník (tStack),
** který byl implementován v rámci příkladu c202. Bez správného vyřešení
** příkladu c202 se o řešení tohoto příkladu nepokoušejte.
**
** Implementujte následující funkci:
**
**    infix2postfix .... konverzní funkce pro převod infixového výrazu
**                       na postfixový
**
** Pro lepší přehlednost kódu implementujte následující pomocné funkce:
**
**    untilLeftPar .... vyprázdnění zásobníku až po levou závorku
**    doOperation .... zpracování operátoru konvertovaného výrazu
**
** Své řešení účelně komentujte.
**
** Terminologická poznámka: Jazyk C nepoužívá pojem procedura.
** Proto zde používáme pojem funkce i pro operace, které by byly
** v algoritmickém jazyce Pascalovského typu implemenovány jako
** procedury (v jazyce C procedurám odpovídají funkce vracející typ void).
**
**/

#include "c204.h"


int solved;


/*
** Pomocná funkce untilLeftPar.
** Slouží k vyprázdnění zásobníku až po levou závorku, přičemž levá závorka
** bude také odstraněna. Pokud je zásobník prázdný, provádění funkce se ukončí.
**
** Operátory odstraňované ze zásobníku postupně vkládejte do výstupního pole
** znaků postExpr. Délka převedeného výrazu a též ukazatel na první volné
** místo, na které se má zapisovat, představuje parametr postLen.
**
** Aby se minimalizoval počet přístupů ke struktuře zásobníku, můžete zde
** nadeklarovat a používat pomocnou proměnnou typu char.
*/
void untilLeftPar(tStack *s, char *postExpr, unsigned *postLen)
{
	char stackTopChar; // deklarace proměnné pro uložení znaku z vrcholu zásobníku

	// průchod přes zásobník, dokud nebude prázdný
	while (!stackEmpty(s))
	{
		stackTop(s, &stackTopChar); // uložení znaku z vrcholu zásobníku
		stackPop(s); // odstranění znaku z vrcholu zásobníku

		if (stackTopChar == '(') // na vrcholu zásobníku byla levá závorka
		{
			break; // odebirání znaků v vrcholu zásobníku musí skončit
		}

		// umístění znaku z vrcholu zásobníku na konec výstupního řetězce a inkrementace jeho délky
		postExpr[(*postLen)++] = stackTopChar;
	}
}


/*
** Pomocná funkce doOperation.
** Zpracuje operátor, který je předán parametrem c po načtení znaku ze
** vstupního pole znaků.
**
** Dle priority předaného operátoru a případně priority operátoru na
** vrcholu zásobníku rozhodneme o dalším postupu. Délka převedeného
** výrazu a taktéž ukazatel na první volné místo, do kterého se má zapisovat,
** představuje parametr postLen, výstupním polem znaků je opět postExpr.
*/
void doOperation(tStack *s, char c, char *postExpr, unsigned *postLen)
{
	if (stackEmpty(s)) // zásobník je prázdný
	{
		stackPush(s, c); // vložení operátoru na vrchol zásobníku
		return;
	}

	char stackTopChar; // deklarace proměnné pro uložení znaku z vrcholu zásobníku
	stackTop(s, &stackTopChar); // uložení znaku z vrcholu zásobníku
	if (stackTopChar == '(') // na vrcholu zásobníku je levá závorka
	{
		stackPush(s, c); // vložení operátoru na vrchol zásobníku
		return;
	}
	if ((stackTopChar == '+' || stackTopChar == '-') && (c == '*' || c == '/'))
	{ // na vrcholu zásobníku je operátor s nižší prioritou
		stackPush(s, c); // vložení operátoru na vrchol zásobníku
		return;
	}

	// umístění znaku z vrcholu zásobníku na konec výstupního řetězce a inkrementace jeho délky
	postExpr[(*postLen)++] = stackTopChar;
	stackPop(s); // odstranění znaku z vrcholu zásobníku

	// tato funkce se bude rekuzivně volat, dokud se daný operátor nepodaří vložit na vrchol zásobníku
	doOperation(s, c, postExpr, postLen);
}


/*
** Konverzní funkce infix2postfix.
** Čte infixový výraz ze vstupního řetězce infExpr a generuje
** odpovídající postfixový výraz do výstupního řetězce (postup převodu
** hledejte v přednáškách nebo ve studijní opoře). Paměť pro výstupní řetězec
** (o velikosti MAX_LEN) je třeba alokovat. Volající funkce, tedy
** příjemce konvertovaného řetězce, zajistí korektní uvolnění zde alokované
** paměti.
**
** Tvar výrazu:
** 1. Výraz obsahuje operátory + - * / ve významu sčítání, odčítání,
**    násobení a dělení. Sčítání má stejnou prioritu jako odčítání,
**    násobení má stejnou prioritu jako dělení. Priorita násobení je
**    větší než priorita sčítání. Všechny operátory jsou binární
**    (neuvažujte unární mínus).
**
** 2. Hodnoty ve výrazu jsou reprezentovány jednoznakovými identifikátory
**    a číslicemi - 0..9, a..z, A..Z (velikost písmen se rozlišuje).
**
** 3. Ve výrazu může být použit předem neurčený počet dvojic kulatých
**    závorek. Uvažujte, že vstupní výraz je zapsán správně (neošetřujte
**    chybné zadání výrazu).
**
** 4. Každý korektně zapsaný výraz (infixový i postfixový) musí být uzavřen
**    ukončovacím znakem '='.
**
** 5. Při stejné prioritě operátorů se výraz vyhodnocuje zleva doprava.
**
** Poznámky k implementaci
** -----------------------
** Jako zásobník použijte zásobník znaků tStack implementovaný v příkladu c202.
** Pro práci se zásobníkem pak používejte výhradně operace z jeho rozhraní.
**
** Při implementaci využijte pomocné funkce untilLeftPar a doOperation.
**
** Řetězcem (infixového a postfixového výrazu) je zde myšleno pole znaků typu
** char, jenž je korektně ukončeno nulovým znakem dle zvyklostí jazyka C.
**
** Na vstupu očekávejte pouze korektně zapsané a ukončené výrazy. Jejich délka
** nepřesáhne MAX_LEN-1 (MAX_LEN i s nulovým znakem) a tedy i výsledný výraz
** by se měl vejít do alokovaného pole. Po alokaci dynamické paměti si vždycky
** ověřte, že se alokace skutečně zdrařila. V případě chyby alokace vraťte namísto
** řetězce konstantu NULL.
*/
char *infix2postfix(const char *infExpr)
{
	// Alokace paměti pro výstupní řetězec.
	char *postExpr = (char *) malloc(MAX_LEN * sizeof(char));
	if (!postExpr)
	{
		// malloc selhal
		return NULL;
	}

	// Alokace paměti pro zásobník.
	tStack *stack = (tStack *) malloc(sizeof(tStack));
	if (!stack)
	{
		// malloc selhal
		free(postExpr);
		return NULL;
	}
	stackInit(stack); // inicializace zásobníku

	unsigned int postLen = 0; // inicializace proměnné pro délku výstupního řetězce
	// průchod přes vstupní řetězec (znak po znaku, zleva doprava)
	for (char c = *infExpr; c != '\0'; c = *(++infExpr))
	{
		if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) // operand
		{
			postExpr[postLen++] = c; // přidání znaku na konec výstupního řetězce a inkrementace jeho délky
		}
		else if (c == '(') // levá závorka
		{
			stackPush(stack, c); // vložení znaku na vrchol zásobníku
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') // operátor
		{
			doOperation(stack, c, postExpr, &postLen); // zpracování operátoru
		}
		else if (c == ')') // pravá závorka
		{
			untilLeftPar(stack, postExpr, &postLen); // vyprázdnění zásobníku až po levou závorku
		}
		else if (c == '=') // konec výrazu
		{
			// průchod přes zásobník, dokud nebude prázdný
			while (!stackEmpty(stack))
			{
				// uložení znaku z vrcholu zásobníku na konec výstupního řetězce a inkrementace jeho délky
				stackTop(stack, &(postExpr[postLen++]));
				stackPop(stack); // odstranění znaku z vrcholu zásobníku
			}
			postExpr[postLen++] = '='; // přidání znaku = na konec výstupního řetězce a inkrementace jeho délky
			break; // konec zpracovávání výrazu
		}
	}

	postExpr[postLen++] = '\0'; // ukončení výstupního řetězce znakem s hodnotou 0 a inkrementace jeho délky
	free(stack); // uvolnění paměti alokované pro zásobník

	return postExpr; // vrácení výstupního řetězce
}
