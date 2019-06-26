#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

typedef struct{
    int totallogica,totaldiscreta1,totaldiscreta2,totalvetores,totaloac,totalintroducao;
    int totalcalculo1,totalcalculo2,totalcalculo3,totalalgoritmo;

}TotalDeCadaArea;

typedef struct{
    char nomedolivro[50];
    char nomedoautor[20];
    int codigo;
    int total;
    int quantidade;
}Livros;

typedef struct Aluno{
    int id;
    char nome[20];
    char cpf[11];
    int maxlivros; //vari�vel para testar se o aluno tem mais de 2 livros
    char livroemprestado1[50];
    char livroemprestado2[50];
    int livros[2];
    int dialivro1,meslivro1,anolivro1; //data do empr�stimo do livro1
    int dialivro2,meslivro2,anolivro2; //data do empr�stimo do livro2
    int dia1,mes1,ano1; //data m�xima para entrega do livro1
    int dia2,mes2,ano2; //data m�xima para entrega do livro2
    char DataDoSistema[12];
};

/*  QUANTIDADE DE LIVROS, ACERVO PADR�O */
int logica[2] = {15,15};
int matematica[2] = {15,15};
int introducao[2] = {15,15};
int algoritmo[2] = {15,15};
int calculo1[3] = {15,15,15};
int calculo2[2] = {15,15};
int calculo3[2] = {15,15};
int vetores[2] = {15,15};
int oac[2] = {15,15};

int ControleDeLivros = 0;
int auxControleDeLivros=0;
int j=0;
int cont = 0;
struct Aluno usu[1000];


//-------VARIAVEIS PARA CADASTRO DE LIVROS----------------------//
//int codigolivro;
//char nomelivro[30];
//char autor[30];
int flag=0;
int livrosiguais=0;
int contlivros = 0;
// ESTRUTURA //
Livros livroscadastrados[500];

///////////////////////
TotalDeCadaArea total;


///////////////////////
char testarnomeigual[20];

void NovoEmprestimo(int i, int nlivros);
int CadAluno(int cont);
void removerAluno(int cont);
void listar(int contador);
int cadLivro();
void editarlivro();
void alterar();


/*---------------------------- MENU PRINCIPAL ----------------------------------- */
int menuPrincipal(){

    int opcMenuPrincipal;
    do{
        system("cls");
        printf("\n\n");
        printf("            ######################################################################################################\n");
        printf("            #                     BIBLIOTECA DO CURSO DE COMPUTA��O                  %s                 #\n",__DATE__);
        printf("            ######################################################################################################\n");
        printf("\n\n\n");
        printf("                      (1) -> ACERVO\n\n");
        printf("                      (2) -> ALUNO\n\n");
        printf("                      (3) -> EMPR�STIMO\n\n");
        printf("                      (4) -> SAIR\n\n");
        printf("\n                      OP��O -> ");
        scanf("%d", &opcMenuPrincipal);

    }while(opcMenuPrincipal <1 && opcMenuPrincipal > 4);

    return opcMenuPrincipal;
}

/*-------------------------------ACERVO------------------------------------*/
void FuncAcervo(){
    int op;

    printf("\n            ########################################################################");
    printf("\n            #                             ACERVO                                   #");
    printf("\n            ########################################################################\n");
    printf("\n\n             (1) -> CADASTRAR LIVRO");
    printf("\n\n             (2) -> EDITAR LIVRO");
    printf("\n\n             (3) -> REMOVER LIVRO");
    printf("\n\n             (4) -> LISTAR LIVROS CADASTRADOS");
    printf("\n\n             (5) -> VOLTAR");

    printf("\n\n             OP��O -> ");
    scanf("%d", &op);
    switch(op){
        case 1:
            cadLivro();
            break;
        case 2:
            editarlivro();
            break;
        case 3:
            removerLivro();
            break;
        case 4:
            listarLivros();
            break;


    }
}
int cadLivro(){

    FILE *cadlivro;
    cadlivro = fopen("CadastroDeLivro.txt", "a");

    int op;
    int tam,k;

    system("cls");
    printf("\n          #######################################################################");
    printf("\n          #                           �REA DO LIVRO                             #");
    printf("\n          #######################################################################");
    printf("\n\n        (1) -> L�GICA DE PROGRAMA��O");
    printf("\n\n        (2) -> MATEM�TICA DISCRETA");
    printf("\n\n        (3) -> ALGORITMO");
    printf("\n\n        (4) -> INTRODU��O A COMPUTA��O");
    printf("\n\n        (5) -> ORGANIZA��O E ARQUITETURA DE COMPUTADORES");
    printf("\n\n        (6) -> C�LCULO");
    printf("\n\n        (7) -> VETORES E GEOMETRIA ANAL�TICA");
    printf("\n\n        (8) -> VOLTAR");
    printf("\n\n        OPC�O ->  ");
    scanf("%d", &op);
    system("cls");
    switch(op){
        case 1:
            setbuf(stdin,NULL);
            printf("\n          ###################################");
            printf("\n          #         CADASTRANDO LIVRO       #");
            printf("\n          ###################################\n\n");
            printf("\n          Informe o nome do autor: ");
            fgets(livroscadastrados[j].nomedoautor,20,stdin);
            setbuf(stdin,NULL);
            tam = strlen(livroscadastrados[j].nomedoautor);
            livroscadastrados[j].nomedoautor[tam-1]='\0';


            printf("\n          Informe o nome do livro: ");
            fgets(livroscadastrados[j].nomedolivro,20,stdin);
            setbuf(stdin,NULL);
            tam = strlen(livroscadastrados[j].nomedolivro);
            livroscadastrados[j].nomedolivro[tam-1]='\0';

            do{
                printf("\n          Informe o c�digo do livro: ");
                scanf("%d", &livroscadastrados[j].codigo);
                if(livroscadastrados[j].codigo <= 19 && livroscadastrados[j].codigo >0){
                    printf("\n          Este c�digo pertence � algum livro do acervo padr�o da biblioteca");
                    setbuf(stdin,NULL);
                    getch();
                    setbuf(stdin,NULL);
                }else{
                    if(livroscadastrados[j].codigo < 0){
                        printf("\n          O C�DIGO DO LIVRO N�O PODE SER N�MERO NEGATIVO");
                        setbuf(stdin,NULL);
                    }
                }
            }while(livroscadastrados[j].codigo <= 19);
            for(k=0;k<=contlivros; k++){
                if(livroscadastrados[j].codigo == livroscadastrados[k].codigo){
                    auxControleDeLivros += 1;
                }
            }
            if(auxControleDeLivros == 1){
                printf("\n          Quantidade: ");
                scanf("%d", &livroscadastrados[j].quantidade);
                printf("\n          LIVRO CADASTRADO COM SUCESSO");

                fprintf(cadlivro, "NOME DO AUTOR: ");
                fprintf(cadlivro, livroscadastrados[j].nomedoautor);
                fprintf(cadlivro, " NOME DO LIVRO: ");
                fprintf(cadlivro, livroscadastrados[j].nomedolivro);
                fprintf(cadlivro, " ID: ");
                fprintf(cadlivro,"%d", livroscadastrados[j].codigo);
                fprintf(cadlivro, " QUANTIDADE: ");
                fprintf(cadlivro,"%d", livroscadastrados[j].quantidade);
                fprintf(cadlivro, "\n");

                livroscadastrados[j].total += 1;
                ControleDeLivros += 1;
                flag = 1;
                total.totallogica += 1;
                contlivros += 1;
                j += 1;
            }else{
                printf("\n          C�DIGO J� CADASTRADO");
                Sleep(2000);
            }

            break;
        case 2:
            printf("\n          ###################################");
            printf("\n          #         CADASTRANDO LIVRO       #");
            printf("\n          ###################################\n\n");
            printf("\n          (1) -> MATEM�TICA DISCRETA 1");
            printf("\n          (2) -> MATEM�TICA DISCRETA 2");
            printf("\n\n          OP��O -> ");
            scanf("%d", &op);

            setbuf(stdin,NULL);
            printf("\n\n          Informe o nome do autor: ");
            fgets(livroscadastrados[j].nomedoautor,20,stdin);
            setbuf(stdin,NULL);
            tam = strlen(livroscadastrados[j].nomedoautor);
            livroscadastrados[j].nomedoautor[tam-1]='\0';

            printf("\n          Informe o nome do livro: ");
            fgets(livroscadastrados[j].nomedolivro,20,stdin);
            setbuf(stdin,NULL);
            tam = strlen(livroscadastrados[j].nomedolivro);
            livroscadastrados[j].nomedolivro[tam-1]='\0';

            do{
                printf("\n          Informe o c�digo do livro: ");
                scanf("%d", &livroscadastrados[j].codigo);
                if(livroscadastrados[j].codigo <= 19 && livroscadastrados[j].codigo >0){
                    printf("\n          Este c�digo pertence � algum livro do acervo padr�o da biblioteca");
                    setbuf(stdin,NULL);
                    getch();
                    setbuf(stdin,NULL);
                }else{
                    if(livroscadastrados[j].codigo < 0){
                        printf("\n          O C�DIGO DO LIVRO N�O PODE SER N�MERO NEGATIVO");
                        setbuf(stdin,NULL);

                    }
                }
            }while(livroscadastrados[j].codigo <= 19);
            for(k=0;k<=contlivros; k++){
                if(livroscadastrados[j].codigo == livroscadastrados[k].codigo){
                    auxControleDeLivros += 1;
                }
            }
            if(auxControleDeLivros == 1){
                printf("\n          Quantidade: ");
                scanf("%d", &livroscadastrados[j].quantidade);
                printf("\n          LIVRO CADASTRADO COM SUCESSO");
                livroscadastrados[j].total += 1;
                if(op==1){
                    total.totaldiscreta1 += 1;
                    fprintf(cadlivro, "NOME DO AUTOR: ");
                    fprintf(cadlivro, livroscadastrados[j].nomedoautor);
                    fprintf(cadlivro, " NOME DO LIVRO: ");
                    fprintf(cadlivro, livroscadastrados[j].nomedolivro);
                    fprintf(cadlivro, " ID: ");
                    fprintf(cadlivro,"%d", livroscadastrados[j].codigo);
                    fprintf(cadlivro, " QUANTIDADE: ");
                    fprintf(cadlivro,"%d", livroscadastrados[j].quantidade);
                    fprintf(cadlivro, "\n");
                }else{
                    if(op==2){
                        total.totaldiscreta2 += 1;
                        fprintf(cadlivro, "NOME DO AUTOR: ");
                        fprintf(cadlivro, livroscadastrados[j].nomedoautor);
                        fprintf(cadlivro, " NOME DO LIVRO: ");
                        fprintf(cadlivro, livroscadastrados[j].nomedolivro);
                        fprintf(cadlivro, " ID: ");
                        fprintf(cadlivro,"%d", livroscadastrados[j].codigo);
                        fprintf(cadlivro, " QUANTIDADE: ");
                        fprintf(cadlivro,"%d", livroscadastrados[j].quantidade);
                        fprintf(cadlivro, "\n");
                    }
                }
                ControleDeLivros += 1;
                flag = 1;
                contlivros += 1;
                j += 1;
            }else{
                printf("\n          C�DIGO J� CADASTRADO");
                Sleep(2000);
            }
            break;
        case 3:
            printf("\n          ###################################");
            printf("\n          #         CADASTRANDO LIVRO       #");
            printf("\n          ###################################\n\n");
            setbuf(stdin,NULL);
            printf("\n          Informe o nome do autor: ");
            fgets(livroscadastrados[j].nomedoautor,20,stdin);
            setbuf(stdin,NULL);
            tam = strlen(livroscadastrados[j].nomedoautor);
            livroscadastrados[j].nomedoautor[tam-1]='\0';

            printf("\n          Informe o nome do livro: ");
            fgets(livroscadastrados[j].nomedolivro,20,stdin);
            setbuf(stdin,NULL);
            tam = strlen(livroscadastrados[j].nomedolivro);
            livroscadastrados[j].nomedolivro[tam-1]='\0';

            do{
                printf("\n          Informe o c�digo do livro: ");
                scanf("%d", &livroscadastrados[j].codigo);
                if(livroscadastrados[j].codigo <= 19 && livroscadastrados[j].codigo >0){
                    printf("\n          Este c�digo pertence � algum livro do acervo padr�o da biblioteca");
                    setbuf(stdin,NULL);
                    getch();
                    setbuf(stdin,NULL);
                }else{
                    if(livroscadastrados[j].codigo < 0){
                        printf("\n          O C�DIGO DO LIVRO N�O PODE SER N�MERO NEGATIVO");
                        setbuf(stdin,NULL);

                    }
                }
            }while(livroscadastrados[j].codigo <= 19);
            for(k=0;k<=contlivros; k++){
                if(livroscadastrados[j].codigo == livroscadastrados[k].codigo){
                    auxControleDeLivros += 1;
                }
            }
            if(auxControleDeLivros == 1){
                printf("\n          Quantidade: ");
                scanf("%d", &livroscadastrados[j].quantidade);
                printf("\n          LIVRO CADASTRADO COM SUCESSO");

                fprintf(cadlivro, "NOME DO AUTOR: ");
                fprintf(cadlivro, livroscadastrados[j].nomedoautor);
                fprintf(cadlivro, " NOME DO LIVRO: ");
                fprintf(cadlivro, livroscadastrados[j].nomedolivro);
                fprintf(cadlivro, " ID: ");
                fprintf(cadlivro,"%d", livroscadastrados[j].codigo);
                fprintf(cadlivro, " QUANTIDADE: ");
                fprintf(cadlivro,"%d", livroscadastrados[j].quantidade);
                fprintf(cadlivro, "\n");

                livroscadastrados[j].total += 1;
                ControleDeLivros += 1;
                flag = 1;
                total.totalalgoritmo += 1;
                contlivros += 1;
                j += 1;
            }else{
                printf("\n          C�DIGO J� CADASTRADO");
                Sleep(2000);
            }
            break;
        case 4:
            printf("\n          ###################################");
            printf("\n          #         CADASTRANDO LIVRO       #");
            printf("\n          ###################################\n\n");
            setbuf(stdin,NULL);
            printf("\n          Informe o nome do autor: ");
            fgets(livroscadastrados[j].nomedoautor,20,stdin);
            setbuf(stdin,NULL);
            tam = strlen(livroscadastrados[j].nomedoautor);
            livroscadastrados[j].nomedoautor[tam-1]='\0';

            printf("\n          Informe o nome do livro: ");
            fgets(livroscadastrados[j].nomedolivro,20,stdin);
            setbuf(stdin,NULL);
            tam = strlen(livroscadastrados[j].nomedolivro);
            livroscadastrados[j].nomedolivro[tam-1]='\0';

            do{
                printf("\n          Informe o c�digo do livro: ");
                scanf("%d", &livroscadastrados[j].codigo);
                if(livroscadastrados[j].codigo <= 19 && livroscadastrados[j].codigo >0){
                    printf("\n          Este c�digo pertence � algum livro do acervo padr�o da biblioteca");
                    setbuf(stdin,NULL);
                    getch();
                    setbuf(stdin,NULL);
                }else{
                    if(livroscadastrados[j].codigo < 0){
                        printf("\n          O C�DIGO DO LIVRO N�O PODE SER N�MERO NEGATIVO");
                        setbuf(stdin,NULL);

                    }
                }
            }while(livroscadastrados[j].codigo <= 19);
            for(k=0;k<=contlivros; k++){
                if(livroscadastrados[j].codigo == livroscadastrados[k].codigo){
                    auxControleDeLivros += 1;
                }
            }
            if(auxControleDeLivros == 1){
                printf("\n          Quantidade: ");
                scanf("%d", &livroscadastrados[j].quantidade);
                printf("\n          LIVRO CADASTRADO COM SUCESSO");

                fprintf(cadlivro, "NOME DO AUTOR: ");
                fprintf(cadlivro, livroscadastrados[j].nomedoautor);
                fprintf(cadlivro, " NOME DO LIVRO: ");
                fprintf(cadlivro, livroscadastrados[j].nomedolivro);
                fprintf(cadlivro, " ID: ");
                fprintf(cadlivro,"%d", livroscadastrados[j].codigo);
                fprintf(cadlivro, " QUANTIDADE: ");
                fprintf(cadlivro,"%d", livroscadastrados[j].quantidade);
                fprintf(cadlivro, "\n");

                livroscadastrados[j].total += 1;
                ControleDeLivros += 1;
                flag = 1;
                total.totalintroducao += 1;
                contlivros += 1;
                j += 1;
            }else{
                printf("\n          C�DIGO J� CADASTRADO");
                Sleep(2000);
            }
            break;
        case 5:
            printf("\n          ###################################");
            printf("\n          #         CADASTRANDO LIVRO       #");
            printf("\n          ###################################\n\n");
            setbuf(stdin,NULL);
            printf("\n          Informe o nome do autor: ");
            fgets(livroscadastrados[j].nomedoautor,20,stdin);
            setbuf(stdin,NULL);
            tam = strlen(livroscadastrados[j].nomedoautor);
            livroscadastrados[j].nomedoautor[tam-1]='\0';

            printf("\n          Informe o nome do livro: ");
            fgets(livroscadastrados[j].nomedolivro,20,stdin);
            setbuf(stdin,NULL);
            tam = strlen(livroscadastrados[j].nomedolivro);
            livroscadastrados[j].nomedolivro[tam-1]='\0';

            do{
                printf("\n          Informe o c�digo do livro: ");
                scanf("%d", &livroscadastrados[j].codigo);
                if(livroscadastrados[j].codigo <= 19 && livroscadastrados[j].codigo >0){
                    printf("\n          Este c�digo pertence � algum livro do acervo padr�o da biblioteca");
                    setbuf(stdin,NULL);
                    getch();
                    setbuf(stdin,NULL);
                }else{
                    if(livroscadastrados[j].codigo < 0){
                        printf("\n          O C�DIGO DO LIVRO N�O PODE SER N�MERO NEGATIVO");
                        setbuf(stdin,NULL);
                    }
                }
            }while(livroscadastrados[j].codigo <= 19);
            for(k=0;k<=contlivros; k++){
                if(livroscadastrados[j].codigo == livroscadastrados[k].codigo){
                    auxControleDeLivros += 1;
                }
            }
            if(auxControleDeLivros == 1){
                printf("\n          Quantidade: ");
                scanf("%d", &livroscadastrados[j].quantidade);
                printf("\n          LIVRO CADASTRADO COM SUCESSO");

                fprintf(cadlivro, "NOME DO AUTOR: ");
                fprintf(cadlivro, livroscadastrados[j].nomedoautor);
                fprintf(cadlivro, " NOME DO LIVRO: ");
                fprintf(cadlivro, livroscadastrados[j].nomedolivro);
                fprintf(cadlivro, " ID: ");
                fprintf(cadlivro,"%d", livroscadastrados[j].codigo);
                fprintf(cadlivro, " QUANTIDADE: ");
                fprintf(cadlivro,"%d", livroscadastrados[j].quantidade);
                fprintf(cadlivro, "\n");

                livroscadastrados[j].total += 1;
                ControleDeLivros += 1;
                flag = 1;
                total.totaloac += 1;
                contlivros += 1;
                j += 1;
            }else{
                printf("\n          C�DIGO J� CADASTRADO");
                Sleep(2000);
            }
            break;
        case 6:
            printf("\n          (1) - > C�LCULO 1");
            printf("\n          (2) - > C�LCULO 2");
            printf("\n          (3) - > C�LCULO 3");
            printf("\n          OP��O -> ");
            scanf("%d", &op);
            printf("\n          ###################################");
            printf("\n          #         CADASTRANDO LIVRO       #");
            printf("\n          ###################################\n\n");
            setbuf(stdin,NULL);
            printf("\n          Informe o nome do autor: ");
            fgets(livroscadastrados[j].nomedoautor,20,stdin);
            setbuf(stdin,NULL);
            tam = strlen(livroscadastrados[j].nomedoautor);
            livroscadastrados[j].nomedoautor[tam-1]='\0';

            printf("\n          Informe o nome do livro: ");
            fgets(livroscadastrados[j].nomedolivro,20,stdin);
            setbuf(stdin,NULL);
            tam = strlen(livroscadastrados[j].nomedolivro);
            livroscadastrados[j].nomedolivro[tam-1]='\0';

            do{
                printf("\n          Informe o c�digo do livro: ");
                scanf("%d", &livroscadastrados[j].codigo);
                if(livroscadastrados[j].codigo <= 19 && livroscadastrados[j].codigo >0){
                    printf("\n          Este c�digo pertence � algum livro do acervo padr�o da biblioteca");
                    setbuf(stdin,NULL);
                    getch();
                    setbuf(stdin,NULL);
                }else{
                    if(livroscadastrados[j].codigo < 0){
                        printf("\n          O C�DIGO DO LIVRO N�O PODE SER N�MERO NEGATIVO");
                        setbuf(stdin,NULL);
                    }
                }
            }while(livroscadastrados[j].codigo <= 19);
            for(k=0;k<=contlivros; k++){
                if(livroscadastrados[j].codigo == livroscadastrados[k].codigo){
                    auxControleDeLivros += 1;
                }
            }
            if(auxControleDeLivros == 1){
                printf("\n          Quantidade: ");
                scanf("%d", &livroscadastrados[j].quantidade);
                printf("\n          LIVRO CADASTRADO COM SUCESSO");

                fprintf(cadlivro, "NOME DO AUTOR: ");
                fprintf(cadlivro, livroscadastrados[j].nomedoautor);
                fprintf(cadlivro, " NOME DO LIVRO: ");
                fprintf(cadlivro, livroscadastrados[j].nomedolivro);
                fprintf(cadlivro, " ID: ");
                fprintf(cadlivro,"%d", livroscadastrados[j].codigo);
                fprintf(cadlivro, " QUANTIDADE: ");
                fprintf(cadlivro,"%d", livroscadastrados[j].quantidade);
                fprintf(cadlivro, "\n");

                livroscadastrados[j].total += 1;
                ControleDeLivros += 1;
                flag = 1;
                contlivros += 1;
                j += 1;
                if(op==1){
                    total.totalcalculo1 += 1;
                }else{
                    if(op==2){
                        total.totalcalculo2 += 1;
                    }else{
                        if(op==3){
                            total.totalcalculo3 += 1;
                        }
                    }
                }
            }else{
                printf("\n          C�DIGO J� CADASTRADO");
                Sleep(2000);
            }
            break;
        case 7:
            printf("\n          ###################################");
            printf("\n          #         CADASTRANDO LIVRO       #");
            printf("\n          ###################################\n\n");
            setbuf(stdin,NULL);
            printf("\n          Informe o nome do autor: ");
            fgets(livroscadastrados[j].nomedoautor,20,stdin);
            setbuf(stdin,NULL);
            tam = strlen(livroscadastrados[j].nomedoautor);
            livroscadastrados[j].nomedoautor[tam-1]='\0';

            printf("\n          Informe o nome do livro: ");
            fgets(livroscadastrados[j].nomedolivro,20,stdin);
            setbuf(stdin,NULL);
            tam = strlen(livroscadastrados[j].nomedolivro);
            livroscadastrados[j].nomedolivro[tam-1]='\0';

            do{
                printf("\n          Informe o c�digo do livro: ");
                scanf("%d", &livroscadastrados[j].codigo);
                if(livroscadastrados[j].codigo <= 19 && livroscadastrados[j].codigo >0){
                    printf("\n          Este c�digo pertence � algum livro do acervo padr�o da biblioteca");
                    setbuf(stdin,NULL);
                    getch();
                    setbuf(stdin,NULL);
                }else{
                    if(livroscadastrados[j].codigo < 0){
                        printf("\n          O C�DIGO DO LIVRO N�O PODE SER N�MERO NEGATIVO");
                        setbuf(stdin,NULL);
                    }
                }
            }while(livroscadastrados[j].codigo <= 19);
            for(k=0;k<=contlivros; k++){
                if(livroscadastrados[j].codigo == livroscadastrados[k].codigo){
                    auxControleDeLivros += 1;
                }
            }
            if(auxControleDeLivros == 1){
                printf("\n          Quantidade: ");
                scanf("%d", &livroscadastrados[j].quantidade);
                printf("\n          LIVRO CADASTRADO COM SUCESSO");

                fprintf(cadlivro, "NOME DO AUTOR: ");
                fprintf(cadlivro, livroscadastrados[j].nomedoautor);
                fprintf(cadlivro, " NOME DO LIVRO: ");
                fprintf(cadlivro, livroscadastrados[j].nomedolivro);
                fprintf(cadlivro, " ID: ");
                fprintf(cadlivro,"%d", livroscadastrados[j].codigo);
                fprintf(cadlivro, " QUANTIDADE: ");
                fprintf(cadlivro,"%d", livroscadastrados[j].quantidade);
                fprintf(cadlivro, "\n");

                livroscadastrados[j].total += 1;
                ControleDeLivros += 1;
                flag = 1;
                total.totalvetores += 1;
                contlivros += 1;
                j += 1;
            }else{
                printf("\n          C�DIGO J� CADASTRADO");
                Sleep(2000);
            }

    }
    getch();
    setbuf(stdin,NULL);
    auxControleDeLivros = 0;

    fclose(cadlivro);
}

void editarlivro(){
    int auxCod;
    int i,op;
    int tam;

    setbuf(stdin,NULL);
    listarLivros();

    printf("\n\n            Informe o c�digo do livro a ser modificado: ");
    scanf("%d", &auxCod);
    for(i=0;i<contlivros;i++){
        if(auxCod == livroscadastrados[i].codigo){
            printf("\n          INFORME O DADO A SER ALTERADO\n");
            printf("\n          (1) -> C�digo do livro");
            printf("\n          (2) -> Nome do autor");
            printf("\n          (3) -> Nome do livro");
            printf("\n          OP��O -> ");
            scanf("%d", &op);
            system("cls");
            switch(op){
                case 1:
                    printf("\n          ###########################################################");
                    printf("\n          #                    EDITANDO LIVRO                       #");
                    printf("\n          ###########################################################\n");
                    printf("\n            Informe o novo c�digo do livro: ");
                    scanf("%d", &livroscadastrados[i].codigo);
                    printf("\n\n            PRESSIONE QUALQUER TECLA PARA VOLTAR...");

                    break;
                case 2:
                    setbuf(stdin,NULL);
                    printf("\n          ###########################################################");
                    printf("\n          #                    EDITANDO LIVRO                       #");
                    printf("\n          ###########################################################\n");
                    printf("            Informe o novo nome do autor: ");
                    fgets(livroscadastrados[i].nomedoautor,20,stdin);
                    tam = strlen(livroscadastrados[i].nomedoautor);
                    livroscadastrados[i].nomedoautor[tam-1]='\0';
                    printf("\n\n            PRESSIONE QUALQUER TECLA PARA VOLTAR...");
                    break;
                case 3:
                    setbuf(stdin,NULL);
                    printf("\n          ###########################################################");
                    printf("\n          #                    EDITANDO LIVRO                       #");
                    printf("\n          ###########################################################\n");
                    printf("\n          Informe o novo nome do livro: ");
                    fgets(livroscadastrados[i].nomedolivro,20,stdin);
                    setbuf(stdin,NULL);
                    tam = strlen(livroscadastrados[i].nomedolivro);
                    livroscadastrados[i].nomedolivro[tam-1]='\0';
                    printf("\n\n            PRESSIONE QUALQUER TECLA PARA VOLTAR...");
                    break;

            }

        }
        getch();
        setbuf(stdin,NULL);

    }
}

void listarLivros(){
    int i;
    system("cls");
    printf("\n          #######################################################################");
    printf("\n          #                          LIVROS CADASTRADOS                         #");
    printf("\n          #######################################################################\n\n");
    printf("    NOME DO LIVRO               NOME DO AUTOR               C�DIGO DO LIVRO               QUANTIDADE\n");
    for(i=0; i<=contlivros; i++){
        if(livroscadastrados[i].codigo != 0){
            printf("\n  %s \t\t\t %s \t\t\t\t %d \t\t\t %d", livroscadastrados[i].nomedolivro,livroscadastrados[i].nomedoautor, livroscadastrados[i].codigo, livroscadastrados[i].quantidade);
        }
    }
    getch();
    setbuf(stdin,NULL);
}

void removerLivro(){

    int i;
    int auxCod;

    system("cls");
    listarLivros();

    printf("\n\n\n            Informe o c�digo do livro a ser removido: ");
    scanf("%d", &auxCod);
    for(i=0;i<=contlivros;i++){
        if(auxCod == livroscadastrados[i].codigo){
            livroscadastrados[i].codigo = 0;
        }
    }


    j -= 1;
    contlivros -= 1;
    printf("\n          LIVRO REMOVIDO");
    Sleep(1500);
}







/*-----------------------------EMPR�STIMO--------------------------------*/

void FuncEmprestimo(){
    int opcEmprestimo;
    int auxID,i;
    int UsuarioNaoEncontrado=0;
    //int nlivros; //variavel para guardar a qntd de livros que o aluno tem.
    //---------------------------OP��O 3 NO MENU PRINCIPAL------------------------------
    do{
        system("cls");
        printf("\n          #######################################################################");
        printf("\n          #                           EMPR�STIMO                                #");
        printf("\n          #######################################################################");
        printf("\n\n          (1) -> NOVO EMPR�STIMO");
        printf("\n\n          (2) -> CONFIRMAR DEVOLU��O");
        printf("\n\n          (3) -> CANCELAR EMPR�STIMO");
        printf("\n\n          (4) -> LISTAR EMPR�STIMO");
        printf("\n\n          (5) -> VOLTAR");
        printf("\n\n          OP��O -> ");
        scanf("%d", &opcEmprestimo);
        system("cls");
        switch(opcEmprestimo){
        case 1:
            listar(cont);
            printf("\n          Para um novo empr�stimo, informe o ID do aluno: ");
            scanf("%d", &auxID);
            for(i=0;i<cont;i++){
                if(auxID == usu[i].id && (usu[i].maxlivros <2)){
                    printf("\n          USU�RIO ENCONTRADO");
                    printf("\n\n            Aguarde.");
                    Sleep(800);
                    printf(".");
                    Sleep(800);
                    printf(".");
                    NovoEmprestimo(i,usu[i].maxlivros);
                }else{
                    if(auxID == usu[i].id && (usu[i].maxlivros >=2)){
                        printf("\n          USU�RIO ENCONTRADO, POR�M, J� EXCEDEU O N�MERO DE EMPR�STIMOS");
                        printf("\n\n            Aguarde.");
                        Sleep(1500);
                        printf(".");
                        Sleep(1500);
                        printf(".");
                    }else{
                       UsuarioNaoEncontrado += 1;
                    }
                }
            }
            if(UsuarioNaoEncontrado == (cont-1)){
                printf("\n          USU�RIO N�O ENCONTRADO!");
            }
            break;
        case 2:
            listar(cont);
            printf("\n          Informe o ID do usu�rio que pretende fazer a devolu��o: ");
            scanf("%d", &auxID);
            for(i=0;i<cont;i++){
                if(auxID == usu[i].id && usu[i].maxlivros > 0){
                    printf("\n          USU�RIO ENCONTRADO!");
                    printf("\n\n            Aguarde.");
                    Sleep(800);
                    printf(".");
                    Sleep(800);
                    printf(".");
                    system("cls");
                    devolucao(i);
                }else{
                    if(auxID == usu[i].id && usu[i].maxlivros == 0){
                        printf("\n\n            USU�RIO ENCONTRADO, POR�M, N�O EST� COM NENHUM LIVRO");
                        printf("\n\n            Aguarde.");
                        Sleep(1500);
                        printf(".");
                        Sleep(1500);
                        printf(".");
                    }
                }
            }


            break;
        case 3:
            listar(cont);
            printf("\n          Informe o ID do usu�rio que pretende cancelar o empr�stimo: ");
            scanf("%d", &auxID);
            for(i=0;i<cont;i++){
                if(auxID == usu[i].id && usu[i].maxlivros > 0){
                    printf("\n          USU�RIO ENCONTRADO!");
                    printf("\n\n            Aguarde.");
                    Sleep(800);
                    printf(".");
                    Sleep(800);
                    printf(".");
                    system("cls");
                    cancelarEmp(i);
                }else{
                    if(auxID == usu[i].id && usu[i].maxlivros == 0){
                        printf("\n\n            USU�RIO ENCONTRADO, POR�M, N�O EST� COM NENHUM LIVRO");
                        printf("\n\n            Aguarde.");
                        Sleep(1500);
                        printf(".");
                        Sleep(1500);
                        printf(".");
                    }
                }
            }
            break;
        case 4:
            listar(cont);
            printf("\n          Informe o ID do usu�rio para listar seus empr�stimos: ");
            scanf("%d", &auxID);
            for(i=0;i<cont;i++){
                if(auxID == usu[i].id && usu[i].maxlivros > 0){
                    printf("\n          USU�RIO ENCONTRADO!");
                    printf("\n\n            Aguarde.");
                    Sleep(800);
                    printf(".");
                    Sleep(800);
                    printf(".");
                    system("cls");
                    listarEmp(i);
                }else{
                    if(auxID == usu[i].id && usu[i].maxlivros == 0){
                        printf("\n\n            USU�RIO ENCONTRADO, POR�M, N�O EST� COM NENHUM LIVRO");
                        printf("\n\n            Aguarde.");
                        Sleep(1500);
                        printf(".");
                        Sleep(1500);
                        printf(".");
                    }
                }
            }
            break;

        }
    }while(opcEmprestimo != 5);
}

void devolucao(int i){
    FILE *file;
    file = fopen("Alunos.txt", "w");
    int op;

    if(usu[i].maxlivros > 0){
        if((usu[i].dia1 >= usu[i].dia1 + 10) || (usu[i].dia1 == usu[i].dialivro1 )){
            printf("\n          #######################################################################");
            printf("\n          # AVISO, PRAZO FINAL PARA ENTREGA DO LIVRO                            #");
            printf("\n          # LIVRO: %s                                            #", usu[i].livroemprestado1);
            printf("\n          #######################################################################");
        }
    }else{
        if(usu[i].maxlivros > 1){
            if((usu[i].dia2 >= usu[i].dia2 + 10) || (usu[i].dia2 == usu[i].dialivro2 )){
                printf("\n          #######################################################################");
                printf("\n          # AVISO, PRAZO FINAL PARA ENTREGA DO LIVRO                            #");
                printf("\n          # LIVRO: %s                                     #", usu[i].livroemprestado1);
                printf("\n          #######################################################################");
            }else{
                if((usu[i].dia1 >= usu[i].dia1 + 10) || (usu[i].dia1 == usu[i].dialivro1 )){
                    printf("\n          #######################################################################");
                    printf("\n          # AVISO, PRAZO FINAL PARA ENTREGA DO LIVRO                            #");
                    printf("\n          # LIVRO: %s                                             #", usu[i].livroemprestado1);
                    printf("\n          #######################################################################");
                }
            }
        }
    }

        do{
            printf("\n");
            printf("\n          ###################################");
            printf("\n          #         DEVOLVENDO LIVRO       #");
            printf("\n          ###################################\n\n");
            printf("\n          Informe qual livro deseja devolver");
            printf("\n          1 - %s", usu[i].livroemprestado1);
            if(usu[i].maxlivros > 1){
                printf("\n          2 - %s", usu[i].livroemprestado2);
            }
            printf("\n          OP��O -> ");
            scanf("%d", &op);
        }while(op != 1 && op != 2);
            if(op == 1){
                switch(usu[i].livros[0]){
                    case 1:
                        logica[0] += 1;
                        break;
                    case 2:
                        logica[1] += 1;
                        break;
                    case 3:
                        matematica[0] += 1;
                        break;
                    case 4:
                        matematica[1] += 1;
                        break;
                    case 5:
                        algoritmo[0] += 1;
                        break;
                    case 6:
                        algoritmo[1] += 1;
                        break;
                    case 7:
                        introducao[0] += 1;
                        break;
                    case 8:
                        introducao[1] += 1;
                        break;
                    case 9:
                        oac[0] += 1;
                        break;
                    case 10:
                        oac[1] += 1;
                        break;
                    case 11:
                        calculo1[0] += 1;
                        break;
                    case 12:
                        calculo1[1] += 1;
                        break;
                    case 13:
                        calculo1[2] += 1;
                        break;
                    case 14:
                        calculo2[0] += 1;
                        break;
                    case 15:
                        calculo2[1] += 1;
                        break;
                    case 16:
                        calculo3[0] += 1;
                        break;
                    case 17:
                        calculo3[1] += 1;
                        break;
                    case 18:
                        vetores[0] += 1;
                        break;
                    case 19:
                        vetores[1] += 1;
                        break;
                }
                for(int j=0;j<ControleDeLivros; j++){
                    if(livroscadastrados[j].codigo == usu[i].livros[0]){
                        livroscadastrados[j].quantidade += 1;
                    }
                }
                usu[i].livros[0] = usu[i].livros[1];
                usu[i].livros[1] = 0;
                strcpy(usu[i].livroemprestado1, usu[i].livroemprestado2);
                strcpy(usu[i].livroemprestado2,"vazio");
                usu[i].maxlivros -= 1;

                for(int x=0; x<cont; x++){
                    if(usu[x].id == NULL){

                    }else{
                        fprintf(file, "NOME: ");
                        fprintf(file, usu[x].nome);
                        fprintf(file, "ID: ");
                        fprintf(file, "%d", usu[x].id);
                        fprintf(file, " LIVROS: ");
                        fprintf(file, "%d", usu[x].maxlivros);
                        fprintf(file, "\n");
                    }
                }
                fclose(file);
                usu[i].dia1 = 0;
                printf("\n          LIVRO DEVOLVIDO!");
                Sleep(3000);
                return;
            }else{
                switch(usu[i].livros[1]){
                    case 1:
                        logica[0] += 1;
                        break;
                    case 2:
                        logica[1] += 1;
                        break;
                    case 3:
                        matematica[0] += 1;
                        break;
                    case 4:
                        matematica[1] += 1;
                        break;
                    case 5:
                        algoritmo[0] += 1;
                        break;
                    case 6:
                        algoritmo[1] += 1;
                        break;
                    case 7:
                        introducao[0] += 1;
                        break;
                    case 8:
                        introducao[1] += 1;
                        break;
                    case 9:
                        oac[0] += 1;
                        break;
                    case 10:
                        oac[1] += 1;
                        break;
                    case 11:
                        calculo1[0] += 1;
                        break;
                    case 12:
                        calculo1[1] += 1;
                        break;
                    case 13:
                        calculo1[2] += 1;
                        break;
                    case 14:
                        calculo2[0] += 1;
                        break;
                    case 15:
                        calculo2[1] += 1;
                        break;
                    case 16:
                        calculo3[0] += 1;
                        break;
                    case 17:
                        calculo3[1] += 1;
                        break;
                    case 18:
                        vetores[0] += 1;
                        break;
                    case 19:
                        vetores[1] += 1;
                        break;
                }
                for(int j=0;j<ControleDeLivros; j++){
                    if(livroscadastrados[j].codigo == usu[i].livros[1]){
                        livroscadastrados[j].quantidade += 1;
                    }
                }
                usu[i].livroemprestado2[50] = NULL;
                usu[i].maxlivros -= 1;
                for(int x=0; x<cont; x++){
                    if(usu[x].id == NULL){

                        }else{
                            fprintf(file, "NOME: ");
                            fprintf(file, usu[x].nome);
                            fprintf(file, "ID: ");
                            fprintf(file, "%d", usu[x].id);
                            fprintf(file, " LIVROS: ");
                            fprintf(file, "%d", usu[x].maxlivros);
                            fprintf(file, "\n");
                        }
                    }
                    fclose(file);
                    usu[i].dia2 = 0;
                    printf("\n          LIVRO DEVOLVIDO!");

            }

    Sleep(3000);
}

void cancelarEmp(int i){
    FILE *file;
    file = fopen("Alunos.txt", "w");
    int op;
    int var = 19;
    if(usu[i].maxlivros > 0){

        do{
            printf("\n");
            printf("\n          ###################################");
            printf("\n          #        CANCELAR EMPR�STIMO      #");
            printf("\n          ###################################\n\n");
            printf("\n          Informe qual livro deseja cancelar o empr�stimo");
            printf("\n          1 - %s", usu[i].livroemprestado1);
            if(usu[i].maxlivros > 1){
                printf("\n          2 - %s", usu[i].livroemprestado2);
            }
            printf("\n          OP��O -> ");
            scanf("%d", &op);
        }while(op != 1 && op != 2);
            if(op == 1){
                switch(usu[i].livros[0]){
                    case 1:
                        logica[0] += 1;
                        break;
                    case 2:
                        logica[1] += 1;
                        break;
                    case 3:
                        matematica[0] += 1;
                        break;
                    case 4:
                        matematica[1] += 1;
                        break;
                    case 5:
                        algoritmo[0] += 1;
                        break;
                    case 6:
                        algoritmo[1] += 1;
                        break;
                    case 7:
                        introducao[0] += 1;
                        break;
                    case 8:
                        introducao[1] += 1;
                        break;
                    case 9:
                        oac[0] += 1;
                        break;
                    case 10:
                        oac[1] += 1;
                        break;
                    case 11:
                        calculo1[0] += 1;
                        break;
                    case 12:
                        calculo1[1] += 1;
                        break;
                    case 13:
                        calculo1[2] += 1;
                        break;
                    case 14:
                        calculo2[0] += 1;
                        break;
                    case 15:
                        calculo2[1] += 1;
                        break;
                    case 16:
                        calculo3[0] += 1;
                        break;
                    case 17:
                        calculo3[1] += 1;
                        break;
                    case 18:
                        vetores[0] += 1;
                        break;
                    case 19:
                        vetores[1] += 1;
                        break;
                }
                for(int j=0;j<ControleDeLivros; j++){
                    if(livroscadastrados[j].codigo == usu[i].livros[0]){
                        livroscadastrados[j].quantidade += 1;
                    }
                }
                usu[i].livros[0] = usu[i].livros[1];
                usu[i].livros[1] = 0;
                strcpy(usu[i].livroemprestado1, usu[i].livroemprestado2);
                strcpy(usu[i].livroemprestado2,"vazio");
                usu[i].maxlivros -= 1;
                for(int x=0; x<cont; x++){
                    if(usu[x].id == NULL){

                    }else{
                        fprintf(file, "NOME: ");
                        fprintf(file, usu[x].nome);
                        fprintf(file, "ID: ");
                        fprintf(file, "%d", usu[x].id);
                        fprintf(file, " LIVROS: ");
                        fprintf(file, "%d", usu[x].maxlivros);
                        fprintf(file, "\n");
                    }
                }
                fclose(file);
                printf("\n          EMPR�STIMO CANCELADO, LIVRO DEVOLVIDO!");
                Sleep(3000);
                return;
            }else{
        // aqui
                    switch(usu[i].livros[1]){
                    case 1:
                        logica[0] += 1;
                        break;
                    case 2:
                        logica[1] += 1;
                        break;
                    case 3:
                        matematica[0] += 1;
                        break;
                    case 4:
                        matematica[1] += 1;
                        break;
                    case 5:
                        algoritmo[0] += 1;
                        break;
                    case 6:
                        algoritmo[1] += 1;
                        break;
                    case 7:
                        introducao[0] += 1;
                        break;
                    case 8:
                        introducao[1] += 1;
                        break;
                    case 9:
                        oac[0] += 1;
                        break;
                    case 10:
                        oac[1] += 1;
                        break;
                    case 11:
                        calculo1[0] += 1;
                        break;
                    case 12:
                        calculo1[1] += 1;
                        break;
                    case 13:
                        calculo1[2] += 1;
                        break;
                    case 14:
                        calculo2[0] += 1;
                        break;
                    case 15:
                        calculo2[1] += 1;
                        break;
                    case 16:
                        calculo3[0] += 1;
                        break;
                    case 17:
                        calculo3[1] += 1;
                        break;
                    case 18:
                        vetores[0] += 1;
                        break;
                    case 19:
                        vetores[1] += 1;
                        break;

                }
                 for(int j=0;j<ControleDeLivros; j++){
                    if(livroscadastrados[j].codigo == usu[i].livros[1]){
                        livroscadastrados[j].quantidade += 1;
                    }
                }




                //
                    usu[i].livroemprestado2[50] = NULL;
                    usu[i].maxlivros -= 1;
                    for(int x=0; x<cont; x++){
                        if(usu[x].id == NULL){

                        }else{
                            fprintf(file, "NOME: ");
                            fprintf(file, usu[x].nome);
                            fprintf(file, "ID: ");
                            fprintf(file, "%d", usu[x].id);
                            fprintf(file, " LIVROS: ");
                            fprintf(file, "%d", usu[x].maxlivros);
                            fprintf(file, "\n");
                        }
                    }
                    fclose(file);
                    printf("\n          EMPR�STIMO CANCELADO, LIVRO DEVOLVIDO!");

            }
    }

    Sleep(3000);
}

void listarEmp(int i){

        printf("\n          Empr�stimos do(a) aluno(a) %s", usu[i].nome);
        printf("\n          1 - %s                      Data do empr�stimo: %02d/%02d/%d", usu[i].livroemprestado1, usu[i].dialivro1,usu[i].meslivro1,usu[i].anolivro1);
        printf("\n                                                          Data m�xima para entrega: %02d/%02d/%d", usu[i].dia1, usu[i].mes1, usu[i].ano1);
        if(usu[i].maxlivros > 1){
            printf("\n          2 - %s                      Data do empr�stimo: %d/%d/%d", usu[i].livroemprestado2, usu[i].dialivro2,usu[i].meslivro2,usu[i].anolivro2);
            printf("\n                                                            Data m�xima para entrega: %02d/%02d/%d", usu[i].dia2, usu[i].mes2, usu[i].ano2);
        }

        printf("\n\n\n            PRESSIONE QUALQUER TECLA PARA VOLTAR...\n");
        setbuf(stdin,NULL);
        getch();
        setbuf(stdin,NULL);
}

void NovoEmprestimo(int i, int nlivros){
    /* ACERVO PADR�O                                            NUMERA��O
    logica para principiantes                                       1
    aprendendo logica                                               2
    fundamentos da matematica discreta                              3
    matematica discreta para computacao                             4
    algoritmos teoria e pratica                                     5
    introducao a programacao                                        6
    ciencia da computacao: uma visao abrangente                     7
    introducao a informatica                                        8
    arquitetura e organizacao de computadores                       9
    fundamentos da arquitetura de computadores                      10
    calculo. para entender e para usar                              11
    calculo - volume 1                                              12
    um curso de calculo - volume 1                                  13
    calculo - volume 2                                              14
    um curso de calculo - volume 2                                  15
    calculo - funcoes de uma e varias variaveis                     16
    um curso de calculo - volume 3                                  17
    vetores e geometrica analitica                                  18
    vetores e uma iniciacao a geometria analitica                   19
    */
    FILE *file;
    file = fopen("Alunos.txt", "w");
    int opcNovoEmprestimo,livro;
    char auxEmp[50];
    int tam;
    int x=4; //numera��o do livro no menu
    int emprestimo = 0;
    char auxNovolivro[30];

    system("cls");
    printf("\n          ###########################################################");
    printf("\n          #                INFORME A �REA DO LIVRO:                 #");
    printf("\n          ###########################################################");
    printf("\n\n              (1) -> L�GICA DE PROGRAMA��O");
    printf("\n\n              (2) -> MATEM�TICA DISCRETA");
    printf("\n\n              (3) -> ALGORITMO");
    printf("\n\n              (4) -> INTRODU��O A COMPUTA��O");
    printf("\n\n              (5) -> ORGANIZA��O E ARQUITETURA DE COMPUTADORES");
    printf("\n\n              (6) -> C�LCULO");
    printf("\n\n              (7) -> VETORES E GEOMETRIA ANAL�TICA");
    printf("\n\n              (8) -> VOLTAR");
    printf("\n\n              OPC�O ->  ");
    scanf("%d", &opcNovoEmprestimo);
    system("cls");

    switch(opcNovoEmprestimo){
        case 1:

            printf("\n          ###############################################################");
            printf("\n          #                     L�GICA DE PROGRAMA��O                   #");
            printf("\n          ###############################################################");
            printf("\n\n            LIVROS                                       QUANTIDADE\n");
            if(logica[0]>0){
                printf("\n          logica para principiantes                            %d",logica[0]);
            }else{
                printf("\n          logica para principiantes                            0");
            }
            if(logica[1]>0){
                printf("\n          aprendendo logica                                    %d",logica[1]);
            }else{
                printf("\n          aprendendo logica                                    0");
            }

            for(int j=0;j<total.totallogica; j++)
                printf("\n          %s \t\t\t\t\t       %d", livroscadastrados[j].nomedolivro, livroscadastrados[j].quantidade);

            printf("\n          ###############################################################\n");
            printf("\n          Informe o nome do livro -> ");
            setbuf(stdin,NULL);
            fgets(auxEmp,50,stdin);
            tam = strlen(auxEmp);
            auxEmp[tam-1] = '\0';
            if((strcmp(auxEmp,"logica para principiantes")==0) && logica[0]>0){
                logica[0] -= 1;
                if(nlivros == 0){ // se o aluno n�o tem nenhum livro, este ser� o primeiro
                    strcpy(usu[i].livroemprestado1,"logica para principiantes");
                    usu[i].livros[0] = 1; //controle de livro devolvido
                    printf("\n          Data do empr�stimo -> Dia: ");
                    scanf("%d", &usu[i].dialivro1);
                    printf("                             -> M�s: ");
                    scanf("%d", &usu[i].meslivro1);
                    printf("                             -> Ano: ");
                    scanf("%d", &usu[i].anolivro1);
                    printf("\n          Data limite para devolu��o -> Dia: ");
                    scanf("%d", &usu[i].dia1);
                    printf("                                     -> M�s: ");
                    scanf("%d", &usu[i].mes1);
                    printf("                                     -> Ano: ");
                    scanf("%d", &usu[i].ano1);
                }else{
                    strcpy(usu[i].livroemprestado2,"logica para principiantes");
                    usu[i].livros[1] = 1;
                    printf("\n          Data do empr�stimo -> Dia: ");
                    scanf("%d", &usu[i].dialivro2);
                    printf("                            -> M�s: ");
                    scanf("%d", &usu[i].meslivro2);
                    printf("                            -> Ano: ");
                    scanf("%d", &usu[i].anolivro2);
                    printf("\n          Data limite para devolu��o -> Dia: ");
                    scanf("%d", &usu[i].dia2);
                    printf("                                     -> M�s: ");
                    scanf("%d", &usu[i].mes2);
                    printf("                                     -> Ano: ");
                    scanf("%d", &usu[i].ano2);
                }
                usu[i].maxlivros += 1;
                printf("\n\n            EMPR�STIMO BEM SUCEDIDO");
            }else{
                if((strcmp(auxEmp,"aprendendo logica")==0) && logica[1]>0){
                    logica[1] -= 1;
                    if(nlivros == 0){
                        strcpy(usu[i].livroemprestado1,"aprendendo logica");
                        usu[i].livros[0] = 2;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro1);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro1);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro1);
                        printf("\n          Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia1);
                        printf("                                     -> M�s: ");
                        scanf("%d", &usu[i].mes1);
                        printf("                                     -> Ano: ");
                        scanf("%d", &usu[i].ano1);
                    }else{
                        strcpy(usu[i].livroemprestado2,"aprendendo logica");
                        usu[i].livros[1] = 2;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro2);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro2);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro2);
                        printf("\n          Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia2);
                        printf("                                     -> M�s: ");
                        scanf("%d", &usu[i].mes2);
                        printf("                                     -> Ano: ");
                        scanf("%d", &usu[i].ano2);
                    }
                    usu[i].maxlivros += 1;
                    printf("\n          EMPR�STIMO BEM SUCEDIDO");
                }else{
                    for(int j=0;j<total.totallogica; j++){
                        if((strcmp(auxEmp,livroscadastrados[j].nomedolivro)==0)){
                            livroscadastrados[j].quantidade -= 1;
                            if(nlivros == 0){ // se o aluno n�o tem nenhum livro, este ser� o primeiro
                                strcpy(usu[i].livroemprestado1, livroscadastrados[j].nomedolivro);
                                usu[i].livros[0] = livroscadastrados[j].codigo; //controle de livro devolvido
                                printf("\n          Data do empr�stimo -> Dia: ");
                                scanf("%d", &usu[i].dialivro1);
                                printf("                             -> M�s: ");
                                scanf("%d", &usu[i].meslivro1);
                                printf("                             -> Ano: ");
                                scanf("%d", &usu[i].anolivro1);
                                printf("\n          Data limite para devolu��o -> Dia: ");
                                scanf("%d", &usu[i].dia1);
                                printf("                                     -> M�s: ");
                                scanf("%d", &usu[i].mes1);
                                printf("                                     -> Ano: ");
                                scanf("%d", &usu[i].ano1);
                            }else{
                                strcpy(usu[i].livroemprestado2, livroscadastrados[j].nomedolivro);
                                usu[i].livros[1] = livroscadastrados[j].codigo;
                                printf("\n  Data do empr�stimo -> Dia: ");
                                scanf("%d", &usu[i].dialivro2);
                                printf("                     -> M�s: ");
                                scanf("%d", &usu[i].meslivro2);
                                printf("                     -> Ano: ");
                                scanf("%d", &usu[i].anolivro2);
                                printf("\n          Data limite para devolu��o -> Dia: ");
                                scanf("%d", &usu[i].dia2);
                                printf("                                     -> M�s: ");
                                scanf("%d", &usu[i].mes2);
                                printf("                                     -> Ano: ");
                                scanf("%d", &usu[i].ano2);
                            }
                            usu[i].maxlivros += 1;
                            printf("\n\n            EMPR�STIMO BEM SUCEDIDO");

                        }
                    }
                }
            }
            setbuf(stdin,NULL);
            getch();
            setbuf(stdin,NULL);
            break;
        case 2:

            printf("\n          ###############################################################");
            printf("\n          #                        MATEM�TICA DISCRETA                  #");
            printf("\n          ###############################################################");
            printf("\n              LIVROS                                       QUANTIDADE\n");
            if(matematica[0]>0){
                printf("\n          fundamentos da matematica discreta                   %d",matematica[0]);
            }else{
                printf("\n          fundamentos da matematica discreta                   0");
            }
            if(matematica[1]>0){
                printf("\n          matematica discreta para computacao                  %d",matematica[1]);
            }else{
                printf("\n          matematica discreta para computacao                  0");
            }
            for(int j=0;j<total.totaldiscreta1; j++){
                printf("\n          %s \t\t\t\t\t       %d", livroscadastrados[j].nomedolivro, livroscadastrados[j].quantidade);
            }
            printf("\n          ###############################################################\n");
            printf("\n          Informe o nome do livro -> ");
            setbuf(stdin,NULL);
            fgets(auxEmp,50,stdin);
            tam = strlen(auxEmp);
            auxEmp[tam-1] = '\0';
            if((strcmp(auxEmp,"fundamentos da matematica discreta")==0) && matematica[0]>0){
                matematica[0] -= 1;
                if(nlivros == 0){
                        strcpy(usu[i].livroemprestado1,"fundamentos da matematica discreta");
                        usu[i].livros[0] = 3;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro1);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro1);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro1);
                        printf("\n          Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia1);
                        printf("                                     -> M�s: ");
                        scanf("%d", &usu[i].mes1);
                        printf("                                     -> Ano: ");
                        scanf("%d", &usu[i].ano1);
                    }else{
                        strcpy(usu[i].livroemprestado2,"fundamentos da matematica discreta");
                        usu[i].livros[1] = 3;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro2);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro2);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro1);
                        printf("\n          Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia2);
                        printf("                                     -> M�s: ");
                        scanf("%d", &usu[i].mes2);
                        printf("                                     -> Ano: ");
                        scanf("%d", &usu[i].ano2);
                    }
                usu[i].maxlivros += 1;
                for(int x=0; x<cont; x++){
                        if(usu[x].id == NULL){

                        }else{
                            fprintf(file, "NOME: ");
                            fprintf(file, usu[x].nome);
                            fprintf(file, "ID: ");
                            fprintf(file, "%d", usu[x].id);
                            fprintf(file, " LIVROS: ");
                            fprintf(file, "%d", usu[x].maxlivros);
                            fprintf(file, "\n");
                        }
                    }
                    fclose(file);
                printf("\n          EMPR�STIMO BEM SUCEDIDO");
            }else{
                if((strcmp(auxEmp,"matematica discreta para computacao")==0) && matematica[1]>1){
                    matematica[1] -= 1;
                    if(nlivros == 0){
                        strcpy(usu[i].livroemprestado1,"matematica discreta para computacao");
                        usu[i].livros[0] = 4;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro1);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro1);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro1);
                        printf("\n          Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia1);
                        printf("                                     -> M�s: ");
                        scanf("%d", &usu[i].mes1);
                        printf("                                     -> Ano: ");
                        scanf("%d", &usu[i].ano1);
                    }else{
                        strcpy(usu[i].livroemprestado2,"matematica discreta para computacao");
                        usu[i].livros[1] = 4;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro2);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro2);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro2);
                        printf("\n              Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia2);
                        printf("                                     -> M�s: ");
                        scanf("%d", &usu[i].mes2);
                        printf("                                     -> Ano: ");
                        scanf("%d", &usu[i].ano2);
                    }
                    usu[i].maxlivros += 1;
                    for(int x=0; x<cont; x++){
                        if(usu[x].id == NULL){

                        }else{
                            fprintf(file, "NOME: ");
                            fprintf(file, usu[x].nome);
                            fprintf(file, "ID: ");
                            fprintf(file, "%d", usu[x].id);
                            fprintf(file, " LIVROS: ");
                            fprintf(file, "%d", usu[x].maxlivros);
                            fprintf(file, "\n");
                        }
                    }
                    fclose(file);
                    printf("\n          EMPR�STIMO BEM SUCEDIDO");
                }else{
                    for(int j=0;j<total.totaldiscreta1; j++){
                        if((strcmp(auxEmp,livroscadastrados[j].nomedolivro)==0)){
                            livroscadastrados[j].quantidade -= 1;
                            if(nlivros == 0){ // se o aluno n�o tem nenhum livro, este ser� o primeiro
                                strcpy(usu[i].livroemprestado1, livroscadastrados[j].nomedolivro);
                                usu[i].livros[0] = livroscadastrados[j].codigo; //controle de livro devolvido
                                printf("\n          Data do empr�stimo -> Dia: ");
                                scanf("%d", &usu[i].dialivro1);
                                printf("                             -> M�s: ");
                                scanf("%d", &usu[i].meslivro1);
                                printf("                             -> Ano: ");
                                scanf("%d", &usu[i].anolivro1);
                                printf("\n          Data limite para devolu��o -> Dia: ");
                                scanf("%d", &usu[i].dia1);
                                printf("                                     -> M�s: ");
                                scanf("%d", &usu[i].mes1);
                                printf("                                     -> Ano: ");
                                scanf("%d", &usu[i].ano1);
                            }else{
                                strcpy(usu[i].livroemprestado2, livroscadastrados[j].nomedolivro);
                                usu[i].livros[1] = livroscadastrados[j].codigo;
                                printf("\n  Data do empr�stimo -> Dia: ");
                                scanf("%d", &usu[i].dialivro2);
                                printf("                     -> M�s: ");
                                scanf("%d", &usu[i].meslivro2);
                                printf("                     -> Ano: ");
                                scanf("%d", &usu[i].anolivro2);
                                printf("\n          Data limite para devolu��o -> Dia: ");
                                scanf("%d", &usu[i].dia2);
                                printf("                                     -> M�s: ");
                                scanf("%d", &usu[i].mes2);
                                printf("                                     -> Ano: ");
                                scanf("%d", &usu[i].ano2);
                            }
                            usu[i].maxlivros += 1;
                            printf("\n\n            EMPR�STIMO BEM SUCEDIDO");

                        }else{
                            printf("\n          EMPR�STIMO N�O FOI BEM SUCEDIDO");
                        }
                    }

                }

            }

            setbuf(stdin,NULL);
            getch();
            setbuf(stdin,NULL);
            break;
        case 3:
            printf("\n          ###############################################################");
            printf("\n          #                        ALGORITMOS                           #");
            printf("\n          ###############################################################");
            printf("\n              LIVROS                                           QUANTIDADE\n");
            if(algoritmo[0]>0){
                printf("\n          algoritmos. teoria e pratica                            %d",algoritmo[0]);
            }else{
                printf("\n          algoritmos. teoria e pratica                            0");
            }
            if(algoritmo[1]>0){
                printf("\n          introducao a programacao                                %d",algoritmo[1]);
            }else{
                printf("\n          introducao a programacao                                0");
            }
            for(int j=0;j<total.totalalgoritmo; j++)
                printf("\n          %s \t\t\t\t\t          %d", livroscadastrados[j].nomedolivro, livroscadastrados[j].quantidade);
            printf("\n          ###############################################################");
            printf("\n          Informe o nome do livro -> ");
            setbuf(stdin,NULL);
            fgets(auxEmp,50,stdin);
            tam = strlen(auxEmp);
            auxEmp[tam-1] = '\0';
            if((strcmp(auxEmp,"algoritmos. teoria e pratica")==0) && algoritmo[0]>0){
                algoritmo[0] -= 1;
                if(nlivros == 0){
                        strcpy(usu[i].livroemprestado1,"algoritmos. teoria e pratica");
                        usu[i].livros[0] = 5;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro1);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro1);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro1);
                        printf("\n          Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia1);
                        printf("                                     -> M�s: ");
                        scanf("%d", &usu[i].mes1);
                        printf("                                     -> Ano: ");
                        scanf("%d", &usu[i].ano1);
                    }else{
                        strcpy(usu[i].livroemprestado2,"algoritmos. teoria e pratica");
                        usu[i].livros[1] = 5;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro2);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro2);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro2);
                        printf("\n          Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia2);
                        printf("                                     -> M�s: ");
                        scanf("%d", &usu[i].mes2);
                        printf("                                     -> Ano: ");
                        scanf("%d", &usu[i].ano2);
                    }
                usu[i].maxlivros += 1;
                for(int x=0; x<cont; x++){
                    if(usu[x].id == NULL){

                    }else{
                        fprintf(file, "NOME: ");
                        fprintf(file, usu[x].nome);
                        fprintf(file, "ID: ");
                        fprintf(file, "%d", usu[x].id);
                        fprintf(file, " LIVROS: ");
                        fprintf(file, "%d", usu[x].maxlivros);
                        fprintf(file, "\n");
                    }
                }
                fclose(file);
                printf("\n      EMPR�STIMO BEM SUCEDIDO");

            }else{
                if((strcmp(auxEmp,"introducao a programacao")==0) && algoritmo[1]>0){
                    algoritmo[1] -= 1;
                    if(nlivros == 0){
                        strcpy(usu[i].livroemprestado1,"introducao a programacao");
                        usu[i].livros[0] = 6;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro1);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro1);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro1);
                        printf("\n          Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia1);
                        printf("                                     -> M�s: ");
                        scanf("%d", &usu[i].mes1);
                        printf("                                     -> Ano: ");
                        scanf("%d", &usu[i].ano1);
                    }else{
                        strcpy(usu[i].livroemprestado2,"introducao a programacao");
                        usu[i].livros[1] = 6;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro2);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro2);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro2);
                        printf("\n          Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia2);
                        printf("                                     -> M�s: ");
                        scanf("%d", &usu[i].mes2);
                        printf("                                     -> Ano: ");
                        scanf("%d", &usu[i].ano2);
                    }
                    usu[i].maxlivros += 1;
                    for(int x=0; x<cont; x++){
                        if(usu[x].id == NULL){

                        }else{
                            fprintf(file, "NOME: ");
                            fprintf(file, usu[x].nome);
                            fprintf(file, "ID: ");
                            fprintf(file, "%d", usu[x].id);
                            fprintf(file, " LIVROS: ");
                            fprintf(file, "%d", usu[x].maxlivros);
                            fprintf(file, "\n");
                        }
                    }
                    fclose(file);
                    printf("\n          EMPR�STIMO BEM SUCEDIDO");
                }else{
                    for(int j=0;j<total.totalalgoritmo; j++){
                        if((strcmp(auxEmp,livroscadastrados[j].nomedolivro)==0)){
                            livroscadastrados[j].quantidade -= 1;
                            if(nlivros == 0){ // se o aluno n�o tem nenhum livro, este ser� o primeiro
                                strcpy(usu[i].livroemprestado1, livroscadastrados[j].nomedolivro);
                                usu[i].livros[0] = livroscadastrados[j].codigo; //controle de livro devolvido
                                printf("\n          Data do empr�stimo -> Dia: ");
                                scanf("%d", &usu[i].dialivro1);
                                printf("                             -> M�s: ");
                                scanf("%d", &usu[i].meslivro1);
                                printf("                             -> Ano: ");
                                scanf("%d", &usu[i].anolivro1);
                                printf("\n          Data limite para devolu��o -> Dia: ");
                                scanf("%d", &usu[i].dia1);
                                printf("                                     -> M�s: ");
                                scanf("%d", &usu[i].mes1);
                                printf("                                     -> Ano: ");
                                scanf("%d", &usu[i].ano1);
                            }else{
                                strcpy(usu[i].livroemprestado2, livroscadastrados[j].nomedolivro);
                                usu[i].livros[1] = livroscadastrados[j].codigo;
                                printf("\n  Data do empr�stimo -> Dia: ");
                                scanf("%d", &usu[i].dialivro2);
                                printf("                     -> M�s: ");
                                scanf("%d", &usu[i].meslivro2);
                                printf("                     -> Ano: ");
                                scanf("%d", &usu[i].anolivro2);
                                printf("\n          Data limite para devolu��o -> Dia: ");
                                scanf("%d", &usu[i].dia2);
                                printf("                                     -> M�s: ");
                                scanf("%d", &usu[i].mes2);
                                printf("                                     -> Ano: ");
                                scanf("%d", &usu[i].ano2);
                            }
                            usu[i].maxlivros += 1;
                            printf("\n\n            EMPR�STIMO BEM SUCEDIDO");

                        }
                    }
                    printf("\n          EMPR�STIMO N�O FOI BEM SUCEDIDO");
                }
            }
            setbuf(stdin,NULL);
            getch();
            setbuf(stdin,NULL);
            break;
        case 4:
            printf("\n          ###############################################################");
            printf("\n          #                   INTRODU��O � COMPUTA��O                   #");
            printf("\n          ###############################################################");
            printf("\n              LIVROS                                    QUANTIDADE\n");
            if(introducao[0]>0){
                printf("\n          ciencia da computacao: uma visao abrangente      %d",introducao[0]);
            }else{
                printf("\n          ciencia da computacao: uma visao abrangente      0");
            }
            if(introducao[1]>0){
                printf("\n          introducao a informatica                         %d",introducao[1]);
            }else{
                printf("\n          introducao a informatica                         0");
            }
            for(int j=0;j<total.totalintroducao; j++)
                printf("\n          %s \t\t\t\t\t       %d", livroscadastrados[j].nomedolivro, livroscadastrados[j].quantidade);
            printf("\n          ###############################################################");
            printf("\n          Informe o nome do livro -> ");
            setbuf(stdin,NULL);
            fgets(auxEmp,50,stdin);
            tam = strlen(auxEmp);
            auxEmp[tam-1] = '\0';
            if((strcmp(auxEmp,"ciencia da computacao: uma visao abrangente")==0) && introducao[0]>0){
                introducao[0] -= 1;
                if(nlivros == 0){
                        strcpy(usu[i].livroemprestado1,"ciencia da computacao: uma visao abrangente");
                        usu[i].livros[0] = 7;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro1);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro1);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro1);
                        printf("\n          Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia1);
                        printf("                                     -> M�s: ");
                        scanf("%d", &usu[i].mes1);
                        printf("                                     -> Ano: ");
                        scanf("%d", &usu[i].ano1);
                    }else{
                        strcpy(usu[i].livroemprestado2,"ciencia da computacao: uma visao abrangente");
                        usu[i].livros[1] = 7;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro2);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro2);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro2);
                        printf("\n          Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia2);
                        printf("                                     -> M�s: ");
                        scanf("%d", &usu[i].mes2);
                        printf("                                     -> Ano: ");
                        scanf("%d", &usu[i].ano2);
                    }
                usu[i].maxlivros += 1;
                for(int x=0; x<cont; x++){
                    if(usu[x].id == NULL){

                    }else{
                        fprintf(file, "NOME: ");
                        fprintf(file, usu[x].nome);
                        fprintf(file, "ID: ");
                        fprintf(file, "%d", usu[x].id);
                        fprintf(file, " LIVROS: ");
                        fprintf(file, "%d", usu[x].maxlivros);
                        fprintf(file, "\n");
                    }
                }
                    fclose(file);
                printf("\n          EMPR�STIMO BEM SUCEDIDO");
            }else{
                if((strcmp(auxEmp,"introducao a informatica")==0) && introducao[1]>0){
                    introducao[1] -= 1;
                    if(nlivros == 0){
                        strcpy(usu[i].livroemprestado1,"introducao a informatica");
                        usu[i].livros[0] = 8;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro1);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro1);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro1);
                        printf("\n          Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia1);
                        printf("                                     -> M�s: ");
                        scanf("%d", &usu[i].mes1);
                        printf("                                     -> Ano: ");
                        scanf("%d", &usu[i].ano1);
                    }else{
                        strcpy(usu[i].livroemprestado2,"introducao a informatica");
                        usu[i].livros[1] = 8;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro2);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro2);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro2);
                        printf("\n          Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia2);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].mes2);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].ano2);
                    }
                    usu[i].maxlivros += 1;
                    for(int x=0; x<cont; x++){
                        if(usu[x].id == NULL){

                        }else{
                            fprintf(file, "NOME: ");
                            fprintf(file, usu[x].nome);
                            fprintf(file, "ID: ");
                            fprintf(file, "%d", usu[x].id);
                            fprintf(file, " LIVROS: ");
                            fprintf(file, "%d", usu[x].maxlivros);
                            fprintf(file, "\n");
                        }
                    }
                    fclose(file);
                    printf("\n          EMPR�STIMO BEM SUCEDIDO");
                }else{
                    for(int j=0;j<total.totallogica; j++){
                        if((strcmp(auxEmp,livroscadastrados[j].nomedolivro)==0)){
                            livroscadastrados[j].quantidade -= 1;
                            if(nlivros == 0){ // se o aluno n�o tem nenhum livro, este ser� o primeiro
                                strcpy(usu[i].livroemprestado1, livroscadastrados[j].nomedolivro);
                                usu[i].livros[0] = livroscadastrados[j].codigo; //controle de livro devolvido
                                printf("\n          Data do empr�stimo -> Dia: ");
                                scanf("%d", &usu[i].dialivro1);
                                printf("                             -> M�s: ");
                                scanf("%d", &usu[i].meslivro1);
                                printf("                             -> Ano: ");
                                scanf("%d", &usu[i].anolivro1);
                                printf("\n          Data limite para devolu��o -> Dia: ");
                                scanf("%d", &usu[i].dia1);
                                printf("                                     -> M�s: ");
                                scanf("%d", &usu[i].mes1);
                                printf("                                     -> Ano: ");
                                scanf("%d", &usu[i].ano1);
                            }else{
                                strcpy(usu[i].livroemprestado2, livroscadastrados[j].nomedolivro);
                                usu[i].livros[1] = livroscadastrados[j].codigo;
                                printf("\n  Data do empr�stimo -> Dia: ");
                                scanf("%d", &usu[i].dialivro2);
                                printf("                     -> M�s: ");
                                scanf("%d", &usu[i].meslivro2);
                                printf("                     -> Ano: ");
                                scanf("%d", &usu[i].anolivro2);
                                printf("\n          Data limite para devolu��o -> Dia: ");
                                scanf("%d", &usu[i].dia2);
                                printf("                                     -> M�s: ");
                                scanf("%d", &usu[i].mes2);
                                printf("                                     -> Ano: ");
                                scanf("%d", &usu[i].ano2);
                            }
                            usu[i].maxlivros += 1;
                            printf("\n\n            EMPR�STIMO BEM SUCEDIDO");

                        }else{
                            printf("\n          EMPR�STIMO N�O FOI BEM SUCEDIDO");
                        }
                    }
                }
            }
            setbuf(stdin,NULL);
            getch();
            setbuf(stdin,NULL);

            break;
        case 5:
            printf("\n          ###############################################################");
            printf("\n          #          ARQUITETURA E ORGANIZA��O DE COMPUTADORES          #");
            printf("\n          ###############################################################");
            printf("\n              LIVROS                                   QUANTIDADE\n");
            if(oac[0]>0){
                printf("\n          arquitetura e organizacao de computadores        %d",oac[0]);
            }
            else{
                printf("\n          arquitetura e organizacao de computadores        0");
            }
            if(oac[1]>0){
                printf("\n          fundamentos da arquitetura de computadores     %d",oac[1]);
            }else{
                printf("\n          fundamentos da arquitetura de computadores     0");
            }
            for(int j=0;j<total.totaloac; j++)
                printf("\n          %s \t\t\t\t\t       %d", livroscadastrados[j].nomedolivro, livroscadastrados[j].quantidade);
            printf("\n          ###############################################################");
            printf("\n          Informe o nome do livro -> ");
            setbuf(stdin,NULL);
            fgets(auxEmp,50,stdin);
            tam = strlen(auxEmp);
            auxEmp[tam-1] = '\0';
            if((strcmp(auxEmp,"arquitetura e organizacao de computadores")==0) && oac[0]>0){
                oac[0] -= 1;
                if(nlivros == 0){
                    strcpy(usu[i].livroemprestado1,"arquitetura e organizacao de computadores");
                    usu[i].livros[0] = 9;
                    printf("\n          Data do empr�stimo -> Dia: ");
                    scanf("%d", &usu[i].dialivro1);
                    printf("                              -> M�s: ");
                    scanf("%d", &usu[i].meslivro1);
                    printf("                              -> Ano: ");
                    scanf("%d", &usu[i].anolivro1);
                    printf("\n          Data limite para devolu��o -> Dia: ");
                    scanf("%d", &usu[i].dia1);
                    printf("                                     -> M�s: ");
                    scanf("%d", &usu[i].mes1);
                    printf("                                     -> Ano: ");
                    scanf("%d", &usu[i].ano1);
                }else{
                    strcpy(usu[i].livroemprestado2,"arquitetura e organizacao de computadores");
                    usu[i].livros[1] = 9;
                    printf("\n          Data do empr�stimo -> Dia: ");
                    scanf("%d", &usu[i].dialivro2);
                    printf("                              -> M�s: ");
                    scanf("%d", &usu[i].meslivro2);
                    printf("                              -> Ano: ");
                    scanf("%d", &usu[i].anolivro2);
                    printf("\n          Data limite para devolu��o -> Dia: ");
                    scanf("%d", &usu[i].dia2);
                    printf("                                     -> M�s: ");
                    scanf("%d", &usu[i].mes2);
                    printf("                                     -> Ano: ");
                    scanf("%d", &usu[i].ano2);
                    }
                usu[i].maxlivros += 1;
                for(int x=0; x<cont; x++){
                    if(usu[x].id == NULL){

                    }else{
                        fprintf(file, "NOME: ");
                        fprintf(file, usu[x].nome);
                        fprintf(file, "ID: ");
                        fprintf(file, "%d", usu[x].id);
                        fprintf(file, " LIVROS: ");
                        fprintf(file, "%d", usu[x].maxlivros);
                        fprintf(file, "\n");
                    }
                }
                    fclose(file);
                printf("\n          EMPR�STIMO BEM SUCEDIDO");
            }else{
                if((strcmp(auxEmp,"fundamentos da arquitetura de computadores")==0) && oac[1]>0){
                    oac[1] -= 1;
                    if(nlivros == 0){
                        strcpy(usu[i].livroemprestado1,"fundamentos da arquitetura de computadores");
                        usu[i].livros[0] = 10;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro1);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro1);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro1);
                        printf("\n          Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia1);
                        printf("                                     -> M�s: ");
                        scanf("%d", &usu[i].mes1);
                        printf("                                     -> Ano: ");
                        scanf("%d", &usu[i].ano1);
                    }else{
                        strcpy(usu[i].livroemprestado2,"fundamentos da arquitetura de computadores");
                        usu[i].livros[1] = 10;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro2);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro2);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro2);
                        printf("\n          Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia2);
                        printf("                                     -> M�s: ");
                        scanf("%d", &usu[i].mes2);
                        printf("                                     -> Ano: ");
                        scanf("%d", &usu[i].ano2);
                    }
                    usu[i].maxlivros += 1;
                    for(int x=0; x<cont; x++){
                        if(usu[x].id == NULL){

                        }else{
                            fprintf(file, "NOME: ");
                            fprintf(file, usu[x].nome);
                            fprintf(file, "ID: ");
                            fprintf(file, "%d", usu[x].id);
                            fprintf(file, " LIVROS: ");
                            fprintf(file, "%d", usu[x].maxlivros);
                            fprintf(file, "\n");
                        }
                    }
                    fclose(file);
                    printf("\n          EMPR�STIMO BEM SUCEDIDO");
                }else{
                    for(int j=0;j<total.totallogica; j++){
                        if((strcmp(auxEmp,livroscadastrados[j].nomedolivro)==0)){
                            livroscadastrados[j].quantidade -= 1;
                            if(nlivros == 0){ // se o aluno n�o tem nenhum livro, este ser� o primeiro
                                strcpy(usu[i].livroemprestado1, livroscadastrados[j].nomedolivro);
                                usu[i].livros[0] = livroscadastrados[j].codigo; //controle de livro devolvido
                                printf("\n          Data do empr�stimo -> Dia: ");
                                scanf("%d", &usu[i].dialivro1);
                                printf("                             -> M�s: ");
                                scanf("%d", &usu[i].meslivro1);
                                printf("                             -> Ano: ");
                                scanf("%d", &usu[i].anolivro1);
                                printf("\n          Data limite para devolu��o -> Dia: ");
                                scanf("%d", &usu[i].dia1);
                                printf("                                     -> M�s: ");
                                scanf("%d", &usu[i].mes1);
                                printf("                                     -> Ano: ");
                                scanf("%d", &usu[i].ano1);
                            }else{
                                strcpy(usu[i].livroemprestado2, livroscadastrados[j].nomedolivro);
                                usu[i].livros[1] = livroscadastrados[j].codigo;
                                printf("\n  Data do empr�stimo -> Dia: ");
                                scanf("%d", &usu[i].dialivro2);
                                printf("                     -> M�s: ");
                                scanf("%d", &usu[i].meslivro2);
                                printf("                     -> Ano: ");
                                scanf("%d", &usu[i].anolivro2);
                                printf("\n          Data limite para devolu��o -> Dia: ");
                                scanf("%d", &usu[i].dia2);
                                printf("                                     -> M�s: ");
                                scanf("%d", &usu[i].mes2);
                                printf("                                     -> Ano: ");
                                scanf("%d", &usu[i].ano2);
                            }
                            usu[i].maxlivros += 1;
                            printf("\n\n            EMPR�STIMO BEM SUCEDIDO");

                        }else{
                            printf("\n          EMPR�STIMO N�O FOI BEM SUCEDIDO");
                        }
                    }
                }
            }
            setbuf(stdin,NULL);
            getch();
            setbuf(stdin,NULL);
            break;
        case 6:
            printf("\n          ###############################################################");
            printf("\n          #                             C�LCULO                         #");
            printf("\n          ###############################################################\n");
            printf("\n          (1) -> C�LCULO 1");
            printf("\n          (2) -> C�LCULO 2");
            printf("\n          (3) -> C�LCULO 3");

            printf("\n          OP��O -> ");
            scanf("%d", &livro);
            if(livro == 1){
                printf("\n          ###############################################################");
                printf("\n          #                         C�LCULO 1                           #");
                printf("\n          ###############################################################");
                printf("\n             LIVROS                                QUANTIDADE\n");
                if(calculo1[0]>0){
                    printf("\n          calculo. para entender e para usar           %d", calculo1[0]);
                }else{
                    printf("\n          calculo. para entender e para usar           0");
                }
                if(calculo1[1]>0){
                    printf("\n          calculo - volume 1                           %d", calculo1[1]);
                }else{
                    printf("\n          calculo - volume 1                           0");
                }
                if(calculo1[2]>0){
                    printf("\n          um curso de calculo - volume 1               %d", calculo1[2]);
                }else{
                    printf("\n          um curso de calculo - volume 1               0");
                }
                for(int j=0;j<total.totalcalculo1; j++){
                    printf("\n          %s \t\t\t\t     %d", livroscadastrados[j].nomedolivro, livroscadastrados[j].quantidade);
                }
                printf("\n          ###############################################################");
                printf("\n          Informe o nome do livro -> ");
                setbuf(stdin,NULL);
                fgets(auxEmp,50,stdin);
                tam = strlen(auxEmp);
                auxEmp[tam-1] = '\0';
                if((strcmp(auxEmp,"calculo. para entender e para usar")==0) && calculo1[0]>0){
                    calculo1[0] -= 1;
                    if(nlivros == 0){
                        strcpy(usu[i].livroemprestado1,"calculo. para entender e para usar");
                        usu[i].livros[0] = 11;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro1);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro1);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro1);
                        printf("\n          Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia1);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].mes1);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].ano1);
                    }else{
                        strcpy(usu[i].livroemprestado2,"calculo. para entender e para usar");
                        usu[i].livros[1] = 11;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro2);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro2);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro2);
                        printf("\n          Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia2);
                        printf("                                     -> M�s: ");
                        scanf("%d", &usu[i].mes2);
                        printf("                                     -> Ano: ");
                        scanf("%d", &usu[i].ano2);
                    }
                    usu[i].maxlivros += 1;
                    for(int x=0; x<cont; x++){
                        if(usu[x].id == NULL){

                        }else{
                            fprintf(file, "NOME: ");
                            fprintf(file, usu[x].nome);
                            fprintf(file, "ID: ");
                            fprintf(file, "%d", usu[x].id);
                            fprintf(file, " LIVROS: ");
                            fprintf(file, "%d", usu[x].maxlivros);
                            fprintf(file, "\n");
                        }
                    }
                    fclose(file);
                    printf("\n          EMPR�STIMO BEM SUCEDIDO");
                }else{
                    if((strcmp(auxEmp,"calculo - volume 1")==0) && calculo1[1]>0){
                        calculo1[1] -= 1;
                        if(nlivros == 0){
                            strcpy(usu[i].livroemprestado1,"calculo - volume 1");
                            usu[i].livros[0] = 12;
                            printf("\n          Data do empr�stimo -> Dia: ");
                            scanf("%d", &usu[i].dialivro1);
                            printf("                             -> M�s: ");
                            scanf("%d", &usu[i].meslivro1);
                            printf("                             -> Ano: ");
                            scanf("%d", &usu[i].anolivro1);
                            printf("\n          Data limite para devolu��o -> Dia: ");
                            scanf("%d", &usu[i].dia1);
                            printf("                                     -> M�s: ");
                            scanf("%d", &usu[i].mes1);
                            printf("                                     -> Ano: ");
                            scanf("%d", &usu[i].ano1);
                        }else{
                            strcpy(usu[i].livroemprestado2,"calculo - volume 1");
                            usu[i].livros[1] = 12;
                            printf("\n          Data do empr�stimo -> Dia: ");
                            scanf("%d", &usu[i].dialivro2);
                            printf("                             -> M�s: ");
                            scanf("%d", &usu[i].meslivro2);
                            printf("                             -> Ano: ");
                            scanf("%d", &usu[i].anolivro2);
                            printf("\n          Data limite para devolu��o -> Dia: ");
                            scanf("%d", &usu[i].dia2);
                            printf("                                     -> M�s: ");
                            scanf("%d", &usu[i].mes2);
                            printf("                                     -> Ano: ");
                            scanf("%d", &usu[i].ano2);
                        }
                        usu[i].maxlivros += 1;
                        for(int x=0; x<cont; x++){
                        if(usu[x].id == NULL){

                        }else{
                            fprintf(file, "NOME: ");
                            fprintf(file, usu[x].nome);
                            fprintf(file, "ID: ");
                            fprintf(file, "%d", usu[x].id);
                            fprintf(file, " LIVROS: ");
                            fprintf(file, "%d", usu[x].maxlivros);
                            fprintf(file, "\n");
                        }
                    }
                    fclose(file);
                        printf("\n          EMPR�STIMO BEM SUCEDIDO");
                    }else{
                        if((strcmp(auxEmp,"um curso de calculo - volume 1")==0) && calculo1[2]>0){
                            calculo1[2] -= 1;
                            if(nlivros == 0){
                                strcpy(usu[i].livroemprestado1,"um curso de calculo - volume 1");
                                usu[i].livros[0] = 13;
                                printf("\n          Data do empr�stimo -> Dia: ");
                                scanf("%d", &usu[i].dialivro1);
                                printf("                             -> M�s: ");
                                scanf("%d", &usu[i].meslivro1);
                                printf("                             -> Ano: ");
                                scanf("%d", &usu[i].anolivro1);
                                printf("\n          Data limite para devolu��o -> Dia: ");
                                scanf("%d", &usu[i].dia1);
                                printf("                                     -> M�s: ");
                                scanf("%d", &usu[i].mes1);
                                printf("                                     -> Ano: ");
                                scanf("%d", &usu[i].ano1);
                            }else{
                                strcpy(usu[i].livroemprestado2,"um curso de calculo - volume 1");
                                usu[i].livros[1] = 13;
                                printf("\n          Data do empr�stimo -> Dia: ");
                                scanf("%d", &usu[i].dialivro2);
                                printf("                             -> M�s: ");
                                scanf("%d", &usu[i].meslivro2);
                                printf("                             -> Ano: ");
                                scanf("%d", &usu[i].anolivro2);
                                printf("\n          Data limite para devolu��o -> Dia: ");
                                scanf("%d", &usu[i].dia2);
                                printf("                                     -> M�s: ");
                                scanf("%d", &usu[i].mes2);
                                printf("                                     -> Ano: ");
                                scanf("%d", &usu[i].ano2);
                            }
                            usu[i].maxlivros += 1;
                            for(int x=0; x<cont; x++){
                                if(usu[x].id == NULL){

                                }else{
                                    fprintf(file, "NOME: ");
                                    fprintf(file, usu[x].nome);
                                    fprintf(file, "ID: ");
                                    fprintf(file, "%d", usu[x].id);
                                    fprintf(file, " LIVROS: ");
                                    fprintf(file, "%d", usu[x].maxlivros);
                                    fprintf(file, "\n");
                                }
                            }
                            fclose(file);
                            printf("\n          EMPR�STIMO BEM SUCEDIDO");
                        }else{
                            for(int j=0;j<total.totallogica; j++){
                                if((strcmp(auxEmp,livroscadastrados[j].nomedolivro)==0)){
                                    livroscadastrados[j].quantidade -= 1;
                                    if(nlivros == 0){ // se o aluno n�o tem nenhum livro, este ser� o primeiro
                                        strcpy(usu[i].livroemprestado1, livroscadastrados[j].nomedolivro);
                                        usu[i].livros[0] = livroscadastrados[j].codigo; //controle de livro devolvido
                                        printf("\n          Data do empr�stimo -> Dia: ");
                                        scanf("%d", &usu[i].dialivro1);
                                        printf("                             -> M�s: ");
                                        scanf("%d", &usu[i].meslivro1);
                                        printf("                             -> Ano: ");
                                        scanf("%d", &usu[i].anolivro1);
                                        printf("\n          Data limite para devolu��o -> Dia: ");
                                        scanf("%d", &usu[i].dia1);
                                        printf("                                     -> M�s: ");
                                        scanf("%d", &usu[i].mes1);
                                        printf("                                     -> Ano: ");
                                        scanf("%d", &usu[i].ano1);
                                    }else{
                                        strcpy(usu[i].livroemprestado2, livroscadastrados[j].nomedolivro);
                                        usu[i].livros[1] = livroscadastrados[j].codigo;
                                        printf("\n  Data do empr�stimo -> Dia: ");
                                        scanf("%d", &usu[i].dialivro2);
                                        printf("                     -> M�s: ");
                                        scanf("%d", &usu[i].meslivro2);
                                        printf("                     -> Ano: ");
                                        scanf("%d", &usu[i].anolivro2);
                                        printf("\n          Data limite para devolu��o -> Dia: ");
                                        scanf("%d", &usu[i].dia2);
                                        printf("                                     -> M�s: ");
                                        scanf("%d", &usu[i].mes2);
                                        printf("                                     -> Ano: ");
                                        scanf("%d", &usu[i].ano2);
                                    }
                                    usu[i].maxlivros += 1;
                                    printf("\n\n            EMPR�STIMO BEM SUCEDIDO");

                                }else{
                                    printf("\n          EMPR�STIMO N�O FOI BEM SUCEDIDO");
                                }
                            }
                        }
                    }
                }
                setbuf(stdin,NULL);
                getch();
                setbuf(stdin,NULL);
            /*-----------------------------------------------------------*/
            }else{
                if(livro == 2){
                    printf("\n          ###############################################################");
                    printf("\n          #                         C�LCULO 2                           #");
                    printf("\n          ###############################################################");
                    printf("\n              LIVROS                                QUANTIDADE\n");
                    if(calculo2[0]>0){
                        printf("\n          calculo - volume 2                           %d", calculo2[0]);
                    }else{
                        printf("\n          calculo - volume 2                           0");
                    }
                    if(calculo2[1]>0){
                        printf("\n          um curso de calculo - volume 2               %d", calculo2[1]);
                    }else{
                        printf("\n          um curso de calculo - volume 2               0");
                    }
                    for(int j=0;j<total.totalcalculo2; j++){
                        printf("\n          %s \t\t\t\t\t       %d", livroscadastrados[j].nomedolivro, livroscadastrados[j].quantidade);
                    }
                    printf("\n          ###############################################################");
                    printf("\n          Informe o nome do livro -> ");
                    setbuf(stdin,NULL);
                    fgets(auxEmp,50,stdin);
                    tam = strlen(auxEmp);
                    auxEmp[tam-1] = '\0';
                    if((strcmp(auxEmp,"calculo - volume 2")==0) && calculo2[0]>0){
                        calculo2[0] -= 1;
                        if(nlivros == 0){
                            strcpy(usu[i].livroemprestado1,"calculo - volume 2");
                            usu[i].livros[0] = 14;
                            printf("\n          Data do empr�stimo -> Dia: ");
                            scanf("%d", &usu[i].dialivro1);
                            printf("                             -> M�s: ");
                            scanf("%d", &usu[i].meslivro1);
                            printf("                             -> Ano: ");
                            scanf("%d", &usu[i].anolivro1);
                            printf("\n          Data limite para devolu��o -> Dia: ");
                            scanf("%d", &usu[i].dia1);
                            printf("                                     -> M�s: ");
                            scanf("%d", &usu[i].mes1);
                            printf("                                     -> Ano: ");
                            scanf("%d", &usu[i].ano1);
                        }else{
                            strcpy(usu[i].livroemprestado2,"calculo - volume 2");
                            usu[i].livros[1] = 14;
                            printf("\n          Data do empr�stimo -> Dia: ");
                            scanf("%d", &usu[i].dialivro2);
                            printf("                             -> M�s: ");
                            scanf("%d", &usu[i].meslivro2);
                            printf("                             -> Ano: ");
                            scanf("%d", &usu[i].anolivro2);
                            printf("\n          Data limite para devolu��o -> Dia: ");
                            scanf("%d", &usu[i].dia2);
                            printf("                                     -> M�s: ");
                            scanf("%d", &usu[i].mes2);
                            printf("                                     -> Ano: ");
                            scanf("%d", &usu[i].ano2);
                        }
                        usu[i].maxlivros += 1;
                        for(int x=0; x<cont; x++){
                            if(usu[x].id == NULL){

                            }else{
                                fprintf(file, "NOME: ");
                                fprintf(file, usu[x].nome);
                                fprintf(file, "ID: ");
                                fprintf(file, "%d", usu[x].id);
                                fprintf(file, " LIVROS: ");
                                fprintf(file, "%d", usu[x].maxlivros);
                                fprintf(file, "\n");
                            }
                        }
                        fclose(file);
                        printf("\n          EMPR�STIMO BEM SUCEDIDO");
                    }else{
                        if((strcmp(auxEmp,"um curso de calculo - volume 2")==0) && calculo2[0]>0){
                            calculo2[1] -= 1;
                            if(nlivros == 0){
                                strcpy(usu[i].livroemprestado1,"um curso de calculo - volume 2");
                                usu[i].livros[0] = 15;
                                printf("\n          Data do empr�stimo -> Dia: ");
                                scanf("%d", &usu[i].dialivro1);
                                printf("                             -> M�s: ");
                                scanf("%d", &usu[i].meslivro1);
                                printf("                             -> Ano: ");
                                scanf("%d", &usu[i].anolivro1);
                                printf("\n          Data limite para devolu��o -> Dia: ");
                                scanf("%d", &usu[i].dia1);
                                printf("                                     -> M�s: ");
                                scanf("%d", &usu[i].mes1);
                                printf("                                     -> Ano: ");
                                scanf("%d", &usu[i].ano1);
                            }else{
                                strcpy(usu[i].livroemprestado2,"um curso de calculo - volume 2");
                                usu[i].livros[1] = 15;
                                printf("\n          Data do empr�stimo -> Dia: ");
                                scanf("%d", &usu[i].dialivro2);
                                printf("                             -> M�s: ");
                                scanf("%d", &usu[i].meslivro2);
                                printf("                             -> Ano: ");
                                scanf("%d", &usu[i].anolivro2);
                                printf("\n          Data limite para devolu��o -> Dia: ");
                                scanf("%d", &usu[i].dia2);
                                printf("                                     -> M�s: ");
                                scanf("%d", &usu[i].mes2);
                                printf("                                     -> Ano: ");
                                scanf("%d", &usu[i].ano2);
                            }
                            usu[i].maxlivros += 1;
                            for(int x=0; x<cont; x++){
                                if(usu[x].id == NULL){

                                }else{
                                    fprintf(file, "NOME: ");
                                    fprintf(file, usu[x].nome);
                                    fprintf(file, "ID: ");
                                    fprintf(file, "%d", usu[x].id);
                                    fprintf(file, " LIVROS: ");
                                    fprintf(file, "%d", usu[x].maxlivros);
                                    fprintf(file, "\n");
                                }
                            }
                            fclose(file);
                            printf("\n          EMPR�STIMO BEM SUCEDIDO");
                        }else{
                            for(int j=0;j<total.totallogica; j++){
                                if((strcmp(auxEmp,livroscadastrados[j].nomedolivro)==0)){
                                    livroscadastrados[j].quantidade -= 1;
                                    if(nlivros == 0){ // se o aluno n�o tem nenhum livro, este ser� o primeiro
                                        strcpy(usu[i].livroemprestado1, livroscadastrados[j].nomedolivro);
                                        usu[i].livros[0] = livroscadastrados[j].codigo; //controle de livro devolvido
                                        printf("\n          Data do empr�stimo -> Dia: ");
                                        scanf("%d", &usu[i].dialivro1);
                                        printf("                             -> M�s: ");
                                        scanf("%d", &usu[i].meslivro1);
                                        printf("                             -> Ano: ");
                                        scanf("%d", &usu[i].anolivro1);
                                        printf("\n          Data limite para devolu��o -> Dia: ");
                                        scanf("%d", &usu[i].dia1);
                                        printf("                                     -> M�s: ");
                                        scanf("%d", &usu[i].mes1);
                                        printf("                                     -> Ano: ");
                                        scanf("%d", &usu[i].ano1);
                                    }else{
                                        strcpy(usu[i].livroemprestado2, livroscadastrados[j].nomedolivro);
                                        usu[i].livros[1] = livroscadastrados[j].codigo;
                                        printf("\n  Data do empr�stimo -> Dia: ");
                                        scanf("%d", &usu[i].dialivro2);
                                        printf("                     -> M�s: ");
                                        scanf("%d", &usu[i].meslivro2);
                                        printf("                     -> Ano: ");
                                        scanf("%d", &usu[i].anolivro2);
                                        printf("\n          Data limite para devolu��o -> Dia: ");
                                        scanf("%d", &usu[i].dia2);
                                        printf("                                     -> M�s: ");
                                        scanf("%d", &usu[i].mes2);
                                        printf("                                     -> Ano: ");
                                        scanf("%d", &usu[i].ano2);
                                    }
                                    usu[i].maxlivros += 1;
                                    printf("\n\n            EMPR�STIMO BEM SUCEDIDO");

                                }else{
                                    printf("\n          EMPR�STIMO N�O FOI BEM SUCEDIDO");
                                }
                            }
                        }
                    }
                setbuf(stdin,NULL);
                getch();
                setbuf(stdin,NULL);
                }else{
                    if(livro == 3){
                        printf("\n          ###############################################################");
                        printf("\n          #                         C�LCULO 3                           #");
                        printf("\n          ###############################################################");
                        printf("\n              LIVROS                                     QUANTIDADE\n");
                        if(calculo3[0]>0){
                            printf("\n          calculo - funcoes de uma e varias variaveis       %d", calculo3[0]);
                        }else{
                            printf("\n          calculo - funcoes de uma e varias variaveis       0");
                        }
                        if(calculo3[1]>0){
                            printf("\n          um curso de calculo - volume 3                    %d", calculo3[1]);
                        }else{
                            printf("\n          um curso de calculo - volume 3                    0");
                        }
                        for(int j=0;j<total.totalcalculo3; j++){
                            printf("\n          %s \t\t\t\t\t       %d", livroscadastrados[j].nomedolivro, livroscadastrados[j].quantidade);
                        }
                        printf("\n          ###############################################################");
                        printf("\n          Informe o nome do livro -> ");
                        setbuf(stdin,NULL);
                        fgets(auxEmp,50,stdin);
                        tam = strlen(auxEmp);
                        auxEmp[tam-1] = '\0';
                        if((strcmp(auxEmp,"calculo - funcoes de uma e varias variaveis")==0) && calculo3[0]>0){
                            calculo3[0] -= 1;
                            if(nlivros == 0){
                                strcpy(usu[i].livroemprestado1,"calculo - funcoes de uma e varias variaveis");
                                usu[i].livros[0] = 16;
                               printf("\n           Data do empr�stimo -> Dia: ");
                                scanf("%d", &usu[i].dialivro1);
                                printf("                             -> M�s: ");
                                scanf("%d", &usu[i].meslivro1);
                                printf("                             -> Ano: ");
                                scanf("%d", &usu[i].anolivro1);
                                printf("\n          Data limite para devolu��o -> Dia: ");
                                scanf("%d", &usu[i].dia1);
                                printf("                                     -> M�s: ");
                                scanf("%d", &usu[i].mes1);
                                printf("                                     -> Ano: ");
                                scanf("%d", &usu[i].ano1);
                            }else{
                                strcpy(usu[i].livroemprestado2,"calculo - funcoes de uma e varias variaveis");
                                usu[i].livros[1] = 16;
                                printf("\n          Data do empr�stimo -> Dia: ");
                                scanf("%d", &usu[i].dialivro1);
                                printf("                             -> M�s: ");
                                scanf("%d", &usu[i].meslivro1);
                                printf("                             -> Ano: ");
                                scanf("%d", &usu[i].anolivro1);
                                printf("\n          Data limite para devolu��o -> Dia: ");
                                scanf("%d", &usu[i].dia1);
                                printf("                                     -> M�s: ");
                                scanf("%d", &usu[i].mes1);
                                printf("                                     -> Ano: ");
                                scanf("%d", &usu[i].ano1);
                            }
                            usu[i].maxlivros += 1;
                            for(int x=0; x<cont; x++){
                                if(usu[x].id == NULL){

                                }else{
                                    fprintf(file, "NOME: ");
                                    fprintf(file, usu[x].nome);
                                    fprintf(file, "ID: ");
                                    fprintf(file, "%d", usu[x].id);
                                    fprintf(file, " LIVROS: ");
                                    fprintf(file, "%d", usu[x].maxlivros);
                                    fprintf(file, "\n");
                                }
                            }
                            fclose(file);
                            printf("\n          EMPR�STIMO BEM SUCEDIDO");
                        }
                        else{
                            if((strcmp(auxEmp,"um curso de calculo - volume 3")==0) && calculo3[1]>0){
                                calculo3[1] -= 1;
                                if(nlivros == 0){
                                    strcpy(usu[i].livroemprestado1,"um curso de calculo - volume 3");
                                    usu[i].livros[0] = 17;
                                   printf("\n           Data do empr�stimo -> Dia: ");
                                    scanf("%d", &usu[i].dialivro1);
                                    printf("                             -> M�s: ");
                                    scanf("%d", &usu[i].meslivro1);
                                    printf("                             -> Ano: ");
                                    scanf("%d", &usu[i].anolivro1);
                                    printf("\n          Data limite para devolu��o -> Dia: ");
                                    scanf("%d", &usu[i].dia1);
                                    printf("                                     -> M�s: ");
                                    scanf("%d", &usu[i].mes1);
                                    printf("                                     -> Ano: ");
                                    scanf("%d", &usu[i].ano1);
                                }else{
                                    strcpy(usu[i].livroemprestado2,"um curso de calculo - volume 3");
                                    usu[i].livros[1] = 17;
                                    printf("\n          Data do empr�stimo -> Dia: ");
                                    scanf("%d", &usu[i].dialivro2);
                                    printf("                             -> M�s: ");
                                    scanf("%d", &usu[i].meslivro2);
                                    printf("                             -> Ano: ");
                                    scanf("%d", &usu[i].anolivro2);
                                    printf("\n          Data limite para devolu��o -> Dia: ");
                                    scanf("%d", &usu[i].dia2);
                                    printf("                                     -> M�s: ");
                                    scanf("%d", &usu[i].mes2);
                                    printf("                                     -> Ano: ");
                                    scanf("%d", &usu[i].ano2);
                                }
                                usu[i].maxlivros += 1;
                                for(int x=0; x<cont; x++){
                                    if(usu[x].id == NULL){

                                    }else{
                                        fprintf(file, "NOME: ");
                                        fprintf(file, usu[x].nome);
                                        fprintf(file, "ID: ");
                                        fprintf(file, "%d", usu[x].id);
                                        fprintf(file, " LIVROS: ");
                                        fprintf(file, "%d", usu[x].maxlivros);
                                        fprintf(file, "\n");
                                    }
                                }
                                fclose(file);
                                printf("\n          EMPR�STIMO BEM SUCEDIDO");
                            }else{
                                for(int j=0;j<total.totallogica; j++){
                                    if((strcmp(auxEmp,livroscadastrados[j].nomedolivro)==0)){
                                        livroscadastrados[j].quantidade -= 1;
                                        if(nlivros == 0){ // se o aluno n�o tem nenhum livro, este ser� o primeiro
                                            strcpy(usu[i].livroemprestado1, livroscadastrados[j].nomedolivro);
                                            usu[i].livros[0] = livroscadastrados[j].codigo; //controle de livro devolvido
                                            printf("\n          Data do empr�stimo -> Dia: ");
                                            scanf("%d", &usu[i].dialivro1);
                                            printf("                             -> M�s: ");
                                            scanf("%d", &usu[i].meslivro1);
                                            printf("                             -> Ano: ");
                                            scanf("%d", &usu[i].anolivro1);
                                            printf("\n          Data limite para devolu��o -> Dia: ");
                                            scanf("%d", &usu[i].dia1);
                                            printf("                                     -> M�s: ");
                                            scanf("%d", &usu[i].mes1);
                                            printf("                                     -> Ano: ");
                                            scanf("%d", &usu[i].ano1);
                                        }else{
                                            strcpy(usu[i].livroemprestado2, livroscadastrados[j].nomedolivro);
                                            usu[i].livros[1] = livroscadastrados[j].codigo;
                                            printf("\n  Data do empr�stimo -> Dia: ");
                                            scanf("%d", &usu[i].dialivro2);
                                            printf("                     -> M�s: ");
                                            scanf("%d", &usu[i].meslivro2);
                                            printf("                     -> Ano: ");
                                            scanf("%d", &usu[i].anolivro2);
                                            printf("\n          Data limite para devolu��o -> Dia: ");
                                            scanf("%d", &usu[i].dia2);
                                            printf("                                     -> M�s: ");
                                            scanf("%d", &usu[i].mes2);
                                            printf("                                     -> Ano: ");
                                            scanf("%d", &usu[i].ano2);
                                        }
                                        usu[i].maxlivros += 1;
                                        printf("\n\n            EMPR�STIMO BEM SUCEDIDO");

                                    }else{
                                        printf("\n          EMPR�STIMO N�O FOI BEM SUCEDIDO");
                                    }
                                }
                            }
                        }
                    }
                setbuf(stdin,NULL);
                getch();
                setbuf(stdin,NULL);
                }
            }

            break;
        case 7:
            printf("\n          ###############################################################");
            printf("\n          #               VETORES E GEOMETRIA ANAL�TICA                 #");
            printf("\n          ###############################################################");
            printf("\n              LIVROS                                     QUANTIDADE\n");
            if(vetores[0]>0){
                printf("\n          vetores e geometrica analitica                    %d", vetores[0]);
            }else{
                printf("\n          vetores e geometrica analitica                    0");
            }
            if(vetores[1]>0){
                printf("\n          vetores e uma iniciacao a geometria analitica     %d", vetores[1]);
            }else{
                printf("\n          vetores e uma iniciacao a geometria analitica     0");
            }
            for(int j=0;j<total.totalvetores; j++){
                printf("\n          %s \t\t\t\t\t       %d", livroscadastrados[j].nomedolivro, livroscadastrados[j].quantidade);
            }
            printf("\n          ###############################################################");
            printf("\n          Informe o nome do livro -> ");
            setbuf(stdin,NULL);
            fgets(auxEmp,50,stdin);
            tam = strlen(auxEmp);
            auxEmp[tam-1] = '\0';
            if((strcmp(auxEmp,"vetores e geometria analitica")==0) && vetores[0]>0){
                vetores[0] -= 1;
                if(nlivros == 0){
                    strcpy(usu[i].livroemprestado1,"vetores e geometria analitica");
                    usu[i].livros[0] = 18;
                    printf("\n          Data do empr�stimo -> Dia: ");
                    scanf("%d", &usu[i].dialivro1);
                    printf("                             -> M�s: ");
                    scanf("%d", &usu[i].meslivro1);
                    printf("                             -> Ano: ");
                    scanf("%d", &usu[i].anolivro1);
                    printf("\n          Data limite para devolu��o -> Dia: ");
                    scanf("%d", &usu[i].dia1);
                    printf("                                     -> M�s: ");
                    scanf("%d", &usu[i].mes1);
                    printf("                                     -> Ano: ");
                    scanf("%d", &usu[i].ano1);
                }else{
                    strcpy(usu[i].livroemprestado2,"vetores e geometria analitica");
                    usu[i].livros[1] = 18;
                    printf("\n          Data do empr�stimo -> Dia: ");
                    scanf("%d", &usu[i].dialivro2);
                    printf("                             -> M�s: ");
                    scanf("%d", &usu[i].meslivro2);
                    printf("                             -> Ano: ");
                    scanf("%d", &usu[i].anolivro2);
                    printf("\n          Data limite para devolu��o -> Dia: ");
                    scanf("%d", &usu[i].dia2);
                    printf("                                     -> M�s: ");
                    scanf("%d", &usu[i].mes2);
                    printf("                                     -> Ano: ");
                    scanf("%d", &usu[i].ano2);
                }
                usu[i].maxlivros += 1;
                for(int x=0; x<cont; x++){
                    if(usu[x].id == NULL){

                    }else{
                        fprintf(file, "NOME: ");
                        fprintf(file, usu[x].nome);
                        fprintf(file, "ID: ");
                        fprintf(file, "%d", usu[x].id);
                        fprintf(file, " LIVROS: ");
                        fprintf(file, "%d", usu[x].maxlivros);
                        fprintf(file, "\n");
                    }
                }
                    fclose(file);
                printf("\n          EMPR�STIMO BEM SUCEDIDO");
            }
            else{
                if((strcmp(auxEmp,"vetores e uma iniciacao a geometria analitica")==0) && vetores[1]>0){
                    vetores[1] -= 1;
                    if(nlivros == 0){
                        strcpy(usu[i].livroemprestado1,"vetores e uma inicia��o a geometria analitica");
                        usu[i].livros[0] = 19;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro1);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro1);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro1);
                        printf("\n          Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia1);
                        printf("                                     -> M�s: ");
                        scanf("%d", &usu[i].mes1);
                        printf("                                     -> Ano: ");
                        scanf("%d", &usu[i].ano1);
                    }else{
                        strcpy(usu[i].livroemprestado2,"vetores e uma iniciacao a geometria analitica");
                        usu[i].livros[1] = 19;
                        printf("\n          Data do empr�stimo -> Dia: ");
                        scanf("%d", &usu[i].dialivro2);
                        printf("                             -> M�s: ");
                        scanf("%d", &usu[i].meslivro2);
                        printf("                             -> Ano: ");
                        scanf("%d", &usu[i].anolivro2);
                        printf("\n          Data limite para devolu��o -> Dia: ");
                        scanf("%d", &usu[i].dia2);
                        printf("                                     -> M�s: ");
                        scanf("%d", &usu[i].mes2);
                        printf("                                     -> Ano: ");
                        scanf("%d", &usu[i].ano2);
                    }
                    usu[i].maxlivros += 1;
                    for(int x=0; x<cont; x++){
                        if(usu[x].id == NULL){

                        }else{
                            fprintf(file, "NOME: ");
                            fprintf(file, usu[x].nome);
                            fprintf(file, "ID: ");
                            fprintf(file, "%d", usu[x].id);
                            fprintf(file, " LIVROS: ");
                            fprintf(file, "%d", usu[x].maxlivros);
                            fprintf(file, "\n");
                        }
                    }
                    fclose(file);
                    printf("\n          EMPR�STIMO BEM SUCEDIDO");
                }else{
                    for(int j=0;j<total.totallogica; j++){
                        if((strcmp(auxEmp,livroscadastrados[j].nomedolivro)==0)){
                            livroscadastrados[j].quantidade -= 1;
                            if(nlivros == 0){ // se o aluno n�o tem nenhum livro, este ser� o primeiro
                                strcpy(usu[i].livroemprestado1, livroscadastrados[j].nomedolivro);
                                usu[i].livros[0] = livroscadastrados[j].codigo; //controle de livro devolvido
                                printf("\n          Data do empr�stimo -> Dia: ");
                                scanf("%d", &usu[i].dialivro1);
                                printf("                             -> M�s: ");
                                scanf("%d", &usu[i].meslivro1);
                                printf("                             -> Ano: ");
                                scanf("%d", &usu[i].anolivro1);
                                printf("\n          Data limite para devolu��o -> Dia: ");
                                scanf("%d", &usu[i].dia1);
                                printf("                                     -> M�s: ");
                                scanf("%d", &usu[i].mes1);
                                printf("                                     -> Ano: ");
                                scanf("%d", &usu[i].ano1);
                            }else{
                                strcpy(usu[i].livroemprestado2, livroscadastrados[j].nomedolivro);
                                usu[i].livros[1] = livroscadastrados[j].codigo;
                                printf("\n  Data do empr�stimo -> Dia: ");
                                scanf("%d", &usu[i].dialivro2);
                                printf("                     -> M�s: ");
                                scanf("%d", &usu[i].meslivro2);
                                printf("                     -> Ano: ");
                                scanf("%d", &usu[i].anolivro2);
                                printf("\n          Data limite para devolu��o -> Dia: ");
                                scanf("%d", &usu[i].dia2);
                                printf("                                     -> M�s: ");
                                scanf("%d", &usu[i].mes2);
                                printf("                                     -> Ano: ");
                                scanf("%d", &usu[i].ano2);
                            }
                            usu[i].maxlivros += 1;
                            printf("\n\n            EMPR�STIMO BEM SUCEDIDO");

                        }else{
                            printf("\n          EMPR�STIMO N�O FOI BEM SUCEDIDO");
                        }
                    }
                }
            }
            setbuf(stdin,NULL);
            getch();
            setbuf(stdin,NULL);
            break;
            char aux[12] = __DATE__;
            strcpy(usu[i].DataDoSistema,aux);
    }

}

/*--------------------------------------------------------------- */


/*-----------------------------ALUNO-----------------------------*/
void FuncAluno(){
    int opcAluno;

        printf("\n          ###############################################################");
        printf("\n          #                       MENU ALUNO                            #");
        printf("\n          ###############################################################\n");
        printf("\n\n          (1) -> CADASTRAR ALUNO");
        printf("\n\n          (2) -> REMOVER ALUNO");
        printf("\n\n          (3) -> EDITAR ALUNO");
        printf("\n\n          (4) -> LISTAR ALUNOS CADASTRADOS");
        printf("\n\n          OP��O -> ");
        scanf("%d", &opcAluno);
        switch(opcAluno){
            case 1:
                system("cls");
                cont = CadAluno(cont);
                break;
            case 2:
                removerAluno(cont);
                break;
            case 3:
                alterar(cont);
                break;
            case 4:
                listar(cont);
                break;
        }
}

int CadAluno(int cont){

    FILE *file;

    file = fopen("Alunos.txt", "a");
    int i = cont;
    usu[i].maxlivros = 0;
    cont++;

    printf("\n          ###############################################################");
    printf("\n          #                      CADASTRAR ALUNO                        #");
    printf("\n          ###############################################################\n\n");
    setbuf(stdin,NULL);
    printf("\n            MATR�CULA: ");
    scanf("%d", &usu[i].id);
    setbuf(stdin,NULL);
    //MUDAN�A COME�OU AQUI
    int comparacao=0;
    for(int x = 0; x <= cont; x++){
        if(usu[x].id == usu[i].id){
            comparacao += 1;
            if(comparacao > 1){
                printf("\n          MATR�CULA J� EXISTE!");
                Sleep(2000);
                return cont-1;
            }
        }
    } // AT� AQUI

    printf("\n            NOME: ");
    fgets(usu[i].nome,20,stdin);
    setbuf(stdin,NULL);

    printf("\n            CPF: ");
    gets(usu[i].cpf);
    setbuf(stdin,NULL);

    printf("\n            Aguarde.");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);

    if(file == NULL){
        printf("\n          ERRO AO ACESSAR O ARQUIVO\n");
    }

    fprintf(file, " NOME: ");
    fprintf(file, usu[i].nome);
    fprintf(file, "ID: ");
    fprintf(file, "%d", usu[i].id);
    fprintf(file, " LIVROS: ");
    fprintf(file, "%d", usu[i].maxlivros);
    fprintf(file, "\n");
    fclose(file);
    return cont;
}

void removerAluno(int cont){
    FILE *file;
    file = fopen("Alunos.txt", "w");
    int i;
    int auxID;
    int usuarioNaoExiste=0;

    system("cls");
    printf("\n          ###############################################################");
    printf("\n          #                       REMOVER ALUNO                         #");
    printf("\n          ###############################################################\n");
    listar(cont);
    printf("\n          Informe o ID do usu�rio a ser exclu�do: ");
    scanf("%d", &auxID);
    for(i=0;i<cont;i++){ //i<50
        if(auxID == usu[i].id){
            usu[i].id = NULL;
            strcpy(usu[i].nome,"vazio");
        }else{
            usuarioNaoExiste += 1;
        }
    }
    if(usuarioNaoExiste == cont){
        printf("\n          USU�RIO N�O ENCONTRADO!");
    }else{
        printf("\n          USU�RIO REMOVIDO!");
        for(i=0;i<cont;i++){
            if(usu[i].id == NULL){

            }else{
                fprintf(file, "NOME: ");
                fprintf(file, usu[i].nome);
                fprintf(file, "ID: ");
                fprintf(file, "%d", usu[i].id);
                fprintf(file, " LIVROS: ");
                fprintf(file, "%d", usu[i].maxlivros);
                fprintf(file, "\n");

            }
        }

    }
    fclose(file);
    Sleep(2000);
}

void listar(int cont){

    int i;
    printf("\n              ######################################");
    printf("\n              #              LISTA:                #");
    printf("\n              ######################################\n\n");
    for(int x=0;x<cont;x++){
        if(usu[x].id == NULL){

        }else{
            printf("                ID: %d\n", usu[x].id);
            printf("                Nome: %s\n", usu[x].nome);
            printf("                CPF: %s\n", usu[x].cpf);
            printf("                Livros: %d", usu[x].maxlivros);
            printf("\n              ######################################\n\n");

        }

    }

    getch();
    setbuf(stdin,NULL);

}

void alterar(int cont){
    int i;
    int auxID;
    int op;
    system("cls");
    printf("\n          ###############################################################");
    printf("\n          #                     ALTERAR DADO DO ALUNO                   #");
    printf("\n          ###############################################################\n");
    listar(cont);
    printf("\n          Informe o ID do usu�rio a ser alterado: ");
    scanf("%d", &auxID);
    printf("\n          Aguarde.");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    system("cls");
    for(i=0;i<cont;i++){
        if(usu[i].id == auxID){
            printf("\n          ###############################################################");
            printf("\n          #                     ALTERAR DADO DO ALUNO                   #");
            printf("\n          ###############################################################\n");
            printf("\n          INFORME QUAL O DADO A SER ALTERADO: ");
            printf("\n\n          1. ID");
            printf("\n\n          2. NOME");
            printf("\n\n          3. CPF");
            printf("\n\n          OP��O -> ");
            scanf("%d", &op);
            switch(op){
                case 1:
                    setbuf(stdin,NULL);
                    printf("\n          ID atual: %d",usu[i].id);
                    printf("\n          Novo ID: ");
                    scanf("%d", &usu[i].id);
                    break;
                case 2:
                    setbuf(stdin,NULL);
                    printf("\n          Nome atual: %s", usu[i].nome);
                    printf("\n          Novo nome: ");
                    fgets(usu[i].nome,30,stdin);
                    break;
                case 3:
                    setbuf(stdin,NULL);
                    printf("\n          CPF atual: %s", usu[i].cpf);
                    printf("\n          Novo CPF: ");
                    gets(usu[i].cpf);
            }
            FILE *file;
            file = fopen("Alunos.txt", "w");
            for(int x=0; x<cont; x++){
                if(usu[x].id == NULL){

                }else{
                    fprintf(file, "NOME: ");
                    fprintf(file, usu[x].nome);
                    fprintf(file, "ID: ");
                    fprintf(file, "%d", usu[x].id);
                    fprintf(file, " LIVROS: ");
                    fprintf(file, "%d", usu[x].maxlivros);
                    fprintf(file, "\n");
                }
            }
            fclose(file);
        }
    }
}

/*---------------------------------------- MAIN --------------------------------------- */
int main(){

    setlocale(LC_ALL, "Portuguese");
    system("color 81");


    /* inicializa��o das vari�veis de total de livros*/
    total.totalalgoritmo = 0;
    total.totalcalculo1 = 0;
    total.totalcalculo2 = 0;
    total.totalcalculo3 = 0;
    total.totaldiscreta1 = 0;
    total.totaldiscreta2 = 0;
    total.totalintroducao = 0;
    total.totaloac = 0;
    total.totallogica = 0;
    total.totalvetores = 0;

    /*----------------------------------------------*/
    int opcMenuPrincipal;
    strcpy(testarnomeigual,"vazio");
    do{
        opcMenuPrincipal = menuPrincipal();

        switch(opcMenuPrincipal){
            case 1:
                system("cls");
                FuncAcervo();
                break;
            case 2:
                system("cls");
                FuncAluno();
                break;
            case 3:
                system("cls");
                FuncEmprestimo();
                break;
        }
    }while(opcMenuPrincipal != 4);
}
