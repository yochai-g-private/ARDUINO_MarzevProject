/*
 Name:		SizeTest.ino
 Created:	1/24/2020 9:05:18 AM
 Author:	MCP
*/

#include <Arduino.h>

enum PIN_NUMBERS
{
	SENSOR_PIN		= 6,
};

bool ON;

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(SENSOR_PIN, INPUT_PULLUP);
	Serial.begin(115200UL);

	ON = digitalRead(SENSOR_PIN) == LOW;
}

// the loop function runs over and over again until power down or reset
void loop() 
{
	bool on = digitalRead(SENSOR_PIN) == LOW;

	if (ON == on)
		return;

	ON = on;

	Serial.println((ON) ? "ON" : "OFF");
}
