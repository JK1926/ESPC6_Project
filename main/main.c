/***********************************************************************
 * INCLUDES
 **********************************************************************/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "hello_world.h"


/***********************************************************************
 * CONSTANTS
 **********************************************************************/
/*
 *  ESP Project Tasks - Enable (1) / Disable (0)
 */
#define ENABLE_LED_BLINK_TASK         1

/*
 *  VWD Tasks Name
 */
#define HELLO_WORLD_TASK_NAME              "vHelloWorld"

/*
 *  VWD Tasks Stack Size
 */
#define STACK_SIZE_HELLO_WORLD_TASK          (1024 * 4)


/*
 *  VWD Tasks Priority
 */
#define HELLO_WORLD_TASK_PRIORITY              (configMAX_PRIORITIES)    //HelloWorld Task priority 25

/*
 *  Tag for Debug Print
 */
#define TAG "MAIN_TASK"

/***********************************************************************
 * PRIVATE VARIABLES
 **********************************************************************/
TaskHandle_t pvHelloWorldTaskHandle = NULL;


/***********************************************************************
 * PRIVATE FUNCTION PROTOTYPES
 **********************************************************************/


/***********************************************************************
 * PRIVATE FUNCTIONS
 **********************************************************************/


/***********************************************************************
 * PUBLIC FUNCTIONS
 **********************************************************************/
void app_main(void) {
	printf("[APP] ESP IDF version: %s\n", esp_get_idf_version());
	ESP_LOGI(TAG, "\nPrio= %d HelloWorldTask     = %d\n",
			HELLO_WORLD_TASK_PRIORITY, STACK_SIZE_HELLO_WORLD_TASK);

	xTaskCreate(vHelloWorld, HELLO_WORLD_TASK_NAME, STACK_SIZE_HELLO_WORLD_TASK,
			HELLO_WORLD_TASK_NAME, HELLO_WORLD_TASK_PRIORITY, &pvHelloWorldTaskHandle);
}
