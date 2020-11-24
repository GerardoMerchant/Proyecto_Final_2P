/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*Autor: *
*Titulo: Casino UPTex*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// variable global para imprimir el mensaje final deseado.
int fin;

// Funcion para repetir el programa
bool repit(){
	char R;
	bool D;
	do{
		if (fin == 0){
			printf("\n\n¿Desea jugar otro juego?\n\n \tS-->Si\n \tN-->No\n");
		}else 
		if (fin == 1){
			printf("\n\n¿Desea jugar de nuevo el Juego de Dados?\n\n \tS-->Si\n \tN-->No\n");
		}
		
		printf("Ingresa: ");
		scanf ("%s",& R);
		if(R=='S' || R=='s'){
		system ("cls");
		return D=true;	
		}else if(R=='N' || R=='n'){ 
		return false;	
		}else 
		printf("\nNo es una opcion valida.\n \tIntentelo de nuevo...\n\n");
			}while (R!='s' || R!='n' || R=='S' || R=='N');
}

// Tiro de dado numero 1 
int Dado1(){
	int	valD1;
	srand(time(NULL));
	valD1= 1 + rand()%(6);
	
	return valD1;
}

// Tiro de dado numero 2
int Dado2(){
	int	valD2;
	srand(time(NULL));
	valD2= 2 + rand()%(5);
	
	return valD2;
}

// Funcion para saber 
bool check(int x, int y){
	bool player;
	if(x+y==7 || x+y==11){
		return player=true;
	} else 
	return player=false;
}

void Dados_J1(){
	system ("cls");
	int player = 0, house = 0, D1, D2;
	bool checked, sal, rep;
	cout<<"\t\t BIENVENIDO AL JUEGO DE DADOS.\n\n \t Reglas:\n"
	"\t *El jugador obtiene un punto si consigue que la suma de los numeros de los dados"
	" sea 7 u 11, gana si acumula 3 puntos.\n \t *La casa obtiene un punto si la suma de los numeros de los dados"
	" es diferente a 7 u 11, gana si acumula 3 puntos.\n \t *Si los dados tienen el mismo numero se tendran que"
	" volver a tirar los dados.\n\n";
	do {
	
	cout<<"\nTIRE LOS DADOS...\n";
	system ("pause");
	
	D1= Dado1();
	D2= Dado2();
	
	while (D1==D2){
		cout<<"\nEl reultado ambos dados han sido iguales a: "<<D1<<" vuelva a tirar los dados...";
		cout<<"\nTIRE LOS DADOS...\n";
		system ("pause");
	
		D1= Dado1();
		D2= Dado2();
	}
	
	cout<<"\nEl resultado del dado numero UNO ha sido: "<<D1<<" y del nuemro DOS: "<<D2<< endl;
	
	checked= check(D1,D2);
	
	if (checked == true){
		player++;
		cout<<"\nPUNTO PARA EL JUGADOR\n";
	}else{
		house++;
		cout<<"\nPUNTO PARA LA CASA\n";
	}
	system ("pause");	
	system ("cls");
	cout<<"\n\t\tPuntuacion:\n\n \t Jugador: "<<player<<"\n\t Casa: "<<house;
	if (player == 3 || house == 3){
		sal=true;
	}else
	sal=false;
	}while(sal==false);
	
	if (player == 3){
		cout<<"\n\nFELICIDADES usted a ganado "<<player<<" a "<<house;
	}else
		cout<<"\n\nLa casa ha ganado "<<house<<" a "<<player<<" mejor suerte para la proxima.";
		fin = 1;
	if (rep=repit()==true){
					return Dados_J1();	
}	
}

// Funcion Principal

int main(){
	int op;
	bool rep;
	cout<< "\t\t *********** Bienvenido al Casino UPTex ***********\n\n";
	cout<< "\t\tJuegos disponibles:\n\n\t\t1---> Juego de Dados\n\t\t2--->J2\n\t\t3--->J3\n\t\t4--->Salir del casino"<<endl;
	cout<< "\nQue juego desea jugar?\n Ingresa: ";
	cin >> op;
	switch (op){
		case 1: Dados_J1();
			break;
			case 2:
				break;
				case 3:
					break;
					case 4: exit (1);
						
	}
	fin = 0;
	if (rep=repit()==true){
					return main();	
}else return 0;
	
}

