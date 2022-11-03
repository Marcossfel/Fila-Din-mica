#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct t_aluno
{
	int ra,faltas;
	float nota1,nota2;
};

typedef struct No{
	t_aluno dado;
	struct No *prox;
}No;

typedef struct Pilha{
	No *topo;
}Pilha;

void iniciaPilha( Pilha *p){
	p->topo = NULL;
	
}

void inseriPilha( t_aluno dado, Pilha *p){
	No *aux = (No*) malloc(sizeof(No));
	if(aux == NULL){
		printf("Erro de alocação.\n");
		return;
	} else {
		aux->dado = dado;
		aux->prox = p->topo;
		p->topo = aux;
	}
}

t_aluno removeElemento(Pilha *p){
	No *aux = p->topo;
	t_aluno dado;
	
	if(aux != NULL){
		printf("\tERRO: Fila vazia");
		return dado;
	} 
	else {
		p->topo = aux->prox;
		aux->prox = NULL;
		dado = aux->dado;
		free(aux);
		return dado;	
	}
}

void mostraPilha(Pilha *p){
	No *aux = p->topo;
	if( aux == NULL){
		
		printf("\tERRO: Pilha vazia");
		return;
		
	} else {
		while( aux != NULL){
			printf(" RA: %d", aux->dado.ra);
			printf(" NOTA1: %d", aux->dado.nota1);
			printf(" NOTA2: %d", aux->dado.nota2);
			printf(" FALTAS: %d", aux->dado.faltas);
			printf("\n");
			aux = aux->prox;
		
	}
}

t_aluno recebe_dados() //insercao dos dados
{
	t_aluno a;
	printf ("RA    :");
	scanf ("%d",&a.ra);
	printf ("NOTA1 :");
	scanf ("%f",&a.nota1);
	printf ("NOTA2 :");
	scanf ("%f",&a.nota2);
	printf ("FALTAS:");
	scanf ("%d",&a.faltas);
	return a;
}


int main(){
	Pilha *algoritimos = (Pilha*) malloc(sizeof(Pilha));
	iniciaPilha(algoritimos);
	char tecla;
	t_aluno aluno;
	
	
	while (tecla!='S' && tecla!='s')
	{
	  printf("[I]nserir [M]ostrar [R]emover [P]rimeiro [S]air\n");
	  tecla=getch(); 
	  if (tecla=='i' || tecla=='I')     
	  {
		aluno=recebe_dados();
		inseriPilha(aluno, algoritimos);		
	  } 
	  else if (tecla=='m' || tecla=='M')
	  {
	  	mostraPilha(algoritimos);
	  } 
	  else if (tecla=='r' || tecla=='R')
	  {
	  	removeElemento(algoritimos);
	  }
	  
	  else if (tecla=='s' || tecla=='S')
	  {
	   printf("Saindo\n");
	  } 
	  else
	  {
		printf("Opcao invalida\n");
	  }
	}
	return 0;
}
