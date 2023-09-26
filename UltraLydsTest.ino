const int triggerPin = 7;  // Ultrasonic sensor trigger pin
const int echoPin = 6;     // Ultrasonic sensor echo pin

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  
  // Trigger the ultrasonic sensor to send a pulse
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  // Measure the duration of the pulse
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in millimeters
  distance = (duration / 2) / 2.91;  // 1 cm = 10 mm, so 1 cm = 29.1 / 10 mm = 5.82 mm
  
  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" mm");
  
  delay(5);  // Delay before the next reading
}
