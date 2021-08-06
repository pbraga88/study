from flask import app
from flask.helpers import make_response
from flask.json import jsonify
from flask_restful import Resource
from api import api
from ..schemas import color_schema
from flask import request
from ..entidades import color
from ..services import color_service

class ColorList(Resource):
    """ get all values"""
    def get(self):
        colors = color_service.list_colors()
        #many=True to deserialize more than one object
        cs = color_schema.ColorSchema(many=True)
        
        return make_response(cs.jsonify(colors), 200)

    def post(self):
        # create a instance of ColorSchema
        cs = color_schema.ColorSchema()
        # Validade the data in request body
        validate = cs.validate(request.json)
        if validate:
            # Generate json format error response. 400 = Bad Request
            return make_response(jsonify(validate), 400)
        else:
            # Capture request data
            color_retrieve = request.json["color"]
            value_retrieve = request.json["value"]
            color_new = color.Color(color=color_retrieve, value=value_retrieve)
            # Call method insert_value and give the above as input
            result = color_service.insert_color(color_new)
            # return and serialize the schema data
            # and transform python in json to return
            return make_response(cs.jsonify(result), 201) # 201 = Created

# class ColorDetail(Resource):
#     # Get by id
#     def get(self, id):
#         # First verify if 'color' exists
#         color = color_service.list_color_id(id)
#         if color is None: # if id does not exist
#             return make_response(jsonify("Color not found"), 404)
#         else:
#             # Create the object which will translate into json
#             # Note that the 'many' attribute is not used here since 
#             # only one color is being returned
#             cs = color_schema.ColorSchema()
#             return make_response(cs.jsonify(color), 200)
 
#     # Edit by id
#     def put(self, id):
#         # First verify if 'color' exists
#         color_bd = color_service.list_color_id(id)
#         if color_bd is None: # if id does not exist
#             return make_response(jsonify("Color not found"), 404)
        
#         cs = color_schema.ColorSchema()
#         validate = cs.validate(request.json)
#         if validate:
#             return make_response(jsonify(validate), 400)
#         else:
#             # Capture request data
#             color = request.json["color"]
#             value = request.json["value"]
#             color_new = color.Color(color=color, value=value)
#             color_service.edit_color(color_bd, color_new)
#             updated_color = color_service.list_color_id(id)
#             return make_response(cs.jsonify(updated_color), 200)
#     # Remove by id 
#     def delete(self, id):
#         color = color_service.list_color_id(id)
#         if color is None: # if id does not exist
#             return make_response(jsonify("Color not found"), 404)
#         color_service.remove_color(color)
#         return make_response('', 204) # 204 = Request and deletion successfull

# # TO BE TESTED
# class ColorDetailByValue(Resource):
#     # Get by value
#     def get(self, color):
#         # First verify if color value exists
#         color_rgb = color_service.list_color_value(color)
#         if color_rgb is None: # if color does not exist
#             return make_response(jsonify("Color not found"), 404)
#         else:
#             # Create the object which will  translate into json
#             # Note that the 'many' attribute is not used here since 
#             # only one color is being returned
#             cs = color_schema.ColorSchema()
#             return make_response(cs.jsonify(color_rgb), 200)

    # # Edit by color
    # def put(self, color_edit):
    #     # First verify if color value exists
    #     color_db = color_service.list_color_value(color_edit)
    #     if color_db is None: # if color does not exist
    #         return make_response(jsonify("Color not found"), 404)
        
    #     cs = color_schema.ColorSchema()
    #     validate = cs.validate(request.json)
    #     if validate:
    #         return make_response(jsonify(validate), 400)
    #     else:
    #         # Capture request data
    #         # color_ret = request.json["color"]
    #         value_ret = request.json["value"]
    #         # color_new = color.Color(color=color_ret, value=value_ret)
    #         color_new = color.Color(value=value_ret)
    #         color_service.edit_color(color_db, color_new)
    #         updated_color = color_service.list_color_value(color_edit)
    #         return make_response(cs.jsonify(updated_color), 200)
    # Remove by color 
    # def delete(self, color_to_delete):
    #     check_color = color_service.list_color_value(color_to_delete)
    #     if check_color is None: # if id does not exist
    #         return make_response(jsonify("Color not found"), 404)
    #     color_service.remove_color(check_color)
    #     return make_response('', 204) # 204 = Request and deletion successfull



# Register classes as API resources. 
# Class name and API route shall be given
api.add_resource(ColorList, '/colors')
# api .add_resource(ColorDetail, '/colors/<int:id>') #use <int:id> since the type to be
#                                                       # retrieved is int
# api .add_resource(ColorDetailByValue, '/colors/<string:color>')                                                     