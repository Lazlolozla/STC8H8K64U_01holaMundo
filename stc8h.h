/* stc8h.h - Solo direcciones SFR, sin abstracciones */
#ifndef _STC8H_H_
#define _STC8H_H_

#include <stdint.h>

/* Registros SFR Puerto 2 - Direcciones físicas del STC8H8K64U */
__sfr __at(0xA0) P2;      /* Registro de datos puerto 2 */
__sfr __at(0x95) P2M1;    /* Configuración modo bit alto */
__sfr __at(0x96) P2M0;    /* Configuración modo bit bajo */

#endif /* _STC8H_H_ */
