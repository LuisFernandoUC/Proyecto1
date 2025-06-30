# Calculadora de MCM – Proyecto 1

**Curso:** IC4700 Lenguajes de Programación  
**Grupo:** 1  
**Semestre:** I-2025  
**Paradigma:** Imperativo / Procedimental  
**Lenguaje:** C con interfaz gráfica (GTK 3)

---

## Descripción general

Este proyecto consiste en una aplicación que permite calcular el **Mínimo Común Múltiplo (MCM)** entre dos números enteros positivos, usando una **interfaz gráfica orientada a eventos**. Fue desarrollado en lenguaje C, siguiendo principios de **programación estructurada**, con separación modular de funcionalidades y **bajo acoplamiento** entre componentes.

La aplicación cuenta con **tres botones principales**:

- **"Calcular MCM"**: Calcula el MCM entre los dos números ingresados.
- **"Reiniciar"**: Permite limpiar los campos de entrada y el resultado mostrado.
- **"Salir"**: Cierra la aplicación.

---

## Objetivos didácticos alcanzados

- Aplicación del paradigma imperativo-procedimental
- Diseño estructurado usando funciones puras y módulos separados
- Interfaz gráfica orientada a eventos con GTK
- Validación robusta de entradas
- Reducción del acoplamiento mediante segmentación funcional

---

## Estructura del proyecto

```
Proyecto_MCM/
├── src/
│   ├── main.c              # Función principal del programa
│   ├── interface.c         # Construcción y lógica de la interfaz gráfica
│   ├── logic.c             # Lógica para el cálculo del MCM
│   └── validation.c        # Validación de entradas numéricas
│   └── error_utils.c       # Funciones para mostrar los diálogos de error
│
├── include/
│   ├── interface.h
│   ├── logic.h
│   └── validation.h
│   └── error_utils.h
│
├── Makefile                # Script de compilación
└── README.md               # Documentación del proyecto (este archivo)
```

---

## Instrucciones de compilación

### Requisitos:

- Linux o WSL con Ubuntu
- GTK 3 instalado con sus herramientas:

```bash
sudo apt update
sudo apt install libgtk-3-dev build-essential pkg-config
```

### Compilar y ejecutar:

```bash
make
./app
```

---

## Instrucciones de uso

1. Ejecuta el programa: `./app`
2. Ingresa **dos números enteros positivos**
3. Presiona el botón "Calcular MCM" para obtener el resultado
4. Si los datos son inválidos, el sistema muestra un mensaje de error
5. Si deseas reiniciar los datos, presiona el botón "Reiniciar"
6. Puedes cambiar los valores y calcular otra vez sin cerrar la aplicación
7. Para cerrar el programa, presiona el botón "Salir"

---

## Validaciones incluidas

- Se rechazan entradas no numéricas (letras, símbolos, vacíos)
- Se rechazan números negativos o cero
- Se permite modificar datos antes de calcular
- El programa puede cerrarse en cualquier momento

---

## División de responsabilidades

| Módulo         | Rol principal                                 |
| -------------- | --------------------------------------------- |
| `main.c`       | Inicia GTK y llama a la interfaz principal    |
| `interface.c`  | Construye la GUI y maneja eventos de usuario  |
| `logic.c`      | Contiene la lógica del cálculo del MCM        |
| `validation.c` | Contiene función para validar números enteros |

---

## Cálculo del acoplamiento de módulos

### Fórmula usada:


| Módulo       | Cálculo                           | Resultado |
| ------------ | --------------------------------- | --------- |
| `main`       | 1 - 1/(2+0+0+0+0+0+1+0) = 1 - 1/3 | **0.666** |
| `interface`  | 1 - 1/(0+0+1+0+0+0+1+1) = 1 - 1/3 | **0.666** |
| `logic`      | 1 - 1/(2+0+1+0+0+0+0+1) = 1 - 1/4 | **0.75**  |
| `validation` | 1 - 1/(1+0+1+0+0+0+0+1) = 1 - 1/3 | **0.666** |

---

## Diagramas de Nassi-Schneiderman
