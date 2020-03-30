/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2015 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "proximidade.h"
int main(void)
{

  /* USER CODE BEGIN 1 */
  //tratamento do sensor
    int ExitWithLongPress;
  //valor ira pegar o primeiro sensor
  int UseSensorsMask = 1<<XNUCLEO53L0A1_DEV_CENTER;
  //valores para aparecer no display
  DemoMode_e DemoMode = RANGE_VALUE;
  RangingConfig_e RangingConfig = HIGH_ACCURACY;
  char *RangingConfigTxt[3] = {"dISt", "vELc", "PrEc"};

  //char *RangingConfigTxt[3] = {"LR", "HS", "HA"};
  char WelcomeMsg[]="Ola sou o detector VL53L0X com mcu " MCU_NAME ".\n";

  char *DemoModeTxt[2] = {"rng", "bar"};

  /** How many device detect set by @a DetectSensors()*/
//  int nDevPresent=0;
  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();

  /* Initialize timestamping for UART logging */
  TimeStamp_Init();

  /* USER CODE BEGIN 2 */
  XNUCLEO53L0A1_Init();
  uart_printf(WelcomeMsg);
  XNUCLEO53L0A1_SetDisplayString("conf");
//  XNUCLEO53L0A1_SetDisplayString("53L0");
  HAL_Delay(WelcomeTime);
  ResetAndDetectSensor(1);

  /* Set VL53L0X API trace level */
  VL53L0X_trace_config(NULL, TRACE_MODULE_NONE, TRACE_LEVEL_NONE, TRACE_FUNCTION_NONE);
//  VL53L0X_trace_config(NULL, TRACE_MODULE_API, TRACE_LEVEL_DEBUG, TRACE_FUNCTION_I2C); // No Trace
//  VL53L0X_trace_config(NULL,TRACE_MODULE_ALL, TRACE_LEVEL_ALL, TRACE_FUNCTION_ALL); // Full trace


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */
      /* Display demo mode */
      XNUCLEO53L0A1_SetDisplayString(DemoModeTxt[DemoMode]);
      HAL_Delay(ModeChangeDispTime);

//      /* Display Ranging config */

	  HAL_Delay(ModeChangeDispTime);
//
//	  /* Reset and Detect all sensors */
      ResetAndDetectSensor(0);
//
//      /* Reset Timestamping */
      TimeStamp_Reset();
//

      /* Start Ranging demo */
      ExitWithLongPress = RangeDemo(UseSensorsMask, RangingConfig);

      /* Blue button has been pressed (long or short press) */
      if(ExitWithLongPress){
    	  /* Long press : change demo mode if multiple sensors present*/
    	  if( nDevPresent >1 ){
    		  /* If more than one sensor is present then toggle demo mode */
    		  DemoMode = (DemoMode == RANGE_VALUE) ? BAR_GRAPH : RANGE_VALUE;
    		  UseSensorsMask = (DemoMode == BAR_GRAPH) ? 0x7 : 1<<XNUCLEO53L0A1_DEV_CENTER;
    	  }
      } else {
    	  /* Short press : change ranging config */
    	  RangingConfig = (RangingConfig == LONG_RANGE) ? HIGH_SPEED : ((RangingConfig == HIGH_SPEED) ? HIGH_ACCURACY : LONG_RANGE);
      }
  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}

