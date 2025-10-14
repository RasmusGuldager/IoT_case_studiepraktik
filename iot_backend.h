// iot_backend.h
// ----------------------------------------------------
// Håndterer WiFi og webserver som et Access Point (AP)

#include <WiFi.h>
#include <WebServer.h>

const char* apSSID = "gruppe_xx";       // Navnet på ESP WiFi
const char* apPassword = "12345678";    // Minimum 8 karakterer

WebServer server(80);
String lastCommand = "";

void handleRoot() {
  String html = "<h1>IoT Light Control</h1>"
                "<button onclick=\"fetch('/on')\">Tænd</button>"
                "<button onclick=\"fetch('/off')\">Sluk</button>";
  server.send(200, "text/html", html);
}

void handleOn() {
  lastCommand = "ON";
  server.send(200, "text/plain", "OK");
}

void handleOff() {
  lastCommand = "OFF";
  server.send(200, "text/plain", "OK");
}

void initWiFiAndServer() {
  Serial.println("Starter ESP i Access Point mode...");
  
  WiFi.softAP(apSSID, apPassword);  // Starter AP
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP: ");
  Serial.println(IP);

  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);

  server.begin();
  Serial.println("Server startet i AP mode!");
}

String getWebCommand() {
  String cmd = lastCommand;
  lastCommand = "";  // Tøm beskeden efter brug
  return cmd;
}

void handleClient() {
  server.handleClient();
}
