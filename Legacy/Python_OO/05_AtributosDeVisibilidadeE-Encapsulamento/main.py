import carro, moto
import time

def carro01(portas=2, cor='branco', comb='gasolina', motor=1.0):
    uno_vermelho = carro.Carro(portas, cor, comb, motor)
    uno_vermelho.ligar()
    uno_vermelho.abastecer(10)
    uno_vermelho.abastecer(50)
    uno_vermelho.abastecer(50)
    #print(uno_vermelho.qtd_combustivel)
    uno_vermelho.acelerar(20)
    uno_vermelho.pintar("Azul")
    #print(f"O carro tem uma velocidade de {uno_vermelho.velocidade}")
    print(f"(Utlizando a @property da classe) A cor o carro é {uno_vermelho.cor}")

    uno_vermelho.cor = "Preto"
    print(f"(Utlizando o @cor.setter da classe) A cor o carro é {uno_vermelho.cor}")
    # Forçando a exclusão do objeto através do método del
    del uno_vermelho

def moto01(passageiros_garupa = 0, cor='branco', comb='gasolina', motor=1.0):
    moto_preta = moto.Moto(passageiros_garupa, cor, comb, motor)
    moto_preta.ligar()
    moto_preta.abastecer(10)
    moto_preta.abastecer(5)
    moto_preta.abastecer(50)
    moto_preta.abastecer(50)
    #print(moto_preta.qtd_combustivel)
    moto_preta.acelerar(100)
    moto_preta.acelerar()
    #print(f"A moto tem uma velocidade de {moto_preta.velocidade}")

def main():
    carro01(portas = 4, cor = 'vermelho', comb="flex", motor=1.0)
    time.sleep(1)
    moto01(passageiros_garupa = 1, cor = 'preta', comb="alcool", motor=128)

if __name__ == '__main__':
    main()