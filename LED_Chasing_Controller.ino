
const int ledPins[] = {8, 9, 10, 11};
const int count = sizeof(ledPins) / sizeof(ledPins[0]);

const int interval = 500;

unsigned long pre_time;
unsigned long current_time;

int currentLed = 0;


void setup() {
  for (int i = 0; i < count; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  digitalWrite(ledPins[currentLed], HIGH);

  pre_time = millis();
}


void loop() {

  current_time = millis();

  if (current_time - pre_time >= interval) {

    digitalWrite(ledPins[currentLed], LOW);

    currentLed = (currentLed + 1) % count;

    digitalWrite(ledPins[currentLed], HIGH);

    pre_time = current_time;
  }

}
