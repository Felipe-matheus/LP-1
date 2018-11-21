#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
		char nome[100];
		int ano;
		float nota;
	}movie;
	movie movies[100];

int load(char txt[50]){

   FILE *file;

   char l[30];

   int i, k = 0;

   // Abrindo o arquivo.

   file = fopen(txt,"r");


   // Lendo os dados do arquivo e salvando no vetor.

   while(!feof(file)){

       fgets(movies[i].nome, 30, file);
       fscanf(file,"%d",movies[i].ano, 30);
       fscanf(file,"%f",movies[i].nota, 30);
       fgets(l, 30, file);
       fscanf(file, "%d", k);
       i++;

   }

   fclose(file);

   return 0;

}
main(){
	//load("lista.txt");
	FILE *file;
	int menu,i=0,op,opc,k,n=0;
	char name[100];
	do{
		printf("\nInsira a opcao desejada: \n1-cadastrar\n2-editar\n3-listar\n4-deletar\n5-sair\n");
		scanf("%d", &menu);
		system("cls");
		switch(menu){
			case 1:
				do{
					fflush(stdin);
					printf("\nInsira o nome do filme: ");
					gets(movies[n].nome);
					fflush(stdin);
					printf("\nInsira o ano em que o filme foi lancado: ");
					scanf("%d", &movies[n].ano);
					fflush(stdin);
					printf("\nInsira a sua nota para o filme: ");
					scanf("%f", &movies[n].nota);
					fflush(stdin);
					printf("\nDeseja adicionar mais um filme? \n1-sim\n2-nao\n");
					scanf("%d", &op);
					n++;
					system("cls");
				}while(op==1);
				break;
			case 2:
				fflush(stdin);
				printf("\nDeseja fazer alteracao em qual filme(insira o numero do indice dele na lista): ");
				scanf("%d", &k);
				fflush(stdin);
				printf("\nQual o novo nome para o filme: ");
				gets(name);
				strcpy(movies[k].nome,name);
				fflush(stdin);
				printf("\nQual o ano desse novo filme: ");
				scanf("%d", &movies[k].ano);
				fflush(stdin);
				printf("\nInsira a nova nota do filme: ");
				scanf("%f", &movies[k].nota);
				system("cls");
				break;
			case 3:
				for(i=0;i<n;i++){
					printf("\nnome: ");
					puts(movies[i].nome);
					printf("ano: %d", movies[i].ano);
					printf("\nnota: %.f", movies[i].nota);
				}
				break;
				system("cls");
		
				
		}
	}while(menu!=5);
	file=fopen("lista.txt", "w");
	for(i=0;i<n;i++){
		fprintf(file,"\n%s", movies[i].nome);
		fprintf(file,"\n%d", movies[i].ano);
		fprintf(file,"\n%.1f", movies[i].nota);
	 }
	fclose(file);
}
