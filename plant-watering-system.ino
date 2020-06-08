#define SensorPin A1
#define RedLed 2
#define LowMotor 3
float sensorValue = 0; 
void setup() {
  pinMode(RedLed, OUTPUT);
  pinMode(LowMotor, OUTPUT);
  Serial.begin(9600); 
} 
void loop() {
  // Gives us average of 100 reads to avoid fuzzy data
  for (int i = 0; i <= 100; i++) { 
    sensorValue = sensorValue + analogRead(SensorPin); 
    delay(1); 
  } 
  sensorValue = sensorValue/100.0;
  Serial.println(sensorValue);
  if (sensorValue < 400){
    Serial.println("Need water!");
    digitalWrite(RedLed, HIGH);
    digitalWrite(LowMotor, LOW);
    delay(5000);
    Serial.println("Done watering.");
    digitalWrite(RedLed, LOW);
  }
  delay(3600000);
} 
