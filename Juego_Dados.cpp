/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*Autor: GerardoMn*
*Titulo: Juego de dados con funcion SRAND*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

bool repit(){
	char R;
	bool D;
	do{
		printf("\n\n¿Desea jugar de nuevo?\n\n \tS-->Si\n \tN-->No\n");
		printf("Ingresa: ");
		scanf ("%s",& R);
		if(R=='S' || R=='s'){
		system ("cls");
		return D=true;	
		}else if(R=='N' || R=='n'){ 
		return 0;	
		}else 
		printf("\nNo es una opcion valida.\n \tIntentelo de nuevo...\n\n");
			}while (R!='s' || R!='n' || R=='S' || R=='N');
}

int Dado1(){
	int	valD1;
	srand(time(NULL));
	valD1= 1 + rand()%(6);
	
	return valD1;
}

int Dado2(){
	int	valD2;
	srand(time(NULL));
	valD2= 2 + rand()%(5);
	
	return valD2;
}

bool check(int x, int y){
	bool player;
	if(x+y==7 || x+y==11){
		return player=true;
	} else 
	return player=false;
}

int main(){
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
	
	// Fin del juego..
	
	if (rep=repit()==true){
		return main();
	}
	
}

