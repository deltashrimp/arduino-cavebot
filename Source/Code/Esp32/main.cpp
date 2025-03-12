// Это код, который надо загрузить на eps32!! Не на esp32-cam!!
#include <Arduino.h> // Эти библиотеки нужны для работы кода
#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "ESP32-AP"; // Имя точки доступа, ip - 192.168.4.1 (ввести в строку поиска в браузере)
const char *password = "12345678"; // Пароль точки доступа

WebServer server(80);

// MX1508 Motor Driver Pins (Пины подключения драйвера к esp32)
const int motor1Pin1 = 5; // IN1
const int motor1Pin2 = 18; // IN2
const int motor2Pin1 = 19; // IN3
const int motor2Pin2 = 21; // IN4

void handleRoot() {
    String html = "<html><body><h1>Motor Control</h1>"
                  "<form action=\"/motor1\" method=\"POST\">"
                  "<input type=\"submit\" name=\"action\" value=\"Forward\">"
                  "<input type=\"submit\" name=\"action\" value=\"Backward\">"
                  "<input type=\"submit\" name=\"action\" value=\"Stop\">"
                  "</form>"
                  "<form action=\"/motor2\" method=\"POST\">"
                  "<input type=\"submit\" name=\"action\" value=\"Forward\">"
                  "<input type=\"submit\" name=\"action\" value=\"Backward\">"
                  "<input type=\"submit\" name=\"action\" value=\"Stop\">"
                  "</form>"
                  "</body></html>";
    server.send(200, "text/html", html);
}

void handleMotor1() {
    String action = server.arg("action");
    if (action == "Forward") {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW);
    } else if (action == "Backward") {
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH);
    } else {
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, LOW);
    }
    server.sendHeader("Location", "/");
    server.send(303);
}

void handleMotor2() {
    String action = server.arg("action");
    if (action == "Forward") {
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
    } else if (action == "Backward") {
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
    } else {
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
    }
    server.sendHeader("Location", "/");
    server.send(303);
}

void setup() {
    // Initialize serial communication
    Serial.begin(115200);

    // Initialize motor control pins
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);

    // Initialize Wi-Fi access point
    WiFi.softAP(ssid, password);
    Serial.println();
    Serial.print("IP address: ");
    Serial.println(WiFi.softAPIP());

    // Initialize web server
    server.on("/", handleRoot);
    server.on("/motor1", HTTP_POST, handleMotor1);
    server.on("/motor2", HTTP_POST, handleMotor2);
    server.begin();
}

void loop() {
    server.handleClient();
}