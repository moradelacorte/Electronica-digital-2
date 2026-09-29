#include <stdio.h>
#include <stddef.h>

struct pru_struct {
    char id1;
    char id2;
    char id3[10];
    char *nombre;
    char *domicilio;
    int edad;
    int varios;
};

struct pru_struct empleados = {
    'B',
    'C',
    "Sensible",
    "Pedro",
    "Av. Carlos Calvo 1234",
    23,
    68
};

void showinfo(struct pru_struct *p) {
    printf("Valores iniciales de la estructura\n");
    printf("\tid1:\t\t%c\n", p->id1);
    printf("\tid2:\t\t%c\n", p->id2);
    printf("\tid3:\t\t%s\n", p->id3);
    printf("\tNombre:\t\t%s\n", p->nombre);
    printf("\tDireccion:\t%s\n", p->domicilio);
    printf("\tEdad:\t\t%d\n", p->edad);
    printf("\tVarios:\t\t%d\n\n", p->varios);

    printf("Direccion de la estructura: %p\n\n", (void*)p);

    printf("Direccion del miembro id1:\t\t%p (offset: %zu bytes)\n",
           (void*)&p->id1, offsetof(struct pru_struct, id1));
    printf("Direccion del miembro id2:\t\t%p (offset: %zu bytes)\n",
           (void*)&p->id2, offsetof(struct pru_struct, id2));
    printf("Direccion del miembro id3:\t\t%p (offset: %zu bytes)\n",
           (void*)&p->id3, offsetof(struct pru_struct, id3));
    printf("Direccion del miembro nombre:\t\t%p (offset: %zu bytes)\n",
           (void*)&p->nombre, offsetof(struct pru_struct, nombre));
    printf("Direccion del miembro domicilio:\t%p (offset: %zu bytes)\n",
           (void*)&p->domicilio, offsetof(struct pru_struct, domicilio));
    printf("Direccion del miembro edad:\t\t%p (offset: %zu bytes)\n",
           (void*)&p->edad, offsetof(struct pru_struct, edad));
    printf("Direccion del miembro varios:\t\t%p (offset: %zu bytes)\n\n",
           (void*)&p->varios, offsetof(struct pru_struct, varios));

    printf("Direccion de la primera posicion de memoria despues de la estructura: %p\n",
           (void*)(p + 1));
    printf("(sizeof(struct pru_struct) = %zu bytes)\n", sizeof(struct pru_struct));
}

int main() {
    int i;
    int tmp;
    (void)i; (void)tmp;

    showinfo(&empleados);

    return 0;
}