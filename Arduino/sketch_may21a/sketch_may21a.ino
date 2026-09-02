int RELAY_PIN = 2;
 
 
void setup() {
  // put your setup code here, to run once:
    pinMode(RELAY_PIN, OUTPUT);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Relay ON");
  digitalWrite(RELAY_PIN, HIGH);
  delay(10000);
 
 
  Serial.println("Relay OFF");
  digitalWrite(RELAY_PIN, LOW);
  delay(10000);
   
}
