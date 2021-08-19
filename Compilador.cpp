#include <iostream> //poder usar sintaxis c++ (cout,cin)
#include <regex> //Permite usar la funcion Regex para poder trabajar ER

using namespace std; 
int id=0; //al ingresar una tira se guarda en el vector posicion id;
vector<string> tds;  //Guarda las tiras ya evaluadas

int const val =30; //Cantidad maxima del parse 

//estructura para cada estado.
struct Q{
	string a;
	string b;
	string lamda;
};

//estructura para cada regla
struct Regla{
	string origen;
	string terminal;
	string noterminal;
	int numero;
	
};

//estructura de derivacion
struct pala{
	string terminal;
	string noterminal;
	int parse[val];
};


Regla A[10],B[10],C[10],D[10],E[10],F[10],G[10],H[10];//declarar reglas p
void TAnalisLexico(string ); 
void TLP();
void mostrarTDS();
void TDS();
int Menu();
void Automata();
void asignarReglas();
void mostrarREGLAS();
void AnalisisSintactico(string rna);
int main ( int argc, char *argv[] )
{
	
	int op; //opcion de menu
		string rna ;//tira ingresada por el usuario
	const std::regex re( "b*ab(ab|ba)*(aa|bb)*(a|b)" ) ; //obtenemos la ER
	
	do{
		Automata();
		asignarReglas();
		
		op = Menu();
		if(op==1){
			
			//pedimos que el usr ingrese una tira. 
			cout<< "Ingrese una tira: ";
			cin >> rna;
			cout << "Tira: " << rna << '\n' ;
			
			//comparamos si la tira pertenece a la ER
			if( regex_match( rna,re ) )
			{
				//si cumple daremos comienzo al analisis Lexico y Sintactico
				
				cout<<endl;
				cout<<"------------------------------------------------------\n";
				TAnalisLexico(rna);
				cout<<endl;
				cout<<"------------------------------------------------------\n";
				TLP();
				
				cout<<endl;
				cout<<endl;
				cout<<"------------------------------------------------------\n";
				TDS();
				id++;
				cout << endl;
				AnalisisSintactico(rna);
			}
			else{
				//de lo contrario indicamos al usr que la tira no pertenece
				cout << "No pertenece" ;
			}
		}else{
			if(op!=2){
				cout << "\nOpcion Incorrecta\n";
			}
		}
		cout <<endl;
		system("PAUSE");
		system("cls");
	}while(op!=2);
	
}

//proceso para realizar el analisis lexcio
void TAnalisLexico(string rna){
	
	tds.push_back(rna);//añadimos palabra a la tabla de simbolos
	cout<<"Token \t Lexema \t Patron"<<endl;
	cout<<"----- \t ------ \t ------"<<endl;
	cout<<"Id    \t ";
	
	//mostrar TLP
	for(int a=0; a<= id; a++){
		if(a>0){
			cout<< ", ";
		}
		cout<<tds[a];
	}
	
	cout<<"\t b*ab(ab|ba)*(aa|bb)*(a|b)"<<endl<<endl;
}

//proceso para la tabla de simbolos
void TDS(){	
	//mostramos cada simbolo de la tabla
	cout<<" TDS	"<<endl<<" ----	"<<endl;
	for(int a=0; a<= id; a++){
		cout<<a<<" | "<<tds[a]<<endl;
	}
}

//Inicializador de TDS
void TLP(){
	cout<<"Secuencia de Tokens\n";
	mostrarTDS();
}

//proceso para mostrar la secuencia de tokens
void mostrarTDS(){
	for(int i = 0; i<=id;i++){
		cout << "<ID,"<<i<<">\n";
	}
}

//proceso para mostrar el menu de opciones (ingresar otra ER o salir)
int Menu(){
	cout <<"...::: Menu :::...\n";
	cout<< "1.- Agregar Tira \n";
	cout<< "2.- Salir \n";
	cout<< "Ingrese una opcion: ";
	int op;
	cin >>op;
	return op;
}

//asigna y muestra los elementos del automata
void Automata(){
	Q A,B,C,D,E,F,G,H,I;
	A.a="B";
	A.b="A";
	A.lamda="-";
	
	
	B.a="-";
	B.b="C";
	B.lamda="-";
	
	C.a="E";
	C.b="D";
	C.lamda="F";
	
	D.a="C";
	D.b="-";
	D.lamda="-";
	
	E.a="-";
	E.b="C";
	E.lamda="-";
	
	F.a="G,I";
	F.b="H,I";
	F.lamda="-";
	
	G.a="F";
	G.b="-";
	G.lamda="-";
	
	H.a="-";
	H.b="F";
	H.lamda="-";
	
	I.a="-";
	I.b="-";
	I.lamda="-";
	cout << "Expresión Regular: b*ab(ab|ba)*(aa|bb)*(a|b)\n\n";
	cout << "AUTOMATA FINITO\n";
	cout << "AF = {E,Q,f,q0,F}\n";
	cout << "E = {a,b}\n";
	cout << "Q = {A, B, C, D, E, F, G, H, I}\n";
	cout << "f:\n";
	cout<<"	Q°	a	b	Lamda\n" ;
	cout<<"	A	"<<A.a<<"	"<<A.b<<"	"<<A.lamda<<"\n" ;
	cout<<"	B	"<<B.a<<"	"<<B.b<<"	"<<B.lamda<<"\n" ;
	cout<<"	C	"<<C.a<<"	"<<C.b<<"	"<<C.lamda<<"\n" ;
	cout<<"	D	"<<D.a<<"	"<<D.b<<"	"<<D.lamda<<"\n" ;
	cout<<"	E	"<<E.a<<"	"<<E.b<<"	"<<E.lamda<<"\n" ;
	cout<<"	F	"<<F.a<<"	"<<F.b<<"	"<<F.lamda<<"\n" ;
	cout<<"	G	"<<G.a<<"	"<<G.b<<"	"<<G.lamda<<"\n" ;
	cout<<"	H	"<<H.a<<"	"<<H.b<<"	"<<H.lamda<<"\n" ;
	cout<<"	I	"<<I.a<<"	"<<I.b<<"	"<<I.lamda<<"\n" ;
	cout << "\nq0 = A\n";
	cout << "\nF = {F}\n";
	cout << endl;
}

//Asignacion de reglas P
void asignarReglas(){
	A[0].origen="A";
	A[0].terminal="a";
	A[0].noterminal="B";
	A[0].numero=1;
	
	A[1].origen="A";
	A[1].terminal="b";
	A[1].noterminal="A";
	A[1].numero=2;
	
	B[0].origen="B";
	B[0].terminal="b";
	B[0].noterminal="C";
	B[0].numero=3;
	
	C[0].origen="C";
	C[0].terminal="b";
	C[0].noterminal="D";
	C[0].numero=4;
	
	C[1].origen="C";
	C[1].terminal="a";
	C[1].noterminal="E";
	C[1].numero=5;
	
	
	C[2].origen="C";
	C[2].terminal="";
	C[2].noterminal="F";
	C[2].numero=6;
	
	
	D[0].origen="D";
	D[0].terminal="a";
	D[0].noterminal="C";
	D[0].numero=7;
	
	
	E[0].origen="E";
	E[0].terminal="b";
	E[0].noterminal="C";
	E[0].numero=8;
	
	
	F[0].origen="F";
	F[0].terminal="a";
	F[0].noterminal="G";
	F[0].numero=9;
	
	
	F[1].origen="F";
	F[1].terminal="b";
	F[1].noterminal="H";
	F[1].numero=10;
	
	
	F[2].origen="F";
	F[2].terminal="a";
	F[2].noterminal="";
	F[2].numero=11;
	
	
	F[3].origen="F";
	F[3].terminal="b";
	F[3].noterminal="";
	F[3].numero=12;
	
	G[0].origen="G";
	G[0].terminal="a";
	G[0].noterminal="F";
	G[0].numero=13;
	
	
	H[0].origen="H";
	H[0].terminal="b";
	H[0].noterminal="F";
	H[0].numero=14;
	mostrarREGLAS();
}

//mostramos reglas P
void mostrarREGLAS(){
	cout << "REGLAS\n";
	cout<<"P = {";
	for(int i=0; i<2; i++){
		cout<<A[i].origen<< " -> " <<A[i].terminal<<A[i].noterminal<<"("<<A[i].numero<<"); \n";
	}
	
	cout<<B[0].origen<< " -> " <<B[0].terminal<<B[0].noterminal<<"("<<B[0].numero<<"); \n";
	for(int i=0; i<3; i++){
		cout<<C[i].origen<< " -> " <<C[i].terminal<<C[i].noterminal<<"("<<C[i].numero<<"); \n";
	}
	cout<<D[0].origen<< " -> " <<D[0].terminal<<D[0].noterminal<<"("<<D[0].numero<<"); \n";
	cout<<E[0].origen<< " -> " <<E[0].terminal<<E[0].noterminal<<"("<<E[0].numero<<"); \n";
	for(int i=0; i<4; i++){
		cout<<F[i].origen<< " -> " <<F[i].terminal<<F[i].noterminal<<"("<<F[i].numero<<"); \n";
	}
	cout<<G[0].origen<< " -> " <<G[0].terminal<<G[0].noterminal<<"("<<G[0].numero<<"); \n";
	cout<<H[0].origen<< " -> " <<H[0].terminal<<H[0].noterminal<<"("<<H[0].numero<<") } \n \n";
}


// Funcion de Análisis Sintáctico
void AnalisisSintactico(string rna){
	cout<<"Analisis Sintactico.\n";
	pala palabra; //declaramos la palabra que se va a ir derivando
	pala aux[30]; //declaramos un vector auxiliar que nos servira para hacer un retroceso en caso de ser necesario
	
	//El auxiliar comenzara por el axioma (A)
	aux[0].terminal="";
	aux[0].noterminal="A";
	
	int indice=0;
	int indiceParse=0;
	
	//Sirve para comparar si algun string esta vacio
	string  vacio ="";
	
	//La palabra auxiliar comenzara por el axioma (A)
	palabra.terminal="";
	palabra.noterminal="A";
	
	//Servira para saber si es que ya se probaron todas las reglas
	//del no terminal, o si todavia continua
	bool continuar=false;
	
	//Llenamos el parse con 0
	for(int i=0;i<30;i++){
		palabra.parse[i]=0;
	}
	//Se repetira todo el proceso de derivacion
	//mientras la palabra sea diferente a la tira
	//y si la palabra todavia tiene no terminales
	while(vacio.compare(palabra.noterminal) != 0 && rna.compare(palabra.terminal)!=0){
		
		
		//Compara el noterminal de la palabra para saber que tipo de reglas usar
		switch(palabra.noterminal[0]){
		//En cada "case" se deriva la palabra y en caso de no quedar reglas 
		//indica que se debe retroceder
		case 'A':
		{
			
			int indiceRegla=0;
			
			for(int i=0;i<2;i++){
				if(palabra.parse[indiceParse]+1==A[i].numero){
					indiceRegla=i;
				}
			}
			
			
			palabra.terminal=palabra.terminal + A[indiceRegla].terminal;
			palabra.noterminal=A[indiceRegla].noterminal;
			palabra.parse[indiceParse]=A[indiceRegla].numero;
			indiceParse++;
			aux[indiceParse].terminal=palabra.terminal;
			aux[indiceParse].noterminal=palabra.noterminal;
			continuar=true;
			
			break;
		}
		case 'B':
		{
			int indiceRegla=0;
			if(palabra.parse[indiceParse]==0){
				palabra.terminal=palabra.terminal + B[indiceRegla].terminal;
				palabra.noterminal=B[indiceRegla].noterminal;
				palabra.parse[indiceParse]=B[indiceRegla].numero;
				indiceParse++;
				aux[indiceParse].terminal=palabra.terminal;
				aux[indiceParse].noterminal=palabra.noterminal;
				continuar=true;
			}else{
				palabra.parse[indiceParse]= 0;
				indiceParse--;
				continuar=false;
			}
			break;
		}
		case 'C':
		{
			int indiceRegla=0;
			if(palabra.parse[indiceParse]==0){
				palabra.terminal=palabra.terminal + C[indiceRegla].terminal;
				palabra.noterminal=C[indiceRegla].noterminal;
				palabra.parse[indiceParse]=C[indiceRegla].numero;
				indiceParse++;
				aux[indiceParse].terminal=palabra.terminal;
				aux[indiceParse].noterminal=palabra.noterminal;
				continuar=true;
			}else{
				for(int i=0;i<3;i++){
					if(palabra.parse[indiceParse]+1==C[i].numero){
						indiceRegla=i;
					}
				}
				if(indiceRegla!=0){
					palabra.terminal=palabra.terminal + C[indiceRegla].terminal;
					palabra.noterminal=C[indiceRegla].noterminal;
					palabra.parse[indiceParse]=C[indiceRegla].numero;
					indiceParse++;
					aux[indiceParse].terminal=palabra.terminal;
					aux[indiceParse].noterminal=palabra.noterminal;
					continuar=true;
				}else{
					palabra.parse[indiceParse]= 0;
					indiceParse--;
					continuar=false;
				}
				
			}
			break;
		}
		
		
		case 'D':
		{
			int indiceRegla=0;
			if(palabra.parse[indiceParse]==0){
				palabra.terminal=palabra.terminal + D[indiceRegla].terminal;
				palabra.noterminal=D[indiceRegla].noterminal;
				palabra.parse[indiceParse]=D[indiceRegla].numero;
				indiceParse++;
				aux[indiceParse].terminal=palabra.terminal;
				aux[indiceParse].noterminal=palabra.noterminal;
				continuar=true;
			}else{
				palabra.parse[indiceParse]= 0;
				continuar=false;
			}
			break;
		}
		
		case 'E':
		{
			int indiceRegla=0;
			if(palabra.parse[indiceParse]==0){
				palabra.terminal=palabra.terminal + E[indiceRegla].terminal;
				palabra.noterminal=E[indiceRegla].noterminal;
				palabra.parse[indiceParse]=E[indiceRegla].numero;
				indiceParse++;
				aux[indiceParse].terminal=palabra.terminal;
				aux[indiceParse].noterminal=palabra.noterminal;
				continuar=true;
			}else{
				palabra.parse[indiceParse]= 0;
				indiceParse--;
				continuar=false;
			}
			break;
		}
		
		
		case 'F':
		{
			int indiceRegla=0;
			if(palabra.parse[indiceParse]==0){
				palabra.terminal=palabra.terminal + F[indiceRegla].terminal;
				palabra.noterminal=F[indiceRegla].noterminal;
				palabra.parse[indiceParse]=F[indiceRegla].numero;
				indiceParse++;
				aux[indiceParse].terminal=palabra.terminal;
				aux[indiceParse].noterminal=palabra.noterminal;
				continuar=true;
			}else{
				for(int i=0;i<4;i++){
					if(palabra.parse[indiceParse]+1==F[i].numero){
						indiceRegla=i;
					}
				}
				if(indiceRegla!=0){
					palabra.terminal=palabra.terminal + F[indiceRegla].terminal;
					palabra.noterminal=F[indiceRegla].noterminal;
					palabra.parse[indiceParse]=F[indiceRegla].numero;
					indiceParse++;
					aux[indiceParse].terminal=palabra.terminal;
					aux[indiceParse].noterminal=palabra.noterminal;
					continuar=true;
				}else{
					palabra.parse[indiceParse]= 0;
					indiceParse--;
					continuar=false;
				}
				
			}
			break;
		}
		
		case 'G':
		{
			int indiceRegla=0;
			if(palabra.parse[indiceParse]==0){
				palabra.terminal=palabra.terminal + G[indiceRegla].terminal;
				palabra.noterminal=G[indiceRegla].noterminal;
				palabra.parse[indiceParse]=G[indiceRegla].numero;
				indiceParse++;
				aux[indiceParse].terminal=palabra.terminal;
				aux[indiceParse].noterminal=palabra.noterminal;
				continuar=true;
			}else{
				palabra.parse[indiceParse]= 0;
				indiceParse--;
				continuar=false;
			}
			break;
		}
		case 'H':
		{
			int indiceRegla=0;
			if(palabra.parse[indiceParse]==0){
				palabra.terminal=palabra.terminal + H[indiceRegla].terminal;
				palabra.noterminal=H[indiceRegla].noterminal;
				palabra.parse[indiceParse]=H[indiceRegla].numero;
				indiceParse++;
				aux[indiceParse].terminal=palabra.terminal;
				aux[indiceParse].noterminal=palabra.noterminal;
				continuar=true;
			}else{
				palabra.parse[indiceParse]= 0;
				indiceParse--;
				continuar=false;
			}
			break;
		}
		default:
			break;
		}
		indice = palabra.terminal.size() -1;
		if(continuar){
			if(palabra.terminal.compare(aux[indiceParse-1].terminal)!=0){
				if(rna.size() == palabra.terminal.size() && palabra.noterminal.compare(vacio)!=0){
					indiceParse--;
					palabra.terminal = aux[indiceParse].terminal;
					palabra.noterminal= aux[indiceParse].noterminal;
				}else{
					if(palabra.terminal[indice]!=rna[indice]){
						indiceParse--;
						palabra.terminal = aux[indiceParse].terminal;
						palabra.noterminal= aux[indiceParse].noterminal;
					}
					
				}
				
			}
			
		}else{
			
			palabra.terminal = aux[indiceParse].terminal;
			palabra.noterminal= aux[indiceParse].noterminal;
		}
		
		cout << palabra.terminal <<"-"<< palabra.noterminal<<"-" <<"Parse: ";
		for(int i=0;i<=indiceParse;i++){
			if(palabra.parse[i]==0){
				break;
			}
			cout << palabra.parse[i]<<",";
		}
		cout <<endl;
		cout <<endl;
		
	}
	
	int index = 0;
	cout << "Parse Izquierdo: ";
	while(palabra.parse[index]!=0){
		cout << palabra.parse[index]<<", ";
		index++;
	}
	
}


