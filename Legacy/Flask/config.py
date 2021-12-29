DEBUG = True

USERNAME = 'root'
PASSWORD = 'admin'
SERVER = 'localhost'
DB = 'flask_api'

# Configuration set defined above to comunicate with mysql database
# SQLAlchemy will use the below URI to comunicate with database
SQLALCHEMY_DATABASE_URI = f'mysql://{USERNAME}:{PASSWORD}@{SERVER}/{DB}'
# To track model modifications
SQLALCHEMY_TRACK_MODIFICATION = True