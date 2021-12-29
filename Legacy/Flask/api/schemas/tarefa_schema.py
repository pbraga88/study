# Criar uma classe que entende como o model de tarefa funciona
# quando os dados são enviados do banco de dados ele passa por aqui para
# tradução e vice-versa

# Classe interpreta os dados de json para python e vice-versa

from api import ma
from ..models import tarefa_model
from marshmallow import fields

#class TarefaSchema(ma.ModelSchema): # DEPRECATED

# 
class TarefaSchema(ma.SQLAlchemySchema):
    # This class will describe the fields
    class Meta:
        #Define de tarefa model
        model = tarefa_model.Tarefa
        # Define which fields to return upon request
        fields = ("id", "titulo", "descricao", "data_expiracao")
    # To validate the type of data
    titulo = fields.String(required=True)
    descricao = fields.String(required=True)
    data_expiracao = fields.Date(required=True)
