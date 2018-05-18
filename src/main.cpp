#include <mbed.h>
#include <rtos.h>
#include <mbed_events.h>

Serial pc(USBTX, USBRX);
Thread worker;
Thread anotherThread;
EventQueue queue ;

DigitalOut red(LED_RED,1); /* initial state 1 led is off */
DigitalOut blue(D9, 0);

void flash_red(void) {
    while(1){
        red.write(1);
        wait(0.5);
        red.write(0);
        wait(0.5);
    }
}

void flash_top(void)
{
  while(true)
  {
    blue.write(0);
    wait(0.5);
    blue.write(1);
    wait(0.5);
  }
}

int main() {

    // put your setup code here, to run once:
    worker.start( flash_red );
    anotherThread.start(flash_top);
    while(1) {
        // put your main code here, to run repeatedly:
    }
}
