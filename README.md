# 🔴🟢🔵 Atividade 2 - Temporizador de Um Disparo (One Shot)

##  Descrição
Este projeto implementa um sistema onde **três LEDs (Azul, Vermelho e Verde) são ativados ao pressionar um botão**. Eles são desligados **progressivamente a cada 3 segundos**, utilizando um **temporizador de um disparo (`add_alarm_in_ms()`)**.

##  Componentes Utilizados
- Raspberry Pi Pico W
- 3 LEDs (Azul, Vermelho e Verde)
- 3 Resistores de **330Ω**
- 1 Botão (Pushbutton)
- Simulação no **Wokwi**
- Teste na **BitDogLab** utilizando LED RGB (GPIOs **11, 12 e 13**) e botão (GPIO5)

##  Funcionalidade
1. Ao pressionar o **botão**, os três LEDs **ligam ao mesmo tempo**.
2. Os LEDs desligam **um de cada vez**, seguindo este ciclo:
   - Após **3 segundos**, o LED **Azul** apaga.
   - Após **6 segundos**, o LED **Vermelho** apaga.
   - Após **9 segundos**, o LED **Verde** apaga.
3. O botão só pode ser pressionado **novamente** após todos os LEDs apagarem.

##  Pinagem (GPIOs)
| Componente  | GPIO |
|-------------|------|
| Botão       | GP5  |
| LED Azul    | GP11 |
| LED Vermelho| GP12 |
| LED Verde   | GP13 |

##  Como Rodar no Wokwi
1. Abra o [Wokwi](https://wokwi.com/)
2. Carregue o `diagram.json` da atividade 2.
3. Compile e rode o código em C no **VS Code** com o **Pico SDK**.

##  Como Rodar na BitDogLab
1. Conecte os LEDs às portas **GPIO11, GPIO12 e GPIO13** e o botão ao **GPIO5**.
2. Compile e transfira o firmware para a **BitDogLab**.
3. Pressione o botão e observe os LEDs apagando em sequência.
