/*
Nunchuck functions  -- Talk to a Wii Nunchuck

Developer: Numair Ahmed, B.S. Mechanical Engineering
University of California, Davis;
Mechanical and Aerospace Engineering Department;
PI: Dr. Barbara Linke

Originally developed: 2007-11 Tod E. Kurt, http://todbot.com/blog/
The Wii Nunchuck reading code originally from Windmeadow Labs
http://www.windmeadow.com/node/42

RELEASE NOTES:
7/21/2015 - Initial modifications to original script done by Tod E. Kurt
8/13/2015 - Test run with WiiChuk and adapter

*/

#include <Wire.h>
#include "nunchuck_funcs.h"

int loop_cnt=0;

byte accx,accy,zbut,cbut,joyx, joyy;
int ledPin = 13;


void setup()
{
    Serial.begin(19200);
    nunchuck_setpowerpins();
    nunchuck_init(); // send the initilization handshake

    Serial.print("WiiChuckDemo ready\n");
}

void loop()
{
    if( loop_cnt > 100 ) { // every 100 msecs get new data
        loop_cnt = 0;

        nunchuck_get_data();

        accx  = nunchuck_accelx(); // ranges from approx 70 - 182
        accy  = nunchuck_accely(); // ranges from approx 65 - 173
        zbut = nunchuck_zbutton();
        cbut = nunchuck_cbutton();
        joyx = nunchuck_joyx();
        joyy = nunchuck_joyy();

        Serial.print("\taccx: "); Serial.print((byte)accx,DEC);
        Serial.print("\taccy: "); Serial.print((byte)accy,DEC);
        Serial.print("\tzbut: "); Serial.print((byte)zbut,DEC);
        Serial.print("\tcbut: "); Serial.println((byte)cbut,DEC);
        Serial.print("\tjoyx: "); Serial.print((byte)joyx,DEC);
        Serial.print("\tjoyy: "); Serial.print((byte)joyy,DEC);    
    }
    loop_cnt++;
    delay(1);
}
