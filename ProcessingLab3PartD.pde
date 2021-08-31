import processing.serial.*; // import serial library
Serial arduino; // serial object named arduino
String arduinoInput; //declare string variable named arduinoInput
PFont f;
String[] list;

void setup() {
  f = createFont("Arial", 20, true); // type and size of font
  size (700, 700); // GUI box size
  printArray(Serial.list()); // find which port arduino is connected to
  arduino = new Serial(this, "COM3", 9600); // initialize port
}

void draw(){
  if (arduino.available() > 0) //only run when there is incoming data from serial port
  {
    background(255);
    arduinoInput = arduino.readString(); // store incoming data to arduinoInput
    println(arduinoInput);
    
     String m = arduinoInput;
     list = split(m, ',');
     if(list.length == 6){
       float zero = float(list[0]);
       float one = float(list[1]);
       float two = float(list[2]);
       float three = float(list[3]);
       float four = float(list[4]);
       float five = float(list[5]);
       textFont(f);
       fill(0);
     // this part is the analog to digital converter by using the formula n * 5/ 1024, where n is the analog input on the arduino.  
     text("Analog Input 0: " + nf((zero*5)/1024,0,3) + " V", 100,100);
     text("\n" + "\n" + "Analog Input 1: " + nf((one * 5) / 1024, 0, 3) + " V", 100, 100);
     text("\n" + "\n" + "\n" + "\n" + "Analog Input 2: " + nf((two * 5) / 1024, 0, 3) + " V", 100, 100);
     text("\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "Analog Input 3: " + nf((three * 5) / 1024, 0, 3) + " V", 100, 100);
     text("\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "Analog Input 4: " + nf((four * 5) / 1024, 0, 3) + " V", 100, 100);
     text("\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "\n" + "Analog Input 5: " + nf((five * 5) / 1024, 0, 3) + " V", 100, 100);
     }
     delay(1000); 
  }
}
