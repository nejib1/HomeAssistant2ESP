<h1 align="center">HomeAssistant2ESP</h1>
<p align="center">Affichez vos données Home Assistant sur un écran OLED Shield via ESP8266</p>

---

## Aperçu

![Demo](https://github.com/nejib1/HomeAssistant2ESP/assets/10485460/52300a29-c2a6-447e-9a5b-595aa5d7d070)

Ce mini-projet vous permet de récupérer facilement des données depuis Home Assistant et de les afficher en temps réel sur un écran OLED Shield. Plus besoin de consulter votre téléphone ou de vous connecter à Home Assistant à chaque fois que vous avez besoin de ces informations !

Le coût du matériel nécessaire est incroyablement abordable, à seulement 3 à 4€ sur AliExpress.

## Matériel Requis

Avant de commencer, assurez-vous d'avoir les éléments suivants :
- [ESP8266 (de préférence au format USB C)](https://fr.aliexpress.com/item/32651747570.html)
- [Mini écran OLED Shield](https://fr.aliexpress.com/item/1005005334479829.html)

Ce projet n'est pas affilié à aucun fournisseur ou site, vous pouvez donc acheter ces composants où vous le souhaitez.

## Installation

1. Ajoutez les 3 automatisations YAML suivantes dans Home Assistant, en remplaçant "sensor.XXXXXX" par votre propre configuration. Vous pouvez ajouter plus ou moins de données, à condition d'adapter le fichier .ino.

2. Renseignez les données de configuration dans le fichier HomeAssistant2ESP8266.ino et compilez-le avec l'Arduino IDE en connectant l'ESP8266 à votre ordinateur (uniquement lors de l'installation initiale).

Si vous n'avez jamais compilé de code Arduino auparavant, nous vous recommandons de suivre les tutoriels essentiels disponibles ici : [Comment installer la carte ESP8266 dans l'IDE Arduino](https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/).

Si vous rencontrez des problèmes, n'hésitez pas à créer un ticket dans la section "Issues" (Problèmes). Je suis là pour vous aider !

---
