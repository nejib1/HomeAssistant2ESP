# HomeAssistant2ESP

![Demo](https://github.com/nejib1/HomeAssistant2ESP/assets/10485460/52300a29-c2a6-447e-9a5b-595aa5d7d070)

**HomeAssistant2ESP** is a mini-project that empowers you to seamlessly retrieve data from Home Assistant using MQTT and display it in real-time on an OLED Shield screen. Say goodbye to the hassle of constantly checking your phone or logging into Home Assistant whenever you need this information!

## Overview

The hardware cost for this project is approximately €4 on AliExpress. (Note: I do not sell any products, nor am I endorsing specific products or websites.)

## Required Hardware

Before you begin, ensure you have the following items:
- [ESP8266 (preferably with USB C)](https://fr.aliexpress.com/item/32651747570.html)
- [Mini OLED Shield screen](https://fr.aliexpress.com/item/1005005334479829.html)

This project is not affiliated with any particular supplier or website, so you can purchase these components from your preferred source.

## Installation

1. **Configure Home Assistant:**
   - Add the following three YAML automations to your Home Assistant configuration, replacing "sensor.XXXXXX" with your specific configuration. You can add more or fewer data points as needed; just be sure to adjust the .ino file accordingly.

2. **Set Up Arduino:**
   - Fill in the configuration data within the HomeAssistant2ESP8266.ino file and compile it using the Arduino IDE while connecting the ESP8266 to your computer (only during the initial installation).

   If you have never compiled Arduino code before, consider following the essential tutorials available here: [How to Install the ESP8266 Board in the Arduino IDE](https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/).

   If you encounter any issues, please do not hesitate to create a ticket in the "Issues" section. I assure you that I will respond!

## Conclusion

To summarize, the steps involved in this project are:

1. Publishing messages in Home Assistant via MQTT.
2. Listening to and capturing information using ESP8266 and displaying it on an OLED Shield screen.

---

# HomeAssistant2ESP (Français)

Ce mini-projet vous permet de récupérer des données depuis Home Assistant, via le protocole MQTT, et de les afficher en temps réel sur un écran OLED Shield. Plus besoin de consulter votre téléphone ou de vous connecter à Home Assistant à chaque fois que vous avez besoin de ces informations !

## Aperçu

![Demo](https://github.com/nejib1/HomeAssistant2ESP/assets/10485460/52300a29-c2a6-447e-9a5b-595aa5d7d070)

Le coût du matériel nécessaire est d'environ 4€ sur AliExpress. (Note : Je ne vends aucun produit, ni ne fais la promotion de produits ou de sites spécifiques.)

## Matériel Requis

Avant de commencer, assurez-vous d'avoir les éléments suivants :
- [ESP8266 (de préférence au format USB C)](https://fr.aliexpress.com/item/32651747570.html)
- [Mini écran OLED Shield](https://fr.aliexpress.com/item/1005005334479829.html)

Ce projet n'est affilié à aucun fournisseur ou site spécifique, vous pouvez donc acheter ces composants où vous le souhaitez.

## Installation

1. Ajoutez les trois automatisations YAML suivantes dans Home Assistant, en remplaçant "sensor.XXXXXX" par votre propre configuration. Vous pouvez ajouter plus ou moins de données, à condition d'adapter le fichier .ino en conséquence.

2. Remplissez les données de configuration dans le fichier HomeAssistant2ESP8266.ino et compilez-le avec l'Arduino IDE en connectant l'ESP8266 à votre ordinateur (uniquement lors de l'installation initiale).

Si vous n'avez jamais compilé de code Arduino auparavant, je vous recommande de suivre les tutoriels essentiels disponibles ici : [Comment installer la carte ESP8266 dans l'IDE Arduino](https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/).

Si vous rencontrez des problèmes, n'hésitez pas à créer un ticket dans la section "Issues" (Problèmes). Je vous assure que je répondrai !

## Conclusion :

En conclusion, les étapes de ce projet consistent à :

1) Publier des messages dans Home Assistant via MQTT
2) Écouter et capturer les informations via ESP8266, puis les afficher sur un écran OLED Shield.
