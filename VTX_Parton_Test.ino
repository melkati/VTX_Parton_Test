<<<<<<< HEAD
/*
 * This sketch controls a Partom or simmilar VTX transmit frequency
 * Copyright (c) 2017 Mario Elkati (Mariete)
 * melkati@gmail.com
 */

/*-----( Declare Constants )-----*/
static const int FREQ[] = {1010, 1040, 1060, 1080, 1100, 1120, 1140, 1160, 1180, 1200, 1240, 1258, 1280, 1320, 1360};
static unsigned long COUNTER18BIT_OLD[] = {
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001, /* 12 */
  0b010000010010110001,
  0b010000010010110001, /* 14 */
  0b010000010010110001};
static unsigned long COUNTER18BIT[] = { // Data original PLL for 1280Mhz
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001, /* 12 */
  0b010000001100100001,
  0b010000001100100001, /* 14 */
  0b010000001100100001};
static unsigned long COUNTER19BIT[] = {
  0b0110001010100001000,
  0b0110010110001000000,
  0b0110011110000010000,
  0b0110100101101100000,
  0b0110101101100110000,
  0b0110110101100000000,
  0b0110111101001010000,
  0b0111000101000100000,
  0b0111001100101110000,
  0b0111010100101000000,
  0b0111100100001100000,
  0b0111101011001101000, /* 12 */
  0b0111110100000001010,
  0b1000000011100100000, /* 14 */
  0b1000010011001000000};
#define VTXDataPin 7
#define VTXClockPin 8
#define VTXLatchEnablePin 9
#define VTXChannelChangePin 3

/*-----( Declare Variables )-----*/
byte VTXChannelOld = 0;
byte VTXChannel = 13;

void setup()
{
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(VTXDataPin, OUTPUT);
  pinMode(VTXClockPin, OUTPUT);
  pinMode(VTXLatchEnablePin, OUTPUT);
  pinMode(VTXChannelChangePin, INPUT_PULLUP);
  digitalWrite(VTXChannelChangePin, HIGH);
  digitalWrite(VTXDataPin, LOW);
  digitalWrite(VTXClockPin, LOW);
  digitalWrite(VTXLatchEnablePin, LOW);
}


void loop()
{
  if (!digitalRead(VTXChannelChangePin))
  {
    while (!digitalRead(VTXChannelChangePin)) {
      //
    }
    VTXChannel++;
    Serial.println("Button pressed...");
  }

  if (VTXChannel != VTXChannelOld)
  {
    Serial.println("Changing channel...");
    ChangeChannel();
  }

//  delay(9500);
//  digitalWrite(LED_BUILTIN, HIGH);
//  delay(500);
//  digitalWrite(LED_BUILTIN, LOW);
//  VTXChannel = 13;
//  ChangeChannel(VTXChannel);
//  delay(9500);
//  digitalWrite(LED_BUILTIN, HIGH);
//  delay(500);
//  digitalWrite(LED_BUILTIN, LOW);
//  VTXChannel = 11;
//  ChangeChannel(VTXChannel);
}

void bitBang(unsigned long pattern, byte numBits)  // This function is what bitbangs the data
{
//  digitalWriteFast(VTXDataPin, LOW);
//  digitalWriteFast(VTXClockPin, LOW);
//  delay(1);
  for(int i=numBits-1; i>-1; i--)
  {
    digitalWriteFast(VTXDataPin, bitRead(pattern, i));
    delayMicroseconds(300);
    digitalWriteFast(VTXClockPin, HIGH);
    delayMicroseconds(350);
    digitalWriteFast(VTXClockPin, LOW);
    Serial.print(bitRead(pattern, i));
    delayMicroseconds(50);

  }
  digitalWriteFast(VTXLatchEnablePin, HIGH);
  delayMicroseconds(500);
  digitalWriteFast(VTXLatchEnablePin, LOW);
  Serial.println("");
  digitalWrite(VTXDataPin, LOW);
}

void ChangeChannel()
{
  Serial.print("VTXChannel: ");
  Serial.println(VTXChannel);
  Serial.print("VTXChannelOld: ");
  Serial.println(VTXChannelOld);
  if (VTXChannel < 1) {
    VTXChannel = 15;
  }
  if (VTXChannel > 15) {
    VTXChannel = 1;
  }
  switch (VTXChannel) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
      Serial.print("Change to channel: ");
      Serial.println(VTXChannel);
      bitBang(COUNTER18BIT[VTXChannel-1], 18);
      bitBang(COUNTER19BIT[VTXChannel-1], 19);
      VTXChannelOld = VTXChannel;
      break;
  }
}

void digitalWriteFast(uint8_t pin, uint8_t x) {
  if (pin / 8) { // pin >= 8
    PORTB ^= (-x ^ PORTB) & (1 << (pin % 8));
  }
  else {
    PORTD ^= (-x ^ PORTD) & (1 << (pin % 8));
  }
}
=======
/*
 * This sketch controls a Partom or simmilar VTX transmit frequency
 * Copyright (c) 2017 Mario Elkati (Mariete)
 * melkati@gmail.com
 */

/*-----( Declare Constants )-----*/
static const int FREQ[] = {1010, 1040, 1060, 1080, 1100, 1120, 1140, 1160, 1180, 1200, 1240, 1258, 1280, 1320, 1360};
static unsigned long COUNTER18BIT_OLD[] = {
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001,
  0b010000010010110001, /* 12 */
  0b010000010010110001,
  0b010000010010110001, /* 14 */
  0b010000010010110001};
static unsigned long COUNTER18BIT[] = { // Data original PLL for 1280Mhz
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001,
  0b010000001100100001, /* 12 */
  0b010000001100100001,
  0b010000001100100001, /* 14 */
  0b010000001100100001};
static unsigned long COUNTER19BIT[] = {
  0b0110001010100001000,
  0b0110010110001000000,
  0b0110011110000010000,
  0b0110100101101100000,
  0b0110101101100110000,
  0b0110110101100000000,
  0b0110111101001010000,
  0b0111000101000100000,
  0b0111001100101110000,
  0b0111010100101000000,
  0b0111100100001100000,
  0b0111101011001101000, /* 12 */
  0b0111110100000001010,
  0b1000000011100100000, /* 14 */
  0b1000010011001000000};
#define VTXDataPin 7
#define VTXClockPin 8
#define VTXLatchEnablePin 9
#define VTXChannelChangePin 3

/*-----( Declare Variables )-----*/
byte VTXChannelOld = 0;
byte VTXChannel = 13;

void setup()
{
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(VTXDataPin, OUTPUT);
  pinMode(VTXClockPin, OUTPUT);
  pinMode(VTXLatchEnablePin, OUTPUT);
  pinMode(VTXChannelChangePin, INPUT_PULLUP);
  digitalWrite(VTXChannelChangePin, HIGH);
  digitalWrite(VTXDataPin, LOW);
  digitalWrite(VTXClockPin, LOW);
  digitalWrite(VTXLatchEnablePin, LOW);
}


void loop()
{
  if (!digitalRead(VTXChannelChangePin))
  {
    while (!digitalRead(VTXChannelChangePin)) {
      //
    }
    VTXChannel++;
    Serial.println("Button pressed...");
  }

  if (VTXChannel != VTXChannelOld)
  {
    Serial.println("Changing channel...");
    ChangeChannel();
  }

//  delay(9500);
//  digitalWrite(LED_BUILTIN, HIGH);
//  delay(500);
//  digitalWrite(LED_BUILTIN, LOW);
//  VTXChannel = 13;
//  ChangeChannel(VTXChannel);
//  delay(9500);
//  digitalWrite(LED_BUILTIN, HIGH);
//  delay(500);
//  digitalWrite(LED_BUILTIN, LOW);
//  VTXChannel = 11;
//  ChangeChannel(VTXChannel);
}

void bitBang(unsigned long pattern, byte numBits)  // This function is what bitbangs the data
{
//  digitalWriteFast(VTXDataPin, LOW);
//  digitalWriteFast(VTXClockPin, LOW);
//  delay(1);
  for(int i=numBits-1; i>-1; i--)
  {
    digitalWriteFast(VTXDataPin, bitRead(pattern, i));
    delayMicroseconds(300);
    digitalWriteFast(VTXClockPin, HIGH);
    delayMicroseconds(350);
    digitalWriteFast(VTXClockPin, LOW);
    Serial.print(bitRead(pattern, i));
    delayMicroseconds(50);

  }
  digitalWriteFast(VTXLatchEnablePin, HIGH);
  delayMicroseconds(500);
  digitalWriteFast(VTXLatchEnablePin, LOW);
  Serial.println("");
  digitalWrite(VTXDataPin, LOW);
}

void ChangeChannel()
{
  Serial.print("VTXChannel: ");
  Serial.println(VTXChannel);
  Serial.print("VTXChannelOld: ");
  Serial.println(VTXChannelOld);
  if (VTXChannel < 1) {
    VTXChannel = 15;
  }
  if (VTXChannel > 15) {
    VTXChannel = 1;
  }
  switch (VTXChannel) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
      Serial.print("Change to channel: ");
      Serial.println(VTXChannel);
      bitBang(COUNTER18BIT[VTXChannel-1], 18);
      bitBang(COUNTER19BIT[VTXChannel-1], 19);
      VTXChannelOld = VTXChannel;
      break;
  }
}

void digitalWriteFast(uint8_t pin, uint8_t x) {
  if (pin / 8) { // pin >= 8
    PORTB ^= (-x ^ PORTB) & (1 << (pin % 8));
  }
  else {
    PORTD ^= (-x ^ PORTD) & (1 << (pin % 8));
  }
}
>>>>>>> b532aca7b8c1784f3c9359babe596d07b61efbeb
