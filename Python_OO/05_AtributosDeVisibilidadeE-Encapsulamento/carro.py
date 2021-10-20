import veiculo

class Carro(veiculo.Veiculo):
    def __init__(self, qtd_portas,  cor, tipo_combustivel, potencia):
        # super() é utilizado para herdar os atributos inicializados na classe
        # pai (Veiculo)
        super().__init__(cor, tipo_combustivel, potencia)
        # Inicializa o atributo exclusivos da classe filho (Carro)
        self.qtd_portas = qtd_portas
    # Polimorfismo: alterando a função abastecer localmente para as
    # características da classe Carro
    def abastecer(self, litros):
        print(f"Método chamado à partir da classe {self.__class__}")
        if self._qtd_combustivel >= 50:
            print("O tanque está cheio")
        else:
            return super().abastecer(litros)
