import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
import tensorflow as tf

# Act de variables continuas

data = pd.read_csv("/home/rolando/Escritorio/Escuela-ITC/ITC 7mo Semestre/IA/Act4/house_prices.csv")

# limpiar la base
data = data.drop(["Id", "Alley", "PoolQC", "Fence", "MiscFeature"], axis=1)
# creamos un dataframe numerico
df_num = data.select_dtypes(include=["int64", "float64"]).columns 
data = data[df_num].dropna()

# 1. preprocesamiento de datos
# 1.1 declaracion de variables
X = data.drop("SalePrice", axis = 1)
Y = data["SalePrice"]


# 1.2 division train test
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size = 0.2, random_state = 0)

# 1.3 escalado
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

# 2. Primer entrenamiento de la red neuronal
model = tf.keras.Sequential([
    tf.keras.layers.Dense(256, activation="relu", input_shape=(X_train_scaled.shape[1], )),
    tf.keras.layers.Dropout(0.2), # capa inicial
    tf.keras.layers.Dense(128, activation="relu"),
    tf.keras.layers.Dropout(0.2), # capa oculta 1
    tf.keras.layers.Dense(64, activation="relu"),
    tf.keras.layers.Dropout(0.2), # capa oculta 2
    tf.keras.layers.Dense(1) # Capa de salida
])

# 2.2 Compilacion
model.compile(optimizer = tf.keras.optimizer.Adam(learning_rate=0.001), loss='mse', metrics=['mae'])

# 2.3 earlystopping
early_stop = tf.keras.callbacks.EarlyStopping(monitor="val_loss", patience=8, restore_best_weights=True)

# 2.4 entrenamiento de epocas
history = model.fit(X_train_scaled, Y_train,
                    epocs = 1000,
                    batch_size = 32,
                    validation_split = 0.2,
                    callbacks = [early_stop],
                    verbose = 1
)

# 2.5 validacion
loss, mae = model.evaluate(X_test_scaled, Y_test)
print(f"el MAE_test es: (mae:.2f)")

# 3. estimacion
Features = [] # poner todas las variables con ayuda de la ia

nueva_casa = pd.DataFrame([[
    85,70,9000,7,5,
    1995, 1998,100,500,0,
    300,800,850,500,0,
    1500,1,0,2,1,
    3,1,7,1,1998,
    1,500,100,60,0,
    0,0,0,6,2022
    ]], columns = Features)

# 3.1 Escalar datos de pronostico
nueva_casa_scaled = scaler.transform(nueva_casa)
precio_pronosticado = model.predict(nueva_casa_scaled)

print("la prediccion del prcio de la nueva casa sera: ", precio_pronosticado[0][0])
