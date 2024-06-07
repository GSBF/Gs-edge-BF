# Monitoramento de Temperatura, Salinidade e pH

Este projeto Arduino foi desenvolvido para monitorar e exibir a temperatura, salinidade e pH de um ambiente, utilizando potenciômetros e um termistor. O sistema também inclui LEDs e um buzzer para indicar diferentes faixas de temperatura, oferecendo um feedback visual e sonoro.

## Componentes Necessários

- Arduino UNO
- Display LCD 16x2
- Termistor
- 2 Potenciômetros (para simular os sensores de salinidade e pH)
- 3 LEDs (Verde, Amarelo, Vermelho)
- Buzzer
- Resistores
- Protoboard e fios jumpers

## Circuito

1. **Display LCD**:
   - Conecte os pinos 12, 11, 5, 4, 3, 2 do Arduino aos pinos correspondentes do LCD.
   
2. **Termistor**:
   - Conecte um lado do termistor ao pino A2 do Arduino e o outro lado ao GND. Adicione um resistor entre o pino A2 e o 5V para formar um divisor de tensão.

3. **Potenciômetros**:
   - Conecte os pinos centrais dos potenciômetros aos pinos A1 e A0 do Arduino.
   - Conecte os outros dois pinos de cada potenciômetro ao 5V e GND.

4. **LEDs e Buzzer**:
   - Conecte os LEDs aos pinos 8, 9, 10 (anodo) do Arduino, com resistores limitadores de corrente em série.
   - Conecte o cátodo dos LEDs ao GND.
   - Conecte o buzzer ao pino 6 do Arduino, com o outro terminal ao GND.

## Funcionamento

1. **Inicialização**:
   - Configura o display LCD, define os pinos como saída e inicializa a comunicação serial.
   
2. **Loop Principal**:
   - Lê o valor analógico do termistor e converte para temperatura em Celsius.
   - Lê os valores dos potenciômetros para simular a salinidade e pH.
   - Atualiza o display LCD a cada 5 segundos.
   - Controla os LEDs e o buzzer com base na faixa de temperatura medida.

3. **Função de Atualização do Display**:
   - Alterna entre exibir temperatura, salinidade e pH no display LCD a cada atualização.
   - Envia os valores lidos para o monitor serial.

## Importância do Projeto

Este projeto é de grande importância em diversas áreas, tais como:

- **Aquicultura**: Monitorar a temperatura, salinidade e pH é crucial para garantir um ambiente ideal para a criação de peixes e outros organismos aquáticos.
- **Agricultura**: Em sistemas de irrigação e hidroponia, controlar esses parâmetros ajuda a otimizar o crescimento das plantas.
- **Indústria Alimentícia**: Na produção de alimentos e bebidas, manter o controle sobre esses fatores é essencial para garantir a qualidade e segurança dos produtos.
- **Pesquisa Científica**: Em laboratórios e estudos científicos, o monitoramento preciso desses parâmetros é fundamental para conduzir experimentos e pesquisas.

## Uso

1. Construa o circuito conforme descrito.
2. Carregue o código no Arduino.
3. Observe as leituras de temperatura, salinidade e pH no display LCD.
4. Verifique a indicação dos LEDs e do buzzer conforme as diferentes faixas de temperatura.

## Observações

- Este projeto utiliza potenciômetros para simular os sensores de salinidade e pH. Em um ambiente real, substitua esses potenciômetros pelos sensores apropriados.
- Ajuste os limites de temperatura, salinidade e pH conforme necessário para a aplicação específica.

Este projeto oferece uma solução prática e acessível para monitorar e controlar importantes parâmetros ambientais, contribuindo para diversos campos da ciência e da indústria.
![image](https://github.com/GSBF/Gs-edge-BF/assets/80282965/c71365f9-3ac7-440e-bef8-3d08e1f7b79a)
![image](https://github.com/GSBF/Gs-edge-BF/assets/80282965/ba8aebe3-9ae5-4bb6-bc14-7c7962ab34b9)
![image](https://github.com/GSBF/Gs-edge-BF/assets/80282965/bc007296-1fa8-4509-b667-343065b4dd18)

