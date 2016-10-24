#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{							// David Bolaños y Sebastian Aguila
	int opcion = 4;
	char oper, suma = '+', resta = '-', multiplicacion = '*', division = '/', factorial = '!', raiz = 'r', potencia = '^', clear = 'c', finalizar = 'x';
	bool cerrar = false;

	while (cerrar == false){
		cout << "----------------" << endl
			<< "1. CALCULADORA" << endl
			<< "2. CONFIGURACION" << endl 
			<< "3. TERMINAR" << endl
			<< "----------------" << endl
			<< "Opcion: ";
		cin >> opcion;

		switch (opcion){
		case 0: break;							// No hacer nada en este caso

		case 1: {								// Abrir calculadora
			cin.sync();
			long double op1 = 0, op2;
			string tipoError;
			bool error = false;
			char p, operacion;

			do{
				cout << "Introduce una operacion aritmetica (" << finalizar << " para terminar):" << endl;
				cout << suma << ":suma  " << resta <<  ":resta  " << multiplicacion << ":mult.  " << division << ":div.  "  << factorial << ":fact.  " << raiz << ":raiz  " << potencia << ":potencia  " << clear << ":clear  " << endl;
				cout << ">>> ";
				p = cin.peek();

				if(p >= '0' && p <= '9')
					cin >> op1;

				do{
					cin.get (operacion);
					if(operacion != '\n')
					{
						error = false;

						if (operacion == suma){
							cin >> op2; 
							op1 = op1 + op2;
						}

						else if (operacion == resta){ 
							cin >> op2; 
							op1 = op1 - op2;
						}

						else if (operacion == multiplicacion){
							cin >> op2; 
							op1 = op1 * op2;
						}

						else if (operacion == division){
							cin >> op2; 						
							if (op2 != 0){
								op1 = op1 / op2;
							}
							else{
								tipoError = "Error!, imposible dividir entre 0!";
								error = true;
							}
						}

						else if (operacion == raiz){
							if (op1 >= 0)
								op1 = sqrt(op1);
							else{
								tipoError = "Error! numero de la raiz no positivo!";
								error = true;
							}
						}

						else if (operacion == potencia){ 
							cin >> op2;

							if (floor(op2) == op2){
								double aux = 1;
								for(int i = 0; i < op2; i++){
									aux = aux * op1;
								}

								if (op2 > 0)
									op1 = aux;

								else if(op2 == 0)
									op1 = 1;

								else
									op1 = 1/aux;
							}

							else{
								tipoError = "Error! Numero del exponente no entero!";							
								error = true;
							}
						}

						else if (operacion == factorial){
							if(op1 > 0){
								if((floor(op1)) == op1)
								{
									int fact= 1;
									for (double i = op1; i > 1; i--)
									{
										fact *= i;
									}
									op1 = (double)fact;
								}

								else{
									tipoError = "Error!, Numero del factorial no entero!"; 
									error = true; 
								}
							}
							else{
								tipoError = "Error!, Numero del factorial no positivo!";
								error = true; 
							}
						}
						else if (operacion == clear)
							op1 = 0;

						else if (operacion == finalizar)
							error = false;

						else 
						{tipoError = "Error!, Expresion incorrecta!";
						error = true;
						}

					}

				} while(operacion != '\n' );

				if (error == true){
					cout << tipoError << endl << endl;
					op1 = 0;
				}

				else
					cout << ">>> " << op1 << endl << endl;

			} while(p != finalizar); break;
				}
		case 2: {								//Configuracion
			cin.sync();

			cout << "Caracter para la suma (Intro para mantener " << suma << ")" << endl;
			oper = cin.peek();
			if (oper != '\n')
				suma = oper;
			cin.sync();

			cout << "Caracter para la resta (Intro para mantener " << resta << ")" << endl;
			oper = cin.peek();
			if (oper != '\n')
				resta = oper;
			cin.sync();

			cout << "Caracter para la multiplicacion (Intro para mantener " << multiplicacion << ")" << endl;
			oper = cin.peek();
			if (oper != '\n')
				multiplicacion = oper;
			cin.sync(); 

			cout << "Caracter para la division (Intro para mantener " << division << ")" << endl;
			oper = cin.peek();
			if (oper != '\n')
				division = oper;
			cin.sync(); 

			cout << "Caracter para la potencia (Intro para mantener " << potencia << ")" << endl;
			oper = cin.peek();
			if (oper != '\n')
				potencia = oper;
			cin.sync(); 

			cout << "Caracter para la raiz (Intro para mantener " << raiz << ")" << endl;
			oper = cin.peek();
			if (oper != '\n')
				raiz = oper;
			cin.sync(); 

			cout << "Caracter para la factorial (Intro para mantener " << factorial << ")" << endl;
			oper = cin.peek();
			if (oper != '\n')
				factorial = oper;
			cin.sync();

			cout << "Caracter para terminar (Intro para mantener " << finalizar << ")" << endl;
			oper = cin.peek();
			if (oper != '\n')
				finalizar = oper; 
			cin.sync();

			cout << "Caracter para poner a 0 (Intro para mantener " << clear << ")" << endl;
			oper = cin.peek();
			if (oper != '\n')
				clear = oper;
			cin.sync();

				} break;

		case 3: // Salir del programa
			cerrar = true; 

		}
	}
	cout << endl << " Hecho por David Bolanios y Sebastian Aguila, Grupo 5 de FP" << endl << "" << endl;
	system("pause");
	return 0;
}