/* main.c - Hola Mundo Transparente STC8H8K64U @ 24MHz */
#include "stc8h.h"

volatile uint8_t estado_led = 0;

static void retardo_ms(uint16_t ms) {
    volatile uint16_t i, j;
    while (ms--) {
        /* Bucle calibrado para ~1ms a 24MHz */
        for (i = 0; i < 2400; i++) {
            j = i; /* Volátil evita eliminación por optimizador */
        }
    }
}

void main(void) {
    /* 
     * CONFIGURACIÓN P2.0 COMO CUASI-BIDIRECCIONAL
     * M1=1, M0=1 => Modo cuasi-bidireccional (pull-up débil + NMOS sink)
     * Seguro para LEDs conectados a VCC (lógica negativa)
     */
    P2M1 &= ~(1 << 0);   /* Bit 0 de P2M1 = 1 */
    P2M0 &= ~(1 << 0);   /* Bit 0 de P2M0 = 1 */
    
    /* 
     * ESTADO INICIAL: LED APAGADO
     * Lógica negativa: pin en ALTO (1) = pull-up activo = LED apagado
     * Usamos OR para garantizar 1 sin afectar otros pines
     */
    P2 |= (1 << 0);

    while (1) {
        /* 
         * TOGGLE LED CON XOR
         * XOR con 1 invierte el bit, XOR con 0 lo mantiene
         * Operación atómica en registro SFR
         */
        P2 ^= (1 << 0);
        
        retardo_ms(500);
        
        /* Actualizar variable de estado (lectura humana del estado) */
        estado_led = !estado_led;
    }
}
