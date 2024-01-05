/*
 * TWI_program.c
 *
 *  Created on: Dec 26, 2023
 *      Author: Saker
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "TWI_config.h"
#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_register.h"


void TWI_voidMasterInit(u8 Copy_u8Address)
{
	if(Copy_u8Address != NO_ADDRESS)
	{
		TWAR = Copy_u8Address << 1;
	}
	CLR_BIT(TWSR, 1);
	CLR_BIT(TWSR, 0);

	TWBR = 2;
}
void TWI_voidSlaveInit(u8 Copy_u8Address)
{
	TWAR = Copy_u8Address << 1;
}


TWI_ERROR_STATE TWI_SendStartCond(void)
{
	TWI_ERROR_STATE Local_ErrorState = NO_ERROR;
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) != START)
	{
		/*ERROR*/
		Local_ErrorState = START_CONDITION_ERROR;

	}
	return Local_ErrorState;
}
TWI_ERROR_STATE TWI_SendRepeatedStartCond(void)
{
	TWI_ERROR_STATE Local_ErrorState = NO_ERROR;
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) != REPEATED_START)
	{
		/*ERROR*/
		Local_ErrorState = REPEATED_START_CONDITION_ERROR;

	}
	return Local_ErrorState;
}

TWI_ERROR_STATE TWI_SendSlaveAddressWithWrite(u8 Copy_u8Address)
{
	TWI_ERROR_STATE Local_ErrorState = NO_ERROR;
	u8 Local_u8Address = Copy_u8Address << 1;
	CLR_BIT(Local_u8Address, 0);
	TWDR = Local_u8Address;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) != MT_SLA_ACK)
	{
		Local_ErrorState = SLAVE_ADDRESS_WITH_WRITE_ERROR;
	}
	return Local_ErrorState;
}
TWI_ERROR_STATE TWI_SendSlaveAddressWithRead(u8 Copy_u8Address)
{
	TWI_ERROR_STATE Local_ErrorState = NO_ERROR;
	u8 Local_u8Address = Copy_u8Address << 1;
	SET_BIT(Local_u8Address, 0);
	TWDR = Local_u8Address;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) != MR_SLA_ACK)
	{
		Local_ErrorState = SLAVE_ADDRESS_WITH_READ_ERROR;
	}
	return Local_ErrorState;
}

TWI_ERROR_STATE TWI_MasterSendDataWithAck(u8 Copy_u8Data)
{
	TWI_ERROR_STATE Local_ErrorState = NO_ERROR;
	TWDR = Copy_u8Data;
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) != MT_DATA_ACK)
	{
		Local_ErrorState = MASTER_SEND_DATA_WITH_ACK;
	}
	return Local_ErrorState;
}
TWI_ERROR_STATE TWI_MasterSendDataWithNAck(u8 Copy_u8Data)
{
	TWI_ERROR_STATE Local_ErrorState = NO_ERROR;
	TWDR = Copy_u8Data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) != MT_DATA_NACK)
	{
		Local_ErrorState = MASTER_SEND_DATA_WITH_ACK;
	}
	return Local_ErrorState;
}

TWI_ERROR_STATE TWI_MasterReceiveDataWithAck(u8 *Copy_u8Data)
{
	TWI_ERROR_STATE Local_ErrorState = NO_ERROR;

	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) != MR_DATA_ACK)
	{
		Local_ErrorState = MASTER_RECEIVE_DATA_WITH_ACK;
	}
	*Copy_u8Data = TWDR;
	return Local_ErrorState;
}
TWI_ERROR_STATE TWI_MasterReceiveDataWithNAck(u8 *Copy_u8Data)
{
	TWI_ERROR_STATE Local_ErrorState = NO_ERROR;

	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) != MR_DATA_NACK)
	{
		Local_ErrorState = MASTER_RECEIVE_DATA_WITH_NACK;
	}
	*Copy_u8Data = TWDR;
	return Local_ErrorState;
}

void TWI_SendStopCond(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)| (1<<TWSTO);
}
