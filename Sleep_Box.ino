//Justin Fortner
//justinm.fortner@gmail.com
//SleepBox
//Last Edited Nov. 18 2019

//Includes
#include <DS3231.h>
#include <SoftwareSerial.h>

//Bluetooth Global Start 
int BTVar = 0;
//Bluetooth Global End

// Init the DS3231 using (Real Time Clock) the hardware interface
DS3231  rtc(SDA, SCL);
//DS3231 Init End

//Init HC05 (Bluetooth) Software Serial
SoftwareSerial BTSerial(3, 5); // RX | TX
//HC05 Init End

//Init a Time-data structure
Time  t;
//Time-data Structure Init End

//LED Global Start
#define RED_LED 9
#define GRN_LED 10
#define BLU_LED 11
int nightREDBrightness = 0;
int nightGRNBrightness = 0;
int nightBLUBrightness = 1;
//LED Global End

//Alarm Global Start
int alarmHour = 0;
int alarmMin = 0;

int alarmPreset0 = 48; //6:00
int alarmPreset1 = 49; //6:15
int alarmPreset2 = 50; //6:30
int alarmPreset3 = 51; //6:45
int alarmPreset4 = 52; //7:00
int alarmPreset5 = 53; //7:15 
int alarmPreset6 = 54; //7:30
int alarmPreset7 = 55; //7:45
int alarmPreset8 = 56; //8:00
int alarmPreset9 = 57; //None
//Alarm Gobal End

void setup()
{
  //Setup Serial Connections Start
  Serial.begin(115200);
  BTSerial.begin(115200);
  //Setup Serial Connections End

  //Initialize DS3231 Start
  rtc.begin();
  //Initialize DS3231 End
  
  //DS3231 Set Date and Time Start
  //rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(07, 32, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(18, 11, 2019);   // Set the date to January 1st, 2014
  //DS3231 Set Date and Time End

  //LED Setup Start
  pinMode(RED_LED, OUTPUT);
  pinMode(GRN_LED, OUTPUT);
  pinMode(BLU_LED, OUTPUT);

  analogWrite(RED_LED, nightREDBrightness);
  analogWrite(GRN_LED, nightGRNBrightness);
  analogWrite(BLU_LED, nightBLUBrightness);
  //LED Setup End
}

void loop()
{
  /* Uncomment if need to change setting of HC 05
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());
  */
  
  //Recieve Bluetooth Signals Start
  if(BTSerial.available()){
    BTVar = BTSerial.read();
    Serial.print(BTVar);
    Serial.println("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
    if(BTVar == alarmPreset0){
      Serial.print("Alarm 0 Set");
      Serial.println("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
      alarmHour = 6;
      alarmMin = 00;
    } else if(BTVar == alarmPreset1){
      Serial.print("Alarm 1 Set");
      Serial.println("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
      alarmHour = 6;
      alarmMin = 15;
    } else if(BTVar == alarmPreset2){
      Serial.print("Alarm 2 Set");
      Serial.println("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
      alarmHour = 6;
      alarmMin = 30;
    } else if(BTVar == alarmPreset3){
      Serial.print("Alarm 3 Set");
      Serial.println("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
      alarmHour = 6;
      alarmMin = 45;
    } else if(BTVar == alarmPreset4){
      Serial.print("Alarm 4 Set");
      Serial.println("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
      alarmHour = 7;
      alarmMin = 00;
    } else if(BTVar == alarmPreset5){
      Serial.print("Alarm 5 Set");
      Serial.println("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
      alarmHour = 7;
      alarmMin = 15;
    } else if(BTVar == alarmPreset6){
      Serial.print("Alarm 6 Set");
      Serial.println("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
      alarmHour = 7;
      alarmMin = 30;
    } else if(BTVar == alarmPreset7){
      Serial.print("Alarm 7 Set");
      Serial.println("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
      alarmHour = 7;
      alarmMin = 45;
    } else if(BTVar == alarmPreset8){
      Serial.print("Alarm 8 Set");
      Serial.println("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
      alarmHour = 8;
      alarmMin = 00;
    } else if(BTVar == alarmPreset9){
      Serial.print("In Test Case");
      Serial.println("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
      alarmHour = 10;
      alarmMin = 15;
    }
  }
  //Recieve Bluetooth Signals End
  
  // Get data from the DS3231 Start
  t = rtc.getTime();
  // Get data from the DS3231 End

  //Check if within 30 minuites of alarm Start
  if(alarmMin == 0){
    if((t.hour == (alarmHour-1) && t.min >= 30) || (t.hour == alarmHour && t.min <= 0)){
      wakeUp();
    }
  } else if(alarmMin == 15){
    if((t.hour == (alarmHour-1) && t.min >= 45) || (t.hour == alarmHour && t.min <= 15)){
      wakeUp();
    }
  }  else if(alarmMin == 30){
    if(t.hour == alarmHour && (t.min >= 0 && t.min <= 30)){
      wakeUp();
    }
  } else if (alarmMin == 45){
    if(t.hour == alarmHour && (t.min >= 15 && t.min <= 45)){
      wakeUp();
    }
  }
  //Check if within 30 minuites of alarm End


  //Used to Debug RTC Start
  // Send date over serial connection
  //Serial.print("Today is the ");
  //Serial.print(t.date, DEC);
  //Serial.print(". day of ");
  //Serial.print(rtc.getMonthStr());
  //Serial.print(" in the year ");
  //Serial.print(t.year, DEC);
  //Serial.println(".");
  
  // Send Day-of-Week and time
  //Serial.print("It is the ");
  //Serial.print(t.dow, DEC);
  //Serial.print(". day of the week (counting monday as the 1th), and it has passed ");
  Serial.print(t.hour, DEC);
  Serial.print(" hour(s), ");
  Serial.print(t.min, DEC);
  Serial.print(" minute(s) and ");
  //Serial.print(t.sec, DEC);
  //Serial.println(" second(s) since midnight.");

  // Send a divider for readability
  Serial.println("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
  //Used to Debug RTC End
}

//When asleep set the LED to the dimmest blue
void asleep(){
  nightREDBrightness = 0;
  nightGRNBrightness = 0;
  nightBLUBrightness = 1;
  analogWrite(RED_LED, nightREDBrightness);
  analogWrite(GRN_LED, nightGRNBrightness);
  analogWrite(BLU_LED, nightBLUBrightness);
  loop();
}

//When time is hit wake up atarts
//Dim white light is increased in brightness for 30 min
//after 30 min or the time of our alarm is hit turn red
void wakeUp(){
  nightREDBrightness = 1;
  nightGRNBrightness = 1;
  nightBLUBrightness = 1;
  for(int i = 0; i <= 30; i++){
    nightREDBrightness = nightREDBrightness + 7;
    nightGRNBrightness = nightGRNBrightness + 7;
    //nightBLUBrightness = nightBLUBrightness + 7;
    analogWrite(RED_LED, nightREDBrightness);
    analogWrite(GRN_LED, nightGRNBrightness);
    analogWrite(BLU_LED, nightBLUBrightness);
    delay (60000);
    t = rtc.getTime();
    //Used to Debug Start
    Serial.print(t.hour, DEC);
    Serial.print(" hour(s), ");
    Serial.print(t.min, DEC);
    Serial.print(" minute(s) and ");
    Serial.println("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
    //Used to Debug End
    if(t.hour >= alarmHour && t.min >= alarmMin){
      late();
    }
  }
  late();
}

//For the 30 Minuites post alarm the LEDs will be the brightest Red
void late(){
  nightREDBrightness = 255;
  nightGRNBrightness = 0;
  nightBLUBrightness = 0;
  analogWrite(RED_LED, nightREDBrightness);
  analogWrite(GRN_LED, nightGRNBrightness);
  analogWrite(BLU_LED, nightBLUBrightness);
  //delay(1800000);
  delay (120000);
  t = rtc.getTime();
  //Used to Debug Start
  Serial.print(t.hour, DEC);
  Serial.print(" hour(s), ");
  Serial.print(t.min, DEC);
  Serial.print(" minute(s) and ");
  Serial.println("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
  //Used to Debug End
  asleep();
}
