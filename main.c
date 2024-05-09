
// Según el valor arrojado por el sensor:
// 0 ~ 300: suelo seco
// 300 ~ 700: suelo húmedo
// 700 ~ 950: en agua

int segmentos[7] = {23, 22, 21, 19, 18, 19, 5};
const int pinH = 26;
int valorSensorHumedad = 0; // sensor de humedad
const int pinBombaAgua = 12; // Pin de control de la bomba de agua
int LDR = 14;
int luminusidad;

void setup()
{
  Serial.begin(115200);
  // Configurar el pin de la bomba de agua como salida
  pinMode(pinBombaAgua, OUTPUT);

  //Configurar el pin de la luminusidad como salida
  pinMode(LDR, INPUT);
}

void loop()
{
  //humedad
    valorSensorHumedad = analogRead(pinH);
    Serial.print("V
// Según el valor arrojado por el sensor:
// 0 ~ 300: suelo seco
// 300 ~ 700: suelo húmedo
// 700 ~ 950: en agua

//WIFI Correo
#include <WiFi.h>

#include <ESP_Mail_Client.h>

#define WIFI_SSID "iPhone de Andres"

#define WIFI_PASSWORD "LechugaTadeista"

#define SMTP_server "smtp.gmail.com"

#define SMTP_Port 465

#define sender_email "lechugatadeista@gmail.com"

#define sender_password "nndv axen atku xvwo"

#define Recipient_email "andresj.alaixp@utadeo.edu.co"

#define Recipient_name "Alaix"

SMTPSession smtp;

const int pinH = 26;
int valorSensorHumedad = 0; // sensor de humedad
const int pinBombaAgua = 12; // Pin de control de la bomba de agua
int LDR = 14;
int luminusidad;

float  tempC;
int tempPin = 27; 


void sendEmailMenor(){
  Serial.print("Connecting...");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED)

  { Serial.print(".");

    delay(200);

   }

  Serial.println("");

  Serial.println("WiFi connected.");

  Serial.println("IP address: ");

  Serial.println(WiFi.localIP());

  Serial.println();

  smtp.debug(1);

  ESP_Mail_Session session;

  session.server.host_name = SMTP_server ;

  session.server.port = SMTP_Port;

  session.login.email = sender_email;

  session.login.password = sender_password;

  session.login.user_domain = "";

  /* Declare the message class */

  SMTP_Message message;

  message.sender.name = "Lechuga Tadeista";

  message.sender.email = sender_email;

  message.subject = "¡Tu lechuga está pidiendo un poco de agua para poder crecer feliz y saludable!";

  message.addRecipient(Recipient_name,Recipient_email);

   //Send HTML message

  String htmlMsg = "<div style=\"color:#000000;\"><h1> El agua es vital para todas las plantas, incluida la lechuga, ya que les proporciona los nutrientes necesarios y les permite absorber los minerales del suelo. No te preocupes, el sistema ya la esta regando. Con un poco de cuidado extra, tu lechuga estará lozana y lista para ser disfrutada en tus ensaladas.</h1><p> Mail Generated from ESP32</p></div>";

  message.html.content = htmlMsg.c_str();

  message.html.content = htmlMsg.c_str();

  message.text.charSet = "us-ascii";

  message.html.transfer_encoding = Content_Transfer_Encoding::enc_7bit;

 /* //Send simple text message

  String textMsg = "How are you doing";

  message.text.content = textMsg.c_str();

  message.text.charSet = "us-ascii";

  message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;*/

  if (!smtp.connect(&session))

    return;

  if (!MailClient.sendMail(&smtp, &message))

    Serial.println("Error sending Email, " + smtp.errorReason());
}

void sendEmailBien(){
  Serial.print("Connecting...");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED)

  { Serial.print(".");

    delay(200);

   }

  Serial.println("");

  Serial.println("WiFi connected.");

  Serial.println("IP address: ");

  Serial.println(WiFi.localIP());

  Serial.println();

  smtp.debug(1);

  ESP_Mail_Session session;

  session.server.host_name = SMTP_server ;

  session.server.port = SMTP_Port;

  session.login.email = sender_email;

  session.login.password = sender_password;

  session.login.user_domain = "";

  /* Declare the message class */

  SMTP_Message message;

  message.sender.name = "Lechuga Tadeista";

  message.sender.email = sender_email;

  message.subject = "¡Excelente noticia! Tu lechuga ha sido regada y está feliz!";

  message.addRecipient(Recipient_name,Recipient_email);

   //Send HTML message

  String htmlMsg = "<div style=\"color:#000000;\"><h1> Tu lechuga tiene suficiente agua. Revisa que tenga sufiente agua el contenedor </h1><p> Mail Generated from ESP32</p></div>";

  message.html.content = htmlMsg.c_str();

  message.html.content = htmlMsg.c_str();

  message.text.charSet = "us-ascii";

  message.html.transfer_encoding = Content_Transfer_Encoding::enc_7bit;

 /* //Send simple text message

  String textMsg = "How are you doing";

  message.text.content = textMsg.c_str();

  message.text.charSet = "us-ascii";

  message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;*/

  if (!smtp.connect(&session))

    return;

  if (!MailClient.sendMail(&smtp, &message))

    Serial.println("Error sending Email, " + smtp.errorReason());
}

void sendEmailMucha(){
  Serial.print("Connecting...");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED)

  { Serial.print(".");

    delay(200);

   }

  Serial.println("");

  Serial.println("WiFi connected.");

  Serial.println("IP address: ");

  Serial.println(WiFi.localIP());

  Serial.println();

  smtp.debug(1);

  ESP_Mail_Session session;

  session.server.host_name = SMTP_server ;

  session.server.port = SMTP_Port;

  session.login.email = sender_email;

  session.login.password = sender_password;

  session.login.user_domain = "";

  /* Declare the message class */

  SMTP_Message message;

  message.sender.name = "Lechuga Tadeista";

  message.sender.email = sender_email;

  message.subject = "Tu lechuga está rebosante de agua después de haber sido regada.";

  message.addRecipient(Recipient_name,Recipient_email);

   //Send HTML message

  String htmlMsg = "<div style=\"color:#000000;\"><h1> ¡Qué bien cuidada está! Ahora tiene todo lo que necesita para crecer fuerte y fresca, exponla al la luz solar para evitar esta muera</h1><p> Mail Generated from ESP32</p></div>";

  message.html.content = htmlMsg.c_str();

  message.html.content = htmlMsg.c_str();

  message.text.charSet = "us-ascii";

  message.html.transfer_encoding = Content_Transfer_Encoding::enc_7bit;

 /* //Send simple text message

  String textMsg = "How are you doing";

  message.text.content = textMsg.c_str();

  message.text.charSet = "us-ascii";

  message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;*/

  if (!smtp.connect(&session))

    return;

  if (!MailClient.sendMail(&smtp, &message))

    Serial.println("Error sending Email, " + smtp.errorReason());
}

void sendEmailGoodLuz(){
  Serial.print("Connecting...");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED)

  { Serial.print(".");

    delay(200);

   }

  Serial.println("");

  Serial.println("WiFi connected.");

  Serial.println("IP address: ");

  Serial.println(WiFi.localIP());

  Serial.println();

  smtp.debug(1);

  ESP_Mail_Session session;

  session.server.host_name = SMTP_server ;

  session.server.port = SMTP_Port;

  session.login.email = sender_email;

  session.login.password = sender_password;

  session.login.user_domain = "";

  /* Declare the message class */

  SMTP_Message message;

  message.sender.name = "Lechuga Tadeista";

  message.sender.email = sender_email;

  message.subject = "¡Ey, Tu lechuga está realizando fotosíntesis, ¡qué maravilla!!";

  message.addRecipient(Recipient_name,Recipient_email);

   //Send HTML message

  String htmlMsg = "<div style=\"color:#000000;\"><h1> La fotosíntesis es un proceso vital para las plantas, mediante el cual convierten la luz solar en energía para crecer y desarrollarse. Así que sí, ¡siéntete orgulloso de cuidar tan bien de tu lechuga! Estás contribuyendo a su salud y bienestar, además de disfrutar de los beneficios de una alimentación fresca y natural.  </h1><p> Mail Generated from ESP32</p></div>";

  message.html.content = htmlMsg.c_str();

  message.html.content = htmlMsg.c_str();

  message.text.charSet = "us-ascii";

  message.html.transfer_encoding = Content_Transfer_Encoding::enc_7bit;

 /* //Send simple text message

  String textMsg = "How are you doing";

  message.text.content = textMsg.c_str();

  message.text.charSet = "us-ascii";

  message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;*/

  if (!smtp.connect(&session))

    return;

  if (!MailClient.sendMail(&smtp, &message))

    Serial.println("Error sending Email, " + smtp.errorReason());
}

void sendEmailBadLuz(){
  Serial.print("Connecting...");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED)

  { Serial.print(".");

    delay(200);

   }

  Serial.println("");

  Serial.println("WiFi connected.");

  Serial.println("IP address: ");

  Serial.println(WiFi.localIP());

  Serial.println();

  smtp.debug(1);

  ESP_Mail_Session session;

  session.server.host_name = SMTP_server ;

  session.server.port = SMTP_Port;

  session.login.email = sender_email;

  session.login.password = sender_password;

  session.login.user_domain = "";

  /* Declare the message class */

  SMTP_Message message;

  message.sender.name = "Lechuga Tadeista";

  message.sender.email = sender_email;

  message.subject = "¡Ey, tu lechuga necesita más luz para crecer grande y fuerte!";

  message.addRecipient(Recipient_name,Recipient_email);

   //Send HTML message

  String htmlMsg = "<div style=\"color:#000000;\"><h1> La luz es esencial para que las plantas realicen la fotosíntesis y puedan desarrollarse plenamente. No te preocupes, puedes ayudarla buscando un lugar más iluminado para colocarla o proporcionándole luz adicional  </h1><p> Mail Generated from ESP32</p></div>";

  message.html.content = htmlMsg.c_str();

  message.html.content = htmlMsg.c_str();

  message.text.charSet = "us-ascii";

  message.html.transfer_encoding = Content_Transfer_Encoding::enc_7bit;

 /* //Send simple text message

  String textMsg = "How are you doing";

  message.text.content = textMsg.c_str();

  message.text.charSet = "us-ascii";

  message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;*/

  if (!smtp.connect(&session))

    return;

  if (!MailClient.sendMail(&smtp, &message))

    Serial.println("Error sending Email, " + smtp.errorReason());
}
void sendEmailError(){
  Serial.print("Connecting...");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED)

  { Serial.print(".");

    delay(200);

   }

  Serial.println("");

  Serial.println("WiFi connected.");

  Serial.println("IP address: ");

  Serial.println(WiFi.localIP());

  Serial.println();

  smtp.debug(1);

  ESP_Mail_Session session;

  session.server.host_name = SMTP_server ;

  session.server.port = SMTP_Port;

  session.login.email = sender_email;

  session.login.password = sender_password;

  session.login.user_domain = "";

  /* Declare the message class */

  SMTP_Message message;

  message.sender.name = "Lechuga Tadeista";

  message.sender.email = sender_email;

  message.subject = "¡¿alo?Tu Lechuga tiene un bug xd!";

  message.addRecipient(Recipient_name,Recipient_email);

   //Send HTML message

  String htmlMsg = "<div style=\"color:#000000;\"><h1> Tu lechuga tiene un Silverfish, revisa el funcionamiento</h1><p> Mail Generated from ESP32</p></div>";

  message.html.content = htmlMsg.c_str();

  message.html.content = htmlMsg.c_str();

  message.text.charSet = "us-ascii";

  message.html.transfer_encoding = Content_Transfer_Encoding::enc_7bit;

 /* //Send simple text message

  String textMsg = "How are you doing";

  message.text.content = textMsg.c_str();

  message.text.charSet = "us-ascii";

  message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;*/

  if (!smtp.connect(&session))

    return;

  if (!MailClient.sendMail(&smtp, &message))

    Serial.println("Error sending Email, " + smtp.errorReason());
}

void setup()
{
  Serial.begin(115200);
  // Configurar el pin de la bomba de agua como salida
  pinMode(pinBombaAgua, OUTPUT);

  //Configurar el pin de la luminusidad como salida
  pinMode(LDR, INPUT);

    Serial.println();

  Serial.print("Connecting...");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED)

  { Serial.print(".");

    delay(200);

   }

  Serial.println("");

  Serial.println("WiFi connected.");

  Serial.println("IP address: ");

  Serial.println(WiFi.localIP());

  Serial.println();

  smtp.debug(1);

  ESP_Mail_Session session;

  session.server.host_name = SMTP_server ;

  session.server.port = SMTP_Port;

  session.login.email = sender_email;

  session.login.password = sender_password;

  session.login.user_domain = "";

  /* Declare the message class */

  SMTP_Message message;

  message.sender.name = "Lechuga Tadeista";

  message.sender.email = sender_email;

  message.subject = "¡La lechuga se a conectado de manera exitosa!";

  message.addRecipient(Recipient_name,Recipient_email);

   //Send HTML message

  String htmlMsg = "<div style=\"color:#000000;\"><h1> Ahora es una Smart lettuce </h1><p> Mail Generated from ESP32</p></div>";

  message.html.content = htmlMsg.c_str();

  message.html.content = htmlMsg.c_str();

  message.text.charSet = "us-ascii";

  message.html.transfer_encoding = Content_Transfer_Encoding::enc_7bit;

 /* //Send simple text message

  String textMsg = "How are you doing";

  message.text.content = textMsg.c_str();

  message.text.charSet = "us-ascii";

  message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;*/

  if (!smtp.connect(&session))

    return;

  if (!MailClient.sendMail(&smtp, &message))

    Serial.println("Error sending Email, " + smtp.errorReason());

}

void loop()
{
    // Desconectar y apagar el módulo WiFi
  WiFi.disconnect(true);

  Serial.println("Módulo WiFi desactivado");

  //humedad
    valorSensorHumedad = analogRead(pinH);
    Serial.print("Valor del sensor de humedad:  ");
    Serial.println(valorSensorHumedad);
    
  // luminusidad
    luminusidad = analogRead(LDR);
    Serial.println("Valor del sensor de luminusidad:  ");
    Serial.println(luminusidad);

  //temperatura
     // Lee el valor desde el sensor
      tempC = analogRead(tempPin); 

      // Convierte el valor a temperatura
      tempC = (5.0 * tempC * 100.0)/1024.0; 

      // Envia el dato al puerto serial
      Serial.print(tempC);
      Serial.print(" °C");

    if (valorSensorHumedad < 300)
    {
        Serial.print("La lechuga necesita agua ");
        Serial.print(valorSensorHumedad);
        Serial.println(" Riegue hasta llegar a un valor aproximado de 400-600");
        digitalWrite(pinBombaAgua, HIGH); // Activar la bomba de agua
        Serial.println("Activando bomba de agua...");
        delay(2000);
        digitalWrite(pinBombaAgua, LOW); // Desactivar la bomba de agua
        sendEmailMenor();

    
    }
    
    else if (valorSensorHumedad >= 300 && valorSensorHumedad < 700)
    {
        Serial.print("La lechuga tiene suficiente agua ");
        Serial.print(valorSensorHumedad);
        Serial.println(" Mantenga la humedad de la planta en un valor entre 400-600");
        sendEmailBien();

      }
    
    else if (valorSensorHumedad >= 700 && valorSensorHumedad < 2000)
    {
        Serial.print("La lechuga tiene mucha agua, expongalo a la luz solar para evitar que la lechuga muera ");
        Serial.print(valorSensorHumedad);
        Serial.println(" Mantenga la humedad de la planta en un valor entre 400-600");
        sendEmailMucha();
    
    }
    else
    {
        Serial.print(valorSensorHumedad);
        Serial.println(" Compruebe el funcionamiento del sistema o el planta tiene excesiva agua");
        sendEmailError();
    }
//luz
    if (luminusidad < 2500)
    {
        Serial.print("La lechuga tiene buena luz");
        Serial.print(luminusidad);
        sendEmailGoodLuz();
    }
    
    else if (luminusidad >2501)
    {
        Serial.print("La lechuga necesita luz");
        Serial.print(luminusidad);
        Serial.println("Ponla al sol ");
        sendEmailBadLuz();
    }

    
    delay(10000); 
}alor del sensor de humedad:  ");
    Serial.println(valorSensorHumedad);
    
  // luminusidad
    luminusidad = analogRead(LDR);
    Serial.println("Valor del sensor de luminusidad:  ");
    Serial.println(luminusidad);


    if (valorSensorHumedad < 300)
    {
        Serial.print("La lechuga necesita agua ");
        Serial.print(valorSensorHumedad);
        Serial.println(" Riegue hasta llegar a un valor aproximado de 400-600");
        digitalWrite(pinBombaAgua, HIGH); // Activar la bomba de agua
        Serial.println("Activando bomba de agua...");
        delay(2000);
        digitalWrite(pinBombaAgua, LOW); // Desactivar la bomba de agua
      
    
    }
    
    else if (valorSensorHumedad >= 300 && valorSensorHumedad < 700)
    {
        Serial.print("La lechuga tiene suficiente agua ");
        Serial.print(valorSensorHumedad);
        Serial.println(" Mantenga la humedad de la planta en un valor entre 400-600");

      }
    
    else if (valorSensorHumedad >= 700 && valorSensorHumedad < 2000)
    {
        Serial.print("La lechuga tiene mucha agua, expongalo a la luz solar para evitar que la lechuga muera ");
        Serial.print(valorSensorHumedad);
        Serial.println(" Mantenga la humedad de la planta en un valor entre 400-600");
    
    
    }
    else
    {
        Serial.print(valorSensorHumedad);
        Serial.println(" Compruebe el funcionamiento del sistema o el planta tiene excesiva agua");

    }
    
    delay(1000); 
}
