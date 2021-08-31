int ai_zero = 0;
int ai_one = 1;
int ai_two = 2;
int val_zero = 0;
int val_one = 0;
int val_two = 0;
int thresh_one = 250;
int thresh_two = 750;
String words = "Translation: ";


void setup() {

  Serial.begin(9600);
  pinMode(ai_zero, INPUT);
  pinMode(ai_one, INPUT);
  pinMode(ai_two, INPUT);

}

void loop() {
  val_zero = analogRead(ai_zero);
  val_one = analogRead(ai_one);
  val_two = analogRead(ai_two);
  delay(500);
  while (val_zero > thresh_two && val_one > thresh_two && val_two > thresh_two){
    delay(100);
    val_zero = analogRead(ai_zero);
    val_one = analogRead(ai_one);
    val_two = analogRead(ai_two);
    
  }

  delay(2000);

  val_zero = analogRead(ai_zero);
  val_one = analogRead(ai_one);
  val_two = analogRead(ai_two);
  if (thresh_one < val_zero && val_zero < thresh_two && 
    val_one > thresh_two && thresh_one < val_two && val_two < thresh_two){

   words = words + String("_");
   Serial.print("\n\n" + words + "\n 1: " + String(val_zero) + 
   ", 2: " + String(val_one) + ", 3: " + String(val_two));
   
   }
   else if (val_zero > thresh_two && val_one > thresh_two &&
            thresh_one < val_two && val_two < thresh_two){

       words.remove(words.length() - 1);
       Serial.print("\n\n" + words + "\n 1: " + String(val_zero) +
       ", 2: " + String(val_one) + ", 3: " + String(val_two));

       
     }
     else {

      words = words + myLetter(val_zero, val_one, val_two);
      Serial.print("\n\n" + words + "\n 1: " + String(val_zero) + 
      ", 2: " + String(val_one) + ", 3: " + String(val_two));
      
     }
     delay(2000);

}

String myLetter(int zero, int one, int two){
  String letter;
  if (zero < thresh_one){
    if (one < thresh_one){
      if (two < thresh_one){
        letter = String("A");
      }
    }
  }
     if (zero < thresh_one){
      if(one < thresh_one){
        if(thresh_one < two && two < thresh_two){
        letter = String("B");
      }
     }
    }
     if(zero < thresh_one){
       if(one > thresh_one && one < thresh_two){
         if(two > thresh_one && two < thresh_two){
        letter = String("C");
      }
     }
    }
      if (zero < thresh_one){
        if (one > thresh_one && one < thresh_two){
          if (two < thresh_one){
            letter = String("D");
          }
        }
      }
      if (zero > thresh_one && zero < thresh_two){
        if (one < thresh_one){
          if (two < thresh_one){
            letter = String("E");
          }
        }
      }
      if (zero > thresh_one && zero < thresh_two){
        if (one < thresh_one){
          if(two > thresh_one && two < thresh_two){
            letter = String("F");
          }
        }
      }
      if(zero > thresh_one && zero < thresh_two){
        if(one > thresh_one && one < thresh_two){
          if(two < thresh_one){
            letter = String("G");
          }
        }
      }
      if(zero > thresh_one && zero < thresh_two){
        if(one > thresh_one && one < thresh_two){
          if(two > thresh_one && two < thresh_two){
            letter = String("H");
          }
        }
      }
      if(zero > thresh_two){
        if(one < thresh_one){
          if(two < thresh_one){
            letter = String("I");
          }
        }
      }
      if(zero > thresh_two){
        if(one < thresh_one){
          if(two > thresh_one && two < thresh_two){
            letter = String("J");
          }
        }
      }
      if(zero > thresh_two){
        if(one > thresh_one && one < thresh_two){
          if(two < thresh_one){
            letter = String("K");
          }
        }
      }
      if(zero > thresh_two){
        if(one > thresh_one && one < thresh_two){
          if(two > thresh_one && two < thresh_two){
            letter = String("L");
          }
        }
      }
      if(zero > thresh_two){
        if(one < thresh_one){
          if(two > thresh_two){
            letter = String("M");
          }
        }
      }
      if(zero > thresh_two){
        if(one > thresh_one && one < thresh_two){
          if(two > thresh_two){
            letter = String("N");
          }
        }
      }
      if(zero > thresh_two){
        if(one > thresh_two){
          if(two < thresh_one){
            letter = String("O");
          }
        }
      }
      if(zero < thresh_one){
        if(one > thresh_two){
          if(two > thresh_two){
            letter = String("P");
          }
        }
      }
      if(zero > thresh_one && zero < thresh_two){
        if(one < thresh_one){
          if(two > thresh_two){
            letter = String("R");
          }
        }
      }
      if(zero > thresh_one && zero < thresh_two){
        if(one > thresh_one && one < thresh_two){
          if(two > thresh_two){
            letter = String("S");
          }
        }
      }
      if(zero > thresh_one && zero < thresh_two){
        if(one > thresh_two){
          if(two < thresh_one){
            letter = String("T");
          }
        }
      }
      if(zero > thresh_one && zero < thresh_two){
        if(one > thresh_two){
          if(two > thresh_two){
            letter = String("U");
          }
        }
      }
      if(zero < thresh_one){
        if(one < thresh_one){
          if(two > thresh_two){
            letter = String("V");
          }
        }
      }
      if(zero < thresh_one){
        if(one > thresh_one && one < thresh_two){
          if(two > thresh_two){
            letter = String("W");
          }
        }
      }
      if(zero < thresh_one){
        if(one > thresh_two){
          if(two < thresh_one){
            letter = String("X");
          }
        }
      }
      if(zero < thresh_one){
        if(one > thresh_two){
          if(two > thresh_one && two < thresh_two){
            letter = String("Y");
          }
        }
      }
  return letter;
}
