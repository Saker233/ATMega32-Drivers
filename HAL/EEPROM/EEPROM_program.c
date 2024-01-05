/*
 * EEPROM_program.c
 *
 *  Created on: Dec 26, 2023
 *      Author: Saker
 */


void EEPROM_voidWriteByte(u8 A_u8Data, u16 A_u16Address)
{
	TWI_SendStartCond();
	TWI_SendSlaveAddressWithWrite(1010 | A2 << 2 | A_u16Address>>8);
	TWI_MasterSendDataWithAck((u8) A_u16Address);
	TWI_MasterSendDataWithAck(A_u8Data);
	TWI_SendStopCond();

	_delay_ms(10);
}


void EEPROM_voidReadByte(u8 *AP_u8ptr, u16 A_u16Address)
{
	TWI_SendStartCond();

	TWI_SendSlaveAddressWithWrite(1010 | A2 << 2 | A_u16Address>> 8);
	TWI_MasterSendDataWithAck((u8) A_u16Address);

	TWI_SendRepeatedStartCond();
	TWI_SendSlaveAddressWithRead(0b1010 | A2 << 2 | A_u16Address>>8);
	TWI_MasterReceiveDataWithAck(AP_u8ptr);
	TWI_SendStopCond();

}
