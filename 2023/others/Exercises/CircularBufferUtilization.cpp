/* Circular buffer Utilization
A circular ring buffer is used to pass data between 2 threads; 1 Thread writes to the buffer whilst the other reads. 
A state variable captures the current utilisation of the ring buffer, where each binary bit represents an entry in the buffer:
•

If a bit is 1, the corresponding position/entry in the ring buffer is used.
If a bit is 0, the corresponding position/entry in the ring buffer is unused.

The utilisation of the buffer is monitored as part of the background self-tests and diagnostics. 
If 3 or more consecutive buffer entries are currently in use it indicates a performance issue with the system.
Write a function that checks a given state variable and returns true if there are 3 or more consecutive bits set and false otherwise.

Be careful: - Note the buffer is circular! 
            - The state variable is an unsigned type, of either 8 or 16 bits width.

Input format
The input format that you must use to provide custom input (available above the Compile and Test buttons) is as follows:
• A single unsigned integer value of either 8 or 16 bits width describing the buffer utilization state

Output format
Print the utilization result as integer 0 or 1

Sample input 
186
Sample output
1
*/
#include <iostream>
#include <cstdint>
#include <limits>

#define LEAD_BITS_1 0x01 // 0000 0001
#define LEAD_BITS_2 0x03 // 0000 0011
#define LEAD_BITS_3 0x07 // 0000 0111
#define LEAD_BITS_4 0x0F // 0000 1111
#define LEAD_BITS_5 0x1F // 0001 1111


// template <typename T>
// bool check_buffer(T state) {
//     // Create a mask with 3 consecutives set bits and 2 leading set bits
//     // T mask = (1 << (sizeof(T) * 8 - 1)) | (1 << (sizeof(T) * 8 - 2)) | 1;
//     T mask = (LEAD_BITS_2 << (sizeof(T) * 8 - 2)) | 1;
//     // T mask = (1 << (sizeof(T) * 8 - 1)) | (1 << (sizeof(T) * 8 - 2)) | (1 << (sizeof(T) * 8 - 3));
    
//     std::cout<<"DEBUG: state = "<<static_cast<uint16_t>(state)<<std::endl;
//     std::cout<<"DEBUG: mask = "<<static_cast<uint16_t>(mask)<<std::endl;
//     std::cout<<"DEBUG: sizeof(T) = "<<sizeof(T)<<std::endl;

//     for (int i = 0; i < sizeof(T) * 8; i++) {
//         // Check if 3 or more consecutive set bits are found
//         if ((state & mask) == mask) {
//             return true;
//         }
//         // Rotate the mask to the right
//         mask = (mask >> 1) | ((mask & 1) << (sizeof(T) * 8 -1));
//     }

//     return false;
// }

template <typename T>
bool check_buffer(T state) {
    if (state == ((LEAD_BITS_2 << sizeof(T) * 8 - 2) | 1) || // uint8_t: 1100 0001; uint16_t: 1100 0000 0000 0001
        state == ((LEAD_BITS_1 << sizeof(T) * 8 - 1) | 3) || // uint8_t: 1000 0011; uint16_t: 1000 0000 0000 0011
        (state & (state << 1) & (state << 2)) != 0 ) {       // state:          1011 1001
            return true;                                     // (state << 1):   0111 0010   
        }                                                    // (state << 2):   1110 0100
    return false;                                            // result:         0010 0000       
}

int main() {
    // The two follow lines are used to optimize I/O performance.
    // When using them, make sure not to mix C++ streams and C standard I/O functions (e.g scanf, printf, etc)
    // in the same program. Also make sure to control the flushing of the output stream manually when needed.
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Read an input state buffer
    uint64_t num{0};
    std::cin>>num;

    // Reading input from STDIN
    bool state_flag {false};

    // Use a type appropriate the size of the value
    if (num <= std::numeric_limits<uint8_t>::max()) {
        uint8_t state = static_cast<uint8_t>(num);
        state_flag = check_buffer(state);
    }
    else {
        int16_t state = static_cast<uint16_t>(num);
        state_flag = check_buffer(state);
    }

    // Finally, print the answer
    std::cout<<state_flag<<std::endl;

    return 0;
}