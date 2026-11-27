#include <WiFi.h>

void setup() {

    Serial.begin(115200);
    //baud rate

    WiFi.mode(WIFI_STA);
    //wifi k 2 mODES 
    //STA:
    // AccessPoint: when turning on the hotspot the mobile becomes the acess point router 

    WiFi.disconnect();

    delay(1000);

}

void loop() {

    Serial.println("Scanning WiFi networks...");

    int count = WiFi.scanNetworks();
    //range main jo bhi wifi hon gy unki scan kr ly ga aur alehda database main uss ka data rkh ly ga aur return sirf number kry ga

    if (count == 0) {

        Serial.println("No networks found");

    }

    else {

        Serial.print("Networks found: ");

        Serial.println(count);

    }

    for (int i = 0; i < count; i++) {

        Serial.print("SSID: ");

        Serial.println(WiFi.SSID(i));

        Serial.print("RSSI: ");

        Serial.println(WiFi.RSSI(i));

        Serial.print("Channel: ");

        Serial.println(WiFi.channel(i));

        Serial.println("----------------");

    }

    WiFi.scanDelete();

    delay(5000);

}