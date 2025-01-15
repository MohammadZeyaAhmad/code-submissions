class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() == 0)
            return b;
        if (b.length() == 0)
            return a;
        string result = "";
        int i = a.length() - 1, j = b.length() - 1;
        int carry = 0;
        while (i >= 0 && j >= 0) {
            if (a[i] == '1' && b[j] == '1') {
                if (carry == 1) {
                    result = "1"+result;
                    carry = 1;
                } else {
                    result = "0" + result;
                    carry = 1;
                }
            } else if (a[i] == '0' && b[j] == '0') {
                if (carry == 1) {
                    result = "1" + result;
                    carry = 0;
                } else {
                    result = "0" + result;
                }

            } else {
                if (carry == 1) {
                    result = "0" + result;
                    carry = 1;
                } else {
                    result = "1" + result;
                }
            }
            i--;
            j--;
        }

        while (i >= 0) {
            if (carry == 1) {
                if (a[i] == '1') {
                    result = "0" + result;
                    carry = 1;
                } else {
                    result = "1" + result;
                    carry=0;
                }

            } else {
                result = a[i] + result;
            }
            i--;
        }

        while (j >= 0) {
            if (carry == 1) {
                if (b[j] == '1') {
                    result = "0" + result;
                    carry = 1;
                } else {
                    result = "1" + result;
                    carry=0;
                }

            } else {
                result = b[j] + result;
            }
            j--;
        }
        
        if (carry != 0 ) {
            result = "1" + result;
        }
        return result;
    }
};
