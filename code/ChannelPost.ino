#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include <UniversalTelegramBot.h>

// Telegram BOT Token (Get from Botfather)
#define BOT_TOKEN "TOKEN"

void writeStringArrayToEEPROM(String message, int address);
String readStringFromEEPROM(int address);
void updateSSIDEEPROM(String data);
void updatePasswordEEPROM(String data);
void updateMessageEPROM(String data);
void updateIntervalEPROM(byte data);
String retrieveSSID();
String retrievePassword();
String retrieveMessage();
byte retrieveInterval();

String formSSID;
String formPassword;
String formMessage;
String formInterval;

// bura degisti
#ifndef APSSID
#define APSSID "lonesaver"
#define APPSK "thereisnospoon"
#endif

/* Set these to your desired credentials. */
const char *ssid = APSSID;
const char *password = APPSK;

ESP8266WebServer server(80);

String page(String page_ssid, String page_password, String page_message, String page_interval);

// \bura degisti

const unsigned long BOT_MTBS = 1000 * formInterval.toInt(); // mean time between scan messages

WiFiClientSecure secured_client;
X509List cert(TELEGRAM_CERTIFICATE_ROOT);
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
unsigned long bot_lasttime; // last time messages' scan has been done

void handleRoot();
void handleNotFound();
void resetDevice();

int wifiConnectionAttempt = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println();

  EEPROM.begin(256);
  formSSID = retrieveSSID();
  formPassword = retrievePassword();
  formMessage = retrieveMessage();
  formInterval = String(retrieveInterval());

  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.on("/reset", resetDevice);
  server.begin();
  Serial.println("HTTP server started");

  // attempt to connect to Wifi network:
  configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
  secured_client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(formSSID);
  WiFi.begin(formSSID, formPassword);

  while (WiFi.status() != WL_CONNECTED && wifiConnectionAttempt < 10)
  {
    delay(1000);
    Serial.print(".");
    wifiConnectionAttempt++;
  }
  Serial.println("\nwifi connected");
  Serial.println(WiFi.localIP());
}

void loop()
{
  server.handleClient();
  if (WiFi.status() == WL_CONNECTED)
  {
    if (millis() - bot_lasttime > BOT_MTBS)
    {
      Serial.println("mesaj");
      // https://web.telegram.org/a/#CHATID
      bot.sendMessage("-chatid", formMessage, "");
      bot_lasttime = millis();
    }
  }
}
