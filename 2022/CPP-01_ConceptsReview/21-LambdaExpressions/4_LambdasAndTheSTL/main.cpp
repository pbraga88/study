#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


// for_each - Non-modifying sequence operation
// Displays each element of nums
void test1() {
    std::cout<<"========== Test 01 =========="<<std::endl;

    std::vector<int> nums {10,20,30,40,50};
    
    std::for_each(nums.begin(), nums.end(), [](int x){std::cout<<x<<std::endl;});
}

// is_permutation - Non-modifying sequence operation
// Tests whether two triangles ares equivalent.
// Triangles are defined by a vector of three points in any orde.
// Regardless of the order of points, if two triangles containt the
// same three points then they are equivalent.
// This is determined by testing whether one sequence of points is a
// permutation of another using a predicate lambda to compare points
void test2() {
    std::cout<<"========== Test 02 =========="<<std::endl;
    
    struct Point {
        int x;
        int y;
    };

    Point pt1 {1,2};
    Point pt2 {4,3};
    Point pt3 {3,5};
    Point pt4 {3,1};

    std::vector<Point> triangle1 {pt1, pt2, pt3};
    std::vector<Point> triangle2 {pt2, pt3, pt1};
    std::vector<Point> triangle3 {pt2, pt4, pt1};

    // Test whethet triangle1 and triangle2 are equivalent
    if (std::is_permutation(triangle1.begin(), triangle1.end(), triangle2.begin(), [] (Point lhs, Point rhs) {
        return lhs.x==rhs.x && lhs.y==rhs.y;})) {
        std::cout<<"Triangles are equivalent"<<std::endl;
    }
    else {
        std::cout<<"Triangles are NOT equivalent"<<std::endl;
    }

    // Test whether triangle1 and triangle3 are equivalent
    if (std::is_permutation(triangle1.begin(), triangle1.end(), triangle3.begin(), [] (Point lhs, Point rhs) {
        return lhs.x==rhs.x && lhs.y==rhs.y;})) {
        std::cout<<"Triangles are equivalent"<<std::endl;
    }
    else {
        std::cout<<"Triangles are NOT equivalent"<<std::endl;
    }

}

// transform - Modifying sequence operation
// The transform function applies whatever operations is defined within the passed lambda
// to each element of the sequence. In this case, each test score is increased by 5 points
void test3() {
    std::cout<<"========== Test 03 =========="<<std::endl;
    
    std::vector<int> test_scores {93, 88, 75, 68, 65};
    int bonus_points {5};

    std::transform(test_scores.begin(), test_scores.end(), test_scores.begin(), [bonus_points](int score) {
        return score+=bonus_points;
    });

    // Display the points after getting the bonus
    for (const auto &point:test_scores) {
        std::cout<<point<<std::endl;
    }
}

// remove_if - Modifying sequence operation
// This example is known as erase-remove idiom and is one of
// the most common uses of lambdas with the Standard Template Library.
// The remove_if function removes all elements for which the predicate
// lambda returns 'true'. The way in which it does this is by replacing 
// each element for which the predicate returns 'true' with the element
// for which the predicate returns 'false'. The function then returns an
// iterator to the new end of the sequence. 
// The size of the sequence is not altered, only the position of its
// elements and its end iterator.
// Used in conjunction with the vector member function "erase", the 
// removed elements can be erased from the vector so that ir only contains 
// the elements for which the predicate return false.
// In this case, the erase-remove idiom is used to remove all even numbers from nums.
void test4() {
    std::cout<<"========== Test 04 =========="<<std::endl;

    std::vector<int> nums {1,2,3,4,5};
    nums.erase(std::remove_if(nums.begin(), nums.end(), [] (int num) {
                        return num%2 == 0;
                    }),
                nums.end());
    for (const auto &num:nums) {
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
}

// Used for test5
class Person{
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
private:
    std::string name;
    int age;
public:
    Person(std::string name, int age) : name{name}, age{age}{};
    Person(const Person &p) : name{p.name}, age{p.age}{};
    ~Person() = default;

    std::string get_name() {return this->name;}
    void set_name(std::string name) {this->name = name;}
    int get_age() {return this->age;}
    void set_age(int age) {this->age = age;}
};
std::ostream &operator<<(std::ostream &os, const Person &rhs) {
    os<<"[Person: "<<rhs.name<<" : "<<rhs.age<<"]";
    return os;
}
// sort - Sorting
// Sort elements in the sequence according to the predicate lambda
// In this example, a vector of people is first sorted by name in ascending order
// and then by age in descending order
void test5() {
    std::cout<<"========== Test 05 =========="<<std::endl;

    Person person1("Larry", 18);
    Person person2("Moe", 30);
    Person person3("Curly", 25);

    std::vector<Person> people {person1, person2, person3};

    // Sort the vector people by name in ascending order
    std::sort(people.begin(), people.end(), [] (Person lhs, Person rhs) {
                return lhs.get_name()<rhs.get_name();
              });
    for (const auto &person:people) {
        std::cout<<person<<std::endl;
    }

    // Sort the vector people by age in descending order
    std::sort(people.begin(), people.end(), [] (Person lhs, Person rhs){
                return lhs.get_age() > rhs.get_age();
              });
    for (const auto &person:people) {
        std::cout<<person<<std::endl;
    }
}

// in_between function is used for test6
// all_of - Non-modifying sequence operation
// Tests whether all elements contained within the sequence satisfy the 
// condition defined by the passed predicate lambda
bool in_between(const std::vector<int> &nums, int start_value, int end_value) {
    bool result {false};
    result = std::all_of(nums.begin(), nums.end(), [start_value, end_value] (int value){
                            return value>=start_value && value<=end_value;
                         });
    return result;
}
void test6() {
    std::cout<<"========== Test 06 =========="<<std::endl;
    std::cout<<std::boolalpha;

    std::vector<int> nums(10);
    std::iota(nums.begin(), nums.end(), 1);

    for (auto &num:nums) {
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;

    std::cout<<in_between(nums, 50, 7)<<std::endl;
    std::cout<<in_between(nums, 1, 10)<<std::endl;
    std::cout<<in_between(nums, 5, 7)<<std::endl;
    std::cout<<in_between(nums, 1, 100)<<std::endl;
}

// The following two classes are used for test7
class Password_Validator1 {
private:
    char restricted_symbol {'$'};
public:
    bool is_valid(std::string password) {
        return std::all_of(password.begin(), password.end(), [this](char character) {
            return character != restricted_symbol;
        });
    }
};
class Password_Validator2 {
private:
    std::vector<char> restricted_symbols {'!', '$', '+'};
public:
    bool is_valid(std::string password) {
        return std::all_of(password.begin(), password.end(), [this] (char character) {
            return std::none_of(restricted_symbols.begin(), restricted_symbols.end(), [character] (char symbol){
                return character == symbol;
            });
        });
    }
};
// all_of - Non-modifying sequence operation
// Tests whether all elements contained within the sequence satisfy the
// condition defined by the passed predicate lambda.
// In this case, the 'all_of' function is contained within the class
// 'Password_Validator' which determines whether a password contains 
// a restricted symbol and thus is valid or not.
// The same can be accomplished by using the stl function 'none_of' and 
// changing the conditional contained within the passed lambda
void test7() {
	std::cout<<"========== Test 07 =========="<<std::endl;
	
	// Password_Validator1 --------------------------------------------------
	std::string password {"holywood1$"};
	Password_Validator1 pv1;
	
	// Test whether password is valid
	if (pv1.is_valid(password))
		std::cout << "The password " << password << " is valid!" << std::endl;
	else
		std::cout << "The password " << password << " is not valid!" << std::endl;
		
	// Test whether new password is valid
	password = "hollywood1";
	if (pv1.is_valid(password))
		std::cout << "The password " << password << " is valid!" << std::endl;
	else
		std::cout << "The password " << password << " is not valid!" << std::endl;
        
	std::cout << "\n";

	// Password_Validator2 --------------------------------------------------
	password = "C++Rocks!";
	Password_Validator2 pv2;
	
	// Test whether password is valid
	if (pv2.is_valid(password))
		std::cout << "The password " << password << " is valid!" << std::endl;
	else
		std::cout << "The password " << password << " is not valid!" << std::endl;
		
	// Test whether new password is valid
	password = "CPlusPlusRocks!";
	if (pv2.is_valid(password))
		std::cout << "The password " << password << " is valid!" << std::endl;
	else
		std::cout << "The password " << password << " is not valid!" << std::endl;
		
	// Test whether new password is valid
	password = "CPlusPlusRocks";
	if (pv2.is_valid(password))
		std::cout << "The password " << password << " is valid!" << std::endl;
	else
		std::cout << "The password " << password << " is not valid!" << std::endl;
}

int main() {
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
    std::vector<int> vec  {1, 2, 3, 4, 5,13};
    int sum = std::accumulate(vec.begin(), vec.end(), 0, [](int total, int x){ return total + x; });
    std::cout << sum << std::endl;

    return 0;
}