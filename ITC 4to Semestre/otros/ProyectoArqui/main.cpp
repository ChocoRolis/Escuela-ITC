///////////////////////////////////////////////////////////////////
/// PROGRAMA: NOP120  
/// AUTOR: Rolando Rivas Davalos 
/// FECHA: 15/05/24 
/// DESCRIPCION: NOP120 es un programa c++ que actualiza 
/// el archivo de Personal, dado otro archivo que especifica
/// movimientos. NOP120 funciona tomando dos archivos de entrada,
/// uno donde se almacena la informacion de cada personal y otro
/// donde se especifican acciones a tomar con esos datos. Las
/// acciones son: Alta, Baja, Cambio. 
/// Cada accion es validada para determinar si es posible 
/// realizarla. Al final el programa guarda los datos modificados  
/// en un nuevo archivo.
///////////////////////////////////////////////////////////////////

/* -------------------------------------------------
 * CONTENIDO:
 * 	1. Funciones 
 *	2. Estructura de Datos usada
 *	3. Main
 *		3a. Uso de archivos
 *		3b. Lectura de Datos
 *		3c. Acciones por movimiento
 *		3d. Reporte 
 *
 *	4. Implementacion de funciones
 * -------------------------------------------------
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// FUNCIONES Y ESTRUCTURA DE DATOS
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


// ....................................................................
// FUNCION fecha_actual() -> string
// Regresa la fecha actual del sistema en forma de yyyymmdd.
// Se utiliza para el valor predeterminado de Personal.fecha_ingreso.
// ....................................................................
string fecha_actual();


// ......................................................................
// ESTRUCTURA Personal
// Guarda toda la informacion que poseen cada personal para idenficarlos.
// Se usara como la estructura de datos que opera el programa.
// ......................................................................
typedef struct personal {
	string trabajador = "000000";
	string grupo = "000";
	string empresa = "000";
	string planta = "000";
	string departamento = "000000";
	string clave = "O";
	string nombre = "     ";
	string salario = "0";
	string fecha_ingreso = fecha_actual();

} Personal;



// .........................................................
// FUNCION Leer_movimiento(ifstream) -> Personal
// Lee 1 movimiento del archivo de movimientos y 
// regresa la informacion guardada en una estructura de
// datos 'Personal'.
// .........................................................
Personal Leer_movimiento(ifstream &entrada);



// .......................................................
// FUNCION Leer_personal(istringstream) -> Personal
// Lee 1 linea de los datos de un personal y regresa la
// informacion en una estructura 'Personal'.
// .......................................................
Personal Leer_personal( istringstream &iss );



// ........................................................................................
// FUNCION Cambiar_datos(Personal1, Personal2) -> void
// Es una funcion tipo 'swap' que transfiere los valores (que no sean vacios o 0)
// de la estructura leida de movimientos a la estructura guardada en el archivo personal.
// Cumple con la accion "Cambio"
// ........................................................................................
void Cambiar_datos( Personal &p_cambios, Personal &p_actual );



// ............................................................................................
// FUNCION Guardar_datos(ostream, Personal) -> void
// Una vez realizada todas la modificaciones solicitadas a los datos de personal se llama a
// esta funcion para escribir estos nuevos datos al nuevo archivo personal.
// ............................................................................................
void Guardar_datos( ofstream &salida, Personal &persona );



// ..........................................................................
// FUNCION Desplegar_reporte(vector_de_pares) -> void
// Imprime el reporte final con todos los movimientos hechos y su tipo
// ..........................................................................
void Desplegar_reporte( vector< pair<string,string> > &movimientos );




//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
// FUNCION MAIN
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//....................................................................................
// 1. Lectura de datos
// 	- Variables ifstream y ofstream abren archivos para lectura
// 	  y escritura respectivamente
//	- Se leen todos los personales y sus datos primero y se guardan
//	  en un arreglo para uso posterior
//	- Se definen variables necesarias para luego crear el reporte
//	- Se leen uno por uno los movimientos 
//		~ En caso de ser alta 'A', se recorre el arreglo en
//		  busqueda de alguna existencia igual a la solicitada.
//		  De no existir, se agrega. Se toma nota para reporte.
//		~ En caso de ser baja 'B', se recorre el arreglo igualmente
//		  buscando si este existe. De ser asi, se elimina y se
//		  toma nota.
//		~ En caso de ser cambio 'C', se investiga en busqueda de
//		  si este existe. De ser asi, se llama a la funcion
//		  'Cambiar_datos()' para actualizar los datos solicitados.
//		  Se toma nota.
//	- Se guardan los datos actualizados en el nuevo archivo con la funcion
//	  'Guardar_datos()'
//	- Se llama finalmente a 'Desplegar_reporte()'
//......................................................................................
int main()
{
	ifstream entrada_movimientos("movimientos.txt"), 
		 entrada_personal("personal.txt");
	ofstream salida_personal("personalActualizado.txt");

	vector< Personal > lista_de_personal;

	
	// Leer datos de personal ya existentes 
	string linea;
	while (getline(entrada_personal, linea))
	{
		istringstream iss(linea);
		Personal datos_personal = Leer_personal( iss );
		lista_de_personal.push_back( datos_personal );
	}


	// Leer y ejecutar movimientos uno por uno
	char accion;
	int size_movimientos = 0;
	vector< pair<string,string> > movimientos;

	while (entrada_movimientos >> accion)
	{
		Personal datos = Leer_movimiento( entrada_movimientos );

		movimientos.push_back({datos.trabajador, ""});

		bool ya_existe = false;

		switch (accion)
		{
			case 'A':
				for (int i = 0; i < lista_de_personal.size(); ++i)
				{
					if ( lista_de_personal[i].trabajador == datos.trabajador )
					{
						ya_existe = true;
						//Reportar Alta invalida
						movimientos[ size_movimientos ].second = "ALTA NO EXITOSA";
						break;
					}
				}
				if (!ya_existe)
				{
					lista_de_personal.push_back( datos );
					movimientos[ size_movimientos ].second = "A L T A";
				}
				
				break;
			
			case 'B':
				for (int i = 0; i < lista_de_personal.size(); ++i)
				{
					if ( lista_de_personal[i].trabajador == datos.trabajador )
					{
						ya_existe = true;
						lista_de_personal.erase(lista_de_personal.begin() + i);

						movimientos[ size_movimientos ].second = "B A J A";
						break;
					}
				}
				if (!ya_existe)
				{
					//Reportar baja invalida
					movimientos[ size_movimientos ].second = "BAJA NO EXITOSA";
				}
				
				break;

			case 'C':
				for (int i = 0; i < lista_de_personal.size(); ++i)
				{
					if ( lista_de_personal[i].trabajador == datos.trabajador )
					{
						ya_existe = true;
						Cambiar_datos( datos, lista_de_personal[i] );
						movimientos[ size_movimientos ].second = "C A M B I O";
						break;
					}
				}
				if (!ya_existe)
				{
					//Reportar Cambio invalido
					movimientos[ size_movimientos ].second = "CAMBIO NO EXITOSO"; }
				
				break;

		}		

		++size_movimientos;
	}

	entrada_movimientos.close();
	entrada_personal.close();

	for (int i = 0; i < lista_de_personal.size(); ++i)
	{
		Guardar_datos( salida_personal, lista_de_personal[i] );
	}


	Desplegar_reporte( movimientos );

	salida_personal.close();
}




//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// IMPLEMENTACION DE FUNCIONES
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

string fecha_actual() 
{
    time_t tiempoActual = time(nullptr);
    
    // Convertir el tiempo en una estructura de tiempo local
    tm* tiempoLocal = localtime(&tiempoActual);
    
    char buffer[80]; // Buffer para almacenar la cadena formateada
    strftime(buffer, 80, "%Y%m%d", tiempoLocal); // Formato YYYY-MM-DD
    string fecha(buffer); // Convertir el buffer a string
    
    return fecha;
}


Personal Leer_movimiento(ifstream &entrada)
{
	Personal nuevo_personal;
	
	string atributo;
	bool continuar_lectura = true;

	while (continuar_lectura)
	{
		entrada >> atributo;

		switch (atributo[ 0 ])
		{
			case 'T':
				nuevo_personal.trabajador = atributo;
				break;
			
			case 'G':
				nuevo_personal.grupo = atributo;
				break;

			case 'E':
				if (atributo.size() > 1)
				{
					nuevo_personal.empresa = atributo;
					break;
				}
				else
				{
					nuevo_personal.clave = atributo;
					break;
				}

			case 'P':
				nuevo_personal.planta = atributo;
				break;

			case 'D':
				nuevo_personal.departamento = atributo;
				break;

			case 'O':
				nuevo_personal.clave = atributo;
				break;

			case 'N':
				nuevo_personal.nombre = atributo;
				break;

			default:
				nuevo_personal.salario = atributo;

				entrada >> atributo;
				if (atributo != "0") { nuevo_personal.fecha_ingreso = atributo; }

				continuar_lectura = false;
		}
	}

	return nuevo_personal;
}


Personal Leer_personal( istringstream &iss )
{
	Personal datos;
	iss >> datos.trabajador
		>> datos.grupo
		>> datos.empresa
		>> datos.planta
		>> datos.departamento
		>> datos.clave
		>> datos.nombre
		>> datos.salario
		>> datos.fecha_ingreso;

	return datos;
}


void Cambiar_datos( Personal &p_cambios, Personal &p_actual )
{
	p_actual.trabajador = p_cambios.trabajador;

	if (p_cambios.grupo[0]         != '0') { p_actual.grupo   	= p_cambios.grupo; 	   }
	if (p_cambios.empresa[0]       != '0') { p_actual.empresa 	= p_cambios.empresa; 	   }
	if (p_cambios.planta[0]        != '0') { p_actual.planta  	= p_cambios.planta; 	   }
	if (p_cambios.departamento[0]  != '0') { p_actual.departamento  = p_cambios.departamento;  }
	if (p_cambios.clave[0]         != '0') { p_actual.clave   	= p_cambios.clave; 	   }
	if (p_cambios.nombre[0]        != '0') { p_actual.nombre   	= p_cambios.nombre; 	   }
	if (p_cambios.salario[0]       != '0') { p_actual.salario       = p_cambios.salario; 	   }
	if (p_cambios.fecha_ingreso[0] != '0') { p_actual.fecha_ingreso = p_cambios.fecha_ingreso; }
}


void Guardar_datos( ofstream &salida, Personal &persona )
{
	salida << persona.trabajador << " " << persona.grupo << " " << persona.empresa <<
		" " << persona.planta << " " << persona.departamento << 
		" " << persona.clave << " " << persona.nombre << 
		" " << persona.salario << " " << persona.fecha_ingreso << endl;
}


void Desplegar_reporte( vector< pair<string,string> > &movimientos )
{
	cout << "12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012\n";
	cout << "00000001		   ACTUALIZACION DEL ARCHIVO DE PERSONAL		  HOJA 0001\n\n";
	cout << "ACME - DIV. BANCOS 		   MOVIMIENTOS EFECTUADOS\n";
	cout << "PERSONAL\n\n";
	cout << "\tTRABAJADOR\tMOVIMIENTO EFECTUADO\n";
	cout << "\t----------\t--------------------\n";
	for (int i = 0; i < movimientos.size(); ++i)
	{
		cout << "\t  " << movimientos[i].first << "\t" << movimientos[i].second << endl;
	}
}
