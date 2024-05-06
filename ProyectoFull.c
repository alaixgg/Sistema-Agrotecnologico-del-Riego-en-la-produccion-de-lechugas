// Según el valor arrojado por el sensor:
// 0 ~ 300: suelo seco
// 300 ~ 700: suelo húmedo
// 700 ~ 950: en agua
#include <WiFi.h>
#include <SMTPClient.h>
#define ADC_VREF_mV    3300.0 // en milivoltios
#define ADC_RESOLUTION 4096.0
#define PIN_LM35       27 //

// Credenciales de WiFi
const char* ssid = "iPhone de Andres(2)";
const char* password = "LechugaTadeista";

// Configuración del servidor SMTP de Gmail
const char* smtpServer = "smtp.gmail.com";
const uint16_t smtpPort = 587; // Gmail utiliza el puerto 587 con TLS

// Credenciales de la cuenta de correo electrónico de Gmail
const char* emailEnvio= "lechugatadeista@gmail.com";
const char* emailPassword = "SistemaAgrotecnologico";

float valorSensorHumedad = 34; // sensor de humedad
const int pinBombaAgua = 12; // Bomba de agua

int segmentos[7] = {23, 22, 21, 19, 18, 19, 5};

int dig[] = {32, 33, 15, 4};
int displayH2O[3][7] = {
    {0, 1, 1, 0, 1, 1, 1}, // H
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 1, 1, 0}, // 0
};
int displaygood[4][7] = {
    {1, 0, 1, 1, 1, 1, 1}, // G
    {0, 0, 1, 1, 1, 0, 1}, // o
    {1, 1, 0, 1, 1, 1, 1}, // o
    {0, 1, 1, 1, 1, 0, 1}, // d
};
int displaymuch[4][7] = {
    {1, 0, 0, 1, 1, 1, 1}, // m
    {0, 0, 1, 1, 1, 0, 0}, //u
    {0, 0, 0, 1, 1, 0, 1}, // C
    {0, 0, 1, 0, 1, 1, 1}, // h
};
int displayerro[4][7] = {
    {1, 0, 0, 1, 1, 1, 1},//e
    {0, 0, 0, 0, 1, 0, 1},//r
    {0, 0, 0, 0, 1, 0, 1},//r
    {1, 1, 0, 1, 1, 1, 1} // o        
};

void sendEmailMenor() {
  // Crear un mensaje de correo electrónico
  SMTP.beginMessage(emailEnvio, "alaixgg@gmail.com", "Tu Lechuga te necesita :c");
  SMTP.println("Tu lechuga necesita agua. Riegue hasta llegar a un valor aproximado de 400-600");
  SMTP.endMessage();


  delay(10000);

void sendEmailBien() {
  // Crear un mensaje de correo electrónico
  SMTP.beginMessage(emailEnvio, "alaixgg@gmail.com", "Tu Lechuga esta feliz :D");
  SMTP.println("Tu lechuga tiene suficiente agua, Mantenga la humedad de la planta en un valor entre 400-600 ");
  SMTP.endMessage();


  delay(10000);

void sendEmailMucho() {
  // Crear un mensaje de correo electrónico
  SMTP.beginMessage(emailEnvio, "alaixgg@gmail.com", "Tu Lechuga te necesita :c, ");
  SMTP.println("Tu lechuga tiene mucha agua, expongalo a la luz solar para evitar que la lechuga muera ");
  SMTP.endMessage();

  delay(10000);

void sendEmailError() {
  // Crear un mensaje de correo electrónico
  SMTP.beginMessage(emailEnvio, "alaixgg@gmail.com", "Tu Lechuga esta bugeada xd");
  SMTP.println("Tu lechuga tiene un Silverfish");
  SMTP.endMessage();


bool A, B, C, D, E, F, G = false; 

void setup()
{

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

  //Sensor de temperatura

  valorsensor = analogRead(potencimetro);
  voltaje = valorsensor * (3.3 / 4095);
  // leer el valor ADC del sensor de temperatura
  int adcVal = analogRead(PIN_LM35);
  // convertir el valor ADC a voltaje en milivoltios
  float milliVolt = adcVal * (ADC_VREF_mV / ADC_RESOLUTION);
  // convertir el voltaje a temperatura en °C
  float tempC = milliVolt / 10;

}  pinMode(pinBombaAgua, OUTPUT);

  for(int i = 0; i < 8; i++)
  {
    pinMode(segmentos[i], OUTPUT); 
    
  }
  for(int k = 0; k < 9 ; k++)
  {
    pinMode(dig[k], OUTPUT);
    digitalWrite(dig[k], 1);
  }
}

void loop()
{
    Serial.print("Temperatura ambiente: ");
    Serial.print(tempC);  

    Serial.print("Valor del sensor:");
    Serial.println(valorSensorHumedad);
    delay(10000);

    if (valorSensorHumedad < 300)
    {
      sendEmailMenor();
    // Activar la bomba de agua
    digitalWrite(pinBombaAgua, HIGH);
    Serial.println("Activando bomba de agua...");
    delay(2000)
    // Desactivar la bomba de agua
    digitalWrite(pinBombaAgua, LOW);
    Serial.println("Desactivando bomba de agua...");  
    }

    else if (valorSensorHumedad >= 300 && valorSensorHumedad < 700)
    {
      sendEmailBien();
      
    }

    else if (valorSensorHumedad >= 700 && valorSensorHumedad < 951)
    {
      sendEmailMucho();  
    }

    else
    {
     sendEmailError();   
    }

    delay(1000); 
}



