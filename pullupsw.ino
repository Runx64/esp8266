void setup() {
  // put your setup code here, to run once:
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int btnState = digitalRead(12);
  Serial.println(btnState);
  if (btnState == 0) {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }
  delay(100);
}
