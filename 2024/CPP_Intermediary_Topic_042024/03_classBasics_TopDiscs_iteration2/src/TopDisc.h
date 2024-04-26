//
// TopDisc.h
//



class TopDisc
{
public:
	// Default constructor, initialize the disc
	TopDisc();
	// Default destructor
	~TopDisc();

	// TopDisc(const char* pszDefaultContents, int identifier); // DEPRECATED, SINCE NOW THERE'S A
															    // UNIQUE IDENTIFIER (unique_identifier)
	// Constructor, initialize the disc with the provided data + mac capacity
	TopDisc(const char* pszDefaultContents, int max_cap);
	// Copy constructor
	TopDisc(const TopDisc& rhs);
	// Overload operator=
	TopDisc& operator=(const TopDisc& rhs);

	int getId();
	void copyContentFrom(const TopDisc &other);

  	// Write all data on disc
	void Write(const char* p_NewData);

	// Read all data from disc
	const char* Read();

	// Get Max Capacity 
	int get_capacity();
protected:
	// Initialize with provided string data
	void Initialize( const char* pszData );

private:
	// static will make it tied to the class not the object, hence it can be used to count
	// the number of instances of a class or, as in this example, give an unique identifier
	// to each object
	static int		m_Identifier;
	const int 		unique_identifier {m_Identifier++};
	int		 		max_capacity{128};
	char			*m_Data;
};