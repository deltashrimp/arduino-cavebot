#include <WiFi.h>
#include <WebServer.h>

// Определяем пины для управления моторами
#define IN1 26  // Подключен к "1 IN" (MOTOR-A: M1 и M3)
#define IN2 27  // Подключен к "2 IN" (MOTOR-A: M1 и M3)
#define IN3 14  // Подключен к "3 IN" (MOTOR-B: M2 и M4)
#define IN4 12  // Подключен к "4 IN" (MOTOR-B: M2 и M4)

// Учетные данные Wi-Fi
const char* ssid = "RobotAP"; // Имя сети
const char* password = "password"; // Пароль

// Создаем веб-сервер на порту 80
WebServer server(80);

// HTML-код веб-страницы
const char* html = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<title>Управление роботом</title>
</head>
<body>
<h1>Управление роботом</h1>
<div style="text-align: center;">
<button onclick="fetch('/forward')">↑</button><br>
<button onclick="fetch('/left')">←</button>
<button onclick="fetch('/stop')">Стоп</button>
<button onclick="fetch('/right')">→</button><br>
<button onclick="fetch('/backward')">↓</button>
</div>
</body>
</html>
)rawliteral"; // По какой-то причине в браузере не отображаются символы, поэтому могут быть краказные символы, но это не влияет на работу кода

// Функции управления моторами
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Обработчики запросов с веб-страницы
void handleRoot() {
  server.send(200, "text/html", html);
}

void handleForward() {
  moveForward();
  server.send(200, "text/plain", "OK");
}

void handleBackward() {
  moveBackward();
  server.send(200, "text/plain", "OK");
}

void handleLeft() {
  turnLeft();
  server.send(200, "text/plain", "OK");
}

void handleRight() {
  turnRight();
  server.send(200, "text/plain", "OK");
}

void handleStop() {
  stopMotors();
  server.send(200, "text/plain", "OK");
}

void setup() {
  // Запускаем Serial для отладки
  Serial.begin(115200);
  
  // Настраиваем пины как выходы
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  // Запускаем точку доступа Wi-Fi
  WiFi.softAP(ssid, password);
  Serial.println("Точка доступа запущена");
  Serial.print("IP-адрес: ");
  Serial.println(WiFi.softAPIP());
  
  // Определяем маршруты веб-сервера
  server.on("/", HTTP_GET, handleRoot);
  server.on("/forward", HTTP_GET, handleForward);
  server.on("/backward", HTTP_GET, handleBackward);
  server.on("/left", HTTP_GET, handleLeft);
  server.on("/right", HTTP_GET, handleRight);
  server.on("/stop", HTTP_GET, handleStop);
  
  // Запускаем сервер
  server.begin();
}

void loop() {
  // Обрабатываем запросы клиентов
  server.handleClient();
}