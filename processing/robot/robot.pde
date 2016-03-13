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

import com.leapmotion.leap.*; //leap motion library
import processing.serial.*; //serial communication library
/**
 * Contrôle des diodes à l'aide de la classe Gesture
 */
Controller leap; //define a controller
Serial port; //define a port

boolean debug = false;

void setup() {
  size(250, 250); //sketch size
  leap = new Controller(); // initialize the controller
  // Activation des gestes (swipe)
  leap.enableGesture(Gesture.Type.TYPE_SWIPE);

  if (!debug)
    port = new Serial(this, Serial.list()[0], 115200);//initialize the port
} 

void draw() {
  if (leap.isConnected()) {
    //GestureList gestures = leap.frame().gestures();
    Hand firstHand = leap.frame().hands().get(0);
    FingerList fingers = leap.frame().fingers().extended(); //finger list to get the fingers count
    int count = fingers.count(); // integer holds the count of fingers

    ///////////////////////////////////////
    // Gestion des diodes et des moteurs //
    ///////////////////////////////////////
    if (firstHand.isValid() && fingers.count() == 5 && !debug) {
      // On récupère les coordonées du centre de la main
      Vector handCenter = firstHand.palmPosition();
      port.write(1);

      if (!debug) {
        println ("X : " + handCenter.getX() + " Z : " + handCenter.getZ());
        if (handCenter.getX() > 90) { // Droite
          port.write(2);
        } else if (handCenter.getX() < -90) { // Gauche
          port.write(3);
        } else if (handCenter.getZ() < -90) { // Haut
          port.write(4);
        } else if (handCenter.getZ() > 90) { // Bas
          port.write(5);
        } else {
          port.write(6); // Arrêt
        }
      } else {
        port.write(6);
      }
    } else {
      port.write(0);
      port.write(6);
    }

    background(0);  // box background color
    fill(255); // text color
    textSize(height/2); // text size
    text(count, 90, 160); // text value and position on the box
  }
}