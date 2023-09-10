#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Définir l'adresse I2C de votre module OLED
#define OLED_ADDRESS 0x3C  // Ajustez ceci si votre OLED a une adresse différente

// Remplacez ces informations par vos propres paramètres WiFi et MQTT
const char* ssid = "VOTRE_SSID"; // Remplacez par le nom de votre réseau WiFi
const char* password = "VOTRE_MOT_DE_PASSE"; // Remplacez par le mot de passe de votre réseau WiFi
const char* mqtt_server = "ADRESSE_MQTT"; // Remplacez par l'adresse IP ou le nom de domaine de votre broker MQTT
const char* mqtt_user = "UTILISATEUR_MQTT"; // Remplacez par le nom d'utilisateur MQTT
const char* mqtt_password = "MOT_DE_PASSE_MQTT"; // Remplacez par le mot de passe MQTT
const char* mqtt_topic1 = "afficheur_esp8266/percent_battery";  // Sujet pour la première information
const char* mqtt_topic2 = "afficheur_esp8266/pv_production_live";  // Sujet pour la deuxième information
const char* mqtt_topic3 = "afficheur_esp8266/consommation_live";  // Sujet pour la troisième information

#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(OLED_RESET);

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastDisplayChangeTime = 0; // Variable pour suivre le temps
int currentDisplayTopic = 1; // Garde en mémoire le sujet actuel à afficher

char topic1Message[128] = ""; // Stocker le message de mqtt_topic1
char topic2Message[128] = ""; // Stocker le message de mqtt_topic2
char topic3Message[128] = ""; // Stocker le message de mqtt_topic3

// Prototype de fonction
void displayData(const char* message, const char* title, int textSize = 2);

void setup() {
  // Initialiser l'écran OLED
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialiser l'OLED avec l'adresse I2C 0x3C (pour le 64x48)
  display.clearDisplay();
  display.display();

  // Connexion WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connexion au WiFi en cours...");
  }
  Serial.println("Connecté au WiFi");

  // Connexion MQTT
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  while (!client.connected()) {
    Serial.println("Connexion au courtier MQTT en cours...");
    if (client.connect("ESP8266Client", mqtt_user, mqtt_password)) {
      Serial.println("Connecté au courtier MQTT");
    } else {
      Serial.print("Échec de la connexion MQTT. Erreur : ");
      Serial.print(client.state());
      Serial.println("Nouvelle tentative dans 5 secondes...");
      delay(5000);
    }
  }

  // S'abonner aux sujets MQTT
  client.subscribe(mqtt_topic1);
  client.subscribe(mqtt_topic2);
  client.subscribe(mqtt_topic3);
}

void loop() {
  client.loop();

  // Vérifier s'il est temps de changer le contenu de l'affichage
  unsigned long currentTime = millis();
  if (currentTime - lastDisplayChangeTime >= 3000) { // Changer toutes les 3 secondes
    lastDisplayChangeTime = currentTime;
    
    // Basculer entre les sujets
    currentDisplayTopic++;
    if (currentDisplayTopic > 3) {
      currentDisplayTopic = 1;
    }
    
    display.clearDisplay();
    switch (currentDisplayTopic) {
      case 1:
        displayData(topic1Message, "Batterie");
        break;
      case 2:
        displayData(topic2Message, "Production");
        break;
      case 3:
        displayData(topic3Message, "Conso");
        break;
    }
    display.display();
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message reçu sur le sujet : ");
  Serial.println(topic);

  // Traiter les données en fonction du sujet MQTT
  if (strcmp(topic, mqtt_topic1) == 0) {
    // Copier le message dans topic1Message
    snprintf(topic1Message, sizeof(topic1Message), "%.*s", length, payload);
  } else if (strcmp(topic, mqtt_topic2) == 0) {
    // Copier le message dans topic2Message
    snprintf(topic2Message, sizeof(topic2Message), "%.*s", length, payload);
  } else if (strcmp(topic, mqtt_topic3) == 0) {
    // Copier le message dans topic3Message
    snprintf(topic3Message, sizeof(topic3Message), "%.*s", length, payload);
  }
}

void displayData(const char* message, const char* title, int textSize) {
  display.setTextSize(textSize); // Définir la taille du texte
  display.setTextColor(WHITE);

  // Calculer la position y pour centrer le texte verticalement
  int16_t y = (display.height() - display.getCursorY()) / 2;

  display.setCursor(0, y);
  display.setTextSize(1); // Définir la taille du texte du titre à 1 (petite)
  display.print(title); // Afficher le titre en petit
  display.setTextSize(textSize); // Définir la taille du texte du message
  display.setCursor(0, y + 16); // Déplacer vers le bas pour afficher le texte
  display.println(message); // Afficher le message

  display.display();
}
