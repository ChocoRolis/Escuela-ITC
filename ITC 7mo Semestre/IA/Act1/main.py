# Transformers de huggingface
# Red Neuronal Text to Text

from transformers import pipeline

clf = pipeline (
        task = "text-classfication",
        model = "pysentimiento/robertuito-sentiment-analysis",
        device_map = "auto"
)

ejemplos = [
        "Me encanto la clase de hoy, super clara",
        "Esto fue una perdida de tiempo",
        "Esta bien, pero no me convencio del todo"
]

for t in ejemplos:
    print(t, " --> ", clf(t))
