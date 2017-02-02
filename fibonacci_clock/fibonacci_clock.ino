/*
An open-source binary clock for Arduino. 
Based on the code from by Rob Faludi (http://www.faludi.com)
Code under (cc) by Daniel Spillere Andrade, www.danielandrade.net
http://creativecommons.org/license/cc-gpl
*/

int second=0, minute=0, hour=0; //start the time on 00:00:00
int addhour,addmin,ledstats,i;

void setup() { //set outputs and inputs
pinMode(0, OUTPUT);pinMode(1, OUTPUT);pinMode(2, OUTPUT);pinMode(3, OUTPUT);pinMode(4, OUTPUT);
pinMode(5, OUTPUT);pinMode(6, OUTPUT);pinMode(7, OUTPUT);pinMode(8, OUTPUT);pinMode(9, OUTPUT);
pinMode(10, OUTPUT);pinMode(11, OUTPUT);pinMode(12, OUTPUT);pinMode(13, OUTPUT);pinMode(A0, OUTPUT);

pinMode(A1, INPUT);pinMode(A2,INPUT);pinMode(A3, INPUT);
}

void loop() {

static unsigned long lastTick = 0; // set up a local variable to hold the last time we moved forward one second
// (static variables are initialized once and keep their values between function calls)
// move forward one second every 1000 milliseconds and reset when millis overflows every 50 days

if (millis() - lastTick >= 1000 || millis() < lastTick - 1000) {
	lastTick = millis();
	second++;

}

// move forward one minute every 60 seconds
	if (second >= 60) {
	minute++;
	second = 0; // reset seconds to zero
}

// move forward one hour every 60 minutes
if (minute >=60) {
	hour++;
	minute = 0; // reset minutes to zero
}

if (hour >=24) {
	hour=0;
	minute = 0; // reset minutes to zero
}


	ledstats = digitalRead(A1);  // read input value, for setting leds off, but keeping count
	if (ledstats == HIGH) {
       
	for(i=0;i<=13;i++){
	digitalWrite(i, LOW);}
        digitalWrite(A0, LOW);
        
	} else  {

	//hours
	if(hour == 1 || hour == 4 || hour == 6 || hour == 9 || hour == 12 || hour == 14 || hour == 17 || hour == 19 || hour == 22 || hour == 25 || hour == 27 || hour == 28 || hour == 30 || hour == 33 || hour == 35 || hour == 38 || hour == 40 || hour == 43 || hour == 46 || hour == 48 || hour == 51 || hour == 53 || hour == 56 || hour == 59) {  digitalWrite(0, HIGH);} else {  digitalWrite(0,LOW);} //value 1
	if(hour == 2 || hour == 7 || hour == 10 || hour == 15 || hour == 20 || hour == 23 || hour == 28 || hour == 31 || hour == 36 || hour == 41 || hour == 44 || hour == 49 || hour == 54 || hour == 57) {digitalWrite(2, HIGH);} else {digitalWrite(2,LOW);} //value 2
        if(hour == 3 || hour == 4 || hour == 11 || hour == 12 || hour == 16 || hour == 17 || hour == 24 || hour == 25 || hour == 32 || hour == 33 || hour == 37 || hour == 38 || hour == 45 || hour == 46 || hour == 50 || hour == 51 || hour == 58 || hour == 59) {digitalWrite(4, HIGH);} else {digitalWrite(4,LOW);} //value 3
	if(hour == 5 || hour == 6 || hour == 7 || hour == 18 || hour == 19 || hour == 20 || hour == 26 || hour == 27 || hour == 28 || hour == 39 || hour == 40 || hour == 41 || hour == 52 || hour == 53 || hour == 54) {digitalWrite(6, HIGH);} else {digitalWrite(6,LOW);} //value 5
	if(hour == 8 || hour == 9 || hour == 10 || hour == 11 || hour == 12 || hour == 29 || hour == 30 || hour == 31 || hour == 32 || hour == 33 || hour == 42 || hour == 43 || hour == 44 || hour == 45 || hour == 46) {digitalWrite(8, HIGH);} else {digitalWrite(8,LOW);} //value 8
        if(hour == 13 || hour == 14 || hour == 15 || hour == 16 || hour == 17 || hour == 18 || hour == 19 || hour == 20 || hour == 48 || hour == 49 || hour == 50 || hour == 51 || hour == 52 || hour == 53 || hour == 54) {digitalWrite(10, HIGH);} else {digitalWrite(10,LOW);} //value 13
        if(hour == 21 || hour == 22 || hour == 23) {digitalWrite(12, HIGH);} else {digitalWrite(12,LOW);} //value 21

	//minutes 
	if(minute == 1 || minute == 4 || minute == 6 || minute == 9 || minute == 12 || minute == 14 || minute == 17 || minute == 19 || minute == 22 || minute == 25 || minute == 27 || minute == 28 || minute == 30 || minute == 33 || minute == 35 || minute == 38 || minute == 40 || minute == 43 || minute == 46 || minute == 48 || minute == 51 || minute == 53 || minute == 56 || minute == 59) {  digitalWrite(1, HIGH);} else {  digitalWrite(1,LOW);} //value 1
	if(minute == 2 || minute == 7 || minute == 10 || minute == 15 || minute == 20 || minute == 23 || minute == 28 || minute == 31 || minute == 36 || minute == 41 || minute == 44 || minute == 49 || minute == 54 || minute == 57) {digitalWrite(3, HIGH);} else {digitalWrite(3,LOW);} //value 2
        if(minute == 3 || minute == 4 || minute == 11 || minute == 12 || minute == 16 || minute == 17 || minute == 24 || minute == 25 || minute == 32 || minute == 33 || minute == 37 || minute == 38 || minute == 45 || minute == 46 || minute == 50 || minute == 51 || minute == 58 || minute == 59) {digitalWrite(5, HIGH);} else {digitalWrite(5,LOW);} //value 3
	if(minute == 5 || minute == 6 || minute == 7 || minute == 18 || minute == 19 || minute == 20 || minute == 26 || minute == 27 || minute == 28 || minute == 39 || minute == 40 || minute == 41 || minute == 52 || minute == 53 || minute == 54) {digitalWrite(7, HIGH);} else {digitalWrite(7,LOW);} //value 5
	if(minute == 8 || minute == 9 || minute == 10 || minute == 11 || minute == 12 || minute == 29 || minute == 30 || minute == 31 || minute == 32 || minute == 33 || minute == 42 || minute == 43 || minute == 44 || minute == 45 || minute == 46) {digitalWrite(9, HIGH);} else {digitalWrite(9,LOW);} //value 8
        if(minute == 13 || minute == 14 || minute == 15 || minute == 16 || minute == 17 || minute == 18 || minute == 19 || minute == 20 || minute == 48 || minute == 49 || minute == 50 || minute == 51 || minute == 52 || minute == 53 || minute == 54) {digitalWrite(11, HIGH);} else {digitalWrite(11,LOW);} //value 13
        if(minute == 21 || minute == 22 || minute == 23 || minute == 24 || minute == 25 || minute == 26 || minute == 27 || minute == 28 || minute == 29 || minute == 30 || minute == 31 || minute == 32 || minute == 33 || minute == 55 || minute == 56 || minute == 57 || minute == 58 || minute == 59) {digitalWrite(13, HIGH);} else {digitalWrite(13,LOW);} //value 21
        if(minute == 34 || minute == 35 || minute == 36 || minute == 37 || minute == 38 || minute == 39 || minute == 40 || minute == 41 || minute == 42 || minute == 43 || minute == 44 || minute == 45 || minute == 46 || minute == 47 || minute == 48 || minute == 49 || minute == 50 || minute == 51 || minute == 52 || minute == 53 || minute == 54 || minute == 55 || minute == 56 || minute == 57 || minute == 58 || minute == 59) {digitalWrite(A0, HIGH);} else {digitalWrite(A0,LOW);} //value 34

	}

	addhour = digitalRead(A2);    // add one minute when pressed
	 if(addhour == HIGH) {
	 hour++;
	 second=0;
	 delay(500);
	}
  
	addmin = digitalRead(A3);    // add one hour when pressed
	 if(addmin == HIGH) {
	 minute++;
	 second=0;
	 delay(500);
	}


}

