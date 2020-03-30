/*
 * proximidade.h
 *
 *  Created on: 30 de mar de 2020
 *      Author: Heitor H V Guimarães
 */

#ifndef PROXIMIDADE_H_
#define PROXIMIDADE_H_

//Includes
#include "stm32xxx_hal.h"

#include <string.h>
#include <stdlib.h>
#include "X-NUCLEO-53L0A1.h"
#include "vl53l0x_api.h"
#include <limits.h>

/* Variaveis Globais ----------------------------------------------------------*/
int nDevPresent;

/** Time the initial 53L0 message is shown at power up */
#define ModeChangeDispTime  500

/** Time the initial 53L0 message is shown at power up */
#define WelcomeTime 660


typedef enum {
	LONG_RANGE 		= 0, /*!< Long range mode */
	HIGH_SPEED 		= 1, /*!< High speed mode */
	HIGH_ACCURACY	= 2, /*!< High accuracy mode */
} RangingConfig_e;


typedef enum {
	RANGE_VALUE 	= 0, /*!< Range displayed in cm */
	BAR_GRAPH 		= 1, /*!< Range displayed as a bar graph : one bar per sensor */
} DemoMode_e;


/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* Mx inicializacoes */
void MX_GPIO_Init(void);
void MX_TIM5_Init(void);

/* tempo de execucao sensor */
void TimeStamp_Init();
void TimeStamp_Reset();
uint32_t TimeStamp_Get();

/* Botao que muda de configuracao */
int BSP_GetPushButton(void);
int PusbButton_WaitUnPress(void);


/* Erros */
void HandleError(int err);
/* Sensor configuracoes */
int DetectSensors(int SetDisplay);
void SetupSingleShot(RangingConfig_e rangingConfig);
char RangeToLetter(VL53L0X_Dev_t *pDev, VL53L0X_RangingMeasurementData_t *pRange);
void Sensor_SetNewRange(VL53L0X_Dev_t *pDev, VL53L0X_RangingMeasurementData_t *pRange);
int RangeDemo(int UseSensorsMask, RangingConfig_e rangingConfig);
void ResetAndDetectSensor(int SetDisplay);

//usado para calcular a media da distancia que aciona a saida
void ArmazDistMedia();


#endif /* PROXIMIDADE_H_ */
