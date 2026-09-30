/*Ejemplo de uso de union*/

#include <stdio.h>
#include <stdint.h>

// Definimos un union que mapea un uint32_t y un arreglo de 4 bytes en el mismo espacio
union SensorData {
    uint32_t valor_completo; // 4 bytes
    uint8_t  bytes[4];       // Mismos 4 bytes, pero accesibles individualmente
};

int main(void) {
    union SensorData lectura;

    // Asignamos el valor completo obtenido del sensor (ej. 0xABCD1234)
    lectura.valor_completo = 0xABCD1234;

    printf("Valor completo del sensor: 0x%X\n\n", lectura.valor_completo);

    // Accedemos a los bytes individuales para enviarlos por UART (Little Endian)
    printf("Enviando byte por byte por la UART:\n");
    for (int i = 0; i < 4; i++) {
        printf("Byte %d a transmitir: 0x%02X (Direccion relativa +%d)\n", i, lectura.bytes[i], i);
    }

    return 0;
}