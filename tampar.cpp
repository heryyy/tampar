#include <iostream>
#include <thread>
#include <chrono>

void printLyrics() {
    struct Line {
        std::string text;
        std::chrono::milliseconds charDelay;
    };

    Line lines[] = {
        {"Hujan samarkan derasnya", std::chrono::milliseconds(100)},
        {"Tutup air mata", std::chrono::milliseconds(100)},
        {"Temani kecewaku yang telah lama", std::chrono::milliseconds(110)},
        {"Berdosa kah ku berdoa", std::chrono::milliseconds(100)},
        {"Minta kau terluka", std::chrono::milliseconds(110)},
        {"Dan tinggalkan dirinya", std::chrono::milliseconds(110)},
        {"Hujan samarkan derasnya", std::chrono::milliseconds(110)},
        {"Tutup air mata", std::chrono::milliseconds(140)},
        {"Tiga tahun tak terasa", std::chrono::milliseconds(120)},
        {"Masih kau yang ada", std::chrono::milliseconds(120)},
        {"Bodoh yang sebenarnya", std::chrono::milliseconds(120)},
        {"Tampar aku di pipi", std::chrono::milliseconds(120)},
        {"Sadarkan kau aku takkan terjadi", std::chrono::milliseconds(120)},
    };

    std::chrono::milliseconds delays[] = {
        std::chrono::milliseconds(600), std::chrono::milliseconds(600), std::chrono::milliseconds(500), std::chrono::milliseconds(1600),
        std::chrono::milliseconds(600), std::chrono::milliseconds(700), std::chrono::milliseconds(700), std::chrono::milliseconds(1400),
        std::chrono::milliseconds(700), std::chrono::milliseconds(500), std::chrono::milliseconds(500), std::chrono::milliseconds(3600),
        std::chrono::milliseconds(500), std::chrono::milliseconds(600), std::chrono::milliseconds(600), std::chrono::milliseconds(600),
        std::chrono::milliseconds(800), std::chrono::milliseconds(900), std::chrono::milliseconds(900), std::chrono::milliseconds(800),
        std::chrono::milliseconds(800), std::chrono::milliseconds(900), std::chrono::milliseconds(900), std::chrono::milliseconds(16000),
        std::chrono::milliseconds(1400), std::chrono::milliseconds(900), std::chrono::milliseconds(900), std::chrono::milliseconds(800),
        std::chrono::milliseconds(800), std::chrono::milliseconds(600), std::chrono::milliseconds(500), std::chrono::milliseconds(500),
        std::chrono::milliseconds(600), std::chrono::milliseconds(5000),
    };

    for (size_t i = 0; i < sizeof(lines) / sizeof(lines[0]); ++i) {
        for (char c : lines[i].text) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(lines[i].charDelay);
        }
        std::this_thread::sleep_for(delays[i % (sizeof(delays) / sizeof(delays[0]))]);
        std::cout << std::endl;
    }
}

int main() {
    printLyrics();
    return 0;
}