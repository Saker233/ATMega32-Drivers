/*
 * TWI_interface.h
 *
 *  Created on: Dec 26, 2023
 *      Author: Saker
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

typedef enum
{
	NO_ERROR,
	START_CONDITION_ERROR,
	REPEATED_START_CONDITION_ERROR,
	SLAVE_ADDRESS_WITH_WRITE_ERROR,
	SLAVE_ADDRESS_WITH_READ_ERROR,
	MASTER_SEND_DATA_WITH_ACK,
	MASTER_SEND_DATA_WITH_NACK,
	MASTER_RECEIVE_DATA_WITH_ACK,
	MASTER_RECEIVE_DATA_WITH_NACK

}TWI_ERROR_STATE;

#define 	NO_ADDRESS			0


void TWI_voidMasterInit(u8 Copy_u8Address);
void TWI_voidSlaveInit(u8 Copy_u8Address);

TWI_ERROR_STATE TWI_SendStartCond(void);
TWI_ERROR_STATE TWI_SendRepeatedStartCond(void);

TWI_ERROR_STATE TWI_SendSlaveAddressWithWrite(u8 Copy_u8Address);
TWI_ERROR_STATE TWI_SendSlaveAddressWithRead(u8 Copy_u8Address);

TWI_ERROR_STATE TWI_MasterSendDataWithAck(u8 Copy_u8Data);
TWI_ERROR_STATE TWI_MasterSendDataWithNAck(u8 Copy_u8Data);

TWI_ERROR_STATE TWI_MasterReceiveDataWithAck(u8 *Copy_u8Data);
TWI_ERROR_STATE TWI_MasterReceiveDataWithNAck(u8 *Copy_u8Data);

void TWI_SendStopCond(void);

#endif /* TWI_INTERFACE_H_ */
