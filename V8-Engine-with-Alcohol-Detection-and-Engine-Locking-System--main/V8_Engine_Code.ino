// V8 Engine - Alcohol Detection and Engine Locking (Simple Version)
// Board: Arduino Uno | Sensor: MQ-3 on A0

const int sensorPin = A0;   // MQ-3 analog output
const int relayPin  = 7;    // relay module
const int buzzerPin = 8;    // buzzer
const int threshold = 400;  // alcohol limit (0 to 1023)

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.println("Sensor warming up (60 seconds)...");
  delay(60000);               // MQ-3 heater needs time to stabilise
  Serial.println("Ready");
}

void loop() {
  int alcohol = analogRead(sensorPin);   // read sensor value

  Serial.print("Alcohol level: ");
  Serial.println(alcohol);

  if (alcohol > threshold) {
    digitalWrite(buzzerPin, HIGH);       // warning ON
    digitalWrite(relayPin, HIGH);        // lock engine (motor cut)
    Serial.println("Alcohol detected - Engine LOCKED");
  } else {
    digitalWrite(buzzerPin, LOW);        // warning OFF
    digitalWrite(relayPin, LOW);         // engine runs
    Serial.println("Safe - Engine ON");
  }

  delay(500);                            // wait before next reading
}
