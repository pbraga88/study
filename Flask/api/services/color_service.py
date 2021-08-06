''' Methods to access the SQLAlchemy and perform CRUD '''

from ..models import color_model
from api import db

# Create a instance of the model
def insert_color(color):
    color_bd = color_model.Color(color=color.color, value=color.value)
    # Here SQLAlchemy is used to insert in database
    db.session.add(color_bd)
    # Commit
    db.session.commit()
    return color_bd

def list_colors():
    colors = color_model.Color.query.all()
    return colors

# def list_color_id(id):
#     # Filter by id
#     color = color_model.Color.query.filter_by(id=id).first()
#     return color

# def list_color_value(color):
#     # Filter by color
#     colorRet = color_model.Color.query.filter_by(color=color).first()
#     return colorRet

# def edit_color(color_bd, color_nova):
#     # color_bd.color = color_nova.color
#     color_bd.value = color_nova.value
#     db.session.commit()

# def remove_color(color):
#     db.session.delete(color)
#     db.session.commit()
