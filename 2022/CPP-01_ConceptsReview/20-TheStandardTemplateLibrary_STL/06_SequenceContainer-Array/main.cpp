#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

// Display arrays of fixed size 5
void display(const std::array<int, 5> &arr) {
    std::cout<<"[ ";
    for (auto n:arr) {
        std::cout<<n<<" ";
    }
    std::cout<<"]"<<std::endl;
}

void test1() {
    std::cout<<"===========test 01==========="<<std::endl;
    std::array<int, 5> arr1 {1,2,3,4,5};
    std::array<int, 5> arr2;

    display(arr1);
    display(arr2); // Elements not initizalized (contain garbage)

    arr2 = {10,20,30,40,50};

    display(arr1);
    display(arr2);

    std::cout<<"Size of arr1 is: "<<arr1.size()<<std::endl;
    std::cout<<"Size of arr2 is: "<<arr2.size()<<std::endl;

    arr1[0] = 1000;
    arr1[2] = 5000;
    display(arr1);

    std::cout<<"Front of arr2: "<<arr2.front()<<std::endl;
    std::cout<<"Back of arr2: "<<arr2.back()<<std::endl;
}

void test2() {
    std::cout<<"===========test 02==========="<<std::endl;
    std::array<int, 5> arr1 {1,2,3,4,5};
    std::array<int, 5> arr2 {10, 20, 30, 40, 50};
    display(arr1);
    display(arr2);

    arr1.fill(0);
    display(arr1);
    display(arr2);

    arr1.swap(arr2);
    display(arr1);
    display(arr2);
}

void test3() {
    std::cout<<"===========test 03==========="<<std::endl;
    std::array<int, 5> arr1 {1,2,3,4,5};
    
    int *ptr = arr1.data();
    std::cout<<ptr<<std::endl; // arr1 address
    *(ptr+1) = 1000;
    
    display(arr1);
}

void test4() {
    std::cout<<"===========test 04==========="<<std::endl;
    std::array<int, 5> arr1 {1,5,4,2,3};
    display(arr1);

    std::sort(arr1.begin(), arr1.end());
    display(arr1);
}

void test5() {
    std::cout<<"===========test 05==========="<<std::endl;
    std::array<int, 5> arr1 {1,2,3,4,5};
    std::array<int, 5>::iterator it_arr_min = std::min_element(arr1.begin(), arr1.end());
    auto it_arr_max = std::max_element(arr1.begin(), arr1.end());
    std::cout<<"Minimum element is: "<<*it_arr_min<<std::endl;
    std::cout<<"Maximum element is: "<<*it_arr_max<<std::endl;
}

void test6() {
    std::cout<<"===========test 06==========="<<std::endl;
    std::array<int, 5> arr1 {1,2,2,3,5};
    auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());
    if (adjacent != arr1.end()) {
        std::cout<<"Duplicated number found! Number: "<<*adjacent<<std::endl;
    }
    else {
        std::cout<<"Duplicated number not found!"<<std::endl;
    }
}

void test7() {
    std::cout<<"===========test 07==========="<<std::endl;
    std::array<int, 10> arr1 {1,2,3,4,5,6,7,8,9,10};

    // accumulate is from #include <numeric>
    int sum = std::accumulate(arr1.begin(), arr1.end(), 0); // Start sum from '0'. 0 + accumulate 
    std::cout<<"Sum of all elements in Arrays is: "<<sum<<std::endl;

}

void test8() {
    std::cout<<"===========test 08==========="<<std::endl;
    std::array<int, 10> arr1 {1,2,2,2,2,6,7,8,8,10};

    int count = std::count(arr1.begin(), arr1.end(), 2);
    std::cout<<"Counted occurrences of 2: "<<count<<std::endl;
}

void test9() {
    std::array<int, 13> arr1{0,1,2,3,4,5,6,7,8,9,10,10,10};

    // Count if even
    int count = std::count_if(arr1.begin(), arr1.end(), [](int x) {return x%2 == 0;});
    std::cout<<"Count of even numbers in array: "<<count<<std::endl;
}

int main() {
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
    // test8();
    test9();

    return 0;
}