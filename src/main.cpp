#include <Arduino.h>

const uint8_t analogPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};
const uint8_t digitalPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

void setAllPins(uint8_t level) {
    for (uint8_t i = 0; i < sizeof(analogPins); i++) {
        digitalWrite(analogPins[i], level);
    }

    for (uint8_t i = 0; i < sizeof(digitalPins); i++) {
        digitalWrite(digitalPins[i], level);
    }
}

void setup() {
    for (uint8_t i = 0; i < sizeof(analogPins); i++) {
        pinMode(analogPins[i], OUTPUT);
    }
    for (uint8_t i = 0; i < sizeof(digitalPins); i++) {
        pinMode(digitalPins[i], OUTPUT);
    }
}

void loop() {
    setAllPins(HIGH);
    delay(3000);

    setAllPins(LOW);
    delay(3000);
}
