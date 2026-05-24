#include <WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>

// Configurações do Sensor DHT
#define DHTPIN 13
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define POT_PIN 34

// Configurações WiFi
const char* WIFI_NAME = "Wokwi-GUEST";
const char* WIFI_PASSWORD = "";

// Configurações do ThingSpeak
unsigned long myChannel = 3392211;
const char* myAPIKey = "D3R9TBYRMB74N8I0";

WiFiClient client;

void setup() {
  Serial.begin(115200);
  
  dht.begin();
  
  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);
  Serial.print("Conectando no WIFI");
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado!");
  
  ThingSpeak.begin(client);
}

void loop() {
  // Leitura dos sensores
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int heartRate = map(analogRead(POT_PIN), 0, 4095, 60, 180);

  // Verificação de erro no DHT
  if(isnan(h) || isnan(t)){
    Serial.println("Erro na leitura do sensor DHT!");
    t = 0; 
    h = 0;
  }

  Serial.printf("Temp: %.2f, Hum: %.2f, Bat: %d\n", t, h, heartRate);

  // Enviando dados para o ThingSpeak
  // Field 1: Temperatura
  // Field 2: Umidade
  // Field 3: Batimentos 
  
  ThingSpeak.setField(1, t);
  ThingSpeak.setField(2, h);
  ThingSpeak.setField(3, heartRate);

  int x = ThingSpeak.writeFields(myChannel, myAPIKey);
  
  if(x == 200){
    Serial.println("Canais atualizados com sucesso!");
  } else {
    Serial.println("Erro na atualização. Código HTTP: " + String(x));
  }

  delay(5000); 
}
