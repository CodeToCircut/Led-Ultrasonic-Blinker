const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13;

long duration;
int currentDistance;
int smoothedDistance = 50;

unsigned long previousMillis = 0;
int ledState = LOW;
int blinkInterval = 0; 

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    currentDistance = 999;
  } else {
    currentDistance = duration * 0.034 / 2;
  }

  if (currentDistance >= 2 && currentDistance <= 400) {
    smoothedDistance = (smoothedDistance * 3 + currentDistance) / 4; 
  } else {
    smoothedDistance = 999; 
  }

  if (smoothedDistance >= 2 && smoothedDistance <= 50) {
    int safeDistance = constrain(smoothedDistance, 2, 50);
    blinkInterval = map(safeDistance, 2, 50, 50, 1000);
  } else {
    blinkInterval = 0;
  }

  unsigned long currentMillis = millis();
  
  if (blinkInterval > 0) {
    if (currentMillis - previousMillis >= blinkInterval) {
      previousMillis = currentMillis;
      ledState = (ledState == LOW) ? HIGH : LOW;
      digitalWrite(ledPin, ledState);
    }
  } else {
    digitalWrite(ledPin, LOW);
    ledState = LOW;
  }
  
  delay(30); 
}
