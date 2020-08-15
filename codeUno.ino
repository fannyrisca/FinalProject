const int relay1 = 2; // pin ardunio untuk relay IN1
const int relay2 = 3; // pin ardunio untuk relay IN2
const int relay3 = 4; // pin ardunio untuk relay IN3
const int relay4 = 5; // pin ardunio untuk relay IN4

bool statR1 = false;
bool statR2 = false;
bool statR3 = false;
bool statR4 = false;

int num = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
}

void loop() {
  if (Serial.available()) {
    num = Serial.read();
    Serial.println(num);
  }

  if (num == 1){
    statR1 = true;
  } else if (num == 2) {
    statR1 = false;
  } else if (num == 3) {
    statR2 = true;
  } else if (num == 4) {
    statR2 = false;
  } else if (num == 5) {
    statR3 = true;
  } else if (num == 6) {
    statR3 = false;
  } else if (num == 7) {
    statR4 = true;
  } else if (num == 8) {
    statR4 = false;
  }

  if (statR1){
    digitalWrite(relay1, LOW);
  } else {
    digitalWrite(relay1, HIGH);
  }

  if (statR2){
    digitalWrite(relay2, LOW);
  } else {
    digitalWrite(relay2, HIGH);
  }

  if (statR3){
    digitalWrite(relay3, LOW);
  } else {
    digitalWrite(relay3, HIGH);
  }

  if (statR4){
    digitalWrite(relay4, LOW);
  } else {
    digitalWrite(relay4, HIGH);
  }
}
