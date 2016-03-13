/* Copyright 2016 Ghayth Bouagila & Hedi Nasr */

/* Licensed under the Apache License, Version 2.0 (the "License"); */
/* you may not use this file except in compliance with the License. */
/* You may obtain a copy of the License at */

/*     http://www.apache.org/licenses/LICENSE-2.0 */

/* Unless required by applicable law or agreed to in writing, software */
/* distributed under the License is distributed on an "AS IS" BASIS, */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. */
/* See the License for the specific language governing permissions and */
/* limitations under the License. */

int diode[8]; // pins pour les diodes
int moteur[4]; // pins pour les moteurs
int c = -1;

void setup() {
  Serial.begin(115200); //set serial with baud rate
  // initialisation des diodes
  for (int i = 0; i < 6; i++) {
    diode[i] = 2 + i;
  }

  diode[6] = 12;
  diode[7] = 13;

  // initialisation des moteurs
  moteur[0] = 5;
  moteur[1] = 6;
  moteur[2] = 10;
  moteur[3] = 11;

  for (int i = 0; i < 8; i++) {
    pinMode (diode[i], OUTPUT);
    pinMode (moteur[i % 4], OUTPUT);
    // RAZ des moteurs
    analogWrite (moteur[i % 4], 0);
    // RAZ des diodes
    digitalWrite (diode[i], LOW);
  }

  setup_bluetooth();
}

void loop() {
  if (Serial.available() > 0) {  //if we have incoming value
    c = Serial.read();

    switch (c) {
      // DIODES
      case 0 : // On éteint tout
        for (int i = 0; i < 10; i++) {
          digitalWrite (diode[i], LOW);
          delay (10);
        }
        break;

      case 1: // On allume tout
        for (int i = 0; i < 10; i++) {
          digitalWrite (diode[i], HIGH);
          delay (10);
        }
        break;
      // MOTEURS
      case 2: // Droite
        analogWrite (moteur[0], 200);
        analogWrite (moteur[1], 0);
        analogWrite (moteur[2], 0);
        analogWrite (moteur[3], 0);
        break;

      case 3: // Gauche
        analogWrite (moteur[0], 0);
        analogWrite (moteur[1], 0);
        analogWrite (moteur[2], 140);
        analogWrite (moteur[3], 0);
        break;

      case 4: // Haut
        analogWrite (moteur[0], 200);
        analogWrite (moteur[1], 0);
        analogWrite (moteur[2], 140);
        analogWrite (moteur[3], 0);
        break;

      case 5: // Bas
        analogWrite (moteur[0], 0);
        analogWrite (moteur[1], 200);
        analogWrite (moteur[2], 0);
        analogWrite (moteur[3], 140);
        break;

      case 6: // Arrêt
        analogWrite (moteur[0], 0);
        analogWrite (moteur[1], 0);
        analogWrite (moteur[2], 0);
        analogWrite (moteur[3], 0);
        break;

      default: break;

        //motor ();
    }
  }

  loop_bluetooth();
}
