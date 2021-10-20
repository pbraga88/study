import carro
import time

def carro01(cor='branco', portas=2, comb='gasolina', motor=1.0):
    uno_vermelho = carro.Carro(cor, portas, comb, motor)
    uno_vermelho.ligar()
    uno_vermelho.abastecer(10)
    print(uno_vermelho.qtd_combustivel)
    uno_vermelho.acelerar(20)
    # Forçando a exclusão do objeto através do método del
    del uno_vermelho

def carro02(cor='branco', portas=2, comb='gasolina', motor=1.0):
    uno_preto = carro.Carro(cor, portas, comb, motor)
    uno_preto.ligar()
    uno_preto.abastecer(10)
    uno_preto.abastecer(5)
    print(uno_preto.qtd_combustivel)
    uno_preto.acelerar(100)
    uno_preto.acelerar()
    print(uno_preto.velocidade)

def main():
    carro01(cor = 'vermelho', portas = 4, comb="flex", motor=1.0)
    time.sleep(1)
    carro02(cor = 'preto', portas = 4, comb="alcool", motor=1.4)

if __name__ == '__main__':
    main()

