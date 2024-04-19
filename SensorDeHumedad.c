// Según el valor arrojado por el sensor:
// 0 ~ 300: suelo seco
// 300 ~ 700: suelo húmedo
// 700 ~ 950: en agua

int segmentos[7] = {23, 22, 21, 19, 18, 19, 5};
float valorSensorHumedad = 14; // Corregido el nombre de la variable
int dig[] = {32, 33, 15, 4};
int display[3][7] = {
    {0, 1, 1, 0, 1, 1, 1}, // H
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {1, 1, 1, 0, 1, 1, 0} // N
    {1, 1, 0, 1, 1, 1, 1} // e
    {1, 1, 0, 1, 1, 1, 1} // e
    {0, 1, 1, 1, 1, 0, 1} // d
    {1, 0, 0, 1, 1, 1, 1} // m
    {0, 0, 1, 1, 1, 0, 0 } //u
    {0, 0, 0, 1, 1, 0, 1} // C
    {0, 0, 1, 0, 1, 1, 1}, // h

    {
};

bool A, B, C, D, E, F, G = false; 

void setup()
{
    Serial.begin(57600);
}

void loop()
{
    Serial.print("Valor del sensor:");
    Serial.println(analogRead(A0));
    delay(1000);

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
    else if (valorSensorHumedad >= 700 && valorSensorHumedad < 950)
    {
        Serial.print("La lechuga tiene mucha agua, expongalo a la luz solar para evitar que la lechuga muera ");
        Serial.print(valorSensorHumedad);
        Serial.println(" Mantenga la humedad de la planta en un valor entre 400-600");
    }
    else
    {
        Serial.print(valorSensorHumedad);
        Serial.println(" Compruebe el funcionamiento del sistema");
    }

    delay(1000); 
}