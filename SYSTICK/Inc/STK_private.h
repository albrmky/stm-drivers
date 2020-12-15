/********************************/
/* Author 	: Noureldeen		*/
/* Date 	: 2 Sep 2020		*/
/* Version 	: V01				*/
/********************************/



#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H


#define STK_CTRL    *((volatile u32*)0xE000E010)
#define STK_LOAD    *((volatile u32*)0xE000E014)
#define STK_VAL     *((volatile u32*)0xE000E018)
#define STK_CALIB   *((volatile u32*)0xE000E01C)

#define AHB_8 	0
#define AHB		1

#define STK_ENABLE	1
#define STK_DISABLE 0


#endif
