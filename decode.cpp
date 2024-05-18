#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

std::vector<int> right_side_numbers(int max_value) {
    std::vector<int> nums;
    int i = 1;
    int k = 2;
    while (i <= max_value) {
        nums.push_back(i);
        i += k;
        k += 1;
    }
    return nums;
}

std::string decode_message(const std::string& file_path) {
    std::ifstream file(file_path);
    std::unordered_map<int, std::string> encode;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            int number;
            std::string word;
            ss >> number >> word;
            encode[number] = word;
        }
        file.close();
    }
    int max_num = 0;
    for (const auto& entry : encode) {
        max_num = std::max(max_num, entry.first);
    }

    std::vector<int> encode_pos = right_side_numbers(max_num);
    std::string decode_message;
    for (int pos : encode_pos) {
        if (encode.find(pos) != encode.end()) {
            decode_message += encode[pos] + " ";
        }
    }
    return decode_message;
}

int main() {
    std::string file_path = "message_file.txt";
    std::string decoded_message = decode_message(file_path);
    std::cout << decoded_message << std::endl;
    return 0;
}
