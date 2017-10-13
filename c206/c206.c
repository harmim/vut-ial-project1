/* c206.c **********************************************************}
{* Téma: Dvousměrně vázaný lineární seznam
**
** Návrh a referenční implementace: Bohuslav Křena, říjen 2001
** Přepracované do jazyka C: Martin Tuček, říjen 2004
** Úpravy: Kamil Jeřábek, říjen 2017
** Implementace: Dominik Harmim <xharmi00@stud.fit.vutbr.cz>, říjen 2017
**
** Implementujte abstraktní datový typ dvousměrně vázaný lineární seznam.
** Užitečným obsahem prvku seznamu je hodnota typu int.
** Seznam bude jako datová abstrakce reprezentován proměnnou
** typu tDLList (DL znamená Double-Linked a slouží pro odlišení
** jmen konstant, typů a funkcí od jmen u jednosměrně vázaného lineárního
** seznamu). Definici konstant a typů naleznete v hlavičkovém souboru c206.h.
**
** Vaším úkolem je implementovat následující operace, které spolu
** s výše uvedenou datovou částí abstrakce tvoří abstraktní datový typ
** obousměrně vázaný lineární seznam:
**
**      DLInitList ...... inicializace seznamu před prvním použitím,
**      DLDisposeList ... zrušení všech prvků seznamu,
**      DLInsertFirst ... vložení prvku na začátek seznamu,
**      DLInsertLast .... vložení prvku na konec seznamu, 
**      DLFirst ......... nastavení aktivity na první prvek,
**      DLLast .......... nastavení aktivity na poslední prvek, 
**      DLCopyFirst ..... vrací hodnotu prvního prvku,
**      DLCopyLast ...... vrací hodnotu posledního prvku, 
**      DLDeleteFirst ... zruší první prvek seznamu,
**      DLDeleteLast .... zruší poslední prvek seznamu, 
**      DLPostDelete .... ruší prvek za aktivním prvkem,
**      DLPreDelete ..... ruší prvek před aktivním prvkem, 
**      DLPostInsert .... vloží nový prvek za aktivní prvek seznamu,
**      DLPreInsert ..... vloží nový prvek před aktivní prvek seznamu,
**      DLCopy .......... vrací hodnotu aktivního prvku,
**      DLActualize ..... přepíše obsah aktivního prvku novou hodnotou,
**      DLSucc .......... posune aktivitu na další prvek seznamu,
**      DLPred .......... posune aktivitu na předchozí prvek seznamu, 
**      DLActive ........ zjišťuje aktivitu seznamu.
**
** Při implementaci jednotlivých funkcí nevolejte žádnou z funkcí
** implementovaných v rámci tohoto příkladu, není-li u funkce
** explicitně uvedeno něco jiného.
**
** Nemusíte ošetřovat situaci, kdy místo legálního ukazatele na seznam 
** předá někdo jako parametr hodnotu NULL.
**
** Svou implementaci vhodně komentujte!
**
** Terminologická poznámka: Jazyk C nepoužívá pojem procedura.
** Proto zde používáme pojem funkce i pro operace, které by byly
** v algoritmickém jazyce Pascalovského typu implemenovány jako
** procedury (v jazyce C procedurám odpovídají funkce vracející typ void).
**/

#include "c206.h"


int solved;
int errflg;


void DLError()
{
/*
** Vytiskne upozornění na to, že došlo k chybě.
** Tato funkce bude volána z některých dále implementovaných operací.
**/
	printf("*ERROR* The program has performed an illegal operation.\n");
	errflg = TRUE; /* globální proměnná -- příznak ošetření chyby */
}


void DLInitList(tDLList *L)
{
/*
** Provede inicializaci seznamu L před jeho prvním použitím (tzn. žádná
** z následujících funkcí nebude volána nad neinicializovaným seznamem).
** Tato inicializace se nikdy nebude provádět nad již inicializovaným
** seznamem, a proto tuto možnost neošetřujte. Vždy předpokládejte,
** že neinicializované proměnné mají nedefinovanou hodnotu.
**/
	// Všechny ukazatele v seznamu nastavíme na NULL.
	L->First = L->Last = L->Act = NULL;
}


void DLDisposeList(tDLList *L)
{
/*
** Zruší všechny prvky seznamu L a uvede seznam do stavu, v jakém
** se nacházel po inicializaci. Rušené prvky seznamu budou korektně
** uvolněny voláním operace free. 
**/
	// Průchod seznamem a zrušení všech jeho prvků.
	tDLElemPtr tDLElem = L->First;
	while (L->First != NULL)
	{
		L->First = L->First->rptr;
		free(tDLElem);
		tDLElem = L->First;
	}

	// Všechny ukazatele v seznamu nastavíme na NULL.
	L->First = L->Last = L->Act = NULL;
}


void DLInsertFirst(tDLList *L, int val)
{
/*
** Vloží nový prvek na začátek seznamu L.
** V případě, že není dostatek paměti pro nový prvek při operaci malloc,
** volá funkci DLError().
**/
	// Alokace paměti pro nový prvek.
	tDLElemPtr tDLElem = (tDLElemPtr) malloc(sizeof(struct tDLElem));
	if (!tDLElem)
	{
		// malloc selhal
		DLError();
		return;
	}

	tDLElem->data = val; // nastavení dat
	tDLElem->lptr = NULL; // levý ukazatel bude NULL
	tDLElem->rptr = L->First; // pravý ukazatel na původní první prvek

	if (L->First) // seznam není prázdný
	{
		L->First->lptr = tDLElem; // levý ukazatel prvního prvku na nový prvek
	}
	else // seznam je prázdný
	{
		L->Last = tDLElem; // poslední prvek bude nový prvek (je to zároveň i první prvek)
	}
	L->First = tDLElem; // první prvek bude nový prvek
}


void DLInsertLast(tDLList *L, int val)
{
/*
** Vloží nový prvek na konec seznamu L (symetrická operace k DLInsertFirst).
** V případě, že není dostatek paměti pro nový prvek při operaci malloc,
** volá funkci DLError().
**/
	// Alokace paměti pro nový prvek.
	tDLElemPtr tDLElem = (tDLElemPtr) malloc(sizeof(struct tDLElem));
	if (!tDLElem)
	{
		// malloc selhal
		DLError();
		return;
	}

	tDLElem->data = val; // nastavení dat
	tDLElem->rptr = NULL; // pravý ukazatel bude NULL
	tDLElem->lptr = L->Last; // levý ukazatel na původní poslední prvek

	if (L->Last) // seznam není prázdný
	{
		L->Last->rptr = tDLElem; // pravý ukazatel posledního prvku na nový prvek
	}
	else // seznam je prázdný
	{
		L->First = tDLElem; // první prvek bude nový prvek (je to zároveň i poslední prvek)
	}
	L->Last = tDLElem; // poslední prvek bude nový prvek
}


void DLFirst(tDLList *L)
{
/*
** Nastaví aktivitu na první prvek seznamu L.
** Funkci implementujte jako jediný příkaz (nepočítáme-li return),
** aniž byste testovali, zda je seznam L prázdný.
**/
	L->Act = L->First; // nastavíme první prvek jako aktivní
}


void DLLast(tDLList *L)
{
/*
** Nastaví aktivitu na poslední prvek seznamu L.
** Funkci implementujte jako jediný příkaz (nepočítáme-li return),
** aniž byste testovali, zda je seznam L prázdný.
**/
	L->Act = L->Last; // nastavíme poslední prvek jako aktivní
}


void DLCopyFirst(tDLList *L, int *val)
{
/*
** Prostřednictvím parametru val vrátí hodnotu prvního prvku seznamu L.
** Pokud je seznam L prázdný, volá funkci DLError().
**/
	// Když je seznam prázdný, signalizuje se chyba.
	if (!L->First)
	{
		DLError();
		return;
	}

	*val = L->First->data; // kopie dat z prvního prvku do val
}


void DLCopyLast(tDLList *L, int *val)
{
/*
** Prostřednictvím parametru val vrátí hodnotu posledního prvku seznamu L.
** Pokud je seznam L prázdný, volá funkci DLError().
**/
	// Když je seznam prázdný, signalizuje se chyba.
	if (!L->Last)
	{
		DLError();
		return;
	}

	*val = L->Last->data; // kopie dat z posledního prvku do val
}


void DLDeleteFirst(tDLList *L)
{
/*
** Zruší první prvek seznamu L. Pokud byl první prvek aktivní, aktivita 
** se ztrácí. Pokud byl seznam L prázdný, nic se neděje.
**/
	tDLElemPtr first = L->First;
	if (first) // seznam není prádzný
	{
		// Pokud je první prvek aktivní, aktivita se ztrácí.
		if (first == L->Act)
		{
			L->Act = NULL;
		}

		if (first == L->Last) // první prvek je zároveň poslední (seznam má jediný prvek)
		{
			L->Last = NULL; // poslední prvek bude NULL
		}
		else // v seznamu je více prvku
		{
			first->rptr->lptr = NULL; // levý ukazatel druhého prvku bude NULL
		}

		// první prvek bude druhý prvek (může být i NULL v případě, že má seznam jediný prvek)
		L->First = first->rptr;
		free(first); // uvolnění prvního prvku
	}
}


void DLDeleteLast(tDLList *L)
{
/*
** Zruší poslední prvek seznamu L. Pokud byl poslední prvek aktivní,
** aktivita seznamu se ztrácí. Pokud byl seznam L prázdný, nic se neděje.
**/
	tDLElemPtr last = L->Last;
	if (last) // seznam není prádzný
	{
		// Pokud je poslední prvek aktivní, aktivita se ztrácí.
		if (last == L->Act)
		{
			L->Act = NULL;
		}

		if (last == L->First) // poslední prvek je zároveň první (seznam má jediný prvek)
		{
			L->First = NULL; // první prvek bude NULL
		}
		else // v seznamu je více prvku
		{
			last->lptr->rptr = NULL; // pravý ukazatel předposledního prvku bude NULL
		}

		// poslední prvek bude předposlední prvek (může být i NULL v případě, že má seznam jediný prvek)
		L->Last = last->lptr;
		free(last); // uvolnění posledního prvku
	}
}


void DLPostDelete(tDLList *L)
{
/*
** Zruší prvek seznamu L za aktivním prvkem.
** Pokud je seznam L neaktivní nebo pokud je aktivní prvek
** posledním prvkem seznamu, nic se neděje.
**/
	// V seznamu musí být aktivní prvek, který není poslední.
	if (L->Act && L->Act != L->Last)
	{
		tDLElemPtr elem = L->Act->rptr; // uložení ukazatele na prvek za aktivním prvkem do elem
		L->Act->rptr = elem->rptr; // pravý ukazatel aktivního prvku bude pravý ukazatel elem
		if (elem == L->Last) // elem je poslední prvek
		{
			L->Last = L->Act; // poslední prvek bude aktivní
		}
		else // elem není poslední prvek
		{
			elem->rptr->lptr = L->Act; // levý ukazatel prvku za elem bude aktivní prvek
		}
		free(elem); // uvolnění elem
	}
}


void DLPreDelete(tDLList *L)
{
/*
** Zruší prvek před aktivním prvkem seznamu L.
** Pokud je seznam L neaktivní nebo pokud je aktivní prvek
** prvním prvkem seznamu, nic se neděje.
**/
	// V seznamu musí být aktivní prvek, který není první.
	if (L->Act && L->Act != L->First)
	{
		tDLElemPtr elem = L->Act->lptr; // uložení ukazatele na prvek před aktivním prvkem do elem
		L->Act->lptr = elem->lptr; // levý ukazatel aktivního prvku bude levý ukazatel elem
		if (elem == L->First) // elem je první prvek
		{
			L->First = L->Act; // první prvek bude aktivní
		}
		else // elem není první prvek
		{
			elem->lptr->rptr = L->Act; // pravý ukazatel prvku před elem bude aktivní prvek
		}
		free(elem); // uvolnění elem
	}
}


void DLPostInsert(tDLList *L, int val)
{
/*
** Vloží prvek za aktivní prvek seznamu L.
** Pokud nebyl seznam L aktivní, nic se neděje.
** V případě, že není dostatek paměti pro nový prvek při operaci malloc,
** volá funkci DLError().
**/
	// Seznam musí být aktivní.
	if (L->Act)
	{
		// Alokace paměti pro nový prvek.
		tDLElemPtr tDLElem = (tDLElemPtr) malloc(sizeof(struct tDLElem));
		if (!tDLElem)
		{
			// malloc selhal
			DLError();
			return;
		}

		tDLElem->data = val; // nastavení dat
		tDLElem->lptr = L->Act; // levý ukazatel bude aktivní prvek
		tDLElem->rptr = L->Act->rptr; // pravý ukazatel bude pravý ukazatel aktivního prvku

		if (L->Act == L->Last) // aktivní prvek je poslední
		{
			L->Last = tDLElem; // nový prvek bude poslední
		}
		else // aktivní prvek není poslední
		{
			L->Act->rptr->lptr = tDLElem; // levý ukazatel prvku napravo od aktivního prvku bude nový prvek
		}

		L->Act->rptr = tDLElem; // pravý ukazatel aktivního prvku bude nový prvek
	}
}


void DLPreInsert(tDLList *L, int val)
{
/*
** Vloží prvek před aktivní prvek seznamu L.
** Pokud nebyl seznam L aktivní, nic se neděje.
** V případě, že není dostatek paměti pro nový prvek při operaci malloc,
** volá funkci DLError().
**/
	// Seznam musí být aktivní.
	if (L->Act)
	{
		// Alokace paměti pro nový prvek.
		tDLElemPtr tDLElem = (tDLElemPtr) malloc(sizeof(struct tDLElem));
		if (!tDLElem)
		{
			// malloc selhal
			DLError();
			return;
		}

		tDLElem->data = val; // nastavení dat
		tDLElem->rptr = L->Act; // pravý ukazatel bude aktivní prvek
		tDLElem->lptr = L->Act->lptr; // levý ukazatel bude levý ukazatel aktivního prvku

		if (L->Act == L->First) // aktivní prvek je první
		{
			L->First = tDLElem; // nový prvek bude první
		}
		else // aktivní prvek není první
		{
			L->Act->lptr->rptr = tDLElem; // pravý ukazatel prvku nalevo od aktivního prvku bude nový prvek
		}

		L->Act->lptr = tDLElem; // levý ukazatel aktivního prvku bude nový prvek
	}
}


void DLCopy(tDLList *L, int *val)
{
/*
** Prostřednictvím parametru val vrátí hodnotu aktivního prvku seznamu L.
** Pokud seznam L není aktivní, volá funkci DLError().
**/
	// Pokud seznam nemá aktivní prvek, tak se signalizuje chyba.
	if (!L->Act)
	{
		DLError();
		return;
	}

	*val = L->Act->data; // kopie dat z aktivního prvku do val
}


void DLActualize(tDLList *L, int val)
{
/*
** Přepíše obsah aktivního prvku seznamu L.
** Pokud seznam L není aktivní, nedělá nic.
**/
	// Seznam musí mít aktivní prvek
	if (L->Act)
	{
		L->Act->data = val; // přepsání dat aktivního prvku
	}
}


void DLSucc(tDLList *L)
{
/*
** Posune aktivitu na následující prvek seznamu L.
** Není-li seznam aktivní, nedělá nic.
** Všimněte si, že při aktivitě na posledním prvku se seznam stane neaktivním.
**/
	// Seznam musí mít aktivní prvek.
	if (L->Act)
	{
		L->Act = L->Act->rptr; // nastavení aktivitu na následující prvek
	}
}


void DLPred(tDLList *L)
{
/*
** Posune aktivitu na předchozí prvek seznamu L.
** Není-li seznam aktivní, nedělá nic.
** Všimněte si, že při aktivitě na prvním prvku se seznam stane neaktivním.
**/
	// Seznam musí mít aktivní prvek.
	if (L->Act)
	{
		L->Act = L->Act->lptr; // nastavení aktivity na přechozí prvek
	}
}


int DLActive(tDLList *L)
{
/*
** Je-li seznam L aktivní, vrací nenulovou hodnotu, jinak vrací 0.
** Funkci je vhodné implementovat jedním příkazem return.
**/
	return L->Act != NULL; // ukazatel na aktivní prvek nesmí být NULL
}
