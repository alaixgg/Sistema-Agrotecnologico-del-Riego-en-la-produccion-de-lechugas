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
  SMTP.begin(smtpServer, smtpPort, emailUsuario, emailPassword);
}

void loop() {
  // Enviar correo electrónico
  sendEmail();
  delay(5000); // Envía el correo cada 5 segundos
}

void sendEmail() {
  // Crear un mensaje de correo electrónico
  SMTP.beginMessage(emailEnvio, "alaixgg@gmail.com", "Tu Lechuga te necesita :c");
  SMTP.println("Tu lechuga necesita agua.");
  SMTP.endMessage();

  // Esperar unos segundos para que el correo se envíe correctamente
  delay(10000);
}
