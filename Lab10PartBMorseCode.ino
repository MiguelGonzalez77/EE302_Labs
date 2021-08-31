/*
  Morse Code.

  Using one button as a digital input to spell words.
  
 */

int counter = 0;
int digitalInput = 2;
int digitalOutput = 10;
int val = 0;
String words = "Translation: ";
int count_one = 0;
int count_two = 0;
int count_three = 0;
int count_four = 0;
int pause_counter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(digitalInput, INPUT);
  pinMode(digitalOutput, OUTPUT);  
}

void loop() {
  val = digitalRead(digitalInput);
  if (val == LOW){
    analogWrite(digitalOutput, 262);
    counter = counter + 1;
    delay(600);
    val = digitalRead(digitalInput);
    if (val == LOW){
      counter = counter + 1;
      delay(600);
      val = digitalRead(digitalInput);
      if(val == LOW){
        counter = counter + 1;
        delay(600);
        val = digitalRead(digitalInput);
        if(val == LOW){
          counter = counter + 1;
          delay(600);
          val = digitalRead(digitalInput);
        }
      }
    }
    if (counter == 3){
      words = words + String(" ");
      count_one = 0;
      count_two = 0;
      count_three = 0;
      count_four = 0;
    }

    else if (counter == 4){
      words.remove(words.length() - 1);
    }
    else if (count_one == 0){
      count_one = counter;
      counter = 0;
      pause_counter = 0;
    }
    else if (count_two == 0 && pause_counter < 15){
      count_two = counter;
      counter = 0;
      pause_counter = 3;
    }
    else if (count_three == 0 && pause_counter < 15){
      count_three = counter;
      counter = 0;
      pause_counter = 6;
    }
    else if (count_four == 0 && pause_counter < 15){
      count_four = counter;
      counter = 0;
      pause_counter = 9;
    }
  }

  if ((count_one != 0 && pause_counter > 15) || count_four != 0){
    words = words + myLetter(count_one, count_two, count_three, count_four);
    count_one = 0;
    count_two = 0;
    count_three = 0;
    count_four = 0;
  }

  digitalWrite(digitalOutput, LOW);
  delay(300);
  counter = 0;
  pause_counter = pause_counter + 1;
  Serial.print("\n\n" + words + "\n 1: " + String(count_one) +
              ", 2: " + String(count_two) + ", 3: " + String(count_three) + ", 4: " +
              String(count_four) + "\npause counter: " + pause_counter);

}
String myLetter(int count_one, int count_two, int count_three, int count_four){
  String letter;
  if (count_one == 1 && count_two == 2 && count_three == 0 && count_four == 0){
    letter = String("A");
  }
  else if (count_one == 2 && count_two == 1 && count_three == 1 && count_four == 1){
    letter = String("B");
  }
  else if (count_one == 2 && count_two == 1 && count_three == 2 && count_four == 1){
    letter = String("C");
  }
  else if (count_one == 2 && count_two == 1 && count_three == 1 && count_four == 0){
    letter = String("D");
  }
  else if (count_one == 1 && count_two == 0 && count_three == 0 && count_four == 0){
    letter = String("E");
  }
  else if (count_one == 1 && count_two == 1 && count_three == 2 && count_four == 1){
    letter = String("F");
  }
  else if (count_one == 2 && count_two == 2 && count_three == 1 && count_four == 0){
    letter = String("G");
  }
  else if (count_one == 1 && count_two == 1 && count_three == 1 && count_four == 1){
    letter = String("H");
  }
  else if (count_one == 1 && count_two == 1 && count_three == 0 && count_four == 0){
    letter = String("I");
  }
  else if (count_one == 1 && count_two == 2 && count_three == 2 && count_four == 2){
    letter = String("J");
  }
  else if (count_one == 2 && count_two == 1 && count_three == 2 && count_four == 0){
    letter = String("K"); 
  }
  else if (count_one == 1 && count_two == 2 && count_three == 1 && count_four == 1){
    letter = String("L");
  }
  else if (count_one == 2 && count_two == 2 && count_three == 0 && count_four == 0){
    letter = String("M");
  }
  else if (count_one == 2 && count_two == 1 && count_three == 0 && count_four == 0){
    letter = String("N");
  }
  else if (count_one == 2 && count_two == 2 && count_three == 2 && count_four == 0){
    letter = String("O");
  }
  else if (count_one == 1 && count_two == 2 && count_three == 2 && count_four == 1){
    letter = String("P");
  }
  else if (count_one == 2 && count_two == 2 && count_three == 1 && count_four == 2){
    letter = String("Q");
  }
  else if (count_one == 1 && count_two == 2 && count_three == 1 && count_four == 0){
    letter = String("R");
  }
  else if (count_one == 1 && count_two == 1 && count_three == 1 && count_four == 0){
    letter = String("S");
  }
  else if (count_one == 2 && count_two == 0 && count_three == 0 && count_four == 0){
    letter = String("T");
  }
  else if (count_one == 1 && count_two == 1 && count_three == 2 && count_four == 0){
    letter = String("U");
  }
  else if (count_one == 1 && count_two == 1 && count_three == 1 && count_four == 2){
    letter = String("V");
  }
  else if (count_one == 1 && count_two == 2 && count_three == 2 && count_four == 0){
    letter = String("W");
  }
  else if (count_one == 2 && count_two == 1 && count_three == 1 && count_four == 2){
    letter = String("X");
  }
  else if (count_one == 2 && count_two == 1 && count_three == 2 && count_four == 2){
    letter = String("Y");
  }
  else if(count_one == 2 && count_two == 2 && count_three == 1 && count_four == 1){
    letter = String("Z");
  }
    return letter;
}
