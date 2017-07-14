void setup() {
  pinMode(1, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(1, HIGH);   
  delay(100);              
  digitalWrite(1, LOW);
  delay(100);
  digitalWrite(3, HIGH);   
  delay(50);              
  digitalWrite(3, LOW);
  delay(50);                
}

