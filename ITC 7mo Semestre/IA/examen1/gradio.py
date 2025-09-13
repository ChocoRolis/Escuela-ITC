import gradio as gr
import numpy as np 

def estimate_salary_by_experience(exp):
    return NULL

# Interfaz de Gradio
 experience_interface = gr.Interface( 
    fn=estimate_salary_by_experience, 
    inputs=gr.Slider(
        minimum=1, 
        maximum=50, 
        step=1, 
        label="Años de Experiencia"
    ), 
    outputs="text", 
    title="Estimación de Salario por Años de Experiencia" 
) 

experience_interface.launch()
