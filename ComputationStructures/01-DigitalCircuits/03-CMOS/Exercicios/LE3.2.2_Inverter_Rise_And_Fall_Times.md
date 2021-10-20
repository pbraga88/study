# LE3.2.2: Inverter Rise and Fall Times  
In the last video, we examined the CMOS inverter circuit consisting of a single PFET pullup connecting the output node to V_DD and single NFET pulldown connecting the output node to GROUND.

When the inverter's input is a digital 0, the PFET pullup is on and the NFET pulldown is off, so the voltage of the output Z rises until it reaches V_DD, a digital 1. The rise time of the output is defined as the amount of time it takes for the output voltage to rise from V_OL to V_OH.

When the inverter's input is a digital 1, the PFET pullup is off and the NFET pulldown is on, so the voltage of the output Z falls until it reaches GROUND, a digital 0. The fall time of the output is defined as the amount of time it takes for the output voltage to fall from V_OH to V_OL.

In both cases, the transition time is inversely proportional to the I_DS of the conducting MOSFET switch: the greater I_DS, the smaller the transition time.

If a designer wanted to change the inverter's design to decrease the rise time, i.e., have output voltage transition more quickly to a digital 1 value, she could (select the best answer):  
**Resposta: Aumentar a largura (WIDTH) do pullup do PFET**  
  
If a designer wanted to change the inverter's design to decrease the fall time, i.e., have output voltage transition more quickly to a digital 0 value, she could (select the best answer):  
**Resposta: Aumentar a largura (WIDTH) do pulldown do NFET**  
  
**Explicação:** Para diminuir o tempo de transição de subida, é necessário aumentar a corrente I_DS que passa pelo pullup do PFET. Portanto, é preciso aumentar a largura do PFET.  
Em uma primeira aproximação, a largura do NFET não afeta o tempo de queda. Diminuir a largura do NFET irá reduzir um pouco a capacitância do seu node drain (a saída do inversor) o que acarretaria em uma dimiuição no tempo de transição de subida (impacto não tão grande quanto dobrar a largura do pullup do PFET). E, pelo mesmo racional, para diminuir o tempo de transição de queda, é necessário aumentar a largura do pulldown do NFET.