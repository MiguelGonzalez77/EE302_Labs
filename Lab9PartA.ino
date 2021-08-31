
  int analogInput_zero = 0;
  int analogInput_one = 1;
  int value_zero = 0;
  int value_one = 0;
  String numbers = String();
void setup() {
  Serial.begin(9600);
  pinMode(analogInput_zero, INPUT);
  pinMode(analogInput_one, INPUT);
}

void loop(){
  value_zero = analogRead(analogInput_zero);
  value_one = analogRead(analogInput_one);
  numbers = value_zero + String(",") + value_one;

  Serial.println(numbers);

  delay(1000);
}
