#include <dummy.h>

// Definir el pin de entrada del sensor
const int humedadPin = 4; // GPIO4 (A0)

// Definir el pin de salida para el LED interno
const int ledPin = 2; // GPIO2

// Definir los rangos de humedad
const int minHumedad = 0; // Humedad mínima posible
const int maxHumedad = 100; // Humedad máxima posible

void setup() {
  // Configurar el monitor serie para la depuración
  Serial.begin(115200);

  // Configurar el pin de salida del LED interno
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Leer el valor analógico del sensor de humedad
  int lectura = analogRead(humedadPin);

  // Convertir el valor leído en humedad relativa
  int humedad = map(lectura, 0, 4095, minHumedad, maxHumedad);
  Serial.print("Humedad detectada: ");
  Serial.print(humedad);
  Serial.println("%");
  delay(500);

  // Encender el LED si se detecta humedad
  if (50 < humedad) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
   }}

  //
