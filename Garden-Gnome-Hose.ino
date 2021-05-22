#include <FS.h>
#include <LittleFS.h>
#include <ESPAsyncWebServer.h>


#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>

#include <DNSServer.h>

#include <ESPAsync_WiFiManager.h> 


AsyncWebServer webServer(80);
DNSServer dnsServer;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200); 
    while (!Serial); 
        delay(200);
    Serial.print("\nStarting Async_AutoConnect_ESP8266_minimal on " + String(ARDUINO_BOARD)); 
    Serial.println(ESP_ASYNC_WIFIMANAGER_VERSION);
    Serial.println("Connect to AutoConnectAP and go to http://192.168.4.1/");
    ESPAsync_WiFiManager ESPAsync_wifiManager(&webServer, &dnsServer, "AutoConnectAP");
    ESPAsync_wifiManager.resetSettings();   //reset saved settings
    // ESPAsync_wifiManager.setAPStaticIPConfig(IPAddress(192,168,186,1));
    ESPAsync_wifiManager.autoConnect("AutoConnectAP");
    if (WiFi.status() == WL_CONNECTED) { 
        Serial.print(F("Connected. Local IP: ")); 
        Serial.println(WiFi.localIP()); 
    }
    else { 
        Serial.println(ESPAsync_wifiManager.getStatus(WiFi.status())); 
    }

    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    Serial.println("Blink!");
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
}