int di_one = 2;
int di_two = 4;
int di_three = 7;
int di_four = 8;
int di_five = 12;
String words = "Translation: ";


void setup() {
  Serial.begin(9600);
  pinMode(di_one, INPUT);
  pinMode(di_two, INPUT);
  pinMode(di_three, INPUT);
  pinMode(di_four, INPUT);
  pinMode(di_five, INPUT);

}

void loop() {
  int val_one = digitalRead(di_one);
  int val_two = digitalRead(di_two);
  int val_three = digitalRead(di_three);
  int val_four = digitalRead(di_four);
  int val_five = digitalRead(di_five);

  while(val_one == HIGH && val_two == HIGH && val_three == HIGH &&
        val_four == HIGH && val_five == HIGH){

     delay(100);

     val_one = digitalRead(di_one);
     val_two = digitalRead(di_two);
     val_three = digitalRead(di_three);
     val_four = digitalRead(di_four);
     val_five = digitalRead(di_five);

     
   }

   delay(2000);

   val_one = digitalRead(di_one);
   val_two = digitalRead(di_two);
   val_three = digitalRead(di_three);
   val_four = digitalRead(di_four);
   val_five = digitalRead(di_five);

   if(val_one == 0 && val_two == 0 && val_three == 1 && val_four == 1 && val_five == 1){
    words = words + String("_");
    Serial.print("\n\n" + words + "\n 1: " + String(val_one) + ", 2: " + String(val_two) +
    ", 3: " + String(val_three) + ", 4: " + String(val_four) + ", 5: " + String(val_five));
   }
   else if (val_one == 0 && val_two == 0 && val_three == 0 && val_four == 0 && val_five == 0){
    words.remove(words.length() - 1);
    Serial.print("\n\n" + words + "\n 1: " + String(val_one) + ", 2: " + String(val_two) +
    ", 3: " + String(val_three) + ", 4: " + String(val_four) + ", 5: " + String(val_five));
   }
   else {
    words = words + myLetter(val_one, val_two, val_three, val_four, val_five);
    Serial.print("\n\n" + words + "\n 1: " + String(val_one) + ", 2: " + String(val_two) +
    ", 3: " + String(val_three) + ", 4: " + String(val_four) + ", 5: " + String(val_five));
   }

   delay(2000);

}


String myLetter(int di_one, int di_two, int di_three, int di_four, int di_five){
  String letter;
  if(di_one == 1 && di_two == 0 && di_three == 0 && di_four == 0 && di_five == 0){
    letter = String("A"); 
  }
  else if (di_one == 0 && di_two == 1 && di_three == 0 && di_four == 0 && di_five == 0){
  letter = String("B");
  }
  else if (di_one == 1 && di_two == 1 && di_three == 0 && di_four == 0 && di_five == 0){
    letter = String("C");
  }
  else if (di_one == 0 && di_two == 0 && di_three == 1 && di_four == 0 && di_five == 0){
    letter = String("D");
  }
  else if (di_one == 1 && di_two == 0 && di_three == 1 && di_four == 0 && di_five == 0){
    letter = String("E");
  }
  else if (di_one == 0 && di_two == 1 && di_three == 1 && di_four == 0 && di_five == 0){
    letter = String("F");
  }
  else if (di_one == 1 && di_two == 1 && di_three == 1 && di_four == 0 && di_five == 0){
    letter = String("G");
  }
  else if (di_one == 0 && di_two == 0 && di_three == 0 && di_four == 1 && di_five == 0){
    letter = String("H");
  }
  else if (di_one == 1 && di_two == 0 && di_three == 0 && di_four == 1 && di_five == 0){
    letter = String("I");
  }
  else if (di_one == 0 && di_two == 1 && di_three == 0 && di_four == 1 && di_five == 0){
    letter = String("J");
  }
  else if (di_one == 1 && di_two == 1 && di_three == 0 && di_four == 1 && di_five == 0){
    letter = String("K");
  }
  else if (di_one == 0 && di_two == 0 && di_three == 1 && di_four == 1 && di_five == 0){
    letter = String("L");
  }
  else if (di_one == 1 && di_two == 0 && di_three == 1 && di_four == 1 && di_five == 0){
    letter = String("M");
  }
  else if (di_one == 0 && di_two == 1 && di_three == 1 && di_four == 1 && di_five == 0){
    letter = String("N");
  }
  else if (di_one == 1 && di_two == 1 && di_three == 1 && di_four == 1 && di_five == 0){
    letter = String("O");
  }
  else if (di_one == 0 && di_two == 0 && di_three == 0 && di_four == 0 && di_five == 1){
    letter = String("P");
  }
  else if (di_one == 1 && di_two == 0 && di_three == 0 && di_four == 0 && di_five == 1){
    letter = String("Q");
  }
  else if (di_one == 0 && di_two == 1 && di_three == 0 && di_four == 0 && di_five == 1){
    letter = String("R"); 
  }
  else if (di_one == 1 && di_two == 1 && di_three == 0 && di_four == 0 && di_five == 1){
    letter = String("S");
  }
  else if (di_one == 0 && di_two == 0 && di_three == 1 && di_four == 0 && di_five == 1){
    letter = String("T");
  }
  else if (di_one == 1 && di_two == 0 && di_three == 1 && di_four == 0 && di_five == 1){
    letter = String("U");
  }
  else if (di_one == 0 && di_two == 1 && di_three == 1 && di_four == 0 && di_five == 1){
    letter = String("V");
  }
  else if (di_one == 1 && di_two == 1 && di_three == 1 && di_four == 0 && di_five == 1){
    letter = String("W");
  }
  else if (di_one == 0 && di_two == 0 && di_three == 0 && di_four == 1 && di_five == 1){
    letter = String("X");
  }
  else if (di_one == 1 && di_two == 0 && di_three == 0 && di_four == 1 && di_five == 1){
    letter = String("Y");
  }
  else if (di_one == 0 && di_two == 1 && di_three == 0 && di_four == 1 && di_five == 1){
    letter = String("Z");
  }
  return letter;
}
