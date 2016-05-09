#define VOLT (A0)
#define WAIT 500

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(VOLT, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  delay(WAIT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(WAIT);
  int inlet = map(analogRead(VOLT),
                  0, 1024,
                  0, 500);
  Serial.println(inlet/100.0);
}
