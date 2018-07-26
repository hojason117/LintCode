class Solution {
public:
    /**
     * @param words: a list of string
     * @return: a boolean
     */
    bool validWordSquare(vector<string> &words) {
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words.at(i).length(); j++) {
                try {
                    if(words.at(i)[j] != words.at(j)[i])
                        return false;
                }
                catch(const std::exception&) {
                    return false;
                }
            }
        }

        return true;
    }
};