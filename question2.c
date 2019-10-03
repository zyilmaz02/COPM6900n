#include "tm4c123gh6pm.h"

void PortC_init (void){
	SYSCTL_RCGCGPIO_R |=0x02;
	GPIO_PORTF_DIR_R |=0x0E;
	GPIO_PORTC_DEN_R |=0x0E;
	//

SYSCTL_RCGC2_R |= 0x04; // 1) activate Port C

GPIO_PORTC_LOCK_R = 0x4C4F434B; 
GPIO_PORTC_CR_R |= 0xF0; // allow changes to PC4-7 The others are used JTAG on the board
GPIO_PORTC_AMSEL_R =0x00; 
GPIO_PORTC_PCTL_R =0x00; 
GPIO_PORTC_AFSEL_R =0x00; 
GPIO_PORTC_DIR_R |= 0xF0; //Output PC4-PC7
GPIO_PORTC_DEN_R |= 0xF0;
	
}

void PortF_Init(void){
	SYSCTL_RCGCGPIO_R |=0x20;
	GPIO_PORTF_LOCK_R= 0x4C4F434B;
	GPIO_PORTF_CR_R |=0x1F;
	GPIO_PORTF_DIR_R |=0x0E;
	GPIO_PORTF_DEN_R |=0x0E;
}
void portF_led(uint32_t data){
	for(int j=0; j<8; j++){
	GPIO_PORTF_DATA_R |= data;
	g(1000000);
	GPIO_PORTF_DATA_R ^=data;
	g(1000000);
	
	}
	
}

int main(){
	PortF_Init();
	uint32_t dta;
	while(1){
		dta=0x08;
		for(int i=0;i<3; i++){
			portF_led(dta);
			g(10000000);
			dta=dta>>1;
			
		}
	}
	
}
int g(int d){
	while(0<d)
		d--;
	return d;
};
