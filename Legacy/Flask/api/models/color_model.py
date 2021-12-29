from api import db

# Inherits model from SQLAlchemy
class Color(db.Model):
    #Create the table with name "color" in database with the below attributes
    __tablename__ = "colors"

    # Primary Key. Autoincrement will sum automatically whenever a task is created. Can't be null
    id = db.Column(db.Integer, primary_key=True, autoincrement=True, nullable=False ) 
    color = db.Column(db.String(20), nullable=False)
    value = db.Column(db.String(10), nullable=False)