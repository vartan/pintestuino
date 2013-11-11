/* 
 * Title:   Arduino Pin Controller
 * Author:  Michael Vartan
 * E-mail:  admin@mvartan.com
 * Usage:   Input bits into serial monitor. If your startAt is 2, and you type
 *          "10110100", the pin outputs will look like this:
 *          Pin 2: HIGH    Pin 6: LOW
 *          Pin 3: LOW     Pin 7: HIGH
 *          Pin 4: HIGH    Pin 8: LOW
 *          Pin 5: HIGH    Pin 9: LOW
 */

int incomingByte = 0;   // for incoming serial data
String s = "00000000";  // initial pinout. 
int startAt = 2;        // first pin you are using. 2 is default.

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        for(int i=0;i<=14;i++)  // opens all digital pins; include 15-19 to
           pinMode(i, OUTPUT);  // include analog pins
}

void loop() {
  String content = "";
  char character;

  while(Serial.available()) {   //begin read serial
      character = Serial.read();
      content.concat(character);
      delay(10);                // you must wait to recieve next character.
  } //end read serial.

  if (content != "") { 
    Serial.println(content); // if we recieved input, send it back as feedback
    s=content;               // and remember it as variable s
  }

  for(int i=0;i<content.length();i++) {
    if(s[i]=='1')
      digitalWrite(startAt+i,HIGH); // set one high
        else
      digitalWrite(startAt+i,LOW);  // zero low
  }
}
