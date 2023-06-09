#include <avr/delay.h>
#include "../../MCAL/DIO/DIO.h"
#include "LCD.h"
/***************************************************************************************/
/********************************** Macros *********************************************/
/***************************************************************************************/
#define LCD_GROUP_DATA GROUPB
#define LCD_GROUP_CONTROL GROUPD
#define LCD_RS_PIN PIN_4
#define LCD_E_PIN PIN_5

#define LCD_HOME 0x02
#define LCD_SET_8FUNCTION 0x38
#define LCD_CLEAR 0x01
#define LCD_DATA_ENTERY 0x06
#define LCD_DISPLAY_ON 0x0C


#define degree_sysmbol 0xdf
#define degree_sysmbol_i  0xdf
void LCD_Vinit(void) {
	/* set DDRA as OUTPUTs pins */
	DIO_SetGroupDirection(LCD_GROUP_DATA, 0xFF);
	/* confguire RS & E as output */
	DIO_SetPinDirection(LCD_GROUP_CONTROL, LCD_RS_PIN, OUTPUT);
	DIO_SetPinDirection(LCD_GROUP_CONTROL, LCD_E_PIN, OUTPUT);

	_delay_ms(30);
	LCD_Send_Command(LCD_HOME);
	_delay_ms(15);

	LCD_Send_Command(LCD_SET_8FUNCTION);
	_delay_ms(1);

	LCD_Send_Command(LCD_DISPLAY_ON);
	_delay_ms(1);

	LCD_Send_Command(LCD_CLEAR);
	_delay_ms(2);

	LCD_Send_Command(LCD_DATA_ENTERY);
	_delay_ms(15);

}

void LCD_Send_Command(u8 command) {
	DIO_SetPinValue(LCD_GROUP_CONTROL, LCD_RS_PIN, LOW);
	_delay_us(1);
	DIO_SetPinValue(LCD_GROUP_CONTROL, LCD_E_PIN, HIGH);
	_delay_us(1);
	DIO_SetGroupValue(LCD_GROUP_DATA, command);
	_delay_us(1);
	DIO_SetPinValue(LCD_GROUP_CONTROL, LCD_E_PIN, LOW);
	_delay_us(5);
	DIO_SetPinValue(LCD_GROUP_CONTROL, LCD_E_PIN, HIGH);
	_delay_ms(10);
}

void LCD_Send_Data(u8 data) {
	DIO_SetPinValue(LCD_GROUP_CONTROL, LCD_RS_PIN, HIGH);
	_delay_us(1);
	DIO_SetPinValue(LCD_GROUP_CONTROL, LCD_E_PIN, HIGH);
	_delay_us(1);
	DIO_SetGroupValue(LCD_GROUP_DATA, data);
	_delay_us(1);
	DIO_SetPinValue(LCD_GROUP_CONTROL, LCD_E_PIN, LOW);
	_delay_us(5);
	DIO_SetPinValue(LCD_GROUP_CONTROL, LCD_E_PIN, HIGH);
	_delay_ms(10);
}

void LCD_Send_string(u8 *ptr) {
	u8 index = 0;
	while (ptr[index] != '\0') {
		LCD_Send_Data(ptr[index]);
		index++;
	}

}

void LCD_Clear(void) {
	LCD_Send_Command(LCD_CLEAR);
}

void LCD_GOTOXY(u8 raw, u8 col) {

	switch (raw) {
	case 1:
		LCD_Send_Command((0x00 + col) | (0x80));
		break;
	case 2:
		LCD_Send_Command((0x40 + col) | (0x80));
		break;
	default:
		break;
	}

}
///////////////////////////////////////////////////
void CLCD_voidSendFloatNumber(f32 Copy_u64Number)
{
	s32 LOC_s32IntNum=Copy_u64Number;
	Copy_u64Number=Copy_u64Number-LOC_s32IntNum;
	Copy_u64Number*=100;
	CLCD_voidSendNumber(LOC_s32IntNum);
	LCD_Send_Data('.');
	CLCD_voidSendNumber((u32)Copy_u64Number );

}
void CLCD_voidSendNumber(u64 Copy_u64Number)
{
	u64 LOC_u64Reversed=1;
	while (Copy_u64Number!=0)
	{
		LOC_u64Reversed=(LOC_u64Reversed*10)+(Copy_u64Number%10);
		Copy_u64Number/=10;
	}
	while (LOC_u64Reversed!=1)
	{
		LCD_Send_Data((LOC_u64Reversed%10)+48);
		LOC_u64Reversed/=10;
	}

}


