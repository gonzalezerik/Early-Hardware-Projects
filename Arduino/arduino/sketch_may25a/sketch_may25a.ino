int RELAY_PIN = 2;
int RELAY_PIN2 = 3;
int RELAY_PIN3 = 4;
int RELAY_PIN4 = 5;

 
 
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
