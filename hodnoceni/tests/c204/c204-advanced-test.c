/**/
/* ************************* c204-advanced-test.c *************************** */
/*  Předmět: Algoritmy (IAL) - FIT VUT v Brně                                 */
/*  Úkol: c204 - Převod infixového výrazu na postfixový (s využitím c202)     */
/*  Referenční implementace: Petr Přikryl, listopad 1994                      */
/*  Vytvořil: Lukáš Maršík, Prosinec 2012                                     */
/*  Upravil: Bohuslav Křena, říjen 2016                                       */
/* ************************************************************************** */

/* Advanced testy pro c204.c */

#include "c204.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <assert.h>

char postExpr[MAX_LEN];           /* výstupní řetězec pro konvertovaný výraz*/

int solved;                                        /* indikátor řešení funkce */
int err_flag;                                              /* indikátor chyby */

/****************************************************************************** 
 * Speciální ošetření testovaných funkcí.                                     *
 ******************************************************************************/

/* Covert infix expression and verify result */ 
void convert_and_verify(char* infExpr, char* postExprOk)
{
  /* Arguments assertation */
  assert(infExpr != NULL);
  assert(postExprOk != NULL);
  assert(strlen(infExpr) <= MAX_LEN);
  assert(strlen(postExprOk) <= MAX_LEN);
  
  solved = 1;
  
  /* Print expression to be convert */
  printf("Original infix expression: %s\n", infExpr);
  
  /* Perform conversion */
  char* postExpr = infix2postfix(infExpr);
  
  /* Has function already started to be solved? */
  if (!solved) {
    printf("[W] Function infix2postfix hasn't been implemented yet.\n");
    return;
  }
  
  /* Test postfix string */
  if (postExpr == NULL) { // bad allocation or bad pointer returned
    printf("ERROR: NULL pointer returned.\n   You may have forgotten to return a correct pointer or\n   an error inside infix2postfix() occured.\n");// error message
  }
  else { // string is probably allocated
  
    /* Try to find zero character */
    char lastChar = postExpr[MAX_LEN-1]; // stored for future test
    postExpr[MAX_LEN-1] = 0; // just in case to have properly terminated string
    if (strlen(postExpr) >= (MAX_LEN-1) && lastChar != '0') { // charater array doesn't contain zero character, this case probably never happend (zero character is often present in unitialized array)
      printf("ERROR: String appears to be too long (exceeds %d characters).\n   Haven't you forgotten to include zero character?\n", MAX_LEN-1);
    }
    else { // string is OK in C language meaning
    
      /* Print converted expression and conversion result */
      printf("Your postfix expression:   %s\n\n", postExpr);
      printf("Conversion result match:   "); 
    
      /* Test strings match */
      if (strcmp(postExpr, postExprOk) != 0) { // conversion test failed
        printf("FAILED\n");
      }
      else { // conersion is finally OK
        printf("OK\n");
      }
    }
      
    free(postExpr); // free memory
  }
}
  

/****************************************************************************** 
 * Vlastní testování                                                          *
 ******************************************************************************/

int main (int argc, char* argv[]) {
	printf ("C204 - Infix to Postfix Expression Conversion - Basic Tests\n");
	printf ("-----------------------------------------------------------\n");

  printf("\n[TEST01] Expression conversion\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Aim: All lower case characters support\n\n");
  convert_and_verify("a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u+v+x+y+z=", "ab+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u+v+x+y+z+=");
  
  printf("\n[TEST02] Expression conversion\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Aim: All upper case characters support\n\n");
  convert_and_verify("A+B+C+D+E+F+G+H+I+J+K+L+M+N+O+P+Q+R+S+T+U+V+X+Y+Z=", "AB+C+D+E+F+G+H+I+J+K+L+M+N+O+P+Q+R+S+T+U+V+X+Y+Z+=");
  
  printf("\n[TEST03] Expression conversion\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Aim: All digits support\n\n");
  convert_and_verify("1+2+3+4+5+6+7+8+9+0=", "12+3+4+5+6+7+8+9+0+=");
  
  printf("\n[TEST04] Expression conversion\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Aim: Operands in extra parentheses\n\n");
  convert_and_verify("(a)+(b)=", "ab+=");
  
  printf("\n[TEST05] Expression conversion\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Aim: Expression in double extra parentheses\n\n");
  convert_and_verify("((a+b))=", "ab+=");
  
  printf("\n[TEST06] Expression conversion\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Aim: Expression evaluation form the left to the right also for minus operator\n\n");
  convert_and_verify("a-b-c=", "ab-c-=");
  
  printf("\n[TEST07] Expression conversion\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Aim: Expression evaluation form the left to the right also for multiply operator\n\n");
  convert_and_verify("a*b*c=", "ab*c*=");
  
  printf("\n[TEST08] Expression conversion\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Aim: Expression evaluation form the left to the right also for divide operator\n\n");
  convert_and_verify("a/b/c=", "ab/c/=");
  
  printf("\n[TEST09] Expression conversion\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Aim: Multiply operator has higher priority than plus (inverse order)\n\n");
  convert_and_verify("A+B*C=", "ABC*+=");
  
  printf("\n[TEST10] Expression conversion\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Aim: Divide operator has higher priority than minus (inverse order)\n\n");
  convert_and_verify("A-b/C=", "AbC/-=");
  
  printf("\n[TEST11] Expression conversion\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Aim: Paretntheses change operator priority\n\n");
  convert_and_verify("(A+b)/c=", "Ab+c/=");
  
  printf("\n[TEST12] Expression conversion\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Aim: Paretntheses change operator priority\n\n");
  convert_and_verify("(a-b)*C=", "ab-C*=");
  
  printf("\n[TEST13] Expression conversion\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Aim: Paretntheses change operator priority\n\n");
  convert_and_verify("a*(B*C)=", "aBC**=");
  
  printf("\n[TEST14] Expression conversion\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Aim: Paretntheses change operator priority\n\n");
  convert_and_verify("a+(B+c)=", "aBc++=");
  
  printf("\n[TEST15] Expression conversion\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Aim: Mixed operators expression\n\n");
  convert_and_verify("a+b*c-d=", "abc*+d-=");
  
  printf("\n[TEST16] Expression conversion\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Aim: Mixed operators expression with parenthesis\n\n");
  convert_and_verify("(a+b)*(c-d)=", "ab+cd-*=");
  
  printf("\n[TEST17] Expression conversion\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Aim: Mixed operators expression with parenthesis\n\n");
  convert_and_verify("a+b*(c-d)=", "abcd-*+=");
  
  printf("\n[TEST18] Expression conversion\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Aim: Mixed operators expression\n\n");
  convert_and_verify("a*b+c/d=", "ab*cd/+=");
  
  printf("\n[TEST19] Expression conversion\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Aim: Complex expression\n\n");
  convert_and_verify("(A*0+b/l)-((c+D)*(x)/k*8)*(e/(3*f/g+r/t*(j+o/p)))=", "A0*bl/+cD+x*k/8*e3f*g/rt/jop/+*+/*-=");
 
	printf("\n\n----- C204 - The End of Advanced Tests -----\n");

	return(0);
}


/* Konec c204-advanced-test.c */
/**/
