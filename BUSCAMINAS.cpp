#include <iostream>
#include<ctime>
#include<string>
#include<stdlib.h>
using namespace std;
int x,h;
void PonerUnos(int Unos[][20]){ 
	for (int a=0;a<10;a++){
		x=rand()%19;
		h=rand()%19;
		Unos[x][h]=1;
	}
}
void PonerNueves(string Pantalla[][20]){
	char x=254;
	for (int a=0;a<20;a++){
		for (int b=0;b<20;b++){
			
			Pantalla[a][b]=x;
		    
		}
	}

}

int VerificarCantidadMinas(int filas,int columnas,int Minas[20][20]){
	int contador=0;
	for (int a=filas-1;a<=filas+1;a++){
		for (int b=columnas-1;b<=columnas+1;b++){
			if (Minas[a][b]==1){
			contador++;
			}
			
		}
	}

	return contador;
}
string Variable(int filas, int columnas, int minas[][20]){
	int p;
	string m;
	p=VerificarCantidadMinas(filas,columnas,minas);
	m.push_back((char)(p+'0'));
	return m;
}
void Izquierda(int filas, int columnas, int minas[][20], string Pantalla[][20],bool bandera);
void Arriba(int filas, int columnas, int minas[][20], string Pantalla[][20],bool bandera);
void Abajo(int filas, int columnas, int minas[][20], string Pantalla[][20],bool bandera);
void Bordes(int filas,int columnas, int minas[][20], string Pantalla[][20]);
int main() {
	srand(time(0));
	int MatrizMinas[20][20]={};
	string MostrarPantalla[20][20];
	string m;
	int p;
	int fila,columna,FilaMatriz,ColumnaMatriz;
	bool Juego=true;
	PonerNueves(MostrarPantalla);
	PonerUnos(MatrizMinas);
	do{
		int nf,nc,NF,NC=NF=nc=nf=1;
		for (int a=0;a<20;a++){
		for (int b=0;b<20;b++){
			cout<<MostrarPantalla[a][b]<<" ";
			}
		cout<<"\n";
		}
	cout<<"Ingresar fila: ";
	cin>>FilaMatriz;
	cout<<"Ingresar columna: ";
	cin>>ColumnaMatriz;
	fila=FilaMatriz-1;
	columna=ColumnaMatriz-1;
	if (MatrizMinas[fila][columna]==1){
		cout<<"Perdiste"<<endl;
		Juego=false;
	}
	else{
		system("cls");
		cout<<fila<<"--"<<columna<<endl;
		MostrarPantalla[fila][columna]=Variable(fila,columna,MatrizMinas); 
		
	}

	if (MostrarPantalla[fila][columna]=="0"){
		Arriba(fila,columna,MatrizMinas,MostrarPantalla,true);
		Abajo(fila,columna,MatrizMinas,MostrarPantalla,true);
		//Arriba(fila,columna,MatrizMinas,MostrarPantalla);
		//Abajo(fila,columna,MatrizMinas,MostrarPantalla);
		for (int a=fila-1;a<=fila+1;a++){
		for (int b=columna-1;b<=columna+1;b++){
					MostrarPantalla[a][b]=Variable(a,b,MatrizMinas);
			}
		}
	}
	
	}while(Juego);
	cout<<"Gracias por jugar"<<endl;
	return 0;
}

void Arriba(int filas, int columnas, int minas[][20], string Pantalla[][20],bool bandera){
	bool arriba=true;
	int fila=0;
	for (int a=filas;a>=0&&arriba==true;a--){
		Pantalla[a][columnas]=Variable(a,columnas,minas);
		if (Variable(a,columnas,minas)!="0" || a==0 || a==19 || columnas==0 || columnas==19){
		arriba=false;
		if (Variable(a,columnas,minas)!="0"){
		Bordes(a+1,columnas,minas,Pantalla);
		}
		else {
		Bordes(a,columnas,minas,Pantalla);
		}
		}
		else { if (Pantalla[a][columnas]=="0"){
		//Izquierda(a,columnas-1,minas,Pantalla,false);
		}
		
		}
	}
}
void Abajo(int filas, int columnas, int minas[][20], string Pantalla[][20],bool bandera){
	bool abajo=true;
	int fila;
	for (int a=filas;a<=19&&abajo==true;a++){
		Pantalla[a][columnas]=Variable(a,columnas,minas);
		if (Variable(a,columnas,minas)!="0" || a==0 || a==19 || columnas==0 || columnas==19){
		abajo=false;
		if (Variable(a,columnas,minas)!="0"){
		Bordes(a-1,columnas,minas,Pantalla);
		}
		else {
		Bordes(a,columnas,minas,Pantalla);
		}
		}
		else { if(Pantalla[a][columnas]=="0") {
		//Izquierda(a,columnas-1,minas,Pantalla,false);
		}
		
		}
	}     
}          
void Izquierda(int filasI, int columnasI, int minas[][20], string Pantalla[][20],bool bandera){
	bool izquierda=true;
	int columna;
	for (int b=columnasI;b>=0&&izquierda==true;b--){
		Pantalla[filasI][b]=Variable(filasI,b,minas);
		if (Variable(filasI,b,minas)!="0" || filasI==0 || filasI==19 || b==0 || b==19){
		izquierda=false;
		if (Variable(filasI,b,minas)!="0"){
		
		Bordes(filasI,b+1,minas,Pantalla);
		}
		else {
		Bordes(filasI,b,minas,Pantalla);
		}
		}
		else{ if(Pantalla[filasI][b]=="0"){
			//Abajo(filasI+1,b,minas,Pantalla,false);
			//Arriba(filasI-1,b,minas,Pantalla,false);
			
		}
		}
	}
}
void Bordes(int filas,int columnas, int minas[][20], string Pantalla[][20]){
	if (filas==0 && columnas==0){
		for (int c=filas;c<=filas+1;c++){
		for (int d=columnas;d<=columnas+1;d++){
			Pantalla[c][d]=Variable(c,d,minas);
			}
		}
	}
	else{ if (filas==0) {
		for (int c=filas;c<=filas+1;c++){
		for (int d=columnas-1;d<=columnas+1;d++){
			Pantalla[c][d]=Variable(c,d,minas);
			}
		}
	}
	else { if (filas==0 && columnas==19){
		for (int c=filas;c<=filas+1;c++){
		for (int d=columnas-1;d<=columnas;d++){
			Pantalla[c][d]=Variable(c,d,minas);
			}
		}
	}
	else { if (columnas==19){
		for (int c=filas-1;c<=filas+1;c++){
		for (int d=columnas-1;d<=columnas;d++){
			Pantalla[c][d]=Variable(c,d,minas);
			}
		}
	}
	else { if (filas==19 && columnas==19) {
		for (int c=filas-1;c<=filas;c++){
		for (int d=columnas-1;d<=columnas;d++){
			Pantalla[c][d]=Variable(c,d,minas);
			}
		}
	}
	else { if (filas==19) {
		for (int c=filas-1;c<=filas;c++){
		for (int d=columnas-1;d<=columnas+1;d++){
			Pantalla[c][d]=Variable(c,d,minas);
			}
		}
	}
	else { if (filas==19 && columnas==0) {
		for (int c=filas-1;c<=filas;c++){
		for (int d=columnas;d<=columnas+1;d++){
			Pantalla[c][d]=Variable(c,d,minas);
			}
		}
	}
	else { if (columnas==0) {
		for (int c=filas;c<=filas+1;c++){
		for (int d=columnas;d<=columnas+1;d++){
			Pantalla[c][d]=Variable(c,d,minas);
			}
		}
	}
	else {
		for (int c=filas-1;c<=filas+1;c++){
		for (int d=columnas-1;d<=columnas+1;d++){
			Pantalla[c][d]=Variable(c,d,minas);
			}
		}
	}
	}
	}
	}
	}
	}
	}
	}
}
