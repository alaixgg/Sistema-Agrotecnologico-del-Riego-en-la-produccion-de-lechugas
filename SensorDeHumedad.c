// Según el valor arrojado por el sensor:
// 0 ~ 300: suelo seco
// 300 ~ 700: suelo húmedo
// 700 ~ 950: en agua

int segmentos[7] = {23, 22, 21, 19, 18, 19, 5};
float valorSensorHumedad = 34; // sensor de humedad
int dig[] = {32, 33, 15, 4};
int displayH2O[3][7] = {
    {0, 1, 1, 0, 1, 1, 1}, // H
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 1, 1, 0}, // 0
}
int displaygood[4][7] = {
    {1, 0, 1, 1, 1, 1, 1}, // G
    {0, 0, 1, 1, 1, 0, 1}, // o
    {1, 1, 0, 1, 1, 1, 1}, // o
    {0, 1, 1, 1, 1, 0, 1}, // d
}
int displaymuch[4][7] = {
    {1, 0, 0, 1, 1, 1, 1}, // m
    {0, 0, 1, 1, 1, 0, 0 }, //u
    {0, 0, 0, 1, 1, 0, 1}, // C
    {0, 0, 1, 0, 1, 1, 1}, // h
}
int displayerro[4][7] = {
    {1, 0, 0, 1, 1, 1, 1},//e
    {0, 0, 0, 0, 1, 0, 1},//r
    {0, 0, 0, 0, 1, 0, 1},//r
    {1, 1, 0, 1, 1, 1, 1} // o        
}

};

bool A, B, C, D, E, F, G = false; 

void setup()
{
    Serial.begin(57600);
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
    Serial.print("Valor del sensor:");
    Serial.println(valorSensorHumedad));
    delay(1000);

    if (valorSensorHumedad < 300)
    {
        Serial.print("La lechuga necesita agua ");
        Serial.print(valorSensorHumedad);
        Serial.println(" Riegue hasta llegar a un valor aproximado de 400-600");

        
      for (int j = 0; j < 8; j++) {
        digitalWrite(dig[j], HIGH);
      }
      for (int j = 0; j < 8; j++) {
        for (int s = 0; s < 5; s++) {
          digitalWrite(segmentos[s], displayH2O[j][s]);
        }
        digitalWrite(dig[j], LOW);
        delay(10);
        digitalWrite(dig[j], HIGH);
      }
        
    }
    else if (valorSensorHumedad >= 300 && valorSensorHumedad < 700)
    {
        Serial.print("La lechuga tiene suficiente agua ");
        Serial.print(valorSensorHumedad);
        Serial.println(" Mantenga la humedad de la planta en un valor entre 400-600");

      for (int j = 0; j < 8; j++) {
        digitalWrite(dig[j], HIGH);
      }
      for (int j = 0; j < 8; j++) {
        for (int s = 0; s < 5; s++) {
          digitalWrite(segmentos[s], displaygood[j][s]);
        }
        digitalWrite(dig[j], LOW);
        delay(10);
        digitalWrite(dig[j], HIGH);
      }
    }
    else if (valorSensorHumedad >= 700 && valorSensorHumedad < 950)
    {
        Serial.print("La lechuga tiene mucha agua, expongalo a la luz solar para evitar que la lechuga muera ");
        Serial.print(valorSensorHumedad);
        Serial.println(" Mantenga la humedad de la planta en un valor entre 400-600");

    for (int j = 0; j < 8; j++) {
        digitalWrite(dig[j], HIGH);
      }
      for (int j = 0; j < 8; j++) {
        for (int s = 0; s < 5; s++) {
          digitalWrite(segmentos[s], displaymuch[j][s]);
        }
        digitalWrite(dig[j], LOW);
        delay(10);
        digitalWrite(dig[j], HIGH);
      }
    }
    else
    {
        Serial.print(valorSensorHumedad);
        Serial.println(" Compruebe el funcionamiento del sistema");

    for (int j = 0; j < 8; j++) {
        digitalWrite(dig[j], HIGH);
      }
      for (int j = 0; j < 8; j++) {
        for (int s = 0; s < 5; s++) {
          digitalWrite(segmentos[s], displayerro[j][s]);
        }
        digitalWrite(dig[j], LOW);
        delay(10);
        digitalWrite(dig[j], HIGH);
      }
        
    }

    delay(1000); 
}
