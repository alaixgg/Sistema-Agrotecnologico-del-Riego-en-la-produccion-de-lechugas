// Según el valor arrojado por el sensor:
// 0 ~ 300: suelo seco
// 300 ~ 700: suelo húmedo
// 700 ~ 950: en agua

int segmentos[7] = {23, 22, 21, 19, 18, 19, 5};
const int pinH = 26;
int valorSensorHumedad = 0; // sensor de humedad

void setup()
{
    Serial.begin(115200);

}

void loop()
{
    valorSensorHumedad = analogRead(pinH);
    Serial.print("Valor del sensor:  ");
    Serial.println(valorSensorHumedad);
    //delay(1000);

    if (valorSensorHumedad < 300)
    {
        Serial.print("La lechuga necesita agua ");
        Serial.print(valorSensorHumedad);
        Serial.println(" Riegue hasta llegar a un valor aproximado de 400-600");
      
    
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
