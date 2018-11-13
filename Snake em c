#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>


//Código feito com base em tutoriais na internet.

void mgotoxy(int x, int y)
{
//função pra desenhar as paredes
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

main()
{
 int x,d=2,cx[300]={1,2},cy[300]={7,7},t=1,mx,my,velo=100,velo2=5,menu;
 char niv;

 char tecla='a';
 int opcao;
 int pontos=0;
 int nivel = 1;
 
 
 printf("Deseja:\n1-JOGAR\n2-SAIR\n");
 scanf("%d", &menu);
 system("cls");
 
 
 for(x=0;x<18;x++)
 { mgotoxy(0,x); //vertical esquerda.//
 
 printf("%c",219);
 }
 for(x=0;x<50;x++)
 { mgotoxy(x,0); //horizontal superior//
 printf("%c",219);
 }
 for(x=0;x<18;x++)
 { mgotoxy(50,x); //vertical direita//
 printf("%c",219);
 }
 for(x=0;x<51;x++)
 { mgotoxy(x,18); //horizontal inferior.//
 printf("%c",219);
 }
//pra gerar a maçã aleatoriamente
 if(pontos<5){
 srand(time(NULL));
 mx=(rand()%49)+1;
 my=(rand()%17)+1;
 }
 
 
 velo = 200;

 
 while(tecla!='s') //enquanto a variavel tecla for diferente de s o laço continua
 { while(tecla!='s'&&!(tecla=kbhit()))
 
 { for(x=t;x>0;x--)
 { cx[x]=cx[x-1];//apagam o rastro da cobra
 cy[x]=cy[x-1];
 }
 //linhas pra movimentar a cobra pela tela
 if(d==0)cx[0]--;
 if(d==1)cy[0]--;
 if(d==2)cx[0]++;
 if(d==3)cy[0]++;
 mgotoxy(cx[t],cy[t]);//linha que desenha a cobra
 printf(" ");
 if(mx==cx[0]&&my==cy[0])//caso a cobra pegue a maçã e aumenta de tamanho
 { t++;
 pontos++;
 mx=(rand()%25)+1;
 my=(rand()%17)+1;
 velo-=5;
 velo2+=5;
 
 }
 //gerar barra que é gostar de você.
 if(pontos==5){
 for(x=0;x<9;x++)
 { mgotoxy(0,x); //vertical esquerda.//
 
 printf("%c",219);
 if(x=9){
	for(x=0;x<20;x++)
 { 
 mgotoxy(x,9); //horizontal inferior.//
 printf("%c",219);
 }
 if(cy[0]==0||cy[0]==9||cx[0]==0||cx[0]==25)tecla='s';	
 }
 }	
 	
 }
 
 mgotoxy(cx[0],cy[0]);
 
 printf("%c",219);
//desenhar a maçã
 mgotoxy(mx,my);
 printf("%c",1);
 //menu
 mgotoxy(55,10);
 
 printf ("Pontos: %d",pontos);
 mgotoxy(55,5);
 printf ("Nivel: %d",nivel);
 mgotoxy(55,3);
 printf ("Velocidade: %d",velo2);
 mgotoxy(3,22);

 printf ("Chama no probleminha\0");
 Sleep(velo);//determina a velocidade da cobra
 for(x=1;x<t;x++)
 { if(cx[0]==cx[x]&&cy[0]==cy[x])tecla='s';
 }
 if(cy[0]==0||cy[0]==18||cx[0]==0||cx[0]==50)tecla='s';
 
 
 
 

 }
 if(tecla!='s')tecla=getch();
 if(tecla=='K')d=0;
 if(tecla=='H')d=1;
 if(tecla=='M')d=2;
 if(tecla=='P')d=3;
 if(cy[0]==0||cy[0]==18||cx[0]==0||cx[0]==26)tecla='s';
 
 }
 system("cls");
 system("pause");
//mensagem de fim de jogo
 printf ("\n\n\tVOCE PERDEU\n\n");

 printf ("\n\n\tVOCE FEZ %d PONTOS",pontos);
 

 


 

 getch();
}
