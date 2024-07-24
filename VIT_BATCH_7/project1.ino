#define trigPin 10 // Trigger pin for ultrasonic sensor
#define echoPin 11 // Echo pin for ultrasonic sensor
#define ledPin 13  // LED pin
#define threshold 7  // Threshold distance for sludge level (cm)

long duration; // Stores echo pulse duration
int distance;     // Stores calculated distance

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); //setting baud rate as 9600
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo pulse duration
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance
  distance = duration * 0.034 / 2;

  // Check sludge level
  if (distance < threshold) {
    digitalWrite(ledPin, HIGH);  // Turn on LED
  } else {
    digitalWrite(ledPin, LOW);   // Turn off LED
  }
  delay(2000);
Serial.print("Distance:");
Serial.print(distance);
Serial.println("cm");

}
