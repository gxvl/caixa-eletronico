# Simulação de Fila de Caixa Eletrônico em C

Este é um programa em C que simula uma fila de pessoas esperando para usar um caixa eletrônico. O programa utiliza pthreads e condicionais para garantir que apenas uma pessoa use o caixa eletrônico por vez e que as pessoas esperem na fila quando o caixa estiver ocupado.

## Descrição do Problema

O programa cria uma fila de pessoas representadas por threads, onde cada pessoa espera na fila para usar o caixa eletrônico. Apenas uma pessoa pode usar o caixa eletrônico por vez. Se o caixa estiver ocupado, as pessoas esperam na fila até que seja sua vez de usar o caixa.

## Funcionalidades Implementadas

- Uma função uso_caixa() que representa o uso do caixa eletrônico por uma pessoa. Esta função imprime uma mensagem indicando que uma pessoa está usando o caixa eletrônico.
- Uma função espera_na_fila() que representa uma pessoa esperando na fila quando o caixa eletrônico está ocupado. Esta função imprime uma - mensagem indicando que uma pessoa está esperando na fila.
- Uso de pthreads para representar as pessoas chegando à fila.
- Uso de uma variável de condição para sincronizar o acesso ao caixa eletrônico.
- Uso de um mutex para proteger a seção crítica (o acesso ao caixa eletrônico).
