import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

df = pd.read_csv("/home/rolando/Escritorio/Escuela-ITC/ITC 7mo Semestre/IA/Act2/diabetes2.csv")

X = df.drop('Outcome', axis = 1).values
Y = df['Outcome'].values

# Division y transformacion
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size = 0.2, random_state = 0)

# Escalado
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

X_train_scaled.mean()

# Construimos la red neuronal
model = Sequential()
model.add(Dense(32, input_dim = 8, activation = 'relu'))
model.add(Dense(16, activation = 'relu'))
model.add(Dense(1, activation = 'sigmoid'))

# Compilamos y entrenamos el modelo
model.compile(loss = 'binary_crossentropy', optimizer = 'adam', metrics = ['accuracy'])

# Crear un numero optimo de iteraciones
from tensorflow.keras.callbacks import EarlyStopping

early_stop = EarlyStopping(
        monitor = 'val_loss', # metrica a vigilar
        patience = 10,
        restore_best_weights = True
)

# Entrenamos el modelo
# model.fit(X_train_scaled, Y_train, epochs = 100, batch_size = 10, verbose = 1)

history = model.fit(
        X_train_scaled, Y_train,
        validation_split = 0.2,
        epochs = 1000,
        batch_size = 10,
        callbacks = [early_stop],
        verbose = 1
)


# Creamos una funcion de prediccion
def hacer_predicion(modelo, muestra, scaled, umbral = 0.5):
    muestra_escalada = scaler.transform( [muestra] )
    probabilidad = model.predict(muestra_escalada)[0]

    clase_pred = 1 if probabilidad >= umbral else 0

    return clase_pred, probabilidad

# Ejemplo
muestra = [6,148, 72, 35, 0, 33.6, 0.627, 50]
clase_pred, probabilidad = hacer_predicion(model, muestra, scaler)
print(f" Clase : {clase_pred}, Probabilidad: {probabilidad}")
