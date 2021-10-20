import veiculo, moto

class Triciclo(moto.Moto):
    def __init__(self, qtd_rodas, qtd_passageiros_garupa, cor, tipo_combustivel, potencia):
        super().__init__(qtd_passageiros_garupa, cor, tipo_combustivel, potencia)
        self.qtd_rodas = qtd_rodas
    