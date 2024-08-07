class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        const vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        const vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        const vector<string> thousands = {"", "Thousand", "Million", "Billion"};

        string result = "";
        int groupIndex = 0;

        while (num > 0) {
            if (num % 1000 != 0) {
                string groupResult = "";
                int part = num % 1000;

                if (part >= 100) {
                    groupResult = ones[part / 100] + " Hundred ";
                    part %= 100;
                }
                if (part >= 20) {
                    groupResult += tens[part / 10] + " ";
                    part %= 10;
                }
                if (part > 0) {
                    groupResult += ones[part] + " ";
                }
                groupResult += thousands[groupIndex] + " ";
                result = groupResult + result;
            }
            num /= 1000;
            groupIndex++;
        }
        return result.substr(0, result.find_last_not_of(" ") + 1); // Remove trailing spaces
    }
};