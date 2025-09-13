import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
from tensorflow.keras.callbacks import EarlyStopping
from tensorflow.keras.activations import swish

df = pd.read_csv("/home/rolando/Escritorio/Escuela-ITC/ITC 7mo Semestre/IA/examen1/BASE2_PART2_AADW_2024_DEF.csv")

X = df.drop('Selector', axis = 1).values
Y = df['Selector'].values

X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size = 0.2, random_state = 0)

scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

model = Sequential()
model.add(Dense(32, input_dim = 8, activation = 'relu'))
model.add(Dense(16, activation = 'swish'))
model.add(Dense(8, activation = 'swish'))
model.add(Dense(8, activation = 'swish'))
model.add(Dense(1, activation = 'sigmoid'))

model.compile(loss= 'binary_crossentropy', optimizer= 'adam', metrics =['accuracy'])
early_stop = EarlyStopping(
    monitor = 'val_loss', 
    patience = 8,
    restore_best_weights=True
)

history = model.fit(
    X_train_scaled, Y_train,
    validation_split = 0.2,
    epochs = 1000,
    batch_size= 10,
    callbacks = [early_stop],
    verbose=1
)
