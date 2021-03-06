//Akriya 1.2v

#include <Utils/WifiUtils.h>
// #include <Utils/MQTTUtils.h>
// #include <Utils/IR_RecvUtils.h>
// #include <Utils/TimeUtils.h>
#include <Utils/UtilManager.h>

// Define NodeMCU D3 pin  connect to LED
#define LED_PIN 13

long lastMsg = 0;
char msg[50];
int value = 0;

int OutPins[6] = {D1,D2,D3};
int OutPinsLength = 3;

void parseAndExecutePayload(byte* payload,int len);
int getValuefromByteString(byte *payload,int len);

MQTTUtils mqttUtils;
// IR_RecvUtils irrUtils;
TimeUtils timeUtils;

int i=0;

void setup() {
  Serial.begin(9600);
  WifiUtils::setup_wifi();
  UtilManager::mqttUtils->setup();
  Serial.println("Test");
  for(int i=0;i<OutPinsLength;i++)
  {
    pinMode(OutPins[i], OUTPUT);
    digitalWrite(OutPins[i], LOW);
  }
  // UtilManager::irrUtils->setupIR_recv();
  Serial.println("\n\t\tSETUP END");
}

void loop() {
  if (!UtilManager::mqttUtils->connected()) {
    UtilManager::mqttUtils->reconnect();
  }
  UtilManager::mqttUtils->client->loop();
  // stateManager.runStateChain();
}
