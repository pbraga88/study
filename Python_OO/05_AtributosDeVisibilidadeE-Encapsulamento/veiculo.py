class Veiculo():
    """ A classe Carro é utilizada para criar objetos do tipo carro """
    # Constructor
    def __init__(self, cor, tipo_combustivel, potencia):
        # __ -> Privado: Apenas esta classe pode acessar o atributo/método
        # _  -> Protected: A classe filha também pode acessar o atributo/método
        # Public: O atributo/método é naturalmente público
        self.__cor = cor
        self.__tipo_combustivel = tipo_combustivel
        self.__potencia = potencia
        self._qtd_combustivel = 0
        self.__is_ligado = False
        self.__velocidade = 0

    # Destructor
    def __del__(self):
        print("Removendo objeto da memória")

    def abastecer(self, litros):
        """ O método abastecer adiciona o que é passado em litros à variável qtd_combustivel """
        self._qtd_combustivel += litros
    
    def pintar(self, cor):
        self.__cor = cor
    
    #Uma property mascara o método para parecer que é o atributo que está sendo acessado diretamente
    @property
    def cor(self):
        return self.__cor
    
    # Também é possível 'setar' um atributo utilizando o método @<atributo>.setter
    @cor.setter
    def cor(self, cor):
        self.__cor = cor

    def ligar(self):
        if self.__is_ligado:
            print("O veículo já está ligado")
        else:
            self.__is_ligado = True
            print("O veículo {} foi ligado".format(self.__cor) )
    
    def desligar(self):
        if self.__is_ligado == False:
            print("O veículo já está desligado")
        else:
            self.__is_ligado = False
        
    def acelerar(self, velocidade = 10):
        if self.__is_ligado:
            self.__velocidade += velocidade
        else:
            print("O carro precisa estar ligado para acelerar")