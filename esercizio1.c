#define _GNU_SOURCE_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

void termina(const char *s);

typedef struct el {
  int val;
  struct el *next;
} intero;

intero *crea_intero(int a)
{
    intero *c = malloc(sizeof(intero));
    if(c == NULL) termina("errore allocazione");
    c->val = a;
    c->next = NULL;
    return c;
}

void stampa_intero(intero *c, FILE *f)
{
    fprintf(f,"%d ", c->val);
}

void scrivi_lista(intero *lis, FILE *f)
{
  intero *el = lis; // el punta al primo elemento della lista
  while(el!=NULL) {
    stampa_intero(el,f);
    fprintf(f,"\n");
    el = el->next;
  }
  fprintf(f,"Fine lista città\n");
}

intero *leggi_intero(FILE *f)
{  
  char *spop=NULL;  // man getline per capire perche' questo e' necessario
  size_t npop=0;
  int e = getline(&spop,&npop,f);
  if(e== -1) return NULL;
  
  intero *c = crea_intero(atoi(spop));
  // dealloco i buffer e termino 
  free(spop);
  return c;
}

intero *aggiungi_intero(intero *lis, intero *z)
{
  //caso base
  if(lis==NULL) return z;// lista vuota, ora c'e' l'elemento z
    z->next = lis;
    return z;

  // caso in cui z non viene inserito in testa
  lis->next = aggiungi_intero(lis->next,z);
  return lis;
}

intero *inserisci_lista_da_file(FILE *f)
{
  assert(f!=NULL);
  intero *lis = NULL;
  intero *c;
  while(  (c = leggi_intero(f))!= NULL) {
    lis = aggiungi_intero(lis,c);
  }
  return lis;
}


int main(int argc, char **argv)
{
    if(argc!=2) {
      printf("Uso: %s file1\n",argv[0]);
      return 1;
    }

    FILE *f = fopen(argv[1], "rt");
    if(f==NULL) termina("impossibile aprire il file");

    intero *lis = inserisci_lista_da_file(f);
    fclose(f);
    scrivi_lista(lis, stdout);

    return 0;
}



void termina(const char *s)
{
    perror(s);
    exit(1);
}
