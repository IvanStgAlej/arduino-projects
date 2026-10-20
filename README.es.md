# Proyectos de Arduino (2021 – 2024)

🇬🇧 [English version](README.md)

Colección de los proyectos de electrónica que he hecho con Arduino y ESP8266, **ordenados por fecha**. Algunos los hice varios años antes de empezar a estudiar informática en FP. El código está **tal y como lo escribí en su momento**, así que el repositorio también enseña cómo ha mejorado mi forma de programar desde 2021.

> [!NOTE]
> Las fechas son las de **última modificación** de cada sketch, así que cada proyecto empezó ese mismo día o antes. La última etapa de esta historia es el [Reloj NeoPixel inteligente](https://github.com/IvanStgAlej/neopixel-smart-clock) (2026), que tiene su propio repositorio.

## Cronología

| Fecha | Proyecto | Placa | Qué hace | Conceptos clave |
|---|---|---|---|---|
| **ene 2021** | [Piano](2021-01-piano/) | Arduino Uno / Nano | Piano de 8 teclas con 3 octavas y una versión pentatónica de 5 teclas | `tone()`, tablas de frecuencias, arrays 2D, antirrebote con `millis()` |
| **jun – dic 2021** | [Espada láser](2021-06-lightsaber/) (3 versiones) | Arduino Uno | Hoja de LEDs NeoPixel que se enciende y se apaga con un botón; selector de color y efecto arcoíris | Adafruit NeoPixel, funciones, máquina de estados, rueda de color |
| **jun 2022** | [LED controlado por Alexa](2022-06-alexa-led/) | ESP8266 NodeMCU | Enciende y apaga un LED con la voz a través de Amazon Alexa | Wi-Fi, Espalexa, callbacks, reconexión |
| **nov 2022 → dic 2024** | [Reloj de LEDs](2022-11-led-clock/) (3 versiones) | Arduino Uno + RTC DS1302 | Reloj con dígitos hechos de segmentos NeoPixel, HH:MM y botón de encendido | Reloj de tiempo real, **tablas de búsqueda**, redibujado parcial, antirrebote |
| **jun 2024** | [Pedal con servo](2024-06-servo-pedal/) | Arduino Uno | Un botón o pedal mueve un servo entre dos posiciones | Librería Servo, antirrebote sin bloquear |
| 2026 | [Reloj NeoPixel inteligente ↗](https://github.com/IvanStgAlej/neopixel-smart-clock) | ESP8266 | Reloj Wi-Fi con NTP, MQTT, Home Assistant y actualizaciones OTA | IoT, MQTT, PlatformIO, CI |

## Cómo ha evolucionado mi código

El reloj es el ejemplo más claro. El mismo problema, dibujar un número con LEDs, resuelto de tres formas distintas a lo largo de dos años:

| Versión | Fecha | Enfoque |
|---|---|---|
| [`clock_v0_digit_functions`](2022-11-led-clock/clock_v0_digit_functions/) | nov 2022 | Una función por número (`cero()`, `uno()`…) y una línea por cada LED. Funciona, pero es largo y repetitivo |
| [`clock_v1_lookup_table_prototype`](2022-11-led-clock/clock_v1_lookup_table_prototype/) | dic 2022 | Prototipo de **tabla de búsqueda**: `digitos[10][15]` guarda qué LEDs forman cada número, y una sola función `pintar()` dibuja cualquier número en cualquier posición |
| [`clock_v2_hhmm`](2022-11-led-clock/clock_v2_hhmm/) | dic 2024 | Reloj HH:MM completo basado en esa tabla. Solo redibuja los dígitos que cambian y añade un botón de encendido con antirrebote y un LED de estado |

La espada láser sigue el mismo camino: la **v1** repite `setPixelColor()` para cada LED, la **v2** lo sustituye por funciones `colorWipe` reutilizables con bucles, y la **v3** añade un selector de color, un LED RGB indicador y un efecto arcoíris basado en una rueda de color.

## Proyectos

### 🎹 Piano (enero de 2021)
- **[`piano`](2021-01-piano/piano/):** 8 pulsadores tocan la escala de do mayor en un zumbador con `tone()`. Otros dos botones cambian entre 3 octavas, con una tabla de frecuencias 2D y un antirrebote de 250 ms basado en `millis()`.
- **[`piano_pentatonic_nano`](2021-01-piano/piano_pentatonic_nano/):** versión más pequeña para Arduino Nano con 5 teclas (escala pentatónica de do sostenido, las teclas negras del piano) y LEDs que indican la octava.

### ⚔️ Espada láser (junio – diciembre de 2021)
Una tira de LEDs NeoPixel hace de hoja, y al pulsar un botón se enciende o se apaga LED a LED.
- **[`lightsaber_v1`](2021-06-lightsaber/lightsaber_v1/)** (jun 2021): 8 LEDs, una línea de código por LED.
- **[`lightsaber_v3_colors`](2021-06-lightsaber/lightsaber_v3_colors/)** (jun 2021): un segundo botón cambia entre verde, azul, rojo, blanco y arcoíris, y un LED RGB muestra el color elegido.
- **[`lightsaber_v2_functions`](2021-06-lightsaber/lightsaber_v2_functions/)** (dic 2021): hoja de 40 LEDs, reescrita con funciones reutilizables `colorWipeON` y `colorWipeOFF`.

### 🗣️ LED controlado por Alexa (junio de 2022)
**[`alexa_led`](2022-06-alexa-led/alexa_led/)**: un ESP8266 se registra como un dispositivo inteligente llamado "LED" con la librería Espalexa, de modo que Alexa lo enciende y lo apaga por voz. Se reconecta al Wi-Fi automáticamente.

Las credenciales del Wi-Fi no están en el repositorio. Copia `secrets.example.h` como `secrets.h` y pon los datos de tu red.

### 🕐 Reloj de LEDs (noviembre de 2022 – diciembre de 2024)
Cada dígito está formado por 7 segmentos de 2 NeoPixels (14 LEDs por dígito, 56 LEDs para HH:MM), y la hora la da un módulo de reloj de tiempo real DS1302 (librería `virtuabotixRTC`). Consulta [Cómo ha evolucionado mi código](#cómo-ha-evolucionado-mi-código).

Los segmentos impresos en 3D se basan en un diseño de [matej_f en Thingiverse](https://www.thingiverse.com/matej_f/designs). Los archivos del diseño no están incluidos.

### 🦶 Pedal con servo (junio de 2024)
**[`servo_pedal`](2024-06-servo-pedal/servo_pedal/)**: cada pulsación de un botón o pedal mueve un servo entre 110° y 0°. Usa un antirrebote que no bloquea: compara tiempos con `millis()` en lugar de usar `delay()`.

## Cómo ejecutar los sketches

1. Abre la carpeta del sketch en el [Arduino IDE](https://www.arduino.cc/en/software). Cada `.ino` está dentro de una carpeta con su mismo nombre, como exige el IDE.
2. Instala desde el gestor de librerías las que use el sketch: **Adafruit NeoPixel**, **virtuabotixRTC** (DS1302), **Espalexa** y el **paquete de placas ESP8266**. `Servo` viene incluida en el IDE.
3. Revisa los pines al principio del sketch y súbelo a la placa.

## Licencia

© 2021–2024 Iván Santiago Alejano. Distribuido bajo la [PolyForm Noncommercial License 1.0.0](LICENSE): libre para uso personal, educativo y cualquier otro uso no comercial. El texto legal que tiene validez es el de la licencia original en inglés.
