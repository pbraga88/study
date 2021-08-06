''' Methods to access the SQLAlchemy and perform CRUD '''

from ..models import tarefa_model
from api import db

# Create a instance of the model
def cadastrar_tarefa(tarefa):
    tarefa_bd = tarefa_model.Tarefa(titulo=tarefa.titulo, descricao=tarefa.descricao,
                                    data_expiracao=tarefa.data_expiracao)
    # Here SQLAlchemy is used to insert in database
    db.session.add(tarefa_bd)
    # Commit
    db.session.commit()
    return tarefa_bd

def listar_tarefas():
    tarefas = tarefa_model.Tarefa.query.all()
    return tarefas

def listar_tarefa_id(id):
    # Filter by id
    tarefa = tarefa_model.Tarefa.query.filter_by(id=id).first()
    return tarefa

def editar_tarefa(tarefa_bd, tarefa_nova):
    tarefa_bd.titulo = tarefa_nova.titulo
    tarefa_bd.descricao = tarefa_nova.descricao
    tarefa_bd.data_expiracao = tarefa_nova.data_expiracao
    db.session.commit()

def remover_tarefa(tarefa):
    db.session.delete(tarefa)
    db.session.commit()
