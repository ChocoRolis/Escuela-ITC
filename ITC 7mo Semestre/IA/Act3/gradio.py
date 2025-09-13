# GRADIO 
# Hugging Face, Transformer
# Permite crear interfaces graficas en colab

import gradio as gr
import numpy as np 

# Crear una funcion en gradio para nuestra ANN
def crear_funcion(preg, glu, bp, skin, ins, bmi, dpf, age, out):
    x = np.array([[preg, glu, bp, skin, ins, bmi, dpf, age]], dtype = float)
    p = float(model.predict(scaler.transform(x), verbose = 0)[0,0])
    return ("Positivo para diabetes(1)" if p > out else "Negativo (0)"), round(p,4)

# Parte de Gradio
demo = gr.Interface(
        fn = crear_funcion,
        inputs = [
            gr.Number(0, label = "Pregnancies"),
            gr.Number(120, label = "Glucose"),
            gr.Number(0, label = "BloodPressure"),
            gr.Number(0, label = "SkinThickness"),
            gr.Number(0, label = "Insulin"),
            gr.Number(0, label = "BMI"),
            gr.Number(0, label = "DiabetesPedigreeFunction"),
            gr.Number(0, label = "Age"),
            gr.Slider(0.05, 0.95, value = 0.5, step = 0.01, label = "Umbral")
        ],
        outputs = [gr.Label(label="Clase"), gr.Number(label="Probabilidad clase 1")],
        title = "Clasificador de diabetes",
        descripcion = "Ajuste de umbral para explorar clases"
)

