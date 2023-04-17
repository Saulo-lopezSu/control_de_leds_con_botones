int leds[] = {2, 3, 4, 5, 6}; // Los pines de los LEDs
int delayTime = 200; // Tiempo de espera entre cambios de estado (en milisegundos)
int button1 = 7; // Pin del botón 1
int button2 = 8; // Pin del botón 2
int button3 = 9; // Pin del botón 3

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT); // Configurar los pines como salidas
  }
  pinMode(button1, INPUT_PULLUP); // Configurar botón 1 como entrada con resistencia pull-up
  pinMode(button2, INPUT_PULLUP); // Configurar botón 2 como entrada con resistencia pull-up
  pinMode(button3, INPUT_PULLUP); // Configurar botón 3 como entrada con resistencia pull-up
}

void loop() {
  if (digitalRead(button1) == LOW) { // Si se presiona el botón 1
    // Encender los LEDs de derecha a izquierda
    for (int i = 0; i < 5; i++) {
      digitalWrite(leds[i], HIGH); // Encender el LED actual
      delay(delayTime); // Esperar un tiempo
      digitalWrite(leds[i], LOW); // Apagar el LED actual
    }
  } else if (digitalRead(button2) == LOW) { // Si se presiona el botón 2
    // Encender los LEDs de izquierda a derecha
    for (int i = 4; i >= 0; i--) {
      digitalWrite(leds[i], HIGH); // Encender el LED actual
      delay(delayTime); // Esperar un tiempo
      digitalWrite(leds[i], LOW); // Apagar el LED actual
    }
  } else if (digitalRead(button3) == LOW) { // Si se presiona el botón 3
    // Encender los LEDs como si se abriera una cortina
    for (int i = 0; i < 3; i++) {
      digitalWrite(leds[2-i], HIGH); // Encender el LED de la izquierda
      digitalWrite(leds[2+i], HIGH); // Encender el LED de la derecha
      delay(delayTime); // Esperar un tiempo
      digitalWrite(leds[2-i], LOW); // Apagar el LED de la izquierda
      digitalWrite(leds[2+i], LOW); // Apagar el LED de la derecha
    }
  }
}
