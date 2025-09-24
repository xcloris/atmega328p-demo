#include <Arduino.h>

const uint8_t analogPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};
const uint8_t digitalPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

void setAllPins(uint8_t level) {
    for (uint8_t i = 0; i < sizeof(analogPins) / sizeof(analogPins[0]); i++) {
        digitalWrite(analogPins[i], level);
    }

    for (uint8_t i = 0; i < sizeof(digitalPins) / sizeof(digitalPins[0]); i++) {
        digitalWrite(digitalPins[i], level);
    }
}

void setup() {
    Serial.begin(9600);

    for (uint8_t i = 0; i < sizeof(analogPins) / sizeof(analogPins[0]); i++) {
        pinMode(analogPins[i], OUTPUT);
    }
    for (uint8_t i = 0; i < sizeof(digitalPins) / sizeof(digitalPins[0]); i++) {
        pinMode(digitalPins[i], OUTPUT);
    }

    Serial.println("Setup done, waiting for serial input...");
}

void loop() {
    if (Serial.available() > 0) {
        String input = Serial.readStringUntil('\n');
        Serial.print("Received: ");
        Serial.println(input);
        if (input == "HIGH") {
            setAllPins(HIGH);
            Serial.println("Set all pins HIGH");
        } else if (input == "LOW") {
            setAllPins(LOW);
            Serial.println("Set all pins LOW");
        }
    }

    static unsigned long lastToggle = 0;
    static bool state = false;

    if (millis() - lastToggle > 3000) {
        state = !state;
        setAllPins(state ? HIGH : LOW);
        Serial.println(state ? "Auto toggle: HIGH" : "Auto toggle: LOW");
        lastToggle = millis();
    }
}
