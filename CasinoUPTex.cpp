 /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*Autores:
* GerardoMerchant*
* Ericklugo279*
* Anaid-Prieto*
*Titulo: Casino UPTex. The Place to Play!*
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#define DIM 20
using namespace std;

// Prototipos
void registro(string &n, float &apu);
void status(string &n, float &apu, float &c, int &r);
void apuesta (string &n, float &apu, float &c, int &r);
void read(string &n, float &apu);

// *******

// Funcion para repetir el programa
bool repit(int &f){
	char R;
	bool D;
	do{
		if (f == 0){
			printf("\n\n¿Desea jugar otro juego?\n\n \tS-->Si\n \tN-->No\n");
		}else if (f == 1){
			printf("\n\n¿Desea jugar de nuevo el Juego de: Dados?\n\n \tS-->Si\n \tN-->No\n");
		}else if (f == 2){
			printf("\n\n¿Desea jugar de nuevo el Juego de: Ruleta Francesa?\n\n \tS-->Si\n \tN-->No\n");
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
// ***********************************

// Seccion para el sistema de apuestas

void registro(string &n, float &apu){
	system("cls");
	cout <<"\nBienvenido por favor escribe tu nombre: ";
	cin >>n;
	cout <<"\nIngresa el dinero con el que entraras al casino: ";
	cin >> apu;
}

void status(string &n, float &apu, float &c, int &r){
	if (r==1){ // Si Ganas
		apu+= c+c;
		cout<< "\n\tSe ha agregado el doble de su apuesta a sus creditos.\nTotal: "<< apu<<endl;
	}else if (r==2){ // pierdes
		cout<< "\n\tSus creditos actuales: "<< apu<<endl;
		if (r==2 && apu==0){
		//apu-=c;
		system("cls");	
		cout<< "Lo sentimos has perdido, te has quedado sin creditos."<<endl;
		read(n, apu);
		exit(1);
	}
	}else if(r==3){// Estatus d
		cout<< "\n\tSus creditos actuales: "<< apu<<endl;
	}
	
}

void apuesta (string &n, float &apu, float &c, int &r){ // Apuesta inicial de cada juego
		bool op;
		float t;
		int re;
		system("cls");
		cout<< "\t============ Apuestas =========="<< endl;
		status(n, apu, c, r=3);
		do{
			
			cout << "Cuantos creditos apuestas " << " --> ";
	    	cin >> c;
	    	if(c > apu){
				system("cls");
				cout<< "Lo sentimos, la cantidad que intenatas apostar exede el total de tus creditos actuales. Intentalo de nuevo. . .\n";
				op=false;
			}else if (c == apu){
	    		cout<< "Estas seguro que deceas apostar todos tus creditos actuales?\n\n\t1---> Si\n\t2---> No\n";
	    		cin >> re;
	    		if (re==1){
	    			op=true;
				}else if(re==2){
				op=false;	
				}
			}else if (c<=apu){
				op=true;
			}
			
		} while(op == false);
		
	    apu-=c;
	    cout<< "Has apostado "<<c<< " en este juego. Te quedan: " << apu << " creditos para seguir jugando."<< endl;
	    system("Pause");
	    system("cls");
 
}

void read(string &n, float &apu){
	int s=3000;
	string datos;
	ofstream a("Reg.txt",ios::out);
	if (a.is_open()){
		a <<"\t\tResultados: \n\nUsuario: "<<n<<"\t Total de creditos ganados: " <<apu<<endl;

	}else cerr << "Error al abrir el archivo"<<endl;
	
	cout<<"\t\tGenerando resultados...\n";
	clock_t time_end;
       time_end = clock() + s * CLOCKS_PER_SEC/1000;
       while (clock() < time_end)
       {
       }
   
	system("cls");
	ifstream f("Reg.txt",ios::in);
	if (f.is_open()){
		while (!f.eof()){
			getline (f, datos);
			cout << datos << endl;
		}
		f.close();
	}
	
	else cerr << "Error al abrir el archivo"<<endl;
}

// ************************

// Seccion del Juego de dados*********
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

void Dados_J1(int &f, string &n, float &apu, float &c, int &r){
	system ("cls");
	int player = 0, house = 0, D1, D2;
	bool checked, sal, rep;
	apuesta(n, apu, c, r);
	status(n, apu, c, r=3);
	cout <<"\t==========================================================================="<< endl;
  	cout <<"\t=                               Juego de Dados                            ="<< endl;
  	cout <<"\t=                                Bienvenido                               ="<< endl;
  	cout <<"\t==========================================================================="<< endl;
	cout<< "\n \t Reglas:\n"
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
		status(n, apu, c, r=1);
	}else{
		cout<<"\n\nLa casa ha ganado "<<house<<" a "<<player<<" mejor suerte para la proxima.";
		status(n, apu, c, r=2);
	}
		

	if (rep=repit(f = 1)==true){
					return Dados_J1(f, n,apu,c,r);	
}	
}
//**************************************

// Seccion del juego de Ruleta Francesa **************

char presentacion(string &n, float &apu, float &c, int &r){
 char ca;
 apuesta(n, apu, c, r);
do {
	status(n, apu, c, r=3);
	cout <<"\t==========================================================================="<< endl;
  	cout <<"\t=                              Ruleta Francesa                            ="<< endl;
  	cout <<"\t=                                Bienvenido                               ="<< endl;
  	cout <<"\t==========================================================================="<< endl;
printf ("Que tipo de apuesta quieres realizar?\n (Para elegir escribe la letra correspondiente: )\n\n");

printf ("A - Pares o Impares \t B - Columna \t C - Terna \t D - Pleno (un numero)\n");

scanf ("%c",&ca);

system("cls"); } while (ca!='A' && ca!='B' && ca!='C' && ca!='D' && ca!='a' && ca!='b' && ca!='c' && ca!='d');
 return ca;
}

void espera(int segundos)
{
 //srand(time(NULL));  
 int Seg1,Seg2;
 Seg1=(int)clock()/CLOCKS_PER_SEC;
 Seg2=Seg1;
 while((Seg2-Seg1) < segundos){
 if(clock()%400<10){
 system("cls");
 printf ("\nUna vez hecha la apuesta, toca ver que numero sale en la ruleta :\n\n\t%d",rand() % 37);
 }
 Seg2=(int)clock()/CLOCKS_PER_SEC;
 }
}

void Ruleta_J2(int &f, string &n, float &apu, float &c, int &r){
	char ce;
 	int no=0,m[DIM],i,premio,k=4;
 	bool rep;
 	//apuesta(n, apu, c, r);
	//status(n, apu, c, r=3);
srand(time(NULL));

ce=presentacion (n, apu, c, r);

switch (ce) {
 case 'A' :
 case 'a' :
 do {
 printf ("1 - Apostar a los pares \t 2 - Apostar a los impares\n");
 scanf ("%d",&no);}while(no!=1 && no!=2);
 break;

case 'B' :
case 'b' :
 do {
 printf ("1 - Apostar a la primera columna \t 1-4-7-10-13-16-19-22-25-28-31-34\n");
 printf ("2 - Apostar a la segunda columna \t 2-5-8-11-14-17-20-23-26-29-32-35\n");
 printf ("3 - Apostar a la tercera columna \t 3-6-9-12-15-18-21-24-27-30-33-36\n");
 scanf ("%d",&no);}while(no!=1 && no!=2 && no!=3);
 break;

case 'C' :
case 'c' :
 do {
 printf ("Dime a los tres numeros que quieres apostar \n(Comprendidos entre 1 y 36):\n");
 for (i=0;i<3;i++)
 scanf ("%d",&m[i]);
 }
 while((m[0]<=0 || m[0]>36) || (m[1]<=0 || m[1]>36) || (m[2]<=0 || m[2]>36));
 break;

case 'D' :
case 'd' :
 do {
 printf ("Dime el numero al que quieres apostar \n(Comprendido entre 1 y 36):\n");

scanf ("%d",&no);
 }
 while(no<=0 || no>36); break;
 }
 
 // ************************

system("cls");

printf ("\nUna vez hecha la apuesta, toca ver que numero sale en la ruleta :\n\n");

for(i=1;i<=100;i++) rand();  //descartamos los 100 primeros números aleatorios
premio = rand() % 37;      //almacenamos el número premiado 

espera (k);  //simulación de la bola moviéndose en la ruleta
system("cls");

if (ce=='A' || ce=='a' && no==1){
	cout<< "Apostaste a los pares"<<endl;
}else if (ce=='A' || ce=='a' && no==2){
	cout<< "Apostaste a los impares"<<endl;
}else if (ce=='B' || ce=='b'){
	if (no==1){
		printf ("Apostaste por la primera columna \t 1-4-7-10-13-16-19-22-25-28-31-34\n");
	}else if (no==2){
		printf ("Apostaste por la segunda columna \t 2-5-8-11-14-17-20-23-26-29-32-35\n");
	}else if (no==3){
		printf ("Apostaste por la tercera columna \t 3-6-9-12-15-18-21-24-27-30-33-36\n");
	}
}else if(ce=='C' || ce=='c'){
	cout<< "Apostaste por los numeros: ";
	for (i=0;i<3;i++){
		printf ("%d, ",m[i]);
	}
 	
 }else if (ce=='D' || ce=='d'){
 	cout<< "El numero al que apostaste es: "<<no<<endl;
 }

printf ("\nUna vez hecha la apuesta, toca ver que numero sale en la ruleta :\n\n");

printf ("\t%d\n\n",premio);

if (premio==0) {
 printf ("Gana la banca!\n");
 status(n, apu, c, r=2);
 system ("pause");
 if (rep=repit(f = 2)==true){
		return Ruleta_J2(f, n,apu,c,r);	
}	
 }

switch ( ce ) {
 case 'A' :
 case 'a' :
 if ((no==1 && premio%2 == 0) || (no==2 && premio%2 == 1)){
 	printf ("Has ganado! \n");
 	status(n, apu, c, r=1);
 } else{
 	printf ("Lo siento! Otra vez sera \n");
 	status(n, apu, c, r=2);
 } 
 
 break;

case 'B' :
case 'b' :
 if ((no==1 && premio%3 == 1) || (no==2 && premio%3 == 2) || (no==3 && premio%2 == 0)){
 	printf ("Has ganado! \n");
 	status(n, apu, c, r=1);
 } else{
 	printf ("Lo siento! Otra vez sera \n");	
 	status(n, apu, c, r=2);
 } 
 
 break;

case 'C' :
case 'c' :
 if ((m[0]==premio) || (m[1]==premio) || (m[2]==premio)){
 	printf ("Has ganado! \n");
 	status(n, apu, c, r=1);
 }else{
 	printf ("Lo siento! Otra vez sera \n");
 	status(n, apu, c, r=2);
 } 
 
 break;
 
case 'D' :
case 'd' :
 if (no==premio){
 	printf ("Has ganado! \n");
 	status(n, apu, c, r=1);
 }else{
 	printf ("Lo siento! Otra vez sera \n");
 	status(n, apu, c, r=2);
 } 
 
 break;

}
 system ("pause");
 if (rep=repit(f = 2)==true){
		return Ruleta_J2(f, n,apu,c,r);	
}
	
}
//*****************************

// Funcion Principal ***************

int main(){
	string nom;
	int fin, op, res, reg=0;
	float cr,apuest;
	bool rep;
	do{
	if (reg==0){
	registro(nom, apuest);
	reg++;	
	}
	system("cls");	
	cout <<"\t==========================================================================="<< endl;
  	cout <<"\t=                      Casino UPTex. The Place to Play!                   ="<< endl;
  	cout <<"\t=                                Bienvenido                               ="<< endl;
  	cout <<"\t==========================================================================="<< endl;
	status(nom, apuest, cr, res=3);
	cout<< "\n\t\tJuegos disponibles:\n\n\t\t1---> Juego de Dados\n\t\t2---> Ruleta Francesa\n\t\t3---> J3 *Proximamente*\n\t\t4---> Salir del casino"<<endl;
	cout<< "\nQue juego desea jugar?\n Ingresa: ";
	cin >> op;
	switch (op){
		case 1: Dados_J1(fin, nom,apuest, cr, res);
			break;
			case 2: Ruleta_J2(fin, nom,apuest, cr, res);
				break;
				case 3: exit(1);
					break;
					case 4:
					read(nom, apuest);
					exit (1);					
	}
	
	rep=repit(fin = 0)==true;
}while(rep==true);
		
read(nom, apuest);
return 0;	
}
