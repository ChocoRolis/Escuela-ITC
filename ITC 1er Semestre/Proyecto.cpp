/*************************************************************
**************************************************************
- Nombre: Jorge Enrique Serangelli Andrade
- Fecha: 19 / Noviembre / 2022
- Clase: Programacion y Algoritmos
- Proyecto Final: Inventario para taller de Bicicleta
- Problema: No sabe cuando vender / ganancias y productos 
- disponibles.
- Solucion: Organizar el inventario de una manera eficiente,
- dar conocimiento de las ventas y resurtir el inventario.
**************************************************************
**************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void pausa();
bool validacion(string entrada);
int convertir_str_to_int(string entrada);

int flag = 0;
int cont_prod = 3;
const int num = 100;
int cantidad[num];
double descuento = 1.0;
bool flag_descuento = false;
double descuento2 = 1.0;
bool flag_descuento2 = false;
bool checkUser1 = true;

/*
- Nombre: pausa()
- Funcion: Cada vez que se termine un proceso se espera que el 
usuario oprima una tecla para continuar.
- @Entrada: NA
- @Salida:  NA
*/
void pausa() {
    cout << "\nPulsa una tecla para continuar...";
    getwchar();
    getwchar();
}

/*
- Nombre: validacion()
- Funcion: Valida el input del usuario sea un numero. Los numeros en
ASCII comprenden del 48 al 57 por lo tanto todo lo que este fuera de
ese rango no es numero.
- @Entrada: string (input del usuario)
- @Salida:  bool (determina si el input fue o no un numero)
*/
bool validacion(string entrada) {
    bool checador = true;
    int entero_prueba;
    for (int i = 0; i < entrada.size(); i++) {
        entero_prueba = (int) entrada[i];
        if (entero_prueba <= 47 || entero_prueba >= 58) {
            cout << "no es un numero" << endl;
            checador = false;
            //return checador;
            break;
        }
    }

    return checador;

}

/*
-Nombre: convertir_str_to_int()
-Funcion: Convertir el input tipo string en un numero entero.
- @Entrada: string (input del usuario)
- @Salida: Entero 
*/

int convertir_str_to_int(string entrada) {
    int entero_prueba;
    int tamano = entrada.size();
    int num_final = 0;
    for (int i = 0; i < entrada.size(); i++) {
        entero_prueba = (int) entrada[i] - 48;
        for (int j = tamano; j != 1; j--) {
            entero_prueba = entero_prueba * 10;
        }
        tamano--;
        num_final = num_final + entero_prueba;
    }

    return num_final;
}

/*
-Nombre: eliminarElementoNom()
-Funcion: Reduce el tamaño del arreglo y mueve todos los elementos en el espacio por delante 
- @Entrada: Entero (Input del usuario)
- @Salida: Entero
*/
int eliminarElementoNom(string arr[], int arr2[], int arr3[], int arr4[], int n, string x) {
    
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x) {
            flag = i;
            break;
        }

    
    if (i < n) {
        
        n = n - 1;
        for (int j = i; j < n; j++) {
            arr[j] = arr[j + 1];
            arr2[j] = arr2[j + 1];
            arr3[j] = arr3[j + 1];
            arr4[j] = arr4[j + 1];
        }
    }

    cont_prod = n;

    return n;
}

/*int comprarProductos(string arr[], int arr2[], int arr3[], int arr4[], int n, string x)
{
int i;
for (i=0;i<n; i++)
    if (arr[i] == x) {
        flag = i;
        break;
    }
if (i<n)
{

}
    
}*/

/*
-Nombre: modificarCantidad()
-Funcion: Reducir las existencias de un producto
- @Entrada: Entero (inputCantidad)
- @Salida: NA

*/

void modificarCantidad(string arr[], string nom, int cant, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == nom) {
            cantidad[i] -= cant;
        }
    }
}
/*
-Nombre: validacionCantidadesaVender
-Funcion: Valida que la cantidad ingresada de un producto por el cliente sea menor a la cantidad ofrecida por el inventario
- @Entrada: Entero (inputCantidad)
- @Salida: bool (determina si el inputCantidad fue menor a la cantidad del inventario)
*/
bool validacionCantidadesaVender (int inputCantidad, int arrCantidad[], string inputUsuario, string arr[]) {
    bool validacion = true;
    int n;
    for (int i = 0; i < num; i++) {
        if (inputUsuario == arr[i]) {
           n = arrCantidad[i]-inputCantidad;
           if (n<0) {
            validacion = false;
            break;
           }
           break;
        }
    }
    return validacion;
}
/*
- Nombre: validacionProducto()
- Funcion: Valida que el nombre ingresado se encuentre en el inventario
- @Entrada: string (input nombre del producto)
- @Salida: bool (Verifica que si existe en el inventario)
*/

bool validacionProducto(string inputUsuario, string arr[]) {
    bool validador = true;
    for (int i = 0; i < num; i++) {
        if (inputUsuario == arr[i]) {
            break;
        }
        if (i == num - 1) {
            validador = false;
        }
    }

    return validador;
}

/*
- Nombre: validacionAnadir
- Funcion: Valida si no existe un producto, para poder anadirle al inventario
- @Entrada: string (input nombre del producto)
- @Salida: bool (Verifica si no existe en el inventario)

*/

bool validacionAnadir(string inputNombre, string arr[]) {
    bool validador = true;
    for (int i = 0; i < num; i++) {
        if (inputNombre == arr[i]) {
            validador = false;
            break;
        }
    }
    return validador;
}

int main() {
    string usuario = "Bici", contrasena = "Bici2022", c = "", u = "", usuario2 = "Bici2", contrasena2 = "BiciUsuario", contrasena3 = "BiciUsuario2", usuario3 = "Bici3";
    bool user = false;
    bool con = false;
    bool con2 = false;
    bool user2 = false;
    bool user3 = false;
    bool con3 = false;


    

    string nombre[num] = " ";

    int preciocomprado[num];
    int preciovender[num];
    nombre[0] = "Bici";
    nombre[1] = "Llanta";
    nombre[2] = "Pedal";
    cantidad[0] = 12;
    cantidad[1] = 22;
    cantidad[2] = 30;
    preciocomprado[0] = 100;
    preciocomprado[1] = 30;
    preciocomprado[2] = 15;
    preciovender[0] = 200;
    preciovender[1] = 60;
    preciovender[2] = 30;


    bool bandera = true;
    bool bandera2 = true;
    bool bandera3 = true;
    bool s = false;
    bool inventario = false;
    char tecla;
    string nom = "";
    int i;
    char o, p, e, z;
    string str_c;
    string str_y;
    string str_r;
    string prueba = "";
    int n = 0;

    bool test = true;
    bool test2 = true;
    string nom_compra = "";
    string nom_compra2 = "";
    string nombre_copia[num];
    string nn;
    string str_respuesta = "0";
    string str_respuesta2 = "0";
    int respuesta = 0;
    int respuesta2 = 0;
    int cont = 0;
    int cont2 = 0;
    string arr_compra[num] = "";
    string arr_compra2[num] = "";
    int arr_cantcompra[num];
    int arr_cantcompra2[num];
    arr_cantcompra[0] = 0;
    arr_cantcompra2[0] = 0;
    string str_cant_compra = "0";
    string str_cant_compra2 = "0";
    int cant_compra = 0;
    int cant_compra2 = 0;
    int total_recibo = 0;
    int total_recibofinal = 0;
    int total_recibo2 = 0;
    int total_recibofinal2 = 0;
    int arr_cantventa[num];
    int arr_cantventa2[num];
    string t = "";
    int costo_produccion;
    int a;
    int a2;
    bool comprarealizada = false;
    bool comprarealizada2 = false;

    // Loop principal del menu.
    while (s != true) {
        cout << " Ingresar sistema (1) " << endl;
        cout << " Salir            (2) " << endl;
        cin >> z;

        // Se validan Usuario y Password y tambien para salir del sistema.
        switch (z) {

        case '1':
            cout << "Acceso al sistema" << endl;
            user = false;
            user2= false;
            user3= false;
            con = false;
            con2 = false;
            con3 = false;
            while (user != true && user2 != true && user3 != true) {
                cout << " Ingrese su usuario " << endl;
                cin >> u;
                if (u == usuario) {
                    user = true;
                    user2 = false;
                    user3 = false;
                    while ( con != true){
                        cout << "Ingrese contrasena" << endl;
                        cin >> c;
                         if (c == contrasena) {
                            con = true;
                            con2= false;
                            con3 = false;
                            bandera = false;
                        }
                        else{
                            cout << "Ingreso mal su contrasena" << endl;
                        }
                    }
                } else if (u == usuario2) {
                    user2 = true;
                    user = false;
                    user3 = false;
                    while ( con2 != true){
                        cout << "Ingrese contrasena" << endl;
                        cin >> c;
                         if (c == contrasena2) {
                            con2 = true;
                            con = false;
                            con3 = false;
                            bandera2 = false;
                            
                        }
                        else{
                            cout << "Ingreso mal su contrasena" << endl;
                        }
                }
            } else if (u == usuario3) {
                user3 = true;
                user = false;
                user2 = false;
                while (con3 != true) {
                    cout << "Ingrese contrasena" << endl;
                    cin >> c;
                    if (c == contrasena3) {
                        con3 = true;
                        con = false;
                        con2 = false;
                        bandera3 = false;
                    }
                    else {
                        cout << "Ingreso mal su contrasena" << endl;
                    }
                }
            }
            else{
                cout << "Ingreso mal su Usuario" << endl;
            }
            }
            break;

            

            case '2':
                cout << "Vuelva pronto" << endl;
                s = true;
                break;
            default:
                system("cls");
                cout << "Opcion no valida" << endl;
                pausa();
                break;
        }

        // Si el usuario y contrasena ingresado son el de la empresa (Usuario: Bici y Contrasena: 2022)
        // entonces se despliega el menu de la empresa con sus respectivas
        // funciones.
        if (user == true && con == true) {
            while (bandera != true) {
                user = true;
                con = true;

                cout << "------Empresa-------" << endl;
                cout << "---Menu principal---" << endl;
                cout << "--------------------" << endl;
                cout << "Inventario      (1)" << endl;
                cout << "Ganancias       (2)" << endl;
                cout << "Cliente         (3)" << endl;
                cout << "Proyecciones    (4)" << endl;
                cout << "Salir           (5)" << endl;
                cout << "------------------" << endl;
                cout << "Que quiere realizar?" << endl;
                cin >> o;

                
                // Se valida el inventario, ganancias, descuentos al cliente, 
                // proyecciones y salir (regresa al sistema)
                

                switch (o) {

                case '1': {

                    do {
                        cout << "------------------------------" << endl;
                        cout << "----------Inventario----------" << endl;
                        cout << "------------------------------" << endl;
                        cout << " Ver productos existentes (1) " << endl;
                        cout << " Anadir producto          (2) " << endl;
                        cout << " Eliminar producto        (3) " << endl;
                        cout << " Regresar a menu principal (4)" << endl;
                        cout << "------------------------------" << endl;
                        cout << "----- Que quiere realizar?----" << endl;
                        cin >> p;

                        // Se valida ver productos existente, anadir producto, 
                        // eliminar producto y regresar a menu principal

                        switch (p) {
                        
                        
                        case '1':
                            // Permite visualizar el inventario 
                            cout << "Nombre" << "\t\t\t" << "Cantidad" << "\t\t" << "Precio comprado" << "\t\t" << "Precio a vender" << endl;
                            for (int i = 0; i < cont_prod; i++) {
                                cout << nombre[i] << "\t\t\t" << cantidad[i] << "\t\t\t" << preciocomprado[i] << "\t\t\t" << preciovender[i] << "\t\t" <<  endl;
                            }

                            pausa();
                            break;
                        case '2':
                           
                            cout << "Nombre" << "\t\t\t" << "Cantidad" << "\t\t" << "Precio comprado" << "\t\t" << "Precio a vender" << endl;
                            for (int i = 0; i < cont_prod; i++) {
                                cout << nombre[i] << "\t\t\t" << cantidad[i] << "\t\t\t" << preciocomprado[i] << "\t\t\t" << preciovender[i] << "\t\t"  << endl;
                            }

                            // Anade nuevos productos al inventario 
                            bool anadir;
                            anadir = false;

                            do {
                            cout << " Anadir nombre de producto " << endl;
                            cin >> nom;
                            anadir = validacionAnadir(nom, nombre);
                            if (anadir == true) {
                            nombre[cont_prod] = nom;
                            cout << " Anadir cantidad " << endl;

                            int int_c;
                            do {
                                cin >> str_c;
                            } while (!validacion(str_c));
                            int_c = convertir_str_to_int(str_c);
                            cantidad[cont_prod] = int_c;
                            cout << " Anadir precio comprado " << endl;

                            int int_y;
                            do {
                                cin >> str_y;
                            } while (!validacion(str_y));
                            int_y = convertir_str_to_int(str_y);
                            preciocomprado[cont_prod] = int_y;
                            cout << " Anadir precio a vender " << endl;

                            int int_r;
                            do {
                                cin >> str_r;
                            } while (!validacion(str_r));
                            int_r = convertir_str_to_int(str_r);
                            preciovender[cont_prod] = int_r;

                            

                            cont_prod++;

                            } else {
                                cout << " El nombre que usted ingreso, ya se encuentra disponible en el inventario " << endl;
                            }
                            } while (anadir == false);
                            pausa();
                            break;
                        case '3':
                            cout << "Nombre" << "\t\t\t" << "Cantidad" << "\t\t" << "Precio comprado" << "\t\t" << "Precio a vender" << endl;
                            for (int i = 0; i < cont_prod; i++) {
                                cout << nombre[i] << "\t\t\t" << cantidad[i] << "\t\t\t" << preciocomprado[i] << "\t\t\t" << preciovender[i] << "\t\t" << endl;
                            }
                            // Da de baja productos existentes en el inventario
                            cout << " Que producto existente desea dar de baja? " << endl;
                            
                            bool validador;
                            do {
                                cin >> prueba;

                                validador = validacionProducto(prueba, nombre);
                                if (validador == true) {
                                    n = eliminarElementoNom(nombre, cantidad, preciocomprado, preciovender, cont_prod, prueba);
                                } else {
                                    cout << "El nombre ingresado no se encuentra en el inventario" << endl;

                                }
                            } while (validador == false);
                            pausa();
                            break;
                        
                        case '4':

                        // Regresa al menu principal del dueño
                            inventario = true;
                            continue;
                            break;
                        default:
                            system("cls");
                            cout << "Opcion no valida" << endl;
                            pausa();
                            break;
                        }

                    } while (inventario != true);
                }
                inventario = false;
                pausa();
                break;

                case '2':

                    //Verifica primero si los usuarios compraron productos (en total dos usuarios)
                    if (comprarealizada==true && comprarealizada2 == true ) {

                    //El dueño elige que producto desea ver si obtuvo ganancias o perdidas debido a que no se vendieron 
                    cout << "--------------------------Ganancias---------------------------" << endl;
                    cout << "--------------------------------------------------------------" << endl;
                    a = 0;
                    for (int i = 0; i < cont_prod; i++) {
                        cout << i+1 << ") " << nombre[i] << endl;
                    }
                    cout << "Que producto del inventario desea visualizar?" << endl;

                    bool validador;
                    //Se busca las ventas obtenidas por un producto de cada cliente para almacenarlas y luego sumarlo
                    // y restarle el coste de produccion y obtener las ganancias del producto.
                    do {
                        cin >> t;
                        validador = validacionProducto(t, nombre);
                        if (validador == true) {
                            int indice_compra;
                            int indice_compra2;
                            for (int i = 0; i < cont; i++) {
                                if (arr_compra[i] == t) {
                                    a = arr_cantventa[i];
                                    indice_compra = i;
                                    break;
                                }
                            }

                            for (int i = 0; i < cont2; i++) {
                                if (arr_compra2[i] == t) {
                                    a2 = arr_cantventa2[i];
                                    indice_compra2 = i;
                                    break;
                                }
                            }

                            
                            for (int i = 0; i < cont_prod; i++) {
                                if (nombre[i] == t) {

                                    costo_produccion = (cantidad[i] + arr_cantcompra[indice_compra]+arr_cantcompra2[indice_compra2]) * preciocomprado[i];
                                    break;
                                }

                            }
                            cout << "El costo de la produccion de " << t << " fue de: " << costo_produccion << endl;

                            cout << "Las ventas de " << t << " fue de: " << a + a2 << endl;

                            int ganancias;

                            ganancias = (a + a2) - costo_produccion;

                            if (ganancias == 0) {

                                cout << "No se obtuvo ganancias de " << t << endl;

                            }

                            if (ganancias < 0) {

                                cout << " Hubo perdidas de " << ganancias <<" debido a que no se vendio stock suficiente de " << t << endl;

                            }

                            if (ganancias > 0) {

                                cout << "Las ganancias obtenidas de " << t << " fueron de: " << ganancias << endl;

                            }

                        } else {
                            cout << "El nombre del producto que ingreso no se encuentra en el inventario." << endl;

                        }
                    } while (validador == false);
                    }
                    else {
                        cout << "Usted no puede ver aun las ganancias debido a que no se ha registrado ninguna venta de sus clientes (dos clientes)" << endl;
                    }

                    pausa();
                    break;

                case '3':
                    //Se elige al cliente que se le quiere dar un descuento para una sola compra
                    cout << "A que cliente quieres otorgar el descuento?" << endl;
                    cout <<  "1) Bici2" << endl;
                    cout <<  "2) Bici3" << endl;
                    char uu;
                    cin >> uu;
                    
                    switch(uu){
                        case '1':
                        checkUser1 = true;
                        break;
                        case '2':
                        checkUser1 = false;
                        break;
                        default:
                            system("cls");
                            cout << "Opcion no valida" << endl;
                            pausa();
                            break;
                    }
                    // Se elige que descuento se le quiere dar al cliente
                    cout << "Que tipo de descuento quieres asignar al cliente?" << endl;
                    cout << "1) 0%" << endl;
                    cout << "2) 20%" << endl;
                    cout << "3) 50%" << endl;
                    char eleccion_descuento;
                    cin >> eleccion_descuento;
                    switch (eleccion_descuento) {
                    case '1':
                    if(checkUser1){
                        descuento = 1.0;
                        cout << "Descuento removido" << endl;
                        flag_descuento = false;
                    }else{
                        descuento2 = 1.0;
                        cout << "Descuento removido" << endl;
                        flag_descuento2 = false;
                    }
                        break;
                    case '2':
                    if(checkUser1){
                        descuento = 0.2;
                        cout << "Descuento otorgado" << endl;
                        flag_descuento = true;
                    } else{
                        descuento2 = 0.2;
                        cout << "Descuento otorgado" << endl;
                        flag_descuento2 = true;
                    }
                        break;
                    case '3':
                    if(checkUser1){
                        descuento = 0.5;
                        cout << "Descuento otorgado" << endl;
                        flag_descuento = true;
                    } else{
                        descuento2 = 0.5;
                        cout << "Descuento otorgado" << endl;
                        flag_descuento2 = true;
                    }
                        
                        break;
                    default:
                    if(checkUser1){
                        descuento = 1.0;
                        cout << "Descuento removido" << endl;
                        flag_descuento = false;
                    }else{
                        descuento2 = 1.0;
                        cout << "Descuento removido" << endl;
                        flag_descuento2 = false;
                    }
                        
                        break;
                    }
                    pausa();
                    break;
                    
                case '4':
            
                    int cant_copia[num];

                    // Se crea una copia de la cantidad del inventario para que no se vea alterada las posiciones
                    // debido a que se va a iterar las posiciones del arreglo cantidad para encontrar el producto
                    // con la menor cantidad de existencias y decirle al usuario cual debe comprar primero de 
                    // manera ascendente
                    
                    cant_copia[num] = cantidad[num];
                    nombre_copia[num] = nombre[num];
                    int y;
                    
                    cout << "El sistema sugiere a la empresa comprar los siguientes productos en este orden ascendente:" << endl;

                    for (int i=0; i < cont_prod; i++) {
                        cant_copia[i] = cantidad[i];
                        nombre_copia[i] = nombre[i];
                    }

                    for (int i=0; i < cont_prod; i++) {
                        for (int j=i+1; j < cont_prod; j++) {
                            if (cant_copia[j] < cant_copia[i]) {
                                y=cant_copia[j];
                                nn=nombre_copia[j];
                                cant_copia[j] = cant_copia[i];
                                nombre_copia[j] = nombre_copia[i];
                                cant_copia[i] = y;
                                nombre_copia[i] = nn;
                            }
                        }
                        cout << i+1 << ") " <<  nombre_copia[i] << ": " << cant_copia[i] << endl;
                    }

                    pausa();
                    break;
                
                case '5':
                    // Regresa al usuario al sistema

                    cout << "Vuelva pronto" << endl;
                    bandera = true;
                    s = false;
                    break;

                default:
                    system("cls");
                    cout << "Opcion no valida" << endl;
                    pausa();
                    break;

                }
            }
            

        }

        
        if (user2 == true && con2 == true) {
            while (bandera2 != true) {
                user2 = true;
                con2 = true;

                // En caso de que se le haya dado un descuento a este cliente, 
                // le aparecera una notificacion que cuenta con un descuento

                 if (flag_descuento) {
                    cout << " Usted cuenta con un descuento de " << descuento *100 << "%" <<  " uselo para una transaccion  " << endl;
                }

                cout << "------Usuario-------" << endl;
                cout << "---Menu principal---" << endl;
                cout << "--------------------" << endl;
                cout << "Comprar          (1)" << endl;
                cout << "Salir            (2)" << endl;
                cout << "--------------------" << endl;
                cout << "Que quiere realizar?" << endl;
                cin >> e;
                switch (e) {
                 // Se valida comprar y salir
                case '1':
                    // El cliente debe escribir que producto desea comprar 
                    cout << "Que desea comprar?" << endl;

                    while (test != false) {
                        cout << "Nombre" << "\t\t\t" << "Cantidad" << "\t\t" << "Precio" << endl;
                        for (int i = 0; i < cont_prod; i++) {
                            cout << nombre[i] << "\t\t\t" << cantidad[i]  << "\t\t\t" << preciovender[i] << "\t\t" << endl;
                        }

                        bool validador;
                        bool veri;
                        do {
                            cin >> nom_compra;
                            validador = validacionProducto(nom_compra, nombre);
                            if (validador == true) {

                                //El cliente escribe cuanta cantidad desea comprar del producto elegido
                                do{
                                    cout << "Cual es la cantidad a comprar?" << endl;
                                    do {
                                        cin >> str_cant_compra;
                                    }while (!validacion(str_cant_compra));
                                    cant_compra = convertir_str_to_int(str_cant_compra);

                                veri = validacionCantidadesaVender(cant_compra, cantidad, nom_compra,nombre);
                                if(veri == true){
                                for (int i = 0; i <= cont; i++) {
                                    if (arr_compra[i] == nom_compra) {
                                        arr_cantcompra[i] += cant_compra;
                                        break;
                                    }
                                    if (i == cont) {
                                        arr_compra[i] = nom_compra;
                                        arr_cantcompra[i] = cant_compra;
                                        cont++;
                                        break;
                                    }
                                }
                                // Se le avisa al cliente que ingreso mas de la cantidad que el inventario puede ofrecer
                                modificarCantidad(nombre, nom_compra, cant_compra, cont_prod);
                                }else{
                                    cout<<"Estas ingresando mas cantidad de lo que se tiene en inventario" << endl;
                                }
                                } while(veri != true);
                                // Se le pregunta al cliente si quiere comprar mas productos 
                                cout << "Quieres comprar otro producto? 1. Si 2. No" << endl;
                                do {
                                    cin >> str_respuesta;
                                } while (!validacion(str_respuesta));
                                respuesta = convertir_str_to_int(str_respuesta);
                                if (respuesta == 1) {
                                    test = true;
                                } else {
                                    test = false;
                                }
                            } else {
                                cout << "El nombre del producto que ingreso no se encuentra en el inventario. Por favor vuelve a intentarlo" << endl;

                            }
                            for (int i = 0; i < cont_prod; i++) {
                        for (int j = 0; j < cont; j++) {
                            //Aqui se realiza la operacion en caso de que el cliente haya obtenido un descuento
                            if (arr_compra[j] == nombre[i] && nom_compra == nombre[i]) {
                                arr_cantventa[j] += cant_compra * (preciovender[i] - (flag_descuento == true ? (int)(preciovender[i] * descuento) : 0));
                                total_recibo += arr_cantcompra[j] * (preciovender[i] - (flag_descuento == true ? (int)(preciovender[i] * descuento) : 0));
                                // El ? es lo mismo que hacer una condicion if else
                                if (flag_descuento == true) {
                                    descuento = 1.0;
                                    flag_descuento = false;
                                }
                            }
                            
                        }
                    }
                        } while (validador == false);
                    }
                    for (int i = 0; i < cont; i++) {
                        cout << arr_compra[i] << "   " << arr_cantcompra[i] << endl;
                    }

                    // Se le enseña al usuario su ticket, mostrando el producto que compro, 
                    // la cantidad que compro de dicho producto, el precio total que pago por el producto,
                    // y la sumatoria que pago en total

                    
                    cout << "Producto comprado: " << "\t\t" << "Cantidad: " << "\t\t" << "Costo total del producto:" << endl;
                    
                    for (int i = 0; i < cont; i++) {
                        cout << arr_compra[i] << "\t\t\t\t" << arr_cantcompra[i] << "\t\t\t"  << arr_cantventa[i] << endl;
                    }
                    
                    for (int j  = 0; j< cont; j++){
                        total_recibofinal += arr_cantventa[j];
                    }
                    
                    cout << "Total pagado" << endl;
                   
                    comprarealizada = true;


                    cout << total_recibofinal << endl;
                    total_recibofinal =0;
                    
                    test = true;

                    pausa();
                    break;

                case '2':

                    // Regresa al sistema principal

                    cout << "Vuelva pronto" << endl;
                    bandera2 = true;
                    s = false;
                    break;

                default:

                    system("cls");
                    cout << "Opcion no valida" << endl;
                    pausa();
                    break;
                    

                }
            }
        }

        // Lo mismo documento en el cliente 1 se hace uso respecto al cliente 2, 
        // solamente que cuenta con sus respectivas variables
        
        if (user3 == true && con3 == true) {
            while (bandera3 != true) {
                user3 = true;
                con3 = true;

                if (flag_descuento2) {
                    cout << " Usted cuenta con un descuento de "<< descuento2 *100 << "%" <<  "   uselo para una transaccion  " << endl;
                }

                cout << "------Usuario 2-------" << endl;
                cout << "---Menu principal---" << endl;
                cout << "--------------------" << endl;
                cout << "Comprar          (1)" << endl;
                cout << "Salir            (2)" << endl;
                cout << "--------------------" << endl;
                cout << "Que quiere realizar?" << endl;
                char w;
                cin >> w;
                switch (w) {
                case '1':


                    cout << "Que desea comprar?" << endl;

                    while (test2 != false) {
                        cout << "Nombre" << "\t\t\t" << "Cantidad" << "\t\t"  << "Precio a vender" << endl;
                        for (int i = 0; i < cont_prod; i++) {
                            cout << nombre[i] << "\t\t\t" << cantidad[i] << "\t\t\t"  << preciovender[i] << "\t\t"  << endl;
                        }

                        bool validador;
                        bool veri;
                        do {
                            cin >> nom_compra2;
                            validador = validacionProducto(nom_compra2, nombre);
                            if (validador == true) {

                                
                                do{
                                    cout << "Cual es la cantidad a comprar?" << endl;
                                    do {
                                        cin >> str_cant_compra2;
                                    } while (!validacion(str_cant_compra2));
                                    cant_compra2 = convertir_str_to_int(str_cant_compra2);

                                veri = validacionCantidadesaVender(cant_compra2, cantidad, nom_compra2,nombre);
                                if(veri == true){
                                for (int i = 0; i <= cont2; i++) {
                                    if (arr_compra2[i] == nom_compra2) {
                                        arr_cantcompra2[i] += cant_compra2;
                                        break;
                                    }
                                    if (i == cont2) {
                                        arr_compra2[i] = nom_compra2;
                                        arr_cantcompra2[i] = cant_compra2;
                                        cont2++;
                                        break;
                                    }
                                }
                               
                                modificarCantidad(nombre, nom_compra2, cant_compra2, cont_prod);
                                }else{
                                    cout<<"Estas ingresando mas cantidad de lo que se tiene en inventario" << endl;
                                }
                                } while(veri != true);
                                cout << "Quieres agregar otro producto? 1. Si 2. No" << endl;

                                do {
                                    cin >> str_respuesta2;
                                } while (!validacion(str_respuesta2));
                                respuesta2 = convertir_str_to_int(str_respuesta2);

                                if (respuesta2 == 1) {
                                    test2 = true;
                                } else {
                                    test2 = false;
                                }
                            } else {
                                cout << "El nombre del producto que ingreso no se encuentra en el inventario. Por favor vuelve a intentarlo" << endl;

                            }
                        } while (validador == false);
                        for (int i = 0; i < cont_prod; i++) {
                        for (int j = 0; j < cont2; j++) {
                            
                            if (arr_compra2[j] == nombre[i] && nom_compra2 == nombre[i]) {
                                arr_cantventa2[j] += cant_compra2 * (preciovender[i] - (flag_descuento2 == true ? (int)(preciovender[i] * descuento2) : 0));
                                total_recibo2 += arr_cantcompra2[j] * (preciovender[i] - (flag_descuento2 == true ? (int)(preciovender[i] * descuento2) : 0));
                                
                                if (flag_descuento2 == true) {
                                    descuento2 = 1.0;
                                    flag_descuento2 = false;
                                }
                            }
                            
                        }
                    }
                    }
                    for (int i = 0; i < cont2; i++) {
                        cout << arr_compra2[i] << "   " << arr_cantcompra2[i] << endl;
                    }


                    
                    cout << "Producto comprado: " << "\t\t" << "Cantidad: " << "\t\t" << "Costo total del producto:" << endl;
        
                    for (int i = 0; i < cont2; i++) {
                        cout << arr_compra2[i] << "\t\t\t\t" << arr_cantcompra2[i] << "\t\t\t" << arr_cantventa2[i] << endl;
                    }
                    

                    for (int j  = 0; j< cont2; j++){
                        total_recibofinal2 += arr_cantventa2[j];
                    }
                    
                    cout << "Total pagado" << endl;
                
                    comprarealizada2 = true;

                    cout << total_recibofinal2 << endl;
                    total_recibofinal2 =0;
                    
                    test2 = true;

                    pausa();
                    break;

                case '2':

                    cout << "Vuelva pronto" << endl;
                    bandera3 = true;
                    s = false;
                    break;

                default:

                    system("cls");
                    cout << "Opcion no valida" << endl;
                    pausa();
                    break;
                    

                }
            }
        }
       
    }

    return 0;
}