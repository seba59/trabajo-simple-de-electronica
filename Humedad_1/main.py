# Importar la biblioteca de GPIO
from machine import Pin, ADC
import time


# Definir el pin de entrada del sensor
humedadPin = Pin(4, Pin.IN)

# Definir el pin de salida para el LED interno
ledPin = Pin(2, Pin.OUT)

# Definir los rangos de humedad
minHumedad = 0 # Humedad mínima posible
maxHumedad = 100 # Humedad máxima posible

# Configurar el pin de salida del LED interno
ledPin.value(0)

while True:
  # Leer el valor analógico del sensor de humedad
    humedadADC = ADC(humedadPin)
    lectura = humedadADC.read()

  # Convertir el valor leído en humedad relativa
    humedad = int((100*lectura)/4095) # "100" respesenta 100%, "4095" la lectura de ESP32 y la "lectura" es la variable
    print("Humedad detectada: {}%".format(humedad))
    time.sleep(0.5)

  # Encender el LED si se detecta humedad
    if 50 < humedad:
        ledPin.value(1)
        time.sleep(0.5)
        ledPin.value(0)
        time.sleep(0.5)