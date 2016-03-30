// Client Leap Motion
import processing.net.*;
import processing.serial.*; //serial communication library

Client myClient;
Serial port; //define a port
String dataIn;
byte interesting = 10;

void setup () {
  //size(200, 200);
  myClient = new Client (this, "192.168.1.181", 2222);
  port = new Serial(this, Serial.list()[0], 115200);//initialize the port
}

void draw () {
  if (myClient.available() > 0) {
    dataIn = myClient.readStringUntil(interesting);
    if (dataIn != null) {
      switch (dataIn) {
      case "FORWARD\n": // forward
        println(dataIn);
        port.write(4);
        break;

      case "BACKWARD\n": // backward
        println(dataIn);
        port.write(5);
        break;

      case "RIGHT\n": // right
        println(dataIn);
        port.write(2);
        break;

      case "LEFT\n": // left
        println(dataIn);
        port.write(3);
        break;

      case "UNDEFINED\n": // stop
        println(dataIn);
        port.write(6);
        break;
      }
    }
  }
}