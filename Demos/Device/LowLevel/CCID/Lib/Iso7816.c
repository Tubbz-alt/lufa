/*
             LUFA Library
     Copyright (C) Dean Camera, 2018.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2018  Dean Camera (dean [at] fourwalledcubicle [dot] com)
  Copyright 2018  Filipe Rodrigues (filipepazrodrigues [at] gmail [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

#include "Iso7816.h"

void Iso7816_CreateSimpleAtr(uint8_t* const atr,
                             uint8_t* const atrLength)
{
	atr[0] = 0x3B; // TS: direct convention

	uint8_t interfaceBytesPresence = 0;

	uint8_t historycalBytes[14]   = "Lufa CCID Demo"; // Must be equal or less than 15
	uint8_t historicalBytesLength = sizeof(historycalBytes);

	atr[1] = (interfaceBytesPresence << 4) + historicalBytesLength; //TO
	memcpy(atr + 2, historycalBytes, historicalBytesLength);

	*atrLength = historicalBytesLength + 2;
}
