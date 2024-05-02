import tkinter as tk
from getpass import getpass
import mysql.connector 

# Para luego:
flag = False

def buscar(linea, desc_corta, desc_larga, masc):
    cursor = dataBase.cursor()
    cursor.execute("use OLP300")

    linea_ = linea.get()
    query = f"SELECT * FROM lineas_de_negocio WHERE Linea = '{linea_}'"
    cursor.execute(query)
    resultado = cursor.fetchall()

    desc_corta.delete(0, tk.END)
    desc_larga.delete(1.0, tk.END)
    masc.delete(0, tk.END)
    
    desc_corta.insert( tk.INSERT, str(resultado[0][2]) )
    desc_larga.insert( tk.INSERT, str(resultado[0][3]) )
    masc.insert( tk.INSERT, str(resultado[0][4]) )
    

def alta(linea, desc_corta, desc_larga, masc):
    cursor = dataBase.cursor()
    cursor.execute("use OLP300")


def cambio(flag, linea, desc_corta, desc_larga, masc):
    cursor = dataBase.cursor()
    cursor.execute("use OLP300")


def baja(flag, linea, desc_corta, desc_larga, masc):
    cursor = dataBase.cursor()
    cursor.execute("use OLP300")



try:
    dataBase = mysql.connector.connect(
        host ="localhost",
        user = "root", #input("Enter username: "),
        passwd = "20032007" # getpass("Enter password: ")
    )
    print(dataBase)
except Error as e:
    print(e)



# CREAR VENTANA PRINCIPAL
ventana = tk.Tk()
ventana.title("Mantenimiento de Linea de Negocio")
ventana.geometry("600x350")


# BOTONES 
frame_botones = tk.Frame(ventana)
frame_botones.pack(pady=20)

boton_agregar = tk.Button(frame_botones, text="Agregar", command=lambda: alta(entrada_linea, entrada_desc_corta, entrada_desc_larga, entrada_mascara))
boton_agregar.pack(side=tk.LEFT, padx=5)

boton_cambiar = tk.Button(frame_botones, text="Cambiar", command=lambda: cambio(flag, entrada_linea, entrada_desc_corta, entrada_desc_larga, entrada_mascara))
boton_cambiar.pack(side=tk.LEFT, padx=5)

boton_borrar= tk.Button(frame_botones, text="Borrar", command=lambda: baja(flag, entrada_linea, entrada_desc_corta, entrada_desc_larga, entrada_mascara))
boton_borrar.pack(side=tk.LEFT, padx=5)

boton_primer = tk.Button(frame_botones, text="<<")
boton_primer.pack(side=tk.LEFT, padx=5)

boton_anterior = tk.Button(frame_botones, text="<")
boton_anterior.pack(side=tk.LEFT, padx=5)

boton_siguiente= tk.Button(frame_botones, text=">")
boton_siguiente.pack(side=tk.LEFT, padx=5)

boton_ultimo = tk.Button(frame_botones, text=">>")
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
