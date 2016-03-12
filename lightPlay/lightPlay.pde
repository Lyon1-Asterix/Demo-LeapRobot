import com.leapmotion.leap.*; //leap motion library
import processing.serial.*; //serial communication library
/**
  * Contrôle des diodes à l'aide de la classe Gesture
  */
Controller leap; //define a controller
Serial port; //define a port

void setup(){
  size(250,250); //sketch size
  leap = new Controller(); // initialize the controller
  // Activation des gestes (fingers)
  leap.enableGesture(Gesture.Type.TYPE_CIRCLE);
  leap.enableGesture(Gesture.Type.TYPE_KEY_TAP);
  leap.enableGesture(Gesture.Type.TYPE_SCREEN_TAP);
  leap.enableGesture(Gesture.Type.TYPE_SWIPE);
  
  for (int i = 0; i < Serial.list().length; i++)
    println(Serial.list()[i]);
    
  //port = new Serial(this, Serial.list()[2], 115200);//initialize the port
} 

void draw(){
  if (leap.isConnected()) {
    GestureList gestures = leap.frame().gestures();
    for (int i = 0; i < gestures.count(); i++) {
       Gesture gesture = gestures.get(i);
       
       switch (gesture.type()) {
         case TYPE_CIRCLE:
           println ("circle");
           break;
         case TYPE_SWIPE:
           println("swipe");
           break;
         case TYPE_KEY_TAP:
           println("key tap");
           break;
         case TYPE_SCREEN_TAP:
           println("screen tap");
           break;
         case TYPE_INVALID:
           println("invalid");
           break;
       }
       
       //if (gesture.type() == Gesture.Type.TYPE_CIRCLE) {
         
       //     CircleGesture circle = new CircleGesture (gesture);
       //     if (circle.pointable().direction().angleTo(circle.normal()) <= Math.PI/4) {
       //       port.write(1); 
       //     } else {
       //       port.write(2); 
       //     }
       //}
      }
    }
    
    FingerList fingers = leap.frame().fingers().extended(); //finger list to get the fingers count
    int count = fingers.count(); // integer holds the count of fingers
    background(0);  // box background color
    fill(255); // text color
    textSize(height/2); // text size
    text(count, 90, 160); // text value and position on the box
  }