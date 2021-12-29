import veiculo

class Moto(veiculo.Veiculo):
    def __init__(self, qtd_passageiros_garupa, cor, tipo_combustivel, potencia):
        super().__init__(cor, tipo_combustivel, potencia)
        self.qtd_passageiros_garupa = qtd_passageiros_garupa

    # Polimorfismo: alterando a função abastecer localmente para as
    # características da classe Moto
    def abastecer(self, litros):
        print(f"Método chamado à partir da classe {self.__class__}")
        if self.qtd_combustivel >= 30:
            print("O tanque está cheio")
        else:
            return super().abastecer(litros)