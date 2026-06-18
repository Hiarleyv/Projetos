#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <UrlEncode.h>

  const char* ssid = "xxx";
  const char* senha = "xxx";

  const String token = "xxx";
  const String id_chat = "xxx";
void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, senha);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("ESP32 conectado ao wifi");
  Serial.println("IP: ");
  Serial.print(WiFi.localIP());
}

void loop() {
    WiFiClientSecure cliente;
    cliente.setInsecure();
    HTTPClient https;

    String mensagem = "Teste";
    String url = "https://api.telegram.org/bot" + token + "/sendMessage?chat_id=" + id_chat + "&parse_mode=Markdown&text=" + urlEncode(mensagem);
    https.begin(cliente,url);

    int respostaHTTP = https.GET();

    if(respostaHTTP > 0){
      Serial.println("Mensagem Enviada!");
    }
      https.end();
      delay(5000);
}

