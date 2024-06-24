#include <Arduino.h>
#include <ArduinoJson.h>
#include <stdlib.h> // For atoi

#include "mqtt_actions.h"       //  Prototypes of functions whose code are here
#include "mqtt.h"
#include "globals.h"



void 
new_session(int origin, char *msg) {
    Serial.println("New session");
    HAS_SESSION = true;
    digitalWrite(ledPin, HIGH);
}

void
stop_session(int origin, char *msg) {
    Serial.println("Stop session");
    HAS_SESSION = false;
    digitalWrite(ledPin, LOW);
}

void
publish_data(Data data) {
    char speedStr[20];
    char locLonStr[20];
    char locLatStr[20];
    char disStr[20];
    char altStr[20];
    char p_altStr[20];
    char calStr[20];

    snprintf(speedStr, sizeof(speedStr), "%.2f", data.speed);
    snprintf(locLonStr, sizeof(locLonStr), "%.6f", data.loc_lng);
    snprintf(locLatStr, sizeof(locLatStr), "%.6f", data.loc_lat);
    snprintf(disStr, sizeof(disStr), "%.2f", data.distance);

    JsonDocument jsonData;
    jsonData["speed"] = speedStr;
    jsonData["loc"]["lat"] = locLatStr;
    jsonData["loc"]["lng"] = locLonStr;
    jsonData["distance"] = disStr;

    String output;
    serializeJson(jsonData, output);
    do_publish("data/live", output.c_str());
}

void
publish_state() {
    bool ledState = digitalRead(ledPin) == HIGH ? true : false;

    JsonDocument jsonState;
    jsonState["session"] = HAS_SESSION;
    jsonState["led"] = ledState;
}