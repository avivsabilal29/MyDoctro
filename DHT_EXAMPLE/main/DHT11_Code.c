#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "DHT11.h"
void app_main()
{
    DHT11_init(GPIO_NUM_4);

    while(1) {
        printf("Temperature is %d \n", DHT11_read().temperature);
        printf("Humidity is %d\n", DHT11_read().humidity);
        printf("Status code is %d\n", DHT11_read().status);
        waitSeconds(1);
    }
}