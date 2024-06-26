class Carro():
    """ A classe Carro é utilizada para criar objetos do tipo carro """
    # Constructor
    def __init__(self, cor, qtd_portas, tipo_combustivel, potencia):
        self.cor = cor
        self.qtd_portas = qtd_portas
        self.tipo_combustivel = tipo_combustivel
        self.potencia = potencia
        self.qtd_combustivel = 0
        self.is_ligado = False
        self.velocidade = 0

    # Destructor
    def __del__(self):
        print("Removendo objeto da memória")

    def abastecer(self, litros):
        """ O método abastecer adiciona o que é passado em litros à variável qtd_combustivel """
        self.qtd_combustivel += litros
    
    def ligar(self):
        if self.is_ligado:
            print("O carro já está ligado")
        else:
            self.is_ligado = True
            print("O carro {} foi ligado".format(self.cor) )
    
    def desligar(self):
        if self.is_ligado == False:
            print("O carro já está desligado")
        else:
            self.is_ligado = False
        
    def acelerar(self, velocidade = 10):
        if self.is_ligado:
            self.velocidade += velocidade
        else:
            print("O carro precisa estar ligado para acelerar")