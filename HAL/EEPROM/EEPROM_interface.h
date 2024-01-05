/*
 * EEPROM_interface.h
 *
 *  Created on: Dec 26, 2023
 *      Author: Saker
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidWriteByte(u8 A_u8Data, u16 A_u16Address);
void EEPROM_voidReadByte(u8 *AP_u8ptr, u16 A_u16Address);

#endif /* EEPROM_INTERFACE_H_ */
