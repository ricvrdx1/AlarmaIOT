#include <WiFi.h>
#include <HTTPClient.h>
#include <TinyGPS++.h>
#include <HardwareSerial.h>

const char* ssid = "Totalplay-2.4G-be98"; // Reemplaza con tu SSID
const char* password = "wj3gHWG8zutNmaee"; // Reemplaza con tu contraseña

TinyGPSPlus gps;
HardwareSerial ss(1);

const int PIRPin = 21;
int motionDetected = 0;

void setup() {
  Serial.begin(115200);
  ss.begin(9600, SERIAL_8N1, 22, 23);
  pinMode(PIRPin, INPUT);
  Serial.println("ESP32 con NEO-6M y PiR");
  WiFi.begin(ssid, password);
  Serial.print("Conectando a Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println(" Conectado!");
}

void loop() {
  while (ss.available() > 0) {
    gps.encode(ss.read());
  }

  String latitude = "";
  String longitude = "";

  if (gps.location.isUpdated()) {
    latitude = String(gps.location.lat(), 6);
    longitude = String(gps.location.lng(), 6);
    Serial.print("Latitud: ");
    Serial.println(latitude);
    Serial.print("Longitud: ");
    Serial.println(longitude);
  }

  motionDetected = digitalRead(PIRPin);
  if (motionDetected == HIGH) {
    Serial.println("Movimiento detectado");
  } else {
    Serial.println("No hay movimiento");
  }

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String serverPath = "http://127.0.0.1:3000";

    String postData = "lat=" + latitude + "&lng=" + longitude + "&motion=" + (motionDetected == HIGH ? "1" : "0");

    http.begin(serverPath.c_str());
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    int httpResponseCode = http.POST(postData);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    } else {
      Serial.print("Error en la conexión: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("Wi-Fi no conectado");
  }

  delay(10000);
}
