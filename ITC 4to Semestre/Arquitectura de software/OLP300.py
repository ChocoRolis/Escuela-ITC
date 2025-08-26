import tkinter as tk
from tkinter import messagebox
from getpass import getpass
import mysql.connector 

# VARIABLES GLOBALES 
consulta_previa = False
datos_consulta = []


# CONEXION A BASES DE DATOS
try:
    dataBase = mysql.connector.connect(
        host ="localhost", #input("Enter username: "),
        user = "root", 
        passwd = "20032007"# getpass("Enter password: ")
    )
    print(dataBase)
except OSError as e:
    print(e)


# CREAR VENTANA PRINCIPAL
ventana = tk.Tk()
ventana.title("Mantenimiento de Linea de Negocio")
ventana.geometry("600x350")


# FUNCIONES

# Estas dos primeras funciones representan el cambio a E1 del diagrama estado-transicion, cuando aun no se ha hecho una consulta previa exitosa
# bool consulta_previa sirve para indicar si se ha hecho la consulta
# list datos_consulta para guardar los datos de la consulta
def consulta_false():       
    global consulta_previa  # Indica que se está utilizando la variable global
    global datos_consulta
    consulta_previa = False
    datos_consulta = []


def consulta_true(datos):
    global consulta_previa
    global datos_consulta
    consulta_previa = True
    datos_consulta = datos


# Buscar y desplegar datos de una Linea de Negocio dado el nombre de la linea
def buscar(linea, desc_corta, desc_larga, masc):
    cursor = dataBase.cursor()
    cursor.execute("use OLP300")

    _linea = linea.get()
    cursor.execute(f"SELECT * FROM lineas_de_negocio WHERE Linea = '{_linea}'")

    resultado = cursor.fetchall()
    if resultado:
        consulta_true(resultado)

        desc_corta.delete(0, tk.END)
        desc_larga.delete(1.0, tk.END)
        masc.delete(0, tk.END)
    
        desc_corta.insert( tk.INSERT, str(resultado[0][2]) )
        desc_larga.insert( tk.INSERT, str(resultado[0][3]) )
        masc.insert( tk.INSERT, str(resultado[0][4]) )
    else:
        messagebox.showinfo("", "La Linea no esta disponible")
        consulta_false()


# Insertar Linea de Negocio en la base de datos
def alta(linea, desc_corta, desc_larga, masc):
    cursor = dataBase.cursor()
    cursor.execute("use OLP300")

    _linea = linea.get()
    _desc_corta = desc_corta.get()
    _desc_larga = desc_larga.get("1.0",'end-1c')
    _masc = masc.get()

    consulta_false()

    if _linea != "" and _desc_corta != "" and _desc_larga != "" and _masc != "":
        cursor.execute(f"SELECT * FROM lineas_de_negocio WHERE Linea = '{_linea}'")
        
        resultado = cursor.fetchone()
        if resultado:
            messagebox.showerror("", "La Linea ya existe")
        else:
            cursor.execute(f"INSERT INTO lineas_de_negocio ( Linea, DescripcionCorta, DescripcionLarga, Mascara, Fecha, Hora, Usuario, Accion ) VALUES ( '{_linea}', '{_desc_corta}', '{_desc_larga}', '{_masc}', current_date(), current_time(), 'RolandoRoot', 'A' )")
            dataBase.commit()
            messagebox.showinfo("Agregado", "Linea de Negocio dada de alta exitosamente")
    else:
        messagebox.showerror("", "Por favor llene los campos requeridos")


# Cambiar datos de una Linea de Negocio 
def cambio(linea, desc_corta, desc_larga, masc):
    cursor = dataBase.cursor()
    cursor.execute("use OLP300")

    if consulta_previa == True:
        _linea = linea.get()
        _desc_corta = desc_corta.get()
        _desc_larga = desc_larga.get("1.0",'end-1c')
        _masc = masc.get()

        if _linea != "" and _desc_corta != "" and _desc_larga != "" and _masc != "":
            cursor.execute(f"UPDATE lineas_de_negocio SET Linea = '{_linea}', DescripcionCorta = '{_desc_corta}', DescripcionLarga = '{_desc_larga}', Mascara = '{_masc}', Fecha = current_date(), Hora = current_time(), Accion = 'C' WHERE id = {datos_consulta[0]}") # NO SIRVE ESTO :(
            consulta_false()
            dataBase.commit()
            messagebox.showinfo("", "Cambios actualizados correctamente")
        else:
            messagebox.showerror("", "Por favor llene los campos requeridos")

    else:
        messagebox.showerror("", "Se necesita primero una consulta de los datos")
   

# Eliminar una Linea de Negocio de la Base de Datos
def baja(linea, desc_corta, desc_larga, masc):
    cursor = dataBase.cursor()
    cursor.execute("use OLP300")
    
    _linea = linea.get()
    
    if _linea != "" and consulta_previa == True:
        cursor.execute(f"SELECT * FROM lineas_de_negocio WHERE Linea = '{_linea}'")

        resultado = cursor.fetchone()
        if resultado:
            cursor.execute(f"DELETE FROM lineas_de_negocio WHERE Linea = '{_linea}'") 
            dataBase.commit()
            messagebox.showinfo("Eliminado", "Linea de Negocio dada de baja exitosamente")
        else:
            messagebox.showinfo("", "Esta linea de negocio no existe")
    else:
        messagebox.showerror("", "Por favor llene el campo de Linea y haga una consulta primero")


def primer(linea, desc_corta, desc_larga, masc):
    cursor = dataBase.cursor()
    cursor.execute("use OLP300")

    cursor.execute("SELECT * FROM lineas_de_negocio WHERE id = (SELECT MIN(id) from lineas_de_negocio)")

    resultado = cursor.fetchall()
    if resultado:
        linea.delete(0, tk.END)
        desc_corta.delete(0, tk.END)
        desc_larga.delete(1.0, tk.END)
        masc.delete(0, tk.END)

        linea.insert( tk.INSERT, str(resultado[0][1]) )
        desc_corta.insert( tk.INSERT, str(resultado[0][2]) )
        desc_larga.insert( tk.INSERT, str(resultado[0][3]) )
        masc.insert( tk.INSERT, str(resultado[0][4]) )


def anterior(linea, desc_corta, desc_larga, masc):
    cursor = dataBase.cursor()
    cursor.execute("use OLP300")

    _linea = linea.get()
    cursor.execute(f"SELECT id FROM lineas_de_negocio WHERE Linea = '{_linea}'")
    resultado = cursor.fetchone()
    if resultado:
        cursor.execute(f"SELECT * FROM lineas_de_negocio WHERE id < {resultado[0]} ORDER BY id DESC LIMIT 1")
        anterior_consulta = cursor.fetchall()
        
        if anterior_consulta:
            linea.delete(0, tk.END)
            desc_corta.delete(0, tk.END)
            desc_larga.delete(1.0, tk.END)
            masc.delete(0, tk.END)

            linea.insert( tk.INSERT, str(anterior_consulta[0][1]) )
            desc_corta.insert( tk.INSERT, str(anterior_consulta[0][2]) )
            desc_larga.insert( tk.INSERT, str(anterior_consulta[0][3]) )
            masc.insert( tk.INSERT, str(anterior_consulta[0][4]) )


def siguiente(linea, desc_corta, desc_larga, masc):
    cursor = dataBase.cursor()
    cursor.execute("use OLP300")

    _linea = linea.get()
    cursor.execute(f"SELECT id FROM lineas_de_negocio WHERE Linea = '{_linea}'")
    resultado = cursor.fetchone()
    if resultado:
        cursor.execute(f"SELECT * FROM lineas_de_negocio WHERE id > {resultado[0]} ORDER BY id LIMIT 1")
        anterior_consulta = cursor.fetchall()
        
        if anterior_consulta:
            linea.delete(0, tk.END)
            desc_corta.delete(0, tk.END)
            desc_larga.delete(1.0, tk.END)
            masc.delete(0, tk.END)

            linea.insert( tk.INSERT, str(anterior_consulta[0][1]) )
            desc_corta.insert( tk.INSERT, str(anterior_consulta[0][2]) )
            desc_larga.insert( tk.INSERT, str(anterior_consulta[0][3]) )
            masc.insert( tk.INSERT, str(anterior_consulta[0][4]) )




def ultimo(linea, desc_corta, desc_larga, masc):
    cursor = dataBase.cursor()
    cursor.execute("use OLP300")

    cursor.execute("SELECT * FROM lineas_de_negocio WHERE id = (SELECT MAX(id) from lineas_de_negocio)")

    resultado = cursor.fetchall()
    if resultado:
        linea.delete(0, tk.END)
        desc_corta.delete(0, tk.END)
        desc_larga.delete(1.0, tk.END)
        masc.delete(0, tk.END)

        linea.insert( tk.INSERT, str(resultado[0][1]) )
        desc_corta.insert( tk.INSERT, str(resultado[0][2]) )
        desc_larga.insert( tk.INSERT, str(resultado[0][3]) )
        masc.insert( tk.INSERT, str(resultado[0][4]) )





# BOTONES
frame_botones = tk.Frame(ventana)
frame_botones.pack(pady=20)

boton_agregar = tk.Button(frame_botones, text="Agregar", command=lambda: alta(entrada_linea, entrada_desc_corta, entrada_desc_larga, entrada_mascara))
boton_agregar.pack(side=tk.LEFT, padx=5)

boton_cambiar = tk.Button(frame_botones, text="Cambiar", command=lambda: cambio(entrada_linea, entrada_desc_corta, entrada_desc_larga, entrada_mascara))
boton_cambiar.pack(side=tk.LEFT, padx=5)

boton_borrar= tk.Button(frame_botones, text="Borrar", command=lambda: baja(entrada_linea, entrada_desc_corta, entrada_desc_larga, entrada_mascara))
boton_borrar.pack(side=tk.LEFT, padx=5)

boton_primer = tk.Button(frame_botones, text="<<", command=lambda: primer(entrada_linea, entrada_desc_corta, entrada_desc_larga, entrada_mascara))
boton_primer.pack(side=tk.LEFT, padx=5)

boton_anterior = tk.Button(frame_botones, text="<", command=lambda: anterior(entrada_linea, entrada_desc_corta, entrada_desc_larga, entrada_mascara))
boton_anterior.pack(side=tk.LEFT, padx=5)

boton_siguiente= tk.Button(frame_botones, text=">", command=lambda: siguiente(entrada_linea, entrada_desc_corta, entrada_desc_larga, entrada_mascara))
boton_siguiente.pack(side=tk.LEFT, padx=5)

boton_ultimo = tk.Button(frame_botones, text=">>", command=lambda: ultimo(entrada_linea, entrada_desc_corta, entrada_desc_larga, entrada_mascara))
boton_ultimo.pack(side=tk.LEFT, padx=5)



# CUADROS DE TEXTO
frame_texto = tk.Frame(ventana)
frame_texto.pack(pady=10)

etiqueta_linea = tk.Label(frame_texto, text="Línea:")
etiqueta_linea.grid(row=0, column=0, padx=5, pady=5, sticky="e")
entrada_linea = tk.Entry(frame_texto, width=40)
entrada_linea.grid(row=0, column=1, padx=5, pady=5)

etiqueta_desc_corta = tk.Label(frame_texto, text="Descripción Corta:")
etiqueta_desc_corta.grid(row=1, column=0, padx=5, pady=5, sticky="e")
entrada_desc_corta = tk.Entry(frame_texto, width=40)
entrada_desc_corta.grid(row=1, column=1, padx=5, pady=5)

etiqueta_desc_larga = tk.Label(frame_texto, text="Descripción Larga:")
etiqueta_desc_larga.grid(row=2, column=0, padx=5, pady=5, sticky="e")
entrada_desc_larga = tk.Text(frame_texto, height=5, width=40)
entrada_desc_larga.grid(row=2, column=1, padx=5, pady=5, sticky="n")

etiqueta_mascara = tk.Label(frame_texto, text="Máscara:")
etiqueta_mascara.grid(row=3, column=0, padx=5, pady=5, sticky="e")
entrada_mascara = tk.Entry(frame_texto, width=40)
entrada_mascara.grid(row=3, column=1, padx=5, pady=5)

boton_buscar = tk.Button(frame_texto, text="Buscar", command=lambda: buscar(entrada_linea, entrada_desc_corta, entrada_desc_larga, entrada_mascara))
boton_buscar.grid(row=0, column=2, padx=5, pady=5)



# BUCLE VENTANA PRINCIPAL 
ventana.mainloop()

# CIERRA BASES DE DATOS
dataBase.close()
