#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
	int mat;
	char nome[100];	
} Aluno; 

typedef struct turma {
	int max;
	int qa;
	Aluno alunos[];
} Turma;

Turma* criar_turma(int max) {

	Aluno alunos[max];
	Turma* turma = (Turma*) malloc(sizeof(Turma) + sizeof(Aluno)*max);

	turma->max = max;
	turma->qa = 0;

	return turma;
}

void incluirDesordenado(Turma *turma) {

	int cont;

	printf("\nInserir novo aluno:");
	do {
		if (turma->qa < turma->max) {
			printf("\nInforme a matrícula do aluno: ");
			scanf("%d", &turma->alunos[++turma->qa-1].mat);

			printf("\nInforme o nome do aluno: ");
			scanf("%s", turma->alunos[turma->qa-1].nome);

			printf("\nAluno Inserido com Sucesso :D\n");
		} else { 
			printf("\nA turma já está cheia :(\n");
			break;
		}

		printf("\nInserir outro Aluno ? (1-sim / 2-nao): ");
		scanf("%d", &cont);
	} while (cont == 1);

}

int procura(int mat, Turma* turma) {	
	for(int i = 0; i < turma->max; i++) {
		if(turma->alunos[i].mat == mat) {
			return i;
		}
	}
	return -1;
}

void mostrar(int pos, Turma* turma) {

	if(pos < turma->qa) {
		printf("Aluno: %d\nMatrícula: %d\nNome: %s", pos, turma->alunos[pos].mat, turma->alunos[pos].nome);
	} else {
		printf("\nNão há nenhum aluno nesta posição");
	}

}

void consultar(int mat, Turma* turma) {	
	int pos = procura(mat, turma);
	if(pos > -1) {
		mostrar(pos, turma);
	} else {
		printf("\nEste aluno não existe");
	}
}

//estrat�gia 1: colocar o ultimo elemento da lista na posi��o do elemento removido
void remover00(int pos, Turma* turma) {

	turma->alunos[pos] = turma->alunos[turma->qa-1];
	turma->qa--;

}

//estrat�gia 2: mover TODOS os elementos que est�o AP�S  o elemento que deve ser removido UMA POSI��O A FRENTE.
void remover01(int pos, Turma* turma) {

	if(pos == turma->max-1) turma->qa--;
	else {
		for(int i = pos; i <= turma->qa; i++) {
			turma->alunos[i] = turma->alunos[i+1];
		}
	}
	turma->qa--;
}

void remover(Turma* turma) {

	int mat, i, cont, achou, resp;
	do {
		printf("\n\nRemover aluno da turma:");
		printf("\nMatrícula do aluno: ");
		scanf("%d", &mat);

		achou = procura(mat, turma);
		if (achou != -1) {
			mostrar(achou, turma);
			printf("\nDeseja remover este aluno (1-sim/2-nao)? ");
			scanf("%d",&resp);

			if (resp==1) {
				// remover00(achou, turma);
				remover01(achou, turma);

				printf("\n\nitem removido com Sucesso!!!\n");
			} else {
				printf("\n\n\aO item nao foi removido!!!\n");
				break;
			}
		} else {
			printf("\n\naNumero de id Incorreto!!!!!!\n");
		}

		printf("\n\nRemover outro(1-sim/2-nao)? ");
		scanf("%d",&cont);
	} while (cont == 1);

}

int main() {
	Turma *turma = criar_turma(30);

	incluirDesordenado(turma);

	mostrar(0, turma);

	remover(turma);

	mostrar(0, turma);

	return 0;
}
