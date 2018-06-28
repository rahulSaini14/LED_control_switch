#include<stm32F4xx_hal.h>

void config(){
		__HAL_RCC_GPIOA_CLK_ENABLE();
	  __HAL_RCC_GPIOD_CLK_ENABLE();
	
		GPIO_InitTypeDef conf;
		conf.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
		conf.Mode = GPIO_MODE_OUTPUT_PP;
		HAL_GPIO_Init(GPIOD,&conf);
	
		conf.Pin = GPIO_PIN_0;
		conf.Mode = GPIO_MODE_INPUT;
		HAL_GPIO_Init(GPIOA,&conf);
	
}

int main(){
		config();
		while(1){
			if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == GPIO_PIN_SET){
				HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_SET);
			}
			else {
				HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_RESET);
			}
				
		}
}