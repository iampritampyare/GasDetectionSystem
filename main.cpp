  #define BLYNK_TEMPLATE_ID "TMPL3MLWvr7LM"
#define BLYNK_TEMPLATE_NAME "Smart Gas Detection system"




#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define gled   D7
#define rled   D6
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//char auth[] = "jH3j76uHFyTxw7p-G-OycqcDCkJKnTZl";

 //Enter your Blynk Auth token
//char ssid[] = "Airtel_Room 501";  //Enter your WIFI SSID
//char pass[] = "May@12344";  //Enter your WIFI Password


int pinSensor = A0;
int THRESHOLD = 550;
//#define buzzer  D8
int rdata = 0; 
//BlynkTimer timer;

void setup()
{
    Serial.begin(9600); 
   // pinMode(buzzer, OUTPUT);
    // pinMode(pinRedLed, OUTPUT);
    // pinMode(pinSensor, INPUT);
    pinMode(gled , OUTPUT);
    pinMode(rled , OUTPUT);
    //Blynk.begin(auth,ssid,pass,"blynk.cloud",80);
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("smart smell detection system is on");
  display.display(); 
}

void loop()
{
    int rdata  =  analogRead(pinSensor);
    Serial.print("Methane Range: ");
    

    if(rdata <= THRESHOLD){
      // digitalWrite(pinRedLed, HIGH);
      //digitalWrite(pinGreenLed, LOW);
      //digitalWrite(buzzer, HIGH);  
      Serial.println("co2 detected");
      display.clearDisplay();

      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0, 10);
      // Display static text
      display.println("co2 detected");
      digitalWrite(rled , HIGH);
      display.display(); 

      // Blynk.logEvent("gas detected","WARNING! co2 Detected!"); //Enter your Event Name
      
      delay(500);
    
    }else
      {
        // digitalWrite(pinRedLed, LOW);
        //digitalWrite(pinGreenLed, HIGH);
        //digitalWrite(buzzer, LOW);
        Serial.println(rdata);
        Serial.println("Air is clean");
        
        display.clearDisplay();

          display.setTextSize(1);
          display.setTextColor(WHITE);
          display.setCursor(0, 10);
          // Display static text
          display.println("Air is clean");
          digitalWrite(gled , HIGH);
          delay(1000);
          digitalWrite(gled , LOW);
          delay(1000);
          display.display(); 
          digitalWrite(rled ,LOW);

      
      delay(500);
      
      }
      
      
    delay(1000); 
    
    Blynk.run();
}







// const int buzzer=8; //Connect buzzer to digital pin 8
// const int sensor=A2; //Connect gas sensor to analog pin A2
// const int smoke_threshold=615 //set to threshold value

// void setup() 
// {  
//     Serial.begin(9600); //set the serial port to 9600
// pinMode(buzzer, OUTPUT); //set buzzer as output
//   pinMode(sensor, INPUT); //set gas sensor as input
   
// }

// void loop() {
 
// int sensor_value=analogRead(sensor);  //read the gas sensor value at pin A2 
// if(sensor_value>smoke_threshold) //compare sesnor value with threshold value
  
// {
//  tone(buzzer,1000,100); //ON the buzzer
//   Serial.print("Smoke detected! sensor value:  "); //print on serial monitor
//   Serial.println(sensor_value);
// }
// else
// {
//   noTone(buzzer); //OFF the buzzer
//   Serial.print("No smoke!! sensor value:"); //print on serial monitor
//   Serial.println(sensor_value);
// }
// delay(1000); //wait
// }








// #include <MQ2.h>
// #include <Wire.h> 
// // #include <LiquidCrystal_I2C.h>
// //I2C pins declaration
// // LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
// int Analog_Input = D8;
// int lpg, co, smoke;

// MQ2 mq2(Analog_Input);
