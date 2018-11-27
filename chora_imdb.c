#include<stdio.h>

#include<string.h>

#include<stdlib.h>

typedef struct{
	char nome[100];
	int ano;
	float nota;
}movie;
movie movies[100];
int n;
FILE *file;

cadastrar(){
	int i=0, op;
	do{
		fflush(stdin);
		printf("\nInsira o nome do filme: ");
		gets(movies[i].nome);
		fflush(stdin);
		printf("\nInsira o ano que o filme foi lancado: ");
		scanf("%d", &movies[i].ano);
		printf("\nInsira a nota do filme: ");
		scanf("%f", &movies[i].nota);
		i++;
		system("cls");
		fflush(stdin);
		printf("\nDeseja inserir mais um filme: \n1-sim\t2-nao\n");
		scanf("%d",&op);
		system("cls");
		
		
	}while(op==1);
	n=i;
}
editar(){
	int k,opc;
	char nome[100];
	do{
		fflush(stdin);
		printf("\nDeseja fazer alteracao em qual filme(insira o numero do indice dele na lista): ");
		scanf("%d", &k);
		fflush(stdin);
		printf("\nQual o novo nome para o filme: ");
		gets(nome);
		strcpy(movies[k].nome,nome);
		fflush(stdin);
		printf("\nQual o ano desse novo filme: ");
		scanf("%d", &movies[k].ano);
		fflush(stdin);
		printf("\nInsira a nova nota do filme: ");
		scanf("%f", &movies[k].nota);
		printf("\nDeseja editar mais um filme: \n1-sim\t2-nao\n");
		scanf("%d",&opc);
	}while(opc==1);
	system("cls");

}

listar(){
	int i;
	for(i=0;i<n;i++){

		printf("\nnome: ");

		puts(movies[i].nome);

		printf("ano: %d", movies[i].ano);

		printf("\nnota: %.2f", movies[i].nota);
		


	}
}



main(){
	int menu,j;
	do{
	printf("Insira a opção desejada: \n1-cadastrar\t2-editar\n3-listar\t4-sair\n");
	scanf("%d", &menu);
	system("cls");
	switch(menu){
		case 1:
			cadastrar();
			break;
		case 2:
			editar();
			break;
		case 3:
			listar();
			break;
		
	}
	}while(menu<4 && menu>0);
	file=fopen("filmes.txt","w");
		for(j=0;j<n;j++){
			fprintf(file,"%s\n",movies[j].nome);
			fprintf(file,"%d\n", movies[j].ano);
			fprintf(file, "%.1f\n", movies[j].nota);
		}
	fclose(file);
}
