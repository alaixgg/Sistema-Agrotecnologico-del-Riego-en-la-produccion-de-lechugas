#include <WiFi.h>
#include <SMTPClient.h>

#define ADC_VREF_mV    3300.0 // en milivoltios
#define ADC_RESOLUTION 4096.0
#define PIN_LM35       27

// Credenciales de WiFi
const char* ssid = "iPhone de Andres(2)";
const char* password = "LechugaTadeista";

// Configuración del servidor SMTP de Gmail
const char* smtpServer = "smtp.gmail.com";
const uint16_t smtpPort = 587; // Gmail utiliza el puerto 587 con TLS

// Credenciales de la cuenta de correo electrónico de Gmail
const char* emailEnvio = "lechugatadeista@gmail.com";
const char* emailPassword = "SistemaAgrotecnologico";

float valorSensorHumedad = 34; // valor inicial del sensor de humedad
const int pinBombaAgua = 12; // Pin de control de la bomba de agua

int segmentos[7] = {23, 22, 21, 19, 18, 19, 5};
int dig[4] = {32, 33, 15, 4};

int displayH2O[3][7] = {
    {0, 1, 1, 0, 1, 1, 1}, // H
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 1, 1, 0}  // 0
};

int displaygood[4][7] = {
    {1, 0, 1, 1, 1, 1, 1}, // G
    {0, 0, 1, 1, 1, 0, 1}, // o
    {1, 1, 0, 1, 1, 1, 1}, // o
    {0, 1, 1, 1, 1, 0, 1}  // d
};

int displaymuch[4][7] = {
    {1, 0, 0, 1, 1, 1, 1}, // m
    {0, 0, 1, 1, 1, 0, 0}, // u
    {0, 0, 0, 1, 1, 0, 1}, // C
    {0, 0, 1, 0, 1, 1, 1}  // h
};

int displayerro[4][7] = {
    {1, 0, 0, 1, 1, 1, 1}, // e
    {0, 0, 0, 0, 1, 0, 1}, // r
    {0, 0, 0, 0, 1, 0, 1}, // r
    {1, 1, 0, 1, 1, 1, 1}  // o
};

SMTPClient smtp;

void sendEmail(const char* subject, const char* message) {
  smtp.beginMessage(emailEnvio, "alaixgg@gmail.com", subject);
  smtp.println(message);
  smtp.endMessage();
}

void setup() {
  Serial.begin(115200);

  // Conexión a WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  Serial.println("Conectado a WiFi");

  // Configuración del cliente SMTP
  smtp.begin(smtpServer, smtpPort, emailEnvio, emailPassword);

  // Configurar el pin de la bomba de agua como salida
  pinMode(pinBombaAgua, OUTPUT);

  // Configurar pines de segmentos como salidas
  for (int i = 0; i < 7; i++) {
    pinMode(segmentos[i], OUTPUT);
  }

  // Configurar pines de dígitos como salidas
  for (int k = 0; k < 4; k++) {
    pinMode(dig[k], OUTPUT);
    digitalWrite(dig[k], 1);
  }
}

void displayMatrix(int matrix[4][7]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 7; j++) {
      digitalWrite(segmentos[j], matrix[i][j]);
    }
    digitalWrite(dig[i], 0);
    delay(5);
    digitalWrite(dig[i], 1);
  }
}

void loop() {
  // Leer el valor del sensor de humedad
  // Supongamos que el valor del sensor se actualiza continuamente
  valorSensorHumedad = analogRead(34);

  Serial.print("Valor del sensor de humedad: ");
  Serial.println(valorSensorHumedad);

  if (valorSensorHumedad < 300) {
    sendEmail("Tu Lechuga te necesita :c", "Tu lechuga necesita agua. Riegue hasta llegar a un valor aproximado de 400-600");
    displayMatrix(displayH2O);
    digitalWrite(pinBombaAgua, HIGH); // Activar la bomba de agua
    Serial.println("Activando bomba de agua...");
    delay(2000);
    digitalWrite(pinBombaAgua, LOW); // Desactivar la bomba de agua
    Serial.println("Desactivando bomba de agua...");
  } else if (valorSensorHumedad >= 300 && valorSensorHumedad < 700) {
    sendEmail("Tu Lechuga esta feliz :D", "Tu lechuga tiene suficiente agua. Mantenga la humedad de la planta en un valor entre 400-600");
    displayMatrix(displaygood);
  } else if (valorSensorHumedad >= 700 && valorSensorHumedad < 951) {
    sendEmail("Tu Lechuga te necesita :c", "Tu lechuga tiene mucha agua. Exponga la planta a la luz solar para evitar que muera");
    displayMatrix(displaymuch);
  } else {
    sendEmail("Tu Lechuga esta bugeada xd", "Tu lechuga tiene un Silverfish");
    displayMatrix(displayerro);
  }

  delay(10000); // Esperar 10 segundos antes de la siguiente lectura
}
