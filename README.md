Reloj Digital con FreeRTOS y LCD

Este proyecto implementa un reloj digital utilizando Arduino, FreeRTOS y una pantalla LCD. El programa permite visualizar el tiempo en formato HH:MM:SS, 
incrementar la hora y los minutos mediante botones y manejar múltiples tareas concurrentes utilizando FreeRTOS.

Características
Pantalla LCD: Visualiza el tiempo en formato HH:MM:SS.
Botones: Permiten incrementar los minutos y las horas.
FreeRTOS: Manejo de tareas concurrentes para la lógica del tiempo, el manejo de los botones y la actualización de la pantalla.

Tecnologías utilizadas
Arduino: Microcontrolador utilizado para el desarrollo del reloj.
FreeRTOS: Sistema operativo en tiempo real para manejo de tareas.
LiquidCrystal: Librería para controlar pantallas LCD.

Requisitos del sistema
Hardware:
Arduino UNO o compatible.
Pantalla LCD (16x2).
Dos botones pulsadores.
Resistencia de 10kΩ para cada botón (pull-down).
Software:
Arduino IDE.
Librería Arduino_FreeRTOS instalada.

Configuración del hardware
Conecta la pantalla LCD a los pines digitales de Arduino según la configuración:
RS: Pin 12
E: Pin 10
D4: Pin 5
D5: Pin 4
D6: Pin 3
D7: Pin 2

Conecta los botones a los pines:
Botón de minutos: Pin 7
Botón de horas: Pin 8

>[!TIP]
>Usa resistencias de 10kΩ como pull-down en los botones para evitar lecturas erróneas.

Cómo funciona
Tareas principales
mostrar: Actualiza la pantalla LCD para mostrar la hora en formato HH:MM:SS.
tiempo: Lleva el conteo del tiempo, incrementando los segundos, minutos y horas.
cambio: Detecta pulsaciones en los botones para incrementar minutos o horas manualmente.
Detalles de las tareas
Formato de tiempo: La hora se muestra siempre en formato HH:MM:SS, con ceros a la izquierda si es necesario.

Botones:
Botón 1: Incrementa los minutos.
Botón 2: Incrementa las horas.

Instalación
Copia el código en un archivo dentro del Arduino IDE.
Instala la librería Arduino_FreeRTOS desde el gestor de librerías.
Conecta el hardware según la sección de configuración.
Carga el programa al Arduino.

Cómo usar
Conecta el Arduino a la alimentación.
Observa el tiempo en la pantalla LCD.
Usa los botones para ajustar la hora o los minutos:
Botón en pin 7: Incrementa los minutos.
Botón en pin 8: Incrementa las horas.

Autor: Jose Carmen MArtínez 
