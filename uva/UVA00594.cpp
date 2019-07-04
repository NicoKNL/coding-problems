#include <iostream>
#include <bitset>

using namespace std;

int main() {
    long value, result;
    int byte;
    while (cin >> value) {
        bitset<32> bits_in(value);
        bitset<32> bits_out;

        byte = 0;
        while(byte < 4) {
            for (int i = 0; i < 8; i++) {
                bits_out[(3 - byte) * 8 + i] = bits_in[byte * 8 + i];
            }
            byte++;
        }

        result = 0;
        for (int i = 0; i < 64; i++) {
            result += (1 << i) * bits_out[i];
        }

        cout << value << " converts to " << result << endl;
    }
    return 0;
}