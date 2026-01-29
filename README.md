# 🎆 Arduino LED-Feuerwerk
[Video](https://www.youtube.com/shorts/s51IdnM4YNw)

Ein **einfaches** Feuerwerk für eine 8x8 WS2812 LED-Matrix!


![Ohne Titel 1-1](https://github.com/user-attachments/assets/c25ef753-0153-4813-a7fd-2a2a3b4ca275)


## ⚙️Hardware
- 8x8 WS2812-LED-Matrix
- ESP32 (hier verwendet der ESP32 WROOM)

  
## ✨ Was passiert?
1. Weiße Rakete steigt von einem zufälligen Punkt hoch.
2. Bei Zielpunkt: bunte Explosion (Raute bei 8x8 Pixeln)
3. Neustart
---

## 📥Installation
1. FastLED Libaray installieren
2. Matrix mit dem Board verbinden
3. Code hochladen :)

## 🔧Code-Anpassungen
```cpp
#define Pin 2 // Anschluss der LED Matrix an den ESP
#define anzahlLED 64 // Anzahl der verfügbaren LEDs
#define breite 8 // Matrix Breite
#define hoehe 8 // Matrix Höhe
    
