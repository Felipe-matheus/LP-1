#include<stdio.h>

#include<string.h>

#include<stdlib.h>

typedef struct{
	char nome[100];
	int deletado;
	int ano;
	float nota;
}movie;
movie movies[100];
int n;
FILE *file;




cadastrar(){
	int i=0, op;
	do{
		movies[i].deletado = 0;
		
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
		if(movies[i].deletado == 0){
			printf("\n nome: ");
			puts(movies[i].nome);
			printf("ano: %d", movies[i].ano);
			printf("\n nota: %.2f", movies[i].nota);	
		}
	}
}


deletar(){
	int k;
	fflush(stdin);
	printf("\nDeseja deletar qual filme (insira o numero do indice dele na lista): ");
	scanf("%d", &k);
	movies[k].deletado = 1;
}

main(){
	file = fopen("quantidade.txt", "r");
	fscanf(file, "%d", &n);
	printf("%d\n\n", n);
	fclose(file);
	int g;
	file = fopen("filmes.txt", "r");
	for(g = 0;g < n; g++){
		fscanf(file,"%s", &movies[g].nome);
		fscanf(file,"%d", &movies[g].ano);
		fscanf(file,"%f", &movies[g].nota);
	}
	fclose(file);
	int menu,j;
	do{
	printf("Insira a opção desejada: \n1-cadastrar\t2-editar\n3-listar\t4-deletar\n5-sair\n");
	scanf("%d", &menu);
	//system("cls");
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
		case 4:
			deletar();
			n--;
		
	}
	}while(menu<5 && menu>0);
	file=fopen("filmes.txt","w");
		for(j=0;j<n;j++){
			if(movies[j].deletado == 0){
				fprintf(file,"%s\n",movies[j].nome);
				fprintf(file,"%d\n", movies[j].ano);
				fprintf(file, "%.1f\n", movies[j].nota);	
			}
		}
	fclose(file);
	file = fopen("quantidade.txt", "w");
	fprintf(file, "%d", n);
	fclose(file);
}
