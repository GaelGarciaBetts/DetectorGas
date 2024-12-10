#include <LiquidCrystal.h>

// Definición de pines
const int sensorGas = A1;     // Pin del sensor MQ-2/MQ-135
const int ledAlarma = 9;      // Pin del LED de alarma
const int buzzer = 8;         // Pin del zumbador

// Umbral de activación
const int umbralGas = 3;    // Valor analógico del MQ-2 para activar alarma

void setup() {
  // Configuración de pines
  pinMode(ledAlarma, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  // Comunicación serial para depuración
  Serial.begin(9600);
}

void loop() {
  // Lectura del sensor de gas
  int valorGas = analogRead(sensorGas);

  // Comprobar condición de alarma
  if (valorGas > umbralGas) {
    activarAlarma();
    Serial.println("Se detectó gas, ¡alarma activada!");
  } else {
    desactivarAlarma();
    Serial.println("Niveles normales de gas.");
  }

  // Espera para la siguiente lectura
  delay(1000);
}

// Función para activar la alarma
void activarAlarma() {
  digitalWrite(ledAlarma, HIGH);
  digitalWrite(buzzer, HIGH);
}

// Función para desactivar la alarma
void desactivarAlarma() {
  digitalWrite(ledAlarma, LOW);
  digitalWrite(buzzer, LOW);
}
