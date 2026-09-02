#include <ESP8266WiFi.h>
#include <Wire.h>

#define RELAY_PIN D1
const char* password = "YOUR_WIFI_PASSWORD";
const char* ssid = "YOUR_WIFI_SSID";
const int port = 8181;

WiFiServer server(port);

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();

   Wire.begin(D1, D2);
}

void loop() {
  WiFiClient client = server.available();
  while(client.connected()) {
    if (client.available()) {
      uint8_t buf;
      size_t length = 1;
      client.read(&buf, length);
      client.write(handleCmd(buf));
    }
  }
}

char* handleCmd(uint8_t cmd) {
  Serial.println(cmd);
  switch(cmd) {
    case 49:
        sprinklerOneOn();
        return "Relay pin set to high\n";
    case 48:
        sprinklerOneOff();
        return "Relay pin set to low\n";
    default:
        return "Send ASCII 1 for on, and 0 for off.\n";
  }
}

void sprinklerOneOn() {
    Serial.print("sprinkler 1 turn on ...");
      Wire.beginTransmission(8); /* begin with device address 8 */
      Wire.write("0");  /* sends hello string */
      Wire.endTransmission();    /* stop transmitting */
}

void sprinklerOneOff() {
  Serial.print("sprinkler 1 turn off ...");
    Wire.beginTransmission(8); /* begin with device address 8 */
    Wire.write("1");  /* sends hello string */
    Wire.endTransmission();    /* stop transmitting */
}
