#include <WiFi.h>

#include <ESP_Mail_Client.h>

#define WIFI_SSID "iPhone de Andres"

#define WIFI_PASSWORD "LechugaTadeista"

#define SMTP_server "smtp.gmail.com"

#define SMTP_Port 465

#define sender_email "lechugatadeista@gmail.com"

#define sender_password "nndv axen atku xvwo"

#define Recipient_email "andresj.alaixp@utadeo.edu.co"

#define Recipient_name "Alaixgg"

SMTPSession smtp;

void setup(){

  Serial.begin(115200);

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

  message.sender.name = "Lechuga Inteligentisima";

  message.sender.email = sender_email;

  message.subject = "El ESP32 Ya funciona";

  message.addRecipient(Recipient_name,Recipient_email);

   //Send HTML message

  String htmlMsg = "<div style=\"color:#000000;\"><h1> Que felicidad, pongame 5.0!</h1><p> Mail Generated from ESP32</p></div>";

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

void loop(){

 

}
