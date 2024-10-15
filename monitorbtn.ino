//party mode button! simple firmware that switches monitors around in wundows since games dont like my monitor situation

//led in arcade button on pin 0
//button input on pin 1
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 #define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#include <Keyboard.h>
void ledCB(bool numlock, bool capslock, bool scrolllock, bool compose, bool kana, void *cbData) {
  (void) numlock;
  (void) scrolllock;
  (void) compose;
  (void) kana;
  (void) cbData;
  digitalWrite(LED_BUILTIN, capslock ? HIGH : LOW);
}
const int blue=1;
const int button =0;
int buttonState = 0; 

int monitorcommand=0;


void setup() {
display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);

 display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.clearDisplay();
  display.setCursor(10, 0);
  display.println("mode sel");
  display.setCursor(10, 30);
  display.println("OFFICE");
  display.display();    

  pinMode(blue, OUTPUT);
  pinMode(button, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Keyboard.onLED(ledCB);
  Keyboard.begin();
 delay(5000);

}

void loop() {
  // put your main code here, to run repeatedly:
buttonState = digitalRead(button);
delay(100);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(blue, HIGH);
    delay(100);
    digitalWrite(blue, LOW);
    delay(100);
    digitalWrite(blue, HIGH);
    delay(100);
    digitalWrite(blue, LOW);
    delay(100);
    digitalWrite(blue, HIGH);
    delay(100);
    digitalWrite(blue, LOW);
    delay(100);
    digitalWrite(blue, HIGH);
    delay(100);
    digitalWrite(blue, LOW);
    delay(100);
    digitalWrite(blue, HIGH);
    delay(100);
    digitalWrite(blue, LOW);
    delay(100);
    digitalWrite(blue, HIGH);
    delay(100);
    digitalWrite(blue, LOW);
    delay(100);
    if( monitorcommand ==0)
    {
      monitorcommand=1;
      Keyboard.press(KEY_LEFT_GUI);
Keyboard.releaseAll();
delay(100);
Keyboard.print("run");
delay(100);
Keyboard.press(KEY_KP_ENTER);
Keyboard.releaseAll();
delay(200);
Keyboard.print("displayswitch 4");
delay(100);
Keyboard.press(KEY_KP_ENTER);
Keyboard.releaseAll();
 display.clearDisplay();
  display.setCursor(10, 0);
  display.println("mode sel");
  display.setCursor(10, 30);
  display.println("GAMING");
  display.display();    
return;
    }
     if( monitorcommand ==1)
    {
      monitorcommand=0;
      Keyboard.press(KEY_LEFT_GUI);
Keyboard.releaseAll();
delay(100);
Keyboard.print("run");
delay(100);
Keyboard.press(KEY_KP_ENTER);
Keyboard.releaseAll();
delay(200);
Keyboard.print("displayswitch 3");
delay(100);
Keyboard.press(KEY_KP_ENTER);
Keyboard.releaseAll();
 display.clearDisplay();
  display.setCursor(10, 0);
  display.println("mode sel");
  display.setCursor(10, 30);
  display.println("OFFICE");
  display.display();    
return;
    }
    

  } else {
    // turn LED off:
    digitalWrite(blue, LOW);
  }
}
