#ifndef mqttClient_h

#define mqttClient_h

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "credentials.h"
#include "common.h"

extern PubSubClient MQTTClient;

extern void Log(const String &payload);
extern void Log(const char *payload);
extern void Log(const char *topic, const char *payload);
extern void Log(String topic, String payload);

class MQTT
{
public:
    MQTT();
    void Begin();
    void publishMQTTmessage(String msg);
    void publishMQTTmessage(String topic, String msg);
    void reconnect();

private:
    void callback(char *topic, byte *payload, unsigned int length);
    size_t capacity;
    WiFiClient espClient;
};

#endif