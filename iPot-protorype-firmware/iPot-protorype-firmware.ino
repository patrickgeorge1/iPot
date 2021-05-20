/*                               COOL STUFF USED
 *  Play music with arduino: https://dragaosemchama.com/en/2019/02/songs-for-arduino/ 
 *  
**/






//------------------                 SET UP                  ----------------------//
#define WATER_PUMP 3
#define BUZZER 6
#define TOP_SHS A0
#define MID_SHS A1
#define BOTTOM_SHS A2

void setup()
{
  pinMode(WATER_PUMP, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, HIGH);  // buzzer is low triggered

  Serial.begin(9600);
}







//------------------             PLAY MUSIC LOGIC            ----------------------//
// ref: https://github.com/robsoncouto/arduino-songs

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0


/*
 * melody = array composed of notes followed by duration = {-4. -4, 8 , 16} 
 * recommanded tempo = 140, change it to modify song speed
 * isBuzzerTriggeredLow - specifies buzzer trigger type
**/
void playMelody(uint8_t passive_buzzer_pin, const int melody[], const int notes, const int tempo, bool isBuzzerTriggerLow) {
  int wholenote = (60000 * 2) / tempo;
  int divider = 0, noteDuration = 0;


  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = melody[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(passive_buzzer_pin, melody[thisNote], noteDuration*0.9);
    delay(noteDuration);
    noTone(passive_buzzer_pin);
    if(isBuzzerTriggerLow) digitalWrite(passive_buzzer_pin, HIGH);
  }
  digitalWrite(passive_buzzer_pin, HIGH);
}



const int melody__irrigationStarted[] = {
  NOTE_C4,4,  NOTE_C4,4,  NOTE_D4,4,  NOTE_E4,4,
  NOTE_E4,-4, NOTE_D4,8,  NOTE_D4,2, 
};

const int melody__errorMode[] = {
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //1
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, -2,

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //5
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, -2,

  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8, //9
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_B2, 8, NOTE_C3, 8,
  NOTE_E2, 8, NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_E2, 8, NOTE_E2, 8,
  NOTE_C3, 8, NOTE_E2, 8, NOTE_E2, 8, NOTE_AS2, -2,
};

const int melody_notes__irrigationStarted = sizeof(melody__irrigationStarted) / sizeof(melody__irrigationStarted[0]) / 2;
const int melody_notes__errorMode = sizeof(melody__irrigationStarted) / sizeof(melody__irrigationStarted[0]) / 2;

const int melody_tempo__irrigationStarted = 111;
const int melody_tempo__errorMode = 225;


void playMelody__irrigationStarted() {
   playMelody(BUZZER, melody__irrigationStarted, melody_notes__irrigationStarted, melody_tempo__irrigationStarted, true);
}

void playMelody__errorMode() {
  for(int i = 0; i < 3; i++) {
    playMelody(BUZZER, melody__errorMode, melody_notes__errorMode, melody_tempo__errorMode, true);
    delay(180);
  }
   
}






//------------------       MEASURING THE SOIL VOLUMETRIC WATER       ----------------------//
#define WATER_IRRIGATION_PERCENT_THRESHOLD 50
#define WATER_IRRIGATION_DURATION_MILLIS 2500
#define WATER_IRRIGATION_TAKE_EFFECT_TIME 5000

// Read and map soil humidity sensors
void measureSoilHumidity(int *top_level_humidity, int *mid_level_humidity, int *bottom_level_humidity) {
  int top_sum = 0, mid_sum = 0, bot_sum = 0;
  
  for (int i = 0; i < 99; i++) {
    // calibration needed
    top_sum += cap(map(map(analogRead(TOP_SHS), 1023, 0, 0, 100), 0, 60, 0, 100), 100);
    mid_sum += cap(map(map(analogRead(MID_SHS), 1023, 0, 0, 100), 0, 60, 0, 100), 100);
    bot_sum += cap(map(map(analogRead(BOTTOM_SHS), 1023, 0, 0, 100), 0, 60, 0, 100), 100);
    delay(20);
  }
    (*top_level_humidity) = top_sum / 100;
    (*mid_level_humidity) = mid_sum / 100;
    (*bottom_level_humidity) = bot_sum / 100;

}

// Compute the overall soil volumetric water procent
void computeSoilVolumetricWater(int *soil_volumetric_water, int *top_level_humidity, int *mid_level_humidity, int *bottom_level_humidity) {
  /*
  *  wa = weight in average
  *  top_level_humidity - 15% wa
  *  mid_level_humidity - 60% wa
  *  bottom_level_humidity - 25% wa
  **/
  (*soil_volumetric_water) = (15 * (*top_level_humidity) + 60 * (*mid_level_humidity) + 25 * (*bottom_level_humidity)) / 100;
}






//------------------       IRRIGATION TOOLS       ----------------------//
#define WATER_IRRIGATION_PERCENT_THRESHOLD 50
#define WATER_IRRIGATION_DURATION_MILLIS 2500
#define WATER_IRRIGATION_TAKE_EFFECT_TIME 5000

/*
 *  Infinite error state. Error sound played. 
 * To EXIT this mode:  restart the board
**/
void errorMode() {
  do {
    playMelody__errorMode();
    delay(2000);
  } while(1);
}

void startWaterPump() {
  digitalWrite(WATER_PUMP, HIGH);
}

void stopWaterPump() {
  digitalWrite(WATER_PUMP, LOW);
}

int cap(int value, int max) {
  return (value > max)  ? max : value;
}

// water the plant for periodOfTime millis
void irrigatePlantForTimePeriod(int periodOfTime) {
  startWaterPump();
  delay(periodOfTime);
  stopWaterPump();  
}








//------------------      ARDUINO LOGIC      ----------------------//
void loop()
{
  // SOIL HUMIDITY ANALYSIS
  int top_level_humidity = 0;
  int mid_level_humidity = 0;
  int bottom_level_humidity = 0;
  int soil_volumetric_water = 0;
  measureSoilHumidity(&top_level_humidity, &mid_level_humidity, &bottom_level_humidity);
  computeSoilVolumetricWater(&soil_volumetric_water, &top_level_humidity, &mid_level_humidity, &bottom_level_humidity);
  
  // human debugging
  Serial.print(top_level_humidity);
  Serial.print(", ");
  Serial.print(mid_level_humidity);
  Serial.print(", ");
  Serial.print(bottom_level_humidity);
  Serial.print("  =>  ");
  Serial.println(soil_volumetric_water);  

  
  // decide if the plant need to be irrigated
  if (soil_volumetric_water < WATER_IRRIGATION_PERCENT_THRESHOLD) {

    // annonce irrigation start
    int wateredPot_soil_volumetric_water = 0;
    playMelody__irrigationStarted();
    Serial.println("The plant needs water");  

    // irrigate in cycles, until soil volumetric water is ok
    while (wateredPot_soil_volumetric_water < WATER_IRRIGATION_PERCENT_THRESHOLD) {

      // try a maximum of 10 times to complete current irrigation cycle
      bool irrigationCycleComplete = false;
      for (int try_number = 1; try_number < 10 && !irrigationCycleComplete; try_number++) {

        // START WATERING for a little time and after that wait until water settles
        irrigatePlantForTimePeriod(WATER_IRRIGATION_DURATION_MILLIS);
        delay(WATER_IRRIGATION_TAKE_EFFECT_TIME);

        // measure the new soil volumetric water
        measureSoilHumidity(&top_level_humidity, &mid_level_humidity, &bottom_level_humidity);
        computeSoilVolumetricWater(&wateredPot_soil_volumetric_water, &top_level_humidity, &mid_level_humidity, &bottom_level_humidity);

        // check if water reached the pot
        if(soil_volumetric_water < wateredPot_soil_volumetric_water) irrigationCycleComplete = true;
      }           

      // irrigation cycle failed, human maintenance needed (no water in reservoir)
      if(!irrigationCycleComplete) errorMode();
    }
    
  } // plant has enough water, check 5 min later
  else delay(300000);
}