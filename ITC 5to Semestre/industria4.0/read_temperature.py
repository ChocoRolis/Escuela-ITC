from machine import Pin, ADC
import utime

class Temperature:
    def __init__(self):
        adcpin = 4
        self.sensor = ADC(adcpin)
        
    def ReadTemperature(self):
        adc_value = self.sensor.read_u16()
        volt = (3.3/65535) * adc_value
        temperature = 27 - (volt - 0.706)/0.001721
        return round(temperature, 2)
           

archivo = "datos_temperatura.csv"
with open(archivo, "a") as f:
    f.write("Tiempo(seg), Temperatura\n")

sensor = Temperature()
ledpico = machine.Pin(25, machine.Pin.OUT)

inicio = utime.time()

while True:
    ledpico.value(1)
    utime.sleep(1)

    temperature = sensor.ReadTemperature()
    tiempo_relativo = utime.time() - inicio
    
    print(temperature)

    with open(archivo, "a") as f:
        f.write(f"{tiempo_relativo},{temperature}\n")
        
    ledpico.value(0)
    utime.sleep(299)