void handleRoot()
{
  for (uint8_t i = 0; i < server.args(); i++)
  {
    if (server.argName(i) == "ssid")
    {
      formSSID = server.arg(i);
      updateSSIDEEPROM(formSSID);
    }
    else if (server.argName(i) == "password")
    {
      formPassword = server.arg(i);
      updatePasswordEEPROM(formPassword);
    }
    else if (server.argName(i) == "message")
    {
      formMessage = server.arg(i);
      updateMessageEPROM(formMessage);
    }
    else if (server.argName(i) == "interval")
    {
      formInterval = server.arg(i);
      updateIntervalEPROM(byte(formInterval.toInt()));
    }
    Serial.println(server.argName(i) + ": " + server.arg(i));
  }
  server.send(200, "text/html", page(formSSID, formPassword, formMessage, formInterval));
}

void handleNotFound()
{
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++)
  {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void resetDevice()
{
  delay(200);
  ESP.restart();
}