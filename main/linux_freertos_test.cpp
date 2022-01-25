#include <stdio.h>
#include <stddef.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

#ifndef UNUSED
#define UNUSED(x) (void)(sizeof(x))
#endif

static TimerHandle_t xDummyTimer = NULL;

static void timer_button_callback(TimerHandle_t pxTimer);
static void process_timer_callback(TimerHandle_t *pxTimer);

static void timer_button_callback(TimerHandle_t pxTimer) {
	if (pxTimer != NULL) {
		process_timer_callback(&pxTimer);
	}
}

static void process_timer_callback(TimerHandle_t *pxTimer) {
	if (xTimerIsTimerActive(*pxTimer) != pdFALSE) {
		xTimerStop(*pxTimer, 100);
	}
	if (xTimerReset(*pxTimer, portMAX_DELAY) == pdPASS) {
		printf("Timer Reset\n");
	}
}

void app_main(void) {
	#ifdef PROJECT_PLATFORM_LINUX
	printf("Running on Linux.\n");
	#elif PROJECT_PLATFORM_ESP32
	printf("Running on ESP32.\n");
	#else
	printf("Running on unknown.\n");
	#endif
	xDummyTimer = xTimerCreate("dummyTimer",  // Just a text name, not used by the kernel.
	                           pdMS_TO_TICKS(100),
	                           pdFALSE,                                                                                                                                                                                                                                                                                                                                                 // The timer is a one-shot timer.
	                           (void *) NULL,  // context will stay the same forever
	                           timer_button_callback
	                           );

	if (xTimerStart(xDummyTimer, portMAX_DELAY) == pdPASS) {
		printf("Timer started\n");
	}
	while (1) {
		vTaskDelay(pdMS_TO_TICKS(500));
		printf("Heartbeat\n");
	}
}

#ifdef PROJECT_PLATFORM_LINUX
void app_main_thread(void *pvParameters) {
	UNUSED(pvParameters);
	app_main();
	vTaskDelete(NULL);
}

int main(int argc, const char * argv[]) {
	xTaskCreate(app_main_thread, "app_main_thread", 1000, NULL, 1, NULL );
	/* Run the FreeRTOS tasks */
	vTaskStartScheduler();
	return 0;
}
#endif
