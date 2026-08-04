# 01holaMundo - STC8H8K64U Bare Metal

Hola Mundo (parpadeo LED) para microcontrolador STC8H8K64U usando SDCC en Linux.  
Proyecto educativo enfocado en transparencia, eficiencia y acceso directo al hardware.

## Filosofía de Trabajo

- **Cero abstracciones:** Sin HAL, Arduino ni librerías genéricas.
- **Sintaxis SDCC pura:** `__sfr __at()` en lugar de sintaxis Keil.
- **Transparencia total:** Operaciones bitwise explícitas, sin macros ocultas.
- **Eficiencia consciente:** Variables globales simples, pila controlada, sin malloc/printf/float.
- **Verificación primaria:** Direcciones SFR validadas contra Reference Manual oficial.
- **Ambiente 100% Linux:** SDCC + stcgal + Makefile + Bash.

## Hardware

- MCU: STC8H8K64U @ 24MHz (configuración de fábrica)
- LED: Conectado a P2.0 en configuración sink (5V → LED → R → Pin)
- Modo GPIO: Cuasi-bidireccional (P2M1=0, P2M0=0) para lógica negativa segura

## Estructura del Proyecto
01holaMundo/
├── 01holaMundo.c    # Código principal transparente
├── stc8h.h          # Solo direcciones SFR verificadas
├── Makefile         # Compilación y grabación mínima
├── README.md        # Este archivo
├── License.txt      # UNLICENSE (dominio público)
└── .gitignore       # Exclusión de binarios y temporales


## Requisitos

- SDCC (>= 4.0 recomendado)
- stcgal (>= 1.7 con soporte STC8G/8H)
- Puerto USB-UART conectado al MCU
- Permisos de acceso a `/dev/ttyUSB0` (o ajustar en Makefile)

## Uso
# Compilar
make

# Grabar en el microcontrolador
make flash

# Limpiar archivos generados
make clean

Referencias

    STC8H Reference Manual (2022/3/9)
    SDCC Compiler User Guide
    stcgal Documentation

