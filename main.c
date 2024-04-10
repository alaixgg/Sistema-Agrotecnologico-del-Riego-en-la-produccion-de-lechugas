
#define ADC_VREF_mV    3300.0 // in millivolt
#define ADC_RESOLUTION 4096.0

int segmentos[7] = {23,22,21,19,18,19,5};
#define PIN_LM35 4
float valorsensor;
int dig[] = {32,33,15,4};
int num[10][7]={
             {1,1,1,1,1,1,0},//0
             {0,1,1,0,0,0,0},//1
             {1,1,0,1,1,0,1},//2
             {1,1,1,1,0,0,1},//3
             {0,1,1,0,0,1,1},//4
             {1,0,1,1,0,1,1},//5
             {1,0,1,1,1,1,1},//6
             {1,1,1,0,0,0,0},//7
             {1,1,1,1,1,1,1},//8
             {1,1,1,0,0,1,1},//9
};

bool A,B,C,D,E,F,G = 0; 


void setup() {
  Serial.begin(115200);
  
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

void loop() {
    //medirTemperatura();
      int voltaje = valorsensor*(3.3/4095);
      // read the ADC value from the temperature sensor
      int adcVal = analogRead(PIN_LM35);
      // convert the ADC value to voltage in millivolt
      float milliVolt = adcVal * (ADC_VREF_mV / ADC_RESOLUTION);
      // convert the voltage to the temperature in °C
      float tempC = milliVolt / 10;
      // convert the °C to °F
      float tempF = tempC * 9 / 5 + 32;
      float diferencia = valorsensor - tempC;

      // print the temperature in the Serial Monitor:
      Serial.print("Temperature: ");
      Serial.print(tempC);   // print the temperature in °C
      Serial.print("°C");
      Serial.print("  ~  "); // separator between °C and °F
      Serial.print(tempF); 
      Serial.println("°F");
      // print the temperature in °F
      Serial.println("Voltaje");

      Serial.print(valorsensor);
      //

  int decena= tempC/10;
  int unidad= (tempC-(decena*10));
  int decimal(tempC*10-(decena*10*100+unidad*10));
  int valor[3] = {decena,unidad,decimal};
  for (int j = 0; j < 3; j++) {

  }
  for (int j = 0; j <3; j++) {
    for (int s = 0; s < 7; s++) {
      digitalWrite(segmentos[s], num[valor[j]][s]);
    }
    digitalWrite(dig[j], LOW);
    delay(10);
    digitalWrite(dig[j], HIGH);
  }
}