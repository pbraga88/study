from api import db

# Inherits model from SQLAlchemy
class Tarefa(db.Model):
    #Create the table with name "tarefa" in database with the below attributes
    __tablename__ = "tarefa"

    # Chave Primária. Autoincrement will sum automatically whenever a task is created. Can't be null
    id = db.Column(db.Integer, primary_key=True, autoincrement=True, nullable=False ) 
    titulo = db.Column(db.String(50), nullable=False)
    descricao = db.Column(db.String(100), nullable=False)
    data_expiracao = db.Column(db.Date, nullable=False)
