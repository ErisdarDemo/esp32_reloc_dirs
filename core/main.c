/**************************************************************************************************/
/** @file     main.c
 *  @brief    x
 *  @details  x
 *
 *  @author   Justin Reina, Firmware Engineer
 *  @created  3/14/25
 *  @last rev 3/17/25
 *
 *  @section    Opens
 *      none current
 *
 *  @section    Legal Disclaimer
 *      ©2025 Justin Reina. All rights reserved. All contents of this source file and/or any other
 *      related source files are the explicit property of Justin Reina. Do not distribute.
 *      Do not copy.
 */
/**************************************************************************************************/

//************************************************************************************************//
//                                            INCLUDES                                            //
//************************************************************************************************//

//Standard Library Includes
#include <stdio.h>
#include <inttypes.h>

//FreeRTOS Includes
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//SDK Includes
#include "sdkconfig.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"


//************************************************************************************************//
//                                          PUBLIC FUNCTIONS                                      //
//************************************************************************************************//

/**************************************************************************************************/
/** @fcn        void app_main(void)
 *  @brief      x
 *  @details    x
 */
/**************************************************************************************************/
void app_main(void) {

	//Locals
	esp_err_t stat;									/* sdk api response							  */
    esp_chip_info_t chip_info;						/* chip information retrieved				  */
    uint32_t flash_size;							/* chip flash size (# bytes) 				  */
    unsigned major_rev;								/* chip info major revision number 			  */
    unsigned minor_rev;								/* chip info minor revision number 			  */


	//Init Notify
    printf("Hello world!\n");


    //--------------------------------------- Print Stats ----------------------------------------//

    //Get Info
    esp_chip_info(&chip_info);

    //Print chip info
    printf("This is %s chip with %d CPU core(s), %s%s%s%s, ",
           CONFIG_IDF_TARGET,
           chip_info.cores,
           (chip_info.features & CHIP_FEATURE_WIFI_BGN)   ? "WiFi/" : "",
           (chip_info.features & CHIP_FEATURE_BT)         ? "BT" : "",
           (chip_info.features & CHIP_FEATURE_BLE)        ? "BLE" : "",
           (chip_info.features & CHIP_FEATURE_IEEE802154) ? ", 802.15.4 (Zigbee/Thread)" : "");

	//Get Revs
    major_rev = (chip_info.revision / 100);
    minor_rev = (chip_info.revision % 100);

	//Print Revs
    printf("silicon revision v%d.%d, ", major_rev, minor_rev);

	//Check Size
	stat = esp_flash_get_size(NULL, &flash_size);

	//Safety
    if(stat != ESP_OK) {
        printf("Get flash size failed, aborting");
        return;
    }

	//Print Size
    printf("%" PRIu32 "MB %s flash\n", 
    			(flash_size / (uint32_t)(1024 * 1024)),
           		(chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

	//Print Heap
    printf("Minimum free heap size: %" PRIu32 " bytes\n", esp_get_minimum_free_heap_size());

	//Notify
    for(int i = 10; i >= 0; i--) {

        printf("Restarting in %d seconds...\n", i);

        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }


    //------------------------------------------- Exit -------------------------------------------//

    printf("Restarting now.\n");

    fflush(stdout);

    esp_restart();
}

