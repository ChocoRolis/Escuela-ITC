import os
import signal

def senial(pid, dirpath):
    try:
        if not os.path.isdir(dirpath):
            print("path no es valido")
        return

    finally:
        os.environ['DIRPATH'] = dirpath
        os.kill(pid, signal.SIGTERM)
        print(f"senial del SIGTERM enviada al proceso {pid}")

def main():
    pid = input("Escriba el PID del proceso a mandar senial: ")
    dirpath = input("Ingrese el path absoluto del directorio: ")
    try:
        pid = int(pid)
        os.kill(pid, signal.SIGTERM)
        print(f"Senial del SIGTERM enviada al proceso {pid}")

    except ValueError:
        print("Numero de senial invalida")

    except ProcessLookupError:
        print(f"Proceso inexistente {pid}")

    except PermissionError:
        print(f"No tienes permiso de mandar la senial a este proceso {pid}")

if __name__ == "__main__":
    main()
