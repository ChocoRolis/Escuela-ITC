#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

//Lectura: A T111T G1G E1E P1P D1111D O N1111N 91111119 19990909

string fecha_actual();

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


Personal LEER_MOVIMIENTO(ifstream &entrada);

Personal LEER_PERSONAL( istringstream &iss );



int main()
{
	ifstream entrada_movimientos("movimientos.txt"), 
		 entrada_personal("personal.txt");
	ofstream salida_personal;

	vector< Personal > lista_de_personal;

	
	// Leer datos de personal ya existentes 
	string linea;
	while (getline(entrada_personal, linea))
	{
		istringstream iss(linea);
		Personal datos_personal = LEER_PERSONAL( iss );

		lista_de_personal.push_back( datos_personal );
	}


	// Leer y ejecutar movimientos uno por uno
	char accion;
	while (entrada_movimientos >> accion)
	{
		Personal persona_1 = LEER_MOVIMIENTO( entrada_movimientos );

		
	}

	entrada_movimientos.close();
	entrada_personal.close();
}


	/*		
	cout << persona.trabajador << " " << persona.grupo << " " << persona.empresa << " " << persona.planta << " " << persona.departamento << " " 
		<< persona.clave << " " << persona.nombre << " " << persona.salario << " " << persona.fecha_ingreso << endl;
	*/


// Para llenar automaticamente el campo de 'fecha_ingreso'
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


Personal LEER_MOVIMIENTO(ifstream &entrada)
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


Personal LEER_PERSONAL( istringstream &iss )
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
