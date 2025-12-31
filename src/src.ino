//Benötigte Libaray
#include <FastLED.h>

#define Pin 2 // Anschluss der LED Matrix
#define anzahlLED 64 // Anzahl der verfügbaren LEDs
// Maße der Matrix in Pixel
#define breite 8 
#define hoehe 8

// Array von dem Datentyp CRGB, das die Farben jeder einzelnen LED speichert. Jeder Eintrag entspricht einer LED.
CRGB leds[anzahlLED];


// Funktion zur Umwandlung von Koordinanten in einen Index im leds-Array
int wandleKoordinatenInIndex(int x, int y) {
  return y * breite + x;
}

void setup() {
  // Initialisieren der Matrix, Pin, Farbraum, Array und Anzahl der LEDs
  FastLED.addLeds<WS2812, Pin, GRB>(leds, anzahlLED);
  // Hellichkeit(max:255)
  FastLED.setBrightness(40);
  FastLED.clear();
  //Die Matrix auf den gespeicherten Stand aktualisieren.
  FastLED.show();
}

void loop() {
   // Aufruf der Feuerwerkfunktion
  firework();
   // Pause zwischen Feuerwerken
  delay(200);  
}

void firework() {
  // Zufällige Startposition auf der X-Achse
  int StartX = random(2, breite - 2); 
  // Zufällige Höhe auf der Y-Achse
  int ZielhöheY = random(2, hoehe - 1);   

  // Mit einer Schleife wird die Rakete als weiße LED weiter nach oben gesetzt
  for (int i = 0; i <= ZielhöheY; i++) {
    FastLED.clear();
    // Eine LED wird weiß in der Reihe, in der sie gestartet ist und um 1 nach oben gesetzt
    leds[wandleKoordinatenInIndex(StartX, i)] = CRGB::White;      
    FastLED.show();
    // unterschiedliche Geschwindigkeiten der Rakete
    delay(random(70, 130));              
  }

  // Wenn die Zielhöhe erreicht ist, wird die Explosion gestartet.
  explosion(StartX, ZielhöheY);
}


void explosion(int StartX, int ZiehlHoeheY) {
  // Eine zufällige Farbe wird gewählt
  CRGB farbe = CHSV(random(255), 255, 255); 

  // Durch mehrere Schleifen wird eine Animation erstellt,
  // durch welche die Explosion von innen nach außen wächst

  // Kontrolliert die Größe der Explosion(sie wird von 1 auf 2 größer)
  for (int n = 1; n <= 2; n++) { 
    // Alle Pixel werden durchgegangen, um zu schauen, ob sie in Reichweite der Explosion liegen.
    for (int x = 0; x < breite; x++) {
      for (int y = 0; y < hoehe; y++) {

        int abstandX = x - StartX; // Abstand zur Explosionsmitte (horizontal)
        int abstandY = y - ZiehlHoeheY; // Abstand zur Explosionsmitte (vertikal)

        // Die LEDs, die benötigt werden, werden angeschaltet.
        if (abs(abstandX) + abs(abstandY) <= n) {
          leds[wandleKoordinatenInIndex(x, y)] = farbe;
        }
      }
    }

    FastLED.show();
    delay(100);
  }

}

