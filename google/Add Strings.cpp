class Solution {
public:
    /**
     * @param num1: a non-negative integers
     * @param num2: a non-negative integers
     * @return: return sum of num1 and num2
     */
    string addStrings(string &num1, string &num2) {
        string result = "";

        bool carry = false;
        for(int i = 1; i <= min(num1.length(), num2.length()); i++) {
            char temp = num1[num1.length() - i] + num2[num2.length() - i] - '0';
            if(carry) {
                temp++;
                carry = false;
            }
            if(temp - '0' >= 10) {
                carry = true;
                temp -= 10;
            }
            result.insert(0, sizeof(char), temp);
        }

        if(num1.length() > num2.length()) {
            string temp = num1.substr(0, num1.length() - num2.length());
            for(int i = temp.length() - 1; i >= 0; i--) {
                if(!carry)
                    break;
                temp[i]++;
                carry = false;
                if(temp[i] - '0' >= 10) {
                    carry = true;
                    temp[i] -= 10;
                }
            }
            if(carry)
                temp.insert(0, sizeof(char), '1');
            result.insert(0, temp);
        }
        else if(num1.length() < num2.length()) {
            string temp = num2.substr(0, num2.length() - num1.length());
            for (int i = temp.length() - 1; i >= 0; i--) {
                if (!carry)
                    break;
                temp[i]++;
                carry = false;
                if(temp[i] - '0' >= 10) {
                    carry = true;
                    temp[i] -= 10;
                }
            }
            if(carry)
                temp.insert(0, sizeof(char), '1');
            result.insert(0, temp);
        }
        else {
            if(carry)
                result.insert(0, sizeof(char), '1');
        }

        return result;
    }
};
