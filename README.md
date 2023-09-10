# HomeAssistant2ESP
Ce mini projet consiste à récupérer des données depuis Home Assistant via ESP8266 et les afficher dans un écran OLED Shield.
Le but est d'avoir ces données sous les yeux sans besoin de consulter le téléphone portable our Home Asistant à chaque fois...
Le coût du matériel nécessaire est compris entre 3 et 4€ sur Aliexpress.

![Demo](https://github.com/nejib1/HomeAssistant2ESP/assets/10485460/52300a29-c2a6-447e-9a5b-595aa5d7d070)

# Matériel nécessaire : 

ESP8266 (de préférence format USB C) 
Lien : https://fr.aliexpress.com/item/32651747570.html

Mini écran Oled Shield: 
Lien : https://fr.aliexpress.com/item/1005005334479829.html

Je ne fais aucune affiliation, ce repository n'a aucun but lucratif, il vous faut un ESP8266 et un Oled Shield depuis n'importe quel fournisseur/site.


# Installation : 

1) Ajouter les 3 automatisations .YAML dans Home assistant, remplacez "sensor.XXXXXX" par votre propre configuration, vous n'êtes pas obligés de faire 3, vous pouvez afficher plus de données ou moins de données, à condition d'adapter le fichier .ino.
2) Renseignez les données de configuration dans HomeAssistant2ESP8266.ino et compilez le Arduino IDE en branchant l'ESP ESP8266 à votre ordinateur (juste pour la première fois, pour l'installation). 
Si vous n'avez jamais compilé un code Arduino auparavant, il est indispensable de suivre les tutoriaux ci-dessous, ce sont des prérequis indispensables :
https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/

N'hésitez pas à créer un ticket dans "Issues" (Problèmes) je répondrai, promis :) 
