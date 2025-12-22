#include <WiFi.h>
#include <WebSocketsServer.h>

const char* ssid = "Yes";
const char* password = "idontknow111";

const int internalLed = 12;
const int GreenLed = 13;

const int trigPin = 18;
const int echoPin = 5;

const float DISTANCE_READY_MIN = 5;
const float DISTANCE_READY_MAX = 20;
const int DISTANCE_JUMP_THRESHOLD = 11;

bool playerReady = false;
bool sendFalse = false;

char* serverConnection = "No";

bool PaddleGame = false;
bool DragonGame = false;
bool Continue = false;

WebSocketsServer webSocketServer = WebSocketsServer(81);

void setup() {
  Serial.begin(115200);

  pinMode(internalLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);

  digitalWrite(GreenLed, LOW);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  connectToWiFi();
  webSocketServer.begin();
  webSocketServer.onEvent(webSocketEvent);

  Serial.println("\n\n\nBe ready to play ..............");
}

// Connect to WiFi
void connectToWiFi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  digitalWrite(internalLed, HIGH);
  Serial.println("Internal LED ON");

  Serial.println(WiFi.localIP());
}

// Measure distance with ultrasonic sensor
float measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;
  return distance;
}

// Send jump signal over WebSocket
void sendJumpSignal(bool jumpDetected) {
  String message = jumpDetected ? "True" : "False";
  webSocketServer.broadcastTXT(message);
}

// Send distance data over WebSocket
void sendDistanceData(float distance) {
  String data = String(distance);
  webSocketServer.broadcastTXT(data);
}

// Send paddle position over WebSocket
void sendPaddlePosition(float distance) {
  String message = String(distance);
  webSocketServer.broadcastTXT(message);
}

void sendDragonGameData(float distance) {
  if (sendFalse) {
    sendJumpSignal(false);
    Serial.println("Player landed {Jump:False}");
    sendFalse = false;
  } else if (distance > DISTANCE_JUMP_THRESHOLD && !sendFalse) {
    sendJumpSignal(true);
    Serial.println("Player jumped {Jump:True}");

    delay(350);

    sendFalse = true;
  }
  delay(50);
}

void loop() {
  webSocketServer.loop();

  if (serverConnection == "Yes") {
    float distance = measureDistance();

    if (DISTANCE_READY_MIN <= distance && distance <= DISTANCE_READY_MAX) {
      if (!playerReady) {
        Serial.println("Player is ready to play ...........");
        playerReady = true;
      }
    }

    if (playerReady) {
      if (PaddleGame) {
        sendPaddlePosition(distance);
      } else if (DragonGame) {
        sendDragonGameData(distance);
      }
    }

    if(playerReady){
      if (Continue) {
        sendDistanceData(distance);  
      }
    }
  }

  delay(100);
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
  if (type == WStype_CONNECTED) {
    Serial.printf("[%u] Connected!\n", num);
    digitalWrite(GreenLed, HIGH);
    Serial.println("Green LED ON");
    serverConnection = "Yes";

    if (!playerReady){

      Serial.println("Be ready to play .................... ");
    }
  
  } else if (type == WStype_DISCONNECTED) {
    Serial.printf("[%u] Disconnected!\n", num);
    digitalWrite(GreenLed, LOW);
    Serial.println("Green LED OFF");
    serverConnection = "No";
    // playerReady = false;

    Serial.println("Be ready to play .................... ");
  
  } else if (type == WStype_TEXT) {
    String message = String((char*)payload).substring(0, length);
    Serial.printf("Received from [%u]: %s\n", num, message.c_str());

// *************************************************************
// ******************* Instructions ****************************
// *************************************************************

    Serial.println(message);

    if (message == "PaddleGame") {
      PaddleGame = true;
      DragonGame = false;
      Serial.println("YOU HAVE SELECTED THE PADDLE GAME");
    } else if (message == "DragonGame") {
      DragonGame = true;
      PaddleGame = false;
      Serial.println("YOU HAVE SELECTED THE DRAGON GAME");
    } else if (message == "False") {
      PaddleGame = false;
      DragonGame = false;
      Continue = false;
      Serial.println("RESET DONE");
    } 
    else if (message == "Continue") {
      Continue = true;
    }
    else if(message == "SingleInputGame"){
      webSocketServer.broadcastTXT("SingleInputGame");
      Continue = true;
      delay(100);
    } 
    else if(message == "DoubleInputGame"){
      webSocketServer.broadcastTXT("DoubleInputGame");
      Continue = true;
      delay(100);
    } 
    else if(message == "TripleInputGame"){
      webSocketServer.broadcastTXT("TripleInputGame");
      Continue = true;
      delay(100);
    }
    
    else {
      Serial.println("Data Error: " + message);
    }

    // now i need to create single Input data collector , double input data collector , triple input data collector 
  }
}
