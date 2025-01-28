// Définir les pins
const int LED = 13;

// Définir les états possibles
enum Etat { ALLUMER, CLIGNOTER, VARIER, ETEINT };
Etat etatActuel = ALLUMER;

// Variables pour le clignotement
unsigned long dernierTemps = 0;
const unsigned long intervalClignotement = 250;
int clignotementCompteur = 0;

// Variables pour la variation
int brightness = 0;
int fade = 5;

// Fonction setup
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

// Fonction principale
void loop() {
  unsigned long tempsActuel = millis();
  
  switch (etatActuel) {
    case ALLUMER:
      etatAllumer();
      break;

    case CLIGNOTER:
      etatClignotement(tempsActuel);
      break;

    case VARIER:
      etatVariation(tempsActuel);
      break;

    case ETEINT:
      etatEteint(tempsActuel);
      break;
  }
}

// États définis
void etatAllumer() {
  Serial.println("Allumé - 2201250");
  digitalWrite(LED, HIGH);
  delay(2000); // Ici, on peut tolérer un délai bloquant
  digitalWrite(LED, LOW);
  etatActuel = CLIGNOTER; // Passer à l'état suivant
}

void etatClignotement(unsigned long tempsActuel) {
  if (tempsActuel - dernierTemps >= intervalClignotement) {
    dernierTemps = tempsActuel;
    digitalWrite(LED, !digitalRead(LED)); // Inverser l'état de la LED
    clignotementCompteur++;

    if (clignotementCompteur >= 8) { // 4 clignotements (ON/OFF = 2 intervalles)
      clignotementCompteur = 0;
      digitalWrite(LED, LOW);
      etatActuel = VARIER; // Passer à l'état suivant
    }
  }
}

void etatVariation(unsigned long tempsActuel) {
  Serial.println("Variation - 2201250");
  analogWrite(LED, brightness);
  
  while (brightness <= 255)
  { // Fade
    analogWrite(LED, brightness);
    delay(40);
    brightness += fade;
  }
  brightness = 0;
  etatActuel = ETEINT;
}

void etatEteint(unsigned long tempsActuel) {
  Serial.println("Éteint - 2201250");
  digitalWrite(LED, LOW);
  delay(2000); // Attente avant de redémarrer
  etatActuel = ALLUMER; // Retourner à l'état initial
}
