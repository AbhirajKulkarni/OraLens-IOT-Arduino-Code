#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Servo.h>
#include <Stepper.h>

// WiFi credentials
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

// Blynk authentication token
char auth[] = "YourBlynkAuthToken";

// Pins for servo motors
#define PAN_SERVO_PIN 18
#define TILT_SERVO_PIN 19

// Pins for stepper motor
#define STEPPER_PIN_STEP 16
#define STEPPER_PIN_DIR 17
#define STEPPER_STEPS 200  // Change this according to your stepper motor

// Pins for MQx sensor and temperature sensor
#define MQx_SENSOR_PIN A0
#define TEMP_SENSOR_PIN A1

// Pins for sound sensor
#define SOUND_SENSOR_PIN A2

Servo panServo;
Servo tiltServo;
Stepper stepper(STEPPER_STEPS, STEPPER_PIN_STEP, STEPPER_PIN_DIR);

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  panServo.attach(PAN_SERVO_PIN);
  tiltServo.attach(TILT_SERVO_PIN);

  pinMode(MQx_SENSOR_PIN, INPUT);
  pinMode(TEMP_SENSOR_PIN, INPUT);
  pinMode(SOUND_SENSOR_PIN, INPUT);
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V0) {  // Slider for pan servo control
  int panPosition = param.asInt();
  panServo.write(panPosition);
}

BLYNK_WRITE(V1) {  // Slider for tilt servo control
  int tiltPosition = param.asInt();
  tiltServo.write(tiltPosition);
}

BLYNK_WRITE(V2) {  // Slider for stepper motor control
  int steps = param.asInt();
  stepper.step(steps);
}

void readSensors() {
  int mqxValue = analogRead(MQx_SENSOR_PIN);
  float temperature = analogRead(TEMP_SENSOR_PIN) / 1024.0 * 5.0 / 0.01; // Example conversion formula
  int soundValue = analogRead(SOUND_SENSOR_PIN);

  Serial.print("MQx Sensor Value: ");
  Serial.println(mqxValue);
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Sound Sensor Value: ");
  Serial.println(soundValue);
}
