#include "DigitalOut.h"
#include "mbed.h"
#include "BME280.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     500ms
InterruptIn ibutton1(BUTTON1);
DigitalOut oled1(LED1);
BME280 sensor(PB_9, PB_8);
int r=31;
void pressed() {
    if (r ==31){
        r = 33;

    }
    else r=31;

}

int main()
{

    ibutton1.rise(&pressed);
    {
    while (1) {
        printf("%d degC, %d hPa, %d %%\n ",
        (int)sensor.getTemperature(),
        (int)sensor.getPressure(),
        (int)sensor.getHumidity(),r);
        wait_us(100000);
    
        if((int)sensor.getTemperature()>r)
        {
            oled1=1;
        }
        else 
        {
            oled1=0;
        }
    }  
    
    }   
}