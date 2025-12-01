#include <Arduino.h>
#include "MarlinCore.h"
#include "pins/pins.h"
#include "pins/stm32f4/pins_MARLIN_WITH_OPENPNP.h"

void MesurePression_Init() {
    // Initialisation des broches si nécessaire
    pinMode(PS_TANK, INPUT);
    pinMode(PS_VACUUM_1, INPUT);
    pinMode(PS_VACUUM_2, INPUT);
    pinMode(PUMP_1, OUTPUT);
    pinMode(ELECTROVALVE_1, OUTPUT);
}

//-------------------------------
//Mesurer la pression du tank
//-------------------------------

void mesurerPressionTank() {
    // Lecture du capteur
    int valeurADC = analogRead(PS_TANK);

    // Affichage (facultatif)
    Serial.print("Pression Tank (ADC) : ");
    Serial.println(valeurADC);

    // --- Hystérésis ---
    // Si pression < 200 → couper la pompe
    if (valeurADC < 200) {
        digitalWrite(PUMP_1, LOW);        // Pompe OFF
    }

    // Si pression > 330 → rallumer la pompe
    else if (valeurADC > 330) {
        digitalWrite(PUMP_1, HIGH);        // Pompe ON
    }
}

//-------------------------------
//Détecter la présence d’une pièce (digital)
//-------------------------------
void detecterPiece(int pinVacuum) {
    static unsigned long lastCheck = 0;      // mémorise le dernier envoi
    const unsigned long interval = 500;      // 500 ms

    unsigned long now = millis();

    // Si 500 ms sont écoulées, on envoie l'état
    if (now - lastCheck >= interval) {
        lastCheck = now;

        int etat = digitalRead(pinVacuum);

        Serial.print("Vacuum pin ");
        Serial.print(pinVacuum);
        Serial.print(" = ");
        Serial.println(etat);

        if (etat == HIGH) {
            Serial.println("Pièce présente");
        } else {
            Serial.println("Aucune pièce détectée");
        }
    }
}

//     detecterPiece(PS_VACUUM_1);
//     detecterPiece(PS_VACUUM_2);
