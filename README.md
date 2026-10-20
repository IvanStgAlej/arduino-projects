# Arduino Projects (2021 – 2024)

🇪🇸 [Versión en español](README.es.md)

A collection of the electronics projects I have built with Arduino and ESP8266, **ordered by date**. Some of them I made several years before starting my vocational training in computing. The code is kept **exactly as I wrote it at the time**, so the repository also shows how my programming has improved since 2021.

> [!NOTE]
> Dates are the **last-modified dates** of each sketch file, so the real start of each project is the same or earlier. The latest stage of this story is the [NeoPixel Smart Clock](https://github.com/IvanStgAlej/neopixel-smart-clock) (2026), which has its own repository.

## Timeline

| Date | Project | Board | What it does | Key concepts |
|---|---|---|---|---|
| **Jan 2021** | [Piano](2021-01-piano/) | Arduino Uno / Nano | 8-key piano with 3 octaves, plus a pentatonic 5-key version | `tone()`, frequency tables, 2D arrays, `millis()` debounce |
| **Jun – Dec 2021** | [Lightsaber](2021-06-lightsaber/) (3 versions) | Arduino Uno | NeoPixel blade that ignites and retracts with a button; colour selector and rainbow effect | Adafruit NeoPixel, functions, state machine, colour wheel |
| **Jun 2022** | [Alexa-controlled LED](2022-06-alexa-led/) | ESP8266 NodeMCU | Turn an LED on and off with voice commands through Amazon Alexa | Wi-Fi, Espalexa, callbacks, reconnection |
| **Nov 2022 → Dec 2024** | [LED clock](2022-11-led-clock/) (3 versions) | Arduino Uno + DS1302 RTC | Clock with digits made of NeoPixel segments, HH:MM, on/off button | Real-time clock, **lookup tables**, partial redraw, debounce |
| **Jun 2024** | [Servo pedal](2024-06-servo-pedal/) | Arduino Uno | A button or pedal toggles a servo between two positions | Servo library, non-blocking debounce |
| 2026 | [NeoPixel Smart Clock ↗](https://github.com/IvanStgAlej/neopixel-smart-clock) | ESP8266 | Wi-Fi clock with NTP, MQTT, Home Assistant and OTA updates | IoT, MQTT, PlatformIO, CI |

## How my code evolved

The clock is the clearest example. The same problem, drawing a digit with LEDs, solved in three different ways over two years:

| Version | Date | Approach |
|---|---|---|
| [`clock_v0_digit_functions`](2022-11-led-clock/clock_v0_digit_functions/) | Nov 2022 | One function per digit (`cero()`, `uno()`…) and one line per LED. It works, but it is long and repetitive |
| [`clock_v1_lookup_table_prototype`](2022-11-led-clock/clock_v1_lookup_table_prototype/) | Dec 2022 | Prototype of a **lookup table**: `digitos[10][15]` stores which LEDs make up each number, and a single `pintar()` function draws any digit in any position |
| [`clock_v2_hhmm`](2022-11-led-clock/clock_v2_hhmm/) | Dec 2024 | Full HH:MM clock built on that table. It only redraws the digits that change and adds an on/off button with debounce and a status LED |

The lightsaber shows the same pattern: **v1** repeats `setPixelColor()` for each LED, **v2** replaces that with reusable `colorWipe` functions and loops, and **v3** adds a colour selector, an RGB indicator LED and a rainbow effect based on a colour wheel.

## Projects

### 🎹 Piano (January 2021)
- **[`piano`](2021-01-piano/piano/):** 8 push buttons play a C major scale through a buzzer with `tone()`. Two extra buttons move between 3 octaves, using a 2D frequency table and a 250 ms debounce based on `millis()`.
- **[`piano_pentatonic_nano`](2021-01-piano/piano_pentatonic_nano/):** a smaller version for an Arduino Nano with 5 keys (a C♯ pentatonic scale, the black keys of a piano) and LEDs that show the octave.

### ⚔️ Lightsaber (June – December 2021)
A NeoPixel strip acts as the blade, and pressing a button ignites or retracts it LED by LED.
- **[`lightsaber_v1`](2021-06-lightsaber/lightsaber_v1/)** (Jun 2021): 8 LEDs, one line of code per LED.
- **[`lightsaber_v3_colors`](2021-06-lightsaber/lightsaber_v3_colors/)** (Jun 2021): a second button cycles through green, blue, red, white and rainbow, and an RGB LED shows the selected colour.
- **[`lightsaber_v2_functions`](2021-06-lightsaber/lightsaber_v2_functions/)** (Dec 2021): a 40-LED blade, refactored with reusable `colorWipeON` and `colorWipeOFF` functions.

### 🗣️ Alexa-controlled LED (June 2022)
**[`alexa_led`](2022-06-alexa-led/alexa_led/)**: an ESP8266 registers itself as a smart device called "LED" with the Espalexa library, so Alexa can switch it on and off by voice. It reconnects to Wi-Fi automatically.

Wi-Fi credentials are not in the repository. Copy `secrets.example.h` to `secrets.h` and fill in your network.

### 🕐 LED clock (November 2022 – December 2024)
Each digit is built from 7 segments of 2 NeoPixels each (14 LEDs per digit, 56 LEDs for HH:MM), and the time comes from a DS1302 real-time clock module (`virtuabotixRTC` library). See [How my code evolved](#how-my-code-evolved) above.

The 3D-printed segments are based on a design by [matej_f on Thingiverse](https://www.thingiverse.com/matej_f/designs). The design files are not included.

### 🦶 Servo pedal (June 2024)
**[`servo_pedal`](2024-06-servo-pedal/servo_pedal/)**: each press of a button or pedal toggles a servo between 110° and 0°. It uses a non-blocking debounce, comparing timestamps with `millis()` instead of using `delay()`.

## Running the sketches

1. Open the folder of a sketch in the [Arduino IDE](https://www.arduino.cc/en/software). Each `.ino` is inside a folder with the same name, as the IDE requires.
2. Install the libraries the sketch uses from the Library Manager: **Adafruit NeoPixel**, **virtuabotixRTC** (DS1302), **Espalexa** and the **ESP8266 board package**. `Servo` comes with the IDE.
3. Check the pin numbers at the top of the sketch and upload it.

## License

© 2021–2024 Iván Santiago Alejano. Licensed under the [PolyForm Noncommercial License 1.0.0](LICENSE): free for personal, educational and other non-commercial use.
