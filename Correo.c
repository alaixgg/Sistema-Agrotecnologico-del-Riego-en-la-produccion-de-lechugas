#include <WiFi.h>
#include <SMTPClient.h>

// Credenciales de WiFi
const char* ssid = "iPhone de Andres(2)";
const char* password = "LechugaTadeista";

// Configuración del servidor SMTP de Gmail
const char* smtpServer = "smtp.gmail.com";
const uint16_t smtpPort = 587; // Gmail utiliza el puerto 587 con TLS

// Credenciales de la cuenta de correo electrónico de Gmail
const char* emailEnvio= "lechugatadeista@gmail.com";
const char* emailPassword = "SistemaAgrotecnologico";

// Pin del sensor de humedad
const int pinSensorHumedad = A0;

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
  SMTP.begin(smtpServer, smtpPort, emailEnvio, emailPassword);
}

void loop() {
  // Leer el valor del sensor de humedad
  int valorSensorHumedad = analogRead(pinSensorHumedad);

  // Enviar correo electrónico si el valor del sensor de humedad es bajo (suelo seco)
  if (valorSensorHumedad < 300) {
    sendEmailMenor();
  }

  delay(5000); // Esperar 5 segundos antes de leer el sensor de nuevo
}

else if (valorSensorHumedad >= 300 && valorSensorHumedad < 700)
  {
  sendEmailBien();
  }
  
else if (valorSensorHumedad >= 700 && valorSensorHumedad < 950)
  {
    sendEmailMucho();  
  }

else
  {
    sendEmailError();  
  }

void sendEmailMenor() {
  // Crear un mensaje de correo electrónico
  SMTP.beginMessage(emailEnvio, "alaixgg@gmail.com", "Tu Lechuga te necesita :c");
  SMTP.println("Tu lechuga necesita agua.");
  SMTP.endMessage();

  // Esperar unos segundos para que el correo se envíe correctamente
  delay(10000);

void sendEmailBien() {
  // Crear un mensaje de correo electrónico
  SMTP.beginMessage(emailEnvio, "alaixgg@gmail.com", "Tu Lechuga esta feliz :D");
  SMTP.println("Tu lechuga tiene suficiente agua.");
  SMTP.endMessage();

  // Esperar unos segundos para que el correo se envíe correctamente
  delay(10000);

void sendEmailMucho() {
  // Crear un mensaje de correo electrónico
  SMTP.beginMessage(emailEnvio, "alaixgg@gmail.com", "Tu Lechuga te necesita :c");
  SMTP.println("Tu lechuga tiene mucha agua");
  SMTP.endMessage();

  // Esperar unos segundos para que el correo se envíe correctamente
  delay(10000);

void sendEmailError() {
  // Crear un mensaje de correo electrónico
  SMTP.beginMessage(emailEnvio, "alaixgg@gmail.com", "Tu Lechuga tiene un bug xd");
  SMTP.println("Tu lechuga tiene un Silverfish");
  SMTP.endMessage();

  // Esperar unos segundos para que el correo se envíe correctamente
  delay(10000);
}
