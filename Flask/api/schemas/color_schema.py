# Class to serialize/deserialize data (python-json)

from api import ma
from ..models import color_model
from marshmallow import fields

class ColorSchema(ma.SQLAlchemySchema):
    # This class will describe the fields
    class Meta:
        #Define color model
        model = color_model.Color
        # Define which fields to return upon request
        # fields = ("id", "color", "value") # To return with id
        fields = ("color", "value")
    # To validate the type of data
    color = fields.String(required=True)
    value = fields.String(required=True)
