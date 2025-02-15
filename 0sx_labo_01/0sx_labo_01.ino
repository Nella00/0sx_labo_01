// Définition des pins
const int LED = 13;

// Définition des états possibles
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

// États allumer
void etatAllumer() {
  Serial.println("Allumé - 2201250");
  digitalWrite(LED, HIGH);
  delay(2000);
  digitalWrite(LED, LOW);
  delay(500); // pour qu'on puisse voir le passage entre les états allumer et clignotement
  etatActuel = CLIGNOTER; // Passer à l'état suivant
}

// etat clignotement
void etatClignotement(unsigned long tempsActuel) {
  Serial.println("Clignotement - 2201250");
  for (int i = 0; i < 4; i++){
    digitalWrite(LED, HIGH);
    delay(250);
    digitalWrite(LED, LOW);
    delay(250);
  }
  etatActuel = VARIER; // Passer à l'état suivant

/*  if (tempsActuel - dernierTemps >= intervalClignotement) {
    dernierTemps = tempsActuel;
    digitalWrite(LED, !digitalRead(LED)); // Inversion de l'état de la LED
    clignotementCompteur++;

    if (clignotementCompteur >= 8) { // 4 clignotements
      clignotementCompteur = 0;
      digitalWrite(LED, LOW);
    }
  }
*/
 
}

// etat variaion
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
  etatActuel = ETEINT; // passer à l'état suivant
}

// etat eteint
void etatEteint(unsigned long tempsActuel) {
  Serial.println("Éteint - 2201250");
  digitalWrite(LED, LOW);
  delay(2000);
  etatActuel = ALLUMER; // Retourner à l'état initial
}
