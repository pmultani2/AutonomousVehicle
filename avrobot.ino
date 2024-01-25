// Motor A connections
int enA = 3;
int in1 = 4;
int in2 = 5;
// Motor B connections
int enB = 9;
int in3 = 6;
int in4 = 7;

// Light
int light = 2;
int analogLight = A4;

// Infrared
int IRLeft = 13;
int IRLeftAnalog = A0;
int IRRight = 11;
int IRRightAnalog = A1;

void setup() {
	// Set all the motor control pins to outputs
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);

  // Set Infrared
  pinMode(IRLeft, INPUT);
  pinMode(IRRight, INPUT);
  pinMode(IRRightAnalog, INPUT);
  pinMode(IRLeftAnalog, INPUT);

  pinMode(light, OUTPUT);

  Serial.begin(9600);
}

int maxSpeed = 95;
void loop() {
  // digitalWrite(light, HIGH);
  // int val = analogRead(analogLight);

  int rightSensor = digitalRead(IRRight);
  int leftSensor = digitalRead(IRLeft);

  Serial.print(leftSensor);
  Serial.print("\t");
  Serial.println(rightSensor);

      
  if (rightSensor == LOW && leftSensor == LOW) {
    Serial.println("Forward");
    motorForward();
      analogWrite(enA, maxSpeed);
  analogWrite(enB, maxSpeed);
  } else if (rightSensor == HIGH && leftSensor == LOW) {
    Serial.println("Right");
    turnRight();
      analogWrite(enA, maxSpeed);
  analogWrite(enB, maxSpeed);
  } else if (rightSensor == LOW && leftSensor == HIGH) {
    Serial.println("Left");
    turnLeft();
      analogWrite(enA, maxSpeed);
  analogWrite(enB, maxSpeed);
  } else {
    Serial.println("Off");
     motorOff();
       analogWrite(enA, maxSpeed);
  analogWrite(enB, maxSpeed);
  }
}

// This function lets you control spinning direction of motors
void directionControl() {
	// Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
	analogWrite(enA, 5);
	analogWrite(enB, 5);

	// Turn on motor A & B
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
	delay(6000);
	
	// Now change motor directions
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
	delay(6000);
	
	// Turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

void motorForward() {
  	digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void motorBackward() {
  	digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void motorOff() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void turnLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

// This function lets you control speed of the motors
void speedControl() {
	// Turn on motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
	
	// Accelerate from zero to maximum speed
	for (int i = 0; i < 6; i++) {
		analogWrite(enA, i);
		analogWrite(enB, i);
		delay(100);
	}
	
	// Decelerate from maximum speed to zero
	for (int i = 5; i >= 0; --i) {
		analogWrite(enA, i);
		analogWrite(enB, i);
		delay(100);
	}
	
	// Now turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}
