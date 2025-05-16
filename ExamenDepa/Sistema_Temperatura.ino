
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define FAN 8

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(FAN, OUTPUT);
  digitalWrite(FAN, LOW);
}

void loop() {
  delay(2000);
  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();

  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("Error al leer el sensor");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C\tHumedad: ");
  Serial.print(humedad);
  Serial.println(" %");

  if (temperatura >= 28.0) {
    digitalWrite(FAN, HIGH);
    Serial.println("Temperatura alta. Ventilador ENCENDIDO.");
  } else {
    digitalWrite(FAN, LOW);
    Serial.println("Temperatura normal. Ventilador APAGADO.");
  }
}
