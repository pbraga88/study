#include <iostream>
#include <climits>
#include <cfloat>

using namespace std;

void prinSizes() {
    // Char
    cout<<"size of char: "<<sizeof(char)<<" Byte"<<endl;

    // Integers
    cout<<"size of short: "<<sizeof(short)<<" Bytes"<<endl;
    cout<<"size of int: "<<sizeof(int)<<" Bytes"<<endl;
    cout<<"size of long: "<<sizeof(long)<<" Bytes"<<endl;
    cout<<"size of long long: "<<sizeof(long long)<<" Bytes"<<endl;

    // Floating-point
    cout<<"size of float: "<<sizeof(float)<<" Bytes"<<endl;
    cout<<"size of double: "<<sizeof(double)<<" Bytes"<<endl;
    cout<<"size of long double: "<<sizeof(long double)<<" Bytes"<<endl;

    // bool
    cout<<"size of bool: "<<sizeof(bool)<<" Byte"<<endl;

    int someVar[5] {0};
    cout<<"size of int someVar: "<<sizeof someVar<<" Bytes"<<endl;
}

void var_platform_sizes() {
    cout<<"CHAR_MAX: "<<sizeof(CHAR_MAX)<<" Bytes"<<endl;
    cout<<"CHAR_MIN: "<<sizeof(CHAR_MIN)<<" Bytes"<<endl;
    cout<<"CHAR RANGE: "<<CHAR_MIN<<" to " <<CHAR_MAX<<endl;
    cout<<endl;
    cout<<"SHRT_MAX: "<<sizeof(SHRT_MAX)<<" Bytes"<<endl;
    cout<<"SHRT_MIN: "<<sizeof(SHRT_MIN)<<" Bytes"<<endl;
    cout<<"SHRT RANGE: "<<SHRT_MIN<<" to " <<SHRT_MAX<<endl;
    cout<<endl;
    cout<<"INT_MAX: "<<sizeof(INT_MAX)<<" Bytes"<<endl;
    cout<<"INT_MIN: "<<sizeof(INT_MIN)<<" Bytes"<<endl;
    cout<<"INT RANGE: "<<INT_MIN<<" to " <<INT_MAX<<endl;
    cout<<endl;
    cout<<"LONG_MAX: "<<sizeof(LONG_MAX)<<" Bytes"<<endl;
    cout<<"LONG_MIN: "<<sizeof(LONG_MIN)<<" Bytes"<<endl;
    cout<<"LONG RANGE: "<<LONG_MIN<<" to " <<LONG_MAX<<endl;
    cout<<endl;
    cout<<"LONG_LONG_MAX: "<<sizeof(LONG_LONG_MAX)<<" Bytes"<<endl;
    cout<<"LONG_LONG_MIN: "<<sizeof(LONG_LONG_MIN)<<" Bytes"<<endl;
    cout<<"LONG LONG RANGE: "<<LONG_LONG_MIN<<" to " <<LONG_LONG_MAX<<endl;
    cout<<endl;
    cout<<"FLT_MAX: "<<sizeof(FLT_MAX)<<" Bytes"<<endl;
    cout<<"FLT_MIN: "<<sizeof(FLT_MIN)<<" Bytes"<<endl;
    cout<<"FLT RANGE: "<<FLT_MIN<<" to " <<FLT_MAX<<endl;
    cout<<endl;
    cout<<"DBL_MAX: "<<sizeof(DBL_MAX)<<" Bytes"<<endl;
    cout<<"DBL_MIN: "<<sizeof(DBL_MIN)<<" Bytes"<<endl;
    cout<<"DBL RANGE: "<<DBL_MIN<<" to " <<DBL_MAX<<endl;
}

void (*funcptr)(void);

int main(int argc, char* argv[]) {
    int funcInd {0};
    if (argc > 1) {
        funcInd = atoi(argv[1]);
    }   
    cout<<funcInd<<endl;
    switch (funcInd)
    {
    case  1:
        funcptr = &prinSizes;
        break;
    case 2:
        funcptr = &var_platform_sizes;
        break;
    default:
        cout<<"No valid value input"<<endl;
        funcInd = 0;
        break;
    }
    
    if(funcInd) {
        funcptr();
    }

    return 0;
}