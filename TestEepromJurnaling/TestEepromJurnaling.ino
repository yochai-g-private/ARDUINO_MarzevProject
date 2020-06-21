/*
 Name:		TestEepromJurnaling.ino
 Created:	1/26/2020 7:18:42 PM
 Author:	MCP
*/

#include "NYG.h"
#include "MicroController.h"
#include "EepromJurnal.h"

using namespace NYG;

// the setup function runs once when you press reset or power the board
void setup() 
{
#if 0
	if (!RTC::Begin())
	{
		LOGGER << "RTC init failed" << NL;

		bool OK = RTC::SetFromSerial(0);

		if (OK)
		{
			MicroController::Restart();
		}
		else
		{
			LOGGER << "RTC not init." << NL;
			//setTimeFromBuildTime();
		}
	}
#endif

	LOGGER << "EepromJurnalWriter::Begin" << NL;
	EepromJurnalWriter::Begin();

	LOGGER << "EepromJurnalWriter::Write" << NL;
	EepromJurnalWriter::Write("My first jurnal line!");

	LOGGER << "EepromJurnalReader::Print" << NL;
	EepromJurnalReader::Print();
}

// the loop function runs over and over again until power down or reset
void loop() 
{
  
}

extern const char* gbl_build_date = __DATE__;
extern const char* gbl_build_time = __TIME__;
