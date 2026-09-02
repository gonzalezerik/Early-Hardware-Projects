#include <SoftwareSerial.h>
#include <Wire.h>

int RELAY_PIN = 2;
int c = 0;
 
void setup() {
  // put your setup code here, to run once:
  
    Wire.begin(8);                /* join i2c bus with address 8 */
    Wire.onReceive(receiveEvent); /* register receive event */         
    pinMode(RELAY_PIN, OUTPUT);
    Serial.begin(9600);

}
 
void loop() {
  // put your main code here, to run repeatedly:
  if (c == 1){
    
  }
  if (c == 0){
    digitalWrite(RELAY_PIN, HIGH);
  }
  
  delay(100);

}





void receiveEvent() {
 
 while (0 <Wire.available()) {
     c = Wire.read();      /* receive byte as a character */
    
  }
    Serial.println(c); 
    if (c == 48){
        Serial.println("Relay ON");
        digitalWrite(RELAY_PIN, LOW);
        delay(100);
      }

      if (c == 49){
        Serial.println("Relay OFF");
        digitalWrite(RELAY_PIN, HIGH);
      }        /* to newline */
}
