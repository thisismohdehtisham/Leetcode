class Solution {
public:
    int getLucky(string s, int k) {
        string number = ""; // start with an empty string
        for (char c : s) {
            number += to_string(
                c - 'a' +
                1); // converting the numbers into strings based 1-base indexing and then  concatenating it.
        }

        while (k > 0) {
            int temp = 0;
            for (char x : number) {
                temp += x - '0'; // storing the numbers after the string
            }

            number = to_string(temp); // converting back into the string
            k--; // decreasing the operation count
        }
        return stoi(number);
    }
};