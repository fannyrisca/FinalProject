#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

int pinLED = 14;
String command;
int com = 0;
String lamp = "mati";
String s1 = "0";
String s2 = "0";
String s3 = "0";
String s4 = "0";

ESP8266WebServer server(80);

const char* ssid = "myIOT";      // Nama AP/Hotspot
const char* password = "1234567890";    // Password AP/Hotspot

//Static IP address configuration
IPAddress staticIP(192, 168, 4, 1); //ESP static ip
IPAddress gateway(192, 168, 4, 1);   //IP Address of your WiFi Router (Gateway)
IPAddress subnet(255, 255, 255, 0);  //Subnet mask
IPAddress dns(8, 8, 8, 8);  //DNS

void setup() {

  Serial.begin(115200);
  delay(10);

  // Mengatur WiFi ----------------------------------------------------------
  Serial.println();
  Serial.print("Configuring access point...");


  WiFi.mode(WIFI_AP);             // Mode AP/Hotspot
  WiFi.config(staticIP, subnet, gateway, dns);
  WiFi.softAP(ssid, password);

  // Membuat tampilan Webpage -----------------------------------------------
  server.on("/command", HTTP_POST, setCommand);

  // Bagian ini opsional jika ingin membuat page lain ----------------------
  server.on("/status", []() {
    server.send(200, "text/plain", "Ini adalah Page Status Aktif");
  });

  // Start the server -------------------------------------------------------
  server.begin();
  Serial.println("Server dijalankan");

  // Print the IP address ---------------------------------------------------
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();

  command = server.arg("state");
  if (lamp == "saklar1hidup") {
    s1 = "1";
    Serial.write(1);
    //Serial.println("Saklar 1 Hidup");
  } else if (lamp == "saklar1mati") {
    s1 = "0";
    Serial.write(2);
    //Serial.println("Saklar 1 mati");
  } else if (lamp == "saklar2hidup") {
    s2 = "1";
    Serial.write(3);
    //Serial.println("Saklar 2 Hidup");
  } else if (lamp == "saklar2mati") {
    s2 = "0";
    Serial.write(4);
    //Serial.println("Saklar 2 mati");
  } else if (lamp == "saklar3Hidup") {
    s3 = "1";
    Serial.write(5);
    //Serial.println("Saklar 3 Hidup");
  } else if (lamp == "saklar3mati") {
    s3 = "0";
    Serial.write(6);
    //Serial.println("Saklar 3 mati");
  } else if (lamp == "saklar4hidup") {
    s4 = "1";
    Serial.write(7);
    //Serial.println("Saklar 4 Hidup");
  } else if (lamp == "saklar4mati") {
    s4 = "0";
    Serial.write(8);
    //Serial.println("Saklar 4 mati");
  }

}

void setCommand() {
  String perintah = "";
  if (server.hasArg("state")) {
    perintah = server.arg("state");
    if (perintah == "checkLamp") {
      server.send(200, "text/plain", s1+","+s2+","+s3+","+s4);
    } else {
      if (perintah == "1") {
        lamp = "saklar1hidup";
        server.send(200, "text/plain", lamp);
      } else if (perintah == "2") {
        lamp = "saklar1mati";
        server.send(200, "text/plain", lamp);
      } else if (perintah == "3") {
        lamp = "saklar2hidup";
        server.send(200, "text/plain", lamp);
      } else if (perintah == "4") {
        lamp = "saklar2mati";
        server.send(200, "text/plain", lamp);
      } else if (perintah == "5") {
        lamp = "saklar3Hidup";
        server.send(200, "text/plain", lamp);
      } else if (perintah == "6") {
        lamp = "saklar3mati";
        server.send(200, "text/plain", lamp);
      } else if (perintah == "7") {
        lamp = "saklar4hidup";
        server.send(200, "text/plain", lamp);
      } else if (perintah == "8") {
        lamp = "saklar4mati";
        server.send(200, "text/plain", lamp);
      }
    }
  } else {
    Serial.println("data tidak masuk");
    server.send(200, "text/plain", "Data tidak masuk");
  }
}
