#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


using namespace std;


// Inicio codigo juego Ahorcado

int ahorcado() {

    char frase[60],rep[100],temporal[100];
    char pal;
    int longitud,i,j,inicial,acertado=0,temp=0,oportunidades=0;
    int repetido=0,gano=0;
    cout<<"\t\t _______________________________ \n";
    cout<<"\t\t|                               |\n";
    cout<<"\t\t|             AHORCADO          |\n";
    cout<<"\t\t|_______________________________|\n";
    cout<<"\t\tIntroduzca la palabra a adivinar: "; cin>>frase;//gets(frase);
    system("cls");
    longitud = 0;
    inicial = 0;
    j = 0;
    rep[0] = ' ';
    rep[1] = '\0';
	oportunidades = strlen(frase)+1;
    do {
        system("cls");
        temp=0;
        if(inicial == 0) {
         for(i=0;i<strlen(frase);i++) {
          if(frase[i] == ' ') {
            temporal[i] = ' ';
             longitud++;
          }
          else {
             temporal[i] = '_';
             longitud++;
          }
         }
        }
inicial = 1;
        temporal[longitud] = '\0';
        for(i=0;i<strlen(rep);i++) {
           if(rep[i] == pal) {
            repetido = 1;
            break;
          }
          else {
           repetido = 0;
         }
        }
        if(repetido == 0) {
         for(i=0;i<strlen(frase);i++) {
            if(frase[i] == pal) {
             temporal[i] = pal;
              acertado++;
              temp=1;
            }
          }
        }
        if(repetido == 0) {
         if(temp == 0) {
           oportunidades -= 1;
         }
        }
        else {
         printf("Ya se ha introducido este caracter");
         printf("\n\n");
        }
        printf("\n");
        for(i=0;i<strlen(temporal);i++) {
         printf(" %c ",temporal[i]);
        }
        printf("\n");
        if(strcmp(frase,temporal) == 0) {
            gano = 1;
            break;
        }
        printf("\n");
        printf("Letras Acertadas: %d",acertado);
        printf("\n");
        printf("Oportunidades Restantes: %d",oportunidades);
        printf("\n");
        rep[j] = pal;
        j++;
        if (oportunidades==0)
        {
           break;
        }
        printf("Introduzca una letra:");
        scanf("\n%c",&pal);
    }while(oportunidades != 0);
    if(gano) {
        printf("\n\n");
        printf("Felicitaciones adivinaste la palabra.");
    }
    else {
   printf("\n\n");
        printf("Lo siento, has perdido. Intenta de nuevo.");
    }
    printf("\n\n");
    system("pause");
    return 0;
}

// Fin codigo juego ahorcado

// Inicio codigo juego Triqui

void pintar_tablero(char* tablero)
{
system("cls");
system ("color 10");
	cout<<"\t\t _______________________________ \n";
    cout<<"\t\t|                               |\n";
    cout<<"\t\t|             TRIQUI            |\n";
    cout<<"\t\t|_______________________________|\n";

cout << "\t\tJugador 1 (X)  -  Jugador 2 (O)" << endl << endl;
cout << endl;

cout << "\t\t\t     |     |     " << endl;
cout << "\t\t\t  " << tablero[1] << "  |  " << tablero[2] << "  |  " << tablero[3] << endl;

cout << "\t\t\t_____|_____|_____" << endl;
cout << "\t\t\t     |     |     " << endl;

cout << "\t\t\t  " << tablero[4] << "  |  " << tablero[5] << "  |  " << tablero[6] << endl;

cout << "\t\t\t_____|_____|_____" << endl;
cout << "\t\t\t     |     |     " << endl;

cout << "\t\t\t  " << tablero[7] << "  |  " << tablero[8] << "  |  " << tablero[9] << endl;

cout << "\t\t\t     |     |     " << endl << endl;
}

int validar_ganar(char* tablero)
{
if (tablero[1] == tablero[2] && tablero[2] == tablero[3])
return 1;
else if (tablero[4] == tablero[5] && tablero[5] == tablero[6])
return 1;
else if (tablero[7] == tablero[8] && tablero[8] == tablero[9])
return 1;
else if (tablero[1] == tablero[4] && tablero[4] == tablero[7])
return 1;
else if (tablero[2] == tablero[5] && tablero[5] == tablero[8])
return 1;
else if (tablero[3] == tablero[6] && tablero[6] == tablero[9])
return 1;
else if (tablero[1] == tablero[5] && tablero[5] == tablero[9])
return 1;
else if (tablero[3] == tablero[5] && tablero[5] == tablero[7])
return 1;
else if (tablero[1] != '1' && tablero[2] != '2' && tablero[3] != '3'
                    && tablero[4] != '4' && tablero[5] != '5' && tablero[6] != '6'
                  && tablero[7] != '7' && tablero[8] != '8' && tablero[9] != '9')
return 0;
else
return -1;
}

int triqui()
{
int jugador = 1,i,escogencia;

char simbolo;
char tablero[10] = {'o','1','2','3','4','5','6','7','8','9'};

do
{
pintar_tablero(tablero);
jugador=(jugador%2)?1:2;

cout << "\t\tJugador " << jugador << " - Por favor ingrese un numero:  ";
cin >> escogencia;

simbolo=(jugador == 1) ? 'X' : 'O';

if (escogencia == 1 && tablero[1] == '1')
tablero[1] = simbolo;
else if (escogencia == 2 && tablero[2] == '2')
tablero[2] = simbolo;
else if (escogencia == 3 && tablero[3] == '3')
tablero[3] = simbolo;
else if (escogencia == 4 && tablero[4] == '4')
tablero[4] = simbolo;
else if (escogencia == 5 && tablero[5] == '5')
tablero[5] = simbolo;
else if (escogencia == 6 && tablero[6] == '6')
tablero[6] = simbolo;
else if (escogencia == 7 && tablero[7] == '7')
tablero[7] = simbolo;
else if (escogencia == 8 && tablero[8] == '8')
tablero[8] = simbolo;
else if (escogencia == 9 && tablero[9] == '9')
tablero[9] = simbolo;
else
{
cout<<"\t\tOpcion invalida.";
jugador--;
cin.ignore();
cin.get();
}
i=validar_ganar(tablero);
jugador++;
}while(i==-1);
pintar_tablero(tablero);
if(i==1)
cout<<"\t\t==> \a\t\tJugador "<<--jugador<<" gana ";
else
cout<<"\t\t==> \a\t\tJuego empatado";
cin.ignore();
cin.get();
return 0;
}

int main()
{
int opcion=0;
int a;

while (opcion != 3) {
	system("color 01");
cout<<"\t\t*************************************************\n";
cout<<"\t\t*  PROYECTO FINAL PROGRAMACION DE COMPUTADORES  *\n";
cout<<"\t\t*  PROFESOR:    OMAR CAMARGO VARGAS             *\n";
cout<<"\t\t*  ESTUDIANTE:  SAMUEL RAMOS                    *\n";
cout<<"\t\t*  ESTUDIANTE:  DELWIN PADILLA                  *\n";
cout<<"\t\t*  ESTUDIANTE:  KENEY VILLEGAS                  *\n";
cout<<"\t\t*                                               *\n";
cout<<"\t\t*                                               *\n";
cout<<"\t\t*************************************************\n";
cout<<"\t\t*                                               *\n";
cout<<"\t\t*          ENTRETENIMIENTO                      *\n";
cout<<"\t\t*                                               *\n";
cout<<"\t\t*  Seleccione la opcion del juego deseado       *\n";
cout<<"\t\t*                                               *\n";
cout<<"\t\t*  1. AHORCADO                                  *\n";
cout<<"\t\t*  2. TRIQUI                                    *\n";
cout<<"\t\t*  3. TERMINAR                                  *\n";
cout<<"\t\t*                                               *\n";
cout<<"\t\t*                                               *\n";
cout<<"\t\t*************************************************\n";
cout<<"\t\t            Seleccione la opcion: ";cin>>opcion;
cout<<"\t\t*                                               *\n";
cout<<"\t\t*************************************************\n";
cout<<endl;
while (((opcion != 1) && (opcion != 2)) && ((opcion != 3)))
{
cout<<"Opcion invalida. Por favor ingrese una opcion valida.\n";
cout<<"Seleccione la opcion: ";
cin>>opcion;
}

switch (opcion){
case 1: system("cls"); ahorcado(); system("cls"); break;
case 2: system("cls"); triqui(); system("cls"); break;
   case 3: cout<<"\t\t\t\tGracias por Jugar!!\n"; cout<<"\t\t\t\tRegrese Pronto.\n\n"; break;
}
}
system("pause");
    return EXIT_SUCCESS;
}
