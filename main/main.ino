// Case: Tænd et lys over WiFi
// ----------------------------------------------------
// Denne kode styrer et LED-lys via en besked fra nettet.
// Alt netværkshåndtering ligger i iot_backend.h

int ledPin = 2;        // Pin til LED (kan ændres)
bool lightOn = false;  // Holder styr på status

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
  initWiFiAndServer();  // Starter WiFi access point
}


void loop() {
  String command = getWebCommand(); // Får besked fra nettet: "ON" / "OFF" fra iot_backend.h filen
  
  if (command == "ON") {
    digitalWrite(ledPin, HIGH);
    lightOn = true;
    Serial.println("Lyset er TÆNDT!");
  } 
  else if (command == "OFF") {
    digitalWrite(ledPin, LOW);
    lightOn = false;
    Serial.println("Lyset er SLUKKET!");
  }

  // Du kan udvide koden herunder

  



  handleClient(); // Holder serveren i live
}


