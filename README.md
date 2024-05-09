##  Descripción:
  Este código está diseñado para monitorear y controlar las condiciones de crecimiento de una planta, específicamente una lechuga, utilizando un microcontrolador ESP32. 
  El sistema incorpora sensores de humedad del suelo, luminosidad y temperatura para determinar las condiciones ambientales y el estado de la planta.
  Basado en los valores de los sensores, el sistema activa una bomba de agua para regar la planta automáticamente y envía correos electrónicos informativos al usuario para notificar el estado de la planta.
## Requisitos

- Placa de desarrollo ESP32
- Sensores de humedad del suelo, luminosidad y temperatura
- Bomba de agua
- Biblioteca ESP_Mail_Client para el manejo de correos electrónicos
  
##  Dependencias:
  - ESP32
  - Biblioteca ESP_Mail_Client para el manejo de correos electrónicos
  - Sensores de humedad del suelo, luminosidad y temperatura

 ## Conexiones:
  - Sensor de humedad del suelo conectado al pin analógico 26 (pinH)
  - Bomba de agua conectada al pin digital 12 (pinBombaAgua)
  - Sensor de luminosidad conectado al pin analógico 14 (LDR)
  - Sensor de temperatura conectado al pin analógico 27 (tempPin)

## Sensores y Interpretación

### Sensor de Humedad del Suelo (pinH):

- **Valores Normales:** Los valores normales pueden variar dependiendo del tipo de suelo y de la planta, pero típicamente oscilan entre 0 y 1023 en una escala analógica.
- **Interpretación en el Código:**
  - Menor que 300: Indica que el suelo está seco y la planta necesita ser regada.
  - Entre 300 y 700: Indica que el suelo está húmedo y la planta tiene suficiente agua.
  - Mayor que 700: Indica que el suelo está encharcado y la planta tiene demasiada agua.

### Sensor de Luminosidad (LDR):

- **Valores Normales:** Los valores pueden variar dependiendo de la intensidad de la luz ambiente y del entorno de la planta, pero típicamente oscilan entre 0 y 4095 en una escala analógica.
- **Interpretación en el Código:**
  - Menor que 2500: Indica que la planta está recibiendo suficiente luz.
  - Mayor que 2500: Indica que la planta necesita más luz y se recomienda exponerla a la luz solar directa.

### Sensor de Temperatura (tempPin):

- **Valores Normales:** Los valores pueden variar dependiendo de la temperatura ambiente, pero típicamente se expresan en grados Celsius.
- **Interpretación en el Código:**
  - El valor leído se convierte en temperatura en grados Celsius y se imprime en el puerto serial. No se utiliza para tomar decisiones de control en este código, pero puede ser útil para monitorear las condiciones ambientales.

## Detalles del Código:

  - Se incluyen las bibliotecas necesarias: WiFi para la conexión a la red, y ESP_Mail_Client para el envío de correos electrónicos.

  - Se definen las constantes para la configuración de la red WiFi y el servidor SMTP, así como las credenciales de correo electrónico del remitente y el destinatario.

  - Se declaran las variables y objetos necesarios para el funcionamiento del sistema, como el objeto SMTPSession para la conexión al servidor SMTP, y variables para almacenar lecturas de sensores y configuraciones de pines.

  - Se definen funciones para enviar correos electrónicos en diferentes situaciones, como cuando la planta necesita agua, tiene suficiente agua, tiene demasiada agua, necesita más luz, etc.

  - En la función setup(), se inicializa el puerto serial, se configuran los pines de entrada y salida, se establece la conexión WiFi y se envía un correo electrónico de notificación al usuario para informar que la lechuga se ha conectado correctamente.

  - En la función loop(), se realizan las siguientes operaciones en cada iteración:
    - Se desconecta y apaga el módulo WiFi para ahorrar energía.
    - Se leen los valores de los sensores de humedad del suelo y luminosidad.
    - Se controlan las condiciones de la planta basadas en los valores de los sensores, activando la bomba de agua si es necesario y enviando correos electrónicos informativos al usuario.
    - Se espera un intervalo de tiempo antes de realizar la siguiente iteración para evitar un consumo excesivo de energía.

  ## Autor: (alaixgg)

  Fecha de Creación: abril 2024

  Última Modificación: 9 de mayo 2024

  ## Licencia

Este proyecto está bajo la [Licencia MIT](https://opensource.org/licenses/MIT).
