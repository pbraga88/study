from flask import app
from flask.helpers import make_response
from flask.json import jsonify
from flask_restful import Resource
from api import api
from ..schemas import tarefa_schema
from flask import request
from ..entidades import tarefa
from ..services import tarefa_service

class TarefaList(Resource):
    """ get all values"""
    def get(self):
        tarefas = tarefa_service.listar_tarefas()
        #many=True to deserialize more than one object
        ts = tarefa_schema.TarefaSchema(many=True)
        
        return make_response(ts.jsonify(tarefas), 200)

    def post(self):
        # create a stance of TarefaSchema
        ts = tarefa_schema.TarefaSchema()
        # Validade the data in request body
        validate = ts.validate(request.json)
        if validate:
            # Generate json format error response. 400 = Bad Request
            return make_response(jsonify(validate), 400)
        else:
            # Capture request data
            titulo = request.json["titulo"]
            descricao = request.json["descricao"]
            data_expiracao = request.json["data_expiracao"]
            tarefa_nova = tarefa.Tarefa(titulo=titulo, descricao=descricao,
                                            data_expiracao=data_expiracao)
            # Call method cadastrar_tarefa and give the above task as input
            result = tarefa_service.cadastrar_tarefa(tarefa_nova)
            # return and serialize the schema data
            # and transform python in json to return
            return make_response(ts.jsonify(result), 201) # 201 = Created

class TarefaDetail(Resource):
    # Get by id
    def get(self, id):
        # First verify if 'tarefa' exists
        tarefa = tarefa_service.listar_tarefa_id(id)
        if tarefa is None: # if id does not exist
            return make_response(jsonify("Tarefa não encontrada"), 404)
        else:
            # Create the object which will  translate into json
            # Note that the 'many' attribute is not used here since 
            # only one task is being returned
            ts = tarefa_schema.TarefaSchema()
            return make_response(ts.jsonify(tarefa), 200)
    # Edit by id
    def put(self, id):
        # First verify if 'tarefa' exists
        tarefa_bd = tarefa_service.listar_tarefa_id(id)
        if tarefa_bd is None: # if id does not exist
            return make_response(jsonify("Tarefa não encontrada"), 404)
        
        ts = tarefa_schema.TarefaSchema()
        validate = ts.validate(request.json)
        if validate:
            return make_response(jsonify(validate), 400)
        else:
            # Capture request data
            titulo = request.json["titulo"]
            descricao = request.json["descricao"]
            data_expiracao = request.json["data_expiracao"]
            tarefa_nova = tarefa.Tarefa(titulo=titulo, descricao=descricao,
                                            data_expiracao=data_expiracao)
            tarefa_service.editar_tarefa(tarefa_bd, tarefa_nova)
            tarefa_atualizada = tarefa_service.listar_tarefa_id(id)
            return make_response(ts.jsonify(tarefa_atualizada), 200)
    # Remove by id 
    def delete(self, id):
        tarefa = tarefa_service.listar_tarefa_id(id)
        if tarefa is None: # if id does not exist
            return make_response(jsonify("Tarefa não encontrada"), 404)
        tarefa_service.remover_tarefa(tarefa)
        return make_response('', 204) # 204 = Request and deletion successfull

# Register classes as API resources. 
# Class name and API route shall be given
api.add_resource(TarefaList, '/tarefas')
api .add_resource(TarefaDetail, '/tarefas/<int:id>') #use <int:id> since the type to be
                                                     # retrieved is int