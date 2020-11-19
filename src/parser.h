/**
 * @file symtable.c
 *
 * Hlavičkový soubor pro parser
 *
 * IFJ Projekt 2020, Tým 2
 *
 * @author <xpolis04> Jan Polišenský
 */
#pragma once
#include<stdbool.h>
#include "symtable.h"
#include "scanner.h"
#include "basic.h"
#define STACK_DEFAULT 1000
#define DEBUG 0


                    // Velikost alokační jednotky zásobníku

/**
 * Pomocný zásobník k rekurzivnímu sestupu, probíhá na něm rozklad neterminálů na terminály
 */

typedef struct teminal{
  int k_w[20]; // keywords for check
  int used; // how many items are used
  bool k_check;
  token_type type;

}T_term;

// structure of syntax_stact
typedef struct SyntaxStack{
    T_term *t;   // Pole neterminálů/terminálů
    int size;
    int top;    // Index prvního volného místa
	int last;   // Index naposledy vloženého prvku
}*synt_stack;


// function prototypes

int       parser            ();
int       parser_debug      ();
int       scanner_debug     ();

void      stack_init        (synt_stack *stack, int err_code);
bool      stack_pop         (synt_stack stack, int err_code);
bool      stack_push        (synt_stack stack, T_term term, int err_code);
void      stack_remove      (synt_stack *stack);
bool      stack_compare     (synt_stack stack, tToken token, Symtable *table);
tList     syntactic_prerun  (Symtable *table);
char     *get_params        (tToken token);
char     *get_retvals       (tToken token);
int       generate_code     (tList list, Symtable *table);

void      stack_expand      (Symtable *table, synt_stack stack, tToken token ,int err_code);
void      senor_clean_fist  (Symtable *table, synt_stack stack, tList token_list);
void      all_fresh         ();
int       semantic_check    (Symtable *table, synt_stack stack, tList list, int err_code);
void      print_stack       (synt_stack stack);
bool      is_correct_kword  (char* id, int which[20], int used);
bool      is_fce            (char* id, Symtable *table);
bool      is_defined        (char* id, Symtable *table);
bool      is_predefined     (char* id, Symtable *table);
bool      is_in_stack       (synt_stack stack, token_type type);
void      id_check          (tToken func, Symtable *local_table, Symtable *table);
tToken    scope_check       (tToken scope, Symtable *global_table, Symtable *func_table);
void      id_add            (tToken token, Symtable *table);
bool      check_ok_params   (Symtable  *table, char* func, tToken token);
data_type get_data_type     (Symtable *table, tToken token);
void      parse_fc_params   (Symtable *table, tToken token);
void      multi_checker     (Symtable *table, tToken token);
void      check_multi_def   (Symtable *table, tToken token);
void      check_retvals     (Symtable *table, tToken token);
void      func_call_checker (Symtable *table, tToken token);
