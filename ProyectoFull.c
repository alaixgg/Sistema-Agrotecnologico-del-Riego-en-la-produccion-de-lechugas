
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
    Serial.print("Valor del sensor de humedad:  ");
    Serial.println(valorSensorHumedad);
    
  // luminusidad
    luminusidad = analogRead(LDR);
    Serial.println("Valor del sensor:  ");
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
