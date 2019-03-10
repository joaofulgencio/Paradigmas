//
// Created by joaooctf on 23/02/19.
//

#include <string.h>
#include <stdio.h>
#include <stdio_ext.h>
#include "matricula.h"
#include "menu.h"

void matricularAlunoNaDisciplina(DisciplinaList *listaDisciplina, char *disciplina, int turma, Aluno aluno) {
    Turma *t = buscaTurma(listaDisciplina, disciplina, turma);
    if (t->numeroDaTurma != 0) {
        insereAluno(t, aluno);
    } else {
        printf("Erro ao encontrar disciplina, a turma não existe!\n");
    }
}

void insereAluno(Turma *turma, Aluno aluno) {
    insertAlunoDisciplina(turma->listaAlunoDisciplina, aluno);
}


void matricularAlunos(DisciplinaList *lista, AlunoList *listaAluno) {
    menuMatricula();

    Aluno a;
    int ra;
    char disciplina[100];
    LoteMatricula matricula[15];
    int numeroMatricula = 0;
    int opcao = 0;
    int opcao2 = 0;
    int turma;
    int indexAlunos = 0;
    int indexDisciplinas = 0;

    do {
        printf("Informe o ra do aluno: ");
        scanf("%d", &ra);
        printf("Opções\n");
        printf("1- novo aluno\n");
        printf("2- Sair\n");
        scanf("%d", &opcao);
        if (opcao == 1) {
            Aluno *aluno = buscaAluno(listaAluno, ra);
            matricula[indexAlunos].aluno = *aluno;
            indexAlunos++;
        }
    } while (opcao == 1);

    do {
        printf("Informe a lista de disciplinas: ");
        __fpurge(stdin);
        scanf("%s", disciplina);

        for (int i = 0; i <= indexAlunos; i++) {
            strcpy(matricula[i].disciplinas[indexDisciplinas], disciplina);
        }

        printf("Opção\n");
        printf("1- Outra disciplina\n");
        printf("2- Sair");
        scanf("%d", &opcao2);
        if (opcao2 == 1) {
            indexDisciplinas++;
        }
    } while (opcao2 == 1);

    printf("Informe a turma: ");
    scanf("%d", &turma);

    for (int i = 0; i <= indexAlunos; i++) {
        for (int j = 0; j <= indexDisciplinas; j++) {
            matricularAlunoNaDisciplina(lista,
                                        matricula[i].disciplinas[j], turma, matricula[i].aluno);
        }
    }

}

