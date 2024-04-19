// Pin del sensor de humedad
float valorSensorHumedad = 14;

// Pin de control de la bomba de agua
const int pinBombaAgua = 12; 

void setup() {
  Serial.begin(115200);

  // Configurar pin de la bomba de agua como salida
  pinMode(pinBombaAgua, OUTPUT);
}

void loop() {
  // Leer el valor del sensor de humedad
  int valorSensorHumedad = analogRead(pinSensorHumedad);

  // Verificar si el suelo está seco (valor del sensor inferior a 400)
  if (valorSensorHumedad < 400) {
    // Activar la bomba de agua
    digitalWrite(pinBombaAgua, HIGH);
    Serial.println("Activando bomba de agua...");
  } else {
    // Desactivar la bomba de agua
    digitalWrite(pinBombaAgua, LOW);
    Serial.println("Desactivando bomba de agua...");
  }

  // Esperar unos segundos antes de leer el sensor de nuevo
  delay(600000);
}
