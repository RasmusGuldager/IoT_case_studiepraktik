// Håndterer WiFi og webserver som et Access Point (AP)

#include <WiFi.h>
#include <WebServer.h>

const char* apSSID = "gruppe_xx";       // Navnet på ESP WiFi
const char* apPassword = "12345678";    // Minimum 8 karakterer

WebServer server(80);
char[]* lastCommand;

void handleRoot() {}

void handleOn() {}

void handleOff() {}

void initWiFiAndServer() {}

char[]* getWebCommand() {}

void handleClient() {}

