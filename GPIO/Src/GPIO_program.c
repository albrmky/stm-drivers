/********************************/
/* Author 	: Noureldeen		*/
/* Date 	: 12 Aug 2020		*/
/* Version 	: V01				*/
/********************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"



void MGPIO_voidSetPinDirection(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Mode)
{
	switch(copy_u8PORT)
	{
		case GPIOA : 
					if(copy_u8PIN <=7)
					{
						GPIOA_CRL &= ~((0b1111)<<(4*copy_u8PIN));
						GPIOA_CRL  |= 	copy_u8Mode<<(4*copy_u8PIN);
					}
					else if(copy_u8PIN <=15)
					{
						GPIOA_CRH &= ~((0b1111)<<(4*(copy_u8PIN-8)));
						GPIOA_CRH  |= copy_u8Mode<<(4*(copy_u8PIN-8));
					}
					else
					{
						//error
					}
					break;
		case GPIOB :
					if(copy_u8PIN <=7)
					{
						GPIOB_CRL &= ~((0b1111)<<(4*copy_u8PIN));
						GPIOB_CRL  |= 	copy_u8Mode<<(4*copy_u8PIN);
					}
					else if(copy_u8PIN <=15)
					{
						GPIOB_CRH &= ~((0b1111)<<(4*(copy_u8PIN-8)));
						GPIOB_CRH  |= copy_u8Mode<<(4*(copy_u8PIN-8));
					}
					else
					{
						//error
					}
					break;
		case GPIOC :
					if(copy_u8PIN <=7)
					{
						GPIOC_CRL &= ~((0b1111)<<(4*copy_u8PIN));
						GPIOC_CRL  |= 	copy_u8Mode<<(4*copy_u8PIN);
					}
					else if(copy_u8PIN <=15)
					{
						GPIOC_CRH &= ~((0b1111)<<(4*(copy_u8PIN-8)));
						GPIOC_CRH  |= copy_u8Mode<<(4*(copy_u8PIN-8));
					}
					else
					{
						//error
					}
					break;
		

	}//switch
	
	
}//fun

void MGPIO_voidSetPinValue(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Value)
{
	switch(copy_u8PORT)
	{
		case GPIOA : 
					if(copy_u8PIN <=15)
					{
						if(copy_u8Value==GPIO_HIGH)
							SET_BIT(GPIOA_ODR,copy_u8PIN);
						else if (copy_u8Value==GPIO_LOW)
							CLR_BIT(GPIOA_ODR,copy_u8PIN);
						else
						{
							//error
						}
					}//if
					else
					{
						//error
					}
					break;
		case GPIOB :
					if(copy_u8PIN <=15)
					{
						if(copy_u8Value==GPIO_HIGH)
							SET_BIT(GPIOB_ODR,copy_u8PIN);
						else if (copy_u8Value==GPIO_LOW)
							CLR_BIT(GPIOB_ODR,copy_u8PIN);
						else
						{
							//error
						}
					}
					else
					{
						//error
					}
					break;
		case GPIOC :
					if(copy_u8PIN <=15)
					{
						if(copy_u8Value==GPIO_HIGH)
							SET_BIT(GPIOC_ODR,copy_u8PIN);
						else if (copy_u8Value==GPIO_LOW)
							CLR_BIT(GPIOC_ODR,copy_u8PIN);
						else
						{
							//error
						}
					}
					else
					{
						//error
					}
					break;
		

	}
	
	
}


u8   MGPIO_u8GetPinValue(u8 copy_u8PORT , u8 copy_u8PIN )
{
	u8 local=0;
	switch(copy_u8PORT)
	{
		case GPIOA : 
					if(copy_u8PIN <=15)
					{
						local= GET_BIT(GPIOA_IDR,copy_u8PIN);
					}
					else
					{
						//error
					}
					break;
		case GPIOB :
					if(copy_u8PIN <=15)
					{
						local= GET_BIT(GPIOB_IDR,copy_u8PIN);
					}
					else
					{
						//error
					}
					break;
		case GPIOC :
					if(copy_u8PIN <=15)
					{
						local= GET_BIT(GPIOC_IDR,copy_u8PIN);
					}
					else
					{
						//error
					}
					break;
		

	}
	return local;
	
}
void MGPIO_voidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Mode , u8 Copy_u8PortWidth)
{
	switch (Copy_u8Port)
	{
		case GPIOA:
				switch(Copy_u8PortWidth)
				{
					case GPIO_LOWER:
									for(int x=0; x<8;x++)
									{
										GPIOA_CRL &= ~((0b1111)<<(4*x));
										GPIOA_CRL  |= 	Copy_u8Mode<<(4*x);
									}
									break;

					case GPIO_HIGHER:
									for(int x=0; x<8;x++)
									{
										GPIOA_CRH &= ~((0b1111)<<(4*x));
										GPIOA_CRH  |= 	Copy_u8Mode<<(4*x);
									}
									break;
					case GPIO_ALL:
									for(int x=0; x<8;x++)
									{
										GPIOA_CRL &= ~((0b1111)<<(4*x));
										GPIOA_CRL  |= 	Copy_u8Mode<<(4*x);
									}
									for(int x=0; x<8;x++)
									{
										GPIOA_CRH &= ~((0b1111)<<(4*x));
										GPIOA_CRH  |= 	Copy_u8Mode<<(4*x);
									}
									break;
				}// small switch
					break;

		case GPIOB:
				switch(Copy_u8PortWidth)
				{
					case GPIO_LOWER:
									for(int x=0; x<8;x++)
									{
										GPIOB_CRL &= ~((0b1111)<<(4*x));
										GPIOB_CRL  |= 	Copy_u8Mode<<(4*x);
									}
									break;
					case GPIO_HIGHER:
									for(int x=0; x<8;x++)
									{
										GPIOB_CRH &= ~((0b1111)<<(4*x));
										GPIOB_CRH  |= 	Copy_u8Mode<<(4*x);
									}
									break;
					case GPIO_ALL:
									for(int x=0; x<8;x++)
									{
										GPIOB_CRL &= ~((0b1111)<<(4*x));
										GPIOB_CRL  |= 	Copy_u8Mode<<(4*x);
									}
									for(int x=0; x<8;x++)
									{
										GPIOB_CRH &= ~((0b1111)<<(4*x));
										GPIOB_CRH  |= 	Copy_u8Mode<<(4*x);
									}
									break;
				}// small switch
				break;

		case GPIOC:
				switch(Copy_u8PortWidth)
				{
					case GPIO_LOWER:
									for(int x=0; x<8;x++)
									{
										GPIOC_CRL &= ~((0b1111)<<(4*x));
										GPIOC_CRL  |= 	Copy_u8Mode<<(4*x);
									}
									break;
					case GPIO_HIGHER:
									for(int x=0; x<8;x++)
									{
										GPIOC_CRH &= ~((0b1111)<<(4*x));
										GPIOC_CRH  |= 	Copy_u8Mode<<(4*x);
									}
									break;
					case GPIO_ALL:
									for(int x=0; x<8;x++)
									{
										GPIOC_CRL &= ~((0b1111)<<(4*x));
										GPIOC_CRL  |= 	Copy_u8Mode<<(4*x);
									}
									for(int x=0; x<8;x++)
									{
										GPIOC_CRH &= ~((0b1111)<<(4*x));
										GPIOC_CRH  |= 	Copy_u8Mode<<(4*x);
									}
									break;
				}// small switch
				break;
	}//big switch
}


void MGPIO_voidWritePort(u8 Copy_u8Port, u16 Copy_u16Value)
{
	switch(Copy_u8Port)
	{
		case GPIOA :
					GPIOA_ODR = Copy_u16Value;
					break;
		case GPIOB :
					GPIOB_ODR = Copy_u16Value;
					break;
		case GPIOC :
					GPIOC_ODR = Copy_u16Value;
					break;
	}

}
